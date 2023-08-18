#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType; //顺序表中的每个元素类型

typedef struct SeqList
{
	SLDataType* list;	//顺序表
	int size;			// 表中所存储了多少个元素
	int capactity;		//数组实际能存数据的空间容量
}SL;


//接口函数--------------------


void SeqListPrint(SL* ps);//打印
void SeqListInit(SL* ps); //初始化数组
void SeqListDestory(SL* ps); //销毁

void SeqListCheckCapacity(SL* ps);//检查容量是否满了

void SeqListPushBack(SL* ps , SLDataType n);//尾插
void SeqListPopBack(SL* ps);//尾删
void SeqListPushFront(SL* ps,SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删



int SeqListFind(SL* ps, SLDataType x);//找到顺序表中的元素 如果找到返回其下标值 如果找不到返回  -1
void SeqListInsert(SL* ps ,int pos, SLDataType x);//再顺序表中的任意位置插入元素
void SeqListDele(SL* ps, int pos);//在顺序表中的任意位置删除元素
//..


//OJ 题


void Arrprint(int* nums,int size);//打印数组

int* ArrDel(int* nums, int* numsize, int vla);//删除数组中和vla相等的所有元素

void ArrMerge(int* nums1, int numsize1,int m,int* nums2,int numsize2,int n);//合并两个数组

int MoveRepetition(int* nums, int* numsize);