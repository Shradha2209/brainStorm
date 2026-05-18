#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ComputerNetwork {
private:
    vector<vector<int>> network;
    int size;

    // DFS Utility Function
    void dfsutil(int node, vector<bool>& vis) {
        vis[node] = true;
        cout << node << " ";

        for (int neighbour : network[node]) {
            if (!vis[neighbour]) {
                dfsutil(neighbour, vis);
            }
        }
    }

    // BFS Utility Function
    void bfsutil(queue<int>& q, vector<bool>& vis, int level) {
        if (q.empty())
            return;

        int sz = q.size();

        cout << "Hop " << level << ": ";

        while (sz--) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbour : network[node]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << endl;

        bfsutil(q, vis, level + 1);
    }

public:
    // Constructor
    ComputerNetwork(int n) {
        size = n;
        network.resize(n + 1);
    }

    // Add connection between computers
    void addConnection(int u, int v) {

        // Validation
        if (u < 1 || v < 1 || u > size || v > size) {
            cout << "Invalid computer number!" << endl;
            return;
        }

        network[u].push_back(v);
        network[v].push_back(u);

        cout << "Connection added between "
             << u << " and " << v << endl;
    }

    // Display Network
    void display() {

        cout << "\n----- Network Connections -----\n";

        for (int i = 1; i <= size; i++) {

            cout << "Computer " << i << " connected to: ";

            if (network[i].empty()) {
                cout << "No connections";
            }
            else {
                for (int x : network[i]) {
                    cout << x << " ";
                }
            }

            cout << endl;
        }

        cout << endl;
    }

    // DFS Traversal
    void dfs(int start) {

        if (start < 1 || start > size) {
            cout << "Invalid starting computer!" << endl;
            return;
        }

        vector<bool> vis(size + 1, false);

        cout << "\nDFS Traversal from Computer "
             << start << ": ";

        dfsutil(start, vis);

        cout << endl;
    }

    // BFS Traversal
    void bfs(int start) {

        if (start < 1 || start > size) {
            cout << "Invalid starting computer!" << endl;
            return;
        }

        vector<bool> vis(size + 1, false);
        queue<int> q;

        vis[start] = true;
        q.push(start);

        cout << "\nBFS Traversal from Computer "
             << start << ":\n";

        bfsutil(q, vis, 0);
    }
};

int main() {

    int n, choice;
    int u, v, start;

    cout << "Enter number of computers in the network: ";
    cin >> n;

    ComputerNetwork cn(n);

    do {

        cout << "\n========== NETWORK MENU ==========\n";
        cout << "1. Add Connection\n";
        cout << "2. Display Network\n";
        cout << "3. DFS Traversal\n";
        cout << "4. BFS Traversal\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter two computers to connect: ";
            cin >> u >> v;

            cn.addConnection(u, v);

            break;

        case 2:

            cn.display();

            break;

        case 3:

            cout << "Enter starting computer for DFS: ";
            cin >> start;

            cn.dfs(start);

            break;

        case 4:

            cout << "Enter starting computer for BFS: ";
            cin >> start;

            cn.bfs(start);

            break;

        case 5:

            cout << "\nExiting Network Simulation...\n";

            break;

        default:

            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
