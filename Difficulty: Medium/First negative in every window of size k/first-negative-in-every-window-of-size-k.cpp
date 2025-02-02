//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    deque<int> ans;
    vector<int> result;
    
    int i = 0, j = 0;
    
    while (j < arr.size()) {
        // Add negative numbers to deque
        if (arr[j] < 0) {
            ans.push_back(arr[j]);
        }

        // If window size not reached, move forward
        if (j - i + 1 < k) {
            j++;
        } 
        // When window size is exactly 'k'
        else if (j - i + 1 == k) {
            // If deque is empty, push 0; otherwise, push front element
            if (!ans.empty()) {
                result.push_back(ans.front());
            } else {
                result.push_back(0);
            }

            // Remove element going out of window
            if (!ans.empty() && arr[i] == ans.front()) {
                ans.pop_front();
            }
            
            // Slide the window
            i++;
            j++;
        }
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
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends