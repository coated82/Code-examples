#include <bits/stdc++.h>

#define MAXV 30  // Máximo de 26 vértices (letras de 'a' a 'z')

using namespace std;

vector<int> adj[MAXV];    // Lista de adjacência
bool visited[MAXV];       // Array para vértices visitados

// Função DFS modificada para coletar vértices de um componente
void dfs(int u, vector<char> &component)
{
    visited[u] = true;
    component.push_back('a' + u);  // ALTERAÇÃO 1: Converte índice para letra
    
    // Ordena os vizinhos para manter ordem lexicográfica
    sort(adj[u].begin(), adj[u].end());
    
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            dfs(v, component);
        }
    }
}

int main()
{
    int N;  // Número de casos de teste
    cin >> N;
    
    for(int caseNum = 1; caseNum <= N; caseNum++)
    {
        int V, E;  // Vértices e Arestas
        cin >> V >> E;
        
        // ALTERAÇÃO 2: Reinicializa apenas os vértices necessários (0 a V-1)
        for(int i = 0; i < V; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
        
        // ALTERAÇÃO 3: Lê arestas como caracteres e converte para índices
        for(int i = 0; i < E; i++)
        {
            char u_char, v_char;
            cin >> u_char >> v_char;
            
            int u = u_char - 'a';  // Converte 'a' -> 0, 'b' -> 1, etc.
            int v = v_char - 'a';
            
            // ALTERAÇÃO 4: Grafo não-direcionado (ambas as direções)
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // ALTERAÇÃO 5: Cabeçalho do caso
        cout << "Case #" << caseNum << ":" << endl;
        
        int componentCount = 0;
        vector<vector<char>> allComponents;
        
        // ALTERAÇÃO 6: Encontra todos os componentes conexos
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                vector<char> component;
                dfs(i, component);
                
                // ALTERAÇÃO 7: Ordena o componente lexicograficamente
                sort(component.begin(), component.end());
                allComponents.push_back(component);
                componentCount++;
            }
        }
        
        // ALTERAÇÃO 8: Ordena componentes pelo primeiro elemento
        sort(allComponents.begin(), allComponents.end());
        
        // ALTERAÇÃO 9: Imprime os componentes
        for(const auto &component : allComponents)
        {
            for(int i = 0; i < component.size(); i++)
            {
                cout << component[i];
                if(i < component.size() - 1)
                    cout << ",";
            }
            cout << endl;
        }
        
        // ALTERAÇÃO 10: Imprime contagem de componentes e linha em branco
        cout << componentCount << " connected components" << endl << endl;
    }
    
    return 0;
}

/*

PRINCIPAIS ALTERAÇÕES PARA O PROBLEMA 1082:

1. CONVERSÃO LETRA/ÍNDICE:
   - Vértices são letras de 'a' a 'z'
   - Convertemos 'a' -> 0, 'b' -> 1, etc., para trabalhar com arrays
   - Na saída, convertemos de volta para letras

2. COMPONENTES CONEXOS:
   - Objetivo: encontrar todos os componentes conexos
   - Cada DFS encontra um componente completo

3. ORDENAÇÃO:
   - Ordena vértices dentro de cada componente
   - Ordena componentes pelo primeiro elemento

4. FORMATAÇÃO DE SAÍDA:
   - "Case #X:"
   - Componentes impressos com vértices separados por vírgula
   - Contagem final de componentes

5. GRAFO NÃO-DIRECIONADO:
   - Mantém o grafo não-direcionado do código original
   - Adiciona arestas nas duas direções

EXEMPLO DE FUNCIONAMENTO:

Entrada:
2       ← 2 casos de teste
4 3     ← Primeiro caso: 4 vértices, 3 arestas
a b
b c
c d
6 5     ← Segundo caso: 6 vértices, 5 arestas
a b
b c
c a
d e
e f

Saída:
Case #1:
a,b,c,d
1 connected components

Case #2:
a,b,c
d,e,f
2 connected components

EXPLICAÇÃO:
- No primeiro caso: todos os vértices estão conectados formando um único componente
- No segundo caso: dois componentes separados {a,b,c} e {d,e,f}

DIFERENÇAS DO PROBLEMA ANTERIOR (1081):
- 1081: DFS hierárquica com arestas de retorno em grafo DIRECIONADO
- 1082: Componentes conexos em grafo NÃO-DIRECIONADO
- 1081: Mostra o caminho da DFS
- 1082: Mostra grupos de vértices conectados

CASOS DE TESTE ADICIONAIS:

Caso 1: Vértices isolados
Entrada:
3 0     ← 3 vértices, 0 arestas

Saída:
Case #1:
a
b
c
3 connected components

Caso 2: Grafo completo
Entrada:
3 3
a b
a c
b c

Saída:
Case #1:
a,b,c
1 connected components

Caso 3: Múltiplos componentes
Entrada:
5 2
a b
c d

Saída:
Case #1:
a,b
c,d
e
3 connected components
*/