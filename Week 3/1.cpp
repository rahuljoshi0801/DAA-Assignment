//Week 3

/* 
l. Given an unsorted array of integers, design an algorithm and a
program to sort the array using insertion sort. Your program should be
able to find number of comparisons and shifts ( shifts - total number of
times the array elements are shifted from their place) required for
sorting the array.
Input Format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines. First line will give
the sorted array.
Second line will give total number of comparisons.
Third line will give total number of shift operations required.*/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, long long &comp, long long &shift)
{
    int n = arr.size();

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // compare and shift
        while(j >= 0)
        {
            comp++; // comparison

            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
                shift++; // shift
                j--;
            }
            else
                break;
        }

        arr[j + 1] = key;
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

        long long comp = 0;
        long long shift = 0;

        insertionSort(arr, comp, shift);

        // print sorted array
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        // print comparisons
        cout << comp << endl;

        // print shifts
        cout << shift << endl;
    }

    return 0;
}


