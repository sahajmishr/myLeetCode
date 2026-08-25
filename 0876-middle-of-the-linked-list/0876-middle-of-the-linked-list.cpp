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
    ListNode* middleNode(ListNode* head) {
       int length = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    
   // that was really easy though just maintaining my strak for day 16  and rank 28,79,705(twenty eight lakh seventy nine thousand seven hundred five ....)
    int mid = length / 2;
    while (mid > 0) {
        head = head->next;
        mid--;
    }
    
    return head;
}  
    
};