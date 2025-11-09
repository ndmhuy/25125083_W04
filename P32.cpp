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

void printSubArray(int startIndex, int endIndex, int nums[])
{
    for (int i = startIndex; i <= endIndex; ++i) {
        if (i != endIndex) std::cout << nums[i] << ' ';
        else std::cout << nums[i];
    }
}

void subArraySumZero(int n, int nums[])
{
    std::unordered_map<long long, std::vector<int>> sumMap;
    sumMap[0].push_back(-1);
    
    long long sum = 0LL;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (sumMap.contains(sum))
            for (auto startId : sumMap[sum]) {
                std::cout << "{";
                printSubArray(startId + 1, i, nums);
                std::cout << "}\n";
            }
        
        sumMap[sum].push_back(i);
    }
}

int main()
{
    int n;
    std::cin >> n;
    int nums[n];
    inputArray(n, nums);
    
    subArraySumZero(n, nums);
    return EXIT_SUCCESS;
}
