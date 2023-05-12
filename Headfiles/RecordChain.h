//--------------------
//以下为记录链表功能函数和结构体的声明
//--------------------

#ifndef _RECORDCHAIN_H_
#define _RECORDCHAIN_H_
#include <stdbool.h>

//--------------------
//记录结构体
struct RecordNode {
    bool isSoldOut;  // 区分进货，出货记录

    // commodityName是商品名称
    char commodityName[50];
    char clientName[50];
    int situation;
    int unitCount;
    int year, month, day;
    int historyLv;

    double purchasePrice, soldPrice; //进价，售价

    struct RecordNode* nextRecord, * preRecord;
    // struct RecordNode * toClientNode;
};
struct userRecordNode 
{
  struct RecordNode* ptr;
  struct userRecordNode* nextRecord, * preRecord;
};
//--------------------

//以下为构建记录链表的函数
void buildRecordChain(struct RecordNode** head, struct RecordNode** tail);
//以下为删除记录链表的函数
void delRecord(struct RecordNode** head, struct RecordNode** tail, struct RecordNode* p);
//以下为增加链表记录的函数
void addRecord(struct RecordNode** head, struct RecordNode** tail, char tempIsSoldOut, char commodityName[50], char clientName[50], double soldPrice, double purchasePrice, char tempUnitCount[50], int lv_);
//以下为重构记录文件的函数
void rebuildRecordFile(struct RecordNode* head);
//以下为构建用户购物记录的函数
void buildUserRecordChain(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail, char userName[50]);
//以下为构建退货记录记录的函数
void buildUserRecordChainT(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail);
//构建商品有关记录
void buildUserRecordChainC(struct RecordNode* HEAD, struct userRecordNode** head, struct userRecordNode** tail, char commodityName[50]);
#endif


