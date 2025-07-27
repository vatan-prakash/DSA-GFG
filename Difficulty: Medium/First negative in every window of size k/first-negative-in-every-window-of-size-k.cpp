class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
       vector<int> result;
       deque<int> q;
       int i=0;int j=0;
       
       
       while(j<arr.size()){
           if(arr[j]<0) q.push_back(arr[j]);
         
        //   if(j-i+1<k) j++;
          
           if(j-i+1==k) {
             if(q.empty()){
                 result.push_back(0);
             }
             else{
                  result.push_back(q.front());
             }
             
             if(!q.empty() && arr[i]==q.front()){
                 q.pop_front();
                
             }
            i++;
               
           }
           
           j++;
           
           
       }
     return result;  
    }
};