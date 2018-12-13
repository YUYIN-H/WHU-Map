#pragma once

typedef struct ANode
{
	int adjvex;				//�ñߵ��ڽӵ���
	struct ANode* nextarc;	//ָ����һ���ߵ�ָ��
	int dist;				//�ñߵ������Ϣ��·��
} ArcNode;					        //�߽������

typedef struct VNode
{
	InfoType info;			//�����������Ϣ:����
	ArcNode *firstarc;		//ָ���һ���߽��
} VNode;							//ͷ�������

typedef struct
{
	Vnode adjlist[MAXV];	//�ڽӱ��ͷ�������
	int n, e;				//ͼ�еĶ�����n�ͱ���e
} AdjGraph;							//������ͼ�ڽӱ�����