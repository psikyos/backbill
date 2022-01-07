
/* 版权:军卫工程一号项目组 */
/************************************************************* 
   文件名
     common.h
   内容
     配置文件的基本函数调用原型
   说明
     关于每个函数的实现在common.c中
   编写者
     吉同路
   编写完成日期:    96.06.13 
   最后一次修改日期:96.09.26
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define TICKPERSEC      18.2
#define WAITSECOND      10000
#define MAXLINE         256
#define MAXSIZE         7  //used in GetConfigNum for size of max value

int   IsRemark(char *pString);
int  IsSection(char *pString);
int IsKeyValue(char *pString);

int GetConfigNum(char *FileName,char *pSection,char *pItemKey,int nValueDefault);

char *GetConfigString(char *FileName,char *pSection,char *pItemKey,
                      char *pValueDefault,char *pBuffer,int nBufferSize);
int SetConfigString(char *FileName,char *pSection,char *pItemKey,char *pItemValue);

char *RSubs(char *pString,char ch,int nMode,char *pBuffer,int nBufferSize);
char *LSubs(char *pString,char ch,int nMode,char *pBuffer,int nBufferSize);
char *MultiCat( char *pBuffer,int nBufferSize,char *first, ... );
char *LTrim(char *pString,char *pBuffer,int nBufferSize); 
char *RTrim(char *pString,char *pBuffer,int nBufferSize); 
char *Trima(char *pString,char *pBuffer,int nBufferSize) ;
int GetConfigMisc(char *FileName,char *pSection,int nItemNo,
                      char *pItemClass,char *pItemCode) ;


//int stricmp ( char *s1, char *s2 );
//int strnicmp ( char *s1, char *s2, int n );
//char *itoa (int value, char *string, int radix);

