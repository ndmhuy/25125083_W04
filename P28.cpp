// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include<iostream>
#include<unordered_map>

void inputArray(int n, int nums[])
{
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];
}

void twoSum(int m, int a[], int n, int b[], int target)
{
    std::unordered_map<int, std::vector<int>> bMap;
    for (int j = 0; j < m; ++j) {
        bMap[b[j]].push_back(j);
    }
    
    for (int i = 0; i < n; ++i) {
        int other = target - a[i];
        if (bMap.contains(other))
            for (auto val : bMap[other])
                std::cout << "(" << i << "," << val << ")";
    }
    std::cout << '\n';
}

int main()
{
    int m, n;
    std::cin >> m >> n;
    int a[m], b[n];
    inputArray(m, a);
    inputArray(n, b);
    
    twoSum(m, a, n, b, 0);
    
    return EXIT_SUCCESS;
}
