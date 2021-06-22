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

    //Topological sort DFS helper
    void topologicalSortDFS_helper(T src,int visited[],stack<int>&s)
    {
      visited[src]=1;
      for(auto neighbour:adjList[src])
      {
        if(!visited[neighbour])
          topologicalSortDFS_helper(neighbour,visited,s);
      }
      s.push(src);
    }

    //TOpological sort DFS 
    void topologicalSortDFS(int n)
    {
      int visited[n];
      memset(visited,0, sizeof(visited));
      stack<int>st;
      for(int i=0;i<n;i++)
      {
         if(!visited[i])
         {
            topologicalSortDFS_helper(i,visited,st);
         }
      }
      while(!st.empty())
      {
         cout<<st.top()<<" ";
         st.pop();
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
      g.topologicalSortDFS(n);
    return 0;
}
