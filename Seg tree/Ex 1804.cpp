#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010; // Tamanho máximo
int n;                   // Tamanho do array
vector<int> arr;         // Array original
vector<int> seg;         // Segment Tree (4 * n)

// --- FUNÇÕES BASE ---

// Constroi a Segment Tree
// node: nó atual, [l, r]: intervalo que o nó representa
void build(int node, int l, int r)
{
    if (l == r)
    {
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
}

// Atualiza um elemento na posição 'idx' para 'val'
void update(int node, int l, int r, int idx, int val)
{
    if (l == r)
    {
        // Encontrou a posição - atualiza
        arr[idx] = val;
        seg[node] = val;
        return;
    }

    int mid = (l + r) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    // Decide para qual lado ir
    if (idx <= mid)
    {
        update(left_child, l, mid, idx, val);
    }
    else
    {
        update(right_child, mid + 1, r, idx, val);
    }

    // Atualiza o nó atual com os novos valores
    seg[node] = seg[left_child] + seg[right_child];
}

// Consulta o intervalo [ql, qr]
int query(int node, int l, int r, int ql, int qr)
{
    // Caso 1: intervalo totalmente fora
    if (qr < l || ql > r)
    {
        return 0; // Elemento neutro da soma
    }

    // Caso 2: intervalo totalmente dentro
    if (ql <= l && r <= qr)
    {
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

// Inicializa a Segment Tree
void init_segment_tree(int size)
{
    n = size;
    seg.resize(4 * n);
    build(0, 0, n - 1);
}

// Interface para consulta
int range_query(int l, int r)
{
    return query(0, 0, n - 1, l, r);
}

// Interface para atualização
void point_update(int idx, int val)
{
    update(0, 0, n - 1, idx, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // variaveis
    string a;
    int n, b = 3, x;
    vector<int> input;

    // entrada
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        input.push_back(x);
    }
    
    // definindo a arvore
    arr = input;
    init_segment_tree(n);

    // loop
    while (cin >> a)
    {
        if (a == "a"){
            cin >> x;
            point_update(x - 1, 0);
        }
        else if(a == "?"){
            cin >> x;
            cout << range_query(0, x - 2) << endl;
        }else{
            break;
        }
    }

    return 0;
}