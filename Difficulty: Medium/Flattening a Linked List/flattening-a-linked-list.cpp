//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    

  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* head1, Node* head2){
        Node* head=new Node(0);   
        Node* tail =head;
        
        while(head1 && head2){
            if(head1->data <= head2->data){
                tail->bottom=head1;
                head1 = head1->bottom;
                tail = tail->bottom;
                tail->bottom=NULL;
            }
            
            else{
                tail->bottom=head2;
                head2 = head2->bottom;
                tail = tail->bottom;
                tail->bottom=NULL;
            }
            
        }
        
        if(head1){
              tail->bottom=head1;
        }
        
        else {
              tail->bottom=head2;
        }
        //delete dummy then return head;
        return head->bottom;
    }
    
   Node *flatten(Node *root) {
    Node* head1, *head2, *head3;

    while (root && root->next) {
        head1 = root;
        head2 = root->next;
        head3 = root->next->next;

        head1->next = nullptr;
        head2->next = nullptr;

        root = merge(head1, head2);

        root->next = head3;
    }

    return root;

    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends