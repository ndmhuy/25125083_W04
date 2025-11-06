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
#include<unordered_map>

void inputMatrix(int row, int column, float mat[][1000])
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            std::cin >> mat[i][j];
}

bool isSymmetric(int size, float mat[1000][1000])
{
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (mat[i][j] != mat[j][i]) return false;
    
    return true;
}

int main()
{
    int size;
    std::cin >> size; // column <= 1000
    float mat[size][1000];
    
    inputMatrix(size, size, mat);
    if (isSymmetric(size, mat)) std::cout << "Symmetric\n";
    else std::cout << "Asymmetric\n";
    
    return EXIT_SUCCESS;
}
