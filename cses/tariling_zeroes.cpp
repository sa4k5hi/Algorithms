#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int n;
    cin>>n;
    int res=0;
    while(n>0) {
        n=n/5;
        res+=n;
    }
    cout<<res<<endl;

    return 0;
}