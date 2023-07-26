/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/

#include <vector>
#include <climits>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        
        while (true) {
            int min = INT_MAX;
            int minIndex = -1;
            
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && lists[i]->val < min) {
                    min = lists[i]->val;
                    minIndex = i;
                }
            }
            
            if (minIndex == -1) {
                break;
            }
            
            curr->next = lists[minIndex];
            curr = curr->next;
            lists[minIndex] = lists[minIndex]->next;
        }
        
        return head->next;
    }
};
