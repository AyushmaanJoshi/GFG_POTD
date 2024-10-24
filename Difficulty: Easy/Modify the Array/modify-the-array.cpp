//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Modify the array by doubling the current element if the next element is equal and valid
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] *= 2;
                arr[i + 1] = 0; // Set the next element to 0 after doubling
            }
        }
        
        // Step 2: Rearrange the array by moving all non-zero elements to the front
        int nonZeroIndex = 0; // Index for placing non-zero elements
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex] = arr[i];
                nonZeroIndex++;
            }
        }
        
        // Step 3: Fill the rest of the array with zeros
        for (int i = nonZeroIndex; i < n; i++) {
            arr[i] = 0;
        }
        
        return arr;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends