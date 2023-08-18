#include "SeqList.h"


void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1); //初始化顺序表

	//尾插
	SeqListPushBack(&s1,1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);

	SeqListPrint(&s1);//打印顺序表

	//尾删
	SeqListPopBack(&s1); 
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	SeqListPrint(&s1);//打印顺序表


	SeqListPushBack(&s1, 10);
	SeqListPushBack(&s1, 20);

	SeqListPrint(&s1);//打印顺序表



	SeqListDestory(&s1);//销毁
}
void TestSeqList2()
{
	SL s1;
	SeqListInit(&s1); //初始化顺序表


	//尾插
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);

	SeqListPrint(&s1);//打印顺序表

	//头插
	SeqListPushFront(&s1,10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPushFront(&s1, 50);
	SeqListPrint(&s1);//打印顺序表


	//头删
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);


	SeqListPrint(&s1);//打印顺序表


}
void TestSeqList3()
{
	SL s1;
	SeqListInit(&s1); //初始化顺序表


	//尾插
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);//打印顺序表


	int num = SeqListFind(&s1, 5);
	if (num != -1)
	{
		printf("在顺序表中的下标为%d\n", num);
	}
	else
	{
		printf("找不到！\n");
	}



	SeqListInsert(&s1,3,300);
	SeqListPrint(&s1);//打印顺序表


	SeqListDele(&s1, 3);
	SeqListPrint(&s1);//打印顺序表


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




////-------------------------------------------------     -线性表的顺序存储结构-   -----------------------------------------------------
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
//// GetElem函数的  时间复杂度为  O（1） 
//
////首先得判断输入的数是否合法     1 <= i  <= length      
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
//// ListInsert 函数的时间复杂度 O(n)
//
////首先判断插入的位置是否合理
////如果顺序线性表满了 ，则抛出异常或者（动态增加容量）
////线性表长+1
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
////ListDelete 函数的时间复杂度 O(n)
////首先检查输入数的范围是否合格
////取出 i 位置的元素 并用  e 返回其值
////从删除元素开始位置 挨个儿往后遍历一遍 移到前一位。
////length--；
//int ListDelete(struct list* L, int i,int* e)
//{
//	int k;
//	if (L->length == 0) //线表为空
//	{
//		return ERROR;
//	}
//	if (i < 1 || i >L->length) //删除的位置不正确
//	{
//		return ERROR;
//	}
//	*e = L->data[i - 1];
//	if (i < L->length)
//	{
//		for (k = i; k < L->length; k++)//移前
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
//	printf("请输入你要往表中添加的元素位置及元素:");
//	scanf("%d%d",&i,&e);
//	ListInsert(&L,i,e);
//	ShowList(L);
//
//	printf("请输入你要查找表中的第几个元素:");
//	scanf("%d", &i);
//	GetElem(L, i, &e);
//    printf("表中第%d个元素是%d\n", i, e);
//
//	printf("请输入你要在表中删除的元素位置");
//	scanf("%d",&i);
//	ListDelete(&L, i,&e);
//	ShowList(L);
//
//	return 0;
//}