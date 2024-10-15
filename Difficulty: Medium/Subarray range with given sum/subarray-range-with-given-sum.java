//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

import java.util.HashMap;

class Solution {
    // Function to count the number of subarrays which adds to the given sum.
    static int subArraySum(int arr[], int tar) {
        // HashMap to store the frequency of prefix sums
        HashMap<Integer, Integer> prefixSumMap = new HashMap<>();
        
        int prefixSum = 0;  // Initialize the prefix sum
        int count = 0;      // Initialize the count of subarrays
        
        // Insert an initial prefix sum of 0 to handle subarrays that start from index 0
        prefixSumMap.put(0, 1);
        
        // Traverse the array
        for (int i = 0; i < arr.length; i++) {
            // Update the prefix sum
            prefixSum += arr[i];
            
            // Check if there is a prefix sum that satisfies the condition
            if (prefixSumMap.containsKey(prefixSum - tar)) {
                count += prefixSumMap.get(prefixSum - tar);
            }
            
            // Update the prefix sum frequency in the map
            prefixSumMap.put(prefixSum, prefixSumMap.getOrDefault(prefixSum, 0) + 1);
        }
        
        return count;  // Return the count of subarrays
    }
    
   
}



//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int tar = Integer.parseInt(br.readLine());
            Solution obj = new Solution();
            int res = obj.subArraySum(arr, tar);

            System.out.println(res);
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends