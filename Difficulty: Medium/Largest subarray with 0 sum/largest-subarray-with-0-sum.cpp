//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
      unordered_map<int, int> prefixSumMap;
        int sum = 0;          // Prefix sum variable
        int maxLength = 0;    // Variable to store the maximum length of subarray with sum 0

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i]; // Calculate the running prefix sum

            // Case 1: If the prefix sum becomes 0, the subarray from 0 to i has sum 0
            if (sum == 0) {
                maxLength = max(maxLength, i + 1);
            }

            // Case 2: If the prefix sum has been seen before
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                // Calculate the length of the subarray between the previous occurrence and the current index
                maxLength = max(maxLength, i - prefixSumMap[sum]);
            } else {
                // Case 3: If the prefix sum is seen for the first time, store it in the map
                prefixSumMap[sum] = i;
            }
        }

        return maxLength;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends