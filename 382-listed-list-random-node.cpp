// https://leetcode.com/problems/linked-list-random-node/

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
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        myHead = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int result = myHead->val;
        ListNode* current = myHead;
        // This is only efficient for when the list is small since it requires a full traversal.
        // When the list length is large, just pick a random number and traverse the list in that many steps,
        // looping around back to the head when at the end.
        for (int i = 1; current != nullptr; current = current->next, i++) {
            if (rand() % i == 0) {
                result = current->val;
            }
        }
        return result;
    }
private:
    ListNode* myHead;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */