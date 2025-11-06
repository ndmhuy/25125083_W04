// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 7 \n 12 67 45 87 678 0 2
// Output: 87

// Test case 2
// Input: 8 \n 5 12 5 45 87 678 5 6
// Output: 87

// Test case 3
// Input: 3 \n 5 5 5
// Output: No second largest number!

#include<iostream>

void inputArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
}

int main()
{
    int n;
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);
    
    int largest = nums[0], secLargest = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > largest) {
            secLargest = largest;
            largest = nums[i];
        } else if (nums[i] > secLargest && nums[i] != largest) secLargest = nums[i];
    }
    
    std::string output = (secLargest > 0) ? std::to_string(secLargest) : "No second largest number!";
    std::cout << output << '\n';

    return EXIT_SUCCESS;
}
