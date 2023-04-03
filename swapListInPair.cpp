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
 // Using recursion
    ListNode* swapPairs(ListNode* head) {
      if(head==NULL || head->next==NULL) return head;
      
      ListNode *temp=head;
      ListNode *curr=temp->next;
      if(temp && temp->next){
        ListNode *nextSwap=temp->next->next;

        temp->next=swapPairs(nextSwap);
        curr->next=temp;        
      }
      return curr;
     
    }
    // using iterative approach
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
         ListNode *curr=head;
         ListNode *dumy=new ListNode();
         ListNode *pre=dumy;
         while(curr && curr->next){
            pre->next=curr->next;
            curr->next=pre->next->next;
            pre->next->next=curr;

            pre=curr;
            curr=curr->next;
         }
         return dumy->next;
    }
};

