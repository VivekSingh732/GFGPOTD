#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
// Reverse The List From the middle
    ListNode *Reverse(ListNode *mid){
        ListNode *prev=NULL;
        ListNode *curr=mid;
        while(curr!=NULL){
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    //Here We find Out the middle of list
    ListNode *middle(ListNode *head){
        ListNode* slow=head;
        ListNode* fast=head;
         while(fast->next!=NULL && fast->next->next!=NULL){
             slow=slow->next;
             fast=fast->next->next;
         }
         return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){return true;}
         ListNode *mid=middle(head);
         ListNode *rev=Reverse(mid->next);
         ListNode *curr=head;
         while(rev!=NULL){
             if(curr->val!=rev->val){
                 return false;
             }
             curr=curr->next;
             rev=rev->next;
         }
         return true;
    }
};