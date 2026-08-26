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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) return nullptr;
        // i didnt expect it to work butit did so okay ..no problem .hehehhhehhe
        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* prevslow = nullptr;
        while(fast&&fast->next){
            prevslow = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prevslow->next = slow->next ;
        
        
        return head ;
    }
};