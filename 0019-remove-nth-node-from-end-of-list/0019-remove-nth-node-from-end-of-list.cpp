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
       // i dont know what i did .. but i just know what i did
    
        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* prevslow = nullptr;
        int length = 1 , slownode = 1;
         if (!head || !head->next) return nullptr; 
        while(fast && fast->next){
            bool isEvenLength = (fast->next->next == nullptr);
            prevslow = slow ;
            slow = slow->next ;
            slownode++;
            length+=2;
            fast = fast->next->next ;
             if (isEvenLength) length -= 1; 
            if(fast==nullptr||fast->next ==nullptr ){
                int node = (length -n)+1 ;
                 if (node == 1) {
                    return head->next;
                }
                if(slownode==node){
                 prevslow->next = slow->next;
                
                 return head ;
                }else if(slownode<node){
                    while(slownode!=node){
                       prevslow = slow ;
                       slow = slow->next ;
                       slownode++;
                    }
                     prevslow->next = slow->next;
                     
                     return head ;
                }else {
                    ListNode* temp = head;
                    int tempnode = 1 ;
                    ListNode* prevtemp = nullptr ;
                    while(tempnode!=node){
                        prevtemp = temp ;
                        temp = temp->next;
                        tempnode++;
                    }
                    prevtemp->next = temp->next ;
                    
                    return head ;

                }
            }
        }
        return head ;
    }
};