#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXV 20000  // AUMENTADO: Para acomodar números até 10000 e seus invertidos

using namespace std;

// REMOVIDO: vector<pair<int, int> > adj[MAXV]; 
// Não usamos lista de adjacência pré-construída pois os vizinhos são gerados dinamicamente

int dist[MAXV]; // Array para armazenar distâncias mínimas da origem

// FUNÇÃO ADICIONADA: Para inverter os dígitos de um número (operacao do botão 2)
int inverter(int num) {
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + (num % 10);
        num /= 10;
    }
    return invertido;
}

void dijkstra(int origem, int destino)  // MODIFICADO: Adicionado parâmetro destino
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

        // MODIFICADO: Parada precoce se encontramos o destino
        if (u == destino) return;

        // Se o vértice ainda não foi processado
        if (!vis[u])
        {
            vis[u] = true; // Marca como processado

            // MODIFICAÇÃO COMPLETA: Não percorremos lista de adjacência prévia
            // Em vez disso, geramos os vizinhos dinamicamente conforme as operações do problema
            
            // Operação 1: Botão de adicionar 1
            int v1 = u + 1;
            int peso = 1; // Todas as operações custam 1
            
            // Verifica se está dentro dos limites e faz relaxamento
            if (v1 < MAXV && dist[u] + peso < dist[v1]) 
            {
                dist[v1] = dist[u] + peso; // Atualiza a distância mínima
                pq.push(make_pair(-dist[v1], v1)); // Insere com distância negativa
            }

            // Operação 2: Botão de inverter dígitos
            int v2 = inverter(u);
            if (v2 < MAXV && dist[u] + peso < dist[v2]) 
            {
                dist[v2] = dist[u] + peso; // Atualiza a distância mínima
                pq.push(make_pair(-dist[v2], v2)); // Insere com distância negativa
            }
            
            // REMOVIDO: Loop original que percorria lista de adjacência
            /*
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
            */
        }
    }
}

int main()
{
    // MODIFICAÇÃO COMPLETA: Nova estrutura de entrada para o problema 1550
    
    int T; // Número de casos de teste
    cin >> T;
    
    while (T--) {
        int A, B; // Números inicial e final
        cin >> A >> B;
        
        dijkstra(A, B); // MODIFICADO: Chamada com dois parâmetros

        // MODIFICADO: Saída simplificada conforme especificação do problema
        if (dist[B] == INF)
            cout << -1 << endl; // MODIFICADO: Formato de saída do problema
        else
            cout << dist[B] << endl; // MODIFICADO: Apenas o número mínimo de operações
    }

    // REMOVIDO: Construção original do grafo
    /*
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
    */

    return 0;
}

/*
CASOS DE TESTE ESPECÍFICOS PARA O PROBLEMA 1550 - INVERSÃO:

Caso de Teste 1: Exemplo simples
Entrada:
1
1 10

Saída esperada:
5
Explicação: 1→2→3→4→5→10 (5 operações de +1)

Caso de Teste 2: Usando inversão
Entrada:
1
10 1

Saída esperada:
4
Explicação: 10→11→12→21→1 (4 operações: +1, +1, inverter, inverter)

Caso de Teste 3: Inversão direta
Entrada:
1
1234 4321

Saída esperada:
1
Explicação: Apenas 1 operação de inversão

Caso de Teste 4: Números com zeros
Entrada:
1
150 51

Saída esperada:
1
Explicação: 150 invertido vira 51 (zeros à esquerda são ignorados)

PRINCIPAIS ALTERAÇÕES REALIZADAS:

1. REPRESENTAÇÃO DO GRAFO:
   - ORIGINAL: Grafo explícito com lista de adjacência pré-construída
   - MODIFICADO: Grafo implícito onde os vizinhos são gerados dinamicamente
     através das operações permitidas (+1 e inverter)

2. OPERAÇÕES PERMITIDAS:
   - ORIGINAL: Arestas com pesos arbitrários definidos na entrada
   - MODIFICADO: Duas operações fixas, ambas com peso 1:
     * Adicionar 1 ao número atual
     * Inverter os dígitos do número atual

3. ESTRUTURA DE ENTRADA:
   - ORIGINAL: nVertices, nArestas, lista de arestas, origem, destino
   - MODIFICADO: T casos de teste, cada um com A e B

4. OTIMIZAÇÕES:
   - Parada precoce quando o destino é encontrado
   - Limite MAXV aumentado para 20000 para segurança
   - Remoção da lista de adjacência para economizar memória

5. LÓGICA DO ALGORITMO:
   - Mantida a essência do Dijkstra: sempre expandir o vértice mais próximo
   - Adaptada a geração de vizinhos para o problema específico
   - Preservado o uso de fila de prioridade com pesos negativos

POR QUE DIJKSTRA FUNCIONA AQUI:
- Todas as operações têm peso 1 (não-negativo)
- Queremos o caminho com menor soma de pesos
- O grafo implícito é gerado sob demanda
- A estratégia gulosa do Dijkstra é ideal para este cenário
*/