//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& nums) {
        // code here
        vector<int> lis;
        for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);  // Find position
        if (it == lis.end()) {
            lis.push_back(num);  // Append if greater
        } else {
            *it = num;  // Replace with a smaller element
        }
    }
    
    return lis.size();
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends