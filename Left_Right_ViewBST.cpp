#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void LeftView(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 1; i <= n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i == 1) //this give the 1st node of tree --> i.e leftmost node 
                cout << temp->data << "-> ";

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
void RightView(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 1; i <= n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i == n) //this give the last node of tree --> i.e rightmost node 
                cout << temp->data << "-> ";

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
int main() {
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->left= new Node(6);
    root->right->left->left= new Node(8);
    
    cout<<"\n******Left View Of Binary Tree*****\n";
    LeftView(root);
    cout<<endl;
    cout<<"\n******Right View Of Binary Tree*****\n";
    RightView(root);
    cout<<endl;
return 0;
}