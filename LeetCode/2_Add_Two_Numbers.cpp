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
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    void addNode(ListNode *list, int value) {
        if (head == nullptr && tail == nullptr) {
            head = list;
            tail = list;
        } else {
            ListNode *newNode = new ListNode(value);

            tail->next = newNode;
            tail = newNode;
        }

        tail->val = value;
        tail->next = nullptr;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *answer = new ListNode(0);
        int passValue = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int sum = passValue;

            passValue = 0;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (sum > 9) {
                passValue = sum / 10;
                sum = sum % 10;
            }

            addNode(answer, sum);

            sum = 0;
        }

        if (passValue > 0) {
            addNode(answer, passValue);
        }

        return answer;
    }
};

int main() {
    ListNode *la = (ListNode *) malloc(sizeof(ListNode));
    ListNode *lb = (ListNode *) malloc(sizeof(ListNode));
    ListNode *lc = (ListNode *) malloc(sizeof(ListNode));
    ListNode *ld = (ListNode *) malloc(sizeof(ListNode));
    ListNode *le = (ListNode *) malloc(sizeof(ListNode));
    ListNode *lf = (ListNode *) malloc(sizeof(ListNode));

    la->val = 2;
    la->next = lb;

    lb->val = 4;
    lb->next = lc;

    lc->val = 3;
    lc->next = nullptr;

    ld->val = 5;
    ld->next = le;

    le->val = 6;
    le->next = lf;

    lf->val = 4;
    lf->next = nullptr;

    Solution sol = Solution();
    ListNode *result = sol.addTwoNumbers(la, ld);
    ListNode *head = result;

    while (head != nullptr) {
        printf("%d", head->val);

        head = head->next;
    }

    printf("\n");

    le->val = 3;
    lf->val = 7;

    Solution sol2 = Solution();
    result = sol2.addTwoNumbers(la, ld);
    head = result;

    while (head != nullptr) {
        printf("%d", head->val);

        head = head->next;
    }

    printf("\n");

    free(la);
    free(lb);
    free(lc);
    free(ld);
    free(le);
    free(lf);

    return 0;
}