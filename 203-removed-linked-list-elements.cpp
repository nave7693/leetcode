// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(-1);
        ListNode* result = prev;
        prev->next = head;
        ListNode* current = head;
        while (current != nullptr) {
            if (current->val == val) {
                prev->next = current->next;
                current = prev->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return result->next;
    }
};