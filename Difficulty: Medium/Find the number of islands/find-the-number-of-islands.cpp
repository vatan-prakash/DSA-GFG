//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
bool isValid(int i, int j, int n, int m, std::vector<std::vector<char>>& grid) {
    // Check if the cell is within the grid bounds and is land ('1')
    return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '1');
}

void DFS(int i, int j, int n, int m, std::vector<std::vector<char>>& grid) {
    // Mark the current cell as visited by setting it to '0'
    grid[i][j] = '0';
    
    // Array to explore all 8 possible directions
    int rowDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int k = 0; k < 8; ++k) {
        int newRow = i + rowDir[k];
        int newCol = j + colDir[k];
        if (isValid(newRow, newCol, n, m, grid)) {
            DFS(newRow, newCol, n, m, grid);
        }
    }
}

// Function to find the number of islands.
int numIslands(std::vector<std::vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int countIslands = 0;
    
    // Traverse the entire grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If a land cell ('1') is found, start a DFS and increment the island count
            if (grid[i][j] == '1') {
                ++countIslands;
                DFS(i, j, n, m, grid);
            }
        }
    }
    return countIslands;
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends