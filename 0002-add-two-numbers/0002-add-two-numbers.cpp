/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=NULL;
        ListNode* last=NULL;
        int c=0;
        while(l1!=NULL || l2!=NULL){
            int sum=0;
            if(c) sum++;
            if(l1!=NULL){
               sum+=l1->val;
                l1=l1->next;
            } 
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            } 
            if(sum>9){
                sum%=10;
                c=1;
            }else{
                c=0;
            }
            ListNode* newnode=new ListNode(sum);
            if(ans==NULL) ans=newnode;
            if(last!=NULL) last->next=newnode;
            last=newnode;
        }
        if(c){
            ListNode* newnode=new ListNode(c);
            if(!ans) ans=newnode;
            last->next=newnode;
            last=newnode;
        }
        return ans;
    }
};