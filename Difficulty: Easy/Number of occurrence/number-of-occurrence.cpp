class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
         int l=0;
        int h=nums.size()-1;
        
        int first=-1;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(target==nums[mid]){
                first=mid;
                h=mid-1;
            }

            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
      l=0;
      h=nums.size()-1;
      int last=-1;
      while(l<=h){
        long long mid=l+(h-l)/2;
            if(target==nums[mid]){
                last=mid;
                l=mid+1;
            }

            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
      }
      if (first == -1 || last == -1) return 0;  // target not found
     return last-first+1;
    }
};
