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

    //Detect cycle in undirected Graph using DFS
    //call detectCycle pass src node,visited array and parent which is -1 for src node first mark the
    //src node visited and goes through the adjecency List of src node and check which neighbour which 
    //we haven't visited till now and fist visit those node and make the src to parent and if that node
    //is already vsited check whether that node is parent or not if that node is not parent return true.

    bool detectCycleDFS(T src,int visited[],T parent)
    {
      visited[src]=1;
      for(auto neighbour:adjList[src])
      {
        if(!visited[neighbour])
        {
          detectCycleDFS(neighbour,visited,src);
        }
        else if(neighbour!=parent)
        {
          return true;
        }
      }
      return false;
    }
    
    // create a bool type visited array to traverse every component
    void visited(int n)
    {
      int visited[n+1];
      memset(visited,0, sizeof(visited));
      for(auto i:adjList)
      {
         if(!visited[i.first])
         {
            if(detectCycleDFS(i.first,visited,-1))
            {
              cout<<"Graph is cyclic";
              return;
            }
         }
      }
       cout<<"Graph is not cyclic";
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
