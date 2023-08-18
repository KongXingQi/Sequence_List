#include "SeqList.h"


void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1); //��ʼ��˳���

	//β��
	SeqListPushBack(&s1,1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);

	SeqListPrint(&s1);//��ӡ˳���

	//βɾ
	SeqListPopBack(&s1); 
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	SeqListPrint(&s1);//��ӡ˳���


	SeqListPushBack(&s1, 10);
	SeqListPushBack(&s1, 20);

	SeqListPrint(&s1);//��ӡ˳���



	SeqListDestory(&s1);//����
}
void TestSeqList2()
{
	SL s1;
	SeqListInit(&s1); //��ʼ��˳���


	//β��
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);

	SeqListPrint(&s1);//��ӡ˳���

	//ͷ��
	SeqListPushFront(&s1,10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPushFront(&s1, 50);
	SeqListPrint(&s1);//��ӡ˳���


	//ͷɾ
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);


	SeqListPrint(&s1);//��ӡ˳���


}
void TestSeqList3()
{
	SL s1;
	SeqListInit(&s1); //��ʼ��˳���


	//β��
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);//��ӡ˳���


	int num = SeqListFind(&s1, 5);
	if (num != -1)
	{
		printf("��˳����е��±�Ϊ%d\n", num);
	}
	else
	{
		printf("�Ҳ�����\n");
	}



	SeqListInsert(&s1,3,300);
	SeqListPrint(&s1);//��ӡ˳���


	SeqListDele(&s1, 3);
	SeqListPrint(&s1);//��ӡ˳���


	SeqListDestory(&s1);
}


void TestArr1()
{
	int arr1[] = { 1, 2, 3, 4};
	int size = sizeof(arr1) / sizeof(arr1[0]);
	int val = 3;

	Arrprint(arr1, size);
	ArrDel(arr1,&size,val);
	Arrprint(arr1,size);
	
}

void TestArr2()
{
	int arr[] = {1,1,1,2,2,2,3,3,4,4};
	int size = sizeof(arr) / sizeof(arr[0]);
	size = MoveRepetition(arr,&size);
	Arrprint(arr, size);


}

void TestArr3()
{
	int arr1[] = { 2, 2, 3, 0, 0, 0 };
	int arr2[] = { 1, 1, 6 };
	int size1 = sizeof(arr1) / sizeof(arr1[1]);
	int size2 = sizeof(arr2) / sizeof(arr2[1]);
	int m = 3,n = 3;

	Arrprint(arr1, size1);
	ArrMerge(arr1, size1, m, arr2, size2, n);
	Arrprint(arr1, size1);



}

void Test1()
{
	SL* s1;
	s1->capactity = 100;
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	Test1();


	//TestArr1();
	//TestArr2();
	//TestArr3();
	return 0;
}




////-------------------------------------------------     -���Ա��˳��洢�ṹ-   -----------------------------------------------------
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//
//#define MAXSIZE 20
//#define ERROR 0
//#define OK 1
//
//
//typedef struct list
//{
//	int data[MAXSIZE];
//	int length;
//};
//
//void ShowList(struct list L)
//{
//	int n = 0;
//	for (n = 0; n < L.length; n++)
//	{
//		printf("%d ",L.data[n]);
//	}
//	printf("\n");
//}
//
//
//// GetElem������  ʱ�临�Ӷ�Ϊ  O��1�� 
//
////���ȵ��ж���������Ƿ�Ϸ�     1 <= i  <= length      
//int GetElem(struct list L, int i, int* e)
//{
//	if (L.length == 0 || i < 1 || i > L.length)
//	{
//		return ERROR;
//	}
//	else
//	{
//		*e = L.data[i - 1];
//		return OK;
//	}
//
//
//}
//
//// ListInsert ������ʱ�临�Ӷ� O(n)
//
////�����жϲ����λ���Ƿ����
////���˳�����Ա����� �����׳��쳣���ߣ���̬����������
////���Ա�+1
//int ListInsert(struct list* L,int i,int e)
//{
//	int k;
//	if (L->length == MAXSIZE)
//	{
//		return ERROR;
//	}
//	if (i < 1 || i >L->length)
//	{
//		return ERROR;
//	}
//	for (k = L->length; k >= i-1; k--)
//	{
//		L->data[k] = L->data[k-1];
//	}
//	L->data[i-1] = e;
//	L->length++;
//	
//	return OK;
//
//}
////ListDelete ������ʱ�临�Ӷ� O(n)
////���ȼ���������ķ�Χ�Ƿ�ϸ�
////ȡ�� i λ�õ�Ԫ�� ����  e ������ֵ
////��ɾ��Ԫ�ؿ�ʼλ�� �������������һ�� �Ƶ�ǰһλ��
////length--��
//int ListDelete(struct list* L, int i,int* e)
//{
//	int k;
//	if (L->length == 0) //�߱�Ϊ��
//	{
//		return ERROR;
//	}
//	if (i < 1 || i >L->length) //ɾ����λ�ò���ȷ
//	{
//		return ERROR;
//	}
//	*e = L->data[i - 1];
//	if (i < L->length)
//	{
//		for (k = i; k < L->length; k++)//��ǰ
//		{
//			L->data[k - 1] = L->data[k];
//		}
//		L->length--;
//	}
//	return OK;
//}
//int main()
//{
//	int i = 0,e=0;
//	struct list L = { {1,2,3,4,5,6,7,8,9,10}, 10 };
//
//	printf("��������Ҫ��������ӵ�Ԫ��λ�ü�Ԫ��:");
//	scanf("%d%d",&i,&e);
//	ListInsert(&L,i,e);
//	ShowList(L);
//
//	printf("��������Ҫ���ұ��еĵڼ���Ԫ��:");
//	scanf("%d", &i);
//	GetElem(L, i, &e);
//    printf("���е�%d��Ԫ����%d\n", i, e);
//
//	printf("��������Ҫ�ڱ���ɾ����Ԫ��λ��");
//	scanf("%d",&i);
//	ListDelete(&L, i,&e);
//	ShowList(L);
//
//	return 0;
//}