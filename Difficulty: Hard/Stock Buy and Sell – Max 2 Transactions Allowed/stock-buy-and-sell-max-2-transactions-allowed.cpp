//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> leftProfit(n, 0), rightProfit(n, 0);

        // Step 1: Compute leftProfit (Max profit possible if selling at index i)
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }

        // Step 2: Compute rightProfit (Max profit possible if buying at index i)
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }

        // Step 3: Find the best split where we combine both transactions
        int maxProfit = rightProfit[0]; // Single transaction case
        for (int i = 0; i < n - 1; i++) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i + 1]);
        }

        return maxProfit;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends