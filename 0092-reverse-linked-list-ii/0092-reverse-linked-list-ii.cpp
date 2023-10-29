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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tempHead=head;
        ListNode* prevHead=NULL;
        int l=left;
        while(l>1){
            prevHead=tempHead;
            tempHead=tempHead->next;
            l--;
        }
        int x=right-left+1;
        ListNode* prev=NULL;
        ListNode* curr=tempHead;
        ListNode* next=tempHead;
        while(x){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            x--; 
        }
        tempHead->next=curr;
        if(!prevHead){
            head=prev;
        }else{
            prevHead->next=prev;
        }
        return head;
    }
};