// User function template for C++
class Solution {
  public:
   
    void find(int n, 
    string& temp,
    vector<string>& ans,
    int one,
    int zero 
    ) 
    
    {
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        
        temp.push_back('1');
            find(n,temp,ans,one+1,zero);
            temp.pop_back();
        
        if(zero<one){
            temp.push_back('0');
            find(n,temp,ans,one,zero+1);
            temp.pop_back();
        }
         
        
    }
    
    vector<string> NBitBinary(int n) {
        // Your code goes here
        
    string temp;
    vector<string> ans;
    int one=0;
    int zero=0;
    
    find(n, temp, ans,one,zero);
    return ans;
        
        
    }
};