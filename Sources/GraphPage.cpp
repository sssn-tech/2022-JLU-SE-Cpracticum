#include"..\Headfiles\GraphPage.h"
#include"..\Headfiles\loginFunction.h"
#include"..\Headfiles\RecordChain.h"
#include"..\Headfiles\GetTime.h"
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\ChainOpt.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\CartChain.h"
#include"..\Headfiles\MD5.h"
#include"..\Headfiles\LinearRegression.h"
#include"..\Headfiles\StrSimilar.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<graphics.h>

#define strnlen_s strnlen
#define pi 3.1415926

//--------------------
//等级宏定义
#define zeroToOne0 100
#define oneToTwo0 500
#define twoToThree0 1000
#define threeToFour0 2000
#define fourToFive0 5000
// --------------------

//--------------------
//折扣定义
double discount = 1;
double tempDiscount = 1;
//--------------------

//-------------------
//引用外部变量
extern char userCurrentName[50];
extern char adminCurrentName[50];
extern struct ClientNode* clientHead;
extern struct ClientNode* clientTail;
extern struct CommodityNode* commodityHead;
extern struct CommodityNode* commodityTail;
extern struct CartNode* cartHead;
extern struct CartNode* cartTail;
extern struct RecordNode* recordHead;
extern struct RecordNode* recordTail;
extern struct userRecordNode* userRecordHead;
extern struct userRecordNode* userRecordTail;
extern struct userRecordNode* userRecordHeadT;
extern struct userRecordNode* userRecordTailT;
extern struct userRecordNode* userRecordHeadC;
extern struct userRecordNode* userRecordTailC;
//--------------------

//此为一些中间变量的声明
//------------
//用户登录
char userLoginName[50];
char userLoginNameTmp[50];
char userLoginPwd[50];
char userLoginPwdTmp[50];
//管理员登陆
char adminLoginName[50];
char adminLoginNameTmp[50];
char adminLoginPwd[50];
char adminLoginPwdTmp[50];

//用户注册
char userSignupName[50];
char userSignupNameTmp[50];
char userSignupPwd1[50];
char userSignupPwd1Tmp[50];
char userSignupPwd2[50];
char userSignupPwd2Tmp[50];
char userIdentifyTmp[50];

//杂项
double MMONEY[31];
MOUSEMSG m;//定义鼠标变量 m
extern int auth;//用户身份 源头在main.cpp
extern int auth1;
extern int auth2;
extern HWND hWnd;//窗口api 源头在main.cpp
extern IMAGE background;
//------------

//--------------------
//图像显示
void pict(void)
{
	putimage(-500, -500, &background);
	setbkmode(TRANSPARENT);
}
//--------------------

//--------------------
//显示登陆系统框架
void xian(void)
{
	char temp[50];
	outtextxy(-240, -430, "当前时间:");
	int year, month, day;
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o版本:1.0");
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(40, -400, 40, -440);
}
//backcolor 243 230 0
//--------------------

//--------------------
//显示用户系统框架
void xianuser(void)
{
	int shenfen=0,i=0, year, month, day;
	char discountStr[50],BALANCE[50], LV[50],temp[50],temp1[50];
	struct ClientNode* nowClient = getClientPtrFromName(userCurrentName);
	shenfen = nowClient->isCostumer;
	strcpy_s(temp1, userCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(discountStr, "折扣:%.2lf", discount);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	sprintf_s(BALANCE, "您的余额:%.2lf元", nowClient->balance);
	sprintf_s(LV, "您的等级%d级", nowClient->lv);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-375, 200, -375, 240);
	line(375, 200, 375, 240);
	line(-375, 240, 375, 240);
	line(-250, 200, -250, 240);
	line(250, 200, 250, 240);
	line(250, -480, 250, -440);
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
	outtextxy(-365, -470, "当前用户:");
	outtextxy(-240, -430, "当前时间:");
	outtextxy(260, -470, discountStr);
	outtextxy(-240,210,BALANCE);
	outtextxy(110, 210, LV);
	outtextxy(-245, -470, temp1);
	outtextxy(-120, -430, temp);
	if (shenfen == 0)
	{
		outtextxy(45, -430, "o(^_^)o用户您好");
	}
	else
	{
		outtextxy(45, -430, "o(^_^)o批发商您好");
	}
}
//backcolor 243 230 0
//--------------------

//--------------------
//显示管理员系统框架
void xianadmin(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year=0, month=0, day=0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o管理员你好");
	outtextxy(-240, -430, "当前时间:");
	outtextxy(-365, -470, "当前管理员:");
	outtextxy(-235, -470, temp1);
	for (; i < 640; i=i+20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430  + i, 250, -440  + i);
		line(375, -440  + i , 250, -430 +  i);
	}
}
//backcolor 243 230 0
//--------------------

