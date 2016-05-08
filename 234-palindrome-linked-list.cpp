// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *one = head;
        ListNode *two = head->next;
        while (two != nullptr) {
            one = one->next;
            two = (two->next == nullptr) ? nullptr : two->next->next;
        }
        ListNode *prev = one;
        ListNode *curr = one->next;
        one->next = nullptr;
        ListNode *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *comp1 = head;
        ListNode *comp2 = prev;
        while (comp1 != nullptr && comp2 != nullptr && comp1->val == comp2->val) {
            comp1 = comp1->next;
            comp2 = comp2->next;
        }
        return comp2 == nullptr;
    }
};