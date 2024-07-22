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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode* first = head;
        ListNode* second = head;
        while (second&&second->next)
        {
            first = first->next;
            second = second->next->next;
        }
        ListNode* sbl = nullptr;
        ListNode* curr = first;
        while (curr)
        {
            ListNode* next = curr->next;
            curr->next = sbl;
            sbl = curr;
            curr = next;
        }
        ListNode* fh = head;
        ListNode* sh = sbl;

        while (sh)
        {
            if(fh->val!=sh->val){
                return false;
            }
            fh = fh->next;
            sh = sh->next;
        }
        return true;
    }
};