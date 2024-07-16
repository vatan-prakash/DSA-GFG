//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Initialize distances to infinity (1e8) and set the source distance to 0
    vector<int> result(V, 1e8);
    result[S] = 0;

    // Relax all edges V-1 times
    for (int count = 1; count <= V - 1; ++count) {
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // If the distance to u is not infinity and the new distance is shorter, update it
            if (result[u] != 1e8 && result[u] + w < result[v]) {
                result[v] = result[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        // Ensure that the starting point of the edge is reachable
        if (result[u] != 1e8 && result[u] + w < result[v]) {
            return {-1};
        }
    }

    return result;

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends