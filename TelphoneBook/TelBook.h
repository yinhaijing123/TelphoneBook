#pragma once
#include<stdio.h>
#include<assert.h>

#define TelBookMaxSize 1000

typedef struct PeoInfo {
    char name[20];
    char sex[10];
    size_t age;
    char tel[50];
    char address[100];
}PeoInfo;

typedef struct TelBook
{
    PeoInfo peo[TelBookMaxSize];
    size_t size;
}TelBook;

void TelBookInit(TelBook * telbook);          //初始化
 
void TelBookAdd(TelBook *telbook);            //添加

void TelBookDel(TelBook *telbook);            //删除

void TelBookSearch(TelBook *telbook);          //查询

void TelBookModify(TelBook *telbook);         //修改

void TelBookDisplay(TelBook *telbook);        //显示

void TelBookDestroy(TelBook *telbook);        //清空

void TelBookSortWithName(TelBook *telbook);   //以名字排序通讯录