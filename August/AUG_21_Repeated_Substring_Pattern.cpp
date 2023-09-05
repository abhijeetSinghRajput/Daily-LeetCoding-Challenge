class Solution
{
    bool isRepeated(string substr, string s)
    {
        if (s.size() % substr.size() != 0 || substr.size() > s.size() / 2)
            return false;

        cout << substr << endl;
        int i, j;
        for (i = 0, j = 0; i < s.size(); i++, j %= substr.size())
        {
            if (s[i] != substr[j++])
                return false;
        }
        return true;
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        string substr;
        for (int i = 0; i < s.size(); i++)
        {
            substr += s[i];
            if (isRepeated(substr, s))
                return true;
        }
        return false;
    }
};