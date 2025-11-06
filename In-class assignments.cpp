// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include<iostream>

void inputArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
}

void printArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cout << nums[i] <<  ' ';
    
    std::cout << '\n';
}

void inputMatrix(int row, int column, float mat[][1000])
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            std::cin >> mat[i][j];
}

void setFloatPrecision(int precision)
{
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(precision);
}

void P01();
void P02();
void P05();
void P315();
void P320();

int main()
{
    std::cout << "In-class assignments\n";
    std::cout << "1. P01\n2. P02\n3. P05\n4. P315\n5. P320\n0. Exit\n";
    
    int choice;
    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                P01();
                break;
            case 2:
                P02();
                break;
            case 3:
                P05();
                break;
            case 4:
                P315();
                break;
            case 5:
                P320();
                break;
            case 0:
                std::cout << "Exitting the program...\n";
                break;
            default:
                std::cout << "Invalid command!\n";
                break;
        }
    } while (choice != 0);
    
    return EXIT_SUCCESS;
}

int largestEven(int n, int nums[]);
int smallestOdd(int n, int nums[]);

void P01()
{
    std::cout << "Largest even and smallest odd of an array:\n";
    int n;
    std::cout << "Enter the size, then all values\n";
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);
    
    try {
        int e = largestEven(n, nums);
        std::cout << e << ' ';
    } catch (const char* msg) {
        std::cout << msg << ' ';
    }
    
    try {
        int o = smallestOdd(n, nums);
        std::cout << o << '\n';
    } catch (const char* msg) {
        std::cout << msg << '\n';
    }
}

float evenAverage(int n, int nums[]);

void P02()
{
    std::cout << "Average of evens of an array:\n";
    int n;
    std::cout << "Enter the size, then all values\n";
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);
    
    setFloatPrecision(2);
    
    try {
        std::cout << evenAverage(n, nums) << '\n';
    } catch (const char* msg) {
        std::cout << msg;
    }
}

void swap(int& a, int& b);
void quicksort(int left, int right, int nums[]);
void sortEvens(int n, int nums[]);

void P05()
{
    std::cout << "Sorting even numbers:\n";
    int n;
    std::cout << "Enter the size, then all values\n";
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);
    
    sortEvens(n, nums);
    printArray(n, nums);
}

float largestInMatrix(int row, int column, float mat[][1000]);

void P315()
{
    std::cout << "Largest value in matrix:\n";
    int row, column;
    std::cout << "Enter the rowsize and columnsize (<= 1000) consecutively, then all the values\n";
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    
    inputMatrix(row, column, mat);
    
    setFloatPrecision(2);
    try {
        std::cout << largestInMatrix(row, column, mat) << '\n';
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
}

float positiveSum(int row, int column, float mat[][1000]);

void P320()
{
    std::cout << "Sum of all positive values in matrix:\n";
    int row, column;
    std::cout << "Enter the rowsize and columnsize (<= 1000) consecutively, then all the values\n";
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    
    inputMatrix(row, column, mat);
    
    setFloatPrecision(2);
    try {
        std::cout << positiveSum(row, column, mat) << '\n';
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    
}

int largestEven(int n, int nums[])
{
    bool containAns = false;
    int largestEven = INT_MIN;
    for (int i = 0; i < n; i++)
        if (nums[i] > largestEven && nums[i] % 2 == 0) {
            largestEven = nums[i];
            containAns = true;
        }
    
    if (!containAns) throw "No valid largest even!";
    
    return largestEven;
}

int smallestOdd(int n, int nums[])
{
    bool containAns = false;
    int smallestOdd = INT_MAX;
    for (int i = 0; i < n; i++)
        if (nums[i] < smallestOdd && nums[i] % 2 == 1) {
            smallestOdd = nums[i];
            containAns = true;
        }
    
    if (!containAns) throw "No valid smallest odd!";
    
    return smallestOdd;
}

float evenAverage(int n, int nums[])
{
    long long sum = 0LL;
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) {
            sum += nums[i];
            ++count;
        }
    }
    
    if (count == 0) throw "No even numbers!\n";
    return sum / (float)count;
}

void sortEvens(int n, int nums[])
{
    int evens[n];
    int id = 0;
    for (int i = 0; i < n; ++i)
        if (nums[i] % 2 == 0) {
            evens[id] = nums[i];
            ++id;
        }
    
    quicksort(0, id - 1, evens);
    int current = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) {
            nums[i] = evens[current];
            ++current;
        }
    }
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int left, int right, int nums[])
{
    int i = left, j = right;
    int pivot = nums[(left + right) / 2];
    
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

float largestInMatrix(int row, int column, float mat[][1000])
{
    if (row == 0 && column == 0)
            throw std::runtime_error("Matrix has no rows and columns!");
        if (row == 0 || column == 0)
            throw std::runtime_error("Matrix has missing dimension!");
    
    float largest = mat[0][0];
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            if (mat[i][j] > largest) largest = mat[i][j];
    
    return largest;
}

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
