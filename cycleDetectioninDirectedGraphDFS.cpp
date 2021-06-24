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
    void addEdge(T u,T v,bool bidir=false)
    {
      adjList[u].push_back(v);

      if(bidir)
      {
        adjList[v].push_back(u);
      } 
    }
     
     void printGraph()
     {
       //Iterate over the map
       for(auto i:adjList)
       {
         cout<<i.first<<"-->";

         //Iterate over the neighbour of node i.e i.second which iS ll
         for(auto neighbour:i.second)
         {
            cout<<neighbour<<",";
         }
         cout<<endl; 
       }
     }

     bool isCycle(T src,int visited[],int dfsVis[])
     {
       visited[src]=1;
       dfsVis[src]=1;
       for(auto neighbour:adjList[src])
       {
         if(!visited[neighbour])
         {
           isCycle(neighbour,visited,dfsVis);
         }
         else if(visited[neighbour] && dfsVis[neighbour])
         {
           return true;
         }
       }
        dfsVis[src]=0;
        return false;
     }
    
    // create a bool type visited array to traverse every component
    bool detectCycle(int n)
    {
      int visited[n+1];
      int dfsVis[n+1];
      memset(visited,0, sizeof(visited));
      memset(dfsVis,0, sizeof(dfsVis));
      for(auto i:adjList)
      {
         if(!visited[i.first])
         {
            if(isCycle(i.first,visited,dfsVis))
            {
              return true;
            }
         }
      }
       return false;
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
    for(int i=1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      g.addEdge(u,v);
    }
     
    //print the graph
    g.printGraph();
    cout<<endl;
    cout<<g.detectCycle(n);
    return 0;
}
