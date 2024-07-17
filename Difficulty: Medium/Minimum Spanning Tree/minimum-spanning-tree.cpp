//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef pair<int,int> P;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
     // Priority queue to store the edges based on their weights.
    // Stored as {weight, node} to prioritize by the smallest weight.
    priority_queue<P, vector<P>, greater<P>> pq;
    
    // To keep track of whether a node is included in the MST.
    vector<bool> inMST(V, false);
    
    // Initialize the sum of weights of the MST.
    int sum = 0;

    // Start with the first node (node 0) with weight 0.
    pq.push({0, 0});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int wt = p.first;  // Weight of the edge
        int node = p.second;  // Current node

        // If the node is already included in the MST, skip it.
        if (inMST[node]) continue;

        // Mark the node as included in the MST.
        inMST[node] = true;
        // Add the weight of the edge to the total sum.
        sum += wt;

        // Traverse all adjacent nodes (neighbors)
        for (auto &it : adj[node]) {
            int neighbour_node = it[0];  // Adjacent node
            int neighbour_wt = it[1];  // Weight of the edge to the adjacent node

            // If the adjacent node is not yet included in the MST, push it to the priority queue
            // with its edge weight.
            if (!inMST[neighbour_node]) {
                pq.push({neighbour_wt, neighbour_node});
            }
        }
    }
    return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends