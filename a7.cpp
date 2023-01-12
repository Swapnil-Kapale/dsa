#include <iostream>
using namespace std;
const int MAX_VERTICES = 100;
// Graph class represents a directed graph
// using adjacency matrix representation
class Graph
{
   int numVertices;                                  // Number of vertices
   int adjMatrix[MAX_VERTICES][MAX_VERTICES];        //Adjacency matrix
    public : Graph(int numVertices); // Constructor
   void addEdge(int u, int v);                       // Function to add an edge to the graph 
   void BFS(int start);           // BFS function
   void DFS(int start);          // DFS function
};

// constructor defination
Graph::Graph(int numVertices)
{
   this->numVertices = numVertices;
   // Initialize the adjacency matrix
   for (int i = 0; i < numVertices; i++)
   {
      for (int j = 0; j < numVertices; j++)
      {
         adjMatrix[i][j] = 0;
      }
   }
}

void Graph::addEdge(int u, int v)
{
   adjMatrix[u][v] = 1;
   adjMatrix[v][u] = 1;
   // Add a edge from u to v
}

void Graph::BFS(int start)
{
   bool visited[MAX_VERTICES];
   for (int i = 0; i < numVertices; i++)
   {
      visited[i] = false;
   }
   int queue[MAX_VERTICES];
   int front = 0;
   int rear = 0;
   visited[start] = true;
   queue[rear] = start;
   rear++;
   while (front < rear)
   {
      int vertex = queue[front];
      std::cout << vertex << " ";
      front++;
      for (int i = 0; i < numVertices; i++)
      {
         if (adjMatrix[vertex][i] == 1 && !visited[i])
         {
            visited[i] = true;
            queue[rear] = i;
            rear++;
         }
      }
   }
}
void Graph::DFS(int start)
{
   bool visited[MAX_VERTICES];
   for (int i = 0; i < numVertices; i++)
   {

      visited[i] = false;
   }
   int stack[MAX_VERTICES];
   int top = -1;
   stack[++top] = start;
   while (top >= 0)
   {
      int vertex = stack[top--];
      if (!visited[vertex])
      {
         std::cout << vertex << " ";
         visited[vertex] = true;
      }
      for (int i = numVertices - 1; i >= 0; i--)
      {
         if (adjMatrix[vertex][i] == 1 && !visited[i])
         {
            stack[++top] = i;
         }
      }
   }
}
int main()
{
   int n = 0;
   cout << "How many vertices are in graph:";
   cin >> n;
   Graph g(n);
   int choice;
   do
   {
      cout << "\n1. Add an edge" << endl;
      cout << "2. DFS:" << endl;
      cout << "3. BFS:" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
      {
         int u, v;
         cout << "Enter the source vertex: ";
         cin >> u;
         cout << "Enter the destination vertex: ";
         cin >> v;
         g.addEdge(u, v);
         break;
      }
      case 2:
      {
         int u;
         cout << "Enter the source vertex(BFS): ";
         cin >> u;
         g.BFS(u);
         break;
      }
      case 3:
      {
         int u;
         cout << "Enter the source vertex(DFS): ";
         cin >> u;
         g.DFS(u);
         break;
      }
      default:
      {
         cout << "Invalid choice" << endl;
      }
      }
   } while (choice != 4);
   return 0;
}
