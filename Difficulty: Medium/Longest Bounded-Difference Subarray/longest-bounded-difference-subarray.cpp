//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, maxLen = 0, startIdx = 0;
        multiset<int> window;  // Ordered set to track min & max elements

        for (int right = 0; right < n; right++) {
            window.insert(arr[right]);

            // Maintain valid window condition (max - min <= x)
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left])); // Remove leftmost element
                left++;  // Shrink the window
            }

            // Update the longest subarray found
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIdx = left;
            }
        }

        // Extract the longest subarray
        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
    }
};




//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends