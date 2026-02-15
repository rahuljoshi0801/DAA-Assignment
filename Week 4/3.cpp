// Week 4

/*

3.Given an unsorted array of integers, design an algorithm and
implement it using a program to find Kth smallest or largest element in
the array. (Worst case Time Complexity = O(n))
Input Format:
The first line contains number of test cases, T. For each test case,
there will be three input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array. Third
line contains K.
Output Format:
The output will have T number of lines.
For each test case, output will be the Kth smallest or largest array
element. If no Kth element is present, output should be “not present”.
Sample for Kth smallest:
Input: Output:
3 123
10 78
123 656 54 765 344 514 765 34 765 234
3
15
4364 13 78 864 346 786 456 21 19 8 434 76 270 601
8 

*/
#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

// Quickselect function
int quickSelect(vector<int>& arr, int low, int high, int k)
{
    if(low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if(pivotIndex == k)
            return arr[pivotIndex];

        else if(pivotIndex > k)
            return quickSelect(arr, low, pivotIndex - 1, k);

        else
            return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int K;
        cin >> K;

        if(K <= 0 || K > n)
        {
            cout << "not present" << endl;
            continue;
        }

        int result = quickSelect(arr, 0, n - 1, K - 1);

        if(result == -1)
            cout << "not present" << endl;
        else
            cout << result << endl;
    }

    return 0;
}
