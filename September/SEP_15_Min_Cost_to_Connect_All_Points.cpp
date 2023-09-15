class pair_hash
{
public:
    size_t operator()(const pair<int, int> point) const
    {
        size_t h1 = hash<int>{}(point.first);
        size_t h2 = hash<int>{}(point.second);
        return h1 ^ h2;
    }
};
class Solution
{
    void init(auto &keys, auto &points)
    {
        for (auto point : points)
        {
            keys[{point[0], point[1]}] = INT_MAX;
        }
    }
    void initFalse(auto &set, auto &points)
    {
        for (auto point : points)
        {
            set[{point[0], point[1]}] = false;
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        unordered_map<pair<int, int>, vector<vector<int>>, pair_hash> adj;
        for (int i = 0; i < points.size(); i++)
        {
            int Xi = points[i][0];
            int Yi = points[i][1];
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {
                    int Yj = points[j][1];
                    int Xj = points[j][0];
                    int distance = abs(Xi - Xj) + abs(Yi - Yj);
                    adj[{Xi, Yi}].push_back({Xj, Yj, distance});
                }
            }
        }

        // finding minimum spanning tree (Prim's Algo)
        int V = points.size(), cost = 0;
        unordered_map<pair<int, int>, int, pair_hash> keys;
        unordered_map<pair<int, int>, bool, pair_hash> set;
        initFalse(set, points);
        init(keys, points);
        keys.begin()->second = 0;
        for (int i = 0; i < V; i++)
        {
            pair<int, int> u = {-1, -1};
            // keys[{x,y}] = distance
            //      .first    .second
            for (auto it : keys)
            {
                if (!set[it.first])
                {
                    if ((u.first == -1 && u.second == -1) || it.second < keys[u])
                    {
                        u = it.first;
                    }
                }
            }

            set[u] = true;
            cost += keys[u];

            for (auto neighbour : adj[u])
            {
                pair<int, int> v = {neighbour[0], neighbour[1]};
                int distance = neighbour[2];
                if (!set[v])
                {
                    keys[v] = min(keys[v], distance);
                }
            }
        }
        return cost;
    }
};