//--------------------
//显示管理员查看用户页面框架
void xianadminLookUser(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(-230, -340, 230, -340);
	line(-230, -240, 0, -240);
	line(0, -340, 50, -290);
	line(0, -240, 50, -290);
	line(0, -240, 50, -190);
	line(50, -290, 230, -290);
	line(50, -190, 230, -190);
	line(95, -176, 185, -176);
	line(95, -14, 185, -14);
	line(50, -95, 95, -176);
	line(50, -95, 95, -14);
	line(230, -95, 185, -176);
	line(230, -95, 185, -14);
	line(0,0,0,180);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o管理员你好");
	outtextxy(-240, -430, "当前时间:");
	outtextxy(-365, -470, "当前管理员:");
	outtextxy(-235, -470, temp1);
	outtextxy(-220, -370, "用户名:");
	outtextxy(-220, -300, "余额:");
	outtextxy(50, -330,"等级:");
	outtextxy(50,-280,"身份:");
	outtextxy(-210,-40,"解封");
	outtextxy(-110, -40, "封禁");
	outtextxy(115,-85,"封禁");
	outtextxy(-210, 50, "上");
	outtextxy(-210, 90, "一");
	outtextxy(-210, 130, "个");
	outtextxy(-140, 50, "下");
	outtextxy(-140, 90, "一");
	outtextxy(-140, 130, "个");
	outtextxy(-70, 20, "删");
	outtextxy(-70, 60, "除");
	outtextxy(-70, 100, "这");
	outtextxy(-70, 140, "个");
	outtextxy(45, 20, "增");
	outtextxy(45, 60, "加");
	outtextxy(45, 100, "一");
	outtextxy(45, 140, "个");
	outtextxy(115, 20, "查");
	outtextxy(115, 60, "看");
	outtextxy(115, 100, "记");
	outtextxy(115, 140, "录");
	outtextxy(185, 90, "返");
	outtextxy(185, 130, "回");
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------

//--------------------
//显示管理员查看用户页面框架
void xianadminLookUserG(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(-230, -340, 230, -340);
	line(-230, -240, 0, -240);
	line(0, -340, 50, -290);
	line(0, -240, 50, -290);
	line(0, -240, 50, -190);
	line(50, -290, 230, -290);
	line(50, -190, 230, -190);
	line(95, -176, 185, -176);
	line(95, -14, 185, -14);
	line(50, -95, 95, -176);
	line(50, -95, 95, -14);
	line(230, -95, 185, -176);
	line(230, -95, 185, -14);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o管理员你好");
	outtextxy(-240, -430, "当前时间:");
	outtextxy(-365, -470, "当前管理员:");
	outtextxy(-235, -470, temp1);
	outtextxy(-220, -370, "用户名:");
	outtextxy(-220, -300, "余额:");
	outtextxy(50, -330, "等级:");
	outtextxy(50, -280, "身份:");
	outtextxy(115, -85, "封禁");
	outtextxy(-25, 90, "返回");
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------


//--------------------
//显示管理员查看商品页面框架
void xianadminLookCommodity(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(0, 0, 0, 180);
	line(-230, -300, 100, -300);
	line(100, -300, 230, -380);
	line(100, -300, 100, -260);
	line(100, -260, 230, -260);
	line(-230, -220, 50, -220);
	line(50, -220, 100, -260);
	line(50, -220, 230, 0);
	line(50, -220, 50, 0);
	line(-110, -110, -10, -110);
	circle(-110,-110, 100);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o管理员你好");
	outtextxy(-240, -430, "当前时间:");
	outtextxy(-365, -470, "当前管理员:");
	outtextxy(-235, -470, temp1);
	outtextxy(-210, 50, "上");
	outtextxy(-210, 90, "一");
	outtextxy(-210, 130, "个");
	outtextxy(-140, 50, "下");
	outtextxy(-140, 90, "一");
	outtextxy(-140, 130, "个");
	outtextxy(-70, 20, "删");
	outtextxy(-70, 60, "除");
	outtextxy(-70, 100, "这");
	outtextxy(-70, 140, "个");
	outtextxy(45, 20, "增");
	outtextxy(45, 60, "加");
	outtextxy(45, 100, "一");
	outtextxy(45, 140, "个");
	outtextxy(115, 20, "查");
	outtextxy(115, 60, "看");
	outtextxy(115, 100, "记");
	outtextxy(115, 140, "录");
	outtextxy(185, 90, "返");
	outtextxy(185, 130, "回");
	outtextxy(120, -290, "进货");
	outtextxy(-220,-350,"商品名称:");
	outtextxy(-220, -270, "剩余量:");
	outtextxy(80,-210,"售价:");
	outtextxy(60, -130, "进");
	outtextxy(60,-90,"价");

	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------

//--------------------
//显示管理员查看商品页面框架
void xianadminLookCommodityG(void)
{
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(-230, -300, 100, -300);
	line(100, -300, 230, -380);
	line(100, -300, 100, -260);
	line(100, -260, 230, -260);
	line(-230, -220, 50, -220);
	line(50, -220, 100, -260);
	line(50, -220, 230, 0);
	line(50, -220, 50, 0);
	line(-110, -110, -10, -110);
	circle(-110, -110, 100);
	outtextxy(-120, -430, temp);
	outtextxy(45, -430, "o(^_^)o管理员你好");
	outtextxy(-240, -430, "当前时间:");
	outtextxy(-365, -470, "当前管理员:");
	outtextxy(-235, -470, temp1);
	outtextxy(-220, -350, "商品名称:");
	outtextxy(-220, -270, "剩余量:");
	outtextxy(80, -210, "售价:");
	outtextxy(60, -130, "进");
	outtextxy(60, -90, "价");
	outtextxy(-25, 90, "返回");
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------


//--------------------
//显示管理员查看记录的页面框架
void xianadminLookRecord(void)
{
	
	int i = 0;
	char temp[50];
	char temp1[50];
	int year = 0, month = 0, day = 0;
	strcpy_s(temp1, adminCurrentName);
	getCurrentTime(&year, &month, &day);
	sprintf_s(temp, "%d年%d月%d日", year, month, day);
	line(52, -200,230, -200);
	line(-250, -400, 250, -400);
	line(-250, 200, 250, 200);
	line(-250, -400, -250, 200);
	line(250, -400, 250, 200);
	line(-230, -380, 230, -380);
	line(-230, 180, 230, 180);
	line(-230, -380, -230, 180);
	line(230, -380, 230, 180);
	line(-250, -400, -230, -380);
	line(250, -400, 230, -380);
	line(-250, 200, -230, 180);
	line(250, 200, 230, 180);
	line(-250, -440, 250, -440);
	line(-250, -440, -250, -400);
	line(250, -440, 250, -400);
	line(-375, -480, 375, -480);
	line(-375, -480, -375, -440);
	line(375, -480, 375, -440);
	line(-375, -440, -250, -440);
	line(375, -440, 250, -440);
	line(-375, -440, -375, 200);
	line(375, -440, 375, 200);
	line(-375, 200, -250, 200);
	line(375, 200, 250, 200);
	line(40, -400, 40, -440);
	line(-230, 0, 230, 0);
	line(0, 0, 0, 180);
	line(-230, -340, 230, -340);
	line(50, -380, 50, -340);
	line(-230, -260, 50, -260);
	line(50, -340, 50, -260);
	line(50, -300, 230, -300);
	line(50, -260, 80, -240);
	line(80, -240, 230, -240);
	line(-230, -130, 0, -130);
	line(0, -130, 80, -240);
	line(0, -130, 0, 0);
	line(0, -130, 230, -130);
	outtextxy(-120, -430, temp);
	outtextxy(-220, -370, "用户名:");
	outtextxy(60,-370,"历史等级:");
	outtextxy(-140, -330, "商品名称:");
	outtextxy(60,-330,"进价:");
	outtextxy(60,-280,"售价:");
	outtextxy(-140, -250, "购买数量:");
	outtextxy(-220, -120, "状态:");
	outtextxy(80,-230,"折后:");
	outtextxy(80, -190, "身份:");
	outtextxy(10,-120,"交易时间:");
	outtextxy(-210, 50, "上");
	outtextxy(-210, 90, "一");
	outtextxy(-210, 130, "个");
	outtextxy(-140, 50, "下");
	outtextxy(-140, 90, "一");
	outtextxy(-140, 130, "个");
	outtextxy(-70, 20, "删");
	outtextxy(-70, 60, "除");
	outtextxy(-70, 100, "这");
	outtextxy(-70, 140, "个");
	outtextxy(45, 20, "查");
	outtextxy(45, 60, "看");
	outtextxy(45, 100, "用");
	outtextxy(45, 140, "户");
	outtextxy(115, 20, "查");
	outtextxy(115, 60, "看");
	outtextxy(115, 100, "商");
	outtextxy(115, 140, "品");
	outtextxy(185, 90, "返");
	outtextxy(185, 130, "回");
	outtextxy(45, -430, "o(^_^)o管理员你好");
	outtextxy(-240, -430, "当前时间:");
	outtextxy(-365, -470, "当前管理员:");
	outtextxy(-235, -470, temp1);
	for (; i < 640; i = i + 20)
	{
		line(-375, -440 + i, -250, -430 + i);
		line(-375, -430 + i, -250, -440 + i);
		line(375, -430 + i, 250, -440 + i);
		line(375, -440 + i, 250, -430 + i);
	}
}
//--------------------

//--------------------
//显示管理员总览的页面框架
void xianzonglan(void)
{
	rectangle(-450, -450, 450, 450);
	rectangle(-400, -400, 400, 300);
}
//--------------------

//--------------------
//登录系统页面
void loginPage(void)
{
	char usernameTmpcpy[50];
	memset(usernameTmpcpy, 0, sizeof(usernameTmpcpy));
	int situation1=0;//状态---用户登录
	int situation2 = 0;//状态---管理员登陆
	int situation3 = 0;//状态---用户注册
	int identify = 0;
	int count = 0;//单个用户输入计数器

	//--------------------
	// 字符串中间变量的声明
	int user_1=0, user_2=0;
	int _user_1 = 0, _user_2 = 0;
	int admin_1 = 0, admin_2 = 0;
	int _admin_1 = 0, _admin_2 = 0;
	int userl_1 = 0,userl_2=0, userl_3=0;
	int _userl_1 = 0, _userl_2 = 0, _userl_3 = 0;
	int _len_ = 0;
	//--------------------
	//以下为页面一
	pict();
	while (TRUE)
	{
		/*此为开始的登陆界面*/
		setcolor(BLACK);    //设置字体颜色
		xian();//登陆界面框架
		outtextxy(-100, -300, "吉大酒吧管理系统");
		outtextxy(-50, -200, "用户登录");
		outtextxy(-62.5, -100, "管理员登录");
		outtextxy(-50, 0, "用户注册");
		outtextxy(-25, 100, "退出");
		rectangle(-110, -310, 110, -270);//---外方框
		rectangle(-120, -320, 120, -260);
		m = GetMouseMsg();//--在循环内获取鼠标
		//鼠标移动到用户登录
		if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(-60, -210, 60, -170);
			//鼠标点击用户登录
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				count = 0;
				user_1 = 0, user_2 = 0;
				_user_1 = 0, _user_2 = 0;
				memset(usernameTmpcpy, 0, sizeof(usernameTmpcpy));
				memset(userCurrentName, 0, sizeof(userCurrentName));
				memset(userLoginName, 0, sizeof(userLoginName));
				memset(userLoginNameTmp, 0, sizeof(userLoginNameTmp));
				memset(userLoginPwd, 0, sizeof(userLoginPwd));
				memset(userLoginPwdTmp, 0, sizeof(userLoginPwdTmp));
				cleardevice(); pict();                                                                            //----------------------------用户登录
				//页面二（1）
				while (TRUE)
				{
					setcolor(BLACK);
					xian();
					outtextxy(-100, -300, "吉大酒吧管理系统");
					outtextxy(130, -300, "(用户)");
					outtextxy(-50, -200, "输入账号");
					outtextxy(-62.5, -100, "请输入密码");
					outtextxy(-50, 0, "尝试登录");
					outtextxy(-25, 100, "返回");
					rectangle(-110, -310, 110, -270);
					rectangle(-120, -320, 120, -260);
					//判空
					if (user_1 != 0)
					{
						outtextxy(150, -200, "_/");
					}
					//判空
					if (user_2 != 0)
					{
						outtextxy(150, -100, "_/");
					}
					m = GetMouseMsg();
					//鼠标移动到输入账号
					if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
					{
						setlinecolor(BLACK);
						rectangle(-60, -210, 60, -170);
						//鼠标点击输入账号
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userLoginNameTmp, 50, "请写入用户账号（40位以内,且只包含字符和数字）",NULL, NULL, 0, 0, false);
							_user_1 = strnlen(userLoginNameTmp,sizeof(userLoginNameTmp));
							if (isStdInput(userLoginNameTmp)&&_user_1<=40)
							{
								strcpy_s(userLoginName, userLoginNameTmp);
								user_1 = strnlen_s(userLoginName, sizeof(userLoginName));
								if (strcmp(usernameTmpcpy, userLoginName) == 0)
								{
									;
								}
								else
								{
									count = 0;
									strcpy_s(usernameTmpcpy, userLoginName);
								}
							}
							else
							{
								MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
							}
						}
					}
                    //鼠标移动到输入密码
					else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
					{
						setlinecolor(BLACK);
						rectangle(-72.5, -110, 72.5, -70);
						//鼠标点击输入密码
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (getClientPtrFromName(userLoginName)==NULL)
							{
								InputBox(userLoginPwdTmp, 50, "请写入用户密码（40位以内，且只包含字符和数字）",NULL, NULL, 0, 0, false);
								_user_2 = strnlen(userLoginPwdTmp, sizeof(userLoginPwdTmp));
								if (isStdInput(userLoginPwdTmp) && _user_2 <= 40)
								{
									strcpy_s(userLoginPwd, userLoginPwdTmp);
									user_2 = strnlen_s(userLoginPwd, sizeof(userLoginPwd));
								}
								else
								{
									MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
								}
							}
							else
							{
								if (getClientPtrFromName(userLoginName)->situation == 1)
								{
									MessageBox(hWnd, "抱歉,您已被封禁,请拨打13894980185联系管理员以解封", " ", MB_OKCANCEL);
								}
								else
								{
									InputBox(userLoginPwdTmp, 50, "请写入用户密码（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
									_user_2 = strnlen(userLoginPwdTmp, sizeof(userLoginPwdTmp));
									if (isStdInput(userLoginPwdTmp) && _user_2 <= 40)
									{
										strcpy_s(userLoginPwd, userLoginPwdTmp);
										user_2 = strnlen_s(userLoginPwd, sizeof(userLoginPwd));
									}
									else
									{
										MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
									}
								}
							}
						}
					}
					//鼠标移动到尝试登录
					else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
					{
						setlinecolor(BLACK);
						rectangle(-60, -10, 60, 30);
						//鼠标点击尝试登陆
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							//判空
							if (user_1 == 0 && user_2 != 0)
							{
								MessageBox(hWnd, "请输入用户账号", " ", MB_OKCANCEL);
							}
							//判空
							else if (user_1 != 0 && user_2 == 0)
							{
								MessageBox(hWnd, "请输入用户密码", " ", MB_OKCANCEL);
							}
							//判空
							else if (user_1 == 0 && user_2 == 0)
							{
								MessageBox(hWnd, "请输入用户账号和密码", " ", MB_OKCANCEL);
							}
							//正式操作
							else
							{
								if (getClientPtrFromName(userLoginName)==NULL)
								{
									situation1 = loginUser(userLoginName, userLoginPwd);
									if (situation1 == 1)
									{
										auth = 1;
										strcpy_s(userCurrentName, userLoginName);
										break;
									}
									else
									{
										count++;
										MessageBox(hWnd, "用户账号或密码错误", " ", MB_OKCANCEL);
									}
								}
								else
								{
									if (getClientPtrFromName(userLoginName)->situation == 1)
									{
										MessageBox(hWnd, "抱歉,您已被封禁,请拨打13894980185联系管理员解封", " ", MB_OKCANCEL);
									}
									else if ((getClientPtrFromName(userLoginName)->situation == 0) && count >= 5)
									{
										getClientPtrFromName(userLoginName)->situation = 1;
										rebuildClientFile(clientHead);
										MessageBox(hWnd, "抱歉,由于操作频繁，您已被封禁，请拨打13894980185联系管理员解封", " ", MB_OKCANCEL);
									}
									else
									{
										situation1 = loginUser(userLoginName, userLoginPwd);
										if (situation1 == 1)
										{
											auth = 1;
											strcpy_s(userCurrentName, userLoginName);
											break;
										}
										else
										{
											count++;
											MessageBox(hWnd, "用户账号或密码错误", " ", MB_OKCANCEL);
										}
									}
								}
							}
						}
					}
					//鼠标移动到返回
					else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
					{
						setlinecolor(BLACK);
						rectangle(-35, 90, 35, 130);
						//鼠标点击返回
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					//鼠标移动到方框外
					else
					{
						setlinecolor(WHITE);
						rectangle(-60, -210, 60, -170);
						rectangle(-72.5, -110, 72.5, -70);
						rectangle(-60, -10, 60, 30);
						rectangle(-35, 90, 35, 130);
					}

				}
			}
		}
		//鼠标移动到管理员登录
		else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(-72.5, -110, 72.5, -70);
			//鼠标点击管理员登录
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				admin_1 = 0, admin_2 = 0;
				memset(adminCurrentName, 0, sizeof(adminCurrentName));
				memset(adminLoginName, 0, sizeof(adminLoginName));
				memset(adminLoginNameTmp, 0, sizeof(adminLoginNameTmp));
				memset(adminLoginPwd, 0, sizeof(adminLoginPwd));
				memset(adminLoginPwdTmp, 0, sizeof(adminLoginPwdTmp));
				cleardevice(); pict();                                                                            //----------------------------管理员登录
				//页面二（2）
				while (TRUE)
				{
					setcolor(BLACK);
					xian();
					outtextxy(-100, -300, "吉大酒吧管理系统");
					outtextxy(130, -300, "(管理员)");
					rectangle(-110, -310, 110, -270);
					rectangle(-120, -320, 120, -260);
					outtextxy(-50, -200, "输入账号");
					outtextxy(-62.5, -100, "请输入密码"); 
					outtextxy(-50, 0, "尝试登录");
					outtextxy(-25, 100, "返回");
					//判空
					if (admin_1 != 0)
					{
						outtextxy(150, -200, "_/");
					}
					//判空
					if (admin_2 != 0)
					{
						outtextxy(150, -100, "_/");
					}
					m = GetMouseMsg();
					//鼠标移动到输入管理员账号
					if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
					{
						setlinecolor(BLACK);
						rectangle(-60, -210, 60, -170);
						//鼠标点击输入管理员账号
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(adminLoginNameTmp, 50, "请写入管理员账号（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
							_admin_1 = strnlen(adminLoginNameTmp, sizeof(adminLoginNameTmp));
							if (isStdInput(adminLoginNameTmp)&&_admin_1<=40)
							{
								strcpy_s(adminLoginName, adminLoginNameTmp);
								admin_1 = strnlen_s(adminLoginName, sizeof(adminLoginName));
							}
							else
							{
								MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
							}
						}
					}
					//鼠标移动到输入管理员密码
					else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
					{
						setlinecolor(BLACK);
						rectangle(-72.5, -110, 72.5, -70);
						//鼠标点击输入管理员密码
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(adminLoginPwdTmp, 50, "请写入管理员密码（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
							_admin_2 = strnlen(adminLoginPwdTmp, sizeof(adminLoginPwdTmp));
							if (isStdInput(adminLoginPwdTmp)&&_admin_2<=40)
							{
								strcpy_s(adminLoginPwd, adminLoginPwdTmp);
								admin_2 = strnlen_s(adminLoginPwd, sizeof(adminLoginPwd));
							}
							else
							{
								MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
							}
						}
					}
					//鼠标移动到尝试登陆
					else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
					{
						setlinecolor(BLACK);
						rectangle(-60, -10, 60, 30);
						//鼠标点击尝试登录
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							//判空
							if (admin_1==0&&admin_2!=0)
							{
								MessageBox(hWnd, "请输入管理员账号", " ", MB_OKCANCEL);
							}
							//判空
							else if (admin_1 != 0 && admin_2 == 0)
							{
								MessageBox(hWnd, "请输入管理员密码", " ", MB_OKCANCEL);
							}
							//判空
							else if (admin_1 == 0 && admin_2 == 0)
							{
								MessageBox(hWnd, "请输入管理员账号和密码", " ", MB_OKCANCEL);
							}
							//正式操作
							else
							{
								situation2 = loginAdmin(adminLoginName, adminLoginPwd);
								if (situation2 == 1)
								{
									auth = 2;
									strcpy_s(adminCurrentName, adminLoginName);
									break;
								}
								else
								{
									MessageBox(hWnd, "管理员账号或密码错误", " ", MB_OKCANCEL);
								}
							}
						}
					}
					//鼠标移动到返回
					else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
					{
						setlinecolor(BLACK);
						rectangle(-35, 90, 35, 130);
						//鼠标点击返回
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					//鼠标移动到方框外
					else
					{
						setlinecolor(WHITE);
						rectangle(-60, -210, 60, -170);
						rectangle(-72.5, -110, 72.5, -70);
						rectangle(-60, -10, 60, 30);
						rectangle(-35, 90, 35, 130);
					}

				}
			}
		}
        //鼠标移动到用户注册
		else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(-60, -10, 60, 30);
			//鼠标点击到用户注册
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				userl_1 = 0;
				userl_2 = 0;
				userl_3 = 0;//长度初始化
				identify = 0;
				_len_ = 0;
				memset(userSignupName, 0, sizeof(userSignupName));//令字符串皆为空
				memset(userSignupNameTmp, 0, sizeof(userSignupNameTmp));
				memset(userSignupPwd1, 0, sizeof(userSignupPwd1));
				memset(userSignupPwd1Tmp, 0, sizeof(userSignupPwd1Tmp));
				memset(userSignupPwd2, 0, sizeof(userSignupPwd2));
				memset(userSignupPwd2Tmp, 0, sizeof(userSignupPwd2Tmp));
				memset(userIdentifyTmp,0, sizeof(userIdentifyTmp));
				cleardevice(); pict();//清除上一级屏幕内容                                                                                 //----------------------------用户注册
				//页面二（3）
				while (TRUE)
				{
					setcolor(BLACK);
					xian();
					outtextxy(-100, -300, "输入你喜欢的账号");
					outtextxy(-50, -200, "输入密码");
					outtextxy(-62.5, -100, "再输入密码");
					outtextxy(-50, 0, "提交注册");
					outtextxy(-25, 100, "返回");
					//判空操作
					if (userl_1 != 0)
					{
						outtextxy(150,-300,"_/");
					}
					//判空操作
					if (userl_2 != 0)
					{
						outtextxy(150, -200, "_/");
					}
					//判空操作
					if (userl_3 != 0)
					{
						outtextxy(150, -100, "_/");
					}
					m = GetMouseMsg();
					//鼠标移动到---输入你喜欢的账号
					if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
					{
						setlinecolor(BLACK);
						rectangle(-110, -310, 110, -270);
						//鼠标点击---输入你喜欢的账号
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userSignupNameTmp, 50, "请写入你喜欢的账号（14位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
							_userl_1 = strnlen_s(userSignupNameTmp,sizeof(userSignupNameTmp));
							if ((isStdInput(userSignupNameTmp)&&_userl_1<=14)||_userl_1==0)
							{
								strcpy_s(userSignupName, userSignupNameTmp);
								userl_1 = strnlen_s(userSignupName, sizeof(userSignupName));
							}
							else
							{
								MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
							}
						}
					}
					//鼠标移动到---输入密码
					else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
					{
						setlinecolor(BLACK);
						rectangle(-60, -210, 60, -170);
						//鼠标点击---输入密码
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userSignupPwd1Tmp, 50, "请写入密码（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
							_userl_2 = strnlen_s(userSignupPwd1Tmp, sizeof(userSignupPwd1Tmp));
							if (isStdInput(userSignupPwd1Tmp)&&_userl_2<=40)
							{
								strcpy_s(userSignupPwd1, userSignupPwd1Tmp);
								userl_2 = strnlen_s(userSignupPwd1, sizeof(userSignupPwd1));
							}
							else
							{
								MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
							}
						}
					}
					//鼠标移动到再次输入密码
					else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
					{
						setlinecolor(BLACK);
						rectangle(-72.5, -110, 72.5, -70);
						//鼠标点击再次输入密码
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							InputBox(userSignupPwd2Tmp, 50, "请再次写入密码（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
							_userl_3 = strnlen_s(userSignupPwd2Tmp, sizeof(userSignupPwd2Tmp));
							if (isStdInput(userSignupPwd2Tmp)&&_userl_3<=40)
							{
								strcpy_s(userSignupPwd2, userSignupPwd2Tmp);
								userl_3 = strnlen_s(userSignupPwd2, sizeof(userSignupPwd2));
							}
							else
							{
								MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
							}
						}
					}
					//鼠标移动到提交注册
					else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
					{
						setlinecolor(BLACK);
						rectangle(-60, -10, 60, 30);
						//鼠标点击提交注册
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							//判空
							if (userl_1 != 0 && userl_2 == 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "请输入两次用户密码", " ", MB_OKCANCEL);
							}
							//判空
							else if (userl_1 == 0 && userl_2 != 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "请输入账号并再次输入密码", " ", MB_OKCANCEL);
							}//判空
							//判空
							else if (userl_1 == 0 && userl_2 == 0 && userl_3 != 0)
							{
								MessageBox(hWnd, "请输入账号和密码", " ", MB_OKCANCEL);
							}
							//判空
							else if (userl_1 == 0 && userl_2 != 0 && userl_3 != 0)
							{
								MessageBox(hWnd, "请输入账号", " ", MB_OKCANCEL);
							}
							//判空
							else if (userl_1 != 0 && userl_2 == 0 && userl_3 != 0)
							{
								MessageBox(hWnd, "请输入密码", " ", MB_OKCANCEL);
							}
							//判空
							else if (userl_1 != 0 && userl_2 != 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "请再次输入密码", " ", MB_OKCANCEL);
							}
							//判空
							else if (userl_1 == 0 && userl_2 == 0 && userl_3 == 0)
							{
								MessageBox(hWnd, "请输入账号并输入两次密码", " ", MB_OKCANCEL);
							}
							//正式操作
							else 
							{
								if (MessageBox(hWnd, "是否成为批发商?\n点击取消变成普通用户\n注意，批发商的每单最低交易额为100", "", MB_OKCANCEL) == IDOK)
								{
									identify = 1;
								}
								else
								{
									identify = 0;
								}
								situation3 = registerUser(userSignupName, userSignupPwd1, userSignupPwd2,identify);
								if (situation3 == -1)
								{
									MessageBox(hWnd, "两次输入密码不一致，请重试", " ", MB_OKCANCEL);
								}
								else if (situation3 == 0)
								{
									MessageBox(hWnd, "用户已存在，请重新输入账号", " ", MB_OKCANCEL);
								}
								else
								{
									cleardevice(); pict();
									MessageBox(hWnd, "注册成功，请登录", " ", MB_OKCANCEL);
									break;
								}
							}
						}
					}
					//鼠标移动到返回
					else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
					{
						setlinecolor(BLACK);
						rectangle(-35, 90, 35, 130);
						//鼠标点击返回
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					//鼠标移动到方框之外
					else
					{
						setlinecolor(WHITE);
						rectangle(-60, -210, 60, -170);
						rectangle(-72.5, -110, 72.5, -70);
						rectangle(-60, -10, 60, 30);
						rectangle(-35, 90, 35, 130);
						rectangle(-110, -310, 110, -270);
					}
				}
			}
		}
		//鼠标移动到退出
		else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-35, 90, 35, 130);
			//鼠标点击退出
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				/*
				MessageBox(hWnd, "感谢您的使用 再见", " ", MB_OKCANCEL);
				*/
				auth = 0;
			}
		}
		//鼠标移动到方框外
		else
		{
			setlinecolor(WHITE);
			rectangle(-60, -210, 60, -170);
			rectangle(-72.5, -110, 72.5, -70);
			rectangle(-60, -10, 60, 30);
			rectangle(-35, 90, 35, 130);
		}
		//以下为退出条件---用户身份开始有正常值
		if (auth == 0||auth==1||auth==2)
		{
			cleardevice(); pict();
			break;
		}
	}                         
}
//--------------------

