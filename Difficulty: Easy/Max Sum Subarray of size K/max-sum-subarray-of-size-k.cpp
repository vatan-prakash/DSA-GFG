//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
      
        int i=0;
        int j=0;
        
        long long sum =0; long long maxsum=0;
        
        while(j<arr.size()){
             sum=sum+arr[j];
          if(j-i+1<k) {
              j++;
             
          }
          else if(j-i+1==k){
              maxsum=max(maxsum,sum);
              sum=sum-arr[i];
              i++;
              j++;
          }
        }
        return maxsum;
        
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
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends