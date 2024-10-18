//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
public:
    int getSingle(vector<int>& arr) {
        int res = 0;
        
        // XOR all the elements. All duplicates will cancel each other out.
        for (int i = 0; i < arr.size(); i++) {
            res = res ^ arr[i];
        }
        
        // The remaining element will be the one that occurs only once.
        return res;
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
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends