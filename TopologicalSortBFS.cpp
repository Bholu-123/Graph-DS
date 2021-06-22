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

    //Topological Sort helper
    void topologicalSortBFS_helper(int indegree[],int n)
    {
      queue<int>q;
      for(int i=0;i<n;i++)
      {
        if(indegree[i]==0)
        {
          q.push(i);
        }
      }
      while(!q.empty())
      {
        T node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto neighbour:adjList[node])
        {
          indegree[neighbour]--;

           if(indegree[neighbour]==0)
           {
             q.push(neighbour);
           }
        }
      }
    }
   //Topological Sort BFS
    void topologicalSortBFS(int n)
    {
      int indegree[n]={0};
      for(int i=0;i<n;i++)
      {
         for(auto j:adjList[i])
         {
           indegree[j]++;
         }
      }

      topologicalSortBFS_helper(indegree,n);
    }

    // void printGraph()
    // {
    //    //Iterate over the map
    //    for(auto i:adjList)
    //    {
    //      cout<<i.first<<"-->";

    //      //Iterate over the neighbour of node i.e i.second which iS ll
    //      for(auto neighbour:i.second)
    //      {
    //         cout<<neighbour<<",";
    //      }
    //      cout<<endl; 
    //    }
    // }
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
    //g.topologicalSortDFS(n);
      g.topologicalSortBFS(n);
    return 0;
}
