Program to calculate vertical threading dislocation density in epitaxial layer
with cubic interface from double-crystal scans.
Simultaneous fit to multiple data files is possible.

# Requirements

### Following programs should be present on your computer
- gcc compiler
- cmake

### Following libraries should be present on your computer
- [Gnu Scientific Library (GSL)](http://www.gnu.org/software/gsl/)
- [Basic Linear Algebra Subprograms (BLAS)](http://www.netlib.org/blas/)

### Following libraries will be installed by cmake
- [Port3](http://www.netlib.org/port/)
- [libconfig](http://www.hyperrealm.com/libconfig/)

# Build
From command line in the program folder type following:

1. mkdir build
2. cd build/
3. cmake ..
4. make

You find executable file **DislScatCubFITThreadingMult** in the *build* folder

5. (optional) ln -s /home/user/folder-with-program/DislScatCubFITThreadingMult/build/DislScatHexFITThreadingMult /home/user/bin/DislScatCubFITThreadingMult

You will be able then run your program from any location simply typing 
DislScatCubFITThreadingMult in a terminal window

# Usage
Suggested folder structure:
sample/
    +datafile_1
    +datafile_2
    ...
    +datafile_n
    +config/
        +data.cfg
        +fit.cfg
        +sample.cfg

## Tested with
Linux Mint 13:
- cmake 2.8.7
- GSL v1.15
- BLAS v1.2
- PORT v3
- libconfig v1.4.9
