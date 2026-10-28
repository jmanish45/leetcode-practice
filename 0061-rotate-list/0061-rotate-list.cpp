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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* tail = NULL;
        int n = 0;
        while(temp) {
            temp=temp->next;
            n++;
        }
        if(!head) return NULL;
        k = k%n;
        if(k==0) return head;
        temp = head;
        for(int i=1; i<(n-k); i++) {
            temp = temp->next;
        }
        tail = temp;
        temp=temp->next;
        ListNode* part2 = temp;
        tail->next = NULL;
        ListNode* last = part2;
        while(last->next) {
            last=last->next;
        }
        
        last->next = head;
        
        return part2;
    }
};