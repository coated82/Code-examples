#include <bits/stdc++.h>

#define MAXV 10005

using namespace std;

vector <int> adj[MAXV];  // Lista de adjacência para representar o grafo
bool vis[MAXV];          // Array para marcar vértices visitados

// Função de busca em profundidade (DFS)
void dfs(int u)
{
    vis[u] = true;  // Marca o vértice atual como visitado

    // Percorre todos os vizinhos do vértice atual
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];  // Próximo vértice vizinho

        // Se o vértice vizinho não foi visitado, visita recursivamente
        if (vis[v] == false)
            dfs(v);
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

    // Lê o vértice de origem para iniciar a DFS
    int origem;
    cin >> origem;
    dfs(origem);

    // Logica da questao
    // Após a DFS, o array 'vis' indica quais vértices são alcançáveis a partir da origem
    
    // Exemplo: contar quantos vértices são alcançáveis
    int contador = 0;
    for (int i = 1; i <= nVertices; i++) {
        if (vis[i]) contador++;
    }
    cout << "Vertices alcancaveis a partir de " << origem << ": " << contador << endl;

    return 0;
}

/*
CASOS DE TESTE PARA ESTUDO:

Caso de Teste 1: Grafo Conexo Simples
Entrada:
5 4
1 2
1 3
2 4
3 5
1

Saída esperada:
Vertices alcancaveis a partir de 1: 5
Explicação: Todos os vértices são alcançáveis a partir do vértice 1.

Caso de Teste 2: Grafo com Componentes Desconexos
Entrada:
6 3
1 2
2 3
4 5
1

Saída esperada:
Vertices alcancaveis a partir de 1: 3
Explicação: Apenas os vértices 1, 2, 3 são alcançáveis. Os vértices 4, 5, 6 formam componentes separados.

Caso de Teste 3: Grafo Linear
Entrada:
4 3
1 2
2 3
3 4
1

Saída esperada:
Vertices alcancaveis a partir de 1: 4
Explicação: O grafo é uma linha: 1-2-3-4, todos alcançáveis a partir de 1.

Caso de Teste 4: Grafo com Apenas um Vértice
Entrada:
1 0
1

Saída esperada:
Vertices alcancaveis a partir de 1: 1
Explicação: Grafo com apenas um vértice isolado.

Caso de Teste 5: Grafo Estrela
Entrada:
5 4
1 2
1 3
1 4
1 5
1

Saída esperada:
Vertices alcancaveis a partir de 1: 5
Explicação: Vértice 1 conectado a todos os outros, formando uma estrela.

Caso de Teste 6: Grafo Vazio
Entrada:
0 0
0

Saída esperada:
Vertices alcancaveis a partir de 0: 0
Explicação: Grafo sem vértices.

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
Vertices alcancaveis a partir de 1: 4
Explicação: Grafo completo onde todos os vértices estão conectados entre si.

PARA TESTAR:
1. Copie a entrada desejada
2. Cole no terminal ao executar o programa
3. Compare com a saída esperada

CONCEITOS IMPORTANTES:
- DFS (Busca em Profundidade): Explora o máximo possível em um ramo antes de retroceder
- Grafo Não-Direcionado: Arestas bidirecionais
- Lista de Adjacência: Estrutura eficiente para grafos esparsos
- Componentes Conexos: Grupos de vértices conectados entre si
- Marcação de Visitados: Evita ciclos infinitos na travessia
*/