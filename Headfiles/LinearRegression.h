#pragma once
//直线方程为y=k*x+b
#include<stdio.h>//头文件
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<graphics.h>
int R = 255, G = 255, B = 0;
typedef struct zb
{
	double x;
	double y;
	struct zb* next;
}xy;
xy* top;//链表头
xy* rear;//链表尾
double temp1 = 0, temp2 = 0;//中间变量 存 k b
double tmp1 = 0, tmp2 = 0;//中间变量 存 两个点的坐标
int i = 0;
int count = 0;//计数器
double k, b;//直线方程的参数
double x00, y00, x11, y11;//前两个点的横纵坐标
double lr = 0.001;
double kp(double k, double b, xy* top);
double bp(double k, double b, xy* top);
void add_head(double x, double y);
void add_next(double x, double y);
int day;
void xianxing(double *kk,double*bb,int DAY)
{
	R = 0, G = 0, B = 0;
	count = 0;
	FILE* fp;
	day = DAY;
	fopen_s(&fp, ".\\Data\\LinearReggression.txt", "r");
	if (fp)
	{
		for (i=0; i < DAY; i++)
		{
			fscanf_s(fp, "%lf %lf\n", &tmp1, &tmp2);
			if (i == 0)
			{
				add_head(tmp1, tmp2);
			}
			else
			{
				add_next(tmp1, tmp2);
			}
		}
		fclose(fp);
	}
	x00 = top->x;
	y00 = top->y;
	x11 = (top->next)->x;
	y11 = (top->next)->y;
	*kk = (y11 - y00) / (x11 - x00);
	*bb = y00 - *kk * x00;//用取的前两个点的坐标为k b赋初值
	for (; count < 10000; count++)//机器学习 梯度下降法进行线性回归
	{
		temp1 = *kk;
		temp2 = *bb;
		*kk = *kk - (kp(temp1, temp2, top)) * lr;
		*bb = *bb - (bp(temp1, temp2, top)) * lr;//由于机器学习速度对斜率影响太小，故增大影响
		if (G == 255)
		{
			G = 0;
		}
		if (R == 255)
		{
			R = 0;
		}
		if (B == 255)
		{
			B = 0;
		}
		R++;
		G++;
		B++;
		setcolor(RGB(R, G, B));
		line(-390, (-*bb / 5) - 50, (31) * 25 - 390, ((-(*kk * (31) + *bb)) / 5) - 50);
		setlinestyle(PS_SOLID, 1);
		setlinecolor(BLACK);
	}
	xy* ptr;
	ptr = top;
	while (ptr)
	{
		xy* m = ptr;
		ptr = ptr->next;
		free(m);
	}
	top = NULL;
}
double kp(double k, double b, xy* top)//求残差平方和关于k的偏导数
{
	double m, n;
	double sum = 0;
	int i = 0;
	for (; i < day; i++)
	{
		m = top->x;
		n = top->y;
		sum += -1 * (2 * (n - k * m - b) * m);
		top = top->next;
	}
	return sum/day;
}
double bp(double k, double b, xy* top)//求残差平方和关于b的偏导数
{
	double m, n;
	double sum = 0;
	int i = 0;
	for (; i < day; i++)
	{
		m = top->x;
		n = top->y;
		sum += -1 * (2 * (n - k * m - b));
		top = top->next;
	}
	return sum/day;
}
void add_head(double x, double y)
{
	xy* p;
	p = (xy*)malloc(sizeof(xy));
	if (p)
	{
		p->x = x;
		p->y = y;
		p->next = NULL;
		top = p;
		rear = p;
	}
}
void add_next(double x, double y)
{
	xy* p;
	p = (xy*)malloc(sizeof(xy));
	if (p)
	{
		p->x = x;
		p->y = y;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
}