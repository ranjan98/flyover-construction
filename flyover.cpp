#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//We are constructing a graph having n number of nodes
//The weights will be having density and length of the flyover

struct link
{
	int to;
	int length;
	int density;
};
class graph
{
	// for vertices lets take int V
	int V;
	//make a pointer which will point to the adjacency list
	vector<link> *adj;
	public:
		graph()
		{
			cout<<"created";
		}
		graph(int V)
		{
			this->V = V;
			adj = new vector<link>[V];
		}
		void addEdge(int v, int w, int density,int length)
		{
			link q,r;
			q.to=w;
			q.density=density;
			q.length=length;
			r.to=v;
			r.density=density;
			r.length=length;
			adj[v].push_back(q); 
			adj[w].push_back(r); //Add w to v list as the graph is undirected
		}
	void check()
		{
			for(int i=0;i<V;i++)
			{
				cout<<"for "<<i<<":";
				for(vector<link>::iterator it=adj[i].begin();it!=adj[i].end();it++)
					cout<<it->to<<"\t";
			}
		}
		void ranjan(int t,int l); // starting node is passed to the function
};
vector<int> visited;
// Our algorithm gives densest path
void graph::ranjan(int t,int l)
{	

	int i=0,k=0,pos=0;
	visited.push_back(t);
	vector<link> temp;
	link tl;
	tl.density=-1;
	tl.length=10;
	tl.to=-1;
	temp.push_back(tl);
	vector<link>::iterator mi=temp.begin(),it=adj[t].begin();
	for(;it!=adj[t].end();it++)
		if(it->density>mi->density&&it->length<=l&&find(visited.begin(),visited.end(),it->to)==visited.end())
			mi=it;
	if(mi==temp.begin())
		return;
	else
	{
		cout<<"Next Node:"<<mi->to<<"\n";
		ranjan(mi->to,l-mi->length);
	}
}
int main()
{
	int n,i,l,v,w,density,length,start,nodes=0;
	cout<<"Welcome to the Traffic Density Problem\n";
	//cout<<"Enter number of nodes: ";
	//cin>>nodes;
	graph g(8);
	//cout<<"Enter number of edges: ";
	//cin>>n;
	/*for(i=0;i<n;i++)
	{
		cout<<"Enter an edge: ";
		cin>>v>>w;
		cout<<"Enter density: ";
		cin>>density;
		cout<<"Enter length: ";
		cin>>length;
		g.addEdge(v,w,density,length);
	}*/
	g.addEdge(0,1,13,3);
	g.addEdge(1,2,20,8);
	g.addEdge(1,3,10,5);
	g.addEdge(0,4,17,9);
	g.addEdge(3,4,12,6);
	g.addEdge(2,3,7,4);
	g.addEdge(2,5,11,7);
	g.addEdge(3,5,9,2);
	g.addEdge(5,6,7,1);
	g.addEdge(6,7,4,3);
	//g.check();
	cout<<"\nEnter the starting node: ";
	cin>>start;
	cout<<"Enter L: ";
	cin>>l;
	cout<<"The Flyover will be constructed as the follows:\n";
	cout<<"Starting Node: "<<start<<"\n";
	g.ranjan(start,l);
}
