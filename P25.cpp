// 25125083
// Nguyen Dinh Minh Huy
// 25A01

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

void mergeSortedArray(int n, int a[], int m, int b[], int output[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) output[k++] = a[i++];
        else output[k++] = b[j++];
    }

    while (i < n)
        output[k++] = a[i++];

    while (j < m)
        output[k++] = b[j++];
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    int a[n], b[m];
    inputArray(n, a);
    inputArray(m, b);
    
    int output[n + m];
    mergeSortedArray(n, a, m, b, output);
    
    printArray(n + m, output);
    return EXIT_SUCCESS;
}
