#include<bits/stdc++.h>
using namespace std;
struct Node{
 int data;
 struct Node *next;
 Node(int x){
    int data=x;
    next=NULL;
 }
};
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node *reverse(Node *head){
        Node *curr=head;
        Node *prev=NULL;
        while(curr!=NULL){
            Node *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *p1=reverse(first);
        Node *p2=reverse(second);
        int carry=0;
        Node *curr=new Node(0);
        Node *temp=curr;
        while(p1!=NULL && p2!=NULL){
            int add=p1->data+p2->data+carry;
            p1=p1->next;
            p2=p2->next;
            carry=add/10;
            curr->next=new Node(add%10);
            curr=curr->next;
        }
        while(p1!=NULL){
            int add=p1->data+carry;
            p1=p1->next;
            carry=add/10;
            curr->next=new Node(add%10);
            curr=curr->next;
        }
        while(p2!=NULL){
            int add=p2->data+carry;
            p2=p2->next;
            carry=add/10;
            curr->next=new Node(add%10);
            curr=curr->next;
        }
        if(carry!=0){
            curr->next=new Node(carry);
        }
        Node *rev=reverse(temp->next);
        return rev;
    }
};
int main(){

}
