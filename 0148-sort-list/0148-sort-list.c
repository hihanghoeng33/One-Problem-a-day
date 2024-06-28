/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

struct ListNode* findMiddle(struct ListNode* head) {
    if (!head) return head;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* mid = findMiddle(head);
    struct ListNode* left = head;
    struct ListNode* right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);
    
    return merge(left, right);
}