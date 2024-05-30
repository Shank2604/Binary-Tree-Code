#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
        int data;
        Tree* left;
        Tree* right;
    
        Tree(int val){
            data = val;
            left = NULL;
            right = NULL;            

        }
};

void printLevelOrder(Tree* node){
    if(node == NULL) return ;
    
    queue<Tree*> q;
    
    q.push(node);
    q.push(NULL);
    while(!q.empty()){
        Tree* node_1 = q.front();
        q.pop();
        if(node_1 != NULL){
            cout<<node_1->data<<" ";
            if(node_1->left){
                q.push(node_1->left);
            }
            if(node_1->right){
                q.push(node_1->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    
}

int main(){
    Tree *root = new Tree(1);

    root->left = new Tree(2);
    root->right = new Tree(3);

    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    
    printLevelOrder(root);

    return 0;
}