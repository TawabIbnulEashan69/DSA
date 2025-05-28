#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout<<"Enter the number of Nodes: ";
    int nodes;
    cin >> nodes;

    if (nodes <= 0) {
        cout << "Error: Number of nodes must be positive!" << endl;
        return 1;
    }

    int graph[nodes][nodes];

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            graph[i][j] = (i == j) ? 0 : -1;

    cout<<"Enter the number of edges ->  ";
    int edges;
    cin >> edges;

    if (edges < 0) {
        cout << "Error: Number of edges cannot be negative!" << endl;
        return 1;
    }

    for (int i = 0; i < edges; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        if (n1 < 0 || n1 >= nodes || n2 < 0 || n2 >= nodes) {
            cout << "Error: Invalid node index! Must be between 0 and " << nodes - 1 << endl;
            continue;
        }

        graph[n1][n2] = 1;
        graph[n2][n1] = 1;
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int start = 0;
    int visited[nodes] = {0};
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    cout << "\nBFS Traversal:\n";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < nodes; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
