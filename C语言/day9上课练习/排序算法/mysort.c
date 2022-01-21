#include "mysort.h"

//冒泡排序
void bubble(int* a)
{
	int i, j, flag;
	for (i = N - 1; i > 0; i--)
	{
		flag = 1;
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				SWAP(a[j], a[j + 1]);
				flag = 0;
			}
		}
		if (flag)//冒泡排序提前结束
		{
			break;
		}
	}
}

//选择排序
void select(int* a)
{
	int i, j;
	int minpos;
	for (i = 0; i < N - 1; i++)
	{
		minpos = i;
		for (j = i + 1; j < N; j++)
		{
			if (a[j] < a[minpos])
			{
				minpos = j;
			}
		}
		SWAP(a[minpos], a[i]);
	}
}

//插入排序
void insert(int* a)
{
	int i, j, insert_val;
	for (i = 1; i < N; i++)//外层控制要拿哪个数去插入
	{
		insert_val = a[i];
		for (j = i - 1; j >= 0; j--)//遍历有序数的序列
		{
			if (a[j] > insert_val)
			{
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = insert_val;
	}
}

//希尔排序
void shell(int* a)
{
	int i, j, insert_val, gap;
	for (gap = N / 2; gap > 0; gap >>= 1)
	{
		for (i = gap; i < N; i++)//外层控制要拿哪个数去插入
		{
			insert_val = a[i];
			for (j = i - gap; j >= 0 && a[j] > insert_val; j -= gap)//遍历有序数的序列
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = insert_val;
		}
	}
}

//快速排序
int partition(int* a, int left, int right)
{
	int i, k;//以right为分割值
	for (i = k = left; i < right; i++)
	{
		if (a[i] < a[right])
		{
			SWAP(a[i], a[k]);
			k++;
		}
	}
	SWAP(a[k], a[right]);
	return k;
}

void quick(int* a, int left, int right)
{
	int pivot;
	if (left < right)
	{
		pivot = partition(a, left, right);
		quick(a, left, pivot - 1);
		quick(a, pivot + 1, right);
	}
}

//堆排序
//每次调整某棵子树为大根堆
//若堆的根是从0下标开始，左孩子是son = 2 * dad + 1
//若堆的根是从1下标开始，左孩子是son = 2 * dad
void adjustMaxHeap(int* a, int adjustPos, int len)
{
	int dad = adjustPos;
	int son = 2 * dad + 1;//左孩子下标
	while (son < len)//son要小于数组长度，不然找不到孩子会越界
	{
		//先比较左孩子和右孩子，谁大谁就和父亲比较
		if (son + 1 < len && a[son + 1] > a[son])
		{
			son++;
		}
		//拿大的孩子和父亲比较，比父亲大就进行交换
		if (a[son] > a[dad])
		{
			SWAP(a[son], a[dad]);
			//向下调整
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}

void heap(int* a)
{
	int i;
	//从最后一个父结点开始调整为大根堆
	for (i = N / 2 - 1; i >= 0; i--)
	{
		adjustMaxHeap(a, i, N);
	}
	//交换堆顶和尾部元素
	SWAP(a[0], a[N - 1]);
	//将剩余元素调整为大根堆
	for (i = N - 1; i > 1; i--)
	{
		adjustMaxHeap(a, 0, i);
		SWAP(a[0], a[i - 1]);//把顶部元素和最后一个元素交换
	}
}

//归并排序
void merge_arr(int* a, int low, int mid, int high)
{
	int b[N];
	int i, j, k;
	for (i = low; i <= high; i++)//把a都给b
	{
		b[i] = a[i];
	}
	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
	{
		if (b[j] <= b[i])
		{
			a[k] = b[j];
			j++;
		}
		else if (b[i] < b[j])
		{
			a[k] = b[i];
			i++;
		}
	}
	while (i <= mid)
	{
		a[k++] = b[i++];
	}
	while (j <= high)
	{
		a[k++] = b[j++];
	}
}

void merge(int* a, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge(a, low, mid);
		merge(a, mid + 1, high);
		merge_arr(a, low, mid, high);
	}
}

//计数排序
void count(int* a)
{
	int count[M] = { 0 };
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		count[a[i]]++;
	}
	//数回填到a[]
	k = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < count[i]; j++)
		{
			a[k++] = i;
		}
	}
}

//打印排序结果
void print(int* a)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%3d", a[i]);
	}
	putchar('\n');
}