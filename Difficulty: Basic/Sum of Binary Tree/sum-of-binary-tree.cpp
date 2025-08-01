/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
  
    
    int sumBT(Node* root) {
        // code here
        if(root==NULL) return 0;
        
         return root->data+sumBT(root->left)+sumBT(root->right);
    }
};