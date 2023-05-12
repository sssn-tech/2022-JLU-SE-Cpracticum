//--------------------
//以下为客户链表功能函数和结构体的声明
//--------------------

#ifndef _CLIENTCHAIN_H_
#define _CLIENTCHAIN_H_
//--------------------
//以下为客户链表的结构体声明
struct ClientNode {
    int situation;//0未锁 1 已锁
    int isCostumer;    // 0 顾客，1 进货商
    double balance;     // 如果是顾客则有余额，新创建余额为0
    char clientName[50];
    int lv;
    int year, month, day;
    struct ClientNode* nextClient, * preClient;
};
//--------------------

//--------------------
//以下为功能函数
void buildClientChain(struct ClientNode** head, struct ClientNode** tail);//构建客户链表
void delClient(struct ClientNode** head, struct ClientNode** tail, struct ClientNode* p);//删除客户
void addClient(struct ClientNode** head, struct ClientNode** tail, char clientNAME[], char tempLv[],int isCostumer);//添加客户
void rebuildClientFile(struct ClientNode* head);//重构客户文件
//--------------------
#endif