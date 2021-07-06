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

    void shortestPath(T src,T n)
    {
    	int dist[n+1];
    	for(auto node:adjList)
    	{
        dist[node.first]=INT_MAX;
    	}
    	dist[src]=0;
    	queue<int>q;
    	q.push(src);
    	while(!q.empty())
    	{
    		T node=q.front();
    		q.pop();

    		for(auto neighbour:adjList[node])
    		{
    			if(dist[neighbour]>dist[node]+1)
    			{
    				dist[neighbour]=1+dist[node];
    				q.push(neighbour);
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
      int u,v;
      cin>>u>>v;
      g.addEdge(u,v);
    }
     
    //print the graph
    //g.printGraph();
    cout<<endl;
    g.shortestPath(1,n);
    return 0;
}
