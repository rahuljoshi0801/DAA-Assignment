//Week 4

/*
1. Given an unsorted array of integers, design an algorithm and
implement it using a program to sort an array of elements by dividing
the array into two subarrays and combining these subarrays after
sorting each one of them. Your program should also find number of
comparisons and inversions during sorting the array.
Input Format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines. First line will give
the sorted array.
Second line will give total number of comparisons. Third line will give total number of inversions required. 
*/

#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;
long long inversions = 0;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        comparisons++;

        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            inversions += (n1 - i);
        }
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
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

        comparisons = 0;
        inversions = 0;

        mergeSort(arr, 0, n - 1);

        // print sorted array
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        // print comparisons
        cout << comparisons << endl;

        // print inversions
        cout << inversions << endl;
    }

    return 0;
}
