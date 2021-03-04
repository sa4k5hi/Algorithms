#include<bits/stdc++.h>
using namespace std;

class BST {
    public:

    int data;
    BST* left;
    BST* right;
};

BST* nnode(int val) {
    BST* nn = new BST();
    nn->data = val;
    nn->left=NULL;
    nn->right=NULL;

}

void insert(BST** root,int val) {
    if((*root) == NULL) {
        BST* nn = nnode(val);

        *root = nn;

    } else {
        if(val < (*root)->data) {
            // BST* tem = (*root)->left;
            insert(&((*root)->left),val);
        } else {
            // BST* tem = (*root)->right;
            insert(&((*root)->right),val);
        }
    }
}

int main() {
    int n;
    cin>>n;
    BST* root =NULL;
    while(n--) {
        int val;
        cin >> val;
        insert(&root,val);
    }

    queue<BST*> q;
    q.push(root);
    
    while(!q.empty()) {
        BST* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left!=NULL) {
            q.push(temp->left);
        }
        if(temp->right!=NULL) {
            q.push(temp->right);
        }
    }


    return 0;

}