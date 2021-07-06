#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
  //create a map of key T type and val of list type 
    map<T,list<pair<T,T>>>adjList;

  public:

    //constructor
    Graph(){

    }

    //Add edge function 
    void addEdge(T u,T v,T w,bool bidir=false)
    {
        adjList[u].push_back({v,w});

        if(bidir)
        {
          adjList[v].push_back({u,w});
        } 
    }
    
    void topologicalSort(T src,int visited[],stack<int>&s)
    {
      visited[src]=1;
      for(auto neighbour:adjList[src])
      {
        if(!visited[neighbour.first])
          topologicalSort(neighbour.first,visited,s);
      }
      s.push(src);
    }
    void shortestPath(T src,T n)
    {
      int visited[n+1];
      memset(visited,0, sizeof(visited));
      stack<int>st;
      for(auto node:adjList)
      {
         if(!visited[node.first])
         {
            topologicalSort(node.first,visited,st);
         }
      }
      
      int dist[n+1];
      //int par[n+1];
      for(auto node:adjList)
      {
        dist[node.first]=INT_MAX;
        //par[node.first]=-1;
      }
      dist[src]=0;
      //par[src]=-1;
      while(!st.empty())
      {
        
        T node=st.top();
        st.pop();
        
        if(dist[node]!=INT_MAX)
        {
          for(auto neighbour:adjList[node])
          {
            if(dist[node]+neighbour.second<dist[neighbour.first])
            {
              dist[neighbour.first]=dist[node]+neighbour.second;
            }
          }
        }
      }
    	for(auto node:adjList)
    	{
    		cout<<src<<" to "<<node.first<<"::"<<dist[node.first]<<endl;
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
      int u,v,w;
      cin>>u>>v>>w;
      g.addEdge(u,v,w);
    }
     
    //print the graph
    //g.printGraph();
    cout<<endl;
    g.shortestPath(0,n);
    return 0;
}
