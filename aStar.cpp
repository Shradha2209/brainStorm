#include<iostream>
#include <vector>
#include<queue>
#include <set>
#include<algorithm>

using namespace std;

struct Node{
    vector<vector<int>> board;
    int g , h;
};

int heuristic(vector<vector<int>> a, vector<vector<int>> goal){
    int cnt =0;
    for(int i =0; i<a.size(); i++){
        for(int j =0; j<a.size(); j++){
            if(a[i][j] != -1 && a[i][j] != goal[i][j]) cnt++;
        }
    }
    return cnt;
}
void print(vector<vector<int>>a){
    for(auto row : a){
        for(int x: row){
            cout<<(x== -1 ? 0:x)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

struct cmp{
    bool operator()(Node a, Node b){
        return a.g + a.h > b.g + b.h;
    }
};

void astar(vector<vector<int>>start , vector<vector<int>>goal){
    priority_queue<Node, vector<Node>,cmp>pq;
    set<vector<vector<int>>>vis;

    pq.push({start , 0, heuristic(start,goal)});

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();

        if(vis.count(cur.board)) continue;
        vis.insert(cur.board);
        print(cur.board);
        cout<<"g= " << cur.g <<"h= "<<cur.h <<"f= " <<cur.g+cur.h<<"\n\n";

        if(cur.board == goal){
            cout << "Goal Reached!\n";
            return;
        }

        int x,y;
        for(int i =0; i<cur.board.size(); i++){
            for(int j =0; j<cur.board.size(); j++){
                if(cur.board[i][j] == -1) {
                    x=i;
                    y=j;
                }
            }
        }
        for(int k =0; k<4; k++){
            int nx = x+ dx[k];
            int ny = y + dy[k];

            if(nx >=0 && nx < cur.board.size() && ny>=0 && ny < cur.board.size()){
                auto next = cur.board;
                swap(next[x][y] , next[nx][ny]);

                if(!vis.count(next)){
                    pq.push({next,cur.g+1,heuristic(next,goal)});

                }
            }
        }
    }
     cout << "No Solution Found\n";
}
int main(){
     int n;
    cout << "Enter size of puzzle: ";
    cin >> n;

    vector<vector<int>> start(n, vector<int>(n));
    vector<vector<int>> goal(n, vector<int>(n));

    cout << "Enter initial state (-1 for blank):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> start[i][j];

    cout << "Enter goal state (-1 for blank):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> goal[i][j];

    astar(start, goal);
}
