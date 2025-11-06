// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 7 3 2 \n 12 67 45 87 678 0 2
// Output: 12 67 45 0 2

// Test case 2
// Input: 7 2 1 \n 12 67 45 87 678 0 2
// Output: 12 67 87 678 0 2

// Test case 3
// Input: 10 3 4 \n 9 18 76 87 54 65 67 34 23 21
// Output: 9 18 76 34 23 21 

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

void remove(int n, int i, int k, int nums[])
{
    for (int id = i; id < n - k; ++id)
        nums[id] = nums[id + k];
}

int main()
{
    int n, i, k;
    std::cin >> n >> i >> k;
    int nums[n];
    inputArray(n, nums);
    
    remove(n, i, k, nums);
    printArray(n - k, nums);

    return EXIT_SUCCESS;
}
