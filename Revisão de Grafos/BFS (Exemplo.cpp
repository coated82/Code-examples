#include <bits/stdc++.h>

#define MAXV 10005

using namespace std;

vector <int> adj[MAXV];  // Lista de adjacência para representar o grafo
int dist[MAXV];          // Array para armazenar distâncias da origem

// Função de busca em largura (BFS)
void bfs(int origem)
{
    memset(dist, -1, sizeof dist); // Inicializa todas as distâncias como -1 (não visitado)

    queue <int> fila;    // Fila para BFS

    dist[origem] = 0;    // Distância da origem para ela mesma é 0
    fila.push(origem);   // Adiciona a origem na fila

    while (!fila.empty()) // Enquanto houver vértices para processar
    {
        int u = fila.front(); // Pega o primeiro vértice da fila
        fila.pop();           // Remove da fila

        // Percorre todos os vizinhos de u
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];  // Vizinho atual

            if (dist[v] == -1) // se v nao foi visitado
            {
                dist[v] = dist[u] + 1; // distancia até v é 1 + a distancia até u
                fila.push(v); // adiciona v no final da fila
            }
        }
    }
}

int main()
{
    int nVertices, nArestas, x, y;

    // Lê número de vértices e arestas
    cin >> nVertices >> nArestas;

    // Constrói o grafo não-direcionado
    for (int i = 0; i < nArestas; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);  // Adiciona y como vizinho de x
        adj[y].push_back(x);  // Adiciona x como vizinho de y (grafo não-direcionado)
    }

    // Lê o vértice de origem para iniciar a BFS
    int origem;
    cin >> origem;
    bfs(origem);

    // Logica da questao
    // Após a BFS, o array 'dist' contém as distâncias mínimas da origem para cada vértice
    
    // Exemplo: mostrar distâncias de todos os vértices alcançáveis
    cout << "Distancias a partir do vertice " << origem << ":" << endl;
    for (int i = 1; i <= nVertices; i++) {
        if (dist[i] != -1) {
            cout << "Vertice " << i << ": " << dist[i] << endl;
        } else {
            cout << "Vertice " << i << ": inalcancavel" << endl;
        }
    }
    
    return 0;
}

/*
CASOS DE TESTE PARA ESTUDO - BFS:

Caso de Teste 1: Grafo Conexo Simples
Entrada:
5 4
1 2
1 3
2 4
3 5
1

Saída esperada:
Vertice 1: 0
Vertice 2: 1
Vertice 3: 1
Vertice 4: 2
Vertice 5: 2
Explicação: BFS explora em camadas - primeiro os vértices a distância 1, depois 2, etc.

Caso de Teste 2: Grafo com Componentes Desconexos
Entrada:
6 3
1 2
2 3
4 5
1

Saída esperada:
Vertice 1: 0
Vertice 2: 1
Vertice 3: 2
Vertice 4: inalcancavel
Vertice 5: inalcancavel
Vertice 6: inalcancavel
Explicação: Apenas os vértices 1, 2, 3 são alcançáveis. BFS encontra o caminho mínimo.

Caso de Teste 3: Grafo Linear
Entrada:
4 3
1 2
2 3
3 4
1

Saída esperada:
Vertice 1: 0
Vertice 2: 1
Vertice 3: 2
Vertice 4: 3
Explicação: Distâncias aumentam linearmente em um caminho.

Caso de Teste 4: Grafo com Apenas um Vértice
Entrada:
1 0
1

Saída esperada:
Vertice 1: 0
Explicação: Apenas o vértice origem.

Caso de Teste 5: Grafo Estrela
Entrada:
5 4
1 2
1 3
1 4
1 5
1

Saída esperada:
Vertice 1: 0
Vertice 2: 1
Vertice 3: 1
Vertice 4: 1
Vertice 5: 1
Explicação: Todos os vértices estão a distância 1 da origem.

Caso de Teste 6: Grafo em Grade 3x3
Entrada:
9 12
1 2
2 3
1 4
2 5
3 6
4 5
5 6
4 7
5 8
6 9
7 8
8 9
1

Saída esperada:
Vertice 1: 0
Vertice 2: 1
Vertice 3: 2
Vertice 4: 1
Vertice 5: 2
Vertice 6: 3
Vertice 7: 2
Vertice 8: 3
Vertice 9: 4
Explicação: Demonstra como BFS encontra caminhos mais curtos em grades.

Caso de Teste 7: Grafo Completo K4
Entrada:
4 6
1 2
1 3
1 4
2 3
2 4
3 4
1

Saída esperada:
Vertice 1: 0
Vertice 2: 1
Vertice 3: 1
Vertice 4: 1
Explicação: Em grafo completo, todos os outros vértices estão a distância 1.

DIFERENÇAS ENTRE BFS E DFS:

BFS (Este código):
- Usa fila (queue)
- Explora em camadas (largura primeiro)
- Encontra caminhos mínimos em grafos não-ponderados
- Consome mais memória para grafos largos

DFS (Código anterior):
- Usa recursão/pilha (stack)
- Explora em profundidade primeiro
- Não garante caminhos mínimos
- Consome menos memória para grafos profundos

CARACTERÍSTICAS DA BFS:
1. Encontra o caminho mais curto em grafos não-ponderados
2. Visita vértices em ordem de distância da origem
3. Usa uma fila para gerenciar a ordem de visitação
4. Complexidade: O(V + E) para lista de adjacência

APLICAÇÕES DA BFS:
- Encontrar caminho mínimo em labirintos
- Verificar conectividade em redes
- Descobrir distâncias em redes sociais
- Algoritmos de roteamento em redes
*/