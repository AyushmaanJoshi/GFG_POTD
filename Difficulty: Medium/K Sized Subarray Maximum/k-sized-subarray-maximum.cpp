//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq;
        
        for (int i = 0; i < arr.size(); i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove all elements smaller than current element from back
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            // Add current element index to deque
            dq.push_back(i);
            
            // Store maximum for current window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends