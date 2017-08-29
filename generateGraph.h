#pragma once
#ifndef _GENERATEGRAPH_H
#define _GENERATEGRAPH_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <map>
#define vn 5000
typedef struct ArcNode
{
	int               adjvex;        //vertex name
	struct ArcNode    *next;         //next vertex  
	int				  weight;        //weight  
}ArcNode;
typedef struct VNode
{
	int        data;         //source vertex  
	ArcNode    *firstarc;    //point to the first vertex  
}VNode, AdjList[vn];
typedef struct
{
	AdjList    vertices;
}ALGraph;
using namespace std;

class Graph
{
public:
	ALGraph generateGraph()
	{
		srand((unsigned)time(NULL));
		ALGraph graph;
		int i, j, m, n, k;
		for (i = 0; i < vn; i++)
		{
			graph.vertices[i].data = i;
			graph.vertices[i].firstarc = NULL;//Initialize the adjacent list
		}
		for (i = 0; i < vn; i++)//each vertex connect with 6 vertices near it
		{
			for (j = 1; j <=3 ; j++)
			{
				m = i + j;
				n = i - j;
				if (m >= vn)
					m = m - vn;//before it
				if (n < 0)
					n = n + vn;//after it
				ArcNode *p;//head in
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = m;
				p->weight = 1;
				p->next = graph.vertices[i].firstarc;
				graph.vertices[i].firstarc = p;

				ArcNode *q;//head in
				q = (ArcNode *)malloc(sizeof(ArcNode));
				q->adjvex = n;
				q->weight = 1;
				q->next = graph.vertices[i].firstarc;
				graph.vertices[i].firstarc = q;
			}
		}


		for (i = 0; i < vn; i++)//random weight
		{
			ArcNode *p1;
			p1 = (ArcNode *)malloc(sizeof(ArcNode));
			p1 = graph.vertices[i].firstarc;
			while (p1 != NULL)//find each edges
			{
				p1->weight = 1+rand();
				k = p1->adjvex;
				ArcNode *q1;
				q1 = (ArcNode *)malloc(sizeof(ArcNode));
				q1 = graph.vertices[k].firstarc;
				while (q1 != NULL)//same weight for(s,t),(t,s)
				{
					if (q1->adjvex == i)
					{
						q1->weight = p1->weight;
					}
					q1 = q1->next;
				}
				p1 = p1->next;
			}
		}

		bool swapArray[vn];//mark exchange value
		for (i = 0; i < vn; i++)
		{
			swapArray[i] = false;
		}
		int k1,k2,temp = -1;
		for (i = 0; i < vn/2; i++)//shuffle,2500
		{
			k1 = rand() % vn;
			k2 = rand() % vn;
				while (swapArray[k1] == true || swapArray[k2] == true)
				{
					k1 = swapArray[k1] == true ? rand() % vn : k1;
					k2 = swapArray[k2] == true ? rand() % vn : k2;
				}
			swapArray[k1] = true;
			swapArray[k2] = true;//ensure random and unique
			for (j = 0; j < vn; j++)
			{
				ArcNode *p;
				p = graph.vertices[j].firstarc;
				while (p != NULL)
				{
					if (p->adjvex == k1)
						p->adjvex = temp;
					p = p->next;
				}
			}//temp

			for (j = 0; j < vn; j++)
			{
				ArcNode *p;
				p = graph.vertices[j].firstarc;
				while (p != NULL)
				{
					if (p->adjvex == k2)
						p->adjvex = k1;
					p = p->next;
				}
			}//2->1

			for (j = 0; j < vn; j++)
			{
				ArcNode *p;
				p = graph.vertices[j].firstarc;
				while (p != NULL)
				{
					if (p->adjvex == temp)
						p->adjvex = k2;
					p = p->next;
				}
			}//temp->2

			graph.vertices[k1].data = k2;
			graph.vertices[k2].data = k1;//index
		}
		VNode cc;
		for (i = 0; i < vn; i++)
		{
			for (j = 0; j < vn; j++)
			{
				if (i == graph.vertices[j].data)
				{
					cc = graph.vertices[i];
					graph.vertices[i] = graph.vertices[j];
					graph.vertices[j] = cc;
				}
			}
		}
		/*for (i = 0; i < 5000; i++)
		{
			graph.vertices[i].data += 1;
			ArcNode *p;
			p = graph.vertices[i].firstarc;
			while (p != NULL)
			{
				p->adjvex += 1;
				p = p->next;
			}
		}*/
		return graph;
	}

	int probability()//20%
	{
		int m = rand()%10;
		if (m < 2)
			return 1;
		else
			return 0;
		
	}

	
	void generateGraph2(int matrix[vn][vn])
	{
		srand((unsigned)time(NULL));
		int i, j, m, a;
		for (i = 0; i < vn; i++)
		{
			for (j = 0; j < vn; j++)
			{
				matrix[i][j] = 0;
			}
		}

		for (i = 0; i < vn; i++)
		{
			matrix[i][i] = 0;
			for (j = i + 1; j <vn; j++)
			{
				matrix[i][j] = probability()*rand();
				if (matrix[i][j] == 0)
					matrix[i][j] = INT_MAX;
				matrix[j][i] = matrix[i][j];
			}
		}
		/*int count[5000];
		for (i = 0; i < 5000; i++)
		{
			count[i] = 0;
		}
		for (i = 0; i < 5000; i++)
		{
			for (j = 0; j < 5000; j++)
				{
					if (matrix[i][j] != INT_MAX)
						count[i]++;
				}
		}*/
		return;
	}


	void connectGraph(int matrix[vn][vn], int s)
	{
		if (matrix[s][0] == INT_MAX)
		{
			matrix[s][0] = rand() + 1;
		}
		for (int i = 0; i < vn; i++)
		{
			if (matrix[i][i + 1] == INT_MAX)
			{
				matrix[i][i + 1] = rand() + 1;
				matrix[i + 1][i] = matrix[i][i + 1];
			}
		}
		return;
	}
};

#endif