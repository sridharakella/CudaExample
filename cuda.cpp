# <include stdio.h>
# <include cuda_runtime.sh>

#define SIZE 1024;

__global_ void vectorAdd(int* A, int* B, int* C, int n)
{
    int i=threadIdx.x;
    C[i]= A[i]+ B[i];
}

int main()
{
int * A, * B, * C; // host vector
int *d_A, * d_B, * d_C; // Device vectors 
int size= SIZE * sizeof(int)

A = (int*)malloc(size);
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
cudaMemCpy(d_A,A,size,cudaMemCpyHostToDevice);
cudaMemCpy(d_B,B,size,cudaMemCpyHostToDevice);

vectorAdd << <1,1024 >> > (d_A,d_b, d_C)

cudaMemCpy(C, d_C, size, cudaMemcpyDeviceToHost)

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