//隐藏控制台
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//基础头文件的引用
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<math.h>
//--------------------

//--------------------
//工程头文件的引用（不要在头文件里随便定义全局变量 避免重定义）
#include".\Headfiles\GraphPage.h"
#include".\Headfiles\loginFunction.h"
#include".\Headfiles\ClientChain.h"
#include".\Headfiles\CommodityChain.h"
#include".\Headfiles\RecordChain.h"
#include".\Headfiles\ChainOpt.h"
#include".\Headfiles\CartChain.h"
//-------------------
 
//-------------------
//登录所用变量声明
int auth = -1;//判定用户身份 初始化为-1
int auth1 = -1;//判定用户退出时的选项 是注销还是退出程序
int auth2 = -1;//判定管理员退出时的选项 是注销还是退出程序
char userCurrentName[50];//此字符串存储当前登录用户的用户名
char adminCurrentName[50];//此字符串存储当前登录管理员的用户名
char tempStr1[50];//用户登录成功的提示字符串
char tempStr2[50];//管理员登录成功的提示字符串
HWND hWnd;//easyx窗口
IMAGE background;
//--------------------

//--------------------
//七个链表的指针
struct RecordNode* recordHead = NULL, * recordTail = NULL;//记录链表
struct ClientNode* clientHead = NULL, * clientTail = NULL;//客户链表
struct CommodityNode* commodityHead = NULL, * commodityTail = NULL;//商品链表
struct CartNode* cartHead = NULL, * cartTail = NULL;//购物车链表
struct userRecordNode* userRecordHead, * userRecordTail;
struct userRecordNode* userRecordHeadT, * userRecordTailT;
struct userRecordNode* userRecordHeadC, * userRecordTailC;
//--------------------

//--------------------
//以下为主函数
int main(void)
{
	backupAll();//程序开始时首先备份全部文件
	buildClientChain(&clientHead, &clientTail);//构建客户链表
	buildCommodityChain(&commodityHead,&commodityTail); //构建商品链表
	buildRecordChain(&recordHead, &recordTail);// 构建记录链表
	initgraph(1000, 1000);//---基础窗口 1000*1000
	loadimage(&background, "picture.png", 1000, 1000);
	//setbkcolor(RGB(243, 230, 0));//---背景颜色
	setbkmode(TRANSPARENT);
	//cleardevice();//---显现背景颜色
	hWnd = GetHWnd();//---获取窗口API
	SetWindowText(hWnd, "酒水批发管理系统用户端");// 使用 Windows API 修改窗口名称
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);//窗口置顶
	MoveWindow(hWnd, 780, 220, 1000, 1040, TRUE);//窗口位置---2k屏幕正中间------------------------------------------------应根据屏幕尺寸做出具体修改
	settextstyle(25, 12, "楷体", 0, 0, 500, 0, 0, 0);  //设置字体长宽 楷书字体
	setorigin(500, 500);//设置原点位置
	Loop://便于注销账户以后重新进入登录界面
	loginPage();//进行登录或注册操作
	if (auth == 0)//用户在登陆注册界面退出
	{
		MessageBox(hWnd, "感谢您的使用 再见", "Jlu_Bar_System_v1.0", MB_OKCANCEL);//提示
		releaseAll();//释放内存
		closegraph();//关闭窗口
		return 0;
	}
	else if (auth == 1)//用户成功登录 进入用户界面
	{
		sprintf_s(tempStr1, "用户:%s", userCurrentName);//为提示字符串赋值
		MessageBox(hWnd, "登录成功", tempStr1, MB_OKCANCEL);//提示
		userPage();//进入用户页面
		if (auth1 == 1)
		{
			MessageBox(hWnd, "感谢您的使用 再见", "Jlu_Bar_System_v1.0", MB_OKCANCEL);//提示
			releaseAll();//释放内存
			closegraph();//关闭窗口
			return 0;
		}
		else
		{
			auth = -1;//判定用户身份 初始化为-1
			auth1 = -1;//初始化用户退出程序的选项
			goto Loop;//跳转到登录
		}
	}
	else//管理员成功登录 进入管理员界面
	{
		sprintf_s(tempStr2, "管理员:%s", adminCurrentName);//为提示字符串赋值
		MessageBox(hWnd, "登录成功", tempStr2, MB_OKCANCEL);//提示
		adminPage();//进入用户页面
		if (auth2 == 1)
		{
			MessageBox(hWnd, "感谢您的使用 再见", "Jlu_Bar_System_v1.0", MB_OKCANCEL);//提示
			releaseAll();//释放内存
			closegraph();//关闭窗口
			return 0;
		}
		else
		{
			auth = -1;//判定用户身份 初始化为-1
			auth2 = -1;//初始化用户退出程序的选项
			goto Loop;//跳转到登录
		}
	}
}
//--------------------