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

 struct compare{
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for( auto l : lists){
            if(l)pq.push(l);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()){
            ListNode* minnode = pq.top();
            pq.pop();
            tail->next = minnode;
            tail = tail->next;
            if(minnode->next)pq.push(minnode->next);
        }
        tail->next = NULL;
        return dummy->next;
    }
};