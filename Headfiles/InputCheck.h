//-------------------
//以下为标准输入输出的函数声明
//--------------------

#ifndef _INPUTCHECK_H_
#define _INPUTCHECK_H_
//--------------------
//以下为功能函数
bool isCharacter(char ch);//是否为字符
bool isDigit(char ch);//是否为数字
bool isFullCharacter(char str[]);//是否都是字符
bool isFullDigit(char str[]);//是否都是数字
// 标准输入意味着该字符串只有字母和数字
bool isStdInput(char str[]);//是否为标准输入输出
// 大写覆写为小写，其余不变
void strToLower(char str[]);//大写覆写为小写其余不变
// 将字符串转换为整数
// 使用本函数前必须先判断字符串合法性！
int strToInt(char str[]);//字符转数字
bool isStandardFloat(char str[]);//是否为标准的浮点数输入
double strToDouble(char str[]);//字符转浮点数
double intStrToDouble(char str[]);//整形字符转浮点数
bool isStandardText(char str[]);
//--------------------
#endif