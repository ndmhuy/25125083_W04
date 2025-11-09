// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include<iostream>

void inputArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
}

int subArrayLargestSum(int n, int nums[], int k)
{
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    
    int max = sum;
    for (int i = 1; i + k - 1 < n; ++i) {
        sum -= nums[i - 1];
        sum += nums[i + k - 1];
        max = (sum > max) ? sum : max;
    }
    return max;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    int nums[n];
    inputArray(n, nums);
    
    std::cout << subArrayLargestSum(n, nums, k) << '\n';
    return EXIT_SUCCESS;
}
