// https://leetcode.com/problems/reverse-linked-list/

// Solution 1: recursive
class Solution {
public:
    ListNode *reverseWorker(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            _result = head;
            return head;
        } else {
            ListNode *first = head;
            ListNode *rest = head->next;
            reverseWorker(rest);
            first->next->next = first;
            first->next = nullptr;
            return rest;
        }
    }

    ListNode* reverseList(ListNode* head) {
        reverseWorker(head);
        return _result;
    }
private:
    ListNode *_result;
};

// Solution 2: iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};