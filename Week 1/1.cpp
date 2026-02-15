// Week 1

/*

l. Given an array of nonnegative integers, design a linear algorithm
and implement it using a program to find whether given key element is
present in the array or not. Also, find total number of comparisons for
each input case. (Time Complexity = O(n), where n is the size of input)


Input:
3
8
34 35 65 31 25 89 64 30
89
5
977 354 244 546 355
244
6
2364 13 67 43 56 63
63

Output:
Present 6
Present 3
Present 6

*/

#include <bits/stdc++>
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

        int comparisons = 0;
        bool found = false;

        for(int i = 0; i < n; i++)
        {
            comparisons++;

            if(arr[i] == key)
            {
                found = true;
                break;
            }
        }

        if(found)
            cout << "Present " << comparisons << endl;
        else
            cout << "NotPresent " << comparisons << endl;
    }

    return 0;
}
