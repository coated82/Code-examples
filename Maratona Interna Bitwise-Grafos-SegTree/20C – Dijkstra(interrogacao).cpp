#include <bits/stdc++.h>
#define INF 1e18
#define MAXV 100005
using namespace std;

vector<pair<int, int>> adj[MAXV];

long long dist[MAXV];

// Vetor que guarda o "pai" de cada vértice no caminho mínimo.
// Serve para reconstruir o caminho final depois.
int pai[MAXV];

// Implementação do algoritmo de Dijkstra.
// origem: vértice de partida (no problema, é sempre 1)
// nVertices: número total de vértices do grafo
void dijkstra(int origem, int nVertices)
{
    // Vetor que marca quais vértices já tiveram sua menor distância definida.
    vector<bool> vis(nVertices + 1, false);

    // Fila de prioridade (min-heap) que armazena pares (distância, vértice).
    // O menor valor de distância sempre fica no topo.
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 1; i <= nVertices; i++)
    {
        dist[i] = INF;   
        pai[i] = -1;     
    }

    dist[origem] = 0;      
    pq.push({0, origem});      
    
    while (!pq.empty())
    {
        int u = pq.top().second;    
        long long du = pq.top().first;
        pq.pop();

        if (vis[u])                  
            continue;
        vis[u] = true;                

        for (auto [v, w] : adj[u])
        {
            // Relaxamento da aresta (u, v)
            // Se encontrar um caminho mais curto até v passando por u...
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;  // atualiza a distância mínima até v
                pai[v] = u;             // guarda que chegamos em v a partir de u
                pq.push({dist[v], v});  // adiciona v na fila para processar
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nVertices, nArestas;
    cin >> nVertices >> nArestas;

    for (int i = 0; i < nArestas; i++)
    {
        int x, y, custo;
        cin >> x >> y >> custo;
        adj[x].push_back({y, custo});
        adj[y].push_back({x, custo});
    }

    int origem = 1;         
    int destino = nVertices; 

    dijkstra(origem, nVertices);

    if (dist[destino] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        // Reconstrói o caminho percorrendo o vetor pai de trás pra frente.
        // Começamos do destino e subimos até chegar na origem.
        vector<int> caminho;
        for (int v = destino; v != -1; v = pai[v])
            caminho.push_back(v);

        // Como o vetor foi construído de trás pra frente, invertemos.
        reverse(caminho.begin(), caminho.end());

        // Imprime o caminho mínimo do vértice 1 até o vértice n.
        for (int v : caminho)
            cout << v << " ";
        cout << endl;
    }

    return 0;
}
