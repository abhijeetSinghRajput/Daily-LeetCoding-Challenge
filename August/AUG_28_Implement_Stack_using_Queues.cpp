class MyStack
{
    deque<int> q;
    // q back will be top();
public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push_back(x);
    }

    int pop()
    {
        if (!empty())
        {
            int poped = top();
            q.pop_back();
            return poped;
        }
        return -1;
    }

    int top()
    {
        if (!empty())
        {
            return q.back();
        }
        return -1;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */