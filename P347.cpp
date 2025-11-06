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

void findMaxMin(int row, int column, float mat[][1000], float maxRow[], float minColumn[])
{
    for (int i = 0; i < row; ++i)
        maxRow[i] = mat[i][0];
    for (int j = 0; j < column; ++j)
        minColumn[j] = mat[0][j];
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (mat[i][j] > maxRow[i]) maxRow[i] = mat[i][j];
            if (mat[i][j] < minColumn[j]) minColumn[j] = mat[i][j];
        }
    }
}

int saddlePoints(int row, int column, float maxRow[], float minColumn[])
{
    std::unordered_map<float, int> freq;
    for (int i = 0; i < row; ++i) {
        if (!freq.contains(maxRow[i])) freq[maxRow[i]] = 1;
        else ++freq[maxRow[i]];
    }
    
    int count = 0;
    for (int j = 0; j < column; ++j)
        if (freq.contains(minColumn[j])) count += freq[minColumn[j]];
    
    return count;
}

int main()
{
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    
    inputMatrix(row, column, mat);
    float maxRow[row], minColumn[column];
    findMaxMin(row, column, mat, maxRow, minColumn);
    
    std::cout << saddlePoints(row, column, maxRow, minColumn) << '\n';
    
    return EXIT_SUCCESS;
}
