//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  bool isBipartiteDFS(vector<int>adj[],int curr,vector<int>& color, int currColor){
      color[curr]=currColor;
      
      for(int &v:adj[curr]){
          if(color[v]==color[curr]){
              return false;
          }
          else if(color[v]==-1){
              int colorOfcurr=1-currColor;
            if(!isBipartiteDFS(adj, v, color ,colorOfcurr)){
                return false;
            }
          }
      }
      return true;
      
  }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(isBipartiteDFS(adj,i,color, 1)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends