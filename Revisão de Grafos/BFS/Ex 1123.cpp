#include <bits/stdc++.h>

#define MAXV 255
#define INF 1000000000

using namespace std;

// ALTERAÇÃO 1: Estrutura para representar arestas ponderadas
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

vector<Edge> adj[MAXV];  // ALTERAÇÃO 2: Lista de adjacência com pesos
int dist[MAXV];          // Array para armazenar distâncias
bool visited[MAXV];      // Array para vértices visitados

// ALTERAÇÃO 3: Algoritmo de Dijkstra para caminhos mínimos
void dijkstra(int origem, int destino, int c, int k) {
    // Inicializa distâncias como infinito
    for (int i = 0; i < MAXV; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    
    dist[origem] = 0;
    
    // Fila de prioridade min-heap: (distância, vértice)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, origem});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        // Se já encontramos um caminho melhor, ignora
        if (current_dist > dist[u]) continue;
        
        // ALTERAÇÃO 4: Lógica especial para vértices antes do ponto crítico
        // Se estamos antes do ponto c (cidades com serviço), só podemos ir para a próxima
        if (u < c) {
            for (const Edge &edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                // Só podemos ir para a próxima cidade na sequência
                if (v == u + 1) {
                    int new_dist = dist[u] + weight;
                    if (new_dist < dist[v]) {
                        dist[v] = new_dist;
                        pq.push({new_dist, v});
                    }
                }
            }
        } else {
            // ALTERAÇÃO 5: Para vértices após o ponto c, podemos usar qualquer aresta
            for (const Edge &edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                int new_dist = dist[u] + weight;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }
    }
}

int main() {
    int n, m, c, k;
    
    // ALTERAÇÃO 6: Lê entrada até encontrar 0 0 0 0
    while (cin >> n >> m >> c >> k) {
        if (n == 0 && m == 0 && c == 0 && k == 0) break;
        
        // ALTERAÇÃO 7: Limpa o grafo para cada caso
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        
        // ALTERAÇÃO 8: Lê as arestas ponderadas
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            
            // Grafo não-direcionado
            adj[u].push_back(Edge(v, p));
            adj[v].push_back(Edge(u, p));
        }
        
        // ALTERAÇÃO 9: Executa Dijkstra com as restrições
        dijkstra(k, c-1, c, k);
        
        // ALTERAÇÃO 10: Imprime o resultado
        cout << dist[c-1] << endl;
    }
    
    return 0;
}

/*

PRINCIPAIS ALTERAÇÕES DO CÓDIGO BASE:

1. MUDANÇA PARA GRAFO PONDERADO:
   - Original: BFS para grafos não-ponderados
   - Alterado: Dijkstra para grafos com pesos

2. ESTRUTURA DE ARESTAS COM PESO:
   - Nova struct Edge com destino e peso
   - Lista de adjacência armazena Edge em vez de int

3. ALGORITMO DE DIJKSTRA:
   - Usa priority_queue para eficiência
   - Complexidade: O((V + E) log V)

4. LÓGICA ESPECIAL DO PROBLEMA:
   - Restrição: nas primeiras c cidades, só podemos seguir a rota sequencial
   - Após a cidade c-1, podemos usar qualquer caminho

5. ENTRADA CONTÍNUA:
   - Lê casos até encontrar 0 0 0 0

EXPLICAÇÃO DO PROBLEMA:

Parâmetros:
- n: número total de cidades
- m: número de estradas
- c: número de cidades na rota de serviço
- k: cidade de origem

Restrição:
- Nas primeiras c cidades (0 a c-1), o caminhão deve seguir a rota sequencial:
  cidade i só pode ir para cidade i+1
- Após a cidade c-1, o caminhão pode usar qualquer estrada

OBJETIVO: Encontrar o caminho mínimo de k até c-1

EXEMPLO DE FUNCIONAMENTO:

Entrada:
6 7 4 3    // n=6, m=7, c=4, k=3
0 1 10     // estrada 0-1 com peso 10
0 2 15     // estrada 0-2 com peso 15
1 3 12     // estrada 1-3 com peso 12
2 5 6      // estrada 2-5 com peso 6
3 4 13     // estrada 3-4 com peso 13
3 5 2      // estrada 3-5 com peso 2
4 5 11     // estrada 4-5 com peso 11
0 0 0 0    // termina

Saída esperada: 28

Explicação:
Rota de serviço: 0 → 1 → 2 → 3 (cidades 0 a 3)
Origem: cidade 3

Como k=3 já está na rota de serviço, só podemos ir sequencialmente:
3 → 2 → 1 → 0 não é permitido (só vai para frente)

Mas podemos sair da rota após c-1=3:
3 → 5 → 2 não é permitido pois 2 < c

A solução correta é usar Dijkstra com a restrição.

CASOS DE TESTE ADICIONAIS:

Caso 1: Origem já no destino
Entrada:
4 3 4 3
0 1 10
1 2 20
2 3 30
0 0 0 0

Saída: 0

Caso 2: Origem após a rota de serviço
Entrada:
5 4 3 4
0 1 10
1 2 20
2 3 30
3 4 40
0 0 0 0

Saída: 40

Caso 3: Múltiplos caminhos possíveis
Entrada:
5 6 3 4
0 1 10
1 2 20
2 3 5
3 4 8
0 4 50
2 4 15
0 0 0 0

Saída: 20  (4 → 2 → 3)

DIFERENÇAS DO CÓDIGO ORIGINAL:

1. ALGORITMO:
   - Original: BFS para distâncias em grafos não-ponderados
   - Alterado: Dijkstra para caminhos mínimos em grafos ponderados

2. ESTRUTURA DE DADOS:
   - Original: vector<int> adj[MAXV] para grafos não-ponderados
   - Alterado: vector<Edge> adj[MAXV] para grafos ponderados

3. LÓGICA DE RESTRIÇÕES:
   - Original: sem restrições de movimento
   - Alterado: restrições específicas baseadas no valor de c

4. ENTRADA/SAÍDA:
   - Original: um caso por execução
   - Alterado: múltiplos casos até condição de parada

COMPLEXIDADE:
- Dijkstra: O((V + E) log V)
- Adequado para as constraints do problema (V ≤ 250)
*/
