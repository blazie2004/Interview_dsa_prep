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
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode*temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            n++;
        }
        int length=n;
        temp=head;
        int num=0;
        while(temp!=nullptr){
            num+=pow(2,length-1)*temp->val;
            length--;
            temp=temp->next;

        }
        return num;
    }
};