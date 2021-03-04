#include<bits/stdc++.h>
using namespace std;

class BST {
    public:
    int data;
    BST* left;
    BST* right;
};

BST* nnode(int val) {
    BST* nn=new BST();
    nn->data=val;
    nn->left=NULL;
    nn->right=NULL;

    return nn;
}

int height(BST* root) {
    if(root==NULL) {
        return 0;
    }

    return max(height(root->left),height(root->right)) +1;
}

void bfs(BST* root, int i) {
    if(i==0) {
        cout<<root->data<<" ";
    }
    if(root->left!=NULL)
    bfs(root->left,i-1);
    if(root->right!=NULL)
    bfs(root->right,i-1);
}

void level(BST* root) {
    int h=height(root);

    for(int i=0;i<h;i++) {
        bfs(root,i);
    }
}

void insert(BST** root,int val) {
    // cout<<"hey"<<endl;
    if((*root) == NULL) {
        BST* nn=nnode(val);
        *root=nn;
    } else {
        if((*root)->data > val) {
            insert(&((*root)->left),val);
        } else {
            insert(&((*root)->right),val);
        }
    }
}

int main() {
    int n;
    cin>>n;
    BST* root=NULL;
    while(n--) {
        int val;
        cin>>val;
        insert(&root,val);
    }

    level(root);


    return 0;
}