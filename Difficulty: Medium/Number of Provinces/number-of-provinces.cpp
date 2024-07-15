//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void dfs(vector<vector<int>>& adj, int u, vector<bool> &vis) {
        vis[u] = true;
        
        for(int v = 0; v < adj[u].size(); v++) {
            if(!vis[v] && adj[u][v] == 1) {
                dfs(adj, v, vis);
            }
        }
    }
  
    int numProvinces(vector<vector<int>>& adj, int V) {
        int c = 0;
        vector<bool> vis(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                c++;
                dfs(adj, i, vis);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends