// User function template for C++

class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) {
        
        unordered_set<int> st;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]!=0 && x%arr[i]==0 && st.count(x/arr[i])){
                return true;
            
            }
            
                st.insert(arr[i]);
        
        
        }
        return 0;
          
    }
};