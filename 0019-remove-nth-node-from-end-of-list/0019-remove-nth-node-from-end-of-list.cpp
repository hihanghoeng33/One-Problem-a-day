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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int number=0;
        ListNode *hapus = new ListNode(0, head);
        ListNode *temp = hapus, *bantu = hapus;
        while (number<=n)
        {
            bantu = bantu->next;
            number++;
        }
        while (bantu!=NULL)
        {
            bantu = bantu->next;
            temp = temp->next;
        }
        
        ListNode *hapusNode = temp->next;
        temp->next = temp->next->next;
        delete(hapusNode);

        ListNode *headBaru = hapus->next;
        delete(hapus);
        return headBaru;
    }
};