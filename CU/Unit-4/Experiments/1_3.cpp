#include <iostream>
using namespace std;

// Function to multiply two matrices
void multiplyMatrix(int mat1[][100], int mat2[][100], int result[][100], int r1, int c1, int r2, int c2) {
    // Initializing elements of result matrix to 0
    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying matrices a and b and storing result in result matrix
    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c2; ++j) {
            for(int k = 0; k < c1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[100][100], mat2[100][100], result[100][100];
    int r1, c1, r2, c2;

    // Taking input for the size of first matrix
    cout << "Enter the number of rows and columns for first matrix: ";
    cin >> r1 >> c1;

    // Taking input for the elements of first matrix
    cout << "Enter the elements of first matrix:" << endl;
    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c1; ++j) {
            cin >> mat1[i][j];
        }
    }

    // Taking input for the size of second matrix
    cout << "Enter the number of rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // Taking input for the elements of second matrix
    cout << "Enter the elements of second matrix:" << endl;
    for(int i = 0; i < r2; ++i) {
        for(int j = 0; j < c2; ++j) {
            cin >> mat2[i][j];
        }
    }

    // Checking if matrices can be multiplied
    if(c1 != r2) {
        cout << "Matrix multiplication not possible!";
        return 0;
    }

    // Calling function to multiply matrices
    multiplyMatrix(mat1, mat2, result, r1, c1, r2, c2);

    // Displaying the result matrix
    cout << "Resultant matrix after multiplication:" << endl;
    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}