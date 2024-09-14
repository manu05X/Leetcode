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
     /* 1-:firstly we made a min heap
     2:- we insert all the first element of every list in the Lists
     3:- then we know that all the lists are sorted so it will be sorted in new list also
     4:- then pop it the first min and link it 
     5:- and before link just check if there are more elements of that list then put the next node
     
     
     if we put all the head nodes in the min heap priority queue, then we will have the node with minimum value
at the top of priority queue. Mark it has head, now push the next node of the poped element, again pop the top
value of priority queue and if head is marked already, add it to the next of head and push the next of popped
node in the priority queue, do priority queue becomes empty, at last return the head .
      */
    struct compare
      {
        bool operator()(ListNode* &x, ListNode* &y)
        {
          return x->val>y->val;
        }
      };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare> pq;
        
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
                pq.push(lists[i]);
            
            //cout << lists[i]->val <<"\n";
        }
        ListNode* dummyhead=NULL;
        ListNode* temp;
        
        while(!pq.empty())
        { 
            ListNode* curr=pq.top();
            pq.pop();
            if(curr->next)
            {
                pq.push(curr->next);
            }
            if(dummyhead==NULL)
            {
              dummyhead=curr;
              temp=curr;
            }
            else
            {
              temp->next=curr;
              temp=temp->next;
            }
      }
      return dummyhead;
    }
};