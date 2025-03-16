//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: If the first element is 0 and it's not the last element
        if (n == 1) return 0;
        if (arr[0] == 0) return -1;

        int jumps = 0, farthest = 0, currentEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);

            // If we reach the current boundary, we must take a jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // If we reached the end of the array, return jumps
                if (currentEnd >= n - 1) return jumps;
            }
        }

        return -1; // If we never reach the last index
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends