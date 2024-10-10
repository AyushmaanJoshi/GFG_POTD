//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxDistance(std::vector<int> &arr) {
        std::unordered_map<int, int> firstOccurrence; // stores the first occurrence of each element
        int maxDist = 0; // to keep track of the maximum distance
        
        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {
            if (firstOccurrence.find(arr[i]) == firstOccurrence.end()) {
                // If it's the first time we've encountered this element, store its index
                firstOccurrence[arr[i]] = i;
            } else {
                // If we've seen this element before, calculate the distance from the first occurrence
                int distance = i - firstOccurrence[arr[i]];
                // Update the maximum distance
                maxDist = std::max(maxDist, distance);
            }
        }
        
        return maxDist;
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
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends