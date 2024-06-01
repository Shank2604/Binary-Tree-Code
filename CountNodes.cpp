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

int countNodes(Tree* root){
    if(root == NULL) return 0;
    
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main(){
    Tree *root = new Tree(1);

    root->left = new Tree(2);
    root->right = new Tree(3);

    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    
    cout<<countNodes(root);
    

    return 0;
}