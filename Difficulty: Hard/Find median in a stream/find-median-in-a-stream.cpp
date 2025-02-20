//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
    vector<double> result;
    priority_queue<int> maxHeap; // Stores smaller half (max heap)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Stores larger half (min heap)

    for (int num : arr) {
        // Step 1: Insert element into one of the heaps
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Step 2: Balance the heaps (size difference ≤ 1)
        if ((int)maxHeap.size() > (int)minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if ((int)minHeap.size() > (int)maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Step 3: Calculate the median
        if (maxHeap.size() == minHeap.size()) {
            result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
        } else {
            result.push_back(maxHeap.top());
        }
    }

    return result;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends