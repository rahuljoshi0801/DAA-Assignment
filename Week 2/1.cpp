// Week 2

/*

1.Given a sorted array of positive integers containing few duplicate
elements, design an algorithm and implement it using a program to find
whether the given key element is present in the array or not. If present,
then also find the number of copies of given key. (Time Complexity =
O(log n))
Input format:
The first line contains number of test cases, T. For each test case,
there will be three input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains the key element that need to be searched in the
array.
Output format:
The output will have T number of lines.
For each test case T, output will be the key element and its number of
copies in the array if the key element is present in the array otherwise
print “ Key not present”. 
Input:

2
8
1 2 2 2 3 4 5 5
2
5
10 20 30 40 50
25

Output:

Present 3
NotPresent
*/

#include <iostream>
using namespace std;

// Function to find first occurrence
int findFirst(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int first = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return first;
}

// Function to find last occurrence
int findLast(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int last = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return last;
}

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
        {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int first = findFirst(arr, n, key);

        if(first == -1)
        {
            cout << "Key not present" << endl;
        }
        else
        {
            int last = findLast(arr, n, key);
            int count = last - first + 1;

            cout << key << " " << count << endl;
        }
    }

    return 0;
}
