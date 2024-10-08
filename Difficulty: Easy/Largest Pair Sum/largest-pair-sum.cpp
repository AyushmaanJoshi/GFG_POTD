//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int l=INT_MIN;
        int sl=INT_MIN;
        
        for (int i=0;i<arr.size();i++){
            if (arr[i]>l){
                l=arr[i];
            }
        }
        
        for (int i=0;i<arr.size();i++){
            if (arr[i]<l && arr[i]>sl){
                sl=arr[i];
            }
        }
        return l+sl;
        
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends