#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF (1LL<<61)
#define int long long

vector<pair<int,int>> adj[100005];

signed main() {
    int n,m;
    cin>>n>>m;

    // vector<vector<int> arr(m);
    for(int i=0;i<m;i++) {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        // arr[i]={x,y,w};
        adj[x].pb({y,w});
    }

    queue<int> q;
    q.push(0);

    vector<int> dist(n,INF);
    dist[0]=0;


    int inq[n];
    int cnt[n];
    vector<int> parent(n);

    parent[0]=0;
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    int flag=-1;

    while(!q.empty()) {
        int v=q.front();
        q.pop();
        inq[v]=0;

        for(auto u:adj[v]) {

            if(dist[u.first] > dist[v] + u.second) {
                dist[u.first] = max(-INF,dist[v] + u.second);
                parent[u.first] = v;
                if(inq[u.first]!=1) {
                    inq[u.first]=1;
                    q.push(u.first);
                    cnt[u.first]++;
                    if(cnt[u.first] > n) {
                        flag=u.first;
                        break;
                    }
                }
            }
        }

        if(flag!=-1)
        break;


    }

    if(flag!=-1) {
        cout<<" negative cycle"<<endl;
        for(int i=0;i<n;i++) {
            flag=parent[flag];
        }

        vector<int> res;
        for(int i=parent[flag];i!=flag;i=parent[i]) {
            res.pb(i);
        }
        res.pb(flag);

        for(int i=0;i<res.size();i++) {
            cout<<res[i]+1<<endl;
        }
    } else {
        cout<<"no negative cycle"<<endl;
    }

    return 0;
}