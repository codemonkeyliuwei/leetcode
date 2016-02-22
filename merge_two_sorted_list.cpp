#include <assert.h>
#include <stdlib.h>

/* Definition for singly-linked list. */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode * head = new ListNode(0);
        ListNode * node = head;

        while (l1 && l2)
        {           
            if (l1->val < l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }

            node = node->next;
        }
        
        node->next = l1 ? l1 : l2;
        ListNode * out = head->next;
        delete head;
        return out;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    
    ListNode n1(1);
    ListNode n3(3);
    ListNode n5(5);
    ListNode n2(2);
    ListNode n4(4);
    ListNode n6(6);
    n1.next = &n3;
    n3.next = &n5;
    n2.next = &n4;
    n4.next = &n6;

    ListNode *ret1 = s.mergeTwoLists(&n1, &n2);
    int i = 0;
    while (ret1 != NULL)
    {
        i++;
        assert(ret1->val == i);
        ret1 = ret1->next;
    }

    i = 2;
    ret1 = s.mergeTwoLists(&n1, NULL);
    while (ret1 == NULL)
    {
        assert(ret1->val == 2);
        i += 2;
        ret1 = ret1->next;
    }

    return 0;
}