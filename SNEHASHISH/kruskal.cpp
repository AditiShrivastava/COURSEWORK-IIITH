#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> parent;
vector<int> ranks;

int swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void make_set(int v) {
    parent[v] = v;
    ranks[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() {

    int n,e;
    
    cout << "Enter no of vertices ";
    cin >> n;

    cout << "Enter no of edges ";
    cin >> e;
    vector<Edge> edges;

    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    ranks.resize(n);
    edges.resize(e);

    cout << "Enter each edge as vertex-1 vertex-2 weight (Vertex no starts from 0)\n";
    for(int i = 0; i < e; i++ ){

        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    }

    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    cout << "Cost of MST " << cost;
}