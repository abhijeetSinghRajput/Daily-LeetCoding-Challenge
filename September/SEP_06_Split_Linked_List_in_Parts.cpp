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
    ListNode *tail = NULL;
    void insert(ListNode *&list, int val)
    {
        ListNode *newnode = new ListNode(val);
        if (!list)
        {
            list = newnode;
        }
        else
        {
            tail->next = newnode;
        }
        tail = newnode;
    }
    int getSize(ListNode *head)
    {
        int size = 0;
        while (head)
        {
            size++;
            head = head->next;
        }
        return size;
    }

public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k, NULL);
        int size = getSize(head), i = 0;
        if (k >= size)
        {
            while (head)
            {
                ListNode *newnode = new ListNode(head->val);
                ans[i++] = newnode;
                head = head->next;
            }
            return ans;
        }

        // in this case partition
        int partitionSize = size / k, extra = size % k;
        while (head)
        {
            ListNode *list = NULL;

            if (head && extra)
            {
                // cout<<head->val<<" ";
                insert(list, head->val);
                head = head->next;
                extra--;
            }

            for (int i = 0; i < partitionSize && head; i++)
            {
                // cout<<head->val<<" ";
                insert(list, head->val);
                head = head->next;
            }
            cout << endl;
            ans[i++] = list;
        }
        return ans;
    }
};