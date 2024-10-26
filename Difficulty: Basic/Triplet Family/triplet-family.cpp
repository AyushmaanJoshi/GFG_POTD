//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        
        // If array has less than 3 elements, return false
        if (n < 3) return false;
        
        // Sort the array to make it easier to find pairs
        sort(arr.begin(), arr.end());
        
        // Fix the largest element and try to find two numbers that sum to it
        // We iterate from largest to second element
        for (int i = n-1; i >= 2; i--) {
            int target = arr[i];  // This is the potential sum we're looking for
            
            // Use two pointer technique to find pair that sums to target
            int left = 0;
            int right = i-1;
            
            while (left < right) {
                int current_sum = arr[left] + arr[right];
                
                // If we found a pair that sums to target
                if (current_sum == target) {
                    return true;
                }
                // If current sum is less than target, move left pointer
                else if (current_sum < target) {
                    left++;
                }
                // If current sum is more than target, move right pointer
                else {
                    right--;
                }
            }
        }
        
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends