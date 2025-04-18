//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
      unordered_map<int, int> freq;
    int xorSum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        xorSum ^= arr[i];  // prefix XOR till index i

        // Case 1: If current prefix XOR itself is k
        if (xorSum == k) count++;

        // Case 2: If there exists a prefix XOR such that xorSum ^ that = k
        int rem = xorSum ^ k;
        if (freq.find(rem) != freq.end()) {
            count += freq[rem];  // add how many times that XOR appeared
        }

        // Store current prefix XOR in map
        freq[xorSum]++;
    }

    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends