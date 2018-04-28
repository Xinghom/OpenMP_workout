#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define ROW_NUM 1600
#define COL_NUM 1600

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

int main(){
    int m = ROW_NUM, n = COL_NUM;
    // Allocate space for the vectors
    Vec row(n);
    Mat matrix;
    srand(time(0));

    cout << "Matrix generating...\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            row[j] = rand() % 100;
        }
        // if (i <= 5) {
        //     for(int k = 0; k <10; k++)
        //         cout << row[k] << endl;
        // }
        matrix.push_back(row);
    }
    cout << "Matrix Ready" << endl;
    
}

