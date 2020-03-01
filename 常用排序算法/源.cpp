#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctime>
void maopao_sort(int* p, int len);//ð�����򣬴Ӵ�С
void choice_sort(int* p, int len);//ѡ�����򣬴Ӵ�С
void Quick_sort(int* p, int L, int H);//�������򣬴Ӵ�С
int find_pos(int* p, int L, int H);
void show(int* p, int len);
int main()
{
	int num[6] = { 1,2,3,4,5,6};
//	maopao_sort(num, sizeof(num) / sizeof(int));
//	choice_sort(num, sizeof(num) / sizeof(int));
	Quick_sort(num, 0,( sizeof(num) / sizeof(int) )- 1);
	show(num, sizeof(num) / sizeof(int));
	return 0;
}
void maopao_sort(int* p, int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (p[i] < p[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
}
void choice_sort(int* p, int len)
{
	int max,index,temp;
	for (int i = 0; i < len - 1; i++)
	{
		max = p[i];
		for (int j = i + 1; j < len; j++)
		{
			if (max < p[j])
			{
				max = p[j];
				index = j;
			}
		}
		if (max != p[i])
		{
			temp = p[index];
			p[index] = p[i];
			p[i] = temp;
		}
	}
}
int find_pos(int* p, int L, int H)
{
	int val = p[L];
	while (L < H)
	{
		while (p[H] <= val&& L < H)
		{
			--H;
		}
		p[L] = p[H];
		while (p[L] >= val&& L < H)
		{
			++L;
		}
		p[H] = p[L];
	}
	p[H] = val;
	return H;
}
void Quick_sort(int* p, int L ,int H)
{
	if (L < H)
	{
		int pos = find_pos(p, L, H);
		Quick_sort(p, L, pos - 1);
		Quick_sort(p, pos + 1, H);
	}

}

void show(int* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\r\n");
}












