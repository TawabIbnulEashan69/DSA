#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nodes, edges;

    cout << "Enter the number of nodes: ";
    cin >> nodes;

    if (nodes <= 0) {
        cout << "Error: Number of nodes must be positive!" << endl;
        return 1;
    }

    vector<vector<int>> graph(nodes);

    cout << "Enter the number of edges ->  ";
    cin >> edges;

    if (edges < 0) {
        cout << "Error: Number of edges cannot be negative!" << endl;
        return 1;
    }

    cout << "Enter edges node -> 1 and 2:" << endl;
    for (int i = 0; i < edges; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        if (n1 < 0 || n1 >= nodes || n2 < 0 || n2 >= nodes) {
            cout << "Error: Invalid node index! Must be between 0 and " << nodes - 1 << endl;
            continue;
        }

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    cout << "Adjacency List Representation:"<<endl;
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
