// User function Template for C++
class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // Your code goes here
       stack<string> st;
       for(int i=0;i<arr.size();i++){
           if(!st.empty() && st.top()==arr[i]){
               st.pop();
               
           }else{
               st.push(arr[i]);
           }
       }
       
       int s=st.size();
       
       return s;
    }
};