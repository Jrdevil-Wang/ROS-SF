# ROS-SF Converter

ROS-SF framework requires that all objects of the serialization-free message class are allocated on the heap, rather than on the stack. ROS-SF Converter can automatically find objects of the target class which are defined on the stack, and convert them to be allocated on the heap.


## Usage

### Requirement

ROS-SF Converter is designed based on LLVM 10.0. On Ubuntu 20.04, `sudo apt install llvm-10-dev` should do the LLVM installation job.


### Compilation

Run command `make` at the `./` directory to compile the `sfm_conv.cpp`. It should generate an executable `sfm_conv`.


### Conversion Test

```
cd test

# Generate original version
# Generated executable "a" could be found under ./test/origin
make 

# Generate converted version
# ROS-SF Converter will generate a converted .cpp file and its corresponding executable
# Generated "a.cpp" and executable "a" could be found under ./test/target
make sfm 
```

Open `./test/origin/a.cpp` and `./test/target/a.cpp` to check their differences. The executing result of both the executables should be the same.



### Advanced Usage

The name of the class being converted is specified in three global variables in  `sfm_conv.cpp` (current values are for the target class `Test::A` ).  If you want to convert other classes such as `sensor_msgs::Image`,  modifications should be made on these global variables in `sfm_conv.cpp`.

- `use_dereivedtype` at line 34.

  The default value is 0, indicating that the target class is of DICompositeType in LLVM. Ordinary classes belong to this type. When you generate the target class using a C++ template, this value should be set to 1, indicating that the target class is of DIDerivedType in LLVM.

- `strCls` at line 36.

  This is the **full name** string of the target class. Line 39 and line 43 are two examples.

- `strIdf` at line 37.

  This is the **identifier name** string of the target class, which is the demangled C++ class name. Line 40, line 41, line 44, and line 45 are four examples. Note that when using line 40 and line 44, _use_dereivedtype_ should be set to 1.

After the above modifications, you should re-compile the `sfm_conv.cpp` 

The generated executable `sfm_conv` can be used to convert other C++ code. For example, the command `make sfm` in the above conversion test is equivalent to the following commands.

```
cd test

# Compile the source file (.cpp) to LLVM bitcode file (.bc)
clang++ -emit-llvm -c -g origin/a.cpp -o target/a.bc

# Use ROS-SF Converter to convert the source file with the help of the LLVM bitcode file
sfm_conv target/a.bc origin/a.cpp > target/a.cpp

# Compile the converted source file
clang++ target/a.cpp -o target/a
```

Currently, this routine is not fully automated because it is related to the compilation process of the target project.
But it is trivial to achieve full automation by replacing the compiler to a tool based on the `sfm_conv`.
