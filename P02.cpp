// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 5 \n 2 6 3 8 5
// Output: 5.33

// Test case 2
// Input: 5 \n 2 4 6 8 10
// Output: 6.00

// Test case 3
// Input: 5 \n 1 3 5 7 9
// Output: No even numbers!

#include<iostream>

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

int main()
{
    int n;
    std::cin >> n;
    
    int nums[n];
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
    
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);
    
    try {
        std::cout << evenAverage(n, nums) << '\n';
    } catch (const char* msg) {
        std::cout << msg;
    }

    return EXIT_SUCCESS;
}
