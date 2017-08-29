#pragma once
#ifndef _MAXBD_H
#define _MAXBD_H
#include "generateGraph.h"
#include <vector>


enum Status 
{
	unseen, fringe, intree
};
class MaxBD
{
public:
	int min(int a, int b)
	{
		return a <= b ? a : b;
	}
	/*Dijkstra for adlist*/
	vector<int> Dijkstra(ALGraph G, int s, int t)
	{
		
		Status status[vn];
		int Dad[vn],w;
		int bw[vn];
		for (int i = 0; i < vn; i++)
		{
			status[i] = unseen;
		}
		
		status[s] = intree;
		Dad[s] = -1;
		bw[s] = INT_MAX;
		
		ArcNode *p;
		vector<int> storefringe;
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p = G.vertices[s].firstarc;
		while (p != NULL)
		{
			w = p->adjvex;
			status[w] = fringe;
			storefringe.push_back(w);
			Dad[w] = s;
			bw[w] = p->weight;
			p = p->next;
		}
		
		while (storefringe.size() != 0)
		{
			int max=0,v,vindex;
			for (int i = 0; i < storefringe.size(); i++)
			{
				if (max < bw[storefringe[i]])
				{
					max = bw[storefringe[i]];
					v = storefringe[i];
					vindex = i;
				}
			}

			status[v] = intree;
			storefringe[vindex] = storefringe[storefringe.size()-1];
			storefringe.pop_back();

			ArcNode *q;
			q = (ArcNode *)malloc(sizeof(ArcNode));
			q = G.vertices[v].firstarc;
			while (q != NULL)
			{
				w = q->adjvex;
				if (status[w] == unseen)
				{
					status[w] = fringe;
					storefringe.push_back(w);
					Dad[w] = v;
					bw[w] = min(bw[v], q->weight);
				}
				else if (status[w] == fringe && bw[w] < min(bw[v],q->weight))
				{
					Dad[w] = v;
					bw[w] = min(bw[v], q->weight);
				}
				q = q->next;
			}
		}
		vector<int> result;
		for (int i = 0; i < vn; i++)
		{
			result.push_back(Dad[i]);
		}
		return result;
	}
	/*Dijkstra for admatrix*/
	vector<int> DijkstraM(int matrix[vn][vn], int s, int t)
	{
		
		Status status[vn];
		int Dad[vn], w;
		int bw[vn];
		for (int i = 0; i < vn; i++)
		{
			status[i] = unseen;
		}
		
		status[s] = intree;
		Dad[s] = -1;
		bw[s] = INT_MAX;
		
		for (int i = 0; i < vn; i++)
		{
			if (matrix[s][i] != 0 && matrix[s][i] != INT_MAX)
			{
				status[i] = fringe;
				Dad[i] = s;
				bw[i] = matrix[s][i];
			}
		}
		vector<int> storefringe;
		for (int i = 0; i < vn; i++)
		{
			if (status[i] == fringe)
				storefringe.push_back(i);
		}
		while (storefringe.size() != 0)
		{
			int max = 0, v = storefringe[0], vindex = 0;
			for (int i = 0; i < storefringe.size(); i++)
			{
				if (max < bw[storefringe[i]]&& bw[storefringe[i]]!=INT_MAX)
				{
					max = bw[storefringe[i]];
					v = storefringe[i];
					vindex = i;
				}
			}
			status[v] = intree;
			storefringe[vindex] = storefringe[storefringe.size() - 1];
			storefringe.pop_back();

			for (int j = 0; j < vn; j++)
			{
				if (matrix[v][j] != 0 && matrix[v][j] != INT_MAX)
				{
					w = j;
					if (status[w] == unseen)
					{
						status[w] = fringe;
						storefringe.push_back(w);
						Dad[w] = v;
						bw[w] = min(bw[v], matrix[v][w]);
					}
					else if (status[w] == fringe&&bw[w] < min(bw[v], matrix[v][w]))
					{
						Dad[w] = v;
						bw[w] = min(bw[v], matrix[v][w]);
					}
				}
			}

		}
		vector<int> result;
		for (int i = 0; i < vn; i++)
		{
			result.push_back(Dad[i]);
		}
		return result;
	}
};

#endif