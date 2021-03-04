#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int size[100000];

int root(int v) {
    if(parent[v]==v) {
        return v;
    }

    return parent[v] = root(parent[v]);
}

void union(int x,int y) {
    int a=root(x);
    int b=root(y);

    if(a!=b) {
        if(a<b)
        swap(a,b);

        parent[b]=a;
        size[a]+=size[b];
    }
}

int main() {
    int n;
    cin>>
    
    for(int i=0;i<n;i++) {
        parent[i]=i;
        size[i]=1;
    }

    for(int i = 0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        union(x,y);
    }
    

    return 0;
}