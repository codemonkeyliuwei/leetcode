#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* node = NULL;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        int carry = 0;
        int sum   = 0;

        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL && l2 != NULL)
            {
                sum += (l1->val + l2->val);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            else
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum   = sum % 10;

            node = new ListNode(sum);
            if (NULL == head)
            {
                head = node;
            }
            else
            {
                prev->next = node;
            }
            prev = node;
            
            sum = carry;
        }

        if (sum != 0)
        {
            prev->next = new ListNode(sum);
        }
        
        return head;
    }
};

int main(void)
{
    Solution s;
    ListNode l1_node1(5);
    //ListNode l1_node2(4);
    //ListNode l1_node3(3);
    ListNode l2_node1(5);
    //ListNode l2_node2(6);
    //ListNode l2_node3(4);
    ListNode* list;
    ListNode* temp;
    
    //l1_node1.next = &l1_node2;
    //l1_node2.next = &l1_node3;
    //l2_node1.next = &l2_node2;
    //l2_node2.next = &l2_node3;

    list = s.addTwoNumbers(&l1_node1, &l2_node1);
    while (list != NULL)
    {
        temp = list;
        cout << temp->val << '\t';
        list = list->next;
        delete temp;
    }
    cout << endl;
}
