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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==n) {
            head = head -> next;
            return head;
        }
        int m = len-n;
        // int idx = m - 1;   //idx is the index which is to be removed
        temp=head;
        for(int i = 0; i<m-1;i++) {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};