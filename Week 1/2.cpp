// Week 1

/*

2.Given an already sorted array of positive integers, design an
algorithm and implement it using a program to find whether given key
element is present in the array or not. Also, find total number of
comparisons for each input case. (Time Complexity = O(nlogn), where
n is the size of input). 

Input:
2
5
10 20 30 40 50
30
6
13 43 56 63 67 2364
100


Output:
Present 1
NotPresent 3

*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;  // number of test cases

    while(t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int low = 0;
        int high = n - 1;
        int comparisons = 0;
        bool found = false;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            comparisons++;

            if(arr[mid] == key)
            {
                found = true;
                break;
            }
            else if(arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if(found)
            cout << "Present " << comparisons << endl;
        else
            cout << "NotPresent " << comparisons << endl;
    }

    return 0;
}
