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

void printSubArray(int startIndex, int endIndex, int nums[])
{
    for (int i = startIndex; i <= endIndex; ++i) {
        if (i != endIndex) std::cout << nums[i] << ' ';
        else std::cout << nums[i];
    }
}

void longestSubArrayTargetSum(int n, int nums[], long long q)
{
    std::unordered_map<long long, int> sumMap;
    sumMap[0] = -1;
    
    int longest = 0, endIndex = -1;
    long long sum = 0LL;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        long long target = sum - q;
        if (sumMap.contains(target)) {
            int currentLen = i - sumMap[target];
            if (currentLen > longest) {
                longest = currentLen;
                endIndex = i;
            }
        }
        if (!sumMap.contains(sum)) sumMap[sum] = i;
    }
    std::cout << "{";
    if (endIndex > -1) {
        int startIndex = endIndex - longest + 1;
        printSubArray(startIndex, endIndex, nums);
    }
    std::cout << "}\n";
}

int main()
{
    int n;
    long long q;
    std::cin >> n >> q;
    int nums[n];
    inputArray(n, nums);
    
    longestSubArrayTargetSum(n, nums, q);
    return EXIT_SUCCESS;
}
