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
public:// these comments are the signs of muy struggling and limitations and weakness i will com eback and do it again ..
    // 1. Create a custom structure to tell the priority queue how to compare Node pointers
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // '>' creates a min-heap based on value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Pass your custom 'compare' struct as the third template argument
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // 2. ONLY push the head node of each non-empty list into the heap initially
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        } 
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // 3. Process the heap dynamically
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            
            // Append the smallest node to our result list
            tail->next = curr;
            tail = tail->next;
            
            // Crucial: Push the next node of the list we just pulled from back into the heap
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }
        
        // 4. Return the head of the newly merged list
        return dummy.next;
    }
};