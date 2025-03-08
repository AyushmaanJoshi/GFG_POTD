//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLength = 1;

        // Function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int newLength = right - left + 1;
                if (newLength > maxLength) {
                    start = left;
                    maxLength = newLength;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes (single-character center)
            expandAroundCenter(i, i);
            // Even-length palindromes (two-character center)
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends