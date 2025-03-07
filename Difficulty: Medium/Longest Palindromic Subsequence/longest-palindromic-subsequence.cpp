//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  vector<vector<int>> dp;
    
    int solve(string &a, string &b, int i, int j) {
        if (i == a.length() || j == b.length()) {
            return 0;
        }
        
        if (dp[i][j] != -1) return dp[i][j];  
        
        if (a[i] == b[j]) {
            return dp[i][j] = 1 + solve(a, b, i + 1, j + 1);
        } else {
            return dp[i][j] = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
        }
    }
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        string s1=s;
        reverse(s1.begin(),s1.end());
        
        return solve(s1,s,0,0);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends