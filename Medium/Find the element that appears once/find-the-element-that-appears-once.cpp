//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    //code
	    int l=0;
	    int h=N-1;
	    if(A[0]!=A[1]) return A[0];
	    if(A[N-2]!=A[N-1]) return A[N-1];

	    while(l<=h){
	        int mid=l+(h-l)/2;
	        if(A[mid]!=A[mid+1] && A[mid-1]!=A[mid]) return A[mid];
	        if((mid%2==1 && A[mid-1]==A[mid])||(mid%2==0 &&  A[mid]==A[mid+1])){
	         l=mid+1;
	        }
	        else h=mid-1;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends