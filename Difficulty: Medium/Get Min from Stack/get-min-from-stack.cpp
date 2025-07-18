class Solution {
  public:
    stack<int> s1;     // Actual stack
    stack<int> mins;   // Min-tracking stack
    
    Solution() {
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int val) {
        s1.push(val);
        if(mins.empty() || val<=mins.top()){
            mins.push(val);
        }
        // code here
    }

    // Remove the top element from the Stack
        
    void pop() {
        // code here
        if(s1.empty()) return ;
        
         if(s1.top()==mins.top()){
                mins.pop();
        }
        s1.pop();
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(s1.empty()) return -1;
        return s1.top();
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        
           if(mins.empty()) return -1;
              return mins.top();
           
    }
};