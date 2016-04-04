// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    // Too complicated. don't need recursion.
    ListNode* removeNthWorker(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        head->next = removeNthWorker(head->next, n);
        whatth++;
        if (whatth == n) {
            return head->next;
        } else {
            return head;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        whatth = 0;
        return removeNthWorker(head, n);
    }
private:
    int whatth;
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nthnext = head;
        ListNode *nthback = head;
        ListNode *nthprev = new ListNode(0);
        nthprev->next = head;
        ListNode *resultprev = nthprev;
        while (n > 1) {
            nthnext = nthnext->next;
            n--;
        }
        while (nthnext->next != nullptr) {
            nthnext = nthnext->next;
            nthback = nthback->next;
            nthprev = nthprev->next;
        }
        nthprev->next = nthback->next;
        return resultprev->next;
    }
};