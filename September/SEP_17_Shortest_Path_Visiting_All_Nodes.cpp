// question no 847

class Hash
{
public:
    size_t operator()(const pair<int, int> &p) const
    {
        size_t h1 = std::hash<int>{}(p.first);
        size_t h2 = std::hash<int>{}(p.second);
        return (h1 ^ h2);
    }
};
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        // there is no edge
        if (n == 0 || n == 1)
            return 0;

        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, Hash> visited;

        for (int i = 0; i < n; i++)
        {
            q.push({i, (1 << i)});
            visited.insert({i, (1 << i)});
        }

        int allVisited = (1 << n) - 1;
        int paths = 0;

        while (!q.empty())
        {
            int size = q.size();
            paths++;
            while (size--)
            {

                auto curr = q.front();
                q.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for (auto &adj : graph[currNode])
                {
                    // combine currmast with ongoing node
                    int nextMask = currMask | (1 << adj);

                    if (nextMask == allVisited)
                    {
                        return paths;
                    }

                    if (visited.find({adj, nextMask}) == visited.end())
                    {
                        visited.insert({adj, nextMask});
                        q.push({adj, nextMask});
                    }
                }
            }
        }
        return -1;
    }
};