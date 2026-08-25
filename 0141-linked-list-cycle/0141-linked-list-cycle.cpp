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
    bool hasCycle(ListNode *head) {
      if(head == nullptr || head->next == nullptr){
        return false ;
      } 
      // i learned tortoise method ... using a slow and a fast okay now i can figure out how i could have used it in middle element ..striver  you are a genius bro really ....
      ListNode* slow = head ;
      ListNode* fast = head ;
      while(fast!= nullptr &&fast->next != nullptr){
        slow = slow->next ;
        fast = fast->next->next ;
        if(slow == fast){
            return true ;
        }
      }
      return false ;

    }
};