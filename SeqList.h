#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType; //˳����е�ÿ��Ԫ������

typedef struct SeqList
{
	SLDataType* list;	//˳���
	int size;			// �������洢�˶��ٸ�Ԫ��
	int capactity;		//����ʵ���ܴ����ݵĿռ�����
}SL;


//�ӿں���--------------------


void SeqListPrint(SL* ps);//��ӡ
void SeqListInit(SL* ps); //��ʼ������
void SeqListDestory(SL* ps); //����

void SeqListCheckCapacity(SL* ps);//��������Ƿ�����

void SeqListPushBack(SL* ps , SLDataType n);//β��
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushFront(SL* ps,SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ



int SeqListFind(SL* ps, SLDataType x);//�ҵ�˳����е�Ԫ�� ����ҵ��������±�ֵ ����Ҳ�������  -1
void SeqListInsert(SL* ps ,int pos, SLDataType x);//��˳����е�����λ�ò���Ԫ��
void SeqListDele(SL* ps, int pos);//��˳����е�����λ��ɾ��Ԫ��
//..


//OJ ��


void Arrprint(int* nums,int size);//��ӡ����

int* ArrDel(int* nums, int* numsize, int vla);//ɾ�������к�vla��ȵ�����Ԫ��

void ArrMerge(int* nums1, int numsize1,int m,int* nums2,int numsize2,int n);//�ϲ���������

int MoveRepetition(int* nums, int* numsize);