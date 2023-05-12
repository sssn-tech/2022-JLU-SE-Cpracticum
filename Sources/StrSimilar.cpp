
#include <stdio.h>
#include <string.h>
#include <math.h>
#include"..\Headfiles\StrSimilar.h"
//--------------------
//以下为字符串相似度功能函数
double innerProduct(double a[], double b[])
{
    int i;
    double sum = 0;
    for (i = 0; i < 36; i++)    
        sum += a[i] * b[i];
    return sum;
}
double norm(double a[]) 
{
    int i;
    double sum = 0;
    for (i = 0; i < 36; i++)  
        sum += a[i] * a[i];
    return sqrt(sum);
}
void strToVectorize(char str[], double* vector) 
{
    int i, j;
    char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";   
    int n = strlen(str);
    for (i = 0; i < 36; i++)
        vector[i] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 36; j++) {
            if (str[i] == charset[j]) {
                vector[j]++;
                break;
            }
        }
    }
} 
double getStrSimilarity(char* str1, char* str2)
{
    double vector1[36], vector2[36];
    strToVectorize(str1, vector1); 
    strToVectorize(str2, vector2);
    return innerProduct(vector1, vector2) / (norm(vector1) * norm(vector2));
}
//--------------------