// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
    int n= stalls.size();
    sort(stalls.begin(),stalls.end());
    int s=1;
    int e=stalls[n-1]-stalls[0];
    int ans=0;
    // if(n<=k) return 0;
    
    while(s<=e){
    int mid=s+(e-s)/2;    
        
    int count =1;
    int pos=stalls[0];
    
   
    
    for(int i=1;i<n;i++){
    if(pos+mid<=stalls[i]){
        count++;
        pos=stalls[i];
    }
    }
    
    if(count<k){
        e=mid-1;  //means cow allot nhi ho pare so distance ka, kro
    }
    else{
        ans=mid;
        s=mid+1;
    }
    
    
    }
    
    return ans;
        
    }
};