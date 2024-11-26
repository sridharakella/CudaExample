# <include stdio.h>
# <include cuda_runtime.sh> // vector addition ,each vector has 1024 elements , let say if you consider ampere architecture this is not possible with 2048 threads.

#define SIZE 1024;
    // define SIZE 1024*432*1024;

__global_ void vectorAdd(int* A, int* B, int* C, int n) // this method will be called by GPU
{
    int i=threadIdx.x;
    C[i]= A[i]+ B[i];
}

int main()
{
int * A, * B, * C; // host vector
int *d_A, * d_B, * d_C; // Device vectors 
int size= SIZE * sizeof(int)

A = (int*)malloc(size); // allocating memory
B = (int*)malloc(size);
c= (int *)malloc(size);

cudaMalloc((void**)&d_A,size);
cudaMalloc((void**)&d_B,size);
cudaMalloc((void**)&d_C,size);

for (int i=0 i<size; i++)
{
    A[i]=i;
    B[i]=SIZE-i;
}
cudaMemCpy(d_A,A,size,cudaMemCpyHostToDevice); // cudamemcpy Host is CPU and device is GPU
cudaMemCpy(d_B,B,size,cudaMemCpyHostToDevice); 

vectorAdd << <1,1024 >> > (d_A,d_b, d_C); // Ampere architecuture doesn't allow 2048 threads, let say we are talking vector have 1024 elements.
//vectorAdd << <2,1024 >> > (d_A,d_b, d_C);   //if we are doing the vector additon with 2048 elements, and ampere acrchitecture doesnt allow 2048 thread 
    // we need to increase the blocks from 1 to 2. so it woulbe <2,1024 >> .
    // vectorAdd << <1024*432,1024 >> > (d_A,d_b, d_C); // if the size is more than 2048 

cudaMemCpy(C, d_C, size, cudaMemcpyDeviceToHost); // once the vector addition is completed, copying from GPU to CPU

for(int i=0; i< SIZE; i++)
{
    printf("%d + %d = %d"), A[i], B[i], C[i];
    printf("\n");
}
cudaFree(d_A);
cudaFree(d_B);
cudaFree(d_C);
free(A);
free(B);
free(C);



}
