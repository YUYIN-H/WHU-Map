#include<stdio.h>
#include<malloc.h>
#include "adjacency.h"
#include "stdafx.h"
#define INF 32767				//���������
#define MAXV 100				//��󶥵����




/*�ڽӱ�Ļ��������㷨*/
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)			//����ͼ���ڽӱ�
{
	int i, j;
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)								//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++)								//����ڽӾ����е�ÿ��Ԫ��
		for (j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)			//����һ����
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));			//����һ���߽��p
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;		//����ͷ�巨������p
				G->adjlist[i].firstarc = p;
			}
	G->n = n; G->e = e;
}

void DispAdj(AdjGraph *G)					//����ڽӱ�G
{
	ArcNode *p;
	for (int i = 0; i < G->n; i++)			//ɨ�����е�����
	{
		p = G->adjlist[i].firstarc;
		printf("%3d", i);
		while (p != NULL)
		{
			printf("%3d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("��\n");
	}
}

void DestroyAdj(AdjGraph *&G)		//����ͼ���ڽӱ�
{
	ArcNode *pre, *p;
	for (int i = 0; i < G->n; i++)			//ɨ�����е�����
	{
		pre = G->adjlist[i].firstarc;			//preָ���i����������׽��
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)		//�ͷŵ�i������������б߽��
			{
				free(p);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);			//�ͷ�ͷ�������
}