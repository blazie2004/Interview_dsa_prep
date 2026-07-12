class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }
        ///base call kar do
        //condition laga to stop rec

        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};