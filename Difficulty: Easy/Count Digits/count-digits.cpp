//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    int evenlyDivides(int N){
        int c=0;
        int temp=N;
        
     while(temp>0){
      int rem=temp%10;
      temp=temp/10;
      
      if(rem>0 && (N%rem)==0) {
          c++;
      }
     }
        return c;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends