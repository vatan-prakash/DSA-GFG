//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> result;
         deque<int> list;
         int i =0;
         int j =0;
         
         while(j<arr.size()){
             
             //CALCULATION PART
             while(!list.empty() && list.back()<arr[j]){
                 list.pop_back();
             }
             
             list.push_back(arr[j]);
             
             if(j-i+1<k){
                 j++;
             }
             
           else if(j-i+1==k){
                 result.push_back(list.front());
                 //slide window
                 
                 if(list.front()==arr[i]){
                     list.pop_front();
                 }
                  i++; j++;

             }
            
             
             
         }
        
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends