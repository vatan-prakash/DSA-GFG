//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countWays(int n)
    {
        int MOD = 1000000007;  // 10^9 + 7
        vector<int> q(n + 1, -1);

        return countWaysHelper(n, q, MOD);
    }

    int countWaysHelper(int n, vector<int>& q, int MOD)
    {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;
        if (q[n] > -1)
            return q[n];

        int nM1 = countWaysHelper(n - 1, q, MOD);
        int nM2 = countWaysHelper(n - 2, q, MOD);
        int cp = (nM1 + nM2) % MOD;

        q[n] = cp;

        return cp;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends