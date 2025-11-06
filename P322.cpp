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

void setFloatPrecision(int precision)
{
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(precision);
}

void inputMatrix(int row, int column, float mat[][1000])
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            std::cin >> mat[i][j];
}

void printRowSum(int row, int column, float mat[][1000])
{
    for (int i = 0; i < row; ++i) {
        float sum = 0.0f;
        for (int j = 0; j < column; ++j)
            sum += mat[i][j];
        std::cout << sum << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    
    inputMatrix(row, column, mat);
    
    setFloatPrecision(2);
    printRowSum(row, column, mat);
    
    return EXIT_SUCCESS;
}
