// User function template for C++

class Solution {
  public:
    int minTime(vector<int>& A, int k) {
        // code here
        int N=A.size();
        int M=k;
    int start = 0;
    int end = 0;
    for (int i = 0; i < N; i++) {
        start = max(start, A[i]); // minimum possible value (max of array)
        end += A[i];              // maximum possible value (sum of array)
    }
    
    
int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        int pages = 0, count = 1;
        for (int i = 0; i < N; i++) {
            pages += A[i];
            if (pages > mid) {
                count++;
                pages = A[i];
            }
        }

        if (count <= M) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
    }
};