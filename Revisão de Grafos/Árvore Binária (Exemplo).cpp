#include <bits/stdc++.h>

using namespace std;

// Estrutura de um nó da árvore binária
// Cada nó armazena um valor e ponteiros para os filhos esquerdo e direito
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Função para inserir na árvore (versão recursiva)
// A árvore é uma ÁRVORE DE BUSCA BINÁRIA:
// - Valores menores vão para a esquerda
// - Valores maiores vão para a direita
// - Valores iguais não são inseridos (não permite duplicatas)
Node* insert(Node* root, int value) {
    // CASO BASE: se chegamos em uma folha (nullptr), criamos novo nó
    if (root == nullptr) {
        return new Node(value);
    }
    
    // VALOR MENOR: vai para a subárvore esquerda
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    // VALOR MAIOR: vai para a subárvore direita
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // VALOR IGUAL: não faz nada (árvore não permite duplicatas)
    
    return root;
}

// Função para buscar um valor na árvore
// Retorna o nó se encontrado, nullptr se não encontrado
Node* search(Node* root, int value) {
    // CASO BASE 1: árvore vazia ou valor encontrado na raiz
    if (root == nullptr || root->data == value) {
        return root;
    }
    
    // VALOR MENOR: busca na subárvore esquerda
    if (value < root->data) {
        return search(root->left, value);
    } 
    // VALOR MAIOR: busca na subárvore direita
    else {
        return search(root->right, value);
    }
}

// TRAVESSIA EM-ORDEM (IN-ORDER)
// Visita: ESQUERDA -> RAIZ -> DIREITA
// Resultado: VALORES EM ORDEM CRESCENTE
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);        // 1. Visita toda subárvore esquerda
        cout << root->data << " ";  // 2. Visita a raiz
        inOrder(root->right);       // 3. Visita toda subárvore direita
    }
}

// TRAVESSIA PRÉ-ORDEM (PRE-ORDER)  
// Visita: RAIZ -> ESQUERDA -> DIREITA
// Resultado: RAIZ primeiro, depois subárvores
// Útil para copiar a estrutura da árvore
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // 1. Visita a raiz primeiro
        preOrder(root->left);       // 2. Visita subárvore esquerda
        preOrder(root->right);      // 3. Visita subárvore direita
    }
}

// TRAVESSIA PÓS-ORDEM (POST-ORDER)
// Visita: ESQUERDA -> DIREITA -> RAIZ
// Resultado: FOLHAS primeiro, raiz por último
// Útil para deletar a árvore (libera folhas antes da raiz)
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);      // 1. Visita subárvore esquerda
        postOrder(root->right);     // 2. Visita subárvore direita
        cout << root->data << " ";  // 3. Visita a raiz por último
    }
}

