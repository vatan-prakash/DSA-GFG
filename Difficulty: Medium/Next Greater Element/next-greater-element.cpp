class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);  // result initialized with -1
        stack<int> st;  // stack to store next greater elements

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack is not empty, top is next greater
            if (!st.empty() && st.top() > arr[i]) {
                result[i] = st.top();
            }

            // Push current element to stack
            st.push(arr[i]);
        }

        return result;
    }
};
