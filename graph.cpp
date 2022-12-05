# include <bits/stdc++.h>
using namespace std;

class Graph{
public:
	vector<vector<int>> graph;
	vector<vector<int>> MST;
	int *parent;
	Graph(int T)
	{
		this->parent = new int[T];
		for(int i=0;i<T;i++)
		{
			parent[i] = i;
		}

	}
	void add_edges_and_vertices(int w, int v, int u)
		{
			graph.push_back({w, v, w});
		}
	int find_set(int i)
	{
		if(parent[i] == i)
		{
			return i;
		}
		else
		{
			return find_set(parent[i]);
		}
	}
	void union_set(int u, int v)
	{
		parent[u] = parent[v];
	}

	void kruskal()
	{
		sort(graph.begin(), graph.end());
		for(int i=0;i<graph.size();i++)
		{
			int x = find_set(graph[i][1]);
			int y = find_set(graph[i][2]);
			if(x != y)
			{
				union_set(graph[i][1], graph[i][2]);
				MST.push_back(graph[i]);
			}

		}
	}
	void primsAlgo(vector<vector<int>> v, int sv )
	{
		vector<int> parent(v.size(), -1);
		vector<int> wt(v.size(), INT_MAX);
		vector<bool> visited(v.size(), false);	
		wt[0] = 0;
		for(int i=0;i<v.size()-1;i++)
		{
			int mini = INT_MAX;
			int u;
			for(int j=0;j<v.size();j++)
			{
				if(visited[j] == false && wt[j] < mini)
				{
					u = j;
					mini = wt[j];
				}

			}
			cout<<u<<endl;
			visited[u] = true;
			for(int k=0;k<v.size();k++)
			{
				if(v[u][k] != -1)
				{
					if(visited[k] == false)
					{
						if(v[u][k] < wt[k])
						{
							wt[k] = v[u][k];
							parent[k] = u;
						}
					}
				}
			}

		}
		for(int i=0;i<parent.size();i++)
		{
			cout<<parent[i]<<" ";
		}

	}
	void prims()
	{
		vector<vector<int>> v(4, vector<int>(4,-1));
		for(int i=0;i<5;i++)
		{
			int sv, ev;
			int data;
			cin>>sv>>ev;
			cout<<"Enter data::";
			cin>>data;

			v[sv][ev] = data;
			v[ev][sv] = data;
		}
		primsAlgo(v, 0);
	}

};


void DFS(vector<vector<int>> v, int sv, vector<bool> &visited)
{
	stack<int> s;
	s.push(sv);
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		for(int i=0;i<v.size();i++)
		{
			if(v[top][i] == 1 && !visited[i])
			{
				s.push(i);
			}

		}
		if(!visited[top])
		{
			cout<<top<<" ";
			visited[top] = true;
		}
	}
}

void BFS(vector<vector<int>> v, int sv, vector<bool> &visited)
{
	queue<int> q;
	q.push(sv);
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		for(int i=0;i<v.size();i++)
		{
			if(v[front][i] == 1 && !visited[i])
			{
				q.push(i);
			}
		}
		if(!visited[front])
		{
			cout<<front<<" ";
			visited[front] = true;
		}
	}
}

int main()
{
	// int vertices;
	// int edges;
	// cout<<"Enter the number of vertices in the graph::";
	// cin>>vertices;
	// cout<<"Enter the number of edges in the graph::";
	// cin>>edges;
	// vector<vector<int>>v(vertices, vector<int>(vertices, 0));
	// vector<bool> visited1(vertices, false);
	// vector<bool> visited2(vertices, false);
	// cout<<"Enter the edges::";
	// for(int i=0;i<edges;i++)
	// {
	// 	int sv, ev;
	// 	cin>>sv>>ev;
	// 	v[sv][ev] = 1;
	// 	v[ev][sv] = 1;

	// }
	// DFS(v, 0, visited1);
	// cout<<endl;
	// BFS(v, 0, visited2);
	Graph g(5);
	g.prims();



}