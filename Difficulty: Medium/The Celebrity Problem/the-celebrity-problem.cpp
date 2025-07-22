class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        for(int i=0;i<n;i++){
            bool rowZ=1;
            bool colZ=1;
            //check kr rhe row if sare elements 0 hai to
          for(int j=0;j<n;j++){
              if(mat[i][j]==1 && i!=j){
                  rowZ=0;
                  break;
              }
          }
        //mai 
          for(int j=0;j<n;j++){
              if(mat[j][i]==0 && i!=j){
                  colZ=0;
                  break;
              }
          }
          
          if(rowZ && colZ) {
              return i;
          }

        }
        
          return -1;
    }
};