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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* curr = head;

        // find the mid point;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* second = slow -> next;
        slow -> next = nullptr;

        // reverse the second list;
        ListNode* prev = nullptr;
        curr = second;
        while(curr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        // don't forget about the new head of the reversed list;
        second = prev;

        // connect both LL's alternatively
        curr = head;
        while(second){
            ListNode* temp1 = curr -> next;
            ListNode* temp2 = second -> next;
            curr -> next = second;
            second -> next = temp1;
            curr = temp1;
            second = temp2;
        }
        
        // return head;
    }
};
