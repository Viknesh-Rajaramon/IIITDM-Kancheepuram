#include "../include/input.h"

void DPMis(vector<int> adj[], int x, int y, set<int> DP[])
{
    else
    {
        for (int i = 0; i < adj[x].size(); i++)
        {
            if (adj[x][i] != y)
            {
                for (int j = 0; j < adj[adj[x][i]].size(); j++)
                {
                    if (adj[adj[x][i]][j] != x)
                    {
                        if (DP[adj[adj[x][i]][j]].empty())
                            DPMis(adj, adj[adj[x][i]][j], adj[x][i], DP);

                        //cout << S.size() << endl;
                        //S.clear();

                        for (auto it = DP[adj[adj[x][i]][j]].begin(); it != DP[adj[adj[x][i]][j]].end(); it++)
                            S1.insert(*it);
                    }
                }
            }
        }
        S1.insert(x);
        if (S1.size() > S2.size())
            DP[x] = S1;
        else
            DP[x] = S2;
    }
}
