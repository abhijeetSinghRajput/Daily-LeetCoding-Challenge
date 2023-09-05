class Solution
{
    string getLine(auto &container, int maxWith)
    {
        int totalFilled = 0;
        for (auto word : container)
        {
            totalFilled += word.size();
        }

        int remainingSpace = maxWith - totalFilled;
        // evenly distribute margin to all word
        if (container.size() == 1)
            return (container[0] + string(remainingSpace, ' '));

        int margin = remainingSpace / (container.size() - 1);
        int extraSpace = remainingSpace % (container.size() - 1);

        string line = "";
        for (int i = 0; i < container.size(); ++i)
        {
            line += container[i];
            // Avoid margin after the last word
            if (i != container.size() - 1)
            {
                line += string(margin, ' ');
                if (extraSpace)
                {
                    line += ' ';
                    extraSpace--;
                }
            }
        }

        return line;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        vector<string> container;
        int count = 0;

        for (auto word : words)
        {
            // checking word will fit or not
            //  I used (container.size() - 1) to ensure that the space required for separating words
            if (count + word.size() + container.size() <= maxWidth)
            {
                container.push_back(word);
                count += word.size();
            }
            else
            {
                ans.push_back(getLine(container, maxWidth));
                container.clear();
                container.push_back(word);
                count = word.size();
            }
        }

        // creating last line with remaining words in container
        string lastLine = "";
        for (auto word : container)
        {
            lastLine += word;
            if (lastLine.size() < maxWidth)
            {
                lastLine += ' ';
            }
        }
        // appending remaining space at the end of the line
        lastLine += string(maxWidth - lastLine.size(), ' ');
        ans.push_back(lastLine);

        return ans;
    }
};