//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        int count = 0;

        // Function to expand around a center and count palindromes
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) // Ensure palindrome length ≥ 2
                    count++;
                left--;
                right++;
            }
        };

        // Expand around each character (odd and even-length palindromes)
        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd-length palindromes
            expand(i, i + 1); // Even-length palindromes
        }

        return count;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends