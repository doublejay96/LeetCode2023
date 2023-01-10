//LeetCode 2. Add Two Numbers
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
        //l1 = l1->next;
        ListNode* start = new ListNode(0, NULL); //this is the ListNode POINTER to before the last digit, to return as the answer
        ListNode* curr = start; //this is the pointer we are currently working on
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            curr->next = new ListNode(0, NULL); //create another ListNode to move to
            curr = curr->next; //move curr pointer to the next ListNode
            if (l1 != nullptr) { //add the first number
                curr->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) { //add the second number
                curr->val += l2->val;
                l2 = l2->next;
            }
            curr->val += carry; //add the carry
            carry = curr->val / 10; //get the new carry one
            curr->val = curr->val % 10; //remove the carried one
            cout << curr->val << std::endl;
        }
        return start->next; //note that there is still a ListNode with 0 value at the start, due to how the loop is written
    }
};