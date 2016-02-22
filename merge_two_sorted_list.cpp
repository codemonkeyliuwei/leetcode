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

        if (NULL == l1)
        {
            return l2;
        }

        if (NULL == l2)
        {
            return l1;
        }

        ListNode * out = NULL;
        if (l1->val < l2->val)
        {
            out = l1;
            l1 = l1->next;
        }
        else
        {
            out = l2;
            l2 = l2->next;
        }

        ListNode * n = out;

        while (l1 && l2)
        {           
            if (l1->val < l2->val)
            {
                n->next = l1;
                l1 = l1->next;
            }
            else
            {
                n->next = l2;
                l2 = l2->next;
            }

            n = n->next;
        }
        
        n->next = l1 ? l1 : l2;

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