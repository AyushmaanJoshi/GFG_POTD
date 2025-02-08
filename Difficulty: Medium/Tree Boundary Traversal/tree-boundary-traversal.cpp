//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/


class Solution {
  public:
    // Helper function to store left boundary nodes (excluding leaves)
    void getLeftBoundary(Node* root, vector<int>& res) {
        Node* cur = root->left;
        while (cur) {
            if (cur->left || cur->right) res.push_back(cur->data);
            cur = (cur->left) ? cur->left : cur->right;
        }
    }
    
    // Helper function to store leaf nodes (in-order traversal)
    void getLeafNodes(Node* root, vector<int>& res) {
        if (!root) return;
        getLeafNodes(root->left, res);
        if (!root->left && !root->right) res.push_back(root->data);
        getLeafNodes(root->right, res);
    }
    
    // Helper function to store right boundary nodes in reverse order (excluding leaves)
    void getRightBoundary(Node* root, vector<int>& res) {
        vector<int> temp;
        Node* cur = root->right;
        while (cur) {
            if (cur->left || cur->right) temp.push_back(cur->data);
            cur = (cur->right) ? cur->right : cur->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }
    
    // Main function to get boundary traversal
   vector<int> boundaryTraversal(Node* root) {
    if (!root) return {};

    vector<int> res;
    res.push_back(root->data);  // Add root node

    // Get left boundary (excluding root & leaves)
    getLeftBoundary(root, res);

    // Get leaf nodes (avoid root duplication)
    if (root->left || root->right) {
        getLeafNodes(root, res);
    }

    // Get right boundary (excluding root & leaves, stored in reverse order)
    getRightBoundary(root, res);

    return res;
}

};


//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends