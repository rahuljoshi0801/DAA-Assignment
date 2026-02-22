//Week 5
/*
Given an unsorted array of alphabets containing duplicate
elements. Design an algorithm and implement it using a program to find
which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)
Input Format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output:
The output will have T number of lines.
For each test case, output will be the array element which has
maximum occurrences and its total number of occurrences.
If no duplicates are present (i.e. all the elements occur only once),
output should be “No Duplicates Present”.
Sample 1/O Problem I:
Input: Output:
3 a-3
10 No Duplicates Present
aedwadqgafp 1-4
15
rkpgvyumagadjcze
20
gtllitcwawglcwdsaavcl 
*/
#include <bits/stdc++.h>
using namespace std;


// Finds alphabet with max occurrence
void findMaxOcc(vector<char>& arr) {
    vector<int> count(26, 0);

    for (char ch : arr) {
        count[ch - 'a']++;
    }

    int maxCount = 0;
    char result = '\0';

    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            result = char(i + 'a');
        }
    }

    if (maxCount <= 1) {
        cout << "No Duplicates Present\n";
    } else {
        cout << result << " " << maxCount << "\n";
    }
}

int main() {
    int T;
    cin >> T;

    vector<char> arr;   // declared outside loop

    while (T--) {
        int n;
        cin >> n;

         char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        arr.push_back(ch);
    }
        findMaxOcc(arr);

        arr.clear();   // clear for next test case
    }

    return 0;
}