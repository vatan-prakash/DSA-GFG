//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int m = matrix.size(); // row size
        int n = matrix[0].size();// col size
       
        int ans = 0;
        if(matrix.size()==1) return 0;
         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                     int countzero =0;
                    if(i>0 && matrix[i-1][j]==0) {  //check if zero exists above
                        countzero++;
                    }
                    
                    if(i<m-1 && matrix[i+1][j]==0) {  //check if zero exists below
                        countzero++;
                    }
                    
                     if(j<n-1 && matrix[i][j+1]==0) {  //check if zero exists right
                        countzero++;
                    }
                        if(j>0 && matrix[i][j-1] == 0){    //check if zero exists on left
                        countzero++;
                    }
                     //check if zero exists on right above diagonal
                     if(j<n-1 && i>0 && matrix[i-1][j+1]==0) { 
                        countzero++;
                    }
                        //check if zero exists on right below diagonal
                    if(j<n-1 && i<m-1 && matrix[i+1][j+1] == 0){
                        countzero++;
                    }
                         //check if zero exists on left above diagonal
                           if(j>0 && i>0 && matrix[i-1][j-1] == 0){
                        countzero++;
                    }
                       //check if zero exists on left below diagonal
                    if(i<m-1 && j>0 && matrix[i+1][j-1] == 0){
                        countzero++;
                    }
                    if(countzero%2==0 && countzero!=0){
                        ans++;
                    }
                }
                  else{
                    continue;
                }
            }
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends