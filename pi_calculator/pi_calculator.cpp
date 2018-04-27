#include <iostream>
#include <omp.h>

int main (int argc, char * argv[]) {
    int nthread, tid;
    double x, pi, step, sum=0.0;
    int i;
    long num_steps = 1000000000; 
    step = 1./(double)num_steps;
    #pragma omp parallel for private(x) reduction(+:sum)
    for (i=0; i<num_steps; i++) {
        tid = omp_get_thread_num();
        std::cout << "This thread is NO." << tid << std::endl;
        x = (i + .5)*step;
        sum = sum + 1.0/(1.+ x*x);

        if (tid == 0) {
            nthread = omp_get_num_thread();
            std::cout << "Total threads: " << nthread << std::endl;
        }
    }
    pi = 4.0*sum*step;
    std::cout << pi << std::endl;
    return 0;
}
