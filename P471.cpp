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

void matMul(int rowA, int columnA, float matA[][1000], int rowB, int columnB, float matB[][1000], float result[][1000])
{
    if (columnA != rowB) throw std::runtime_error("Columnsize of A must match with rowsize of B!");
    
    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < columnB; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < columnA; ++k)
                sum += matA[i][k] * matB[k][j];
            result[i][j] = sum;
        }
    }
}

int main()
{
    int rowA, columnA;
    std::cin >> rowA >> columnA; // column <= 1000
    float matA[rowA][1000];
    inputMatrix(rowA, columnA, matA);
    
    int rowB, columnB;
    std::cin >> rowB >> columnB; // column <= 1000
    float matB[rowB][1000];
    inputMatrix(rowB, columnB, matB);
    
    try {
        float result[rowA][1000];
        matMul(rowA, columnA, matA, rowB, columnB, matB, result);
        outputMatrix(rowA, columnB, result);
        
    } catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    
    return EXIT_SUCCESS;
}
