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
  ListNode* partition(ListNode* head, int x) {
    if (!head)
      return NULL;
    ListNode* small = new ListNode(-2);
    ListNode* large = new ListNode(-1);
    ListNode* curr = head;
    ListNode* sp = small;
    ListNode* lp = large;
    while (curr) {
      if (curr->val < x) {
        sp->next = curr;
        curr = curr->next;
        sp = sp->next;
        sp->next = NULL;
      } else {
        lp->next = curr;
        curr = curr->next;
        lp = lp->next;
        lp->next = NULL;
      }
    }
    sp->next = large->next;
    return small->next;
  }
};
