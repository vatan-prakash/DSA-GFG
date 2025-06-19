class Solution {
  public:
     
    bool isPossible(vector<int> arr, int k,int n, int mid ){
        
        
        
        int count=1;
        int pages=0;
        
        for (int i = 0; i < n; i++) {
        if(arr[i]>mid) return false;
        if(pages+arr[i]>mid){
            count++;
            pages=arr[i];
        }
        else{
            pages+=arr[i];
        }
        
        if(count>k){
            return false;
        }
    }
        return true;
    } 
  
  
  
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
        
        if(k>n) return -1;
        
        int s = *max_element(arr.begin(), arr.end());

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int e = sum;
        int result=0;
        while(s<=e){
        int mid=s+(e-s)/2;
        
        if(isPossible(arr,k,n,mid)){
            result=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        
        }
        return result;
    }
};