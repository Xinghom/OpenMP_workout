#!/bin/bash -l

#SBATCH -q premium
#SBATCH -N 1
#SBATCH -t 00:10:00
#SBATCH -L SCRATCH
#SBATCH -C haswell

export OMP_NUM_THREADS=1
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=2
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=4
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=8
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=16
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=32
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=64
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=128
srun -n 1 -c 64 ./pi
