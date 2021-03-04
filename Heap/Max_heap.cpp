#include<bits/stdc++.h>
using namespace std;

void max_heapify(int arr[],int n,int i) {
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[left]>arr[largest]) {
        largest=left;
    }

    if(right<=n && arr[right]>arr[largest]) {
        largest=right;
    }

    // cout<<i<<" "<<largest<<endl;

    if(largest!=i) {
        swap(arr[largest],arr[i]);
        max_heapify(arr,n,largest);
    }
}

void build(int arr[],int n) {
    for(int i=n/2;i>=1;i--) {
        max_heapify(arr,n,i);
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n+2];
    arr[0]=-1;
    // vector<int> v(n);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    build(arr,n);

    for(int i=1;i<=n;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}