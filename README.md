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
5. (optional) ln -s /home/user/folder-with-program/DislScatCubFITThreadingMult/build/DislScatHexFITThreadingMult /home/user/bin/DislScatCubFITThreadingMult

You will be able then run your program from any location simply typing 
DislScatCubFITThreadingMult in a terminal window.

# Usage
Suggested folder structure:  
.  
├── config  
│   ├── data.cfg  
│   ├── fit.cfg  
│   ├── sample.cfg  
├── data1.dat  
├── data2.dat  
├── ...  
├── datan.dat  

Data files should mandatory contain (at least) two columns entitled in the header as follows:  
    #   [omega]  [intensity]  
or  
    #   [domega]  [intensity]  
if 0-point is in the peak center. [omega]-column values should be in degrees.

Each added datafile should possess the following record in the data.cfg configuration file:
    {  
        file = "relative_path/data.dat";
        Q = [ H, K, I, L ];
        resolution : 
        {
            x = <double>;
            z = <double>;
        };
        I0 = <double>;
        Ibg = <double>;
    }  
Do not forget to add record 
    {  
		name = "Data.[<integer>].I0";
		minVal = <double>;
		maxVal = <double>;
	}  
to *fit.cfg* upon addition of a new datafile. 
This will add a new intensity-scale fit variable. 
Normally, you always want to fit intensity scale.

To run the program type:

DislScatCubFITThreadingMult config/

Folder structure after run:  
.
├── config  
│   ├── data.cfg  
│   ├── data.~cfg  
│   ├── fit.cfg  
│   ├── resume.txt  
│   ├── sample.cfg  
│   ├── sample.~cfg  
│   ├── data1.ft  
│   ├── data2.ft  
│   ├── ...  
│   └── datan.ft  
├── data1.dat
├── data2.dat
├── ...  
└── datan.dat  

## Tested with
Linux Mint 13:
- cmake 2.8.7
- GSL v1.15
- BLAS v1.2
- PORT v3
- libconfig v1.4.9
