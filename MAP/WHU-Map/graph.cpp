#include<stdio.h>
#include<malloc.h>
#include "adjacency.h"
#include "stdafx.h"
#define INF 32767				//定义无穷大
#define MAXV 100				//最大顶点个数




/*邻接表的基本运算算法*/
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)			//创建图的邻接表
{
	int i, j;
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)								//给邻接表中所有头结点的指针域置初值
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++)								//检查邻接矩阵中的每个元素
		for (j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)			//存在一条边
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));			//创建一个边结点p
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;		//采用头插法插入结点p
				G->adjlist[i].firstarc = p;
			}
	G->n = n; G->e = e;
}

void DispAdj(AdjGraph *G)					//输出邻接表G
{
	ArcNode *p;
	for (int i = 0; i < G->n; i++)			//扫描所有单链表
	{
		p = G->adjlist[i].firstarc;
		printf("%3d", i);
		while (p != NULL)
		{
			printf("%3d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("∧\n");
	}
}

void DestroyAdj(AdjGraph *&G)		//销毁图的邻接表
{
	ArcNode *pre, *p;
	for (int i = 0; i < G->n; i++)			//扫描所有单链表
	{
		pre = G->adjlist[i].firstarc;			//pre指向第i个单链表的首结点
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)		//释放第i个单链表的所有边结点
			{
				free(p);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);			//释放头结点数组
}