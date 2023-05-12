#include"..\Headfiles\CartChain.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

extern double discount;//引用外部变量discount
//--------------------

//--------------------
//以下为添加商品至购物车的函数
void addCart(struct CartNode** head, struct CartNode** tail,double originPrice,int unitNumber,char unitName[50],int lv)
{
    struct CartNode* now = (struct CartNode*)malloc(sizeof(struct CartNode));
    now->preCart  = NULL;    // 申请新节点第一件事就是指针初始化！非常重要！
    now->nextCart = NULL;
    now->soldPrice_Original = originPrice*unitNumber;
    if (*head == NULL && *tail == NULL)
    {
        // 增加链表第一个节点,该节点即是头又是尾
        *head = *tail = now;
        // 输入具体信息的代码块
        now->unitCount = unitNumber;
        now->soldPrice_Discount = originPrice * unitNumber*discount;
        now->historylv = lv;
        strcpy_s(now->unitName,unitName);
        return;
    }
    else {
        // 不是第一个节点，则只需接在最后节点(tail)的后面
        (*tail)->nextCart = now;
        now->preCart = *tail;
        *tail = now;
        // 输入具体信息
        now->unitCount = unitNumber;
        now->soldPrice_Discount = originPrice *unitNumber* discount;
        now->historylv = lv;
        strcpy_s(now->unitName, unitName);
        return;
    }
}
//--------------------

//--------------------
//以下为删除购物车商品的函数
void  delCart(struct CartNode** head, struct CartNode** tail, struct CartNode* p)
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
            struct CartNode* temp = *head;
            *head = (*head)->nextCart;
            (*head)->preCart = NULL;
            free(temp);
            return;
        }
        if (*head != p && *tail == p)
        {
            // 要删除的节点是尾，但不是头
            struct CartNode* temp = *tail;
            *tail = (*tail)->preCart;
            (*tail)->nextCart = NULL;
            free(temp);
            return;
        }
    }
    // 如果删除的节点不是头或者尾的特殊情况
    // 注意，p是指向节点的指针，和head，tail不一样
    p->nextCart->preCart = p->preCart;
    p->preCart->nextCart = p->nextCart;
    free(p);
}
//--------------------