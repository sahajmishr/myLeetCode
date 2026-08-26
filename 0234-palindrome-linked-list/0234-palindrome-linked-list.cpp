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
ListNode *reverse(ListNode* head ){
    if(head==nullptr || head->next == nullptr) return head ;
    ListNode* next = nullptr;
    ListNode* prev = nullptr ;
    while(head){
        next = head->next;
        head->next = prev ;
        prev = head ;
        head = next ;
      

    }
    return prev ;

}
    bool isPalindrome(ListNode* head) {
      // using the O(1)space ;
      //slow and fast is still in use as i have to find the middle bruuhhh 
      //i am not sure if it will work or fail lets see
      if(head->next == nullptr || head == nullptr ) return true ;
      ListNode* slow = head ;
      ListNode* fast = head ;
      while(fast&& fast->next){
        slow = slow->next;
        fast = fast->next->next;
      }
     ListNode* revHead =  reverse(slow);
     ListNode* temp1 = head ;
     ListNode* temp2 = revHead ;
     while(temp2){
        if(temp1->val!=temp2->val) return false ;
        temp1 = temp1->next ;
        temp2 = temp2->next ;
     }
       return true ;

    }
};