/*
	ROS-SF Convertor, based on LLVM 10.0

	Authors:
		Yu-Ping Wang, wyp@tsinghua.edu.cn

	Last Modified: 2021.10.05 by Yu-Ping Wang
 */

#include "llvm/Support/TargetSelect.h"
#include "llvm/Bitcode/BitcodeReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using namespace llvm;

const int use_derivedtype = 0;

const string strCls = "Test::A";
const string strIdf = "_ZTSN4Test1AE";

// const string strCls = "sensor_msgs::Image";
// const string strIdf = "_ZTSN11sensor_msgs6Image_ISaIvEEE"; // ROS version, DIDerivedType
// const string strIdf = "_ZTSN11sensor_msgs5ImageE"; // ROS-SF version, DICompositeType

// const string strCls = "sensor_msgs::PointCloud2";
// const string strIdf = "_ZTSN11sensor_msgs12PointCloud2_ISaIvEEE"; // ROS version, DIDerivedType
// const string strIdf = "_ZTSN11sensor_msgs11PointCloud2E"; // ROS-SF version, DICompositeType

bool judgeType(const DIType * type) {
    if (use_derivedtype != 0) {
        const DIDerivedType * ddt = dyn_cast<DIDerivedType>(type);
        if (!ddt)
            return false;
        const DIType * dbt = ddt->getBaseType();
        if (!dbt)
            return false;
        const DICompositeType * dct = dyn_cast<DICompositeType>(dbt);
        if (!dct)
            return false;
        if (dct->getIdentifier() != strIdf)
            return false;
        errs() << *ddt << "\n";
        errs() << *dct << "\n";
    } else {
        const DICompositeType * dct = dyn_cast<DICompositeType>(type);
        if (!dct)
            return false;
        if (dct->getIdentifier() != strIdf)
            return false;
        errs() << *dct << "\n";
    }
    return true;
}
int find_initializer(string l, int s) {
    int level = 0;
    while (true) {
        if (l[s] == '(')
            level++;
        else if (l[s] == ')')
            level--;
        else if ((l[s] == ',' || l[s] == ';') && level == 0)
            break;
        s++;
    }
    return s;
}
string trim_initializer(string l) {
    int pos = l.find("=");
    if (pos == string::npos)
        return l;
    return l.substr(pos + 1);
}
// main process
ExitOnError ExitOnErr;
int main(int argc, char** argv) {
    // prepare LLVM
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    ExitOnErr.setBanner(string(argv[0]) + "error: ");
    // handle input error
    if (argc <= 2) {
        errs() << "Usage: <" << argv[0] << "> source.bc source.cpp\n";
        return -1;
    }
	// read input cpp
    ifstream fin(argv[2]);
    vector<string> lines;
    while (fin) {
        string line;
        getline(fin, line);
        if (!fin)
            break;
        lines.push_back(line);
    }
    // handle IR .bc file
    unique_ptr<MemoryBuffer> mb = ExitOnErr(errorOrToExpected(MemoryBuffer::getFile(argv[1])));
    LLVMContext context;
    unique_ptr<Module> m = ExitOnErr(parseBitcodeFile(*mb.get(), context));
    errs() << "\nprocessing...\n";
    vector<map<int, string> > toChange(lines.size());
    for (Function & f : (*m))
        if (!f.isDeclaration())
            for (BasicBlock & bb : f)
                for (Instruction & i : bb) {
                    if (isa<DbgDeclareInst>(i)) {
						const DbgDeclareInst * di = dyn_cast<DbgDeclareInst>(&i);
                        if (!di)
                            continue;
						// local variable or parameter declaration found
                        const DILocalVariable * dlv = di->getVariable();
						// skip parameter declaration
						if (dlv->getArg() > 0)
							continue;
						// check type
						if (!judgeType(dlv->getType()))
                            continue;
						// local variable with target class type
                        const DebugLoc & loc = i.getDebugLoc();
                        if (!loc || loc.getLine() == 0 || loc.getCol() == 0)
                            continue;
                        DIScope * scp = cast<DIScope>(loc->getScope());
                        string fileName = scp->getFilename();
                        errs() << "Find " << strCls << " at " << loc.getLine() << ", " << loc.getCol() << "@" << fileName << "\n";
                        if (fileName != argv[2])
                            continue;
                        toChange[loc.getLine() - 1][loc.getCol()] = dlv->getName();
                    }
                }
    // actually replace object definition
    errs() << "\nreplacing...\n";
	for (size_t i = 0; i < lines.size(); i++) {
		string line = lines[i];
		for (map<int, string>::reverse_iterator rit = toChange[i].rbegin(); rit != toChange[i].rend(); ++rit) {
			string name = rit->second;
			int name_st = rit->first - 1;
            int name_ed = name_st + name.length();
            int pos = find_initializer(line, name_ed);
            string init = trim_initializer(line.substr(name_ed, pos - name_ed));
			outs() << "/* modified by sfm */ boost::shared_ptr<" << strCls << "> _psfm_" << name << "(new " << strCls << "(" << init << "));\n";
			string ndef = string("& ") + name + "(*_psfm_" + name + ")";
			line.replace(name_st, pos - name_st, ndef);
			errs() << "modifying: " << line << "\n";
	    }
		outs() << line << "\n";
	}
    return 0;
}

