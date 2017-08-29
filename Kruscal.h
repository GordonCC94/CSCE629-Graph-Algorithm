#pragma once
#ifndef _KRUSCAL_H
#define _KRUSCAL_H
#include <stack>
#include "generateGraph.h"
#include "heapsort.h"
#include <unordered_map>
#include <stack>
int graph[vn][vn] = { 0 };
enum Color
{
	white, black, gray
};
Color color[vn];
ArcNode *q;
int D[vn], height[vn];
edge e[vn*vn];
using namespace std;
class kruscal
{
public:

	int Find(int v)
	{
		stack<int> sk;
		int c,w = v;
		while (D[w] != -1)
		{
			sk.push(w);
			w = D[w];
		}
		while (sk.size() != 0)
		{
			c = sk.top();
			sk.pop();
			D[c] = w;
		}
		return w;
	}
	void Union(int r1, int r2)
	{
		if (height[r1] > height[r2])
			D[r2] = r1;
		else if (height[r1] < height[r2])
			D[r1] = r2;
		else
		{
			D[r2] = r1;
			height[r1]++;
		}
		return;
	}
	void MakeSet(int D[], int height[])
	{
		for (int i = 0; i < vn; i++)
		{
			D[i] = -1;
			height[i] = 0;
		}
	}

	/*Kruscal for Graph 1*/
	vector<edge> Kruscal(ALGraph G, int source, int terminal)
	{
		MakeSet(D, height);
		vector<edge> T;
		Heap hp;
		
		edge node;
		node.s = -1;
		node.t = -1;
		node.weight = -1;
		e[0]=node;
		int i,count=0,j;
		ArcNode *p;
		for (i = 0; i < vn; i++)
		{
			p = (ArcNode *)malloc(sizeof(ArcNode));
			p = G.vertices[i].firstarc;
			while (p != NULL)
			{
				node.s = i;
				node.t = p->adjvex;
				node.weight = p->weight;
				if (node.s < node.t)
				{
					hp.Kinsert(e, node, count);
					//hp.insertHeapKruscal(e, node, count);
					count++;
				}
				p = p->next;
			}
		}
		
		edge max;
		while (count!= 0)
		{
			//edge max=hp.MaxHeapForKruscal(e,count);
			max = e[1];
			int r1 = Find(max.s);
			int r2 = Find(max.t);
			if (r1 != r2)
			{
				T.push_back(max);
				Union(r1, r2);
			}
			hp.Kdelete(e, 1, count);
			//hp.deleteHeapKruscal(e, count);
			count--;
		}
		/*MST*/
		return T;
	}


	/*Kruscal for Graph 2*/
	vector<edge> KruscalH(int matrix[vn][vn], int source, int terminal)
	{
		/*DFSmain(G, source);
		Rank(D);*/
		MakeSet(D, height);
		vector<edge> T;
		Heap hp;
		
		edge node;
		node.s = -1;
		node.t = -1;
		node.weight = -1;
		e[0] = node;
		int i, count = 0, j;	

		for (i = 0; i < vn; i++)
		{
			for (j = i; j < vn; j++)
			{
				node.s = i;
				node.t = j;
				if (matrix[i][j] != INT_MAX&&matrix[i][j]!=0)
				{
					node.weight = matrix[i][j];
					hp.Kinsert(e, node, count);
					count++;
				}
			}
		}
		
		while (count != 0)
		{
			edge max = e[1];
			int r1 = Find(max.s);
			int r2 = Find(max.t);
			if (r1 != r2)
			{
				T.push_back(max);
				Union(r1, r2);
			}
			hp.Kdelete(e, 1,count);
			count--;
		}
		
		return T;
	}



	/*BFS*/
	vector<int> BFS(vector<edge> e, int start, int terminal)
	{
		int edgeNumber = e.size();
		int i, j,index, t, w, count = 0;
		vector<int> dad(vn);
		dad[start] = -1;
		Color color[vn];
		for (i = 0; i < edgeNumber; i++)
		{
			graph[e[i].s][e[i].t] = e[i].weight;
			graph[e[i].t][e[i].s] = e[i].weight;
		}
		for (i = 0; i < vn; i++)
		{
			color[i] = white;
		}

		color[start] = gray;
		queue<int> q;
		q.push(start);
		while (q.size() != 0)
		{
			t = q.front();
			q.pop();
			count = 0;
			while (count<vn)
			{
				if (graph[t][count] != 0)
				{
					if (color[count] == white)
					{
						color[count] = gray;
						dad[count] = t;
						q.push(count);
					}
				}
				count++;
			}
			color[t] = black;
		}
		return dad;
	}





};

#endif