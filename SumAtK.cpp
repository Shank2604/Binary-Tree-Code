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

int sumAtK(Tree* node , int k){
    if(node == NULL) return -1;
    
    queue<Tree*> q;
    
    q.push(node);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    while(!q.empty()){
        Tree* node_1 = q.front();
        q.pop();
        if(node_1 != NULL){
            if(level == k) sum+=node_1->data;
            if(node_1->left){
                q.push(node_1->left);
            }
            if(node_1->right){
                q.push(node_1->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){
    Tree *root = new Tree(1);

    root->left = new Tree(2);
    root->right = new Tree(3);

    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    
    cout<<sumAtK(root,2);

    return 0;
}