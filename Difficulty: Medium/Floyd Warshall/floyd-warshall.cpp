//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
void shortest_distance(vector<vector<int>>& matrix){
    int n = matrix.size();
    
    // Replace -1 with a large number (infinity)
    const int INF = 100000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = INF;
            }
        }
    }
    
    // Floyd-Warshall algorithm to find shortest paths
    for(int via = 0; via < n; via++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // Update shortest path from i to j via vertex 'via'
                if(matrix[i][via] != INF && matrix[via][j] != INF){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }
    
    // Convert back large numbers to -1 (representing unreachable paths)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == INF){
                matrix[i][j] = -1;
            }
        }
    }
    
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends