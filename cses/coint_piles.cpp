#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t,b,s;
    cin>>t;
    while(t--) {
        cin>>b>>s;
        if(b<s) swap(b,s);
        long long x = 2*s - b;
        if(x>=0 && x%3==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }


//     multiples of 3 if equal and smaller*2>=bigger and s - b +s%3=0
//     4,4 -2,-1
//     2,3 -1,-2
//     1,1 -- no

//     5,5
//     3,4
//     2,2 -- no


//     6,6
//     4,5
//     3,3 -- yes

//     7,7  -2,-1
//     5,6  -1,-2
//     4,4 -- no

//     8,8
//     6,7
//     5,5  

//     b-s=x   --> 4-3 = 1

//    7,4
//    5,3
//    3,2
//    1,1


    return 0;
}