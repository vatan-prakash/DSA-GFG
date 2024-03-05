//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
      long long int i = 0, j = 0;
    vector<long long> result;
    deque<long long> negIndices; // Using deque to efficiently remove the first element

    while (j < N) {
        // If the current element is negative, store its index in the deque
        if (A[j] < 0)
            negIndices.push_back(j);

        // If the window size is less than K, expand the window
        if (j - i + 1 < K)
            j++;
        else { // If the window size is equal to K
            // If there are no negative integers in the current window, push 0 to the result vector
            if (negIndices.empty())
                result.push_back(0);
            else { // Otherwise, push the first negative integer to the result vector
                result.push_back(A[negIndices.front()]);
                // If the index of the first negative integer is the same as the start of the window, remove it from the deque
                if (negIndices.front() == i)
                    negIndices.pop_front();
            }
            i++; // Move the start of the window forward
            j++; // Move the end of the window forward
        }
    }
    return result;
                                                 
 }