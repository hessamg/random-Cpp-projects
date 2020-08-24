#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
        
    }
};
class Solution{
public:
    Node* insert(Node* root, int data){
        if(root==NULL){
            return new Node(data);
        }
        else{
            Node* cur;
            if(data<=root->data){
                cur=insert(root->left,data);
                root->left=cur;
            }
            else{
                cur=insert(root->right,data);
                root->right=cur;
            }
            return root;
        }
    }
    
    int getHeight(Node* root){
        if(!root) {
            return -1;
        }
        return (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right))+1;
        
    }
    
    void levelOrder(Node * root){
        queue<Node *> q;
        Node* n = root;
        
        while(n != NULL){
            cout << n->data << ' ';
            
            if( n->left  != NULL ) q.push(n->left);
            if( n->right != NULL ) q.push(n->right);
            
            if( !q.empty() ) {
                n = q.front();
                q.pop();
            } else {
                n = NULL;
            }
        }
    }
    
};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    int height = myTree.getHeight(root);
    cout << height;
    myTree.levelOrder(root);

    return 0;
}
