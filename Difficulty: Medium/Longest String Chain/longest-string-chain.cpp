//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   static bool compare(const string &a, const string &b) {
        return a.size() < b.size();
    }
    int longestStringChain(vector<string>& words) {
        // Code here
          sort(words.begin(), words.end(), compare);

        unordered_map<string, int> dp;
        int maxLength = 1;

        // Step 2: Process each word
        for (string word : words) {
            dp[word] = 1;  // Every word is at least a chain of length 1
            
            // Step 3: Try removing each character and check predecessor
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1); // Remove one character
                
                if (dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }
            
            maxLength = max(maxLength, dp[word]); // Track max chain length
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends