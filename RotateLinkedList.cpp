#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
class Solution
{
   public:
   int length(Node *head){
       Node *temp=head;
       int cnt=0;
       while(temp!=NULL){
           cnt++;
           temp=temp->next;
       }
       return cnt;
   }
   Node * rotate(Node *head,int k)
    {
       int len=length(head);
       if(len==k){
           return head;
       }
       Node *temp=head;
       Node *curr=head;
       while(curr->next!=NULL){
           curr=curr->next;
       }
       Node *half=head;
       int i=1;
       while(i!=k){
           half=half->next;
           i++;
       }
       Node *p=half->next;
       half->next=curr->next;
       curr->next=head;
       return p;
       
    }
};