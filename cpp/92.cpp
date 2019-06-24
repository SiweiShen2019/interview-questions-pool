#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    int change_len = n - m + 1; // number of nodes reversed
    ListNode *pre = NULL;
    ListNode *result = head;
    while (head && --m) { // move forward m-1 times to get the pre
      pre = head;
      head = head->next;
    }
    ListNode *new_tail = head; // the tail after reverse operation
    ListNode *new_head = NULL;
    // almost same as lc 206
    while (head && change_len) { // reverse change_len nodes
      ListNode *next = head->next;
      head->next = new_head;
      new_head = head;
      head = next;
      change_len--;
    }
    new_tail->next = head;
    if (pre) { // m > 1
      pre->next = new_head;
    } else {  // special case, m = 1
      result = new_head;
    }
    return result;
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

  head = solve.reverseBetween(&a, 1, 4);
  printf("After revers:\n");
  printListNode(head);
}
