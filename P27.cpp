// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include<iostream>

void inputArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
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
    
    while (i <= j)
    {
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

int main()
{
    int m, n, q;
    std::cin >> m >> n >> q;
    int a[m], b[n];
    inputArray(m, a);
    inputArray(n, b);
    
    quicksort(0, m - 1, a);
    quicksort(0, n - 1, b);
    
    int min = INT_MAX;
    int i = 0, j = n - 1;
    int aId = i, bId = j;
    while (i < m && j >= 0)
    {
        int current = a[i] + b[j];
        if (current > q) {
            if (current < min) {
                min = current;
                aId = i;
                bId = j;
            }
            --j;
        }
        else ++i;
    }
    
    if (min < INT_MAX) std::cout << "a[" << aId << "] + b[" << bId << "] = " << min << '\n';
    else std::cout << "There are no such pairs!\n";
    return EXIT_SUCCESS;
}
