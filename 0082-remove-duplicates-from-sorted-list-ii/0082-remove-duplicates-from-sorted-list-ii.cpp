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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* ans = new ListNode(100);
        ListNode*  a = ans;
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        while(temp) {
            bool duplicate = false;
            while(temp2 && temp2->val == temp->val) {
                duplicate = true;
                temp2 = temp2->next;
            }
            if(!duplicate) {
                a->next = temp;
                a = a->next;
            }
            temp = temp2;
            if(temp2) temp2 = temp2->next;
        }
        a->next = NULL;
        return ans->next;
    }
};