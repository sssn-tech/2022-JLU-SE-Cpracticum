#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\RecordChain.h"
#include"..\Headfiles\ClientChain.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\GetTime.h"
#include"..\Headfiles\ChainOpt.h"

extern struct CommodityNode* commodityHead, * commodityTail;
extern struct userRecordNode* userRecordHead;
extern struct userRecordNode* userRecordTail;
//--------------------
//以下为构建记录链表的函数
void buildRecordChain(struct RecordNode** head, struct RecordNode** tail)
{
    // 以只读模式打开文件
    FILE* recordFILE;
    fopen_s(&recordFILE,".\\Data\\RecordChainData\\RecordData.txt", "r");
    *head = *tail = NULL; // 先初始化防止不操作返回野值
    struct RecordNode* pre = NULL, * now = NULL;
    if (recordFILE)
    {
        int opt;
        fscanf_s(recordFILE, "%d", &opt); // opt==-1为停止添加节点，==1为添加新节点
        while (opt == 1)
        {
            now = (struct RecordNode*)malloc(sizeof(struct RecordNode));
            now->preRecord = NULL; // 申请完空间直接把指针初始化
            now->nextRecord =NULL; // 申请完空间直接把指针初始化
            // 以下代码用来录入每个记录的细节信息， 做成代码块方便折叠
            {
                int temp;   // temp 用来给bool类型变量isSoldOut赋值
                fscanf_s(recordFILE, "%d", &temp);
                if (temp == 1)
                    now->isSoldOut = true;
                else
                    now->isSoldOut = false;
                fscanf_s(recordFILE, "%s", &now->commodityName, 50);
                fscanf_s(recordFILE, "%s", &now->clientName,50);
                fscanf_s(recordFILE, "%lf", &now->purchasePrice);
                fscanf_s(recordFILE, "%lf", &now->soldPrice);
                fscanf_s(recordFILE, "%d", &now->unitCount);
                fscanf_s(recordFILE, "%d", &now->historyLv);
                fscanf_s(recordFILE, "%d %d %d", &now->year, &now->month, &now->day);
                fscanf_s(recordFILE, "%d", &now->situation);
                // fscanf("")
            }

            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
            fscanf_s(recordFILE, "%d", &opt);
        }
        *tail = now;
        fclose(recordFILE);
    }
    recordFILE = NULL;
}
//--------------------

