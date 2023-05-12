//-------------------
//以下为登录功能头文件的函数声明
//-------------------

#ifndef _LOGINFUNCTION_H_
#define _LOGINFUNCTION_H_

//--------------------
//以下为功能函数
int loginUser(char id[], char pwd[]);//用户登录函数
int loginAdmin(char id[], char pwd[]);//管理员登陆函数
int registerUser(char id[],char pwd1[],char pwd2[],int identify);//用户注册函数
//--------------------
#endif