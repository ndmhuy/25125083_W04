// 25125083
// Nguyen Dinh Minh Huy
// 25A01

// Test case 1
// Input: 7 6 \n 3 5 12 67 80 45 678 \n 5 23 12 45 56 67
// Output: 5 12 45 67

// Test case 2
// Input: 7 6 / 3 5 12 67 67 45 678 \n 5 23 12 45 12 67
// Output: 5 12 45 67

// Test case 3
// Input: 2 2 \n 1 1 \n 1 1
// Output: 1

#include<iostream>
#include<unordered_set>

void inputArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
}

int main()
{
    int m, n;
    std::cin >> m >> n;
    int a[m], b[n];
    inputArray(m, a);
    inputArray(n, b);
    
    std::unordered_set<int> seenInA;
    for (int i = 0; i < m; ++i)
        seenInA.insert(a[i]);
    
    for (int i = 0; i < n; ++i)
        if (seenInA.find(b[i]) != seenInA.end()) {
            std::cout << b[i] << ' ';
            seenInA.erase(b[i]);
        }
    std::cout << '\n';

    return EXIT_SUCCESS;
}