//--------------------
//以下为删除记录链表的函数
void  delRecord(struct RecordNode** head, struct RecordNode** tail, struct RecordNode* p)
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

            //此部分可能需要集成
            struct CommodityNode* searchPtr = commodityHead;
            while (searchPtr != NULL)
            {
                if (strcmp(searchPtr->commodityName, (*head)->commodityName) == 0)
                {
                    if ((*head)->isSoldOut == true)
                        searchPtr->unitCount += (*head)->unitCount;
                    else if ((*head)->isSoldOut == false)
                        searchPtr->unitCount -= (*head)->unitCount;
                }
                searchPtr = searchPtr->nextCommodity;
            }
            rebuildCommodityFile(commodityHead);
            *head = *tail = NULL; // free后内存被清理，但是指针仍指向该地址，必须置空防bug
            return;
        }
        if (*head == p && *tail != p)
        {
            // 要删除的节点是头，但不是尾
            struct RecordNode* temp = *head;
            *head = (*head)->nextRecord;
            (*head)->preRecord = NULL;

            //此部分可能需要集成
            struct CommodityNode* searchPtr = commodityHead;
            while (searchPtr != NULL)
            {
                if (strcmp(searchPtr->commodityName, temp->commodityName) == 0)
                {
                    if (temp->isSoldOut == true)
                        searchPtr->unitCount += temp->unitCount;
                    else if (temp->isSoldOut == false)
                        searchPtr->unitCount -= temp->unitCount;
                }
                searchPtr = searchPtr->nextCommodity;
            }
            rebuildCommodityFile(commodityHead);
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // 要删除的节点是尾，但不是头
            struct RecordNode* temp = *tail;
            *tail = (*tail)->preRecord;
            (*tail)->nextRecord = NULL;

            //此部分可能需要集成
            struct CommodityNode* searchPtr = commodityHead;
            while (searchPtr != NULL)
            {
                if (strcmp(searchPtr->commodityName, temp->commodityName) == 0)
                {
                    if (temp->isSoldOut == true)
                        searchPtr->unitCount += temp->unitCount;
                    else if (temp->isSoldOut == false)
                        searchPtr->unitCount -= temp->unitCount;
                }
                searchPtr = searchPtr->nextCommodity;
            }
            rebuildCommodityFile(commodityHead);
            free(temp);
            return;
        }
    }
    // 如果删除的节点不是头或者尾的特殊情况
    // 注意，p是指向节点的指针，和head，tail不一样
    p->nextRecord->preRecord = p->preRecord;
    p->preRecord->nextRecord = p->nextRecord;
    //将record中的变化适应到commodity中

    struct CommodityNode* searchPtr = commodityHead;
    while (searchPtr != NULL)
    {
        if (strcmp(searchPtr->commodityName, p->commodityName) == 0)
        {
            if (p->isSoldOut == true)
                searchPtr->unitCount += p->unitCount;
            else if (p->isSoldOut == false)
                searchPtr->unitCount -= p->unitCount;
        }
        searchPtr = searchPtr->nextCommodity;
    }
    rebuildCommodityFile(commodityHead);
    free(p);
}
//--------------------

//--------------------
//以下为增加链表记录的函数
void addRecord(struct RecordNode** head, struct RecordNode** tail,char tempIsSoldOut,char commodityName[50],char clientName[50], double soldPrice,double purchasePrice,char tempUnitCount[50],int lv_)
{
    struct RecordNode* now = (struct RecordNode*)malloc(sizeof(struct RecordNode));
    now->preRecord = now->nextRecord = NULL;    // 申请新节点第一件事就是指针初始化！非常重要！
    if (*head == NULL && *tail == NULL)
    {
        *head = *tail = now;
        // 输入具体信息的代码块
        // 此处应有比较复杂的非法输入检测
        {
            now->isSoldOut = (tempIsSoldOut == '1') ? true : false;
            now->situation = 0;
            now->historyLv = lv_;
            strcpy_s(now->commodityName, commodityName);
            strcpy_s(now->clientName, clientName);

            // 需要一个strToDouble函数！！！！
            now->soldPrice = soldPrice;
            now->purchasePrice = purchasePrice;
            // 以上需要
            now->unitCount = strToInt(tempUnitCount);
            getCurrentTime(&now->year, &now->month, &now->day);
        }
        return;
    }
    else {
        // 不是第一个节点，则只需接在最后节点(tail)的后面
        (*tail)->nextRecord = now;
        now->preRecord = *tail;
        *tail = now;

        // 输入具体信息
        // 此处应有比较复杂的非法输入检测
        
            now->isSoldOut = (tempIsSoldOut == '1') ? true : false;
            now->situation = 0;
            now->historyLv = lv_;
            strcpy_s(now->commodityName, commodityName);
            strcpy_s(now->clientName, clientName);

            // 需要一个strToDouble函数！！！！
            now->soldPrice = soldPrice;
            now->purchasePrice = purchasePrice;
            // 以上需要
            now->unitCount = strToInt(tempUnitCount);
            getCurrentTime(&now->year, &now->month, &now->day);
        return;
    }
}
//--------------------

