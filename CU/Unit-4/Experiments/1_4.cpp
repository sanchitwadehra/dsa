#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

std::vector<int> parent, rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
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
        if (rank[a] < rank[b])
            std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int n;
    std::cout << "Enter the no. of vertices:\n";
    std::cin >> n;
    parent.resize(n);
    rank.resize(n);
    std::vector<Edge> edges;

    // Call make_set for each vertex
    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    std::cout << "\nEnter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            std::cin >> cost;
            if (cost != 0) { // Only add an edge if there is a direct connection
                edges.push_back({i, j, cost});
            }
        }
    }

    int cost = 0;
    std::vector<Edge> result;
    std::sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    std::cout << "The edges of Minimum Cost Spanning Tree are\n";
    for (Edge e : result) {
        std::cout << e.u << " " << e.v << " " << e.weight << "\n";
    }
    std::cout << "\nMinimum cost = " << cost << "\n";

    return 0;
}
