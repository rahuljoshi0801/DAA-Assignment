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
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        unordered_map<int, int> freq;

        // Step 1: Build frequency map
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        bool found = false;

        // Step 2: Check for valid pair
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            int complement = key - x;

            if (freq.find(complement) != freq.end()) {

                if (x != complement) {
                    cout << x << " " << complement << endl;
                    found = true;
                    break;
                }
                else if (x == complement && freq[x] >= 2) {
                    cout << x << " " << complement << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "No Such Elements Exist" << endl;
        }
    }

    return 0;
}