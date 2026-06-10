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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1 , l2 , 0);
    }
    ListNode* add(ListNode* l1 , ListNode* l2 , int carry){
        if(!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int val1 = 0 , val2 = 0 , sum = 0;
        sum += carry;

        if(l1) {
            val1 = l1 -> val;
            sum += val1 ;
        }
        if(l2) {
            val2 = l2 -> val;
            sum += val2 ;
        }     

        carry = sum / 10;
        int nodeValue = sum % 10;

        ListNode* nextNode = add(
            (l1 ? l1 -> next : nullptr),
            (l2 ? l2 -> next : nullptr),
            carry
        );

        return new ListNode(nodeValue , nextNode);
    }
};
