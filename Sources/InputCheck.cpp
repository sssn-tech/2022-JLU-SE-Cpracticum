#include <math.h>
#include <string.h>
#include<stdbool.h>
#include "..\Headfiles\InputCheck.h"

#define strnlen_s strnlen

//-------------------
//以下为功能函数
//是否为字符
bool isCharacter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
//是否为整形数字
bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}
//是否全是字符
bool isFullCharacter(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (!isCharacter(str[i]))
			return false;
	return true;
}
//是否全是整型数字
bool isFullDigit(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (!isDigit(str[i]))
			return false;
	return true;
}
//是否为标准输入
bool isStdInput(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (!(isCharacter(str[i]) || isDigit(str[i])))
			return false;
	return true;
}
//大写覆写为小写其余不变
void strToLower(char str[])
{
	// (int)'a' - 'A' = 32
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
}
//字符转为整形
int strToInt(char str[])
{
	int res = 0, L = strlen(str);
	for (int i = 0; i < L; i++)
	{
		res = res * 10 + str[i] - '0';
	}
	return res;
}
//字符转浮点数
double intStrToDouble(char str[])
{
	int res = 0, L = strlen(str);
	for (int i = 0; i < L; i++)
	{
		res = res * 10 + str[i] - '0';
	}
	return res;
}
//是否标准的浮点数
bool isStandardFloat(char str[])
{
	int i = strlen(str);
	int k = 0;

	//处理出现负数的问题
	for (int m = 0; m < i; m++)
	{
		if (str[m] == '-')
			return false;
	}

	if (i > 9)
		return false;
	int j = 0;
	int z = 0;
	if (str[0] == '.' || str[i - 1] == '.')
		return false;
	for (; j < i; j++)
	{
		if (str[j] == '.')
		{
			z++;
			if (z == 1)
			{
				k = j;
			}
		}
	}
	if (z == 1)
	{
		if (k + 3 < i)
			return false;
		else
			return true;
	}
	else {
		return false;
	}
}
//字符转化为浮点数
double strToDouble(char str[])
{
	int i = strlen(str);
	int j = 0;
	int z = 0;
	for (; j < i; j++)
	{
		if (str[j] == '.')
		{
			z = j;
			break;
		}
	}
	double sum = 0;
	j = z - 1;
	double tmp = 1;
	for (; j >= 0; j--)
	{
		sum += (str[j] - '0') * tmp;
		tmp *= 10;
	}
	j = z + 1;
	tmp = 0.1;
	for (; j < i; j++)
	{
		sum += 1.0 * (str[j] - '0') * tmp;
		tmp = tmp * 0.1;
	}
	return sum;
}
//是否为标准的文本
bool isStandardText(char str[])
{
	int len = 0;
	int i = 0;
	len = strnlen_s(str, sizeof(str));
	for (; i < len;i++)
	{
		if (str[i] == ' ')
		{
			return false;
		}
	}
	return true;
}
//--------------------