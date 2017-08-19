// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int size = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            size++;
        }
        tail->next = head;
        ListNode* search = head;
        for (int i = 0; i < k % size; i++) {
            search = search->next;
        }
        ListNode* prevk = head;
        while (search != tail) {
            prevk = prevk->next;
            search = search->next;
        }
        ListNode* result = prevk->next;
        prevk->next = nullptr;
        return result;
    }
};