/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Step 1: create a deep copy of only singly linked list
        Node* dummy = new Node(0);  // deep copy LL
        Node* tempdummy = dummy; //traverses on deep copy LL
        Node* temp = head; //traverses original LL
        while(temp) {
                Node* a = new Node(temp->val); //newnode which duplicates the each node and to join it in deep copy LL
                tempdummy->next = a;
                tempdummy = tempdummy->next;
                temp = temp->next;
        }
        //Step 2 : Join both the oroginl and deep copy LL by creating alternate connections
        Node* duplicate = dummy->next;
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(-10);
        Node* tempD = dummy;
        while(a){
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;

        }
        dummy = dummy->next;
        //Step 3 : joining the random pointer of duplicates w.r.t the original
        Node* t1 = dummy;
        while(t1) {
            Node* t2 = t1->next;
            if(t1->random) t2->random = t1->random->next;
            t1=t1->next->next;
        }
        //step 4 : removing connections by seperaring joint ll
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);
         t1 = d1;
        Node* t2 = d2;
        Node* t = dummy;
        while(t) {
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2 -> next;
        }
        t1 -> next = NULL;
        t2 -> next = NULL;
        d1 = d1->next;
        d2 = d2->next;

    return d2;
    }
};