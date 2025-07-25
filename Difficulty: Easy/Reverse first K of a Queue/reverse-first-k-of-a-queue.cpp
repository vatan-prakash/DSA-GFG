class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (q.size() < k) return q;  // if k is larger than size, return original queue

        stack<int> st;

        // Step 1: Push first k elements into the stack
        for (int i = 0; i < k; ++i) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue elements from the stack back to the queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move the remaining (size - k) elements to the back
        int rem = q.size() - k;
        while (rem--) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
