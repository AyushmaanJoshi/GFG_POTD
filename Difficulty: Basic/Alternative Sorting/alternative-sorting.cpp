//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> alternateSort(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Sort the array
        // Time complexity: O(nlogn)
        sort(arr.begin(), arr.end());
        
        // Step 2: Create result array
        // Space complexity: O(n)
        vector<int> result(n);
        
        // Step 3: Fill result array alternately with max and min elements
        // Two pointers: left for minimum elements, right for maximum elements
        int left = 0;  // pointing to smallest elements
        int right = n - 1;  // pointing to largest elements
        bool putMaximum = true;  // flag to alternate between max and min
        
        // Time complexity: O(n)
        for(int i = 0; i < n; i++) {
            if(putMaximum) {
                result[i] = arr[right];
                right--;
            } else {
                result[i] = arr[left];
                left++;
            }
            putMaximum = !putMaximum;  // toggle flag
        }
        
        return result;
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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends