#!/bin/bash -l

#SBATCH -J Mat_Sqr_with_diff_Threads_By_OMP_for_Xinghang
#SBATCH -q premium
#SBATCH -N 1
#SBATCH -t 03:00:00
#SBATCH -L SCRATCH
#SBATCH -C haswell

echo "====== Outer Loop Version Start ====== "
export Description="Threads Num: "
export OMP_NUM_THREADS=1
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo " ------------------------------------- "
export OMP_NUM_THREADS=2
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo " ------------------------------------- "
export OMP_NUM_THREADS=4
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo " ------------------------------------- "
export OMP_NUM_THREADS=8
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo " ------------------------------------- "
export OMP_NUM_THREADS=16
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo " ------------------------------------- "
export OMP_NUM_THREADS=32
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo " ------------------------------------- "
export OMP_NUM_THREADS=64
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo " ------------------------------------- "
export OMP_NUM_THREADS=128
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./outer

echo "=============== Outer loop Version Done =================="

echo " "
echo " "

echo " ******** Inner Loop Version Start ********* "
export Description="Threads Num: "
export OMP_NUM_THREADS=1
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo " ------------------------------------- "
export OMP_NUM_THREADS=2
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo " ------------------------------------- "
export OMP_NUM_THREADS=4
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo " ------------------------------------- "
export OMP_NUM_THREADS=8
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo " ------------------------------------- "
export OMP_NUM_THREADS=16
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo " ------------------------------------- "
export OMP_NUM_THREADS=32
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo " ------------------------------------- "
export OMP_NUM_THREADS=64
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo " ------------------------------------- "
export OMP_NUM_THREADS=128
echo $Description$OMP_NUM_THREADS
srun -n 1 -c 64 ./inner

echo "=============== Inner loop Version Done =================="