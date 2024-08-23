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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode();
        ListNode *curr = temp;
        int simpan = 0, sum = 0;
        while (l1 || l2)
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + simpan;
            simpan = sum/10;
            ListNode *baru = new ListNode(sum%10);
            curr->next = baru;
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(simpan>0){
            ListNode *carryLeft = new ListNode(simpan);
            curr->next = carryLeft;
        }
        return temp->next;
    }

};