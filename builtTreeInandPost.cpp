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


int searchPos(int in[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in[i]==curr) return i;
    }
    return -1;
}

Tree* builtTree(int post[],int in[],int start,int end){
    if(start > end) return NULL;
    static int idx = 4;

    int curr = post[idx];
    idx--;

    Tree* node = new Tree(curr);

    int pos = searchPos(in,start,end,curr);

    if(start == end) return node;
    node->right = builtTree(post,in,pos+1,end);
    node->left = builtTree(post,in,start,pos-1);

    return node;
}

void inorder(Tree* node){
    if(node == NULL) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void postorder(Tree* node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main(){

    int postOrder[] = {4,2,5,3,1};
    int inOrder[] = {4,2,1,5,3};

    Tree* root = builtTree(postOrder,inOrder,0,4);

    inorder(root);

    postorder(root);



    return 0;
}