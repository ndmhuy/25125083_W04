// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include<iostream>
#include<algorithm>
#include<unordered_map>

void inputArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
}

bool isPrime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

void buildPrimeSieve(int size, bool sieve[])
{
    sieve[0] = sieve[1] = false;
    for (int p = 2; p * p < size; ++p) {
        if (sieve[p]) {
            for (int i = p * p; i < size; i += p)
                sieve[i] = false;
        }
    }
}

int countPrimes(int n, int nums[])
{
    
    int count = 0;
    if (n <= 4400) {
        // isPrime()
        for (int i = 0; i < n; ++i)
            if (isPrime(nums[i])) ++count;
    }
    else {
        // Erastothenes Sieve
        int size = 1000000;
        bool sieve[size];
        std::fill(sieve, sieve + size, true);
        buildPrimeSieve(size, sieve);
        
        for (int i = 0; i < n; ++i)
            if (nums[i] < size && nums[i] >= 0) {
                if (sieve[nums[i]]) ++count;
            } else if (isPrime(nums[i])) ++count;
    }
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);
    
    std::cout << countPrimes(n, nums) << '\n';
    return EXIT_SUCCESS;
}
