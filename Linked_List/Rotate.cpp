// C++ program to rotate
// a linked list counter clock wise

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node* rotate(Node* head, int k)
{
    // Your code here
    Node* curr=head;
    int cnt=1;
    while(cnt<k) {
        cnt++;
        curr=curr->next;
        if(curr==NULL) {
        return head;
        }
    }
    // if(curr==NULL) {
    //     return head;
    // }
    Node* fhead=curr->next;
    curr->next=NULL;
    
    Node* temp=fhead;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    
    temp->next=head;
    
    return fhead;
        
}



/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code*/
int main(void)
{
	/* Start with the empty list */
	Node* head = NULL;

	// create a list 10->20->30->40->50->60
	for (int i = 90; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	head=rotate(head, 20);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}

// This code is contributed by rathbhupendra
