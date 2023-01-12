#include <iostream>
#include <climits> //for infinite distance INT_MAx
using namespace std;
const int MAX_VERTICES = 100;
class Graph
{
public:
    int numVertices;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int V;
    Graph(int numVertices);
    void addEdge(int u, int v, int weight);
    void PrimMST();
    int minKey(int key[], bool mstSet[]);
    void printMST(int parent[]);
    void primMST();
};
Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    this->V = numVertices;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }
}
void Graph::addEdge(int u, int v, int weight)
{
    graph[u][v] = weight;
    graph[v][u] = weight;
}
int Graph::minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void Graph::printMST(int parent[])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t "<< graph[i][parent[i]] << "\n ";
}
void Graph::primMST()
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] =
                                   graph[u][v];
    }
    printMST(parent);
}
int main()
{
    int n;
    cout << "How many vertices are in graph:";
    cin >> n;
    Graph g(n);
    int choice;
    do
    {
        cout << "\n1. Add an edge" << endl;
        cout << "2. MST:" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int u, v, w;
            cout << "Enter the source vertex: ";
            cin >> u;
            cout << "Enter the destination vertex: ";
            cin >> v;
            cout << "Enter Weight:";
            cin >> w;
            g.addEdge(u, v, w);
            break;
        }
        case 2:
        {
            g.primMST();
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } while (choice != 3);
    return 0;
}
