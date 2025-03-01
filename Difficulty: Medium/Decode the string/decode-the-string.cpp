//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
       stack<int> numStack; // Stack to store repeat counts
    stack<string> strStack; // Stack to store intermediate decoded strings
    string currStr = ""; // Current working string
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Build multi-digit numbers
        } 
        else if (c == '[') {
            numStack.push(num); // Push the repeat count
            strStack.push(currStr); // Push current string
            num = 0;
            currStr = ""; // Reset current string
        } 
        else if (c == ']') {
            int repeatTimes = numStack.top();
            numStack.pop();
            
            string temp = currStr;
            for (int i = 1; i < repeatTimes; i++) {
                currStr += temp;
            }
            
            currStr = strStack.top() + currStr;
            strStack.pop();
        } 
        else {
            currStr += c; // Append characters to current string
        }
    }

    return currStr;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends