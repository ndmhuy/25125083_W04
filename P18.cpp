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

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// reverse on [startIndex, endIndex)
void reverse(int nums[], int startIndex, int endIndex)
{
    int left = startIndex, right = endIndex - 1;
    while (left < right)
    {
        swap(nums[left], nums[right]);
        ++left;
        --right;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    int nums[n];
    inputArray(n, nums);
    
    reverse(nums, 0, n);
    reverse(nums, 0, n - m);
    reverse(nums, n - m, n);
    
    printArray(n, nums);
    return EXIT_SUCCESS;
}
