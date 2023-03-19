#include <iostream>
using namespace std;
bool checkSparsematrix(int num[][3], int m);
main() {
    int m = 3;
    int num[m][3] = { {0,2,0},{0,5,0},{3,0,0} };
    bool sparsematrix = checkSparsematrix(num, m);
    if (sparsematrix == true) {
        cout << "THis is a sparse matrix";
    }
    else {
        cout << "THis is not a sparse matrix";
    }
}
bool checkSparsematrix(int num[][3], int m) {
    int count = 0;
    float check = (m * 3) / 2;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < 3;j++) {
            if (num[i][j] == 0) {
                count++;
            }
        }
    }
    if (count > check) {
        return true;
    }
    else {
        return false;
    }
}