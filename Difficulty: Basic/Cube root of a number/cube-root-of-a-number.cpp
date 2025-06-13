class Solution {
public:
    int cubeRoot(int n) {
        long long l = 0;
        long long h = n;
        long long ans = 0;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            long long cube = mid * mid * mid;

            if (cube == n) {
                return mid;  // exact cube root
            }
            else if (cube < n) {
                ans = mid;   // possible answer
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        return ans;  // floor of cube root
    }
};
