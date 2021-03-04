#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define INF (1LL<<61)

vector<int> adj[100005];
int vis[100005];
int parent[100005];

int st=-1,ed=-1;
bool dfs(int v) {
    vis[v]=1;

    for(auto u :adj[v]) {
        if(u == parent[v]) continue;
        if(vis[u]!=1) {
            parent[u]=v;
            if(dfs(u))
            return true;
        } else {
            st = u;
            ed = v;
            return true;
        }
    }

    return false;
}

signed main() {

    int n,m;
    cin>>n>>m;

    memset(vis,0,sizeof(vis));
    parent[0]=0;

    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    bool flag=false;
    for(int i=0;i<n;i++) {
        if(vis[i]!=1) {
            if(dfs(i)) {
                flag=true;
                break;
            }
        }
    }

    if(flag) {
        cout<<"cycle present" <<endl;

        vector<int> res;
        for(int i=ed;i!=st;i=parent[i]) {
            res.pb(i);
        }

        res.pb(st);

        for(int i=0;i<res.size();i++) {
            cout<<res[i]+1<<endl;
        }

    } else {
        cout<<"no cycle"<<endl;
    }


    return 0;
}