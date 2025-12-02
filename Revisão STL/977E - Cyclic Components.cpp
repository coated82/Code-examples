#include <bits/stdc++.h>
using namespace std;

#define MAXV 1000005

vector<int> adj[MAXV];
bool vis[MAXV];
bool ciclo;

void dfs(int u)
{
    vis[u] = true;

    if ((int)adj[u].size() != 2) // se tiver mais de uma conexão ele não é ciclico
    {
        ciclo = false;
    }

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, A, x, y;

    cin >> V >> A;

    for (int i = 0; i < A; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int res = 0;

    for (int i = 0; i < V; i++) // verifica ciclos a partir dos vertices
    {
        if (!vis[i])
        {
            ciclo = true;
            dfs(i);
            if (ciclo)
            {
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}