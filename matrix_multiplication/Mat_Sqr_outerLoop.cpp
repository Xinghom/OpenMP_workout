#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <omp.h>

#define ROW_NUM 100
#define COL_NUM 100
#define RANDOM_NUM_MAX 1
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
        cout << "--\n";
    }
}


int main(){
    int m = ROW_NUM, n = COL_NUM;
    // Allocate space for the vectors
    // If we initialize the vector length in this way, we can then assign individual elements directly, as in row[j] =
    // rather than with push_back.
    Vec row(n);
    Mat matrix;
    srand(time(0));

    cout << "Matrix generating...\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            row[j] = rand() % RANDOM_NUM_MAX + RANDOM_NUM_LOWER_BOUND;
        }
        matrix.push_back(row);
    }
    cout << "Matrix Ready" << endl;
    cout << "Matrix Squaring ..." << endl;
    
    Mat result;
    #pragma omp parallel shared(result) private(matrix, m, n)
    {
        #pragma omp for reduction(+:sum)
        for (int row_1 = 0; row_1 < m; row_1++) {
            for(int col = 0; col < n; col++) {
                double sum = 0;
                for (int row_2 = 0; row_2 < m; row_2++) {
                    sum += matrix[row_1][row_2] * matrix[row_2][col];
                }
                row[col] = sum;
            }
            result.push_back(row);
        }
    }
    cout << "Square done." << endl;
    try {
        printM(result);
    } catch (char * msg) {
        cout << msg << endl;
    }
    
    return 0;
}

