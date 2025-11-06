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

void swap(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void quicksort(int left, int right, float nums[])
{
    int i = left, j = right;
    float pivot = nums[(left + right) / 2];
    
    while (i <= j) {
        while (nums[i] < pivot) ++i;
        while (nums[j] > pivot) --j;
        if (i <= j) {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
    
    if (left < j) quicksort(left, j, nums);
    if (right > i) quicksort(i, right, nums);
}

void spiralSort(int row, int column, float mat[][1000])
{
    float flat[row * column];
    int id = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            flat[id] = mat[i][j];
            ++id;
        }
    }
    
    quicksort(0, id - 1, flat);
    
    id = 0;
    int top = 0, bottom = row - 1, left = 0, right = column - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j)
            mat[top][j] = flat[id++];
        ++top;
        
        for (int i = top; i <= bottom; ++i)
            mat[i][right] = flat[id++];
        --right;
        
        if (top <= bottom) {
            for (int j = right; j >= left; --j)
                mat[bottom][j] = flat[id++];
            --bottom;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                mat[i][left] = flat[id++];
            ++left;
        }
    }
}

int main()
{
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    inputMatrix(row, column, mat);
    
    spiralSort(row, column, mat);
    std::cout << "Sorted matrix:\n";
    outputMatrix(row, column, mat);
    
    return EXIT_SUCCESS;
}
