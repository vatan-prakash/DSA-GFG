//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(string &pat, string &s) {

      
       int ans = 0;
       
       unordered_map<char, int> mp;
        int k = pat.length();
       
       
       for (char ch : pat) {
        mp[ch]++;
       }
       
       int count = mp.size();
       
       int i=0;
       int j=0;
       
       while(j < s.length()){
           
           if(mp.find(s[j]) != mp.end()){
               mp[s[j]]--;
               
               if(mp[s[j]] == 0){
                   count--;
               }
           }
           
           if(j-i+1<k) {
               j++;
           }
           
           else if(j-i+1==k){
               if(count==0){
                   ans++;
               }
               
               if(mp.find(s[i]) != mp.end()) {
                   mp[s[i]]++;
                   if(mp[s[i]] == 1){
                       count++;
                   }
                   
               }
               
               i++;j++;
           }
           
           
       }
       return ans;
       
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends