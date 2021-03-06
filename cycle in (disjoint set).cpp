// To find cycle in undirected graph using disjoint set....

#include<bits/stdc++.h>
using namespace std;

vector<int> parent; // to store parent of a vertex;

//to find the parent of an vertex
int find(int v)
{
	if(parent[v]==-1) // that vertex itself is a parent node
		return v;
	return find(parent[v]);
}

void union_op(int u,int v) 
{
	u = find(u);
	v = find(v);
	parent[u] = v;
}

bool isCyclic(vector<pair<int,int>>& edge)
{
	for(auto i: edge)
	{
		int u = find(i.first);	//FIND absolute parent of subset
		int v = find(i.second);

		if(u == v)
			return true;

		//UNION operation
		union_op(u,v);	//UNION of 2 sets
	}
	return false;
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	parent.resize(V,-1);	//Mark all vertices as separate subsets with only 1 element
	vector<pair<int,int>> e;	//to store edges of graph
	for(int i=0;i<E;++i)
	{
		int u,v;
		cin>>u>>v;
		e.push_back({u,v});
	}

	if(isCyclic(e))// function to check for cycle
		cout<<"cycle exist in undirected graph\n";
	else
		cout<<"not exist\n";
	
	return 0;
}

//TIME COMPLEXITY: O(E.V)