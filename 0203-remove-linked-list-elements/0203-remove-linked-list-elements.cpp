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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* temp = head;
        ListNode* ans = new ListNode(100);
        ListNode* t = ans;
        
        while(temp) {
            if(temp->val!=val) {
                t->next = temp;
                t = t->next;
                
            }
            temp = temp -> next;

        }
        t->next = nullptr;
        return ans->next;
    }
};