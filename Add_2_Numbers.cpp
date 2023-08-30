class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        int carry = 0;
        ListNode* head = l3;
        while(l1 && l2) {
            int sum = carry + l1 -> val +l2 -> val;
            carry = sum / 10;
            l3 -> next = new ListNode(sum%10);
            l3 = l3 -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1)
        {
         int sum = carry + l1 -> val;
            carry = sum / 10;
            l3 -> next = new ListNode(sum%10);
            l3 = l3 -> next;
            l1 = l1 -> next;
        }
        while(l2)
        {
           int sum = carry + l2 -> val;
            carry = sum / 10;
            l3 -> next = new ListNode(sum%10);
            l3 = l3 -> next;
            l2 = l2 -> next; 
        }
        if(carry)
        {
            l3 -> next = new ListNode(carry);
        }
        return head -> next;
    }
};
