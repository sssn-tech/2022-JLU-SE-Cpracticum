//--------------------
//程序开始前进行的操作
//--------------------

#ifndef _CHAINOPT_H_
#define _CHAINOPT_H_
void backupAll();// 程序开始前，先执行backupAll来备份文件数据
void releaseAll();// 程序开始前，先执行backupAll来备份文件数据
struct ClientNode* getClientPtrFromName(char yourName[]);//根据客户名获取客户链表指针
struct CommodityNode* getCommodityPtrFromName(char yourName[]);//根据商品名获取商品链表指针
#endif