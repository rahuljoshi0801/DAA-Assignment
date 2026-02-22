//Week 5

/*
Given an unsorted array of integers, design an algorithm and
implement it using a program to find whether two elements exist such
that their sum is equal to the given key element. (Time Complexity =
O(n log n))
Input Format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array. Third
line contains key
Output Format:
The output will have T number of lines.
For each test case, output will be the elements arr|i] and arr{j] such that
arr[i]+arr[j] = key if exist otherwise print '‘No Such Elements Exist”.
Sample 1/O Problem II:
Input: Output:
2 10 40
10 No Such Element Exist
64 28 97 40 1272 84 24 38 10
50
15
56 10729129341456120113991294
302
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