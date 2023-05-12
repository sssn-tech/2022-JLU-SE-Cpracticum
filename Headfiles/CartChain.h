//--------------------
//以下为购物车链表功能函数和结构体的声明
//--------------------

//--------------------
#ifndef _CARTCHAIN_H_
#define _CARTCHAIN_H_
struct CartNode {
    char unitName[50];
    double soldPrice_Original;
    double soldPrice_Discount;
    int unitCount;
    int historylv;
    struct CartNode* preCart, * nextCart;
};
void addCart(struct CartNode** head, struct CartNode** tail, double originPrice, int unitNumber, char unitName[50], int lv);//增加购物车节点
void  delCart(struct CartNode** head, struct CartNode** tail, struct CartNode* p);//删除该购物车节点
#endif 
