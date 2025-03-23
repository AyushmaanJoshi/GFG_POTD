//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0; // Invalid case

        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty string has 1 way to decode
        dp[1] = 1; // Single character, as long as it's not '0'

        for (int i = 2; i <= n; i++) {
            // Checking single-digit decoding (1-9)
            if (digits[i - 1] >= '1' && digits[i - 1] <= '9') {
                dp[i] += dp[i - 1];
            }

            // Checking two-digit decoding (10-26)
            int twoDigit = stoi(digits.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends