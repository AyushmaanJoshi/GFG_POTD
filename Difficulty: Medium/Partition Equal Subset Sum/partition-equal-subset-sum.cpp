//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // If total sum is odd, partitioning is impossible
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: We can always make sum 0 (by taking an empty subset)
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] <= j) {  // Can include arr[i-1] in the subset
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {  // Cannot include arr[i-1]
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];  // Can we make sum = target using all elements?
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends