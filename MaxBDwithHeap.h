#pragma once
#ifndef _MaxBDwithHeap_H
#define _MaxBDwithHeap_H

#include "heapsort.h"
#include "generateGraph.h"
#include <vector>


class HeapBD
{
	friend class Heap;
	Heap hp;
public:
	int min(int a, int b)
	{
		return a <= b ? a : b;
	}
	/*Dijkstra for adlist*/
	vector<int> DijkstraHeap(ALGraph G, int s, int t)
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
		
		ArcNode *p;
		int H[vn];
		int D[vn + 1], index = 0;
		D[0] = -1;
		for (int i = 0; i < vn; i++)
		{
			H[i] = 0;
			D[i + 1] = -1;
		}
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p = G.vertices[s].firstarc;
		while (p != NULL)
		{
			w = p->adjvex;
			status[w] = fringe;
			Dad[w] = s;
			bw[w] = p->weight;
			p = p->next;
		}
		
		for (int i = 0; i < vn; i++)
		{
			if (status[i] == fringe)
			{
				H[i] = bw[i];
				D[1+index++] = i;
			}
		}
		
		while (index!= 0)
		{
			int v = hp.MaxHeap(D,index,H);
			status[v] = intree;
			hp.DeleteHeap(D, v, index,H);
			index--;

			ArcNode *q;
			q = (ArcNode *)malloc(sizeof(ArcNode));
			q = G.vertices[v].firstarc;
			while (q != NULL)
			{
				w = q->adjvex;
				if (status[w] == unseen)
				{
					status[w] = fringe;
					Dad[w] = v;
					bw[w] = min(bw[v], q->weight);
					H[w] = bw[w];
					D[1+index++] = w;
				}
				else if (status[w] == fringe && bw[w] < min(bw[v], q->weight))
				{
					hp.DeleteHeap(D, w, index, H);
					index--;
					Dad[w] = v;
					bw[w] = min(bw[v], q->weight);
					H[w] = bw[w];
					D[1+index++] = w;
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
	vector<int> DijkstraMHeap(int matrix[vn][vn], int s, int t)
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
		int H[vn];
		int D[vn + 1], index = 0;
		D[0] = -1;
		for (int i = 0; i < vn; i++)
		{
			H[i] = 0;
			D[i + 1] = -1;
		}
		
		for (int i = 0; i < vn; i++)
		{
			if (status[i] == fringe)
			{
				D[1 + index++] = i;
				H[i] = bw[i];
			}
		}
		while (index!= 0)
		{
			int v = hp.MaxHeap(D, index, H);
			status[v] = intree;
			hp.DeleteHeap(D, v, index, H);
			index--;

			for (int j = 0; j < vn; j++)
			{
				if (matrix[v][j] != 0 && matrix[v][j] != INT_MAX)
				{
					w = j;
					if (status[w] == unseen)
					{
						status[w] = fringe;
						bw[w] = matrix[v][w];
						Dad[w] = v;
						bw[w] = min(bw[v], matrix[v][w]);
						H[w] = bw[w];
						D[1 + index++] = w;
					}
					else if (status[w] == fringe&&bw[w] < min(bw[v], matrix[v][w]))
					{
						hp.DeleteHeap(D, w, index, H);
						index--;
						Dad[w] = v;
						bw[w] = min(bw[v], matrix[v][w]);
						D[1 + index++] = w;
						H[w] = bw[w];
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
