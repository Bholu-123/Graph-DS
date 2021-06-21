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

    //Detect cycle using BFS
    bool detectCycleBFS(T src,int visited[],T parent)
    {
      queue<pair<T,T>>q;
      visited[src]=1;
      q.push({src,-1});
      while(!q.empty())
      {
        T node=q.front().first;
        T par=q.front().second;
        q.pop();
        for(auto neighbour:adjList[node])
        {
          if(!visited[neighbour])
          {
            visited[neighbour]=1;
            //cout<<par<<neighbour<<node<<endl;
            q.push({neighbour,node});
          }
          else if(visited[neighbour] && par!=neighbour)
          {
            //cout<<"cycle is present"<<endl;
            //cout<<par<<neighbour<<node<<endl;
            return  true;
          }
        }
      }
        return false;
    }
    
    // create a bool type visited array to traverse every component
    void visited(int n)
    {
      int visited[n+1];
      memset(visited,0, sizeof(visited));
      for(int i=1;i<=n;i++)
      {
         if(!visited[i])
         {
            if(!detectCycleBFS(i,visited,-1))
            {
              cout<<"Graph is not cyclic";
              return;
            }
         }
      }
       cout<<"Graph is cyclic";
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
