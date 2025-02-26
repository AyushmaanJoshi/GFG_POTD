//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
    vector<int> left(n, -1), right(n, n);  // PSE & NSE indices
    stack<int> s;

    // Finding Previous Smaller Element (PSE)
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) left[i] = s.top();
        s.push(i);
    }

    // Clear stack for next step
    while (!s.empty()) s.pop();

    // Finding Next Smaller Element (NSE)
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) right[i] = s.top();
        s.push(i);
    }

    // Step 2: Compute result using window sizes
    vector<int> windowMax(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int window_size = right[i] - left[i] - 1;
        windowMax[window_size] = max(windowMax[window_size], arr[i]);
    }

    // Fill missing entries by propagating max values
    for (int i = n - 1; i >= 1; i--) {
        windowMax[i] = max(windowMax[i], windowMax[i + 1]);
    }

    // Ignore the first element (index 0 is unused)
    vector<int> result(windowMax.begin() + 1, windowMax.end());
    return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends