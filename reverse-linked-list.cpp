#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseListRecursively(ListNode* head) {
        ListNode* pre  = NULL;
        ListNode* next = NULL;
        while (head) {
            pre = head;
            head = head->next;
            pre->next = next;
            next = pre;
        }
        head = pre;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* tmp  = NULL;
        while (head->next) {
            tmp = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return tmp;
        }
        return tmp;

    }
};

void PrintList(ListNode* list)
{
    ListNode* tmp = list;
    while (tmp)
    {
        cout << tmp->val;
        tmp = tmp->next;
    }
    cout << endl;
}

int main(void)
{

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    PrintList(&n1);
    
    Solution s;
    ListNode* rl = s.reverseList(&n1);
    PrintList(rl);
    
    return 0;
}

