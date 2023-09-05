class Solution
{
public:
    int bestClosingTime(string customers)
    {
        // APPROCH
        // total penality is (pre N) + (post Y)
        // number of customer don't comes before close
        // number of customer comes at or after close

        int n = customers.size();
        vector<int> pre_N(n), post_Y(n);

        // how many y or n  ith index
        pre_N[0] = (customers[0] == 'N');
        post_Y[n - 1] = (customers[n - 1] == 'Y');

        for (int i = 1; i < n; i++)
        {
            if (customers[i] == 'N')
                pre_N[i] = pre_N[i - 1] + 1;
            else
                pre_N[i] = pre_N[i - 1];

            if (customers[n - 1 - i] == 'Y')
                post_Y[n - 1 - i] = post_Y[n - i] + 1;
            else
                post_Y[n - 1 - i] = post_Y[n - i];
        }

        int minPenality = INT_MAX, best_time;
        for (int i = 0; i < n; i++)
        {
            // before close '<'
            int preN = (i - 1 < 0) ? 0 : pre_N[i - 1];
            // close or after close '>='
            int postY = post_Y[i];
            int penality = preN + postY;

            if (penality < minPenality)
            {
                minPenality = penality;
                best_time = i;
            }
        }
        // closing the show at the end of the day
        if (pre_N[n - 1] < minPenality)
            best_time = n;

        return best_time;
    }
};