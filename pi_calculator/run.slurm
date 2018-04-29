#!/bin/bash -l

#SBATCH -q premium
#SBATCH -N 1
#SBATCH -t 00:10:00
#SBATCH -L SCRATCH
#SBATCH -C haswell

export OMP_NUM_THREADS=32
srun -n 1 -c 64 ./run_pi