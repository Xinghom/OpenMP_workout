#include <omp.h>
#include <stdio.h>
#include <stdlib.h> 

int main (int argc, char *argv[]) {
    int nthreads, tid;
    
    #pragma omp parallel private(nthreads, tid) 
    {
        // get thread number
        tid = omp_get_thread_num();
        printf("Hello world from thread = %d\n", tid);
        
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("number of threads = %d\n", nthreads);
        }
    }
    return 0;
}
