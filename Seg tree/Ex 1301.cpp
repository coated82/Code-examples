#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
int n;
vector<int> arr;
vector<int> seg;

// ALTERAÇÃO 1: Função para converter valor para representação do produto
// No problema 1301, só nos importa o sinal, não o valor exato
int value_to_sign(int x) {
    if (x == 0) return 0;      // Zero permanece zero
    return (x > 0) ? 1 : -1;   // Positivo vira 1, negativo vira -1
}

// Build da Segment Tree
void build(int node, int l, int r) {
    if (l == r) {
        // ALTERAÇÃO 2: Armazena apenas o sinal do valor
        seg[node] = value_to_sign(arr[l]);
        return;
    }
    
    int mid = (l + r) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    
    build(left_child, l, mid);
    build(right_child, mid + 1, r);
    
    // ALTERAÇÃO 3: PRODUTO em vez de SOMA
    // Multiplica os sinais dos filhos em vez de somar
    seg[node] = seg[left_child] * seg[right_child];
}

// Update: altera um elemento
void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        arr[idx] = val;
        // ALTERAÇÃO 4: Atualiza com o sinal do novo valor
        seg[node] = value_to_sign(val);
        return;
    }
    
    int mid = (l + r) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    
    if (idx <= mid) {
        update(left_child, l, mid, idx, val);
    } else {
        update(right_child, mid + 1, r, idx, val);
    }
    
    // ALTERAÇÃO 5: Atualiza com produto em vez de soma
    seg[node] = seg[left_child] * seg[right_child];
}

// Query: produto do intervalo [ql, qr]
int query(int node, int l, int r, int ql, int qr) {
    // Caso 1: intervalo totalmente fora
    if (qr < l || ql > r) {
        // ALTERAÇÃO 6: Elemento neutro da MULTIPLICAÇÃO é 1 (não 0)
        // Pois 1 * x = x (não altera o resultado)
        return 1;
    }
    
    // Caso 2: intervalo totalmente dentro
    if (ql <= l && r <= qr) {
        return seg[node];
    }
    
    // Caso 3: intervalo parcialmente dentro
    int mid = (l + r) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;
    
    int left_prod = query(left_child, l, mid, ql, qr);
    int right_prod = query(right_child, mid + 1, r, ql, qr);
    
    // ALTERAÇÃO 7: Retorna produto em vez de soma
    return left_prod * right_prod;
}

// Funções de interface (mantidas da versão base)
void init_segment_tree(int size) {
    n = size;
    seg.resize(4 * n);
    build(0, 0, n - 1);
}

int range_query(int l, int r) {
    return query(0, 0, n - 1, l, r);
}

void point_update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
}

int main() {
    // ALTERAÇÃO 8: Otimização de I/O para problemas grandes
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    
    // ALTERAÇÃO 9: Loop para múltiplos casos de teste (até EOF)
    while (cin >> N >> K) {
        // Lê o array original
        arr.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        // Constrói a Segment Tree
        init_segment_tree(N);
        
        // Processa os comandos
        for (int i = 0; i < K; i++) {
            char cmd;
            int a, b;
            cin >> cmd >> a >> b;
            
            if (cmd == 'C') {
                // ALTERAÇÃO 10: UPDATE - altera elemento na posição a-1 para valor b
                // Obs: problema usa indexação 1-based, convertemos para 0-based
                point_update(a - 1, b);
            } else if (cmd == 'P') {
                // ALTERAÇÃO 11: QUERY - produto do intervalo [a-1, b-1]
                int result = range_query(a - 1, b - 1);
                
                // ALTERAÇÃO 12: Converte o resultado para o formato exigido
                // 0 → '0', positivo → '+', negativo → '-'
                if (result == 0) {
                    cout << '0';
                } else if (result > 0) {
                    cout << '+';
                } else {
                    cout << '-';
                }
            }
        }
        // ALTERAÇÃO 13: Nova linha após cada caso
        cout << '\n';
    }
    
    return 0;
}