// Função para encontrar o menor valor na árvore
// Em uma Árvore de Busca Binária, o menor valor está
// no nó mais à esquerda
Node* findMin(Node* root) {
    // Percorre sempre para a esquerda até encontrar uma folha
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Função para remover um nó - É A MAIS COMPLEXA!
// Tem 3 casos principais para considerar:
Node* remove(Node* root, int value) {
    if (root == nullptr) return root; // Valor não encontrado
    
    // PROCURA O NÓ A SER REMOVIDO
    if (value < root->data) {
        root->left = remove(root->left, value); // Busca na esquerda
    } else if (value > root->data) {
        root->right = remove(root->right, value); // Busca na direita
    } else {
        // NÓ ENCONTRADO! Agora verifica qual dos 3 casos:
        
        // CASO 1: NÓ COM 0 OU 1 FILHO
        if (root->left == nullptr) {
            // Tem apenas filho direito ou nenhum filho
            Node* temp = root->right;
            delete root;
            return temp; // Retorna o filho direito (pode ser nullptr)
        } else if (root->right == nullptr) {
            // Tem apenas filho esquerdo
            Node* temp = root->left;
            delete root;
            return temp; // Retorna o filho esquerdo
        }
        
        // CASO 2: NÓ COM 2 FILHOS
        // Estratégia: encontrar o SUCESSOR IN-ORDER (menor valor da subárvore direita)
        Node* temp = findMin(root->right); // Encontra o menor da direita
        root->data = temp->data; // Copia o valor do sucessor
        root->right = remove(root->right, temp->data); // Remove o sucessor
    }
    return root;
}

// Função para calcular a ALTURA da árvore
// Altura: número de arestas do caminho mais longo da raiz até uma folha
// Árvore vazia: altura -1 (mas aqui retornamos 0 por convenção)
int height(Node* root) {
    if (root == nullptr) return 0;
    
    // Calcula altura das subárvores
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Altura = maior altura das subárvores + 1 (a raiz)
    return max(leftHeight, rightHeight) + 1;
}

// Função para contar quantos nós existem na árvore
int countNodes(Node* root) {
    if (root == nullptr) return 0;
    
    // Total = raiz + nós da esquerda + nós da direita
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// TRAVESSIA POR NÍVEL (BFS - Breadth First Search)
// Visita todos os nós de cada nível antes de ir para o próximo nível
// Usa uma FILA para controlar a ordem de visitação
void levelOrder(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        cout << current->data << " ";
        
        // Adiciona os filhos na fila (se existirem)
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

int main() {
    Node* root = nullptr;
    
    // CONSTRUINDO A ÁRVORE:
    // Inserindo valores na árvore binária de busca
    // A ordem de inserção afeta a estrutura da árvore!
    root = insert(root, 50);  // Raiz
    root = insert(root, 30);  // Vai para esquerda (30 < 50)
    root = insert(root, 70);  // Vai para direita (70 > 50)
    root = insert(root, 20);  // Vai para esquerda de 30 (20 < 30)
    root = insert(root, 40);  // Vai para direita de 30 (40 > 30)
    root = insert(root, 60);  // Vai para esquerda de 70 (60 < 70)
    root = insert(root, 80);  // Vai para direita de 70 (80 > 70)
    
    /* 
        ESTRUTURA DA ÁRVORE CRIADA:
              50
            /    \
           30     70
          /  \   /  \
         20  40 60  80
    */
    
    cout << "Travessia em-ordem: ";
    inOrder(root);  // Deve mostrar: 20 30 40 50 60 70 80
    cout << endl;
    
    cout << "Travessia pré-ordem: ";
    preOrder(root); // Deve mostrar: 50 30 20 40 70 60 80
    cout << endl;
    
    cout << "Travessia pós-ordem: ";
    postOrder(root); // Deve mostrar: 20 40 30 60 80 70 50
    cout << endl;
    
    cout << "Travessia por nível: ";
    levelOrder(root); // Deve mostrar: 50 30 70 20 40 60 80
    cout << endl;
    
    // BUSCA NA ÁRVORE
    int searchValue = 40;
    Node* found = search(root, searchValue);
    if (found != nullptr) {
        cout << "Valor " << searchValue << " encontrado!" << endl;
    } else {
        cout << "Valor " << searchValue << " nao encontrado!" << endl;
    }
    
    // ESTATÍSTICAS DA ÁRVORE
    cout << "Altura da arvore: " << height(root) << endl;
    cout << "Total de nos: " << countNodes(root) << endl;
    
    // DEMONSTRAÇÃO DE REMOÇÃO
    cout << "\n=== DEMONSTRACAO DE REMOCAO ===" << endl;
    cout << "Removendo o valor 30 (no com dois filhos)..." << endl;
    root = remove(root, 30);
    
    /* 
        APÓS REMOVER 30:
        Estratégia: substituir pelo sucessor in-order (40)
        Nova estrutura:
              50
            /    \
           40     70
          /      /  \
         20     60  80
    */
    
    cout << "Travessia em-ordem apos remocao: ";
    inOrder(root);  // Deve mostrar: 20 40 50 60 70 80
    cout << endl;
    
    return 0;
}

/*
CASOS DE TESTE PARA ESTUDO - ÁRVORE BINÁRIA:

Caso de Teste 1: Árvore Balanceada
Entrada: 50, 30, 70, 20, 40, 60, 80
Saída esperada:
Em-ordem: 20 30 40 50 60 70 80
Pré-ordem: 50 30 20 40 70 60 80
Pós-ordem: 20 40 30 60 80 70 50
Por nível: 50 30 70 20 40 60 80

Caso de Teste 2: Árvore Degenerada (lista)
Entrada: 10, 20, 30, 40, 50
Saída esperada:
Em-ordem: 10 20 30 40 50
Pré-ordem: 10 20 30 40 50
Por nível: 10 20 30 40 50

Caso de Teste 3: Árvore com Apenas Raiz
Entrada: 100
Saída esperada:
Todas as travessias: 100

Caso de Teste 4: Árvore Vazia
Entrada: (nenhuma)
Saída esperada:
Todas as travessias: (nada)

Caso de Teste 5: Remoções
Entrada inicial: 50, 30, 70, 20, 40
Remover: 30 (nó com dois filhos)
Saída esperada após remoção:
Em-ordem: 20 40 50 70

FUNÇÕES IMPLEMENTADAS:

1. insert() - Insere um novo nó
2. search() - Busca um valor
3. remove() - Remove um nó
4. inOrder() - Travessia em-ordem
5. preOrder() - Travessia pré-ordem  
6. postOrder() - Travessia pós-ordem
7. levelOrder() - Travessia por nível (BFS)
8. height() - Calcula altura
9. countNodes() - Conta total de nós
10. findMin() - Encontra menor valor

CARACTERÍSTICAS DA ÁRVORE BINÁRIA:

- Árvore de Busca Binária: valores menores à esquerda, maiores à direita
- Complexidade média: O(log n) para busca, inserção e remoção
- Complexidade pior caso: O(n) para árvore degenerada
- Travessias:
  * Em-ordem: valores em ordem crescente
  * Pré-ordem: útil para copiar árvore
  * Pós-ordem: útil para deletar árvore
  * Por nível: BFS, útil para encontrar nível

APLICAÇÕES:
- Implementação de conjuntos e mapas
- Árvores de expressões aritméticas
- Sistemas de arquivos
- Compressão de dados (Huffman)
*/