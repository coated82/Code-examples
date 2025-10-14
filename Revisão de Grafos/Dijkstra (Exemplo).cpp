#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXV 10005

using namespace std;

vector<pair<int, int> > adj[MAXV]; // Lista de adjacência: (vértice, peso)
int dist[MAXV]; // Array para armazenar distâncias mínimas da origem

void dijkstra(int origem)
{
    bool vis[MAXV] = {}; // Array para marcar vértices processados
    priority_queue<pair<int, int> > pq; // Fila de prioridade MAX-heap
    
    // Inicializa todas as distâncias como infinito
    for (int i = 0; i < MAXV; i++)
        dist[i] = INF;

    dist[origem] = 0; // Distância da origem para ela mesma é 0

    // Insere a origem na fila de prioridade
    // Usa distância negativa para simular MIN-heap
    pq.push(make_pair(0, origem)); // (dist, vert)

    while (!pq.empty())
    {
        int u = pq.top().second; // Extrai o vértice com menor distância
        pq.pop();

        // Se o vértice ainda não foi processado
        if (!vis[u])
        {
            vis[u] = true; // Marca como processado

            // Percorre todos os vizinhos de u
            for (int i = 0; i < (int) adj[u].size(); i++)
            {
                int v = adj[u][i].first; // Vértice vizinho
                int duv = adj[u][i].second; // Peso da aresta u-v

                // Relaxamento: se encontrou um caminho menor para v
                if (dist[u] + duv < dist[v]) 
                {
                    dist[v] = dist[u] + duv; // Atualiza a distância mínima
                    pq.push(make_pair(-dist[v], v)); // Insere com distância negativa
                }
            }
        }
    }
}

int main()
{
    int nVertices, nArestas, x, y, custo;

    cin >> nVertices >> nArestas;

    // Constrói o grafo não-direcionado com pesos
    for (int i = 0; i < nArestas; i++)
    {
        cin >> x >> y >> custo;
        adj[x].push_back(make_pair(y, custo));
        adj[y].push_back(make_pair(x, custo));
    }

    int origem, destino;
    cin >> origem >> destino;

    dijkstra(origem);

    if (dist[destino] == INF)
        cout << "Nao existe caminho de " << origem << " ate " << destino << endl;
    else
        cout << "O custo de " << origem << " ate " << destino << " eh " << dist[destino] << endl;

    return 0;
}

/*
CASOS DE TESTE PARA ESTUDO - DIJKSTRA:

Caso de Teste 1: Grafo Simples com Pesos
Entrada:
4 4
1 2 5
1 3 10
2 4 3
3 4 2
1 4

Saída esperada:
O custo de 1 ate 4 eh 8
Explicação: Caminho mínimo: 1→2→4 (5+3=8). O caminho 1→3→4 custa 12.

Caso de Teste 2: Grafo com Caminhos Diferentes
Entrada:
5 7
1 2 4
1 3 2
2 3 1
2 4 5
3 4 8
3 5 10
4 5 2
1 5

Saída esperada:
O custo de 1 ate 5 eh 10
Explicação: Caminho: 1→3→2→4→5 (2+1+5+2=10) ou 1→3→5 (2+10=12) ou 1→2→4→5 (4+5+2=11)
            Saída: 10

Caso de Teste 3: Grafo Desconexo
Entrada:
4 2
1 2 3
3 4 2
1 4

Saída esperada:
Nao existe caminho de 1 ate 4
Explicação: Vértices 1,2 e 3,4 estão em componentes separados.

Caso de Teste 4: Grafo com Uma Aresta
Entrada:
2 1
1 2 7
1 2

Saída esperada:
O custo de 1 ate 2 eh 7
Explicação: Caminho direto entre origem e destino.

Caso de Teste 5: Grafo com Laços (Self-loops)
Entrada:
3 4
1 2 4
2 2 1  // self-loop
2 3 3
1 3 9
1 3

Saída esperada:
O custo de 1 ate 3 eh 7
Explicação: Caminho: 1→2→3 (4+3=7). O self-loop em 2 não afeta.

Caso de Teste 6: Grafo com Pesos Diferentes
Entrada:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1 5

Saída esperada:
O custo de 1 ate 5 eh 6
Explicação: Caminho: 1→2→3→5 (2+1+3=6)

Caso de Teste 7: Grafo Grande
Entrada:
6 9
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 4 11
3 6 2
4 5 6
5 6 9
1 5

Saída esperada:
O custo de 1 ate 5 eh 20
Explicação: Caminho: 1→3→6→5 (9+2+9=20)

CARACTERÍSTICAS DO ALGORITMO DE DIJKSTRA:

1. FUNCIONAMENTO:
   - Encontra caminhos mínimos em grafos com pesos NÃO-NEGATIVOS
   - Usa estratégia gulosa: sempre expande o vértice mais próximo
   - Mantém estimativas de distância e as atualiza com relaxamento

2. ESTRUTURAS DE DADOS:
   - Lista de adjacência: (vértice, peso)
   - Fila de prioridade: para selecionar o próximo vértice
   - Array de distâncias: distâncias mínimas conhecidas
   - Array de visitados: vértices já processados

3. COMPLEXIDADE:
   - Com binary heap: O((V+E) log V)
   - Com Fibonacci heap: O(E + V log V)

4. LIMITAÇÕES:
   - Não funciona com pesos negativos
   - Para pesos negativos, usar Bellman-Ford

DIFERENÇAS ENTRE ALGORITMOS:

BFS: 
- Grafos não-ponderados
- Encontra menor número de arestas
- Complexidade: O(V+E)

Dijkstra:
- Grafos com pesos não-negativos  
- Encontra menor soma de pesos
- Complexidade: O((V+E) log V)

Bellman-Ford:
- Grafos com pesos negativos
- Detecta ciclos negativos
- Complexidade: O(VE)

APLICAÇÕES DO DIJKSTRA:
- Roteamento em redes de computadores
- Sistemas de navegação GPS
- Planejamento de rotas em logística
- Redes de distribuição de energia
*/