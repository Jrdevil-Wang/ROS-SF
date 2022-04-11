# ROS-SF Converter

ROS-SF Converter can automatically convert the code of existing ROS application to use our ROS-SF framework.



## Code Summary

`sfm_conv.cpp` is the main converter code.

`./test` is a test to show how it works.

`./test/origin` is the code before conversion.

`./test/target` is the location for the code after conversion.



## Usage

### Compilation

Type `make` at the `./` directory to compile the `sfm_conv.cpp`.

LLVM 10.0 is needed to compile it. On Ubuntu 20.04, `sudo apt install llvm-10-dev` should do the LLVM installation job.



### Conversion Test

```
cd test

# generate original version
# generated executable could be found under ./test/origin
make 

# generate converted version
# it will generate a converted .cpp file and its corresponding executable
# generated .cpp file and executable could be found under ./test/target
make sfm 
```

Open `./test/origin/a.cpp` and `./test/target/a.cpp` to check their differences. The executing result of both the executables should be the same.



### Advanced Usage

The name of the class being converted is specified in three global variables in  `sfm_conv.cpp` (currently the class name is `Test::A` ).  If you want to convert other classes such as `sensor_msgs::Image`,  modifications should be made on these global variables in `sfm_conv.cpp`.

- `use_dereivedtype` at line 34.

  The default value is 0, indicating that the target class is of DICompositeType in LLVM. Ordinary classes belong to this type. When you generate the target class using a C++ template, this value should be set to 1, indicating that the target class is of DIDerivedType in LLVM.

- `strCls` at line 36.

  This is the **full name** string of the target class. Line 39 and line 43 are two examples.

- `strIdf` at line 37.

  This is the **identifier name** string of the target class, which is the demangled C++ class name. Line 40, line 41, line 44, and line 45 are four examples. Note that when using line 40 and line 44, _use_dereivedtype_ should be set to 1.

After the above modifications, you should re-compile the `sfm_conv.cpp` 

The generated executable `sfm_conv` can be used to convert other C++ code：

```
cd test

clang++ -emit-llvm -c
sfm_conv a.bc a.cpp > a_mod.cpp
```



`./test/Makefile`  shows an example of how to use `sfm_conv`.
Basically, we need to compile the target `.cpp` file with LLVM (`clang++ -emit-llvm -c`) to generate a LLVM bitcode file (`.bc`).
Then run `sfm_conv a.bc a.cpp > a_mod.cpp` to convert `a.cpp` to `a_mod.cpp` with the help of `a.bc`.

Currently, this routine is not fully automated because it is related to the compilation process of the target project.
But it is trivial to achieve full automation by replacing the compiler to a tool based on the `sfm_conv`.
