#include <iostream>
#include <omp.h>

int main (int argc, char * argv[]) {
    double x, pi, step, sum=0.0;
    int i;
    
    step = 1./(double)num_steps;
    #pragma omp parallel for private(x) reduction(+:sum)
    {
        for (i=0; i<num_steps; i++) {
        x = (i + .5)*step;
        sum = sum + 1.0/(1.+ x*x);
        }
    }
    pi = 4.0*sum*step;
    std::cout << pi << std::endl;
    return 0;
}
