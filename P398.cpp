// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 7 6 \n 3 5 12 67 80 45 678 \n 5 23 12 45 56 67
// Output: 5 12 45 67

// Test case 2
// Input: 7 6 / 3 5 12 67 67 45 678 \n 5 23 12 45 12 67
// Output: 5 12 45 67

// Test case 3
// Input: 2 2 \n 1 1 \n 1 1
// Output: 1

#include<iostream>

void inputMatrix(int row, int column, float mat[][1000])
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            std::cin >> mat[i][j];
}

void outputMatrix(int row, int column, float mat[][1000])
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cout << mat[i][j] << ' ';
            if (j == column - 1) std::cout << '\n';
        }
    }
}

void rotateBorder(int row, int column, float mat[][1000])
{
    float temp = mat[0][column - 1];
    
    for (int j = column - 1; j >= 1; --j)
        mat[0][j] = mat[0][j - 1];
    for (int i = 0; i < row - 1; ++i)
        mat[i][0] = mat[i + 1][0];
    for (int j = 0; j < column - 1; ++j)
        mat[row - 1][j] = mat[row - 1][j + 1];
    for (int i = row - 1; i > 1; --i)
        mat[i][column - 1] = mat[i - 1][column - 1];
    
    mat[1][column - 1] = temp;
}

int main()
{
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    
    inputMatrix(row, column, mat);
    rotateBorder(row, column, mat);
    outputMatrix(row, column, mat);
    
    return EXIT_SUCCESS;
}
