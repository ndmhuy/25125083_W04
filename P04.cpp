// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 5 \n 2 6 3 8 5
// Output: 3 \n 2 3 5

// Test case 2
// Input: 5 \n 2 6 1 4 7
// Output: 2 \n 2 7

// Test case 3
// Input: 10 \n 2 3 5 7 11 13 17 19 23 29
// Output: 10 \n 2 3 5 7 11 13 17 19 23 29

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

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);
    
    int primes[n];
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (isPrime(nums[i])) primes[count++] = nums[i];
    
    std::cout << count << '\n';
    printArray(count, primes);

    return EXIT_SUCCESS;
}
