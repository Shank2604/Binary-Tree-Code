#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;

    Tree(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int searchVal(int in[],int curr,int start,int end){
    for(int i=start;i<=end;i++){
        if(in[i]==curr) return i;
    }
    return -1;
}

Tree* builtTree(int pre[],int in[],int start,int end){
    static int idx = 0;
    if(start > end) return NULL;

    
    int curr = pre[idx];
    idx++;

    Tree* node = new Tree(curr);

    if(start == end) return node;

    int pos = searchVal(in,curr,start,end);

    

    node->left = builtTree(pre,in,start,pos-1);
    node->right = builtTree(pre,in,pos+1,end);
    return node;
}


void inorder(Tree* node){
    if(node == NULL) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main(){
    int pre[] = {1,2,4,3,5};
    int in[] = {4,2,1,5,3};

    Tree* root = builtTree(pre,in,0,4);
    inorder(root);



    return 0;
}