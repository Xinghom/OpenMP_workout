#!/bin/bash -l

#SBATCH -q premium
#SBATCH -N 1
#SBATCH -t 00:30:00
#SBATCH -L SCRATCH
#SBATCH -C haswell

export Description="Threads Num: "
export OMP_NUM_THREADS=1
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=2
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=4
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=8
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=16
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=32
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=64
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=128
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=256
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi

export OMP_NUM_THREADS=512
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./pi