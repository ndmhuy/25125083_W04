// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include<iostream>
#include<unordered_set>
#include<unordered_map>

// Helper functions
void setFloatPrecision(int precision)
{
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(precision);
}

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

void outputMatrix(int row, int column, float mat[][1000])
{
    setFloatPrecision(2);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cout << mat[i][j] << ' ';
            if (j == column - 1) std::cout << '\n';
        }
    }
}

// Problem function declarations
void P04();
void P08();
void P12();
void P26();
void P322();
void P347();
void P398();
void P423();
void P457();
void P471();

// Menu
int main()
{
    int choice;
    do {
        std::cout << "Homework assignments\n";
        std::cout << "1. P04 (Primes in array)\n";
        std::cout << "2. P08 (Remove k elements from array)\n";
        std::cout << "3. P12 (Second largest number)\n";
        std::cout << "4. P26 (Common elements in 2 arrays)\n";
        std::cout << "5. P322 (Sum of matrix rows)\n";
        std::cout << "6. P347 (Saddle points in matrix)\n";
        std::cout << "7. P398 (Rotate matrix border)\n";
        std::cout << "8. P423 (Spiral sort matrix)\n";
        std::cout << "9. P457 (Symmetric matrix check)\n";
        std::cout << "10. P471 (Matrix multiplication)\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: P04(); break;
            case 2: P08(); break;
            case 3: P12(); break;
            case 4: P26(); break;
            case 5: P322(); break;
            case 6: P347(); break;
            case 7: P398(); break;
            case 8: P423(); break;
            case 9: P457(); break;
            case 10: P471(); break;
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

// P04
bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    
    return true;
}

void P04()
{
    std::cout << "--- P04: Primes in array ---\n";
    int n;
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);

    int primes[n];
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (isPrime(nums[i]))
            primes[count++] = nums[i];

    std::cout << count << '\n';
    printArray(count, primes);
}

// P08
void remove(int n, int i, int k, int nums[])
{
    for (int id = i; id < n - k; ++id)
        nums[id] = nums[id + k];
}

void P08()
{
    std::cout << "--- P08: Remove k elements ---\n";
    int n, i, k;
    std::cin >> n >> i >> k;
    int nums[n];
    inputArray(n, nums);

    remove(n, i, k, nums);
    printArray(n - k, nums);
}

// P12
void P12()
{
    std::cout << "--- P12: Second largest number ---\n";
    int n;
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);

    int largest = nums[0];
    int secLargest = INT_MIN; // safer initial value

    for (int i = 1; i < n; ++i) {
        if (nums[i] > largest) {
            secLargest = largest;
            largest = nums[i];
        } else if (nums[i] > secLargest && nums[i] != largest) {
            secLargest = nums[i];
        }
    }

    if (secLargest == INT_MIN)
        std::cout << "No second largest number!\n";
    else
        std::cout << secLargest << '\n';
}

// P26
void P26()
{
    std::cout << "--- P26: Common elements ---\n";
    int m, n;
    std::cin >> m >> n;
    int a[m], b[n];
    inputArray(m, a);
    inputArray(n, b);

    std::unordered_set<int> seenInA;
    for (int i = 0; i < m; ++i)
        seenInA.insert(a[i]);

    for (int i = 0; i < n; ++i)
        if (seenInA.find(b[i]) != seenInA.end()) {
            std::cout << b[i] << ' ';
            seenInA.erase(b[i]);
        }
    std::cout << '\n';
}

// P322
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

void P322()
{
    std::cout << "--- P322: Sum of matrix rows ---\n";
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    
    inputMatrix(row, column, mat);
    
    setFloatPrecision(2);
    printRowSum(row, column, mat);
}

// P347
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

void P347()
{
    std::cout << "--- P347: Saddle points ---\n";
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];

    inputMatrix(row, column, mat);
    float maxRow[row], minColumn[column];
    findMaxMin(row, column, mat, maxRow, minColumn);

    std::cout << saddlePoints(row, column, maxRow, minColumn) << '\n';
}

// P398
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

void P398()
{
    std::cout << "--- P398: Rotate matrix border ---\n";
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    
    inputMatrix(row, column, mat);
    rotateBorder(row, column, mat);
    outputMatrix(row, column, mat);
}

// P423
void swap_float(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void quicksort_float(int left, int right, float nums[])
{
    int i = left, j = right;
    float pivot = nums[(left + right) / 2];

    while (i <= j) {
        while (nums[i] < pivot) ++i;
        while (nums[j] > pivot) --j;
        if (i <= j) {
            swap_float(nums[i], nums[j]);
            ++i;
            --j;
        }
    }

    if (left < j) quicksort_float(left, j, nums);
    if (right > i) quicksort_float(i, right, nums);
}

void spiralSort(int row, int column, float mat[][1000])
{
    int size = row * column;
    float flat[size];
    int id = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            flat[id] = mat[i][j];
            ++id;
        }
    }

    quicksort_float(0, id - 1, flat);

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

void P423()
{
    std::cout << "--- P423: Spiral sort matrix ---\n";
    int row, column;
    std::cin >> row >> column; // column <= 1000
    float mat[row][1000];
    inputMatrix(row, column, mat);

    spiralSort(row, column, mat);
    std::cout << "Sorted matrix:\n";
    outputMatrix(row, column, mat);
}


// P457
bool isSymmetric(int size, float mat[][1000])
{
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (mat[i][j] != mat[j][i]) return false;
    
    return true;
}

void P457()
{
    std::cout << "--- P457: Symmetric matrix check ---\n";
    int size;
    std::cin >> size; // column <= 1000
    float mat[size][1000];
    
    inputMatrix(size, size, mat);
    if (isSymmetric(size, mat)) std::cout << "Symmetric\n";
    else std::cout << "Asymmetric\n";
}

// P471
void matMul(int rowA, int columnA, float matA[][1000], int rowB, int columnB, float matB[][1000], float result[][1000])
{
    if (columnA != rowB)
        throw std::runtime_error("Column size of A and row size of B must be the same!");

    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < columnB; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < columnA; ++k)
                sum += matA[i][k] * matB[k][j];
            result[i][j] = sum;
        }
    }
}

void P471()
{
    std::cout << "--- P471: Matrix multiplication ---\n";
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
}
