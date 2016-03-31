// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) { return l2; }
        if (l2 == nullptr) { return l1; }
        ListNode *prev = new ListNode(INT_MIN);
        ListNode *current = nullptr;
        ListNode *result = prev;
        while (l1 != nullptr && l2 != nullptr) {
            bool l1chosen = l1->val <= l2->val;
            current = l1chosen ? l1 : l2;
            prev->next = current;
            int currentval = l1chosen ? l1->val : l2->val;
            while (current != nullptr && currentval == current->val) {
                prev = current;
                current = current->next;
            }
            if (current == nullptr) {
                if (l1chosen) {
                    prev->next = l2;
                    break;
                } else {
                    prev->next = l1;
                    break;
                }
            } else {
                if (l1chosen) {
                    l1 = current;
                } else {
                    l2 = current;
                }
            }
        }
        return result->next;
    }
};