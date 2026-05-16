#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ComputerNetwork{
    private:
    vector<vector<int>> network;
    int size;

    void dfsutil(int node, vector<bool>vis){
        vis[node] = true;
        cout<<node<<" ";
        for(int neighbour : network[node]){
            if(!vis[neighbour]){
                dfsutil(neighbour,vis);
            }
        }
    }

    void bfsutil(queue<int>q, vector<bool>vis , int level){
        if(q.empty()) return;
        int sz = q.size();
        cout<<"Hop"<<level<<":";
        while(sz--){
            int node = q.front();
            q.pop();

            cout<<node<<" ";
            for(int neighbour:network[node]){
                if(!vis[neighbour]){
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        cout<<endl;
        bfsutil(q,vis,level+1);
    }

    public:
    ComputerNetwork(int n ){
        size = n ;
        network.resize(n+1);
    }

    void addConnection(int u , int v){
        network[u].push_back(v);
        network[v].push_back(u);
    }

    void display(){
        for(int i = 1; i<=size; i++){
            cout << "Computer " << i << " connected to: ";
            for(int x: network[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void dfs(int start){
        vector<bool>vis(size+1, false);
         cout << "DFS Network Traversal from Computer " << start << ": ";
         if(start >= 1 && start <= size) dfsutil(start,vis);
         cout<<endl;
    }

    void bfs(int start){
        vector<bool>vis(size+1,false);
        queue<int>q;

        cout << "BFS (Shortest Hop Routing) from Computer " << start << ":\n";
        if(start < 1 || start > size)return;

        vis[start] = true;
        q.push(start);
        bfsutil(q,vis,0);
    }

};

int main(){
     int n, choice, u, v, start;

    cout << "Enter number of computers in the network: ";
    cin >> n;

    ComputerNetwork cn(n);

      do {
        cout << "\n--- Network Menu ---\n";
        cout << "1. Add connection\n";
        cout << "2. Display network\n";
        cout << "3. DFS (Network Exploration)\n";
        cout << "4. BFS (Shortest Hop Routing)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
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
                cout << "Enter starting computer: ";
                cin >> start;
                cn.dfs(start);
                break;

            case 4:
                cout << "Enter starting computer: ";
                cin >> start;
                cn.bfs(start);
                break;

            case 5:
                cout << "Exiting network simulation...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
