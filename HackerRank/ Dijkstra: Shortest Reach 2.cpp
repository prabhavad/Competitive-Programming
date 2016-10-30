#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#define IPAIR std::pair <long int,long int>
#define INFINITE LONG_MAX
using namespace std;



class Graph
{
	long long int NoOfVertex;
	std::list < pair <long int,long int> > *AdjList;


	public:

		Graph(long long int V)
		{
			this->NoOfVertex = V;
			AdjList = new std::list < IPAIR > [V];
		}

		void AddEdge(long long int From,long long int To,long long int Weight)
		{
			AdjList[From].push_back(make_pair(To,Weight));
			AdjList[To].push_back(make_pair(From,Weight));
		}


		void Dijkstra(long long int sourceVertex)
		{
			std::priority_queue <IPAIR, vector <IPAIR> , greater<IPAIR> > PQ;
			std::vector <long long int> Distance(NoOfVertex,INFINITE);

			std::vector <bool> Done1(NoOfVertex,false);


			PQ.push(make_pair(0,sourceVertex));

			Distance[sourceVertex] = 0;


			while (!PQ.empty())
			{
				long long int u = PQ.top().second;
				PQ.pop();

				if (!Done1[u])
				{
					Done1[u] = true;
				}
				else
				{
					continue;
				}



				for (std::list <IPAIR>::iterator i = AdjList[u].begin(); i != AdjList[u].end(); i++)
				{
					long long int v = (*i).first;
					long long int Weight = (*i).second;

					if (Distance[v] > Distance[u] + Weight)
					{
						Distance[v] = Distance[u] + Weight;
						PQ.push(make_pair(Distance[v],v));
					}
				}

			}

			for (long long int j = 1;  j< NoOfVertex; j++)
			{
				if (j != sourceVertex)
				{
					if (Distance[j] == INFINITE)
					{
						cout<<"-1"<<" ";
					}
					else
					{
						cout<<Distance[j]<<" ";
					}
				}
			}
			cout<<endl;
		}

		
};



int main()
{
	long long int T,N,M,x,y,r,S;

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;

	for (long long int i = 0; i < T; i++)
	{
		cin>>N>>M;

		Graph G(N + 1);

		for (long long int j = 0; j < M; j++)
		{
			cin>>x>>y>>r;
			
				G.AddEdge(x,y,r);
			
		}

		cin>>S;

		G.Dijkstra(S);
	}
	return 0;
}
