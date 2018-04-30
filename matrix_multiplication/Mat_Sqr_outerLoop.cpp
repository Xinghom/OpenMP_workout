#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <omp.h>

#define ROW_NUM 1600
#define COL_NUM 1600
#define RANDOM_NUM_MAX 100
#define RANDOM_NUM_LOWER_BOUND 1

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

void printM(Mat m){
    if (m.empty()) {
        throw "Matrix is empty >.<";
    }
    int row = m.size();
    int col = m[0].size();
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << m[i][j] << " ";
        }
        cout << " | \n";
    }
}


int main(){
    int m = ROW_NUM, n = COL_NUM, i, j, row_1, col, row_2;
    int tID, numThreads, chunk = 10;
    // Allocate space for the vectors
    // If we initialize the vector length in this way, we can then assign individual elements directly, as in row[j] =
    // rather than with push_back.
    Vec row(n);
    Mat matrix;
    Mat result;
    srand(time(0));
 
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++) {
            row[j] = rand() % RANDOM_NUM_MAX + RANDOM_NUM_LOWER_BOUND;
        }
        matrix.push_back(row);
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++) {
            row[j] = 0;
        }
        result.push_back(row);
    }

    cout << "Matrix Ready" << endl;
    cout << "Matrix Squaring ..." << endl;

    #pragma omp parallel shared (matrix, result, numThreads, chunk) private(tID,row_1,col,row_2)
    {
        tID = omp_get_thread_num();
        if (tID == 0) {
            numThreads = omp_get_num_threads();
            cout << "Total Threads Number: " << numThreads << endl;
        }
        #pragma omp for schedule (static, chunk)
        for (row_1 = 0; row_1 < ROW_NUM; row_1++) {
            cout << "thread " << tID << " is doing row " << row_1 << endl;
            for (col = 0; col < COL_NUM; col++) {
                for (row_2 = 0; row_2 < ROW_NUM; row_2++) {
                    result[row_1][col] += matrix[row_1][row_2] * matrix[row_2][col];
                }
            }
        }
    }
    cout << "Square done." << endl;
//    try {
//        printM(result);
//    } catch (char const* msg) {
//        cout << msg << endl;
//    }
    return 0;
}