//--------------------
//以下为重构记录文件的函数
void rebuildRecordFile(struct RecordNode* head) 
{
    // 当增链表节点发生变化时，执行此函数，覆写record.txt文件
    // 注意是覆写
    FILE* recordFile;
    fopen_s(&recordFile,".\\Data\\RecordChainData\\RecordData.txt", "w");
    if (recordFile)
    {
        while (head != NULL)
        {
            // 输出节点所有信息的代码块，在测试时，暂时只输出unit count
            {
                fprintf(recordFile, "1\n");
                if (head->isSoldOut == true)
                {
                    fprintf(recordFile, "1\n");
                }
                else
                {
                    fprintf(recordFile, "0\n");
                }
                fprintf(recordFile, "%s\n", head->commodityName);
                fprintf(recordFile, "%s\n", head->clientName);
                fprintf(recordFile, "%.2f\n", head->purchasePrice);
                fprintf(recordFile, "%.2f\n", head->soldPrice);
                fprintf(recordFile, "%d\n", head->unitCount);
                fprintf(recordFile, "%d\n", head->historyLv);
                fprintf(recordFile, "%d %d %d\n", head->year, head->month, head->day);
                fprintf(recordFile, "%d\n", head->situation);
                fprintf(recordFile, "\n");
                head = head->nextRecord;
            }
        }
        fputs("-1", recordFile);
        fclose(recordFile);
    }
    recordFile = NULL;
}
//--------------------

//--------------------
//以下为构建用户购物记录的函数
void buildUserRecordChain(struct RecordNode* HEAD,struct userRecordNode** head, struct userRecordNode** tail,char userName[50])
{
    *head = *tail = NULL; // 先初始化防止不操作返回野值
    struct RecordNode* temp=NULL;
    temp = HEAD;
    struct userRecordNode* pre = NULL, * now = NULL;
    while (temp)
    {
        if (strcmp(userName, temp->clientName)== 0 && getClientPtrFromName(temp->clientName) && getCommodityPtrFromName(temp->commodityName))
        {
            now = (struct userRecordNode*)malloc(sizeof(struct userRecordNode));
            now->nextRecord = NULL; // 申请完空间直接把指针初始化
            now->preRecord = NULL; // 申请完空间直接把指针初始化
            now->ptr = temp;
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
        }
        temp = temp->nextRecord;
    }
    *tail = now;
}
//--------------------

//--------------------
//以下为构建退货记录记录的函数
void buildUserRecordChainT(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail)
{
    *head = *tail = NULL; // 先初始化防止不操作返回野值
    struct RecordNode* temp = NULL;
    temp = HEAD;
    struct userRecordNode* pre = NULL, * now = NULL;
    while (temp)
    {
        if (temp->situation==1&& getClientPtrFromName(temp->clientName)&& getCommodityPtrFromName(temp->commodityName))
        {
            now = (struct userRecordNode*)malloc(sizeof(struct userRecordNode));
            now->nextRecord = NULL; // 申请完空间直接把指针初始化
            now->preRecord = NULL; // 申请完空间直接把指针初始化
            now->ptr = temp;
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
        }
        temp = temp->nextRecord;
    }
    *tail = now;
}
//--------------------

//--------------------
//以下为构建商品有关购物记录的函数
void buildUserRecordChainC(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail, char commodityName[50])
{
    *head = *tail = NULL; // 先初始化防止不操作返回野值
    struct RecordNode* temp = NULL;
    temp = HEAD;
    struct userRecordNode* pre = NULL, * now = NULL;
    while (temp)
    {
        if (strcmp(commodityName,temp->commodityName)==0 && getClientPtrFromName(temp->clientName) && getCommodityPtrFromName(temp->commodityName))
        {
            now = (struct userRecordNode*)malloc(sizeof(struct userRecordNode));
            now->nextRecord = NULL; // 申请完空间直接把指针初始化
            now->preRecord = NULL; // 申请完空间直接把指针初始化
            now->ptr = temp;
            if (*head == NULL)
            {
                *head = now;
            }
            else {
                pre->nextRecord = now;
                now->preRecord = pre;
            }
            pre = now;
        }
        temp = temp->nextRecord;
    }
    *tail = now;
}
//--------------------
