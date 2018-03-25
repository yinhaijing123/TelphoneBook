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

void TelBookInit(TelBook * telbook);          //��ʼ��
 
void TelBookAdd(TelBook *telbook);            //���

void TelBookDel(TelBook *telbook);            //ɾ��

void TelBookSearch(TelBook *telbook);          //��ѯ

void TelBookModify(TelBook *telbook);         //�޸�

void TelBookDisplay(TelBook *telbook);        //��ʾ

void TelBookDestroy(TelBook *telbook);        //���

void TelBookSortWithName(TelBook *telbook);   //����������ͨѶ¼