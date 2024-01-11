#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long sum = (n*1LL*(n+1))/2*1LL;
    if(sum%2==0) {
        sum/=2;
        vector<int> v;
        vector<int> v2;
        // cout<<"tea "<<sum<<endl;
        while(n>0) {
            if(sum>=n) {
                sum-=n;
                // cout<<"tea2 "<<n<<" "<<sum<<endl;
                v.push_back(n);
            } else {
                v2.push_back(n);
            }
            n--;
        }
        if(sum==0) {
            cout<<"YES"<<endl;
            cout<<v.size()<<endl;
            for(auto x:v)
            cout<<x<<" ";
            cout<<endl;
            cout<<v2.size()<<endl;
            for(auto x:v2)
            cout<<x<<" ";
            cout<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    } else {
       cout<<"NO"<<endl;
    }
    

    return 0;
}