/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *fast = head, *slow = head;

        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (!fast)
                return false;

            fast = fast->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};