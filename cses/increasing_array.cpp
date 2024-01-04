#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long mx=0;
    long long res=0;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(x<mx) {
            res+=(mx-x);
        } else {
            mx=x;
        }
    }
    cout<<res<<endl;


    return 0;
}