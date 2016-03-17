// https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        // This uses the counting method - traverse both lists to get their sizes,
        // then skip nodes in the bigger list until the remaining parts of both
        // lists are equal in size, then traverse in parallel to find the first
        // common node, if any.
        size_t sizeA = 0;
        size_t sizeB = 0;
        ListNode *currentA = headA;
        ListNode *currentB = headB;

        while (currentA != nullptr) {
            sizeA++;
            currentA = currentA->next;
        }
        while (currentB != nullptr) {
            sizeB++;
            currentB = currentB->next;
        }
        
        ListNode *leadList = nullptr;
        ListNode *trailList = nullptr;
        size_t diffSize = 0;
        if (sizeA >= sizeB) {
            leadList = headA;
            trailList = headB;
            diffSize = sizeA - sizeB;
        } else {
            leadList = headB;
            trailList = headA;
            diffSize = sizeB - sizeA;
        }
        
        for (size_t i = 0; i < diffSize; i++) {
            leadList = leadList->next;
        }
        
        while (leadList != nullptr && trailList != nullptr) {
            if (leadList == trailList) {
                return leadList;
            }
            leadList = leadList->next;
            trailList = trailList->next;
        }
        return nullptr;
    }
};