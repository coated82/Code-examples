#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;  // Tamanho máximo
int n;                    // Tamanho do array
vector<int> arr;          // Array original
vector<int> seg;          // Segment Tree (4 * n)

// --- FUNÇÕES BASE ---

// Constroi a Segment Tree
// node: nó atual, [l, r]: intervalo que o nó representa
void build(int node, int l, int r) {
    if (l == r) {
        // Nó folha - armazena o elemento do array
        seg[node] = arr[l];
        return;
    }
    
    int mid = (l + r) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    
    // Constroi subárvores esquerda e direita
    build(left_child, l, mid);
    build(right_child, mid + 1, r);
    
    // Combina resultados dos filhos (SOMA)
    seg[node] = seg[left_child] + seg[right_child];
    
    // Para MÍNIMO: seg[node] = min(seg[left_child], seg[right_child]);
    // Para MÁXIMO: seg[node] = max(seg[left_child], seg[right_child]);
}

// Atualiza um elemento na posição 'idx' para 'val'
void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        // Encontrou a posição - atualiza
        arr[idx] = val;
        seg[node] = val;
        return;
    }
    
    int mid = (l + r) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    
    // Decide para qual lado ir
    if (idx <= mid) {
        update(left_child, l, mid, idx, val);
    } else {
        update(right_child, mid + 1, r, idx, val);
    }
    
    // Atualiza o nó atual com os novos valores
    seg[node] = seg[left_child] + seg[right_child];
}

// Consulta o intervalo [ql, qr]
int query(int node, int l, int r, int ql, int qr) {
    // Caso 1: intervalo totalmente fora
    if (qr < l || ql > r) {
        return 0;  // Elemento neutro da soma
        // Para mínimo: return INF;
        // Para máximo: return -INF;
    }
    
    // Caso 2: intervalo totalmente dentro
    if (ql <= l && r <= qr) {
        return seg[node];
    }
    
    // Caso 3: intervalo parcialmente dentro
    int mid = (l + r) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    
    int left_sum = query(left_child, l, mid, ql, qr);
    int right_sum = query(right_child, mid + 1, r, ql, qr);
    
    return left_sum + right_sum;
}

// --- FUNÇÕES DE INTERFACE (para facilitar o uso) ---

// Inicializa a Segment Tree
void init_segment_tree(int size) {
    n = size;
    seg.resize(4 * n);
    build(0, 0, n - 1);
}

// Interface para consulta
int range_query(int l, int r) {
    return query(0, 0, n - 1, l, r);
}

// Interface para atualização
void point_update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
}

// --- EXEMPLO DE USO ---
int main() {
    // Array de exemplo
    vector<int> input = {1, 3, 5, 7, 9, 11};
    arr = input;
    n = arr.size();
    
    // Inicializa Segment Tree
    init_segment_tree(n);
    
    cout << "=== SEGMENT TREE - EXEMPLO PRATICO ===" << endl;
    cout << "Array original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Testando consultas
    cout << "\n=== CONSULTAS ===" << endl;
    cout << "Soma [1, 3]: " << range_query(1, 3) << endl;  // 3+5+7 = 15
    cout << "Soma [0, 5]: " << range_query(0, 5) << endl;  // 1+3+5+7+9+11 = 36
    cout << "Soma [2, 4]: " << range_query(2, 4) << endl;  // 5+7+9 = 21
    
    // Testando atualizações
    cout << "\n=== ATUALIZACOES ===" << endl;
    cout << "Atualizando posicao 2 de 5 para 10" << endl;
    point_update(2, 10);
    
    cout << "Array apos update: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Consultas após atualização
    cout << "\n=== CONSULTAS APOS UPDATE ===" << endl;
    cout << "Soma [1, 3]: " << range_query(1, 3) << endl;  // 3+10+7 = 20
    cout << "Soma [0, 5]: " << range_query(0, 5) << endl;  // 1+3+10+7+9+11 = 41
    
    return 0;
}