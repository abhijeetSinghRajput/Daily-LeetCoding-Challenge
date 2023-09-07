/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    ListNode *reverse(ListNode *curr, ListNode *tail)
    {
        ListNode *prevNode, *nextNode, *temp = curr;

        prevNode = nextNode = NULL;
        while (curr != tail)
        {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        temp->next = tail;
        return prevNode;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *temp = head, *leftNode = head, *rightNode;
        int i = 1;
        while (temp)
        {
            if (i == left - 1)
                leftNode = temp;
            if (i == right)
                rightNode = temp;
            i++;
            temp = temp->next;
        }
        if (left == 1)
            head = reverse(leftNode, rightNode->next);
        else
            leftNode->next = reverse(leftNode->next, rightNode->next);

        return head;
    }
};