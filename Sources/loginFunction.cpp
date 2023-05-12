#include"..\Headfiles\loginFunction.h"
#include"..\Headfiles\MD5.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\InputCheck.h"
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#include<math.h>

extern struct ClientNode* clientHead;
extern struct ClientNode* clientTail;
extern HWND hWnd;

//--------------------
//以下为登录功能函数
int loginUser(char id[], char pwd[])
{
	FILE* fp;
	char idTmp[50] = { 0 }, pwdTmp[50] = {0};
	int flag = 0;
	char decryptId[50];
	char decryptPwd[50];
	fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "r");
	MD5Function((unsigned char*)id, decryptId);
	MD5Function((unsigned char*)pwd, decryptPwd);
	if (fp!=NULL)
	{
		while (fscanf_s(fp, "%s %s\n", idTmp, 50, pwdTmp, 50) != EOF)
		{ // 循环读取文件中的数据，直到文件末尾
			if (strcmp(decryptId, idTmp) == 0 && strcmp(decryptPwd, pwdTmp) == 0)
			{ // 如果输入的账号和密码与文件中的数据匹配，则设置标志为1，并跳出循环
				flag = 1;
				break;
			}
		}
		fclose(fp);
	}
	fp = NULL;
	if (flag == 1)
	{ 
		return 1;
	}
	else
	{
		return 0;
	}
}
int loginAdmin(char id[], char pwd[])
{
	FILE* fp;
	char idTmp[50] = { 0 }, pwdTmp[50] = { 0 };
	int flag = 0;
	char decryptId[50];
	char decryptPwd[50];
	fopen_s(&fp, ".\\Data\\loginData\\adminData.txt", "r");
	MD5Function((unsigned char*)id, decryptId);
	MD5Function((unsigned char*)pwd, decryptPwd);
	if (fp != NULL)
	{
		while (fscanf_s(fp, "%s %s\n", idTmp, 50, pwdTmp, 50) != EOF)
		{ // 循环读取文件中的数据，直到文件末射1?7
			if (strcmp(decryptId, idTmp) == 0 && strcmp(decryptPwd, pwdTmp) == 0)
			{ // 如果输入的账号和密码与文件中的数据匹配，则设置标志为1，并跳出循环
				flag = 1;
				break;
			}
		}
		fclose(fp);
	}
	fp = NULL;
	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int registerUser(char id[], char pwd1[], char pwd2[],int identify)
{
	int judge = 0;
	judge = strcmp(pwd1, pwd2);
	if (judge != 0)
	{
		return -1;
	}
	FILE* fp;
	char idTmp[50] = { 0 }, pwdTmp[50] = { 0 };
	int flag = 0;
	char decryptId[50];
	char decryptPwd[50];
	fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "r");
	MD5Function((unsigned char*)id, decryptId);
	MD5Function((unsigned char*)pwd1, decryptPwd);
	if (fp != NULL)
	{
		while (fscanf_s(fp, "%s %s\n", idTmp, 50, pwdTmp, 50) != EOF)
		{ // 循环读取文件中的数据，直到文件末射1?7
			if (strcmp(decryptId, idTmp)==0)
			{ // 如果输入的账号和密码与文件中的数据匹配，则设置标志为1，并跳出循环
				flag = 1;
				break;
			}
		}
		fclose(fp);
	}
	fp = NULL;
	if (flag == 1)
	{
		return 0;
	}
	else
	{
		fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "a+");
		if (fp)
		{
			fprintf_s(fp, "%s %s\n", decryptId, decryptPwd);
			fclose(fp);
		}
		fp = NULL;
		char a[50]="0";
		addClient(&clientHead, &clientTail, id, a,identify);
		rebuildClientFile(clientHead);
		return 1;
	}
}
//--------------------