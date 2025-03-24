//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    unordered_map<string, int> dp;

    int countWaysUtil(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];

        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            int LT = countWaysUtil(s, i, k - 1, true);
            int LF = countWaysUtil(s, i, k - 1, false);
            int RT = countWaysUtil(s, k + 1, j, true);
            int RF = countWaysUtil(s, k + 1, j, false);

            if (s[k] == '&') {
                ways += (isTrue) ? (LT * RT) : (LT * RF + LF * RT + LF * RF);
            } else if (s[k] == '|') {
                ways += (isTrue) ? (LT * RT + LT * RF + LF * RT) : (LF * RF);
            } else if (s[k] == '^') {
                ways += (isTrue) ? (LT * RF + LF * RT) : (LT * RT + LF * RF);
            }
        }
        return dp[key] = ways;
    }

    int countWays(string &s) {
        dp.clear();
        return countWaysUtil(s, 0, s.size() - 1, true);
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends