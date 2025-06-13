

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        
        int l=0;
        int h=arr.size()-1;
        int fx=-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==0){
                fx=mid;
                h=mid-1;
            
            }
            else {
                l=mid+1;
            }
        }
        if(fx==-1){
            return 0;
        }
        return arr.size()-fx;
      
    }
};