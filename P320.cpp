// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 3 3 \n 1.0 2.0 3.0 9.0 8.0 7.0 5.0 4.0 6.0
// Output: 45.00

// Test case 2
// Input: 2 5 \n -3.0 4.5 7.5 1.0 1.15 -8.0 4.0 9.0 2.0 9.15
// Output: 38.30

// Test case 3
// Input: 0 0
// Output: Matrix has no rows and columns!

// Test case 3
// Input: 4 0
// Output: Matrix has missing dimension!

#include<iostream>

float positiveSum(int row, int column, float mat[][1000])
{
    if (row == 0 && column == 0)
            throw std::runtime_error("Matrix has no rows and columns!");
        if (row == 0 || column == 0)
            throw std::runtime_error("Matrix has missing dimension!");
    
    float sum = 0.0f;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            if (mat[i][j] > 0) sum += mat[i][j];
    
    return sum;
}

int main()
{
    int row, column;
    std::cin >> row >> column; // column <= 1000
    
    float mat[row][1000];
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            std::cin >> mat[i][j];
    
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);
    try {
        std::cout << positiveSum(row, column, mat) << '\n';
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    

    return EXIT_SUCCESS;
}
