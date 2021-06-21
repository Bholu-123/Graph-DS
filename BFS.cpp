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

    //BFS traversal
    /*First we create a visited array which will take care which node has been
     till now and pass the src node and visited array to bfs fns in bfs fns 
     we create a queue first push the src node in the queue also mark it visited 
     and then access the front node of queue print it pop this node from queue 
     and traverse all the neighbours of front node by the help of adjList and push 
     all the neighbours in the queue which is not visited till now and also mark that 
     neighbours visited and repeat this process till q is not empty*/
    void BFS(T src,int visited[])
    {
      //Create a queue
       queue<T>q;

      //Push src node in queue
       q.push(src);

      //mark the visited of src 
       visited[src]=1;
       
       while(!q.empty())
       {
          T node=q.front();
          cout<<node<<" ";
          q.pop();
          for(auto neighbour:adjList[node])
          {
            if(!visited[neighbour])
            {
              q.push(neighbour);
              visited[neighbour]=1;
            }
          }
       }
    }

    void visited(int n)
    {
      int visited[n+1];
      memset(visited,0, sizeof(visited));
      for(int i=1;i<=n;i++)
      {
         if(!visited[i])
         {
            BFS(i,visited);
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
