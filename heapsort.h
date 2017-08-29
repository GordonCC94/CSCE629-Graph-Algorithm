#pragma once
#ifndef _HEAPSORT_H
#define _HEAPSORT_H
typedef struct Edge
{
	int weight;
	int s;
	int t;
}edge;
#include <queue>
#include <vector>
#include <map>

using namespace std;
class Heap
{
public:
	void HeapAdjust(int a[], int s, int n, int H[])
	{
		int i;
		int temp, tempVertex;
		temp = H[a[s]];
		tempVertex = a[s];
		for (i = 2 * s; i <= n; i *= 2)
		{
			if (i < n && H[a[i]] < H[a[i + 1]])
			{
				i++;//
			}
			if (temp >= H[a[i]])
			{
				break;
			}
			a[s] = a[i];//
			s = i;		//
		}
		a[s] = tempVertex;    //
		return;
	}
	void heapSort(int a[], int n, int H[])//
	{
		int i;
		for (i = n / 2; i > 0; i--)
		{
			HeapAdjust(a, i, n, H);//
		}
		//for (i = n; i > 1; i--)//
		//{
		//	swap(a[1], a[i]);//
		//	HeapAdjust(a, 1, i - 1, H);//
		//}
		//return;
	}
	int MaxHeap(int a[], int n, int H[])
	{
		heapSort(a, n, H);
		return a[1];
	}
	void InsertHeap(int a[], int x, int n, int H[])
	{
		a[n + 1] = x;
		heapSort(a, n + 1, H);
		return;
	}
	void DeleteHeap(int a[], int x, int n, int H[])
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == x)
			{
				swap(a[n], a[i]);
				a[n] = -1;
			}
		}//找到目标位置，放置最后

		return;
	}

	void heapAdjustForKruscal(edge e[], int n)//
	{
		int i;
		for (i = n / 2; i > 0; i--)
		{
			//HeapAdjustForKruscal(e, i, n);
			int j, temp = e[i].weight;
			edge tempE = e[i];
			for (j = 2 * i; j <= n; j *= 2)
			{
				if (j < n&&e[j].weight < e[j + 1].weight)
				{
					j++;
				}
				if (temp >= e[j].weight)
				{
					break;
				}
				e[i] = e[j];
				i = j;
			}
			e[i] = tempE;
		}
	}
	void insertHeapKruscal(edge e[], edge s, int n)
	{
		e[n + 1] = s;
		heapAdjustForKruscal(e, n + 1);
	}
	void deleteHeapKruscal(edge e[], int n)
	{
		swap(e[1], e[n]);
		heapAdjustForKruscal(e, n - 1);
	}

	void Kswap(edge heap[], int a, int b)
	{
		edge temp = heap[a];
		heap[a] = heap[b];
		heap[b]=temp;
	}
	void Kinsert(edge heap[], edge e,int n)
	{
		heap[n+1]=e;
		heapUp(heap, n+1);
	}
	void heapUp(edge heap[], int index) 
	{
		if (index > 1)
		{
			int parent = index / 2;
			int parentValue = heap[parent].weight;
			int indexValue = heap[index].weight;
			if (parentValue < indexValue)
			{
				Kswap(heap, parent, index);
				heapUp(heap, parent);
			}
		}
	}
	void Kdelete(edge heap[], int index,int length)
	{
		Kswap(heap, index, length);
		heapDown(heap, 1,length);
	}
	void heapDown(edge heap[], int index,int length)
	{
		int n = length -1;
		int child = -1;
		if (2 * index > n)
		{
			return;
		}
		else if (2 * index < n)
		{
			child = 2 * index;
			if (heap[child].weight < heap[child+1].weight) 
			{
				child++;
			}
		}
		else if (2 * index == n)
		{
			child = 2 * index;
		}
		if (heap[child].weight >heap[index].weight)
		{
			Kswap(heap, child, index);
			heapDown(heap, child,length);
		}
	}



};
	

#endif