#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include "..\Headfiles\ChainOpt.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\RecordChain.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\CartChain.h"

//--------------------
//外部变量的引用 链表的头节点指针
extern struct RecordNode* recordHead;//记录链表头
extern struct ClientNode* clientHead;//客户链表头
extern struct CommodityNode* commodityHead;//商品链表头
extern struct CartNode* cartHead;//购物车链表
extern struct userRecordNode* userRecordHead;
extern struct userRecordNode* userRecordTail;
extern struct userRecordNode* userRecordHeadT;
extern struct userRecordNode* userRecordTailT;
extern struct userRecordNode* userRecordHeadC;
extern struct userRecordNode* userRecordTailC;
//--------------------
// 
//--------------------
//以下为备份函数
char ch;
void backupAll()
{
    //RecordData.txt备份记录文件
    FILE* recordFile;
    fopen_s(&recordFile,".\\Data\\RecordChainData\\RecordData.txt", "r");
    FILE* recordFile_backup;
    fopen_s(&recordFile_backup,".\\Data\\RecordChainData\\RecordData_backup.txt", "w");
    if (recordFile && recordFile_backup)
    {
       ch = fgetc(recordFile);
        while (ch != EOF)
        {
            fputc(ch, recordFile_backup);
            ch = fgetc(recordFile);
        }
        fclose(recordFile);     fclose(recordFile_backup);
    }
    recordFile = recordFile_backup = NULL;
    //feedback.txt备份记录文件
    FILE* feedFile;
    fopen_s(&feedFile, ".\\Data\\RecordChainData\\feedback.txt", "r");
    FILE* feedbkFile_backup;
    fopen_s(&feedbkFile_backup, ".\\Data\\RecordChainData\\feedback_backup.txt", "w");
    if (feedFile && feedbkFile_backup)
    {
        ch = fgetc(feedFile);
        while (ch != EOF)
        {
            fputc(ch, feedbkFile_backup);
            ch = fgetc(feedFile);
        }
        fclose(feedFile);     fclose(feedbkFile_backup);
    }
    recordFile = recordFile_backup = NULL;
    //ClientData.txt备份客户文件
    FILE* clientFile;
    fopen_s(&clientFile,".\\Data\\ClientChainData\\ClientData.txt", "r");
    FILE* clientFile_backup;
    fopen_s(&clientFile_backup,".\\Data\\ClientChainData\\ClientData_backup.txt", "w");
    if (clientFile && clientFile_backup)
    {
        ch = fgetc(clientFile);
        while (ch != EOF)
        {
            fputc(ch, clientFile_backup);
            ch = fgetc(clientFile);
        }
        fclose(clientFile);     fclose(clientFile_backup);
    }
    clientFile = clientFile_backup = NULL;
    //CommodityData.txt.txt备份商品文件
    FILE* commodityFile;
    fopen_s(&commodityFile,".\\Data\\CommodityChainData\\CommodityData.txt", "r");
    FILE* commodityFile_backup;
    fopen_s(&commodityFile_backup,".\\Data\\CommodityChainData\\CommodityData_backup.txt", "w");
    if (commodityFile && commodityFile_backup)
    {
        ch = fgetc(commodityFile);
        while (ch != EOF)
        {
            fputc(ch, commodityFile_backup);
            ch = fgetc(commodityFile);
        }
        fclose(commodityFile);     fclose(commodityFile_backup);
    }
    commodityFile = commodityFile_backup = NULL;
    //AdminData.txt备份管理员登录的账号密码
    FILE* adminDataFile;
    fopen_s(&adminDataFile,".\\Data\\loginData\\adminData.txt", "r");
    FILE* adminDataFile_backup;
    fopen_s(&adminDataFile_backup,".\\Data\\loginData\\adminData_backup.txt", "w");
    if (adminDataFile && adminDataFile_backup)
    {
        ch = fgetc(adminDataFile);
        while (ch != EOF)
        {
            fputc(ch, adminDataFile_backup);
            ch = fgetc(adminDataFile);
        }
        fclose(adminDataFile);     fclose(adminDataFile_backup);
    }
    adminDataFile = adminDataFile_backup = NULL;
    //UserData.txt备份用户登录的账号密码
    FILE* userDataFile;
    fopen_s(&userDataFile,".\\Data\\loginData\\userData.txt", "r");
    FILE* userDataFile_backup;
    fopen_s(&userDataFile_backup,".\\Data\\loginData\\userData_backup.txt", "w");
    if (userDataFile && userDataFile_backup)
    {
        ch = fgetc(userDataFile);
        while (ch != EOF)
        {
            fputc(ch, userDataFile_backup);
            ch = fgetc(userDataFile);
        }
        fclose(userDataFile);     fclose(userDataFile_backup);
    }
    userDataFile = userDataFile_backup = NULL;

}
//--------------------

//--------------------
//以下为内存释放函数
void releaseAll()
{
    // RecordChain释放
    struct RecordNode* p = recordHead;
    struct RecordNode* pp = NULL;
    while (p)
    {
        pp = p;
        p = p->nextRecord;
        free(pp);
    }
    // ClientChain释放
    struct ClientNode* q = clientHead;
    struct ClientNode* qq = NULL;
    while (q)
    {
        qq = q;
        q = q->nextClient;
        free(qq);
    }
    //CommodityChain释放
    struct CommodityNode* r = commodityHead;
    struct CommodityNode* rr = NULL;
    while (r)
    {
        rr = r;
        r = r->nextCommodity;
        free(rr);
    }
    //CartChain释放
    struct CartNode* t = cartHead;
    struct CartNode* tt = NULL;
    while (t)
    {
        tt = t;
        t = t->nextCart;
        free(tt);
    }
    //用户购物记录链表释放
    struct userRecordNode* s = userRecordHead;
    struct userRecordNode* ss = NULL;
    while (s)
    {
        ss = s;
        s = s->nextRecord;
        free(ss);
    }
    //退货记录链表
    struct userRecordNode* n = userRecordHeadT;
    struct userRecordNode* nn = NULL;
    while (n)
    {
        nn = n;
        n = n->nextRecord;
        free(nn);
    }
    struct userRecordNode* m = userRecordHeadC;
    struct userRecordNode* mm = NULL;
    while (m)
    {
        mm = m;
        m = m->nextRecord;
        free(mm);
    }
}
//-------------------

//--------------------
//以下为用户寻找函数
struct ClientNode* getClientPtrFromName(char yourName[])
{
    struct ClientNode* searchPtr = clientHead;
    struct ClientNode* res = NULL;
    while (searchPtr != NULL)
    {
        if (strcmp(searchPtr->clientName, yourName) == 0)
        {
            res = searchPtr;
            return res;
        }
        searchPtr = searchPtr->nextClient;
    }
    return res;
}
//--------------------

//-------------------
//此为获取商品指针的函数
struct CommodityNode* getCommodityPtrFromName(char yourName[])
{
    struct CommodityNode* searchPtr = commodityHead;
    struct CommodityNode* res = NULL;
    while (searchPtr != NULL)
    {
        if (strcmp(searchPtr->commodityName, yourName) == 0)
        {
            res = searchPtr;
            return res;
        }
        searchPtr = searchPtr->nextCommodity;
    }
    return res;
}
//--------------------