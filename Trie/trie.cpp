#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    bool isEnd;
    TrieNode* links[26];
    TrieNode() {
        isEnd=false;
        for(int i=0;i<26;i++) {
            links[i]=NULL;
        }
    }
};

TrieNode* insert(TrieNode* root, string s) {
    int k=s.size();
    TrieNode* curr=root;
    for(int i=0;i<k;i++) {
        int x=s[i]-'a';
        if(curr->links[x]==NULL) {
            TrieNode* temp=new TrieNode();
            curr->links[x]=temp;
        }
        curr=curr->links[x];
    }

    curr->isEnd=true;

    return root;
}

bool search(TrieNode* root,string s) {
    int k=s.size();
    TrieNode* curr= root;
    for(int i=0;i<k;i++) {
        int x=s[i]-'a';
        if(curr==NULL) {
            return false;
        }
        curr=curr->links[x];
    }

    return curr->isEnd;

}

bool prefix(TrieNode* root,string s) {
    int k=s.size();
    TrieNode* curr = root;
    for(int i=0;i<k;i++) {
        int x=s[i]-'a';

        if(curr==NULL) {
            return false;
        }

        curr=curr->links[x];
    }

    return true;
}

int main() {
    TrieNode* root = new TrieNode();
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        insert(root, s);
    }

    string s1,s2;
    cin>>s1>>s2;
    bool f=search(root,s1);
    cout<<f<<endl;
    f=prefix(root,s2);
    cout<<f<<endl;


    return 0;
}