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
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    dummy->next = head;
    while (pre->next) {
      ListNode* curr = pre->next;
      while (curr->next && curr->val == curr->next->val) {
        // ListNode* tmp = curr;
        curr = curr->next;
        // delete tmp;
      }
      if (curr == pre->next) {
        pre = pre->next;
      } else {
        // ListNode* tmp = pre->next;
        pre->next = curr->next;
        // delete tmp;
      }
    }
    return dummy->next;
  }
};
