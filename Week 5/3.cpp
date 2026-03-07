/Week 5
/*
You have been given two sorted integer arrays of size m and n.
Design an algorithm and implement it using a program to find list of
elements which are common to both. (Time Complexity = O(m+n))
Input Format:
First line contains m (the size of first array).
Second line contains m space-separated integers describing first array.
Third line contains n (the size of second array).
Fourth line contains n space-separated integers describing second
array.
Output Format:
Output will be the list of elements which are common to both.
Sample 1/0O Problem IlI: 
Input: Output:
7 10 10 34 55
3476 1039851055
12
305534721034 1089 11 30 69 51
*/
#include <iostream>
using namespace std;

int main() {
    int m, n;

    cin >> m;
    int A[m];
    for(int i = 0; i < m; i++) {
        cin >> A[i];
    }

    cin >> n;
    int B[n];
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int i = 0, j = 0;

    while(i < m && j < n) {
        if(A[i] == B[j]) {
            cout << A[i] << " ";
            i++;
            j++;
        }
        else if(A[i] < B[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return 0;
}