#include "generateGraph.h"
#include "heapsort.h"
#include "MaxBD.h"
#include "MaxBDwithHeap.h"
#include "Kruscal.h"
#include <iostream>
int matrix[vn][vn];
#define x INT_MAX
int s = 0, t = 8;
void main()
{
	Graph sl;//Graph Object
	MaxBD bd;//Dijsktra Object
	HeapBD hp;//Dijsktra with heap Object
	kruscal kc;//Kruscal Object
	
	/*Test G1*/
	//ALGraph g;
			   //for (int i = 0; i < 10; i++)
			   //{
			   //	g.vertices[i].data = i;
			   //	g.vertices[i].firstarc = NULL;
			   //}
			   ////0
			   //ArcNode *p;//头插法前一个
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 1;
			   //p->weight = 6;
			   //p->next = NULL;
			   //p->next = g.vertices[0].firstarc;
			   //g.vertices[0].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 2;
			   //p->weight = 3;
			   //p->next = NULL;
			   //p->next = g.vertices[0].firstarc;
			   //g.vertices[0].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 3;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[0].firstarc;
			   //g.vertices[0].firstarc = p;
			   ////1
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 0;
			   //p->weight = 6;
			   //p->next = NULL;
			   //p->next = g.vertices[1].firstarc;
			   //g.vertices[1].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 2;
			   //p->weight = 4;
			   //p->next = NULL;
			   //p->next = g.vertices[1].firstarc;
			   //g.vertices[1].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 4;
			   //p->weight = 2;
			   //p->next = NULL;
			   //p->next = g.vertices[1].firstarc;
			   //g.vertices[1].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 5;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[1].firstarc;
			   //g.vertices[1].firstarc = p;
			   ////2
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 0;
			   //p->weight = 3;
			   //p->next = NULL;
			   //p->next = g.vertices[2].firstarc;
			   //g.vertices[2].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 4;
			   //p->weight = 2;
			   //p->next = NULL;
			   //p->next = g.vertices[2].firstarc;
			   //g.vertices[2].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 1;
			   //p->weight = 4;
			   //p->next = NULL;
			   //p->next = g.vertices[2].firstarc;
			   //g.vertices[2].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 6;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[2].firstarc;
			   //g.vertices[2].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 3;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[2].firstarc;
			   //g.vertices[2].firstarc = p;
			   ////3
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 0;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[3].firstarc;
			   //g.vertices[3].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 2;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[3].firstarc;
			   //g.vertices[3].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 6;
			   //p->weight = 8;
			   //p->next = NULL;
			   //p->next = g.vertices[3].firstarc;
			   //g.vertices[3].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 9;
			   //p->weight = 18;
			   //p->next = NULL;
			   //p->next = g.vertices[3].firstarc;
			   //g.vertices[3].firstarc = p;
			   ////4
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 2;
			   //p->weight = 2;
			   //p->next = NULL;
			   //p->next = g.vertices[4].firstarc;
			   //g.vertices[4].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 5;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[4].firstarc;
			   //g.vertices[4].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 1;
			   //p->weight = 2;
			   //p->next = NULL;
			   //p->next = g.vertices[4].firstarc;
			   //g.vertices[4].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 6;
			   //p->weight = 8;
			   //p->next = NULL;
			   //p->next = g.vertices[4].firstarc;
			   //g.vertices[4].firstarc = p;
			   ////5
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 1;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[5].firstarc;
			   //g.vertices[5].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 4;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[5].firstarc;
			   //g.vertices[5].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 6;
			   //p->weight = 7;
			   //p->next = NULL;
			   //p->next = g.vertices[5].firstarc;
			   //g.vertices[5].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 7;
			   //p->weight = 5;
			   //p->next = NULL;
			   //p->next = g.vertices[5].firstarc;
			   //g.vertices[5].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 8;
			   //p->weight = 4;
			   //p->next = NULL;
			   //p->next = g.vertices[5].firstarc;
			   //g.vertices[5].firstarc = p;
			   ////6
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 3;
			   //p->weight = 8;
			   //p->next = NULL;
			   //p->next = g.vertices[6].firstarc;
			   //g.vertices[6].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 2;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[6].firstarc;
			   //g.vertices[6].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 4;
			   //p->weight = 8;
			   //p->next = NULL;
			   //p->next = g.vertices[6].firstarc;
			   //g.vertices[6].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 5;
			   //p->weight = 7;
			   //p->next = NULL;
			   //p->next = g.vertices[6].firstarc;
			   //g.vertices[6].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 9;
			   //p->weight = 10;
			   //p->next = NULL;
			   //p->next = g.vertices[6].firstarc;
			   //g.vertices[6].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 7;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[6].firstarc;
			   //g.vertices[6].firstarc = p;
			   ////7
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 5;
			   //p->weight = 5;
			   //p->next = NULL;
			   //p->next = g.vertices[7].firstarc;
			   //g.vertices[7].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 6;
			   //p->weight = 9;
			   //p->next = NULL;
			   //p->next = g.vertices[7].firstarc;
			   //g.vertices[7].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 8;
			   //p->weight = 1;
			   //p->next = NULL;
			   //p->next = g.vertices[7].firstarc;
			   //g.vertices[7].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 9;
			   //p->weight = 3;
			   //p->next = NULL;
			   //p->next = g.vertices[7].firstarc;
			   //g.vertices[7].firstarc = p;
			   ////8
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 5;
			   //p->weight = 4;
			   //p->next = NULL;
			   //p->next = g.vertices[8].firstarc;
			   //g.vertices[8].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 7;
			   //p->weight = 1;
			   //p->next = NULL;
			   //p->next = g.vertices[8].firstarc;
			   //g.vertices[8].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 9;
			   //p->weight = 4;
			   //p->next = NULL;
			   //p->next = g.vertices[8].firstarc;
			   //g.vertices[8].firstarc = p;
			   ////9
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 3;
			   //p->weight = 18;
			   //p->next = NULL;
			   //p->next = g.vertices[9].firstarc;
			   //g.vertices[9].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 6;
			   //p->weight = 10;
			   //p->next = NULL;
			   //p->next = g.vertices[9].firstarc;
			   //g.vertices[9].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 7;
			   //p->weight = 3;
			   //p->next = NULL;
			   //p->next = g.vertices[9].firstarc;
			   //g.vertices[9].firstarc = p;
			   //p = (ArcNode *)malloc(sizeof(ArcNode));
			   //p->adjvex = 8;
			   //p->weight = 4;
			   //p->next = NULL;
			   //p->next = g.vertices[9].firstarc;
			   //g.vertices[9].firstarc = p;
	/*TEST G2*/
	//int matrix1[10][10];
			   //matrix1[0][0] = 0;
			   //matrix1[0][1] = 6;
			   //matrix1[0][2] = 3;
			   //matrix1[0][3] = 9;
			   //matrix1[0][4] = x;
			   //matrix1[0][5] = x;
			   //matrix1[0][6] = x;
			   //matrix1[0][7] = x;
			   //matrix1[0][8] = x;
			   //matrix1[0][9] = x;
			   //matrix1[1][0] = 6;
			   //matrix1[1][1] = 0;
			   //matrix1[1][2] = 4;
			   //matrix1[1][3] = x;
			   //matrix1[1][4] = 2;
			   //matrix1[1][5] = 9;
			   //matrix1[1][6] = x;
			   //matrix1[1][7] = x;
			   //matrix1[1][8] = x;
			   //matrix1[1][9] = x;
			   //matrix1[2][0] = 3;
			   //matrix1[2][1] = 4;
			   //matrix1[2][2] = 0;
			   //matrix1[2][3] = 9;
			   //matrix1[2][4] = 2;
			   //matrix1[2][5] = x;
			   //matrix1[2][6] = 9;
			   //matrix1[2][7] = x;
			   //matrix1[2][8] = x;
			   //matrix1[2][9] = x;
			   //matrix1[3][0] = 9;
			   //matrix1[3][1] = x;
			   //matrix1[3][2] = 9;
			   //matrix1[3][3] = 0;
			   //matrix1[3][4] = x;
			   //matrix1[3][5] = x;
			   //matrix1[3][6] = 8;
			   //matrix1[3][7] = x;
			   //matrix1[3][8] = x;
			   //matrix1[3][9] = 18;
			   //matrix1[4][0] = x;
			   //matrix1[4][1] = 2;
			   //matrix1[4][2] = 2;
			   //matrix1[4][3] = x;
			   //matrix1[4][4] = 0;
			   //matrix1[4][5] = 9;
			   //matrix1[4][6] = 8;
			   //matrix1[4][7] = x;
			   //matrix1[4][8] = x;
			   //matrix1[4][9] = x;
			   //matrix1[5][0] = x;
			   //matrix1[5][1] = 9;
			   //matrix1[5][2] = x;
			   //matrix1[5][3] = x;
			   //matrix1[5][4] = 9;
			   //matrix1[5][5] = 0;
			   //matrix1[5][6] = 7;
			   //matrix1[5][7] = 5;
			   //matrix1[5][8] = 4;
			   //matrix1[5][9] = x;
			   //matrix1[6][0] = x;
			   //matrix1[6][1] = x;
			   //matrix1[6][2] = 9;
			   //matrix1[6][3] = 8;
			   //matrix1[6][4] = 8;
			   //matrix1[6][5] = 7;
			   //matrix1[6][6] = 0;
			   //matrix1[6][7] = 9;
			   //matrix1[6][8] = x;
			   //matrix1[6][9] = 10;
			   //matrix1[7][0] = x;
			   //matrix1[7][1] = x;
			   //matrix1[7][2] = x;
			   //matrix1[7][3] = x;
			   //matrix1[7][4] = x;
			   //matrix1[7][5] = 5;
			   //matrix1[7][6] = 9;
			   //matrix1[7][7] = 0;
			   //matrix1[7][8] = 1;
			   //matrix1[7][9] = 3;
			   //matrix1[8][0] = x;
			   //matrix1[8][1] = x;
			   //matrix1[8][2] = x;
			   //matrix1[8][3] = x;
			   //matrix1[8][4] = x;
			   //matrix1[8][5] = 4;
			   //matrix1[8][6] = x;
			   //matrix1[8][7] = 1;
			   //matrix1[8][8] = 0;
			   //matrix1[8][9] = 4;
			   //matrix1[9][0] = x;
			   //matrix1[9][1] = x;
			   //matrix1[9][2] = x;
			   //matrix1[9][3] = 18;
			   //matrix1[9][4] = x;
			   //matrix1[9][5] = x;
			   //matrix1[9][6] = 10;
			   //matrix1[9][7] = 3;
			   //matrix1[9][8] = 4;
			   //matrix1[9][9] = 0;     

	int i;
	/*Question 1: Create a Graph*/
	ALGraph g;
	g=sl.generateGraph();    //the first graph
	sl.generateGraph2(matrix); //the second graph
	cout << "G1 and G2 have been generated" << endl;
	cout << "s="<<s <<"   "<<"t="<<t<< endl;
	/*Question 3.1: Max BandWidth Without Heap(Graph 1)*/

	vector<int> Dad1;
	Dad1 = bd.Dijkstra(g, s, t);
	vector<int> path1; 
	path1.push_back(t);
	int m1 = Dad1[t];
	while (m1 != s)
	{
		path1.push_back(m1);
		m1 = Dad1[m1];
	}
	path1.push_back(s);
	cout << "G1 Dijsktra's path" << endl;
	for (i = 0; i < path1.size(); i++)
	{
		cout << path1[i]<<"->";
	}
	cout << "end" <<endl;
	cout <<endl;

	/*Question 3.1: Max BandWidth Without Heap(Graph 2)*/
	
	vector<int> Dad2;
	Dad2 = bd.DijkstraM(matrix, s, t);
	vector<int> path2; 
	path2.push_back(t);
	int m2 = Dad2[t];
	while (m2 != s)
	{
		path2.push_back(m2);
		m2 = Dad2[m2];
	}
	path2.push_back(s);
	cout << "G2 Dijsktra's path" << endl;
	for (i = 0; i < path2.size(); i++)
	{
		cout << path2[i] << "->";
	}
	cout <<"end"<< endl;
	cout <<endl;
	/*Question 3.2 : Max BandWidth using Heap(Graph 1)*/
	
	vector<int> Dad3;
	Dad3 = hp.DijkstraHeap(g, s, t);
	vector<int> path3; 
	path3.push_back(t);
	int m3 = Dad3[t];
	while (m3 != s)
	{
		path3.push_back(m3);
		m3 = Dad3[m3];
	}
	path3.push_back(s);
	cout << "G1 Dijsktra(heap)'s path" << endl;
	for (i = 0; i < path3.size(); i++)
	{
		cout << path3[i] << "->";
	}
	cout <<"end"<< endl;
	cout << endl;
	/*Question 3.2 : Max BandWidth using Heap(Graph 2)*/
	
	vector<int> Dad4;
	Dad4 = hp.DijkstraMHeap(matrix, s, t);
	vector<int> path4;
	path4.push_back(t);
	int m4 = Dad4[t];
	while (m4 != s)
	{
		path4.push_back(m4);
		m4 = Dad4[m4];
	}
	path4.push_back(s);
	cout << "G2 Dijsktra(heap)'s path" << endl;
	for (i = 0; i < path4.size(); i++)
	{
		cout << path4[i] << "->";
	}
	cout <<"end"<< endl;
	cout << endl;
	/*Question 3.3 : Max BandWidth Kruscal(Graph 1)*/
	
	vector<edge> T1;
	T1 = kc.Kruscal(g, s, t);
	vector<int> Dad5 = kc.BFS(T1, s, t);
	vector<int> path5;
	path5.push_back(t);
	int m5 = Dad5[t];
	while (m5 != s)
	{
		path5.push_back(m5);
		m5 = Dad5[m5];
	}
	path5.push_back(s);
	cout << "G1 Kruscal's path" << endl;
	for (i = 0; i < path5.size(); i++)
	{
		cout << path5[i] << "->";
	}
	cout << "end"<<endl;
	cout << endl;
	/*Question 3.3: Max BandWidth Kruscal(Graph 2)*/

	vector<edge> T2;
	T2 = kc.KruscalH(matrix, s, t);
	vector<int> Dad6 = kc.BFS(T2, s, t);
	vector<int> path6;
	path6.push_back(t);
	int m6 = Dad6[t];
	while (m6 != s)
	{
		path6.push_back(m6);
		m6 = Dad6[m6];
	}
	path6.push_back(s);
	cout << "G2 Kruscal's path" << endl;
	for (i = 0; i < path6.size(); i++)
	{
		cout << path6[i] << "->";
	}
	cout << "end"<<endl;
	cout << endl;
	system("pause");
}

