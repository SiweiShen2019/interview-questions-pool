#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* new_head = NULL;
    while (head) {
      ListNode* tmp_next = head->next;
      head->next = new_head;
      new_head = head;
      head = tmp_next;
    }
    return new_head;
  }
};

void printListNode(ListNode* head) {
  while (head) {
    printf("%d -> ", head->val);
    head = head->next;
  }
  printf("||\n");
}

int main() {
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);
  ListNode d(4);
  ListNode e(5);

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;

  Solution solve;
  ListNode *head = &a;
  printf("Before reverse:\n");
  printListNode(head);

  head = solve.reverseList(&a);
  printf("After revers:\n");
  printListNode(head);
}
