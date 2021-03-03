#include<bits/stdc++.h>
using namespace std;

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

BST* nnode(int x) {
    BST *nn=new BST();
    nn->data=x;
    nn->left=NULL;
    nn->right=NULL;

    return nn;
}

BST* insert(int x,BST* root) {
    if(root==NULL) {
        BST* nn=nnode(x);

        return nn;
    }

    if(x<root->data) {
        root->left=insert(x,root->left);
    } else {
        root->right=insert(x,root->right);
    }

    return root;
}

void printt(BST* root) {
    if(root==NULL) {
        return;
    }
    printt(root->left);
    cout<<root->data<<" ";
    printt(root->right);
}


int main() {
    int n;
    cin>>n;
    BST* root=NULL;
    while(n--) {
        int d;
        cin>>d;
        root=insert(d,root);
    }

    printt(root);

    return 0;

}