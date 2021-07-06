#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
  //create a map of key T type and val of list type 
    map<T,list<T>>adjList;

  public:

    //constructor
    Graph(){

    }

    //Add edge function 
    void addEdge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);

        if(bidir)
        {
          adjList[v].push_back(u);
        } 
    }
     //DFS traversal
    void DFS(T src,int visited[])
    {
      visited[src]=1;
      cout<<src<<" ";
      for(auto neighbour:adjList[src])
      {
         if(!visited[neighbour])
          {
            DFS(neighbour,visited);
          }
      }
    }
     //check which node is visited or not
    void visited(int n)
    {
      int visited[n+1];
      memset(visited,0, sizeof(visited));
      //iterate over map and check which is visited or not
      
      for(auto i:adjList)
      {
         if(!visited[i.first])
         {
            DFS(i.first,visited);
         }
      }
    }
};
 
int main()
{
  #ifndef ONLINE_JUDGE 
     freopen("input.txt", "r", stdin); 
     freopen("output.txt", "w", stdout); 
  #endif

  Graph<int>g;
  
    int n;//no of vertices
    cin>>n;
    int m;//no of edges
    cin>>m;

    //create edge between u and v
    for(int i=0;i<m;i++)
    {
      int u,v;
      cin>>u>>v;
      g.addEdge(u,v);
    }
     
    //print the graph
    //g.printGraph();
    cout<<endl;
    g.visited(n);
    return 0;
}
