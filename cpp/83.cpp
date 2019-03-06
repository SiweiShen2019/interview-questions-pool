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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
      return NULL;
    ListNode* curr = head;
    while (curr->next) {
      ListNode* next = curr->next;
      if (curr->val == next->val)
        curr->next = next->next;
        // delete next;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};
