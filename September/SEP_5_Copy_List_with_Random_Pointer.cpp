/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, int> map;
        Node *temp = head;
        int i = 0;
        while (temp)
        {
            map[temp] = i++;
            temp = temp->next;
        }
        // 7 0
        // 13 1
        // 11 2
        // 10 3
        // 1  4

        Node *newHead = NULL, *tail = NULL;
        temp = head;
        while (temp)
        {
            Node *newnode = new Node(temp->val);
            if (!newHead)
            {
                newHead = newnode;
            }
            else
            {
                tail->next = newnode;
            }
            tail = newnode;
            temp = temp->next;
        }

        vector<Node *> aux;
        temp = newHead;
        while (temp)
        {
            aux.push_back(temp);
            temp = temp->next;
        }

        temp = head;
        Node *newTemp = newHead;

        while (temp)
        {
            Node *rand = NULL;
            if (temp->random)
            {
                int i = map[temp->random];
                rand = aux[i];
            }
            newTemp->random = rand;
            temp = temp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};