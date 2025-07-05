// User function Template for C++

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> stacks;
        
      while(!st.empty()){
           int c = st.top();
           stacks.push(c);
           st.pop();
        }
        
        st.push(x);
        
        while(!stacks.empty()){
            int c = stacks.top();
           st.push(c);
           stacks.pop();
        }
        
        return st;
    }
};