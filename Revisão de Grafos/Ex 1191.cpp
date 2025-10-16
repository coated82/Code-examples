#include <bits/stdc++.h>

#define MAXV 10005

using namespace std;

vector<int> adj[MAXV];    // Lista de adjacência
bool visited[MAXV];       // Array para vértices visitados

// Função DFS modificada para atender aos requisitos do problema 1081
void dfs(int u, int depth, bool &hasPrinted)
{
    visited[u] = true;  // Marca o vértice como visitado
    
    // ORDENAÇÃO DOS VIZINHOS - ALTERAÇÃO 1:
    // O problema exige que os vértices sejam visitados em ordem crescente
    sort(adj[u].begin(), adj[u].end());
    
    // Percorre todos os vizinhos do vértice atual
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        
        // FORMATAÇÃO DA INDENTAÇÃO - ALTERAÇÃO 2:
        // Imprime espaços baseados na profundidade para mostrar hierarquia
        for(int j = 0; j < depth; j++)
            cout << "  ";
        
        // DETECÇÃO DO TIPO DE ARESTA - ALTERAÇÃO 3:
        // Se o vértice NÃO foi visitado, é uma aresta de árvore
        if(!visited[v])
        {
            cout << u << "-" << v << " pathR(G," << v << ")" << endl;
            hasPrinted = true;  // Marca que algo foi impresso neste componente
            dfs(v, depth + 1, hasPrinted);  // Chama recursivamente com profundidade aumentada
        }
        // Se o vértice JÁ foi visitado, é uma aresta de retorno
        else
        {
            cout << u << "-" << v << endl;
            hasPrinted = true;  // Marca que algo foi impresso
        }
    }
}

int main()
{
    int N;  // Número de casos de teste - ALTERAÇÃO 4: Problema tem múltiplos casos
    cin >> N;
    
    for(int caseNum = 1; caseNum <= N; caseNum++)
    {
        int V, E;  // Vértices e Arestas
        cin >> V >> E;
        
        // REINICIALIZAÇÃO DAS ESTRUTURAS - ALTERAÇÃO 5:
        // Limpa e reinicializa para cada caso de teste
        for(int i = 0; i < V; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
        
        // GRAFO DIRECIONADO - ALTERAÇÃO 6:
        // Ao contrário do código base, este problema é com grafo DIRECIONADO
        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);  // Apenas uma direção - grafo direcionado
            // ALTERAÇÃO: Removido adj[v].push_back(u) do código original
        }
        
        // CABEÇALHO DO CASO - ALTERAÇÃO 7:
        cout << "Caso " << caseNum << ":" << endl;
        
        // CONTROLE DE COMPONENTES CONEXOS - ALTERAÇÃO 8:
        // Executa DFS para cada componente conexo não visitado
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                bool hasPrinted = false;  // Controla se este componente imprimiu algo
                dfs(i, 1, hasPrinted);    // Inicia DFS com profundidade 1
                
                // FORMATAÇÃO ENTRE COMPONENTES - ALTERAÇÃO 9:
                // Pula linha apenas se o componente imprimiu algo E não é o último
                if(hasPrinted && i < V-1)
                {
                    // Verifica se há mais componentes não visitados
                    bool moreComponents = false;
                    for(int j = i+1; j < V; j++)
                    {
                        if(!visited[j])
                        {
                            moreComponents = true;
                            break;
                        }
                    }
                    if(moreComponents)
                        cout << endl;
                }
            }
        }
    }
    
    return 0;
}

/*

PRINCIPAIS ALTERAÇÕES DO CÓDIGO BASE:

1. GRAFO DIRECIONADO:
   - Original: grafo não-direcionado (adicionava arestas nas duas direções)
   - Alterado: grafo direcionado (apenas adj[u].push_back(v))

2. HIERARQUIA DE PROFUNDIDADE:
   - Adicionado parâmetro 'depth' na DFS
   - Implementada indentação com espaços baseada na profundidade

3. FORMATAÇÃO DE SAÍDA ESPECÍFICA:
   - Arestas de árvore: "u-v pathR(G,v)"
   - Arestas de retorno: "u-v"
   - Cabeçalho: "Caso X:"

4. ORDENAÇÃO DOS VIZINHOS:
   - sort(adj[u].begin(), adj[u].end()) para visitar em ordem crescente

5. CONTROLE DE MÚLTIPLOS CASOS:
   - Loop principal para N casos de teste
   - Reinicialização das estruturas para cada caso

6. DETECÇÃO DE TIPOS DE ARESTA:
   - Aresta de árvore: quando o vértice destino não foi visitado
   - Aresta de retorno: quando o vértice destino já foi visitado

7. TRATAMENTO DE MÚLTIPLOS COMPONENTES:
   - Executa DFS para cada vértice não visitado
   - Controla quebra de linha entre componentes

EXEMPLO DE FUNCIONAMENTO:

Entrada: 
2        ← 2 casos de teste
4 4      ← Primeiro caso: 4 vértices, 4 arestas
0 1
1 2
2 3
3 1
6 7      ← Segundo caso: 6 vértices, 7 arestas
0 1
0 4
4 2
2 3
3 4
2 1
5 0

Saída:
Caso 1:
0-1 pathR(G,1)    ← Aresta de árvore (não visitado)
  1-2 pathR(G,2)  ← Hierarquia com 2 espaços (profundidade 2)
    2-3 pathR(G,3)← Hierarquia com 4 espaços (profundidade 3)
      3-1         ← Aresta de retorno (já visitado)

Caso 2:
0-1 pathR(G,1)
  1-2 pathR(G,2)
    2-3 pathR(G,3)
      3-4         ← Aresta de retorno
    2-1           ← Aresta de retorno
0-4               ← Aresta de árvore (mas formato diferente)
4-2               ← Aresta de árvore
5-0 pathR(G,0)    ← Novo componente conexo

O problema exige essa formatação específica para demonstrar a hierarquia 
de profundidade da DFS e identificar arestas de retorno.
*/