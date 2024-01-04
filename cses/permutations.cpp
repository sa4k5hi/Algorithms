#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n==2 || n==3) {
        cout<<"NO SOLUTION"<<endl;
    } else {
        int st1,st2;
        if(n%2==0) {
            st1=n-1;
            st2=n;
        } else {
            st1=n;
            st2=n-1;
        }
        while(st1>0) {
            cout<<st1<<" ";
            st1-=2;
        }
        while(st2>0) {
            cout<<st2<<" ";
            st2-=2;
        }
    }


    return 0;
}