#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"..\Headfiles\InputCheck.h"
#include"..\Headfiles\CommodityChain.h"
#include"..\Headfiles\GetTime.h"

//--------------------
//以下为商品链表构建函数
void buildCommodityChain(struct CommodityNode** head, struct CommodityNode** tail)
{
    FILE* commodityFILE;
    fopen_s(&commodityFILE,".\\Data\\CommodityChainData\\CommodityData.txt", "r");
    if (commodityFILE)
    {
        *head = *tail = NULL; // 先初始化防止不操作返回野值
        int opt;
        fscanf_s(commodityFILE, "%d", &opt); // opt==-1为停止添加节点，==1为添加新节点
        struct CommodityNode* pre = NULL, * now = NULL;
        while (opt == 1)
        {
            now = (struct CommodityNode*)malloc(sizeof(struct CommodityNode));
            now->nextCommodity = NULL; // 申请完空间直接把指针初始化
            now->preCommodity = NULL; // 申请完空间直接把指针初始化

            // 以下代码用来录入每个记录的细节信息， 做成代码块方便折叠
            {
                fscanf_s(commodityFILE, "%s", &now->commodityName, 50);
                fscanf_s(commodityFILE, "%lf", &now->purchasePrice);
                fscanf_s(commodityFILE, "%lf", &now->soldPrice);
                fscanf_s(commodityFILE, "%d", &now->unitCount);
                // fscanf("")
            }

            if (*head == NULL)
            {
                *head = now;

            }
            else {
                pre->nextCommodity = now;
                now->preCommodity = pre;
            }
            pre = now;
            fscanf_s(commodityFILE, "%d", &opt);
        }
        *tail = now;

        fclose(commodityFILE);
    }
    commodityFILE = NULL;
}
//--------------------

//--------------------
//以下为删除商品的函数
void  delCommodity(struct CommodityNode** head, struct CommodityNode** tail, struct CommodityNode* p)
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
            struct CommodityNode* temp = *head;
            *head = (*head)->nextCommodity;
            (*head)->preCommodity = NULL;
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // 要删除的节点是尾，但不是头
            struct CommodityNode* temp = *tail;
            *tail = (*tail)->preCommodity;
            (*tail)->nextCommodity = NULL;
            free(temp);
            return;
        }
    }
    // 如果删除的节点不是头或者尾的特殊情况
    // 注意，p是指向节点的指针，和head，tail不一样
    p->nextCommodity->preCommodity = p->preCommodity;
    p->preCommodity->nextCommodity = p->nextCommodity;
    free(p);
}
//--------------------

//--------------------
//以下为添加商品的函数
void addCommodity(struct CommodityNode** head, struct CommodityNode** tail, char commodityName[50], double soldPrice, double purchasePrice, int unitCount)
{
    struct CommodityNode* now = (struct CommodityNode*)malloc(sizeof(struct CommodityNode));
    now->preCommodity =  NULL;    // 申请新节点第一件事就是指针初始化！非常重要！
    now->nextCommodity = NULL;
    if (*head == NULL && *tail == NULL)
    {
        *head = *tail = now;
        // 输入具体信息的代码块
        strcpy_s(now->commodityName, commodityName);
        now->purchasePrice = purchasePrice;
        now->soldPrice = soldPrice;
        now->unitCount = unitCount;
        return;
    }
    else {
        // 不是第一个节点，则只需接在最后节点(tail)的后面
        (*tail)->nextCommodity = now;
        now->preCommodity = *tail;
        *tail = now;
        // 输入具体信息
        strcpy_s(now->commodityName, commodityName);
        now->purchasePrice = purchasePrice;
        now->soldPrice = soldPrice;
        now->unitCount = unitCount;
        return;
    }
}
//--------------------

//--------------------
//以下为重构商品文件的函数
void rebuildCommodityFile(struct CommodityNode* head)
{
    FILE* commodityFile;
    fopen_s(&commodityFile,".\\Data\\CommodityChainData\\CommodityData.txt", "w");
    if (commodityFile)
    {
        while (head != NULL)
        {
            // 输出节点所有信息的代码块，在测试时，暂时只输出unit count
            {
                fprintf(commodityFile, "1\n");
                fprintf_s(commodityFile, "%s\n", head->commodityName);
                fprintf_s(commodityFile, "%.2f\n", head->purchasePrice);
                fprintf_s(commodityFile, "%.2f\n", head->soldPrice);
                fprintf_s(commodityFile, "%d\n", head->unitCount);
                fprintf_s(commodityFile, "\n");
                head = head->nextCommodity;
            }
        }
        fputs("-1", commodityFile);
        fclose(commodityFile);
    }
    commodityFile = NULL;
}
//--------------------
