class Solution
{
    stack<char> stack;
    void fun(int num)
    {
        if (num == 0)
            return;

        if (num % 26 == 0)
        {
            stack.push('Z');
            num--;
        }
        else
            stack.push(64 + (num % 26));

        fun(num / 26);
    }

public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        fun(columnNumber);
        while (!stack.empty())
        {
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
    }
};