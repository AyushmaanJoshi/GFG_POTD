//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int n = arr.size();
        int result = 0;
        
        // Use difference array technique
        // diff will store count of x minus count of y
        // Map will store frequency of each difference
        unordered_map<int, int> diffFreq;
        int diff = 0;
        
        // Initialize with 0 difference seen once
        diffFreq[0] = 1;
        
        // Process each element
        for(int i = 0; i < n; i++) {
            // Update difference: +1 for x, -1 for y
            if(arr[i] == x) diff++;
            if(arr[i] == y) diff--;
            
            // Add count of previous occurrences of current difference
            // If we see same difference again, it means we found subarrays 
            // where count of x equals count of y
            result += diffFreq[diff];
            
            // Update frequency map
            diffFreq[diff]++;
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
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends