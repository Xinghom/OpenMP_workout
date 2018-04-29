#include <iostream>
#include <omp.h>
#include <chrono>

int main (int argc, char * argv[]) {
    // int nthread, tid;
    double x, pi, step, sum=0.0;
    int i;
    long num_steps = 1000000000; 
    step = 1./(double)num_steps;

    auto start = std::chrono::steady_clock::now( );
    #pragma omp parallel for private(x) reduction(+:sum)
    for (i=0; i<num_steps; i++) {
//        tid = omp_get_thread_num();
//        std::cout << "This thread is NO." << tid << std::endl;
        x = (i + .001)*step;
        sum = sum + 1.0/(1.+ x*x);
//        if (tid == 0) {
//            nthread = omp_get_num_threads();
//            std::cout << "Total threads: " << nthread << std::endl;
//        }
    }
    pi = 4.0*sum*step;
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - start );
    std::cout << pi << std::endl;
    std::cout << "Milliseconds since start: " << elapsed.count( ) << '\n';
    return 0;
}
