class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> PascalTriangle;

        PascalTriangle.push_back({1});
        if (numRows == 1)
            return PascalTriangle;

        PascalTriangle.push_back({1, 1});
        if (numRows == 2)
            return PascalTriangle;

        for (int i = 1; i < numRows - 1; i++)
        {
            vector<int> row = {1};
            for (int j = 0; j < PascalTriangle[i].size() - 1; j++)
            {
                row.push_back(PascalTriangle[i][j] + PascalTriangle[i][j + 1]);
            }
            row.push_back({1});
            PascalTriangle.push_back(row);
        }
        return PascalTriangle;
    }
};