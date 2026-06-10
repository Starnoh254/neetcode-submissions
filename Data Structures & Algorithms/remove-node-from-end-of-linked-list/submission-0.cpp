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
        ListNode* previousNode = nullptr;
        ListNode* temp = head;
        int length = 0;

        while(temp){
            length ++;
            temp = temp -> next;
        }

        temp = head;

        int target = length - n;
        for(int i = 0 ; i < target; i++){
            previousNode = temp;
            temp = temp -> next;
        }

        if(previousNode) {
            previousNode -> next = temp -> next;
        }
        else {
            head = head -> next;
        }

        return head;

        
    }
};
