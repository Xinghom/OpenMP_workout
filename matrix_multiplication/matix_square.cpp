#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define ROW_NUM 1600
#define COL_NUM 1600
#define RANDOM_NUM_MAX 10

using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

// ** smart way to overload "*", then I can simply do like Vec b = a*x; ** //
// Vec operator*(const Mat &a, const Vec &x){
//     int i,j;
//     int m = a.size();
//     int n = x.size();

//     Vec prod(m);

//     for(i = 0; i < m; i++){
//         prod[i] = 0.;
//         for(j = 0; j < n; j++)
//         prod[i] += a[i][j]*x[j];
//     }
//     return prod;
// }

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
            row[j] = rand() % RANDOM_NUM_MAX;
        }
        matrix.push_back(row);
    }
    cout << "Matrix Ready" << endl;

    cout << "Matrix Squaring ..." << endl;
    Mat result;
    for (int row_1 = 0; row_1 < m; row_1++) {
        for(int col = 0; col < n; col++) {
            double sum;
            for (int row_2 = 0; row_2 < m; row_2++) {
                sum += matrix[row_1][row_2] * matrix[row_2][col];
            }
            row[col] = sum;
        }
        result.push_back(row);
        cout << to_string(row_1) + "/" + to_string(m) << endl;
    }
    cout << "square done." << endl;
    try {
        printM(result);
    } catch (char * msg) {
        cout << msg << endl;
    }
    
    return 0;
}

