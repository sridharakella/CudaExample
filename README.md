# CudaExample
Cuda Examples 

Portable Batch System (PBS) and the Simple Linux Utility for Resource Management (Slurm) 

sample PBS 
qsub(queuesubmit) qstat, qdel, qalter

openMP( open multiprocessor) shared mutiprocessing in c++, forton etc.
#include <omp.h>



Slurm (slurmctld is installed on master , slurmd is installed on compute node, slurmd for database deamon)

Slurm entties:
Nodes, Patitions , Jobs and Jobs steps.

scontrol(only executed root user, slurm state).< br / >
sinfo(state of partitions, and nodes managed from slurm, has filtering, sorting) < br / >
squeue( heavinly used, reports the jobs in priortiy order) < br / >
scancel( to cancel the ) < br / >
sacct( used for accounting information, about completed jobs) < br / >
srun/sbatch( to submit the jobs for later execution) < br / >



#!/bin/bash
#SBATCH --job-name=parallel_sum
#SBATCH --output=job_output.txt
#SBATCH --nodes=1
#SBATCH --ntasks=32( it rewuest 32 MPI processes)
#SBATCH --ntasks-per-node= 16 MPI per node)
#SBATCH --cpus-per-task=28  
#SBATCH --time=01:20:00
#SBATCH --mail-type=ALL
#SBATCH --mail-user=tntech.edu
#SBATCH --account=ipdc-2018
module load opempi

cd /home/CAE/sridhar
./parallel_sum


Performance measure for GPU:

Throughput-    calculated the number of floating points for second

Clock speed  ( sometimes higher clock speed doesn't mean it is good, it takes more power consumption).

Hopper architecture ( needs cuda version atleast, compute capability.  cuda 11.8 toolkit)

https://developer.nvidia.com/cuda-gpus

https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#compute-capability-5-x

https://www.techpowerup.com/gpu-specs/a100-pcie-40-gb.c3623
https://www.techpowerup.com/gpu-specs/geforce-rtx-3090.c3622


on Demand GPU: https://docs.lambdalabs.com/public-cloud/
on Demand https://cloud.vast.ai/



