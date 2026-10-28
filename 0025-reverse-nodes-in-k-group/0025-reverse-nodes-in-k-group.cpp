class Solution {
public:
    
    ListNode* reverseList(ListNode*head) {
        ListNode* curr = head;
        ListNode* Next = head;
        ListNode* prev = NULL;
        while(curr) {
            Next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = Next;
        
        }
        return prev;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
        while(temp) {
            if(n==left-1) a = temp;
            if(n==left) b = temp;
            if(n==right) c = temp;
            if(n==right+1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a!=NULL) a->next=NULL;
        c->next=NULL;
        ListNode* newhead = reverseList(b);
        if(a!=NULL) a->next=newhead;
        b->next = d;
        if(a!=NULL) return head;
        return newhead;


    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // ListNode* dummy = new ListNode(0);
        // dummy -> next = head;
        ListNode* temp = head;
        int nodes = 0;
        while(temp) {
            nodes++;
            temp=temp->next;
        }
        int left = 1;
        int right = k;
        while(right<=nodes) {
        head = reverseBetween(head, left, right );
        
        
        left+=k;
        right+=k;
       }
       
       return head;
        
    }
};