#include <iostream>
#include <unordered_map>

using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return nullptr;
    RandomListNode *ret = new RandomListNode(head->label);
    RandomListNode *src_ptr = head->next;
    RandomListNode *des_ptr;
    unordered_map<RandomListNode*, RandomListNode*> map;
    map[head] = ret;
    while (src_ptr) {
        des_ptr = new RandomListNode(src_ptr->label);
        map[src_ptr] = des_ptr;
        src_ptr = src_ptr->next;
    }
    src_ptr = head;
    des_ptr = ret;
    while (src_ptr) {
        des_ptr->next = map[src_ptr->next];
        des_ptr->random = map[src_ptr->random];
        src_ptr = src_ptr->next;
        des_ptr = des_ptr->next;
    }
    return ret;
}

void test() {
    RandomListNode r1(1);
    RandomListNode r2(2);
    RandomListNode r3(3);
    RandomListNode r4(4);
    RandomListNode r5(5);
    r1.next = &r2;
    r1.random = &r3;
    r2.next = &r3;
    r2.random = &r1;
    r3.next = &r4;
    r3.random = &r5;
    r4.next = &r5;
    r4.random = &r5;
    r5.random = &r3;
    RandomListNode *ret = copyRandomList(&r1);
    while (ret) {
        cout << ret->label << " next: ";
        if (ret->next) cout << ret->next->label;
        else cout << "NULL";
        cout << " random: ";
        if (ret->random) cout << ret->random->label;
        else cout << "NULL";
        cout << endl;
        ret = ret->next;
    }
}


int main() {
    test();
    return 0;
}