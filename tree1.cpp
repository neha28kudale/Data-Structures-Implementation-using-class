#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
int height(Node* root){
    if(!root) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH,rightH)+1;
}
int diameterofTree(Node* root){
    if(!root) return 0;
    int currDia = height(root->left)+height(root->right);
    int left = diameterofTree(root->left);
    int right = diameterofTree(root->right);
    return max(currDia, max(left,right));
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<< " -> ";
    inorder(root->right);
}
void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<< " -> ";
}
void preorder(Node* root){
    if(!root) return;
    cout<<root->data<< " -> ";
    preorder(root->left);
    preorder(root->right);
}
void levelOrder(Node* root){
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" -> ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);

    root->right->left = new Node(6);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);

    cout<<"Diameter of Tree is : "<<diameterofTree(root);
    cout<<"\nInorder Traversal : ";
    inorder(root);
    cout<<"\npostorder Traversal : ";
    postorder(root);
    cout<<"\npretorder Traversal : ";
    preorder(root);
    cout<<"\nLevel order Traversal : ";
    levelOrder(root);
    return 0;
}