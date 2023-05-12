//--------------------
//以下为MD5加密功能的头文件内的声明
//包括结构体声明 宏定义 以及函数声明
//--------------------

#ifndef _MD5_H_
#define _MD5_H_

//--------------------
//以下为MD5加密功能结构体的声明
typedef struct {
    unsigned int count[2];
    unsigned int state[4];
    unsigned char buffer[64];
}MD5_CTX;
//--------------------

//-------------------
//以下为MD5加密功能所需的宏定义
#define F(x, y, z)  ((x & y) | (~x & z))
#define G(x, y, z)  ((x & z) | (y & ~z))
#define H(x, y, z)  (x ^ y ^ z)
#define I(x, y, z)  (y ^ (x | ~z))
#define ROTATE_LEFT(x, n)   ((x << n) | (x >> (32 - n)))
#define FF(a, b, c, d, x, s, ac) \
        { \
        a += F(b, c, d) + x + ac; \
        a = ROTATE_LEFT(a, s); \
        a += b; \
        }
#define GG(a, b, c, d, x, s, ac) \
        { \
        a += G(b, c, d) + x + ac; \
        a = ROTATE_LEFT(a, s); \
        a += b; \
        }
#define HH(a, b, c, d, x, s, ac) \
        { \
        a += H(b, c, d) + x + ac; \
        a = ROTATE_LEFT(a, s); \
        a += b; \
        }
#define II(a, b, c, d, x, s, ac) \
        { \
        a += I(b, c, d) + x + ac; \
        a = ROTATE_LEFT(a, s); \
        a += b; \
        }
//--------------------

//-------------------
//以下为MD5加密功能所需函数的声明
void MD5Init(MD5_CTX* context);
void MD5Update(MD5_CTX* context, unsigned char* input, unsigned int inputlen);
void MD5Final(MD5_CTX* context, unsigned char digest[16]);
void MD5Transform(unsigned int state[4], unsigned char block[64]);
void MD5Encode(unsigned char* output, unsigned int* input, unsigned int len);
void MD5Decode(unsigned int* output, unsigned char* input, unsigned int len);
//--------------------

//--------------------
//MD5Function是集成的MD5加密方法 以下为功能函数
void MD5Function(unsigned char encrypt[], char* crypt1);
//-------------------



#endif //CLIONPROJECT_MD5_H

