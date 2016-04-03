// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = head->next;
        while (curr != nullptr && next != nullptr) {
            prev->next = next;
            curr->next = next->next;
            next->next = curr;
            prev = curr;
            curr = curr->next;
            if (curr != nullptr) {
                next = curr->next;
            } else {
                next = nullptr;
            }
        }
        return dummy->next;
    }
};