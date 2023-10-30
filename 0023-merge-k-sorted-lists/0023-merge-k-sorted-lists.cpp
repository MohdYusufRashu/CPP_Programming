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
    ListNode* mergeKlistshelper(vector<ListNode*>& lists,int index){
        if(index==lists.size()-1){
            return lists[index];
        }
        ListNode* head1=lists[index];
        ListNode* head2=mergeKlistshelper(lists,index+1);
        ListNode* prev=NULL;
        ListNode* l1;
        ListNode* l2;
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        if(head1->val <= head2->val){
            l1=head1;
            l2=head2;
        }else{
            l1=head2;
            l2=head1;
        }
        ListNode* ans=l1;
        while(l2){
            while(l1!=NULL && l1->val<=l2->val){
                prev=l1;
                l1=l1->next;
            }
            prev->next=l2;
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        return mergeKlistshelper(lists,0);
    }
};