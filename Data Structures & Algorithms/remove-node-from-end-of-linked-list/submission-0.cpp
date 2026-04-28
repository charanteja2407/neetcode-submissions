/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0, head);

        int i = n;
        ListNode* fast = dummy;
        while(i--){
            fast = fast -> next;
        }

        ListNode* curr = dummy;

        while(fast && fast -> next){
            curr = curr -> next;
            fast = fast -> next;
        }

        curr -> next = curr -> next -> next;

        return dummy -> next;
    }
};
