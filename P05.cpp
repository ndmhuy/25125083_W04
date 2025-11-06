// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 9 \n 9 8 7 6 5 4 3 2 1
// Output: 9 2 7 4 5 6 3 8 1

// Test case 2
// Input: 5 \n 2 6 1 4 7
// Output: 2 4 1 6 7

// Test case 3
// Input: 6 \n -3 4 -8 0 7 9
// Output: -3 -8 0 4 7 9

#include<iostream>

void swap(int& a, int& b);
void quicksort(int left, int right, int nums[]);
void printArray(int n, int nums[]);

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

int main()
{
    int n;
    std::cin >> n;
    
    int nums[n];
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    sortEvens(n, nums);
    printArray(n, nums);

    return EXIT_SUCCESS;
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

void printArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cout << nums[i] <<  ' ';
    
    std::cout << '\n';
}
