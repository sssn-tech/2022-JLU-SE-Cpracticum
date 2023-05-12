//--------------------
//以下为商品链表功能函数和结构体的声明
//--------------------

#ifndef _COMMODITYCHAIN_H_
#define _COMMODITYCHAIN_H_
//--------------------
//以下为结构体声明
struct CommodityNode {
    char commodityName[50];
    double soldPrice;
    double purchasePrice;
    int unitCount;//当前件数
    struct CommodityNode* nextCommodity, * preCommodity;
};
//--------------------

//--------------------
//以下为功能函数
void buildCommodityChain(struct CommodityNode** head, struct CommodityNode** tail);//构建商品链表
void delCommodity(struct CommodityNode** head, struct CommodityNode** tail, struct CommodityNode* p);//删除商品
void addCommodity(struct CommodityNode** head, struct CommodityNode** tail, char commodityName[50], double soldPrice, double purchasePrice, int unitCount);//添加商品
void rebuildCommodityFile(struct CommodityNode* head);//重构商品文件
//--------------------
#endif //CLIONPROJECT_COMMODITYCHAIN_H
