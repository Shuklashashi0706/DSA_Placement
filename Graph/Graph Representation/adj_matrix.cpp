#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // // undirected unweighted graph
  // int vertex, edges;
  // cin>>vertex>>edges;
  // vector<vector<int>> graph(vertex, vector<int>(vertex, 0));
  // int u, v;
  // for (int i = 0; i < edges; i++)
  // {
  //   cin >> u >> v;
  //   graph[u][v] = 1;
  //   graph[v][u] = 1;
  // }
  // for (int i = 0; i < vertex; i++)
  // {
  //   for (int j = 0; j < vertex; j++)
  //   {
  //     cout << graph[i][j] << "\t";
  //   }
  //   cout << endl;
  // }

   // directed unweighted graph
  int vertex, edges;
  cin>>vertex>>edges;
  vector<vector<int>> graph(vertex, vector<int>(vertex, 0));
  int u,v;
  for (int i = 0; i < edges; i++)
  {
    cin >> u >> v;
    graph[u][v] = 1;
  }
  for (int i = 0; i < vertex; i++)
  {
    for (int j = 0; j < vertex; j++)
    {
      cout << graph[i][j] << "\t";
    }
    cout << endl;
  }


  return 0;
}