#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

#define INF (1LL<<61)
vector<pair<int,int>> adj[100005];

signed main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(3));
    for(int i=0;i<m;i++) {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        // adj[x].pb({y,w});
        arr[i] = {x,y,w};
    }

    vector<int> dist(n,INF);
    int flag=-1;
    vector<int> parent(n+2);

    dist[0]=0;
    for(int i=0;i<n;i++) {
        flag=-1;
        for(int j=0;j<m;j++) {
            if(dist[arr[j][0]] < INF) {
                if(dist[arr[j][1]] > dist[arr[j][0]] + arr[j][2]) {
                    dist[arr[j][1]] = max(-INF,dist[arr[j][0]] + arr[j][2]);
                    flag=arr[j][1];
                    parent[arr[j][1]] = arr[j][0];
                    // cout<<arr[j][1]<<" "<<arr[j][0]<<endl;
                }
            } 
        }

        if(!flag)
        break;
    }

    if(flag!=-1) {
        vector<int> res;
        cout<<"negative cycle"<<endl;

        // cout<<flag<<" hi"<<endl;
        for(int i=0;i<n;i++) {
            flag=parent[flag];
            // cout<<flag<<endl;

        }

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