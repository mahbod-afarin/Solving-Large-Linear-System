#!/bin/bash
#  
#SBATCH 
#SBATCH -o lab1.out
#SBATCH -e lab1.err
#SBATCH -J lab1
#SBATCH -n 1
#SBATCH -c 4
#SBATCH --mem=11000
#SBATCH --time=8:0:0

####################################
# DO NOT CHANGE CODES IN THIS FILE #
####################################

cd ../build

export MKL_ENABLE_INSTRUCTIONS=AVX2
export MKL_NUM_THREADS=1

./verify &> ../data/mydata.txt

# rm lab1.*
