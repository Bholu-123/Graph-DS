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

    //DFS Bipartite
    bool isBipartiteDFS(T src,int color[])
    {
      if(color[src]==-1)
      {
        color[src]=1;
      }
      for(auto neighbour:adjList[src])
      {
        if(color[neighbour]==-1)
        {
          color[neighbour]=1-color[src];
          if(!isBipartiteDFS(neighbour,color))
          {
            return false;
          }
        }
        else if(color[neighbour]==color[src])
            return false;
      }
      return true;
    }

    //Check whether the graph is bipartite or not
    void isBipartite(int n)
    { 
       int color[n+1];
       memset(color,-1, sizeof(color));
       for(auto i:adjList)
       {
         if(color[i.first]==-1)
         {
            if(!isBipartiteDFS(i.first,color))
            {
              cout<<"Graph is not Bipartite"<<endl;
              return;
            }
         }
       }
        
        cout<<"Graph is Bipartite"<<endl;
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
    g.isBipartite(n);
    return 0;
}
