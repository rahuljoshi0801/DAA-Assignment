// Week 2

/*

2.Given a sorted array of positive integers, design an algorithm
and implement it using a program to find three indices i, j, k such that
arrli] + arr[j] = arr[k].
Input format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output:
The output will have T number of lines.
For each test case T, print the value of i, j and k, if found else print “No
sequence found”.

Input:
3
5
1 5 8 4 20
9
10
2 4 28 48 71 86 89 92 120 194
15
64 69 82 95 99 107 113 141 171 350 369 400 511 590 666

Output:
No sequence found
No sequence found
43, 95, 113


*/

#include <iostream>
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

        bool found = false;

        // Fix k from end
        for(int k = n - 1; k >= 2 && !found; k--)
        {
            int i = 0;
            int j = k - 1;

            while(i < j)
            {
                int sum = arr[i] + arr[j];

                if(sum == arr[k])
                {
                    cout << i+1 << ", " << j+1 << ", " << k+1 << endl;
                    found = true;
                    break;
                }
                else if(sum < arr[k])
                    i++;
                else
                    j--;
            }
        }

        if(!found)
            cout << "No sequence found" << endl;
    }

    return 0;
}
