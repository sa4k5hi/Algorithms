#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* fhead=NULL;
Node* reverse(Node*  head) {
    if(head==NULL)
    return head;
    if(head->next==NULL) {
        fhead=head;
        return head;
    }

    Node* res=reverse(head->next);
    res->next=head;
    head->next=NULL;

    return head;
}

void printt(Node* a) {
    while(a!=NULL) {
        cout<<a->data<<endl;
        a=a->next;
    }
}


int main() {
    int n;
    cin>>n;
    Node* head=NULL;
    while(n--) {
        int d;
        cin>>d;
        Node* temp=new Node();
        temp->data=d;
        temp->next=NULL;

        if(head==NULL) {
            head=temp;
        } else {
            Node* p=head;
            while(p->next!=NULL) {
                p=p->next;
            }
            p->next=temp;
        }
    }

    // printt(head);

    head=reverse(head);
    printt(fhead);
    
    return 0;
}