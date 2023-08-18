#include "SeqList.h"




void SeqListPrint(SL* ps)//��ӡ
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ",ps->list[i]);
	}
	printf("\n");
}




void SeqListInit(SL* ps) //��ʼ������
{
	ps->list = NULL;
	ps->size = ps->capactity = 0;
}

void SeqListDestory(SL* ps) //����
{
	free(ps->list);
	ps->list = NULL;
	ps->capactity = ps->size = 0;

}


void SeqListCheckCapacity(SL* ps)//��������Ƿ�����
{
	if (ps->size == ps->capactity)
	{
		int newcapactity = (ps->capactity == 0) ? 4 : ps->capactity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->list, newcapactity*sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc error\n");
			exit(-1);
		}
		ps->list = tmp;
		ps->capactity = newcapactity;
	}
}

void SeqListPushBack(SL* ps, SLDataType n)//β��
{
	SeqListCheckCapacity(ps);
	ps->list[ps->size] = n;
	ps->size++;
}

void SeqListPopBack(SL* ps)//βɾ
{
	assert(ps->size > 0);
	ps->size--;
}



void SeqListPushFront(SL* ps, SLDataType x)//ͷ��
{

	SeqListCheckCapacity(ps);


	//�Ӻ���ǰŲ������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->list[end + 1] = ps->list[end];
		end--;
	}
	ps->list[0] = x;
	ps->size++;

}


void SeqListPopFront(SL* ps)//ͷɾ
{
	assert(ps -> size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->list[begin - 1] = ps->list[begin];
		begin++;
	}

	ps->size--;

}

int SeqListFind(SL* ps, SLDataType x)//�ҵ�˳����е�Ԫ�� ����ҵ��������±�ֵ ����Ҳ�������  -1
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->list[i] == x)
		{
			return i;
		}
	}
	return -1;
}


void SeqListInsert(SL* ps, int pos, SLDataType x)//��˳����е�����λ�ò���Ԫ��
{

	assert(!(pos < 0 || pos > ps->size));//�жϲ���λ���Ƿ���Ч
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos - 1)
	{
		ps->list[end+1] = ps->list[end];
		end--;
	}
	ps->list[pos-1] = x;
	ps->size++;
}

void SeqListDele(SL* ps, int pos)//��˳����е�����λ��ɾ��Ԫ��
{
	assert(!(pos < 0 || pos > ps->size));//�ж�ɾ��λ���Ƿ���Ч
	while (pos <= ps->size)
	{
		ps->list[pos - 1] = ps->list[pos];
		pos++;
	}
	ps->size--;

}



//OJ
void Arrprint(int* nums,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ",nums[i]);
	}
	printf("\n");
}

int* ArrDel(int* nums, int* numsize, int vla)
{
	//1. ���� ������������  ʱ�� O(n^4)           vevry ���ӣ���������������
	/*int src = 0;
	int i = 0,count=0;
	for (i = 0; i < *numsize; i++)
	{
		if (numsize[i] == vla)
		{
			count++;
		}
	}
	for (i = 0; i < count; i++)
	{
		for (src = 0; src < *numsize; src++)
		{
			if (nums[src] == vla)
			{
				int j = src;
				for (j = src; j < *numsize; j++)
				{
					nums[j] = nums[j + 1];
				}
				*numsize -= 1;
			}
		}
	}*/

	//2.����һ����ʱ���� �Ѳ���val��ֵ����ȥ��Ȼ���ٿ�����ȥ��
	//ʱ�临�Ӷ���O(n^2)  �ռ临�Ӷ���o(n)
	/*int* tmps = (int*)malloc(*numsize*sizeof(int));
	int srcbegin = 0, tmpbegin = 0;
	while (srcbegin < *numsize)
	{
		if (nums[srcbegin] != vla)
		{
			tmps[tmpbegin] = nums[srcbegin];
			srcbegin++;
			tmpbegin++;
		}
		else
		{
			srcbegin++;
		}
		
	}
	srcbegin = 0;
	while (srcbegin < tmpbegin)
	{
		nums[srcbegin] = tmps[srcbegin];
		srcbegin++;
	}
	*numsize = tmpbegin;
	free(tmps);
	tmps = NULL;*/

	//3.ʱ�临�Ӷ���O(n)  �ռ临�Ӷ���o(1)

	int src = 0, dest = 0;
	while (src < *numsize)
	{
		if (nums[src] != vla)
		{
			nums[dest] = nums[src];
			src++;
			dest++;
		}
		else
		{
			src++;
		}
	}
	*numsize = dest;


	return nums;
}


void ArrMerge(int* nums1, int numsize1, int m, int* nums2, int numsize2, int n)//�ϲ���������
{
	int end1 = m - 1, end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}


}



int MoveRepetition(int* nums, int *numsize)
{
	int i = 0, j = 1;
	int src = 0;
	while (j < *numsize)
	{
		if (nums[i] == nums[j])
		{
			j++;
		}
		else
		{
			nums[src] = nums[i];
			i = j;
			j++;
			src++;
		}

	}
	nums[src] = nums[i];
	src++;


	return src;

}