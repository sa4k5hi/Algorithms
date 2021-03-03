#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void printt(Node* a) {
    while(a!=NULL) {
        cout<<a->data<<" ";
        a=a->next;
    }
}

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* head=NULL;
    if(head1->data > head2->data) {
        head=head2;
        head2=head2->next;
    } else {
        head=head1;
        head1=head1->next;
    }
    Node* curr=head;
    while(head1!=NULL && head2!=NULL) {
        if(head2-> data > head1->data) {
            Node* temp=head1;
            // curr->next=temp;
            cout<<"tea"<<endl;
            head1=head1->next;
            curr->next=temp;
        } else {
            Node* temp=head2;
            // curr->next=temp;
            cout<<"coff"<<endl;
            head2=head2->next;
            curr->next=temp;
        }
        curr=curr->next;

        // printt(head);
    }
    
    if(head1!=NULL) {
        curr->next=head1;
    } 
    
    if(head2!=NULL) {
        curr->next=head2;
    }
    
    return head;
}  

Node* insert(Node* head,int n) {
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

    return head;
}


int main() {
    int n,m;
    cin>>n>>m;
    Node* head1=NULL,*head2=NULL;

    head1=insert(head1,n);
    head2=insert(head2,m);

    cout<<"hey"<<endl;
    Node* head=sortedMerge(head1,head2);
    printt(head);
    
    return 0;
}