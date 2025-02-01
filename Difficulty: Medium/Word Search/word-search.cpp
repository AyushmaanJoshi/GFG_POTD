//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    bool dfs(vector<vector<char>>& mat, int i, int j, string& word, int index) {
        // If we have found the whole word
        if (index == word.length()) return true;
        
        // Boundary checks and character match check
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) 
            return false;

        // Temporarily mark the cell as visited
        char temp = mat[i][j];
        mat[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(mat, i + 1, j, word, index + 1) ||  // Down
                     dfs(mat, i - 1, j, word, index + 1) ||  // Up
                     dfs(mat, i, j + 1, word, index + 1) ||  // Right
                     dfs(mat, i, j - 1, word, index + 1);    // Left

        // Restore the cell back after DFS
        mat[i][j] = temp;

        return found;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();

        // Start DFS from each matching first letter of the word
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, i, j, word, 0))
                    return true;
            }
        }
        
        return false;  // If no path is found
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends