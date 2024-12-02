# CudaExample
Cuda Examples 

Portable Batch System (PBS) and the Simple Linux Utility for Resource Management (Slurm) 

sample PBS 
qsub(queuesubmit) qstat, qdel, qalter

Slurm

#!/bin/bash
#SBATCH --job-name=parallel_sum
#SBATCH --output=job_output.txt
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=28
#SBATCH --time=01:20:00
#SBATCH --mail-type=ALL
#SBATCH --mail-user=mhossain44@students.tntech.edu
#SBATCH --account=ipdc-2018
cd /home/CAE/sridhar
./parallel_sum


Performance measure for GPU:

Throughput-calculated the number of floating points for second


Clock speed( sometimes higher clock speed doesn't mean it is good, it takes more power consumption).

Hopper architecture ( needs cuda version atleast  cuda 11.8 toolkit)
https://developer.nvidia.com/cuda-gpus

https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#compute-capability-5-x

https://www.techpowerup.com/gpu-specs/a100-pcie-40-gb.c3623
https://www.techpowerup.com/gpu-specs/geforce-rtx-3090.c3622


on Demand GPU: https://docs.lambdalabs.com/public-cloud/
on Demand https://cloud.vast.ai/



