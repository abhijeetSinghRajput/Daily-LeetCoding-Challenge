class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> vec(n, 1);

        // compare with left neighbours
        for (int i = 0; i < n; i++)
        {
            if (i - 1 >= 0 && ratings[i] > ratings[i - 1])
            {
                vec[i] = vec[i - 1] + 1;
            }
        }
        for (auto i : vec)
            cout << i << " ";
        cout << endl;
        // compare with right neighbours
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + 1 < n && ratings[i] > ratings[i + 1])
            {
                vec[i] = max(vec[i], vec[i + 1] + 1);
            }
        }
        for (auto i : vec)
            cout << i << " ";

        int sum = accumulate(vec.begin(), vec.end(), 0);
        return sum;
    }
};