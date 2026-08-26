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
// took me sometime but i kinda like it ..
    ListNode* oddEvenList(ListNode* head) {
        if(head== nullptr || head->next == nullptr) return head ;
        ListNode* odd = head ;
        ListNode* even = head->next ;
        ListNode* even1 = head->next ;

        while(even && even->next){
            odd->next = odd->next->next;
            even->next= even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even1;
         return head ;
    }
};
    
   