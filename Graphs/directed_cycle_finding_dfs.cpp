#include<bits/stdc++.h>
using namespace std;
#define INF (1LL<<61)
#define int long long 
#define pb push_back

vector<int> adj[100005];
int st=-1,ed=-1;

int col[100005];
int parent[100005];

bool dfs(int v) {
    col[v]=1;

    for(auto u:adj[v]) {
        if(col[u]==0) {
            parent[u]=v; 
            if(dfs(u))
            return true;
        } else if(col[u]==1) {
            st=u;
            ed=v;
            return true;
        }

    }

    col[v]=2;
    return false;
}

signed main() {

    int n,m;
    cin>>n>>m;

    memset(col,0,sizeof(col));
    parent[0]=0;

    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);

        cout<<"hey"<<endl;
    }

    bool flag=false;
    for(int i=0;i<n;i++) {
        cout<<"tea"<<endl;
        if(col[i]==0) {
            if(dfs(i)) {
                cout<<"wc"<<endl;
                flag=true;
                break;
            }
        }
    }

    if(flag) {
        cout<<"cycle found"<<endl;
        vector<int> res;

        for(int i=ed;i!=st;i=parent[i]) {
            res.pb(i);
        }
        res.pb(st);

        for(int i=0;i<res.size();i++) {
            cout<<res[i]+1<<endl;
        }
    } else {
        cout<<"no cycle found"<<endl;
    }

    return 0;
}