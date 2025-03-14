//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum + 1, 1e9); // Initialize with a large value
        dp[0] = 0; // Base case
        
        for (int c : coins) { // Iterate through each coin
            for (int i = c; i <= sum; i++) { 
                dp[i] = min(dp[i], 1 + dp[i - c]); 
            }
        }
        
        return (dp[sum] == 1e9) ? -1 : dp[sum]; // If no solution, return -1
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends