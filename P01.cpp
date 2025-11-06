// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 5 \n 2 6 3 8 5
// Output: 8 3

// Test case 2
// Input: 5 \n 2 4 6 8 10
// Output: 10 No valid smallest odd!

// Test case 3
// Input: 5 \n 1 3 5 7 9
// Output: No valid largest even! 1

// Test case 4
// Input: 0
// Output: No valid largest even! No valid smallest odd!

#include<iostream>

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

int main()
{
    int n;
    std::cin >> n;
    
    int nums[n];
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
    
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

    return EXIT_SUCCESS;
}
