#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<vector<pair<int,int>>>graph;
const int INF = 1e9;

// Input Array
void inputArray() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    arr.resize(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array input successful!\n";
}

// Display Array
void displayArray() {
    if (arr.empty()) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

// Selection Sort
void selectionSort() {
    if (arr.empty()) {
        cout << "Array is empty. Input array first.\n";
        return;
    }

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }

    cout << "Array sorted using Selection Sort!\n";
    displayArray();
}

// Input Graph
void inputGraph() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    graph.assign(n + 1, {});

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});   // Undirected graph
    }

    cout << "Graph input successful!\n";
}

// Display Graph
void displayGraph() {
    if (graph.empty()) {
        cout << "Graph is empty.\n";
        return;
    }

    cout << "\nAdjacency List:\n";
    for (int i = 1; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto edge : graph[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << "\n";
    }
}

void dijkstra(int src) {
    if (graph.empty()) {
        cout << "Graph is empty. Input graph first.\n";
        return;
    }

    int n = graph.size();
    vector<int>dist(n+1, INF);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    dist[src] =0;
    pq.push({0,src});

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if(d > dist[u]) continue;

        for(auto edge : graph[u]){
            int v = edge.first;
            int w = edge.second;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    cout << "\nShortest Distances from " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }
}

void primMST(int src) {
    if (graph.empty()) {
        cout << "Graph is empty. Input graph first.\n";
        return;
    }

    int n = graph.size() - 1;

    vector<int> key(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    key[src] = 0;
    pq.push({0, src});

    int totalWeight = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int weight = top.first;
        int u = top.second;

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += weight;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i
                 << "  Weight = " << key[i] << "\n";
        }
    }

    cout << "\nTotal MST Weight = " << totalWeight << "\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Input Array\n";
        cout << "2. Display Array\n";
        cout << "3. Selection Sort\n";
        cout << "4. Input Graph\n";
        cout << "5. Display Graph\n";
        cout << "6. Dijkstra Shortest Path\n";
        cout << "7. Prim's Minimum Spanning Tree\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            inputArray();
        else if (choice == 2)
            displayArray();
        else if (choice == 3)
            selectionSort();
        else if (choice == 4)
            inputGraph();
        else if (choice == 5)
            displayGraph();
        else if (choice == 6) {
            int src;
            cout << "Enter source vertex: ";
            cin >> src;
            dijkstra(src);
        }
        else if (choice == 7) {
            int src;
            cout << "Enter starting vertex: ";
            cin >> src;
            primMST(src);
        }
        else if (choice == 8) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
