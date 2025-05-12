//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
  public:
    vector<int> candyStore(int candies[], int n, int k) {
        // Write Your Code here
        sort(candies, candies+n);
        int i=0;
        int j=n-1;
        int minsum=0;
        int maxsum=0;
        vector<int> ans;
        while(i<=j){
            minsum+=candies[i];
           
            i++;
            j-=k;
        }
        ans.push_back(minsum);
        i=0;
        j=n-1;
        while(i<=j){
            maxsum+=candies[j];
            j--;
            i+=k;
        }
        ans.push_back(maxsum);
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends