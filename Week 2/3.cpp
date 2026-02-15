// Week 2

/*

3. Given an array of nonnegative integers, design an algorithm and
a program to count the number of pairs of integers such that their
difference is equal to a given key, K.
Input format:
The first line contains number of test cases, T. For each test case,
there will be three input lines. First line contains n (the size of array). 
Second line contains space-separated integers describing array. Third
line contains the key element.
Output format:
The output will have T number of lines.
For each test case T, output will be the total count i.e. number of times
such pair exists. 

Input:
2
5
1 5 18 4 2
13
10
2 4 7 11 6 9 12 28 48 14
20
output:
1
1
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int K;
        cin >> K;

        sort(arr, arr + n);

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            int target = arr[i] + K;

            if(binary_search(arr + i + 1, arr + n, target))
                count++;
        }

        cout << count << endl;
    }

    return 0;
}
