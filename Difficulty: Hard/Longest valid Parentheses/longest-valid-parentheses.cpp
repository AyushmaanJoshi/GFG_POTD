//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int maxLength(string& s) {
        stack<int> st;
        st.push(-1);  // Base index before the first character
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(i);  // Store the index of the opening bracket
            } else {
                if (!st.empty()) {
                    st.pop();  // Pop the last opening bracket index
                }
                // If stack is empty, push current index (resetting the sequence)
                if (st.empty()) {
                    st.push(i);
                } else {
                    // Calculate the current valid substring length
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends