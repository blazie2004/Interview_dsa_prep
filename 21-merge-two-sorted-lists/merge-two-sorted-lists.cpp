class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* newnode = new ListNode(0);
        ListNode* carry = newnode;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->val <= l2->val) {
                carry->next = l1;
                l1 = l1->next;
            }
            else {
                carry->next = l2;
                l2 = l2->next;
            }

            carry = carry->next;
        }

        if (l1 != nullptr)
            carry->next = l1;

        if (l2 != nullptr)
            carry->next = l2;

        return newnode->next;
    }
};