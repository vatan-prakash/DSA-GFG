//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
   
 void dfs(int node,vector<int> adj[], int vis[],vector<int> &lst){
       vis[node]=1;      //0 pe aya to one ho gya
       lst.push_back(node);
       //0 k nebours hai 2 3 1 
       // adjency list like 0->2 3 1 list phle 2 pe jaegi fir 2 k nebour dhundegi 4 and 0
       //but 0 ho chuka hai vist so uski value 1 hai to bas 4 jaega asie hi 
       // recursion call hoti jaegi depth me jate rhenge
       for(auto it: adj[node]){ 
           if(!vis[it]){
               dfs(it,adj,vis,lst);
           }
       }
   }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};   //v is vertex start me visted 0
        vector<int> lst;
        int start=0;   
        dfs(start,adj,vis,lst);
        return lst;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends