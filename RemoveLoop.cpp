#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void removeLoop(Node* head)
    {
        if(head==NULL) return;
        Node *slow=head->next;
        Node *fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            if(slow==fast) break;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow!=fast) return;
        
        slow=head;
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
        }else{
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
        
    }
};