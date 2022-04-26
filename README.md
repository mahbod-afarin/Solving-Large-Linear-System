# lab2

## how to build

Same as lab1, this frame can only be built and run on Tardis.

```
$ cd ~/
$ wget https://www.cs.ucr.edu/~yzhai015/lab2_frame.tar.gz
$ tar -xvf lab2_frame.tar.gz
$ cd ~/lab2
```

Then you should
* Implement all functions in ```src/for_you_to_do.c```.
* Do NOT modify ```include/for_you_to_do.h```. It just listed all functions you are to implement.
* Modify optimal block size in line 77 of ```test/verification.c``` based on your lab1 result.
* If you really want to modify the matrix dimension in line 34 of ```test/verification.c```, please send me a message and explain why you need to modify it. If you don't need to modify it, please be sure to use the default matrix sizes.

You have your codes ready to run. Cong! Now you can run the code by
```
$ cd ~/lab2/build
$ export CXX=/act/gcc-4.7.2/bin/g++
$ export CC=/act/gcc-4.7.2/bin/gcc
$ cmake ..
$ make
```

Then you want to submit your code with ```SLURM```. You just need to do
```
$ cd ~/lab2/script
$ sbatch submit.sh
```

I left the results I obtained from Tardis with my code in ```data/mydata.txt``` since some of you may want to refer to it. If you run your own submission, ```mydata.txt``` will be overwritten by your result.# assignment2
