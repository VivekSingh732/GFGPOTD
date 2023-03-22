#include<iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp=list1;
        ListNode *temp1=list2;
        ListNode *Dummy=new ListNode(-1);
        ListNode *temp2=Dummy;
        while(temp!=NULL && temp1!=NULL){
            if(temp->val<temp1->val){
                temp2->next=temp;
                temp=temp->next;
            }else{
                temp2->next=temp1;
                temp1=temp1->next;
            }
            temp2=temp2->next;
        }
        while(temp!=NULL){
            temp2->next=temp;
            temp=temp->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            temp2->next=temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return Dummy->next;
    }
    
};
int main(){

}