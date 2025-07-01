// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        vector<int> ans(1,1);
        int result;
        int carry=0;
        
        
        while(n>1){
            int size=ans.size();
            for(int i=0;i<size;i++){
                
                result = ans[i]*n + carry;
                carry= result/10;
                ans[i]=result%10;
                
            }
            
            while(carry){
                ans.push_back(carry%10);
                carry/=10;// taki carry kam ho ek digit
            }
            n--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};