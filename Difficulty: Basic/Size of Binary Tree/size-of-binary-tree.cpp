/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* node) {
        // code here
        if(node==NULL) return 0;
        return 1+getSize(node->left)+getSize(node->right);
    }
};