#include <stdio.h>

#define MAXN 200005
#define INF 1000000007

int efficiency[MAXN];
long long tree[4 * MAXN];

void build_tree(int node, int start, int end) {
    if (start == end) {
        tree[node] = efficiency[start];
        return;
    }

    int mid = (start + end) / 2;
    build_tree(2 * node, start, mid);
    build_tree(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update_tree(int node, int start, int end, int idx, int val) {
    if (start == end) {
        efficiency[idx] = val;
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid)
        update_tree(2 * node, start, mid, idx, val);
    else
        update_tree(2 * node + 1, mid + 1, end, idx, val);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long query_tree(int node, int start, int end, int l, int r) {
    if (r < start || l > end)
        return 0;

    if (l <= start && r >= end)
        return tree[node];

    int mid = (start + end) / 2;
    long long p1 = query_tree(2 * node, start, mid, l, r);
    long long p2 = query_tree(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &efficiency[i]);
    }

    build_tree(1, 1, N);

    while (M--) {
        int type, a, b;
        scanf("%d %d %d", &type, &a, &b);

        if (type == 1) {
            update_tree(1, 1, N, a, b);
        } else {
            printf("%lld\n", query_tree(1, 1, N, a, b));
        }
    }

    return 0;
}
