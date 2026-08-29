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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr  ) return head ;
       ListNode* temp = head ;

       int length = 0;
       while(temp){
       length++;
       temp = temp->next ;
       } 

       // i am damn sure its gonna give error in submittion let see what would it be i am happy for monza gp ;
       if(length == k ) return head ;
       if(k>length){
        k = k%length ;
       }
       if(k==0) return head ;
       int rotnode = length - k ;
       ListNode* curr = head ;
       ListNode* str = nullptr ;
       int currnode = 1;
       while(currnode!= rotnode){
         curr = curr->next ;
         currnode++;
       }
       str = curr;
       ListNode* newhead = str->next ;
       while(curr&&curr->next){
        curr = curr->next ;
       }
       str->next = nullptr ;
       curr->next = head ;
       return newhead ;
    }
};