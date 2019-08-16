#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int getListSize(ListNode *head) {
        int size = 0;
        ListNode *move = head;

        while (move != nullptr) {
            size++;
            move = move->next;
        }

        return size;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *move = head;
        ListNode *previousNode = head;
        int size = getListSize(head);
        int indexToRemove = size - n;
        int index = -1;

        if (size == n) {
            head = head->next;
            move->next = nullptr;
        } else {
            while (move != nullptr) {
                index++;

                if (index == indexToRemove) {
                    previousNode->next = move->next;

                    break;
                }

                move = move->next;

                if (move != head && move != head->next) {
                    previousNode = previousNode->next;
                }
            }
        }

        return head;
    }
};

int main() {
    ListNode *a = (ListNode *) malloc(sizeof(ListNode));
    ListNode *b = (ListNode *) malloc(sizeof(ListNode));
    ListNode *c = (ListNode *) malloc(sizeof(ListNode));
    ListNode *d = (ListNode *) malloc(sizeof(ListNode));
    ListNode *e = (ListNode *) malloc(sizeof(ListNode));

    a->next = b;
    a->val = 1;

    b->next = c;
    b->val = 2;

    c->next = d;
    c->val = 3;

    d->next = e;
    d->val = 4;

    e->val = 5;

    Solution sol = Solution();

    a = sol.removeNthFromEnd(a, 1);

    while (a != nullptr) {
        cout << a->val << endl;
        a = a->next;
    }

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    return 0;
}