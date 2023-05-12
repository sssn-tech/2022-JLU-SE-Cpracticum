#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\GetTime.h"

//-------------------
//以下为客户链表构建函数
void buildClientChain(struct ClientNode** head, struct ClientNode** tail)
{
    FILE* clientFILE;
    fopen_s(&clientFILE,".\\Data\\ClientChainData\\ClientData.txt", "r");
    *head = *tail = NULL; // 先初始化防止不操作返回野值
    int opt;//操作
    if (clientFILE)
    {
        fscanf_s(clientFILE, "%d", &opt); // opt==-1为停止添加节点，==1为添加新节点
        struct ClientNode* pre = NULL, * now = NULL;
        while (opt == 1)
        {
            now = (struct ClientNode*)malloc(sizeof(struct ClientNode));
            now->nextClient= NULL; // 申请完空间直接把指针初始化
            now->preClient = NULL;
            // 以下代码用来录入每个记录的细节信息， 做成代码块方便折叠
            {
                fscanf_s(clientFILE,"%s",&now->clientName, 50);
                fscanf_s(clientFILE,"%d",&now->lv);
                fscanf_s(clientFILE,"%lf",&now->balance);
                fscanf_s(clientFILE,"%d %d %d",&now->year,&now->month,&now->day);
                fscanf_s(clientFILE,"%d",&now->isCostumer);
                fscanf_s(clientFILE,"%d",&now->situation);
                // fscanf("")
            }
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextClient = now;
                now->preClient = pre;
            }
            pre = now;
            fscanf_s(clientFILE, "%d", &opt);
        }
        *tail = now;
        fclose(clientFILE);
    }
    clientFILE = NULL;
}
//--------------------

//-------------------
//以下为删除客户的函数
void  delClient(struct ClientNode** head, struct ClientNode** tail, struct ClientNode* p)
{
    // ** head, ** tail是头尾指针的地址，直接对其解引用，然后加以修改
    // 注意，p是指向节点的指针，和head，tail不一样
    if (*head == p || *tail == p)
    {
        // 如果要删除的节点比较特殊，是头或尾节点
        if (*head == p && *tail == p)
        {
            // 要删除的节点既是头又是尾， 此时链表只有这一个元素
            free(*head);
            *head = *tail = NULL; // free后内存被清理，但是指针仍指向该地址，必须置空防bug
            return;
        }
        if (*head == p && *tail != p)
        {
            // 要删除的节点是头，但不是尾
            struct ClientNode* temp = *head;
            *head = (*head)->nextClient;
            (*head)->preClient = NULL;
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // 要删除的节点是尾，但不是头
            struct ClientNode* temp = *tail;
            *tail = (*tail)->preClient;
            (*tail)->nextClient = NULL;
            free(temp);
            return;
        }
    }
    // 如果删除的节点不是头或者尾的特殊情况
    // 注意，p是指向节点的指针，和head，tail不一样
    p->nextClient->preClient = p->preClient;
    p->preClient->nextClient = p->nextClient;
    free(p);
}
//-------------------

//--------------------
//以下为添加客户的函数
void addClient(struct ClientNode** head, struct ClientNode** tail,char clientNAME[], char tempLv[],int isCostumer)
{
    struct ClientNode* now = (struct ClientNode*)malloc(sizeof(struct ClientNode));
    now->preClient =NULL;    // 申请新节点第一件事就是指针初始化！非常重要！
    now->nextClient = NULL;
    now->balance = 0.00;    //新创建的用户余额为0
    if (*head == NULL && *tail == NULL)
    {
        // 增加链表第一个节点,该节点即是头又是尾
        *head = *tail = now;
        // 输入具体信息的代码块
        strcpy_s(now->clientName,clientNAME);
        now->lv = strToInt(tempLv);
        now->situation = 0;
        getCurrentTime(&now->year, &now->month, &now->day);
        now->isCostumer = isCostumer;
        return;
    }
    else {
        // 不是第一个节点，则只需接在最后节点(tail)的后面
        (*tail)->nextClient = now;
        now->preClient = *tail;
        *tail = now;
        // 输入具体信息
        strcpy_s(now->clientName, clientNAME);
        now->lv = strToInt(tempLv);
        now->situation = 0;
        getCurrentTime(&now->year, &now->month, &now->day);
        now->isCostumer = isCostumer;
        return;
    }
}
//--------------------

//--------------------
//以下为重构客户文件的函数
void rebuildClientFile(struct ClientNode* head)
{
    FILE* clientFile;
    fopen_s(&clientFile,".\\Data\\ClientChainData\\ClientData.txt", "w");
    if (clientFile)
    {
        while (head != NULL)
        {
            // 输出节点所有信息的代码块，在测试时，暂时只输出unit count
            {
                fprintf(clientFile, "1\n");
                fprintf_s(clientFile, "%s\n", head->clientName);
                fprintf_s(clientFile, "%d\n", head->lv);
                fprintf_s(clientFile, "%.2f\n", head->balance);
                fprintf_s(clientFile, "%d %d %d\n", head->year, head->month, head->day);
                fprintf_s(clientFile, "%d\n", head->isCostumer);
                fprintf_s(clientFile, "%d\n", head->situation);
                fprintf_s(clientFile, "\n");
                head = head->nextClient;
            }
        }
        fputs("-1", clientFile);
        fclose(clientFile);
    }
    clientFile = NULL;
}
//--------------------