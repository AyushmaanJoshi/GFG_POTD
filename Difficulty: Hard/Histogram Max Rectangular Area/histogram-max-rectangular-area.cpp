//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
    // Your code here
    int n = arr.size();
    stack<int> st;
    int maxArea = 0;
    
    for (int i = 0; i <= n; i++) {
        // Current height (0 when we reach the end of array)
        int currHeight = (i == n) ? 0 : arr[i];
        
        // While stack is not empty and the current height is less than the height at the top of stack
        while (!st.empty() && currHeight < arr[st.top()]) {
            // Get the height at the top of stack
            int height = arr[st.top()];
            st.pop();
            
            // Calculate width
            // If stack becomes empty, it means all elements to the left are greater
            // So the width is i, otherwise the width is (i - st.top() - 1)
            int width = st.empty() ? i : (i - st.top() - 1);
            
            // Calculate area and update maxArea if needed
            maxArea = max(maxArea, height * width);
        }
        
        // Push the current index onto the stack
        st.push(i);
    }
    
    return maxArea;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends