//
// Created by Antoni Dobrenov on 30.06.23.
//

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

struct Edge {
    int v1;
    int v2;
    int weight;

    Edge(int v1, int v2) : v1(v1), v2(v2), weight(0) {}
    Edge(int v1, int v2, int weight) : v1(v1), v2(v2), weight(weight) {}
};

class Graph {
private:
    int numOfVertices;
    std::vector<std::vector<int> > adjList;
    std::vector<Edge> edges;

public:
    Graph(int &numOfVertices) : numOfVertices(numOfVertices) {
        adjList = std::vector<std::vector<int> >(numOfVertices);
    }

    bool addEdge(int from, int to) {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].v1 == from && edges[i].v2 == to) {
                return false;
            }
        }
        edges.push_back(Edge(from, to));
        adjList[from].push_back(to);
        adjList[to].push_back(from);
        return true;
    }

    bool addEdge(int from, int to, int weight) {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].v1 == from && edges[i].v2 == to) {
                return false;
            }
        }
        edges.push_back(Edge(from, to, weight));
        adjList[from].push_back(to);
        adjList[to].push_back(from);
        return true;
    }

    void print() {
        for (int i = 0; i < numOfVertices; i++) {
            std::cout << "Съседи на връх " << i << ":" << std::endl;
            for (int j = 0; j < adjList[i].size(); j++) {
                std::cout << adjList[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<int> hasPath(int from, int to) {
        std::vector<bool> visited(numOfVertices);
        std::vector<int> path;
        std::cout << dfs(from, to, visited, path);
        return path;
    }

private:

    bool dfs(int from, int to, std::vector<bool>& visited, std::vector<int>& path) {
        visited[from] = true;
        path.push_back(from);
        if (from == to) {
            return true;
        }

        for (int i = 0 ; i < adjList[from].size(); i ++) {
            int neighbor = adjList[from][i];
            if (!visited[neighbor]) {
                if (dfs(neighbor, to, visited, path)) {
                    return true;
                }
            }
        }
        path.pop_back();
        return false;
    }

};


int main() {
    int numOfV = 5;
    Graph graph = Graph(numOfV);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 1);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);

//    graph.print();

    std::vector<int> a = graph.hasPath(2, 4);
    for (int i = 0; i < a.size(); i ++){
        if (i == a.size() - 1) {
            std::cout << a[i];
        } else {
            std::cout << a[i] << " -> ";
        }
    }
    return 0;
}