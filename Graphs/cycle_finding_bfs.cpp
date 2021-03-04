#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

#define INF (1LL<<61)
int vis[100000];
int parent[100000];
vector<int> adj[100000];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<int> q;
    q.push(0);

    bool flag=false;
    vis[0]=0;
    parent[0]=0;
    int st=-1,ed=-1;
    while(!q.empty()) {
        int v=q.front();
        q.pop();

        for(auto u:adj[v]) {
            if(vis[u]==1 && parent[u]!=v) {
                flag=true;
                st=u;
                ed=v;
                break;
            } else {
                vis[u]=1;
                parent[u]=v;
                q.push(u);
            }
        } 

        if(flag)
        break;
    }

    vector<int> res;

    for(int i=st;i!=ed;i=parent[i]) {
        res.pb(i);
    }
    res.pb(ed);

    for(int i=0;i<res.size();i++) {
        cout<<res[i]+1<<endl;
    }

    return 0;
}