// Week 1

/*

3.Given an already sorted array of positive integers, design an
algorithm and implement it using a program to find whether a given key
element is present in the sorted array or not. For an array arr[n], search
at the indexes arr[0], arr[2], arr[4],. ,arr[2k] and so on. Once the interval
(arr[2k] <
key < arr[ 2k+1] ) is found, perform a linear search operation from the
index 2k to find the element key. (Complexity < O(n), where n is the
number of elements need to be scanned for searching): Jump Search

Input:
2
8
10 20 30 40 50 60 70 80
50
5
10 20 30 40 50
35


Output:
Present 3
NotPresent 5


*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cin >> key;

        int step = 2;
        int comparisons = 0;
        bool found = false;

        int prev = 0;
        int i;

        // Jump phase
        for(i = 0; i < n; i += step)
        {
            comparisons++;

            if(arr[i] == key)
            {
                found = true;
                break;
            }

            if(arr[i] > key)
                break;

            prev = i;
        }

        // Linear search phase
        if(!found)
        {
            int end = (i < n) ? i : n-1;

            for(int j = prev; j <= end; j++)
            {
                comparisons++;

                if(arr[j] == key)
                {
                    found = true;
                    break;
                }
            }
        }

        if(found)
            cout << "Present " << comparisons << endl;
        else
            cout << "NotPresent " << comparisons << endl;
    }

    return 0;
}
