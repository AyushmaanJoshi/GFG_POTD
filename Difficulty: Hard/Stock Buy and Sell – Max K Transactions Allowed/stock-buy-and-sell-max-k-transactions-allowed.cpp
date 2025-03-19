//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0; // Edge case

        // If k >= n/2, it's the same as unlimited transactions
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }

        // DP table to store max profit for each transaction and each day
        vector<int> prev(n, 0), curr(n, 0);

        for (int t = 1; t <= k; t++) {
            int maxDiff = -prices[0]; // Maximum difference (effective buy price)
            for (int d = 1; d < n; d++) {
                curr[d] = max(curr[d - 1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, prev[d] - prices[d]); // Track best buy price for `t-1`
            }
            swap(prev, curr); // Update prev for next iteration
        }

        return prev[n - 1]; // Max profit with at most k transactions
    }
};




//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends