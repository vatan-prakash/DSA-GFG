// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
       
       stack<int> st;
       int count=0;
       vector<int> result;
       for(int i=0;i<str.size();i++){
           
               if(str[i]=='('){
               count++;
               st.push(count);
              
               result.push_back(count);
           }
           
               else if(str[i]==')'){
                   result.push_back(st.top());
                   st.pop();
               }
               
          }
          
         
    
       
       return result;
        
    }
};