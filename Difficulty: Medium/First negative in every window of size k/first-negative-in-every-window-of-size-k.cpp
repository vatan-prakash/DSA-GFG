//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> result;
        deque<int> dq;
        
        int i=0;
        int j=0;
        
        while(j<arr.size()){
            
            if(arr[j]<0){
                dq.push_back(arr[j]);
            }

            
           if(j-i+1==k){
                if(dq.empty()){
                        result.push_back(0);
                }
                
                
                else{
                    result.push_back(dq.front());
                }
                
                if(!dq.empty() && arr[i]==dq.front()){
                    dq.pop_front();
                }
                
                i++;
            }
            j++;
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
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends