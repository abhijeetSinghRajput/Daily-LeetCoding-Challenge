class Solution
{
    unordered_map<string, multiset<string>> adj;
    vector<string> route;

    void dfs(string airport)
    {
        while (!adj[airport].empty())
        {
            string next = *(adj[airport].begin());
            adj[airport].erase(adj[airport].begin());
            dfs(next);
        }
        route.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto ticket : tickets)
        {
            adj[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        return vector<string>(route.rbegin(), route.rend());
    }
};
