// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* result = head;
        while (head->next != nullptr){
            if (head->next->val == head->val) {
                ListNode* temp = head->next;
                head->next = head->next->next;
                delete temp;
            } else {
                head = head->next;
            }
        }
        return result;
    }
};