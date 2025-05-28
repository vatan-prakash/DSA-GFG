class Solution {
  public:
   
   void subseq( vector<int>& arr, int i,int n,  vector<vector<int>>& ans,  vector<int>& temp){
       if(i==n){
           ans.push_back(temp);
           return ;
       }
       
      subseq(arr, i+1,n,ans,temp);
      temp.push_back(arr[i]);
        subseq(arr, i+1,n,ans,temp);
        temp.pop_back();
       
   }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
       vector<vector<int>> ans;
       vector<int> temp;
       int n = arr.size();
       subseq(arr, 0,n,ans,temp);
            vector<int> result;

       for (const auto& vec : ans) {
       int sum = 0;
       for (int num : vec) {
        sum += num;
       }
       result.push_back(sum);
      }
       
        return result;
    }
};