//--------------------
//用户系统页面
void userPage(void)
{
	buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
	char ttemp[50], TempStr1[50], TempStr2[50], TempStr3[50], TempStr1_[50], TempStr2_[50], TempStr3_[50], targetMd5[50], originMd5[50], finalMd5[50], levelStandard[50], commodityName[50], chooseNumber[50], commodityName_[50], money[50], userCommodityName[50], TempStr1__[50], TempStr2__[50], TempStr3__[50], pwdTmp[50], changePwd[50], userNameMd5[50], idTmp_[50] = { 0 }, pwdTmp_[50] = { 0 }, userCurrentName_[50],tmpptr[50],userText[220];
	double tempNumSum = 0,soldPrice=0,soldPriceOrigin = 0,soldPriceDiscount = 0, userOriginMoneyTmp = 0, userFinalMoneyTmp = 0;
	int flag = 1,tempNumber1 = 0, tempNumber2 = 0, tempNumber3 = 0,_lengh_ = 0,_level_ = 0,count = 0,tempLevel = 0,unitCount,unitCount_ = 0,_chooseNumber_ = 0,yearTmp=0,monthTmp=0,dayTmp=0,userBuyNumber=0,pwdLen=0,fflag=0,lenText=0,year__=0,month__=0,day__=0;
	struct ClientNode* nowClient = getClientPtrFromName(userCurrentName);
	struct CartNode* temp=NULL;
	struct CartNode* qingkong = NULL;
	struct CommodityNode* tempCommodityPtr=NULL;
	struct CommodityNode* tempPtr = NULL;
	struct CartNode* tempPtr_ = NULL;
	struct userRecordNode* tempPtr__;
	tempPtr = commodityHead;
	cartHead = NULL;
	cartTail = NULL;
	discount = 1;
	if (nowClient->isCostumer == 0)
	{
		if (nowClient->lv == 0)
		{
			discount = 1;
		}
		else if (nowClient->lv == 1)
		{
			discount = 0.95;
		}
		else if (nowClient->lv == 2)
		{
			discount = 0.9;
		}
		else if (nowClient->lv == 3)
		{
			discount = 0.85;
		}
		else if (nowClient->lv == 4)
		{
			discount = 0.8;
		}
		else
		{
			discount = 0.75;
		}
	}
	else
	{
		if (nowClient->lv == 0)
		{
			discount = 1;
		}
		else if (nowClient->lv == 1)
		{
			discount = 0.9;
		}
		else if (nowClient->lv == 2)
		{
			discount = 0.85;
		}
		else if (nowClient->lv == 3)
		{
			discount = 0.8;
		}
		else if (nowClient->lv == 4)
		{
			discount = 0.75;
		}
		else
		{
			discount = 0.7;
		}
	}
	while (TRUE)
	{
		setcolor(BLACK);
		xianuser();
		outtextxy(-100, -300, "查看所有在售商品");
		outtextxy(-50, -200, "购物历史");
		outtextxy(-62.5, -100, "查看购物车");
		outtextxy(-50, 0, "注销账户");
		outtextxy(-25, 100, "退出");
		outtextxy(-340, 210, "充值");
		outtextxy(290, 210, "升级");
		outtextxy(110, 100, "修改密码");
		outtextxy(-210, 100, "提交工单");
		//鼠标移动到---查看所有在售商品
		m = GetMouseMsg();//--在循环内获取鼠标
		if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
		{
			setlinecolor(BLACK);
			rectangle(-110, -310, 110, -270);
			//鼠标点击---查看所有在售商品
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				tempPtr = commodityHead;
				memset(chooseNumber, 0, sizeof(chooseNumber));
				_chooseNumber_ = 0;
				if (tempPtr == NULL)
				{
					MessageBox(hWnd, "暂无商品在售,我们深感抱歉", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						setcolor(BLACK);
						xianuser();
						strcpy_s(commodityName, tempPtr->commodityName);
						soldPrice = tempPtr->soldPrice;
						unitCount = tempPtr->unitCount;
						if (unitCount <= 0)
						{
							strcpy_s(TempStr3, "商品属于缺货状态");
						}
						else
						{
							sprintf_s(TempStr3, "商品剩余:%d个", unitCount);
						}
						sprintf_s(TempStr1, "商品名称:%s",commodityName);
						sprintf_s(TempStr2, "商品价格:%.2lf元", soldPrice);
						outtextxy(-100, -300,TempStr1);
						outtextxy(-100, -200, TempStr2);
						outtextxy(-100, -100, TempStr3);
						outtextxy(-200, 30, "上一个商品");
						outtextxy(-200, 90, "加入到购物车");
						outtextxy(50, 30, "下一个商品");
						outtextxy(50, 90, "返回到主页");
						line(-230, 0, 230, 0);
						m = GetMouseMsg();//--在循环内获取鼠标
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr->preCommodity == NULL)
								{
									MessageBox(hWnd, "这是第一个商品", " ", MB_OKCANCEL);
								}
								else
								{
									tempPtr = tempPtr->preCommodity;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								InputBox(chooseNumber, 50, "请输入你想要的商品数量，单次交易数量不超过10000", NULL, NULL, 0, 0, false);
								_chooseNumber_ = strnlen(chooseNumber, sizeof(chooseNumber));
								if (_chooseNumber_ == 0)
								{
									;
								}
								else
								{
									if (isFullDigit(chooseNumber) && _chooseNumber_ <= 5 && _chooseNumber_ > 0 && isStdInput(chooseNumber) && strToInt(chooseNumber) <= 10000 && strToInt(chooseNumber) > 0)
									{
										if (strToInt(chooseNumber) > unitCount)
										{
											MessageBox(hWnd, "超过了商品总数,请重新输入", " ", MB_OKCANCEL);
										}
										else
										{
											if (nowClient->isCostumer == 0)
											{
												addCart(&cartHead, &cartTail, tempPtr->soldPrice, strToInt(chooseNumber), tempPtr->commodityName,nowClient->lv);
												MessageBox(hWnd, "成功加入购物车", " ", MB_OKCANCEL);
												cleardevice(); pict();
												putimage(-500, -500, &background);
												setbkmode(TRANSPARENT);
											}
											else
											{
												if (strToInt(chooseNumber) <100)
												{
													MessageBox(hWnd, "批发商购买数额不得低于100", " ", MB_OKCANCEL);
												}
												else
												{
													addCart(&cartHead, &cartTail, tempPtr->soldPrice, strToInt(chooseNumber), tempPtr->commodityName,nowClient->lv);
													MessageBox(hWnd, "成功加入购物车", " ", MB_OKCANCEL);
													cleardevice(); pict();
												}
											}
										}
									}
									else
									{
										MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
									}
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr->nextCommodity == NULL)
								{
									MessageBox(hWnd, "这是最后一个商品", " ", MB_OKCANCEL);
								}

								else
								{
									tempPtr = tempPtr->nextCommodity;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}
			}
		}
		//鼠标移动到---购物历史
		else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(-60, -210, 60, -170);
			//鼠标点击---购物历史
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				tempPtr__ = userRecordHead;
				yearTmp = 0;
				monthTmp = 0;
				dayTmp = 0;
				userOriginMoneyTmp = 0;
				userFinalMoneyTmp = 0;
				userBuyNumber = 0;
				memset(userCommodityName, 0, sizeof(userCommodityName));
				memset(TempStr1__, 0, sizeof(TempStr1__));
				memset(TempStr1__, 0, sizeof(TempStr1__));
				memset(TempStr1__, 0, sizeof(TempStr1__));
			    LLLoop:
				if (tempPtr__==NULL)
				{
					MessageBox(hWnd, "暂无购物记录", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						setcolor(BLACK);
						xianuser();
						yearTmp = tempPtr__->ptr->year;
						monthTmp = tempPtr__->ptr->month;
						dayTmp = tempPtr__->ptr->day;
						userOriginMoneyTmp = tempPtr__->ptr->soldPrice;
						if (nowClient->isCostumer == 0)
						{
							if (tempPtr__->ptr->historyLv == 0)
							{
								tempDiscount = 1;
							}
							else if (tempPtr__->ptr->historyLv == 1)
							{
								tempDiscount = 0.95;
							}
							else if (tempPtr__->ptr->historyLv == 2)
							{
								tempDiscount = 0.9;
							}
							else if (tempPtr__->ptr->historyLv == 3)
							{
								tempDiscount = 0.85;
							}
							else if (tempPtr__->ptr->historyLv == 4)
							{
								tempDiscount = 0.8;
							}
							else
							{
								tempDiscount = 0.75;
							}
						}
						else
						{
							if (tempPtr__->ptr->historyLv == 0)
							{
								tempDiscount = 1;
							}
							else if (tempPtr__->ptr->historyLv == 1)
							{
								tempDiscount = 0.9;
							}
							else if (tempPtr__->ptr->historyLv == 2)
							{
								tempDiscount = 0.85;
							}
							else if (tempPtr__->ptr->historyLv == 3)
							{
								tempDiscount = 0.8;
							}
							else if (tempPtr__->ptr->historyLv == 4)
							{
								tempDiscount = 0.75;
							}
							else
							{
								tempDiscount = 0.7;
							}
						}
						userFinalMoneyTmp = userOriginMoneyTmp*tempDiscount;
						userBuyNumber = tempPtr__->ptr->unitCount;
						strcpy_s(userCommodityName,tempPtr__->ptr->commodityName);
						sprintf_s(TempStr1__, "商品名称:%s", userCommodityName);
						if (userOriginMoneyTmp < 100 && userFinalMoneyTmp < 100)
						{
							sprintf_s(TempStr2__, "售价:%.2lf元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp, userFinalMoneyTmp, userBuyNumber);
						}
						else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >= 100&& userFinalMoneyTmp<1000)
						{
							sprintf_s(TempStr2__, "售价:%.2lf元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp, userFinalMoneyTmp/100, userBuyNumber);
						}
						else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >=1000)
						{
							sprintf_s(TempStr2__, "售价:%.2lf元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp, userFinalMoneyTmp/1000, userBuyNumber);
						}
						else if (userOriginMoneyTmp >= 100&& userOriginMoneyTmp <1000&& userFinalMoneyTmp < 100)
						{
							sprintf_s(TempStr2__, "售价:%.2lf百元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp/100, userFinalMoneyTmp, userBuyNumber);
						}
						else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
						{
							sprintf_s(TempStr2__, "售价:%.2lf百元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp/100, userFinalMoneyTmp/100, userBuyNumber);
						}
						else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >=1000)
						{
							sprintf_s(TempStr2__, "售价:%.2lf百元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp/100, userFinalMoneyTmp/1000, userBuyNumber);
						}
						else if (userOriginMoneyTmp >=1000&& userFinalMoneyTmp < 100)
						{
							sprintf_s(TempStr2__, "售价:%.2lf千元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp/1000, userFinalMoneyTmp, userBuyNumber);
						}
						else if (userOriginMoneyTmp>=1000&& userFinalMoneyTmp >= 100&& userFinalMoneyTmp<1000)
						{
							sprintf_s(TempStr2__, "售价:%.2lf千元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp/1000, userFinalMoneyTmp/100, userBuyNumber);
						}
						else
						{
							sprintf_s(TempStr2__, "售价:%.2lf千元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp/1000, userFinalMoneyTmp/1000, userBuyNumber);
						}
						sprintf_s(TempStr3__, "%d年%d月%d日", yearTmp,monthTmp,dayTmp);
						outtextxy(-100, -300, TempStr1__);
						outtextxy(-220, -200, TempStr2__);
						outtextxy(-100, -100, TempStr3__);
						line(-230, 0, 230, 0);
						outtextxy(-200, 30, "上一个商品");
						outtextxy(-200, 90, "申请售后");
						outtextxy(50, 30, "下一个商品");
						outtextxy(50, 90, "返回到主页");
						if (tempPtr__->ptr->situation == 1)
						{
							outtextxy(-200, -40, "已移交管理员处理");
						}
						else if (tempPtr__->ptr->situation == 2)
						{
							outtextxy(-200, -40, "处理完成，已退款");
						}
						else
						{
							;
						}
						m = GetMouseMsg();//--在循环内获取鼠标
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr__->preRecord == NULL)
								{
									MessageBox(hWnd, "这是第一个记录", " ", MB_OKCANCEL);
								}
								else
								{
									tempPtr__ = tempPtr__->preRecord;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (getCommodityPtrFromName(tempPtr__->ptr->commodityName))
								{
									if (tempPtr__->ptr->situation == 0)
									{
										tempPtr__->ptr->situation = 1;
										rebuildRecordFile(recordHead);
										MessageBox(hWnd, "已为您向管理员递交申请，请耐心等待", " ", MB_OKCANCEL);
										MessageBox(hWnd, "如有其他问题，请拨打客服热线13894980185", " ", MB_OKCANCEL);
										cleardevice(); pict();
									}
									else if (tempPtr__->ptr->situation == 1)
									{
										MessageBox(hWnd, "管理员正在处理，联系电话13894980185", " ", MB_OKCANCEL);
									}
									else
									{
										MessageBox(hWnd, "退款已完成，无法继续申请售后", " ", MB_OKCANCEL);
									}
								}
								else
								{
									MessageBox(hWnd, "商品已下架，无法继续申请售后", " ", MB_OKCANCEL);
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr__->nextRecord == NULL)
								{
									MessageBox(hWnd, "这是最后一个记录", " ", MB_OKCANCEL);
								}

								else
								{
									tempPtr__ = tempPtr__->nextRecord;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}
			}
		}
		//鼠标移动到查看购物车
		else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(-72.5, -110, 72.5, -70);
			//鼠标点击查看购物车
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(TempStr1_, 0, sizeof(TempStr1_));
				memset(TempStr2_, 0, sizeof(TempStr2_));
				memset(TempStr3_, 0, sizeof(TempStr3_));
				memset(commodityName_, 0, sizeof(commodityName_));
				unitCount_ = 0;
				soldPriceOrigin = 0;
				soldPriceDiscount = 0;
				tempPtr_ = cartHead;
				LLoop:
				if (tempPtr_ == NULL)
				{
					MessageBox(hWnd, "购物车是空的", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						setcolor(BLACK);
						xianuser();
						strcpy_s(commodityName_, tempPtr_->unitName);
						soldPriceOrigin = tempPtr_->soldPrice_Original;
						soldPriceDiscount = tempPtr_->soldPrice_Discount;
						unitCount_= tempPtr_->unitCount;
						sprintf_s(TempStr3_, "商品个数:%d个", unitCount_);
						sprintf_s(TempStr1_, "商品名称:%s", commodityName_);
						if (soldPriceOrigin < 100 && soldPriceDiscount < 100)
						{
							sprintf_s(TempStr2_, "原价:%.2lf元 打折后:%.2lf元", soldPriceOrigin, soldPriceDiscount);
						}
						else if (soldPriceOrigin < 100 && soldPriceDiscount >= 100 && soldPriceDiscount < 1000)
						{
							sprintf_s(TempStr2_, "原价:%.2lf元 打折后:%.2lf百元", soldPriceOrigin, soldPriceDiscount/100);
						}
						else if (soldPriceOrigin < 100 && soldPriceDiscount >= 1000)
						{
							sprintf_s(TempStr2_, "原价:%.2lf元 打折后:%.2lf千元", soldPriceOrigin, soldPriceDiscount/1000);
						}
						else if (soldPriceOrigin >= 100 && soldPriceOrigin < 1000 && soldPriceDiscount < 100)
						{
							sprintf_s(TempStr2_, "原价:%.2lf百元 打折后:%.2lf元", soldPriceOrigin/100, soldPriceDiscount);
						}
						else if (soldPriceOrigin >= 100 && soldPriceOrigin < 1000 && soldPriceDiscount >= 100 && soldPriceDiscount < 1000)
						{
							sprintf_s(TempStr2_, "原价:%.2lf百元 打折后:%.2lf百元", soldPriceOrigin/100, soldPriceDiscount/100);
						}
						else if (soldPriceOrigin >= 100 && soldPriceOrigin < 1000 && soldPriceDiscount >= 1000)
						{
							sprintf_s(TempStr2_, "原价:%.2lf百元 打折后:%.2lf千元", soldPriceOrigin/100, soldPriceDiscount/1000);
						}
						else if (soldPriceOrigin >= 1000 && soldPriceDiscount < 100)
						{
							sprintf_s(TempStr2_, "原价:%.2lf千元 打折后:%.2lf元", soldPriceOrigin/1000, soldPriceDiscount);
						}
						else if (soldPriceOrigin >= 1000 && soldPriceDiscount >= 100 && soldPriceDiscount < 1000)
						{
							sprintf_s(TempStr2_, "原价:%.2lf千元 打折后:%.2lf百元", soldPriceOrigin/1000, soldPriceDiscount/100);
						}
						else
						{
							sprintf_s(TempStr2_, "原价:%.2lf千元 打折后:%.2lf千元", soldPriceOrigin/1000, soldPriceDiscount/1000);
						}
						outtextxy(-100, -300, TempStr1_);
						outtextxy(-220, -200, TempStr2_);
						outtextxy(-100, -100, TempStr3_);
						line(-230, 0, 230, 0);
						outtextxy(-200, 30, "上一个商品");
						outtextxy(-200, 90, "从购物车移除");
						outtextxy(50, 30, "下一个商品");
						outtextxy(50, 90, "返回到主页");
						outtextxy(-340, 210, "支付");
						outtextxy(290, 210, "清空");
						tempCommodityPtr = getCommodityPtrFromName(tempPtr_->unitName);
						m = GetMouseMsg();//--在循环内获取鼠标
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr_->preCart == NULL)
								{
									MessageBox(hWnd, "这是第一个商品", " ", MB_OKCANCEL);
								}
								else
								{
									tempPtr_ = tempPtr_->preCart;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								temp = tempPtr_;
								delCart(&cartHead, &cartTail, temp);
								tempPtr_ = cartHead;
								MessageBox(hWnd, "删除成功", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto LLoop;
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (tempPtr_->nextCart == NULL)
								{
									MessageBox(hWnd, "这是最后一个商品", " ", MB_OKCANCEL);
								}

								else
								{
									tempPtr_ = tempPtr_->nextCart;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else if (m.x >= 125 && m.x <= 250 && m.y >= 700 && m.y <= 740)
						{
							setlinecolor(BLACK);
							rectangle(-365, 205, -260, 235);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(ttemp, 0, sizeof(ttemp));
								if ((tempPtr_->soldPrice_Discount > nowClient->balance) || (tempPtr_->unitCount > tempCommodityPtr->unitCount))
								{
									if (tempPtr_->soldPrice_Discount > nowClient->balance && !(tempPtr_->unitCount > tempCommodityPtr->unitCount))
									{
										MessageBox(hWnd, "余额不足", " ", MB_OKCANCEL);
									}
									else if (!(tempPtr_->soldPrice_Discount > nowClient->balance) && tempPtr_->unitCount > tempCommodityPtr->unitCount)
									{
										MessageBox(hWnd, "商品数量不足", " ", MB_OKCANCEL);
									}
									else
									{
										MessageBox(hWnd, "余额不足并且商品数量不足", " ", MB_OKCANCEL);
									}

								}
								else
								{
									nowClient->balance = nowClient->balance - tempPtr_->soldPrice_Discount;
									rebuildClientFile(clientHead);
									tempCommodityPtr->unitCount = tempCommodityPtr->unitCount - tempPtr_->unitCount;
									rebuildCommodityFile(commodityHead);
									sprintf_s(ttemp, "%d", tempPtr_->unitCount);
									addRecord(&recordHead, &recordTail, '1', tempPtr_->unitName, nowClient->clientName, tempCommodityPtr->soldPrice, tempCommodityPtr->purchasePrice, ttemp, tempPtr_->historylv);
									rebuildRecordFile(recordHead);
									temp = tempPtr_;
									delCart(&cartHead, &cartTail, temp);
									tempPtr_ = cartHead;
									buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
									MessageBox(hWnd, "支付成功", " ", MB_OKCANCEL);
									cleardevice(); pict();
									goto LLoop;
								}
							}
						}
						else if (m.x >= 750 && m.x <= 875 && m.y >= 700 && m.y <= 740)
						{
							setlinecolor(BLACK);
							rectangle(260, 205, 365, 235);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(tmpptr, 0, sizeof(tmpptr));
								memset(ttemp, 0, sizeof(ttemp));
								qingkong = NULL;
								flag = 1;
								qingkong = cartHead;
								tempNumSum = 0;
								while (qingkong)
								{
									if (qingkong->unitCount > getCommodityPtrFromName(qingkong->unitName)->unitCount)
									{
										flag = 0;
									}
									tempNumSum += qingkong->soldPrice_Discount;
									qingkong = qingkong->nextCart;
								}
								if ((nowClient->balance < tempNumSum) || flag == 0)
								{
									if (nowClient->balance < tempNumSum&&flag!=0)
									{
										MessageBox(hWnd, "余额不足", " ", MB_OKCANCEL);
									}
									else if (!(nowClient->balance < tempNumSum) && flag == 0)
									{
										MessageBox(hWnd, "某个商品库存不足，无法清空购物车", " ", MB_OKCANCEL);
									}
									else
									{
										MessageBox(hWnd, tmpptr, " ", MB_OKCANCEL);
									}
								}
								else
								{
									qingkong = cartHead;
									while (qingkong)
									{
										if (getCommodityPtrFromName(qingkong->unitName)->unitCount <qingkong->unitCount)
										{
											sprintf_s(tmpptr, "%s库存不足，无法清空购物车",qingkong->unitName );
											MessageBox(hWnd, tmpptr, " ", MB_OKCANCEL);
											tempPtr_ = cartHead;
											buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
											goto LLoop;
										}
										else
										{
											getCommodityPtrFromName(qingkong->unitName)->unitCount = getCommodityPtrFromName(qingkong->unitName)->unitCount - qingkong->unitCount;
											rebuildCommodityFile(commodityHead);
										}
										nowClient->balance = nowClient->balance - qingkong->soldPrice_Discount;
										rebuildClientFile(clientHead);
										sprintf_s(ttemp, "%d", qingkong->unitCount);
										addRecord(&recordHead, &recordTail, '1', qingkong->unitName, nowClient->clientName, getCommodityPtrFromName(qingkong->unitName)->soldPrice, getCommodityPtrFromName(qingkong->unitName)->purchasePrice, ttemp, qingkong->historylv);
										rebuildRecordFile(recordHead);
										temp = qingkong;
										delCart(&cartHead, &cartTail, temp);
										qingkong= cartHead;
									}
									buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, userCurrentName);
									MessageBox(hWnd, "成功清空购物车", " ", MB_OKCANCEL);
									cleardevice(); pict();
									tempPtr_ = cartHead;
									goto LLoop;
								}
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(260, 205, 365, 235);
							rectangle(-365, 205, -260, 235);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}
			}
		}
		//鼠标移动到注销账户
		else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(-60, -10, 60, 30);
			//鼠标点击注销账户
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(userCurrentName, 0, sizeof(userCurrentName));
				memset(userLoginName, 0, sizeof(userLoginName));
				memset(userLoginNameTmp, 0, sizeof(userLoginNameTmp));
				memset(userLoginPwd, 0, sizeof(userLoginPwd));
				memset(userLoginPwdTmp, 0, sizeof(userLoginPwdTmp));
				auth1 = 0;
			}
		}
		//鼠标移动到退出
		else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-35, 90, 35, 130);
			//鼠标点击退出
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				auth1 = 1;
			}
		}
		////鼠标移动到充值
		else if (m.x >= 125 && m.x <= 250 && m.y >= 700 && m.y <= 740)
		{
			setlinecolor(BLACK);
			rectangle(-365,205, -260, 235 );
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice(); pict();
				_lengh_ = 0;
				memset(originMd5, 0, sizeof(originMd5));
				memset(targetMd5, 0, sizeof(targetMd5));
				memset(finalMd5, 0, sizeof(finalMd5));
				memset(money, 0, sizeof(money));
				tempNumber1 = 0;
				tempNumber2 = 0;
				tempNumber3 = 0;
				count = 0;
				tempNumber1 = rand() % 10;
				tempNumber2 = rand() % 10;
				tempNumber3 = rand() % 10;
				sprintf_s(originMd5, 50, "jnfcu%dombhf%dplkhg%d", tempNumber1, tempNumber2, tempNumber3);
				MD5Function((unsigned char*)originMd5, targetMd5);
				InputBox(money, 50, "请写入充值钱数，只能为整数，单次充值不超过10000元", NULL, NULL, 0, 0, false);
				_lengh_ = strnlen_s(money, sizeof(money));
				if (_lengh_ == 0)
				{
					;
				}
				else
				{
					if (isFullDigit(money) && _lengh_ <= 5 && _lengh_ > 0 && isStdInput(money) && strToInt(money) <= 10000 && strToInt(money) > 0)
					{
						MessageBox(hWnd, "您正在为我们提供算力，请稍后", " ", MB_OKCANCEL);
						for (; count < strToInt(money); count++)
						{
							MD5Function((unsigned char*)targetMd5, targetMd5);
						}
						sprintf_s(finalMd5, "您的运算结果%s", targetMd5);
						MessageBox(hWnd, finalMd5, " ", MB_OKCANCEL);
						nowClient->balance = nowClient->balance + strToInt(money);
						rebuildClientFile(clientHead);
						MessageBox(hWnd, "恭喜您，充值成功", " ", MB_OKCANCEL);
					}
					else
					{
						MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
					}
				}
				cleardevice(); pict();

			}
		}
		//鼠标移动到升级
		else if (m.x >= 750 && m.x <= 875 && m.y >= 700 && m.y <= 740)
		{
			setlinecolor(BLACK);
			rectangle(260,205,365,235 );
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice(); pict();
				tempLevel = 0;
				_level_ = 0;
				memset(levelStandard, 0, sizeof(levelStandard));
				tempLevel = nowClient->lv;
				if (tempLevel == 0)
				{
					if (MessageBox(hWnd, "是否升级到1级", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "余额不足", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "升级成功", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else if (tempLevel == 1)
				{
					if (MessageBox(hWnd, "是从1级升级到2级", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "余额不足", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "升级成功", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else if (tempLevel == 2)
				{
					if (MessageBox(hWnd, "是否从2级升级到3级", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "余额不足", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "升级成功", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else if (tempLevel == 3)
				{
					
					if (MessageBox(hWnd, "是否由3级升级到4级", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "余额不足", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "升级成功", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				
				}
				else if (tempLevel == 4)
				{
					if (MessageBox(hWnd, "是否从4级升级到5级", "", MB_OKCANCEL)==IDOK)
					{
						if (nowClient->balance < threeToFour0)
						{
							MessageBox(hWnd, "余额不足", " ", MB_OKCANCEL);
						}
						else
						{
							nowClient->balance = nowClient->balance - threeToFour0;
							nowClient->lv = nowClient->lv + 1;
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "升级成功", " ", MB_OKCANCEL);
						}
					}
					else
					{
						;
					}
				}
				else
				{
					MessageBox(hWnd, "您已满级", " ", MB_OKCANCEL);
				}
				if (nowClient->isCostumer == 0)
				{
					if (nowClient->lv == 0)
					{
						discount = 1;
					}
					else if (nowClient->lv == 1)
					{
						discount = 0.95;
					}
					else if (nowClient->lv == 2)
					{
						discount = 0.9;
					}
					else if (nowClient->lv == 3)
					{
						discount = 0.85;
					}
					else if (nowClient->lv == 4)
					{
						discount = 0.8;
					}
					else
					{
						discount = 0.75;
					}
				}
				else
				{
					if (nowClient->lv == 0)
					{
						discount = 1;
					}
					else if (nowClient->lv == 1)
					{
						discount = 0.9;
					}
					else if (nowClient->lv == 2)
					{
						discount = 0.85;
					}
					else if (nowClient->lv == 3)
					{
						discount = 0.8;
					}
					else if (nowClient->lv == 4)
					{
						discount = 0.75;
					}
					else
					{
						discount = 0.7;
					}
				}
			}
		}
		//鼠标移动到修改密码
		else if (m.x >= 600 && m.x <= 720 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(100, 90, 220, 130);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				fflag = 0;
				memset(pwdTmp, 0, sizeof(pwdTmp));
				memset(changePwd, 0, sizeof(changePwd));
				memset(userNameMd5, 0, sizeof(userNameMd5));
				memset(idTmp_, 0, sizeof(idTmp_));
				memset(pwdTmp_, 0, sizeof(pwdTmp_));
				strcpy_s(userCurrentName_, userCurrentName);
				MD5Function((unsigned char*)userCurrentName_, userNameMd5);
				pwdLen = 0;
				InputBox(pwdTmp, 50, "请写入用户密码（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
				pwdLen = strnlen(pwdTmp, sizeof(pwdTmp));
				if (isStdInput(pwdTmp) && pwdLen <= 40)
				{
					strcpy_s(changePwd, pwdTmp);
					MD5Function((unsigned char*)changePwd, changePwd);
					if (pwdLen == 0)
					{
						;
					}
					else
					{
						FILE* fp, * fp1;
						fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "r");
						fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "w");
						if ((fp != NULL) && (fp1 != NULL))
						{
							while (fscanf_s(fp, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
							{ // 循环读取文件中的数据，直到文件末
								if (strcmp(idTmp_, userNameMd5) == 0)
								{ // 如果输入的账号和密码与文件中的数据匹配，则设置标志为1，并跳出循环
									if (strcmp(pwdTmp_, changePwd) == 0)
									{
										MessageBox(hWnd, "新旧密码不能相同", " ", MB_OKCANCEL);
										fflag = 1;
										break;
									}
									else
									{
										fprintf_s(fp1, "%s %s\n", idTmp_, changePwd);
									}
								}
								else
								{
								fprintf_s(fp1, "%s %s\n", idTmp_, pwdTmp_);
								}
							}
							fclose(fp); fclose(fp1);
						}
						fp = NULL; fp1 = NULL;
						if (fflag == 0)
						{
							fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "w");
							fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "r");
							if ((fp != NULL) && (fp1 != NULL))
							{
								while (fscanf_s(fp1, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
								{ // 循环读取文件中的数据，直到文件末
									fprintf_s(fp, "%s %s\n", idTmp_, pwdTmp_);
								}
								fclose(fp); fclose(fp1);
							}
							fp = NULL; fp1 = NULL;
							MessageBox(hWnd, "密码修改成功,请重新登录", " ", MB_OKCANCEL);
							memset(userCurrentName, 0, sizeof(userCurrentName));
							memset(userLoginName, 0, sizeof(userLoginName));
							memset(userLoginNameTmp, 0, sizeof(userLoginNameTmp));
							memset(userLoginPwd, 0, sizeof(userLoginPwd));
							memset(userLoginPwdTmp, 0, sizeof(userLoginPwdTmp));
							auth1 = 0;
						}
						else
						{
							;
						}
					}
				}
				else
				{
					MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
				}
			}
		}
		//鼠标移动到提交工单
		else if (m.x >= 280 && m.x <= 400 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-220, 90, -100, 130);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				year__ = 0, month__ = 0, day__ = 0;
				getCurrentTime(&year__, &month__, &day__);
				memset(userText, 0, sizeof(userText));
				InputBox(userText, 200, "此工单将交由管理员处理，请你写出你的请求，包括你的订单信息以及联系方式(100字以内)",NULL,NULL,300,400,false);
				lenText = strnlen_s(userText, sizeof(userText));
				if (lenText == 0)
				{
					;
				}
				else
				{
					FILE* feedback;
					fopen_s(&feedback, ".\\Data\\RecordChainData\\feedback.txt", "a+");
					if (feedback)
					{
						fprintf(feedback, "%s\n", nowClient->clientName);
						fprintf(feedback, "%d_%d_%d\n", year__, month__, day__);
						fprintf(feedback, "%s\n", userText);
						fprintf(feedback, "%s\n", "--------------------------------------------------------------------------------------------");
						fclose(feedback);
						feedback = NULL;
					}
					MessageBox(hWnd, "工单提交成功", " ", MB_OKCANCEL);
				}
			}
		}
		//鼠标移动到方框之外
		else
		{
			setlinecolor(WHITE);
			rectangle(-365, 205, -260, 235);
			rectangle(260, 205, 365, 235);
			rectangle(-60, -210, 60, -170);
			rectangle(-72.5, -110, 72.5, -70);
			rectangle(-60, -10, 60, 30);
			rectangle(-35, 90, 35, 130);
			rectangle(-110, -310, 110, -270);
			rectangle(100, 90, 220, 130);
			rectangle(-220, 90, -100, 130);
		}
		if (auth1 == 0 || auth1 == 1)
		{
			cleardevice(); pict();
			break;
		}
	}
}
//--------------------

//--------------------
//管理员系统页面
void adminPage(void)
{
	char str1[50], str2[50], str3[50], str4[50], str5[50], str6[50], str7[50], str8[50], str9[50], idTmp_[50], pwdTmp_[50], userNameMd5[50], userCommodityName[50], userCommodityNameT[50], str10[50], str11[50], str12[50], TEXTtmp[220], TEXT[10000], str13[50], str14[50], str15[50], str16[50], SumNumber[50], tempZB[50], str17[50], str18[50], str19[50], str20[50], str21[50], str22[50], str23[50], str24[50], str25[50], str26[50], str27[50], str28[50],PROFILE[50],TIME[50],str29[50],str30[50],str31[50],STR1[50],STR2[50],STR3[50];
	int yearTmp1=0, monthTmp1=0, dayTmp1=0, yearTmp2 = 0,monthTmp2 = 0,dayTmp2 = 0,userBuyNumber = 0, yearTmp3 = 0,monthTmp3 = 0,dayTmp3 = 0, userBuyNumberT = 0,_sum=0,userBuyNumber1 = 0,YEAR=0,MONTH=0,DAY=0;
	//--------------------
	int userl_1 = 0,userl_2 = 0,userl_3 = 0,identify = 0,_len_ = 0, _userl_1 = 0, _userl_2 = 0, _userl_3 = 0,situationTmp=0,i=0,ii=0,iii=0,iiii=0,judgeNum=0;
	int Xuserl_1 = 0, Xuserl_2 = 0, Xuserl_3 = 0, Xidentify = 0, X_len_ = 0, X_userl_1 = 0, X_userl_2 = 0, X_userl_3 = 0, XsituationTmp = 0;
	//--------------------
	double userOriginMoneyTmp = 0, userFinalMoneyTmp = 0, userOriginMoneyTmpT = 0, userFinalMoneyTmpT = 0, M = 0, N = 0, userOriginMoneyTmp1 = 0, userFinalMoneyTmp1 = 0,profile=0,tempPoint=0;
	double k = 0, b = 0;
	struct ClientNode* ptr1=NULL;
	struct userRecordNode* ptr2 = NULL;
	struct userRecordNode* ptr3 = NULL;
	struct CommodityNode* ptr4 = NULL;
	struct userRecordNode* ptr5 = NULL;
	struct RecordNode* ptr6 = NULL;
	struct ClientNode* ptr7=NULL;
	struct CommodityNode* ptr8=NULL,*judge = NULL;
	struct ClientNode* ptr9 = NULL,*ptr10=NULL;
	struct RecordNode* temp = NULL, * calculate = NULL, * calculate1 = NULL;
	while (TRUE)
	{
		setcolor(BLACK);
		xianadmin();
		outtextxy(-100, -300, "管理员--操作终端");
		outtextxy(-150, -200, "查看客户");
		outtextxy(50, -200, "查看商品");
		outtextxy(-150, -100, "销售记录");
		outtextxy(50, -100, "退货申请");
		outtextxy(-150, 0, "总览页面");
		outtextxy(50, 0, "返回主页");
		outtextxy(-150, 100, "查看工单");
		outtextxy(50, 100, "退出程序");
		rectangle(-110, -310, 110, -270);//---外方框
		rectangle(-120, -320, 120, -260);
		m = GetMouseMsg();//--在循环内获取鼠标
		//鼠标移动到查看客户
		if (m.x >= 340 && m.x <= 460 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(-160, -210, -40, -170);
			//鼠标点击查看客户
			if (m.uMsg == WM_LBUTTONDOWN)
			{
			loop1:
				memset(str1, 0, sizeof(str1));
				memset(str2, 0, sizeof(str2));
				memset(str3, 0, sizeof(str3));
				ptr1 = clientHead;
				if (ptr1 == NULL)
				{
					MessageBox(hWnd, "暂无用户", " ", MB_OKCANCEL);
				}
				else
				{ 
				cleardevice(); pict();
				while (TRUE)
				{
					sprintf_s(str1, "%s", ptr1->clientName);
					sprintf_s(str2, "%d级", ptr1->lv);
					sprintf_s(str3, "%.2lf元", ptr1->balance);
					sprintf_s(str4, "%d年", ptr1->year);
					sprintf_s(str5, "%d月", ptr1->month);
					sprintf_s(str6, "%d日", ptr1->day);
					setcolor(BLACK);
					xianadminLookUser();
					outtextxy(-120, -370, str1);
					outtextxy(115, -330, str2);
					outtextxy(-145, -300, str3);
					outtextxy(-120, -210, "注册日期");
					outtextxy(-120, -170, str4);
					outtextxy(-120, -130, str5);
					outtextxy(-120, -90, str6);
					outtextxy(-25, -40, "查询");
					if (ptr1->isCostumer == 0)
					{
						outtextxy(125, -280, "用户");
					}
					else
					{
						outtextxy(125, -280, "批发商");
					}
					if (ptr1->situation == 0)
					{
						outtextxy(115, -125, "未被");
					}
					else
					{
						outtextxy(115, -125, "已被");
					}
					m = GetMouseMsg();//--在循环内获取鼠标
					if (m.x >= 280 && m.x <= 325 && m.y >= 540 && m.y <= 660)
					{
						setlinecolor(BLACK);
						rectangle(-220, 40, -175, 160);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->preClient == NULL)
							{
								MessageBox(hWnd, "这是第一个用户", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1 = ptr1->preClient;
							}
							cleardevice(); pict();
						}
					}
					else if (m.x >= 350 && m.x <= 395 && m.y >= 540 && m.y <= 660)
					{
						setlinecolor(BLACK);
						rectangle(-150, 40, -105, 160);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->nextClient == NULL)
							{
								MessageBox(hWnd, "这是最后一个用户", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1 = ptr1->nextClient;
							}
							cleardevice(); pict();
						}
					}
					else if (m.x >= 420 && m.x <= 465 && m.y >= 510 && m.y <= 670)
					{
						setlinecolor(BLACK);
						rectangle(-80, 10, -35, 170);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							MD5Function((unsigned char*)(ptr1->clientName), userNameMd5);
							FILE* fp, * fp1;
							fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "r");
							fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "w");
							if ((fp != NULL) && (fp1 != NULL))
							{
								while (fscanf_s(fp, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
								{ // 循环读取文件中的数据，直到文件末
									if (strcmp(idTmp_, userNameMd5) == 0)
									{ // 如果输入的账号和密码与文件中的数据匹配，则设置标志为1，并跳出循环
										;
									}
									else
									{
										fprintf_s(fp1, "%s %s\n", idTmp_, pwdTmp_);
									}
								}
								fclose(fp); fclose(fp1);
							}
							fp = NULL; fp1 = NULL;
							fopen_s(&fp, ".\\Data\\loginData\\userData.txt", "w");
							fopen_s(&fp1, ".\\Data\\loginData\\operationTmpData.txt", "r");
							if ((fp != NULL) && (fp1 != NULL))
							{
								while (fscanf_s(fp1, "%s %s\n", idTmp_, 50, pwdTmp_, 50) != EOF)
								{ // 循环读取文件中的数据，直到文件末
									fprintf_s(fp, "%s %s\n", idTmp_, pwdTmp_);
								}
								fclose(fp); fclose(fp1);
							}
							fp = NULL; fp1 = NULL;
							delClient(&clientHead, &clientTail, ptr1);
							rebuildClientFile(clientHead);
							MessageBox(hWnd, "删除成功", " ", MB_OKCANCEL);
							cleardevice(); pict();
							goto loop1;
						}
					}
					else if (m.x >= 535 && m.x <= 580 && m.y >= 510 && m.y <= 670)
					{
						setlinecolor(BLACK);
						rectangle(35, 10, 80, 170);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							userl_1 = 0;
							userl_2 = 0;
							userl_3 = 0;//长度初始化
							identify = 0;
							_len_ = 0;
							memset(userSignupName, 0, sizeof(userSignupName));//令字符串皆为空
							memset(userSignupNameTmp, 0, sizeof(userSignupNameTmp));
							memset(userSignupPwd1, 0, sizeof(userSignupPwd1));
							memset(userSignupPwd1Tmp, 0, sizeof(userSignupPwd1Tmp));
							memset(userSignupPwd2, 0, sizeof(userSignupPwd2));
							memset(userSignupPwd2Tmp, 0, sizeof(userSignupPwd2Tmp));
							memset(userIdentifyTmp, 0, sizeof(userIdentifyTmp));
							cleardevice(); pict();
							while (TRUE)
							{
								setcolor(BLACK);
								xianadmin();
								outtextxy(-100, -300, "输入你喜欢的账号");
								outtextxy(-50, -200, "输入密码");
								outtextxy(-62.5, -100, "再输入密码");
								outtextxy(-50, 0, "添加用户");
								outtextxy(-25, 100, "返回");
								//判空操作
								if (userl_1 != 0)
								{
									outtextxy(150, -300, "_/");
								}
								//判空操作
								if (userl_2 != 0)
								{
									outtextxy(150, -200, "_/");
								}
								//判空操作
								if (userl_3 != 0)
								{
									outtextxy(150, -100, "_/");
								}
								m = GetMouseMsg();
								//鼠标移动到---输入你喜欢的账号
								if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
								{
									setlinecolor(BLACK);
									rectangle(-110, -310, 110, -270);
									//鼠标点击---输入你喜欢的账号
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										InputBox(userSignupNameTmp, 50, "请写入你喜欢的账号（14位以内，且只包含字符和数字,第一位必须是字符）", NULL, NULL, 0, 0, false);
										_userl_1 = strnlen_s(userSignupNameTmp, sizeof(userSignupNameTmp));
										if ((isStdInput(userSignupNameTmp) && _userl_1 <= 14 && isCharacter(userSignupNameTmp[0])) || _userl_1 == 0)
										{
											strcpy_s(userSignupName, userSignupNameTmp);
											userl_1 = strnlen_s(userSignupName, sizeof(userSignupName));
										}
										else
										{
											MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
										}
									}
								}
								//鼠标移动到---输入密码
								else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
								{
									setlinecolor(BLACK);
									rectangle(-60, -210, 60, -170);
									//鼠标点击---输入密码
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										InputBox(userSignupPwd1Tmp, 50, "请写入密码（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
										_userl_2 = strnlen_s(userSignupPwd1Tmp, sizeof(userSignupPwd1Tmp));
										if (isStdInput(userSignupPwd1Tmp) && _userl_2 <= 40)
										{
											strcpy_s(userSignupPwd1, userSignupPwd1Tmp);
											userl_2 = strnlen_s(userSignupPwd1, sizeof(userSignupPwd1));
										}
										else
										{
											MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
										}
									}
								}
								//鼠标移动到再次输入密码
								else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
								{
									setlinecolor(BLACK);
									rectangle(-72.5, -110, 72.5, -70);
									//鼠标点击再次输入密码
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										InputBox(userSignupPwd2Tmp, 50, "请再次写入密码（40位以内，且只包含字符和数字）", NULL, NULL, 0, 0, false);
										_userl_3 = strnlen_s(userSignupPwd2Tmp, sizeof(userSignupPwd2Tmp));
										if (isStdInput(userSignupPwd2Tmp) && _userl_3 <= 40)
										{
											strcpy_s(userSignupPwd2, userSignupPwd2Tmp);
											userl_3 = strnlen_s(userSignupPwd2, sizeof(userSignupPwd2));
										}
										else
										{
											MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
										}
									}
								}
								//鼠标移动到提交注册
								else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
								{
									setlinecolor(BLACK);
									rectangle(-60, -10, 60, 30);
									//鼠标点击提交注册
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										//判空
										if (userl_1 != 0 && userl_2 == 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "请输入两次用户密码", " ", MB_OKCANCEL);
										}
										//判空
										else if (userl_1 == 0 && userl_2 != 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "请输入账号并再次输入密码", " ", MB_OKCANCEL);
										}//判空
										//判空
										else if (userl_1 == 0 && userl_2 == 0 && userl_3 != 0)
										{
											MessageBox(hWnd, "请输入账号和密码", " ", MB_OKCANCEL);
										}
										//判空
										else if (userl_1 == 0 && userl_2 != 0 && userl_3 != 0)
										{
											MessageBox(hWnd, "请输入账号", " ", MB_OKCANCEL);
										}
										//判空
										else if (userl_1 != 0 && userl_2 == 0 && userl_3 != 0)
										{
											MessageBox(hWnd, "请输入密码", " ", MB_OKCANCEL);
										}
										//判空
										else if (userl_1 != 0 && userl_2 != 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "请再次输入密码", " ", MB_OKCANCEL);
										}
										//判空
										else if (userl_1 == 0 && userl_2 == 0 && userl_3 == 0)
										{
											MessageBox(hWnd, "请输入账号并输入两次密码", " ", MB_OKCANCEL);
										}
										//正式操作
										else
										{
											if (MessageBox(hWnd, "是否成为批发商?\n点击取消变成普通用户\n注意，批发商的每单最低交易额为100", "", MB_OKCANCEL) == IDOK)
											{
												identify = 1;
											}
											else
											{
												identify = 0;
											}
											situationTmp = registerUser(userSignupName, userSignupPwd1, userSignupPwd2, identify);
											if (situationTmp == -1)
											{
												MessageBox(hWnd, "两次输入密码不一致，请重试", " ", MB_OKCANCEL);
											}
											else if (situationTmp == 0)
											{
												MessageBox(hWnd, "用户已存在，请重新输入账号", " ", MB_OKCANCEL);
											}
											else
											{
												cleardevice(); pict();
												MessageBox(hWnd, "添加成功", " ", MB_OKCANCEL);
												goto loop1;
											}
										}
									}
								}
								//鼠标移动到返回
								else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
								{
									setlinecolor(BLACK);
									rectangle(-35, 90, 35, 130);
									//鼠标点击返回
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										cleardevice(); pict();
										break;
									}
								}
								//鼠标移动到方框之外
								else
								{
									setlinecolor(WHITE);
									rectangle(-60, -210, 60, -170);
									rectangle(-72.5, -110, 72.5, -70);
									rectangle(-60, -10, 60, 30);
									rectangle(-35, 90, 35, 130);
									rectangle(-110, -310, 110, -270);
								}
							}

						}
					}
					else if (m.x >= 605 && m.x <= 650 && m.y >= 510 && m.y <= 670)
					{
						setlinecolor(BLACK);
						rectangle(105, 10, 150, 170);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
						loop2:
							cleardevice(); pict();
							buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, ptr1->clientName);
							memset(userCommodityName, 0, sizeof(userCommodityName));
							yearTmp1 = 0;
							monthTmp1 = 0;
							dayTmp1 = 0;
							userOriginMoneyTmp = 0;
							userFinalMoneyTmp = 0;
							userBuyNumber = 0;
							memset(str7, 0, sizeof(str7));
							memset(str8, 0, sizeof(str8));
							memset(str9, 0, sizeof(str9));
							ptr2 = userRecordHead;
							if (ptr2 == NULL)
							{
								MessageBox(hWnd, "暂无购物记录", " ", MB_OKCANCEL);
							}
							else
							{
								while (TRUE)
								{
									setcolor(BLACK);
									xianadmin();
									yearTmp1 = ptr2->ptr->year;
									monthTmp1 = ptr2->ptr->month;
									dayTmp1 = ptr2->ptr->day;
									userOriginMoneyTmp = ptr2->ptr->soldPrice;
									if (ptr1->isCostumer==0)
									{
										if (ptr2->ptr->historyLv== 0)
										{
											tempDiscount = 1;
										}
										else if (ptr2->ptr->historyLv==1)
										{
											tempDiscount = 0.95;
										}
										else if (ptr2->ptr->historyLv==2)
										{
											tempDiscount = 0.9;
										}
										else if (ptr2->ptr->historyLv==3)
										{
											tempDiscount = 0.85;
										}
										else if (ptr2->ptr->historyLv==4)
										{
											tempDiscount = 0.8;
										}
										else
										{
											tempDiscount = 0.75;
										}
									}
									else
									{
										if (ptr2->ptr->historyLv==0)
										{
											tempDiscount = 1;
										}
										else if (ptr2->ptr->historyLv==1)
										{
											tempDiscount = 0.9;
										}
										else if (ptr2->ptr->historyLv==2)
										{
											tempDiscount = 0.85;
										}
										else if (ptr2->ptr->historyLv==3)
										{
											tempDiscount = 0.8;
										}
										else if (ptr2->ptr->historyLv==4)
										{
											tempDiscount = 0.75;
										}
										else
										{
											tempDiscount = 0.7;
										}
									}
									userFinalMoneyTmp = userOriginMoneyTmp * tempDiscount;
									userBuyNumber = ptr2->ptr->unitCount;
									strcpy_s(userCommodityName, ptr2->ptr->commodityName);
									sprintf_s(str7, "商品名称:%s", userCommodityName);
									if (userOriginMoneyTmp < 100 && userFinalMoneyTmp < 100)
									{
										sprintf_s(str8, "售价:%.2lf元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp, userFinalMoneyTmp, userBuyNumber);
									}
									else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
									{
										sprintf_s(str8, "售价:%.2lf元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp, userFinalMoneyTmp / 100, userBuyNumber);
									}
									else if (userOriginMoneyTmp < 100 && userFinalMoneyTmp >= 1000)
									{
										sprintf_s(str8, "售价:%.2lf元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp, userFinalMoneyTmp / 1000, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp < 100)
									{
										sprintf_s(str8, "售价:%.2lf百元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp / 100, userFinalMoneyTmp, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
									{
										sprintf_s(str8, "售价:%.2lf百元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp / 100, userFinalMoneyTmp / 100, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 100 && userOriginMoneyTmp < 1000 && userFinalMoneyTmp >= 1000)
									{
										sprintf_s(str8, "售价:%.2lf百元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp / 100, userFinalMoneyTmp / 1000, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 1000 && userFinalMoneyTmp < 100)
									{
										sprintf_s(str8, "售价:%.2lf千元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp / 1000, userFinalMoneyTmp, userBuyNumber);
									}
									else if (userOriginMoneyTmp >= 1000 && userFinalMoneyTmp >= 100 && userFinalMoneyTmp < 1000)
									{
										sprintf_s(str8, "售价:%.2lf千元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp / 1000, userFinalMoneyTmp / 100, userBuyNumber);
									}
									else
									{
										sprintf_s(str8, "售价:%.2lf千元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp / 1000, userFinalMoneyTmp / 1000, userBuyNumber);
									}
									sprintf_s(str9, "%d年%d月%d日", yearTmp1, monthTmp1, dayTmp1);
									outtextxy(-100, -300, str7);
									outtextxy(-220, -200, str8);
									outtextxy(-100, -100, str9);
									line(-230, 0, 230, 0);
									outtextxy(-200, 30, "上一条记录");
									outtextxy(-200, 90, "删除记录");
									outtextxy(50, 30, "下一条记录");
									outtextxy(50, 90, "返回上级");
									if (ptr2->ptr->situation== 1)
									{
										outtextxy(-200, -40, "请您尽快处理其退款请求");
									}
									else if (ptr2->ptr->situation == 2)
									{
										outtextxy(-200, -40, "处理完成，已退款");
									}
									else
									{
										outtextxy(-200, -40, "未申请售后");
									}
									m = GetMouseMsg();//--在循环内获取鼠标
									if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
									{
										setlinecolor(BLACK);
										rectangle(-210, 20, -40, 60);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											if (ptr2->preRecord == NULL)
											{
												MessageBox(hWnd, "这是第一个记录", " ", MB_OKCANCEL);
											}
											else
											{
												ptr2= ptr2->preRecord;
											}
										}
									}
									else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
									{
										setlinecolor(BLACK);
										rectangle(-210, 80, -40, 120);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											temp = ptr2->ptr;
											delRecord(&recordHead, &recordTail, temp);
											rebuildRecordFile(recordHead);
											buildUserRecordChain(recordHead, &userRecordHead, &userRecordTail, ptr1->clientName);
											ptr2 = userRecordHead;
											MessageBox(hWnd, "删除成功", " ", MB_OKCANCEL);
											cleardevice(); pict();
											goto loop2;
										}
									}
									else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
									{
										setlinecolor(BLACK);
										rectangle(40, 20, 210, 60);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											if (ptr2->nextRecord==NULL)
											{
												MessageBox(hWnd, "这是最后一个记录", " ", MB_OKCANCEL);
											}

											else
											{
												ptr2 = ptr2->nextRecord;
											}
										}
									}
									else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
									{
										setlinecolor(BLACK);
										rectangle(40, 80, 210, 120);
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											break;
										}
									}
									else
									{
										setlinecolor(WHITE);
										rectangle(-210, 20, -40, 60);
										rectangle(-210, 80, -40, 120);
										rectangle(40, 20, 210, 60);
										rectangle(40, 80, 210, 120);
									}
								}
							}
						}
					}
					else if (m.x >= 675 && m.x <= 720 && m.y >= 580 && m.y <= 660)
					{
						setlinecolor(BLACK);
						rectangle(175, 80, 220, 160);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					else if (m.x >= 280 && m.x <= 370 && m.y >= 450 && m.y <= 490)
					{
						setlinecolor(BLACK);
						rectangle(-220, -50, -130, -10);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->situation == 0)
							{
								MessageBox(hWnd, "该用户未被封禁", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1->situation = 0;
								rebuildClientFile(clientHead);
								MessageBox(hWnd, "解封成功", " ", MB_OKCANCEL);
								cleardevice(); pict();
							}
						}
					}
					else if (m.x >= 380 && m.x <= 460&& m.y >= 450 && m.y <= 490)
					{
						setlinecolor(BLACK);
						rectangle(-120, -50, -40, -10);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							if (ptr1->situation == 1)
							{
								MessageBox(hWnd, "该用户已被封禁", " ", MB_OKCANCEL);
							}
							else
							{
								ptr1->situation = 1;
								rebuildClientFile(clientHead);
								MessageBox(hWnd, "封禁成功", " ", MB_OKCANCEL);
								cleardevice(); pict();
							}
						}
					}
					else if (m.x >= 472 && m.x <= 570 && m.y >= 450 && m.y <= 490)
					{
						setlinecolor(BLACK);
						rectangle(-28, -50, 70, -10);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							memset(str30, 0, sizeof(str30));
							memset(str31, 0, sizeof(str31));
							memset(STR1, 0, sizeof(STR1));
							memset(STR2, 0, sizeof(STR2));
							memset(STR3, 0, sizeof(STR3));
							InputBox(str30, 50, "请写入用户账号（40位以内,且只包含字符和数字）", NULL, NULL, 0, 0, false);
							if (strnlen_s(str30, sizeof(str30)) == 0)
							{
								;
							}
							else if (isStdInput(str30) && strnlen_s(str30, sizeof(str30)) <= 40 && strnlen_s(str30, sizeof(str30)) > 0)
							{
								strcpy_s(str31, str30);
								ptr9 = clientHead;
								ptr10 = clientHead;
								while (ptr9)
								{
									strcpy_s(STR1,str31);
									strcpy_s(STR2, ptr9->clientName);
									strcpy_s(STR3, ptr10->clientName);
									strToLower(STR1);
									strToLower(STR2);
									strToLower(STR3);
									if (getStrSimilarity(STR1, STR2) >= getStrSimilarity(STR1, STR3))
									{
										ptr10 = ptr9;
									}
									ptr9 = ptr9->nextClient;
								}
								MessageBox(hWnd, "接下来为您展示最相似的用户的详细信息", " ", MB_OKCANCEL);
								memset(str1, 0, sizeof(str1));
								memset(str2, 0, sizeof(str2));
								memset(str3, 0, sizeof(str3));
								if (ptr10)
								{
									cleardevice(); pict();
									while (TRUE)
									{
										sprintf_s(str1, "%s", ptr10->clientName);
										sprintf_s(str2, "%d级", ptr10->lv);
										sprintf_s(str3, "%.2lf元", ptr10->balance);
										sprintf_s(str4, "%d年", ptr10->year);
										sprintf_s(str5, "%d月", ptr10->month);
										sprintf_s(str6, "%d日", ptr10->day);
										setcolor(BLACK);
										xianadminLookUserG();
										outtextxy(-120, -370, str1);
										outtextxy(115, -330, str2);
										outtextxy(-145, -300, str3);
										outtextxy(-120, -210, "注册日期");
										outtextxy(-120, -170, str4);
										outtextxy(-120, -130, str5);
										outtextxy(-120, -90, str6);
										if (ptr10->isCostumer == 0)
										{
											outtextxy(125, -280, "用户");
										}
										else
										{
											outtextxy(125, -280, "批发商");
										}
										if (ptr10->situation == 0)
										{
											outtextxy(115, -125, "未被");
										}
										else
										{
											outtextxy(115, -125, "已被");
										}
										m = GetMouseMsg();//--在循环内获取鼠标
										if (m.x >= 465 && m.x <= 535 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-35, 80, 35, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												ptr1 = ptr10;
												MessageBox(hWnd, "您将进行对该用户的操作", " ", MB_OKCANCEL);
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-35, 80, 35, 120);
										}
									}
								}
							}
							else
							{
								MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
							}
						}
					}
					else
					{
						setlinecolor(WHITE);
						rectangle(-220, 40, -175, 160);
						rectangle(-150, 40, -105, 160);
						rectangle(-80, 10, -35, 170);
						rectangle(35, 10, 80, 170);
						rectangle(105, 10, 150, 170);
						rectangle(175, 80, 220, 160);
						rectangle(-220, -50, -130, -10);
						rectangle(-120, -50, -40, -10);
						rectangle(-28, -50, 70, -10);
					}
				}
				}
				
			}
		}
		//鼠标移动到查看商品
		else if (m.x >= 540 && m.x <= 660 && m.y >= 290 && m.y <= 330)
		{
			setlinecolor(BLACK);
			rectangle(40, -210, 160, -170);
			//鼠标点击查看商品
			if (m.uMsg == WM_LBUTTONDOWN)
			{
			loop4:
				memset(str13, 0, sizeof(str13));
				memset(str14, 0, sizeof(str14));
				memset(str15, 0, sizeof(str15));
				memset(str16, 0, sizeof(str16));
				memset(tempZB, 0, sizeof(tempZB));
				ptr4 = commodityHead;
				if (ptr4 == NULL)
				{
					MessageBox(hWnd, "暂无商品在售，请添加商品", " ", MB_OKCANCEL);
				}
				else
				{
					cleardevice(); pict();
					while (TRUE)
					{
						M = 0;
						N = 0;
						sprintf_s(str13, "%s", ptr4->commodityName);
						sprintf_s(str14, "%d个", ptr4->unitCount);
						if (ptr4->purchasePrice < 100)
						{
							sprintf_s(str15, "%.2lf元", ptr4->purchasePrice);
						}
						else if (ptr4->purchasePrice >= 100&& ptr4->purchasePrice<1000)
						{
							sprintf_s(str15, "%.2lf百元", ptr4->purchasePrice/100);
						}
						else
						{
							sprintf_s(str15, "%.2lf千元", ptr4->purchasePrice/1000);
						}
						if (ptr4->soldPrice < 100)
						{
							sprintf_s(str16, "%.2lf元", ptr4->soldPrice);
						}
						else if (ptr4->soldPrice >= 100 && ptr4->soldPrice < 1000)
						{
							sprintf_s(str16, "%.2lf百元", ptr4->soldPrice / 100);
						}
						else
						{
							sprintf_s(str16, "%.2lf千元", ptr4->soldPrice / 1000);
						}
						setcolor(BLACK);
						xianadminLookCommodity();
						outtextxy(-100, -350, str13);
						outtextxy(-125, -270, str14);
						outtextxy(90, -30, str15);
						outtextxy(140, -210, str16);
						calculate = recordHead;
						while (calculate)
						{
							if (calculate->situation == 0 || calculate->situation == 1)
							{
								M += calculate->unitCount;
							}
							calculate = calculate->nextRecord;
						}
						calculate = recordHead;
						while (calculate)
						{
							if ((calculate->situation == 0 || calculate->situation == 1)&& strcmp(calculate->commodityName,ptr4->commodityName) == 0)
							{
								N += calculate->unitCount;
							}
							calculate = calculate->nextRecord;
						}
						if (N == 0)
						{
							outtextxy(0, -200, "未");
							outtextxy(0, -170, "售");
							outtextxy(0, -140, "出");
						}
						else
						{
							line(-20, -115, 0, -115);
							line(0, -115, 0, -50);
							line(-110, -110, 100 * cos(2 * pi * (N / M)) - 110, -100 * sin(2 * pi * (N / M)) - 110);
							outtextxy(10, -170, "销");
							outtextxy(10, -140, "售");
							outtextxy(10, -110, "占");
							outtextxy(10, -80, "比");
							sprintf_s(tempZB, "%.2lf",(N/M)*100);
							outtextxy(-40, -30, tempZB);
							outtextxy(20, -30, '%');
							floodfill(-60, -108, BLACK, FLOODFILLBORDER);

						}
						m = GetMouseMsg();//--在循环内获取鼠标
						if (m.x >= 280 && m.x <= 325 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-220, 40, -175, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr4->preCommodity == NULL)
								{
									MessageBox(hWnd, "这是第一个商品", " ", MB_OKCANCEL);
								}
								else
								{
									ptr4 = ptr4->preCommodity;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 350 && m.x <= 395 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-150, 40, -105, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr4->nextCommodity == NULL)
								{
									MessageBox(hWnd, "这是最后一个商品", " ", MB_OKCANCEL);
								}
								else
								{
									ptr4 = ptr4->nextCommodity;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 420 && m.x <= 465 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(-80, 10, -35, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								delCommodity(&commodityHead, &commodityTail, ptr4);
								rebuildCommodityFile(commodityHead);
								MessageBox(hWnd, "删除成功", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto loop4;
							}
						}
						else if (m.x >= 535 && m.x <= 580 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(35, 10, 80, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								Xuserl_1 = 0;
								Xuserl_2 = 0;
								Xuserl_3 = 0;//长度初始化
								Xidentify = 0;
								X_len_ = 0;
								judgeNum = 0;
								memset(userSignupName, 0, sizeof(userSignupName));//令字符串皆为空
								memset(userSignupNameTmp, 0, sizeof(userSignupNameTmp));
								memset(userSignupPwd1, 0, sizeof(userSignupPwd1));
								memset(userSignupPwd1Tmp, 0, sizeof(userSignupPwd1Tmp));
								memset(userSignupPwd2, 0, sizeof(userSignupPwd2));
								memset(userSignupPwd2Tmp, 0, sizeof(userSignupPwd2Tmp));
								memset(userIdentifyTmp, 0, sizeof(userIdentifyTmp));
								cleardevice(); pict();
								while (TRUE)
								{
									setcolor(BLACK);
									xianadmin();
									outtextxy(-100, -300, "请你输入商品名称");
									outtextxy(-50, -200, "输入进价");
									outtextxy(-62.5, -100, "请输入售价");
									outtextxy(-50, 0, "添加商品");
									outtextxy(-25, 100, "返回");
									//判空操作
									if (Xuserl_1 != 0)
									{
										outtextxy(150, -300, "_/");
									}
									//判空操作
									if (Xuserl_2 != 0)
									{
										outtextxy(150, -200, "_/");
									}
									//判空操作
									if (Xuserl_3 != 0)
									{
										outtextxy(150, -100, "_/");
									}
									m = GetMouseMsg();
									//鼠标移动到---输入商品名
									if (m.x >= 390 && m.x <= 610 && m.y >= 190 && m.y <= 230)
									{
										setlinecolor(BLACK);
										rectangle(-110, -310, 110, -270);
										//鼠标点击---输入商品名
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											InputBox(userSignupNameTmp, 50, "请写入商品名称（14位以内,14个字符或7个汉字），包含字符和数字和汉字）", NULL, NULL, 0, 0, false);
											X_userl_1 = strnlen_s(userSignupNameTmp, sizeof(userSignupNameTmp));
											if ((isStandardText(userSignupNameTmp) && (X_userl_1 <= 14) )|| X_userl_1 == 0)
											{
												strcpy_s(userSignupName, userSignupNameTmp);
												Xuserl_1 = strnlen_s(userSignupName, sizeof(userSignupName));
											}
											else
											{
												MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
											}
										}
									}
									//鼠标移动到---输入进价
									else if (m.x >= 440 && m.x <= 560 && m.y >= 290 && m.y <= 330)
									{
										setlinecolor(BLACK);
										rectangle(-60, -210, 60, -170);
										//鼠标点击---输入进价
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											InputBox(userSignupPwd1Tmp, 50, "请写入进价（40位以内，必须是带小数点的浮点数)", NULL, NULL, 0, 0, false);
											X_userl_2 = strnlen_s(userSignupPwd1Tmp, sizeof(userSignupPwd1Tmp));
											if (isStandardFloat(userSignupPwd1Tmp) && X_userl_2 <= 40)
											{
												if (strToDouble(userSignupPwd1Tmp) >= 10000)
												{
													MessageBox(hWnd, "价格不能够大于等于10000", " ", MB_OKCANCEL);
												}
												else
												{
													strcpy_s(userSignupPwd1, userSignupPwd1Tmp);
													Xuserl_2 = strnlen_s(userSignupPwd1, sizeof(userSignupPwd1));
												}
											}
											else
											{
												MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
											}
										}
									}
									//鼠标移动输入售价
									else if (m.x >= 427.5 && m.x <= 572.5 && m.y >= 390 && m.y <= 430)
									{
										setlinecolor(BLACK);
										rectangle(-72.5, -110, 72.5, -70);
										//鼠标点击输入售价
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											InputBox(userSignupPwd2Tmp, 50, "请写入售价（40位以内，必须是带小数点的浮点数)", NULL, NULL, 0, 0, false);
											X_userl_3 = strnlen_s(userSignupPwd2Tmp, sizeof(userSignupPwd2Tmp));
											if (isStandardFloat(userSignupPwd2Tmp) && X_userl_3 <= 40)
											{
												if (strToDouble(userSignupPwd2Tmp) >= 10000)
												{
													MessageBox(hWnd, "价格不能够大于等于10000", " ", MB_OKCANCEL);
												}
												else
												{
													strcpy_s(userSignupPwd2, userSignupPwd2Tmp);
													Xuserl_3 = strnlen_s(userSignupPwd2, sizeof(userSignupPwd2));
												}
											}
											else
											{
												MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
											}
										}
									}
									//鼠标移动到添加商品
									else if (m.x >= 440 && m.x <= 560 && m.y >= 490 && m.y <= 530)
									{
										setlinecolor(BLACK);
										rectangle(-60, -10, 60, 30);
										//鼠标点击添加商品
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											judgeNum = 0;
											//判空
											if (Xuserl_1 != 0 && Xuserl_2 == 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "请输入进价和售价", " ", MB_OKCANCEL);
											}
											//判空
											else if (Xuserl_1 == 0 && Xuserl_2 != 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "请输入商品名并输入售价", " ", MB_OKCANCEL);
											}//判空
											//判空
											else if (Xuserl_1 == 0 && Xuserl_2 == 0 && Xuserl_3 != 0)
											{
												MessageBox(hWnd, "请输入商品名和进价", " ", MB_OKCANCEL);
											}
											//判空
											else if (Xuserl_1 == 0 && Xuserl_2 != 0 && Xuserl_3 != 0)
											{
												MessageBox(hWnd, "请输入商品名", " ", MB_OKCANCEL);
											}
											//判空
											else if (Xuserl_1 != 0 && Xuserl_2 == 0 && Xuserl_3 != 0)
											{
												MessageBox(hWnd, "请输入进价", " ", MB_OKCANCEL);
											}
											//判空
											else if (Xuserl_1 != 0 && Xuserl_2 != 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "请再次输入售价", " ", MB_OKCANCEL);
											}
											//判空
											else if (Xuserl_1 == 0 && Xuserl_2 == 0 && Xuserl_3 == 0)
											{
												MessageBox(hWnd, "请输入商品名，进价和售价", " ", MB_OKCANCEL);
											}
											//正式操作
											else
											{
												if (strToDouble(userSignupPwd2Tmp) <= strToDouble(userSignupPwd1Tmp))
												{
													MessageBox(hWnd, "售价不能小于等于进价", " ", MB_OKCANCEL);
												}
												else
												{
													judge = commodityHead;
													while (judge)
													{
														if (strcmp(userSignupName, judge->commodityName) == 0)
														{
															judgeNum = 1;
														}
														judge = judge->nextCommodity;
													}
													judge = NULL;
													if (judgeNum == 0)
													{
														addCommodity(&commodityHead, &commodityTail, userSignupName, strToDouble(userSignupPwd2), strToDouble(userSignupPwd1), 0);
														rebuildCommodityFile(commodityHead);
														MessageBox(hWnd, "添加成功", " ", MB_OK);
														cleardevice(); pict();
														goto loop4;
													}
													else
													{
														MessageBox(hWnd, "商品已存在", " ", MB_OK);
													}
												}
											}
										}
									}
									//鼠标移动到返回
									else if (m.x >= 465 && m.x <= 535 && m.y >= 590 && m.y <= 630)
									{
										setlinecolor(BLACK);
										rectangle(-35, 90, 35, 130);
										//鼠标点击返回
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											cleardevice(); pict();
											break;
										}
									}
									//鼠标移动到方框之外
									else
									{
										setlinecolor(WHITE);
										rectangle(-60, -210, 60, -170);
										rectangle(-72.5, -110, 72.5, -70);
										rectangle(-60, -10, 60, 30);
										rectangle(-35, 90, 35, 130);
										rectangle(-110, -310, 110, -270);
									}
								}

							}
						}
						else if (m.x >= 605 && m.x <= 650 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(105, 10, 150, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
							loop5:
								cleardevice(); pict();
								buildUserRecordChainC(recordHead, &userRecordHeadC, &userRecordTailC, ptr4->commodityName);
								yearTmp3 = 0;
								monthTmp3 = 0;
								dayTmp3 = 0;
								userOriginMoneyTmp1 = 0;
								userFinalMoneyTmp1 = 0;
								userBuyNumber1 = 0;
								memset(str17, 0, sizeof(str17));
								memset(str18, 0, sizeof(str18));
								memset(str19, 0, sizeof(str19));
								ptr5 = userRecordHeadC;
								if (ptr5 == NULL)
								{
									MessageBox(hWnd, "暂无相关记录", " ", MB_OKCANCEL);
								}
								else
								{
									while (TRUE)
									{
										setcolor(BLACK);
										xianadmin();
										yearTmp3 = ptr5->ptr->year;
										monthTmp3 = ptr5->ptr->month;
										dayTmp3 = ptr5->ptr->day;
										userOriginMoneyTmp1 = ptr5->ptr->soldPrice;
										if (getClientPtrFromName(ptr5->ptr->clientName)->isCostumer == 0)
										{
											if (ptr5->ptr->historyLv == 0)
											{
												tempDiscount = 1;
											}
											else if (ptr5->ptr->historyLv == 1)
											{
												tempDiscount = 0.95;
											}
											else if (ptr5->ptr->historyLv == 2)
											{
												tempDiscount = 0.9;
											}
											else if (ptr5->ptr->historyLv == 3)
											{
												tempDiscount = 0.85;
											}
											else if (ptr5->ptr->historyLv == 4)
											{
												tempDiscount = 0.8;
											}
											else
											{
												tempDiscount = 0.75;
											}
										}
										else
										{
											if (ptr5->ptr->historyLv == 0)
											{
												tempDiscount = 1;
											}
											else if (ptr5->ptr->historyLv == 1)
											{
												tempDiscount = 0.9;
											}
											else if (ptr5->ptr->historyLv == 2)
											{
												tempDiscount = 0.85;
											}
											else if (ptr5->ptr->historyLv == 3)
											{
												tempDiscount = 0.8;
											}
											else if (ptr5->ptr->historyLv == 4)
											{
												tempDiscount = 0.75;
											}
											else
											{
												tempDiscount = 0.7;
											}
										}
										userFinalMoneyTmp1 = userOriginMoneyTmp1 * tempDiscount;
										userBuyNumber1 = ptr5->ptr->unitCount;
										sprintf_s(str17, "商品名称:%s", ptr5->ptr->commodityName);
										if (userOriginMoneyTmp1 < 100 && userFinalMoneyTmp1 < 100)
										{
											sprintf_s(str18, "售价:%.2lf元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp1, userFinalMoneyTmp1, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 < 100 && userFinalMoneyTmp1 >= 100 && userFinalMoneyTmp1 < 1000)
										{
											sprintf_s(str18, "售价:%.2lf元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp1, userFinalMoneyTmp1/ 100, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 < 100 && userFinalMoneyTmp1 >= 1000)
										{
											sprintf_s(str18, "售价:%.2lf元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp1, userFinalMoneyTmp1 / 1000, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 100 && userOriginMoneyTmp1 < 1000 && userFinalMoneyTmp1 < 100)
										{
											sprintf_s(str18, "售价:%.2lf百元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp1 / 100, userFinalMoneyTmp1, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 100 && userOriginMoneyTmp1< 1000 && userFinalMoneyTmp1 >= 100 && userFinalMoneyTmp1 < 1000)
										{
											sprintf_s(str18, "售价:%.2lf百元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp1 / 100, userFinalMoneyTmp1 / 100, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 100 && userOriginMoneyTmp1 < 1000 && userFinalMoneyTmp1 >= 1000)
										{
											sprintf_s(str18, "售价:%.2lf百元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp1 / 100, userFinalMoneyTmp1 / 1000, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 1000 && userFinalMoneyTmp1 < 100)
										{
											sprintf_s(str18, "售价:%.2lf千元 折后:%.2lf元 总数:%d个", userOriginMoneyTmp1 / 1000, userFinalMoneyTmp1, userBuyNumber1);
										}
										else if (userOriginMoneyTmp1 >= 1000 && userFinalMoneyTmp1>= 100 && userFinalMoneyTmp1 < 1000)
										{
											sprintf_s(str18, "售价:%.2lf千元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmp1 / 1000, userFinalMoneyTmp1 / 100, userBuyNumber1);
										}
										else
										{
											sprintf_s(str18, "售价:%.2lf千元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmp1 / 1000, userFinalMoneyTmp1 / 1000, userBuyNumber1);
										}
										sprintf_s(str19, "%d年%d月%d日", yearTmp3, monthTmp3, dayTmp3);
										outtextxy(-100, -300, str17);
										outtextxy(-220, -200, str18);
										outtextxy(-100, -100, str19);
										line(-230, 0, 230, 0);
										outtextxy(-200, 30, "上一条记录");
										outtextxy(-200, 90, "删除记录");
										outtextxy(50, 30, "下一条记录");
										outtextxy(50, 90, "返回上级");
										outtextxy(0, -40, ptr5->ptr->clientName);
										if (ptr5->ptr->situation == 1)
										{
											outtextxy(-200, -350, "请您尽快处理其退款请求");
										}
										else if (ptr5->ptr->situation == 2)
										{
											outtextxy(-200, -350, "处理完成，已退款");
										}
										else
										{
											outtextxy(-200, -350, "未申请售后");
										}
										m = GetMouseMsg();//--在循环内获取鼠标
										if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
										{
											setlinecolor(BLACK);
											rectangle(-210, 20, -40, 60);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												if (ptr5->preRecord == NULL)
												{
													MessageBox(hWnd, "这是第一个记录", " ", MB_OKCANCEL);
												}
												else
												{
													ptr5 = ptr5->preRecord;
												}
											}
										}
										else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-210, 80, -40, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												temp = ptr5->ptr;
												delRecord(&recordHead, &recordTail, temp);
												rebuildRecordFile(recordHead);
												buildUserRecordChainC(recordHead, &userRecordHeadC, &userRecordTailC, ptr4->commodityName);
												ptr5 = userRecordHeadC;
												MessageBox(hWnd, "删除成功", " ", MB_OKCANCEL);
												cleardevice(); pict();
												goto loop5;
											}
										}
										else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
										{
											setlinecolor(BLACK);
											rectangle(40, 20, 210, 60);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												if (ptr5->nextRecord == NULL)
												{
													MessageBox(hWnd, "这是最后一个记录", " ", MB_OKCANCEL);
												}
												else
												{
													ptr5 = ptr5->nextRecord;
												}
											}
										}
										else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(40, 80, 210, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-210, 20, -40, 60);
											rectangle(-210, 80, -40, 120);
											rectangle(40, 20, 210, 60);
											rectangle(40, 80, 210, 120);
										}
									}
								}
							}
						}
						else if (m.x >= 675 && m.x <= 720 && m.y >= 580 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(175, 80, 220, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else if (m.x >= 610 && m.x <= 670 && m.y >= 195 && m.y <= 235)
						{
							setlinecolor(BLACK);
							rectangle(110, -300, 170, -265);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								InputBox(SumNumber, 50, "请写入进货数量,小于10000", NULL, NULL, 0, 0, false);
								_sum = strnlen_s(SumNumber,sizeof(SumNumber));
								if (_sum == 0)
								{
									;
								}
								else
								{
									if (isFullDigit(SumNumber)&& strToInt(SumNumber)>0&&_sum<=4)
									{
										ptr4->unitCount = ptr4->unitCount + strToInt(SumNumber);
										rebuildCommodityFile(commodityHead);
										MessageBox(hWnd, "进货成功", " ", MB_OKCANCEL);
										cleardevice(); pict();
									}
									else
									{
										MessageBox(hWnd, "非法输入，请重试", " ", MB_OKCANCEL);
									}
								}
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-220, 40, -175, 160);
							rectangle(-150, 40, -105, 160);
							rectangle(-80, 10, -35, 170);
							rectangle(35, 10, 80, 170);
							rectangle(105, 10, 150, 170);
							rectangle(175, 80, 220, 160);
							rectangle(110, -300, 170, -265);
					    }
					}
				}
			}
		}
		//鼠标移动到销售记录
		else if (m.x >= 340 && m.x <= 460 && m.y >= 390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(-160, -110, -40, -70);
			//鼠标点击到销售记录
			if (m.uMsg == WM_LBUTTONDOWN)
			{
			loop6:
				ptr6 = recordHead;
				cleardevice(); pict();
				memset(str20, 0, sizeof(str20));
				memset(str21, 0, sizeof(str21));
				memset(str22, 0, sizeof(str22));
				memset(str23, 0, sizeof(str23));
				memset(str24, 0, sizeof(str24));
				memset(str25, 0, sizeof(str25));
				memset(str26, 0, sizeof(str26));
				memset(str27, 0, sizeof(str27));
				if (ptr6 == NULL)
				{
					MessageBox(hWnd, "暂无销售记录", " ", MB_OKCANCEL);
				}
				else
				{
					while (TRUE)
					{
						setcolor(BLACK);
						xianadminLookRecord();
						sprintf_s(str20, "%d级", ptr6->historyLv);
						if (ptr6->purchasePrice < 100)
						{
							sprintf_s(str21, "%.2lf元", ptr6->purchasePrice);
						}
						else if (ptr6->purchasePrice >= 100 && ptr6->purchasePrice < 1000)
						{
							sprintf_s(str21, "%.2lf百元", ptr6->purchasePrice / 100);
						}
						else
						{
							sprintf_s(str21, "%.2lf千元", ptr6->purchasePrice / 1000);
						}
						if (ptr6->soldPrice < 100)
						{
							sprintf_s(str22, "%.2lf元", ptr6->soldPrice);
						}
						else if (ptr6->soldPrice >= 100 && ptr6->soldPrice < 1000)
						{
							sprintf_s(str22, "%.2lf百元", ptr6->soldPrice / 100);
						}
						else
						{
							sprintf_s(str22, "%.2lf千元", ptr6->soldPrice / 1000);
						}
						sprintf_s(str24, "%d个", ptr6->unitCount);
						if (getClientPtrFromName(ptr6->clientName))
						{
							if (getClientPtrFromName(ptr6->clientName)->isCostumer == 0)
							{
								if (ptr6->historyLv == 0)
								{
									tempDiscount = 1;
								}
								else if (ptr6->historyLv == 1)
								{
									tempDiscount = 0.95;
								}
								else if (ptr6->historyLv == 2)
								{
									tempDiscount = 0.9;
								}
								else if (ptr6->historyLv == 3)
								{
									tempDiscount = 0.85;
								}
								else if (ptr6->historyLv == 4)
								{
									tempDiscount = 0.8;
								}
								else
								{
									tempDiscount = 0.75;
								}
							}
							else
							{
								if (ptr6->historyLv == 0)
								{
									tempDiscount = 1;
								}
								else if (ptr6->historyLv == 1)
								{
									tempDiscount = 0.9;
								}
								else if (ptr6->historyLv == 2)
								{
									tempDiscount = 0.85;
								}
								else if (ptr6->historyLv == 3)
								{
									tempDiscount = 0.8;
								}
								else if (ptr6->historyLv == 4)
								{
									tempDiscount = 0.75;
								}
								else
								{
									tempDiscount = 0.7;
								}
							}
						}
						sprintf_s(str23, "%.2lf元", ptr6->soldPrice * tempDiscount);
						sprintf_s(str25, "%d年", ptr6->year);
						sprintf_s(str26, "%d月", ptr6->month);
						sprintf_s(str27, "%d日", ptr6->day);
						outtextxy(-130, -370, ptr6->clientName);
						outtextxy(-120, -290, ptr6->commodityName);
						outtextxy(-120, -210, str24);
						outtextxy(130, -120, str25);
						outtextxy(130, -80, str26);
						outtextxy(130, -40, str27);
						if (getClientPtrFromName(ptr6->clientName))
						{
							if (getClientPtrFromName(ptr6->clientName)->isCostumer == 0)
							{
								outtextxy(80, -160, "普通用户");
							}
							else
							{
								outtextxy(80, -160, "批发商");
							}
							if (ptr6->situation == 1)
							{
								outtextxy(-220, -70, "请处理退款请求");
							}
							else if (ptr6->situation == 2)
							{
								outtextxy(-220, -70, "处理完成，已退款");
							}
							else
							{
								outtextxy(-220, -70, "未申请售后");
							}
						}
						else
						{
							outtextxy(-220, -70, "用户已注销");
							memset(str21, 0, sizeof(str21));
							memset(str22, 0, sizeof(str22));
							memset(str23, 0, sizeof(str23));
							memset(str20, 0, sizeof(str20));
						}
						outtextxy(180, -370, str20);
						outtextxy(120, -330, str21);
						outtextxy(120, -280, str22);
						outtextxy(140, -230, str23);
						if (getCommodityPtrFromName(ptr6->commodityName) == NULL)
						{
							outtextxy(-220, -40, "商品已下架");
						}
						m = GetMouseMsg();//--在循环内获取鼠标
						if (m.x >= 280 && m.x <= 325 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-220, 40, -175, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr6->preRecord == NULL)
								{
									MessageBox(hWnd, "这是第一个记录", " ", MB_OKCANCEL);
								}
								else
								{
									ptr6 = ptr6->preRecord;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 350 && m.x <= 395 && m.y >= 540 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(-150, 40, -105, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (ptr6->nextRecord == NULL)
								{
									MessageBox(hWnd, "这是最后一个记录", " ", MB_OKCANCEL);
								}
								else
								{
									ptr6 = ptr6->nextRecord;
								}
								cleardevice(); pict();
							}
						}
						else if (m.x >= 420 && m.x <= 465 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(-80, 10, -35, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								temp = ptr6;
								delRecord(&recordHead, &recordTail, temp);
								rebuildRecordFile(recordHead);
								MessageBox(hWnd, "删除成功", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto loop6;
							}
						}
						else if (m.x >= 535 && m.x <= 580 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(35, 10, 80, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(str1, 0, sizeof(str1));
								memset(str2, 0, sizeof(str2));
								memset(str3, 0, sizeof(str3));
								ptr7 = NULL;
								ptr7 = getClientPtrFromName(ptr6->clientName);
								if (ptr7)
								{
									cleardevice(); pict();
									while (TRUE)
									{
										sprintf_s(str1, "%s", ptr7->clientName);
										sprintf_s(str2, "%d级", ptr7->lv);
										sprintf_s(str3, "%.2lf元", ptr7->balance);
										sprintf_s(str4, "%d年", ptr7->year);
										sprintf_s(str5, "%d月", ptr7->month);
										sprintf_s(str6, "%d日", ptr7->day);
										setcolor(BLACK);
										xianadminLookUserG();
										outtextxy(-120, -370, str1);
										outtextxy(115, -330, str2);
										outtextxy(-145, -300, str3);
										outtextxy(-120, -210, "注册日期");
										outtextxy(-120, -170, str4);
										outtextxy(-120, -130, str5);
										outtextxy(-120, -90, str6);
										if (ptr7->isCostumer == 0)
										{
											outtextxy(125, -280, "用户");
										}
										else
										{
											outtextxy(125, -280, "批发商");
										}
										if (ptr7->situation == 0)
										{
											outtextxy(115, -125, "未被");
										}
										else
										{
											outtextxy(115, -125, "已被");
										}
										m = GetMouseMsg();//--在循环内获取鼠标
										if (m.x >= 465 && m.x <= 535 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-35, 80, 35, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-35, 80, 35, 120);
										}
									}
								}
								else
								{
									MessageBox(hWnd, "该用户已注销", " ", MB_OKCANCEL);
								}
							}
						}
						else if (m.x >= 605 && m.x <= 650 && m.y >= 510 && m.y <= 670)
						{
							setlinecolor(BLACK);
							rectangle(105, 10, 150, 170);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								memset(str13, 0, sizeof(str13));
								memset(str14, 0, sizeof(str14));
								memset(str15, 0, sizeof(str15));
								memset(str16, 0, sizeof(str16));
								memset(tempZB, 0, sizeof(tempZB));
								ptr8 = NULL;
								ptr8 = getCommodityPtrFromName(ptr6->commodityName);
								if (ptr8)
								{
									cleardevice(); pict();
									while (TRUE)
									{
										M = 0;
										N = 0;
										sprintf_s(str13, "%s", ptr8->commodityName);
										sprintf_s(str14, "%d个", ptr8->unitCount);
										if (ptr8->purchasePrice < 100)
										{
											sprintf_s(str15, "%.2lf元", ptr8->purchasePrice);
										}
										else if (ptr8->purchasePrice >= 100 && ptr8->purchasePrice < 1000)
										{
											sprintf_s(str15, "%.2lf百元", ptr8->purchasePrice / 100);
										}
										else
										{
											sprintf_s(str15, "%.2lf千元", ptr8->purchasePrice / 1000);
										}
										if (ptr8->soldPrice < 100)
										{
											sprintf_s(str16, "%.2lf元", ptr8->soldPrice);
										}
										else if (ptr8->soldPrice >= 100 && ptr8->soldPrice < 1000)
										{
											sprintf_s(str16, "%.2lf百元", ptr8->soldPrice / 100);
										}
										else
										{
											sprintf_s(str16, "%.2lf千元", ptr8->soldPrice / 1000);
										}
										setcolor(BLACK);
										xianadminLookCommodityG();
										outtextxy(-100, -350, str13);
										outtextxy(-125, -270, str14);
										outtextxy(90, -30, str15);
										outtextxy(150, -210, str16);
										calculate = recordHead;
										while (calculate)
										{
											if (calculate->situation == 0 || calculate->situation == 1)
											{
												M += calculate->unitCount;
											}
											calculate = calculate->nextRecord;
										}
										calculate = recordHead;
										while (calculate)
										{
											if ((calculate->situation == 0 || calculate->situation == 1) && strcmp(calculate->commodityName, ptr6->commodityName) == 0)
											{
												N += calculate->unitCount;
											}
											calculate = calculate->nextRecord;
										}
										if (N == 0)
										{
											outtextxy(0, -200, "未");
											outtextxy(0, -170, "售");
											outtextxy(0, -140, "出");
										}
										else
										{
											line(-20, -115, 0, -115);
											line(0, -115, 0, -50);
											line(-110, -110, 100 * cos(2 * pi * (N / M)) - 110, -100 * sin(2 * pi * (N / M)) - 110);
											outtextxy(10, -170, "销");
											outtextxy(10, -140, "售");
											outtextxy(10, -110, "占");
											outtextxy(10, -80, "比");
											sprintf_s(tempZB, "%.2lf", (N / M) * 100);
											outtextxy(-40, -30, tempZB);
											outtextxy(20, -30, '%');
											floodfill(-60, -112, BLACK, FLOODFILLBORDER);
										}
										m = GetMouseMsg();//--在循环内获取鼠标
										if (m.x >= 465 && m.x <= 535 && m.y >= 580 && m.y <= 620)
										{
											setlinecolor(BLACK);
											rectangle(-35, 80, 35, 120);
											if (m.uMsg == WM_LBUTTONDOWN)
											{
												cleardevice(); pict();
												break;
											}
										}
										else
										{
											setlinecolor(WHITE);
											rectangle(-35, 80, 35, 120);
										}
									}
								}
								else
								{
									MessageBox(hWnd, "该商品已下架", " ", MB_OKCANCEL);
								}
							}
						}
						else if (m.x >= 675 && m.x <= 720 && m.y >= 580 && m.y <= 660)
						{
							setlinecolor(BLACK);
							rectangle(175, 80, 220, 160);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-220, 40, -175, 160);
							rectangle(-150, 40, -105, 160);
							rectangle(-80, 10, -35, 170);
							rectangle(35, 10, 80, 170);
							rectangle(105, 10, 150, 170);
							rectangle(175, 80, 220, 160);
						}
					}
				}
			}
		}
		//鼠标移动到退货申请
		else if (m.x >= 540 && m.x <= 660 && m.y >=390 && m.y <= 430)
		{
			setlinecolor(BLACK);
			rectangle(40, -110, 160, -70);
			//鼠标点击退货申请
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				buildUserRecordChainT(recordHead, &userRecordHeadT, &userRecordTailT);
			loop3:
				cleardevice(); pict();
				memset(userCommodityNameT, 0, sizeof(userCommodityNameT));
				yearTmp2 = 0;
				monthTmp2 = 0;
				dayTmp2 = 0;
				userOriginMoneyTmpT = 0;
				userFinalMoneyTmpT = 0;
				userBuyNumberT = 0;
				memset(str10, 0, sizeof(str10));
				memset(str11, 0, sizeof(str11));
				memset(str12, 0, sizeof(str12));
				ptr3 = userRecordHeadT;
				if (ptr3 == NULL)
				{
					MessageBox(hWnd, "暂无退货申请", " ", MB_OKCANCEL);
				}
				else
				{
					while (TRUE)
					{
						setcolor(BLACK);
						xianadmin();
						yearTmp2 = ptr3->ptr->year;
						monthTmp2 = ptr3->ptr->month;
						dayTmp2 = ptr3->ptr->day;
						userOriginMoneyTmpT = ptr3->ptr->soldPrice;
						if (getClientPtrFromName(ptr3->ptr->clientName)->isCostumer==0)
						{
							if (ptr3->ptr->historyLv == 0)
							{
								tempDiscount = 1;
							}
							else if (ptr3->ptr->historyLv==1)
							{
								tempDiscount = 0.95;
							}
							else if (ptr3->ptr->historyLv==2)
							{
								tempDiscount = 0.9;
							}
							else if (ptr3->ptr->historyLv==3)
							{
								tempDiscount = 0.85;
							}
							else if (ptr3->ptr->historyLv==4)
							{
								tempDiscount = 0.8;
							}
							else
							{
								tempDiscount = 0.75;
							}
						}
						else
						{
							if (ptr3->ptr->historyLv==0)
							{
								tempDiscount = 1;
							}
							else if (ptr3->ptr->historyLv==1)
							{
								tempDiscount = 0.9;
							}
							else if (ptr3->ptr->historyLv==2)
							{
								tempDiscount = 0.85;
							}
							else if (ptr3->ptr->historyLv==3)
							{
								tempDiscount = 0.8;
							}
							else if (ptr3->ptr->historyLv==4)
							{
								tempDiscount = 0.75;
							}
							else
							{
								tempDiscount = 0.7;
							}
						}
						userFinalMoneyTmpT = userOriginMoneyTmpT * tempDiscount;
						userBuyNumberT = ptr3->ptr->unitCount;
						strcpy_s(userCommodityNameT, ptr3->ptr->commodityName);
						sprintf_s(str10, "商品名称:%s", userCommodityNameT);
						if (userOriginMoneyTmpT < 100 && userFinalMoneyTmpT < 100)
						{
							sprintf_s(str11, "售价:%.2lf元 折后:%.2lf元 总数:%d个", userOriginMoneyTmpT, userFinalMoneyTmpT,userBuyNumberT);
						}
						else if (userOriginMoneyTmpT < 100 && userFinalMoneyTmpT >= 100 && userFinalMoneyTmpT < 1000)
						{
							sprintf_s(str11, "售价:%.2lf元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmpT, userFinalMoneyTmpT / 100, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT < 100 && userFinalMoneyTmpT >= 1000)
						{
							sprintf_s(str11, "售价:%.2lf元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmpT, userFinalMoneyTmpT / 1000, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 100 && userOriginMoneyTmpT < 1000 && userFinalMoneyTmpT < 100)
						{
							sprintf_s(str11, "售价:%.2lf百元 折后:%.2lf元 总数:%d个", userOriginMoneyTmpT / 100, userFinalMoneyTmpT, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 100 && userOriginMoneyTmpT < 1000 && userFinalMoneyTmpT >= 100 && userFinalMoneyTmpT < 1000)
						{
							sprintf_s(str11, "售价:%.2lf百元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmpT / 100, userFinalMoneyTmpT/ 100, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 100 && userOriginMoneyTmpT < 1000 && userFinalMoneyTmpT >= 1000)
						{
							sprintf_s(str11, "售价:%.2lf百元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmpT / 100, userFinalMoneyTmpT / 1000, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 1000 && userFinalMoneyTmpT < 100)
						{
							sprintf_s(str11, "售价:%.2lf千元 折后:%.2lf元 总数:%d个", userOriginMoneyTmpT / 1000, userFinalMoneyTmpT, userBuyNumberT);
						}
						else if (userOriginMoneyTmpT >= 1000 && userFinalMoneyTmpT >= 100 && userFinalMoneyTmpT < 1000)
						{
							sprintf_s(str11, "售价:%.2lf千元 折后:%.2lf百元 总数:%d个", userOriginMoneyTmpT / 1000, userFinalMoneyTmpT / 100, userBuyNumberT);
						}
						else
						{
							sprintf_s(str11, "售价:%.2lf千元 折后:%.2lf千元 总数:%d个", userOriginMoneyTmpT / 1000, userFinalMoneyTmpT / 1000, userBuyNumberT);
						}
						sprintf_s(str12, "%d年%d月%d日", yearTmp2, monthTmp2, dayTmp2);
						outtextxy(-100, -300, str10);
						outtextxy(-220, -200, str11);
						outtextxy(-100, -100, str12);
						outtextxy(-200, -40, ptr3->ptr->clientName);
						line(-230, 0, 230, 0);
						outtextxy(-200, 30, "上一条申请");
						outtextxy(-200, 90, "准许退款");
						outtextxy(50, 30, "下一条申请");
						outtextxy(50, 90, "返回上级");
						m = GetMouseMsg();//--在循环内获取鼠标
						if (m.x >= 290 && m.x <= 460 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(-210, 20, -40, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (ptr3->preRecord == NULL)
								{
									MessageBox(hWnd, "这是第一个记录", " ", MB_OKCANCEL);
								}
								else
								{
									ptr3 = ptr3->preRecord;
								}
							}
						}
						else if (m.x >= 290 && m.x <= 460 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(-210, 80, -40, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								getClientPtrFromName(ptr3->ptr->clientName)->balance = getClientPtrFromName(ptr3->ptr->clientName)->balance + userFinalMoneyTmpT * userBuyNumberT;
								rebuildClientFile(clientHead);
								getCommodityPtrFromName(ptr3->ptr->commodityName)->unitCount = getCommodityPtrFromName(ptr3->ptr->commodityName)->unitCount + userBuyNumberT;
								rebuildCommodityFile(commodityHead);
								ptr3->ptr->situation = 2;
								rebuildRecordFile(recordHead);
								buildUserRecordChainT(recordHead, &userRecordHeadT, &userRecordTailT);
								MessageBox(hWnd, "退款成功", " ", MB_OKCANCEL);
								cleardevice(); pict();
								goto loop3;
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 520 && m.y <= 560)
						{
							setlinecolor(BLACK);
							rectangle(40, 20, 210, 60);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								if (ptr3->nextRecord == NULL)
								{
									MessageBox(hWnd, "这是最后一个记录", " ", MB_OKCANCEL);
								}

								else
								{
									ptr3 = ptr3->nextRecord;
								}
							}
						}
						else if (m.x >= 540 && m.x <= 710 && m.y >= 580 && m.y <= 620)
						{
							setlinecolor(BLACK);
							rectangle(40, 80, 210, 120);
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								cleardevice(); pict();
								break;
							}
						}
						else
						{
							setlinecolor(WHITE);
							rectangle(-210, 20, -40, 60);
							rectangle(-210, 80, -40, 120);
							rectangle(40, 20, 210, 60);
							rectangle(40, 80, 210, 120);
						}
					}
				}

			}
		}
		//鼠标移动到总览页面
		else if (m.x >= 340 && m.x <= 460 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(-160, -10, -40, 30);
			//鼠标点击总览页面
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(TIME, 0, sizeof(TIME));
				YEAR = 0;
				MONTH = 0;
				DAY = 0;
				tempPoint = 0;
				getCurrentTime(&YEAR, &MONTH, &DAY);
				sprintf_s(TIME, "%d年%d月%d日", YEAR, MONTH, DAY);
				cleardevice(); pict();
				while (TRUE)
				{
					setcolor(BLACK);
					xianzonglan();
					settextstyle(125, 60, "楷体", 0, 0, 500, 0, 0, 0);
					outtextxy(-390,-350," (@-@)");
					outtextxy(-390,-150, TIME);
					settextstyle(25, 12, "楷体", 0, 0, 500, 0, 0, 0);
					outtextxy(-390, 365, "查看本月盈亏明细");
					outtextxy(190, 365, "预测明日盈亏结果");
					outtextxy(-25, 365, "返回");
					m = GetMouseMsg();
					if (m.x >= 100 && m.x <= 320 && m.y >= 855 && m.y <= 895)
					{
						setlinecolor(BLACK);
						rectangle(-400, 355, -180, 395);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							YEAR = 0;
							MONTH = 0;
							DAY = 0;
							tempPoint = 0;
							getCurrentTime(&YEAR, &MONTH, &DAY);
							memset(str28, 0, sizeof(str28));
							cleardevice(); pict();
							while (TRUE)
							{
								setcolor(BLACK);
								xianzonglan();
								outtextxy(-25, 365, "返回");
								line(-400, -50, 400, -50);
								line(-390, -400, -390, 300);
								line(-390, -400, -400, -390);
								line(-390, -400, -380, -390);
								line(400, -50, 390, -60);
								line(400, -50, 390, -40);
								settextstyle(12, 6, "楷体", 0, 0, 500, 0, 0, 0);
								i = 1;
								ii = 25;
								for (; i <= 31; i++)
								{
									sprintf_s(str28, "%d", i);
									line(-390 + ii, -50 ,- 390 + ii, -60);
									outtextxy(-390 + ii, -45, str28);
									ii+=25;
								}
								i = 1;
								ii = 0;
								iii = 1600;
								for (; i <= 17; i++)
								{
									if (i == 9)
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										ii += 40;
										iii = iii - 200;
									}
									else
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										outtextxy(-375, -370 + ii, str28);
										ii += 40;
										iii = iii - 200;
									}
									
								}
								i = 1;
								ii = 25;
								iiii = 0;
								for (; i <= DAY; i++)
								{
									profile = 0;
									calculate1 = recordHead;
									while (calculate1)
									{
										if ((calculate1->year == YEAR && calculate1->month == MONTH && calculate1->day == i)&&(calculate1->situation==0||calculate1->situation==1)&& getClientPtrFromName(calculate1->clientName)&& getCommodityPtrFromName(calculate1->commodityName))
										{
											if (getClientPtrFromName(calculate1->clientName)->isCostumer == 0)
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.95;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.8;
												}
												else
												{
													tempDiscount = 0.75;
												}
											}
											else
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.8;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.75;
												}
												else
												{
													tempDiscount = 0.7;
												}
											}
											profile += ((calculate1->soldPrice) * tempDiscount - calculate1->purchasePrice)*(calculate1->unitCount);
										}
										sprintf_s(PROFILE, "%.2lf元", profile);
										calculate1 = calculate1->nextRecord;
									}
									setlinestyle(PS_SOLID, 2);
									if (i == 1)
									{
										tempPoint = profile;
										line(-390+ii,-(tempPoint/5)-50, -390 + ii, -(tempPoint / 5) - 50);
										ii = ii + 25;
									}
									else
									{
										line(-390 + ii-25, -(tempPoint / 5) - 50, -390 + ii, -(profile / 5) - 50);
										tempPoint = profile;
										ii = ii + 25;
									}
									setlinestyle(PS_SOLID, 1);
									if (i >= 1 && i <= 5)
									{
										if (i == 1)
										{
											iiii = 0;
										}
										outtextxy(-370, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 6 && i <= 10)
									{
										if (i == 6)
										{
											iiii = 0;
										}
										outtextxy(-270, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 11 && i <= 15)
									{
										if (i == 11)
										{
											iiii = 0;
										}
										outtextxy(-170, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 16 && i <= 20)
									{
										if (i == 16)
										{
											iiii = 0;
										}
										outtextxy(190, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 21 && i <= 25)
									{
										if (i == 21)
										{
											iiii = 0;
										}
										outtextxy(290, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else
									{
										if (i == 26)
										{
											iiii = 0;
										}
										outtextxy(390, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
								}
								outtextxy(-390, 310, "1:");
								outtextxy(-390, 330, "2:");
								outtextxy(-390, 350, "3:");
								outtextxy(-390, 370, "4:");
								outtextxy(-390, 390, "5:");
								outtextxy(-290, 310, "6:");
								outtextxy(-290, 330, "7:");
								outtextxy(-290, 350, "8:");
								outtextxy(-290, 370, "9:");
								outtextxy(-290, 390, "10:");
								outtextxy(-190, 310, "11:");
								outtextxy(-190, 330, "12:");
								outtextxy(-190, 350, "13:");
								outtextxy(-190, 370, "14:");
								outtextxy(-190, 390, "15:");
								outtextxy(170, 310, "16:");
								outtextxy(170, 330, "17:");
								outtextxy(170, 350, "18:");
								outtextxy(170, 370, "19:");
								outtextxy(170, 390, "20:");
								outtextxy(270, 310, "21:");
								outtextxy(270, 330, "22:");
								outtextxy(270, 350, "23:");
								outtextxy(270, 370, "24:");
								outtextxy(270, 390, "25:");
								outtextxy(370, 310, "26:");
								outtextxy(370, 330, "27:");
								outtextxy(370, 350, "28:");
								outtextxy(370, 370, "29:");
								outtextxy(370, 390, "30:");
								outtextxy(370, 410, "31:");
								settextstyle(25, 12, "楷体", 0, 0, 500, 0, 0, 0);
								m = GetMouseMsg();
								if (m.x >= 465 && m.x <= 535 && m.y >= 855 && m.y <= 895)
								{
									setlinecolor(BLACK);
									rectangle(-35, 355, 35, 395);
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										cleardevice(); pict();
										break;
									}
								}
								else
								{
									setlinecolor(WHITE);
									rectangle(-35, 355, 35, 395);
								}
							}
						}
					}
					else if (m.x >= 680 && m.x <=900 && m.y >= 855 && m.y <= 895)
					{
						setlinecolor(BLACK);
						rectangle(180, 355, 400, 395);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							while (TRUE)
							{
								setcolor(BLACK);
								xianzonglan();
								outtextxy(-25, 365, "返回");
								outtextxy(-25, 310, "预测");
								line(-400, -50, 400, -50);
								line(-390, -400, -390, 300);
								line(-390, -400, -400, -390);
								line(-390, -400, -380, -390);
								line(400, -50, 390, -60);
								line(400, -50, 390, -40);
								settextstyle(12, 6, "楷体", 0, 0, 500, 0, 0, 0);
								i = 1;
								ii = 25;
								for (; i <= 31; i++)
								{
									sprintf_s(str28, "%d", i);
									line(-390 + ii, -50, -390 + ii, -60);
									outtextxy(-390 + ii, -45, str28);
									ii += 25;
								}
								i = 1;
								ii = 0;
								iii = 1600;
								for (; i <= 17; i++)
								{
									if (i == 9)
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										ii += 40;
										iii = iii - 200;
									}
									else
									{
										sprintf_s(str28, "%d", iii);
										line(-390, -370 + ii, -380, -370 + ii);
										outtextxy(-375, -370 + ii, str28);
										ii += 40;
										iii = iii - 200;
									}

								}
								i = 1;
								ii = 25;
								iiii = 0;
								for (; i <= DAY; i++)
								{
									profile = 0;
									calculate1 = recordHead;
									while (calculate1)
									{
										if ((calculate1->year == YEAR && calculate1->month == MONTH && calculate1->day == i) && (calculate1->situation == 0 || calculate1->situation == 1) && getClientPtrFromName(calculate1->clientName) && getCommodityPtrFromName(calculate1->commodityName))
										{
											if (getClientPtrFromName(calculate1->clientName)->isCostumer == 0)
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.95;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.8;
												}
												else
												{
													tempDiscount = 0.75;
												}
											}
											else
											{
												if (calculate1->historyLv == 0)
												{
													tempDiscount = 1;
												}
												else if (calculate1->historyLv == 1)
												{
													tempDiscount = 0.9;
												}
												else if (calculate1->historyLv == 2)
												{
													tempDiscount = 0.85;
												}
												else if (calculate1->historyLv == 3)
												{
													tempDiscount = 0.8;
												}
												else if (calculate1->historyLv == 4)
												{
													tempDiscount = 0.75;
												}
												else
												{
													tempDiscount = 0.7;
												}
											}
											profile += ((calculate1->soldPrice) * tempDiscount - calculate1->purchasePrice) * (calculate1->unitCount);
										}
										sprintf_s(PROFILE, "%.2lf元", profile);
										MMONEY[i - 1] = profile;
										calculate1 = calculate1->nextRecord;
									}
									setlinestyle(PS_SOLID, 5);
									if (i == 1)
									{
										line(-390 + ii, -(profile / 5) - 50, -390 + ii, -(profile / 5) - 50);
										ii = ii + 25;
									}
									else
									{
										line(-390 + ii, -(profile / 5) - 50, -390 + ii, -(profile / 5) - 50);
										ii = ii + 25;
									}
									setlinestyle(PS_SOLID, 1);
									if (i >= 1 && i <= 5)
									{
										if (i == 1)
										{
											iiii = 0;
										}
										outtextxy(-370, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 6 && i <= 10)
									{
										if (i == 6)
										{
											iiii = 0;
										}
										outtextxy(-270, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 11 && i <= 15)
									{
										if (i == 11)
										{
											iiii = 0;
										}
										outtextxy(-170, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 16 && i <= 20)
									{
										if (i == 16)
										{
											iiii = 0;
										}
										outtextxy(190, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else if (i >= 21 && i <= 25)
									{
										if (i == 21)
										{
											iiii = 0;
										}
										outtextxy(290, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
									else
									{
										if (i == 26)
										{
											iiii = 0;
										}
										outtextxy(390, 310 + iiii, PROFILE);
										iiii = iiii + 20;
									}
								}
								outtextxy(-390, 310, "1:");
								outtextxy(-390, 330, "2:");
								outtextxy(-390, 350, "3:");
								outtextxy(-390, 370, "4:");
								outtextxy(-390, 390, "5:");
								outtextxy(-290, 310, "6:");
								outtextxy(-290, 330, "7:");
								outtextxy(-290, 350, "8:");
								outtextxy(-290, 370, "9:");
								outtextxy(-290, 390, "10:");
								outtextxy(-190, 310, "11:");
								outtextxy(-190, 330, "12:");
								outtextxy(-190, 350, "13:");
								outtextxy(-190, 370, "14:");
								outtextxy(-190, 390, "15:");
								outtextxy(170, 310, "16:");
								outtextxy(170, 330, "17:");
								outtextxy(170, 350, "18:");
								outtextxy(170, 370, "19:");
								outtextxy(170, 390, "20:");
								outtextxy(270, 310, "21:");
								outtextxy(270, 330, "22:");
								outtextxy(270, 350, "23:");
								outtextxy(270, 370, "24:");
								outtextxy(270, 390, "25:");
								outtextxy(370, 310, "26:");
								outtextxy(370, 330, "27:");
								outtextxy(370, 350, "28:");
								outtextxy(370, 370, "29:");
								outtextxy(370, 390, "30:");
								outtextxy(370, 410, "31:");
								/*
								if (DAY < 2)
								{
									MessageBox(hWnd, "这是本月第一天，暂时无法预测", " ", MB_OK);
								}
								else
								{
									i = 0;
									for (; i < DAY; i++)
									{
										FILE* ss;
										fopen_s(&ss, ".\\Data\\LinearReggression.txt", "w");
										if (ss)
										{
											for (; i < DAY; i++)
											{
												fprintf_s(ss, "%lf %lf\n", (i+1)*1.0, MMONEY[i]);
											}
											fclose(ss);
										}
									}
									double k=0, b=0;
									xianxing(&k, &b, DAY);
									printf("%lf %lf", k, b);
								}
								*/
								settextstyle(25, 12, "楷体", 0, 0, 500, 0, 0, 0);
								m = GetMouseMsg();
								if (m.x >= 465 && m.x <= 535 && m.y >= 855 && m.y <= 895)
								{
									setlinecolor(BLACK);
									rectangle(-35, 355, 35, 395);
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										cleardevice(); pict();
										break;
									}
								}
								else if (m.x >= 465 && m.x <= 535 && m.y >= 805 && m.y <= 845)
								{
									setlinecolor(BLACK);
									rectangle(-35, 305, 35, 345);
									if (m.uMsg == WM_LBUTTONDOWN)
									{
										memset(str29, 0, sizeof(str29));
										if (DAY < 2)
										{
											MessageBox(hWnd, "这是本月第一天，暂时无法预测", " ", MB_OK);
										}
										else
										{
											i = 0;
											for (; i < DAY; i++)
											{
												FILE* ss;
												fopen_s(&ss, ".\\Data\\LinearReggression.txt", "w");
												if (ss)
												{
													for (; i < DAY; i++)
													{
														fprintf_s(ss, "%lf %lf\n", (i + 1) * 1.0, MMONEY[i]);
													}
													fclose(ss);
												}
											}
											k = 0, b = 0;
											xianxing(&k, &b, DAY);
											sprintf_s(str29, "回归直线方程:y=  %lf * x %+lf", k,b);
											MessageBox(hWnd, str29, " ", MB_OK);
											memset(str29, 0, sizeof(str29));
											cleardevice(); pict();
											sprintf_s(str29, "预测您明日的营业额为:%lf元", k*(DAY+1)+b);
											MessageBox(hWnd, str29, " ", MB_OK);
											setcolor(GREEN);
											line(-390, (-b / 5) - 50, (31) * 25 - 390, ((-(k * (31) + b)) / 5) - 50);
											setlinecolor(BLACK);
										}
									}
								}
								else
								{
									setlinecolor(WHITE);
									rectangle(-35, 305, 35, 345);
									rectangle(-35, 355, 35, 395);
								}
							}
						}
					}
					else if (m.x >= 465 && m.x <= 535 && m.y >= 855 && m.y <= 895)
					{
						setlinecolor(BLACK);
						rectangle(-35, 355, 35, 395);
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							cleardevice(); pict();
							break;
						}
					}
					else
					{
						setlinecolor(WHITE);
						rectangle(-400, 355, -180, 395);
						rectangle(180, 355, 400, 395);
						rectangle(-35, 355, 35, 395);
					}
				}
			}
		}
		//鼠标移动到返回主页
		else if (m.x >= 540 && m.x <= 660 && m.y >= 490 && m.y <= 530)
		{
			setlinecolor(BLACK);
			rectangle(40, -10, 160, 30);
			//鼠标点击返回主页
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(adminCurrentName, 0, sizeof(adminCurrentName));
				memset(adminLoginName, 0, sizeof(adminLoginName));
				memset(adminLoginNameTmp, 0, sizeof(adminLoginNameTmp));
				memset(adminLoginPwd, 0, sizeof(adminLoginPwd));
				memset(adminLoginPwdTmp, 0, sizeof(adminLoginPwdTmp));
				auth2 = 0;
			}
		}
		//鼠标移动到查看工单
		else if (m.x >= 340 && m.x <= 460 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(-160, 90, -40, 130);
			//鼠标点击查看工单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				memset(TEXTtmp, 0, sizeof(TEXTtmp));
				memset(TEXT, 0, sizeof(TEXT));
				FILE* feedback;
				fopen_s(&feedback, ".\\Data\\RecordChainData\\feedback.txt", "r");
				if (feedback)
				{
					while (fscanf_s(feedback, "%s\n", TEXTtmp, 220) != EOF)
					{
						strcat_s(TEXT, 1 + strnlen_s(TEXT, sizeof(TEXT)) + strnlen_s(TEXTtmp, sizeof(TEXTtmp)), TEXTtmp);
						strcpy_s(TEXTtmp,"\n");
						strcat_s(TEXT, 1 + strnlen_s(TEXT, sizeof(TEXT)) + strnlen_s(TEXTtmp, sizeof(TEXTtmp)), TEXTtmp);
					}
					fclose(feedback);
					feedback = NULL;
				}
				if (strnlen_s(TEXT, sizeof(TEXT)) == 0)
				{
					MessageBox(hWnd, "暂无工单记录", " ", MB_OK);
				}
				else
				{
					MessageBox(hWnd, TEXT, "工单页面", MB_OK);
					if (MessageBox(hWnd, "是否清空工单", "", MB_OKCANCEL) == IDOK)
					{
						fopen_s(&feedback, ".\\Data\\RecordChainData\\feedback.txt", "w");
						if (feedback)
						{
							fclose(feedback);
							feedback = NULL;
							MessageBox(hWnd, "删除成功", " ", MB_OK);
						}
					}
				}
			}
		}
		//鼠标移动到退出程序
		else if (m.x >= 540 && m.x <= 660 && m.y >= 590 && m.y <= 630)
		{
			setlinecolor(BLACK);
			rectangle(40, 90, 160, 130);
			//鼠标点击退出
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				auth2 = 1;
			}
		}
		//鼠标移动到方框之外
		else
		{
			setlinecolor(WHITE);
			rectangle(-160, -210, -40, -170);
			rectangle(40, -210, 160, -170);
			rectangle(-160, -110, -40, -70);
			rectangle(40, -110, 160, -70);
			rectangle(-160, -10, -40, 30);
			rectangle(40, -10, 160, 30);
			rectangle(40, 90, 160, 130);
			rectangle(-160, 90, -40, 130);
		}
		if (auth2 == 0 || auth2 == 1)
		{
			cleardevice(); pict();
			break;
		}
	}
}
//--------------------