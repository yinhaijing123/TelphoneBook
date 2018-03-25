#define _CRT_SECURE_NO_WARNINGS
#include"TelBook.h"

void TelBookInit(TelBook * telbook)
{
    assert(telbook);
    telbook->size = 0;
}

void TelBookAdd(TelBook *telbook)
{
    assert(telbook);
    printf("请依此输入要添加人的姓名、性别、年龄、电话、地址：\n");
    if (telbook->size >= TelBookMaxSize)
    {
        printf("通讯录已满\n");
        return;
    }
    ++telbook->size;
    scanf("%s%s%d%s%s", telbook->peo[telbook->size-1].name, telbook->peo[telbook->size - 1].sex, 
                       &telbook->peo[telbook->size - 1].age, telbook->peo[telbook->size - 1].tel, 
                        telbook->peo[telbook->size - 1].address);
}

void ToDelPeo(TelBook *telbook, int pos)
{
    assert(telbook);
    int i = 0;
    for (i = pos; i < telbook->size-1; i++)
    {
        strcpy(telbook->peo[i].name ,telbook->peo[i + 1].name);
        strcpy(telbook->peo[i].sex, telbook->peo[i + 1].sex);
        telbook->peo[i].age = telbook->peo[i].age;
        strcpy(telbook->peo[i].tel, telbook->peo[i + 1].tel);
        strcpy(telbook->peo[i].address, telbook->peo[i + 1].address);
    }
    --telbook->size;
}

void TelBookDel(TelBook *telbook)
{
    assert(telbook);
    if (telbook->size == 0)
    {
        printf("通讯录为空\n");
        return;
    }
    char to_del_name[20];
    printf("请输入要删除的人的姓名：\n");
    scanf("%s", to_del_name);
    int ret=ToFind(telbook,to_del_name);
    if (ret == -1)
    {
        printf("无此人记录\n");
    }
    else
    {
        ToDelPeo(telbook, ret);
        printf("%s已删除\n", to_del_name);
    }
}

int ToFind(TelBook *telbook,char *to_find_name)
{
    assert(telbook);
    if (telbook->size == 0)
    {  
        return -1;
    }
    int i = 0;
    for (i = 0; i < telbook->size; i++)
    {
        if (!strcmp(telbook->peo[i].name, to_find_name))
        {
            return i;
        }
    }
    return -1;
}

void TelBookSearch(TelBook *telbook)
{
    assert(telbook);
    char to_find_name[20];
    printf("请输入要查找的人的姓名：\n");
    scanf("%s", to_find_name);
    int ret=ToFind(telbook,to_find_name);
    if (ret == -1)
    {
        printf("查无此人\n");
    }
    else
    {
        printf("[姓名:%s]\t[性别:%s]\t[年龄:%d]\t[电话:%s]\t[地址:%s]\n",
            telbook->peo[ret].name, telbook->peo[ret].sex, telbook->peo[ret].age,
            telbook->peo[ret].tel, telbook->peo[ret].address);
    } 
}

void TelBookModify(TelBook *telbook)
{
    assert(telbook);
    char to_modify_name[20];
    printf("请输入要修改的人的姓名：\n");
    scanf("%s", to_modify_name);
    int ret = ToFind(telbook, to_modify_name);
    if (ret == -1)
    {
        printf("查无此人\n");
    }
    else
    {
        printf("请依此输入要添加人的姓名、性别、年龄、电话、地址：\n");
        scanf("%s%s%d%s%s", telbook->peo[ret].name, telbook->peo[ret].sex,
            &telbook->peo[ret].age, telbook->peo[ret].tel,
            telbook->peo[ret].address);
        printf("%s已修改\n",to_modify_name);
    }
}

void TelBookDisplay(TelBook *telbook)
{
    int i = 0;

    printf("该通讯录共有%u条记录\n", telbook->size);
    printf("[姓名]\t[性别]\t[年龄]\t[电话]\t\t[地址]\n");

    for (i = 0; i < telbook->size; i++)
    {
        printf("%s\t%s\t%d\t%s\t\t%s\n",
            telbook->peo[i].name, telbook->peo[i].sex, telbook->peo[i].age,
            telbook->peo[i].tel, telbook->peo[i].address);
    }

}

void TelBookDestroy(TelBook *telbook)
{
    assert(telbook);
    telbook->size = 0;
}

void SwapStr(char *str1, char *str2)
{
    char tmp[20];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}

void SwapPeo(PeoInfo *peo1,PeoInfo *peo2)
{
    int tmp = peo1->age;
    peo1->age = peo2->age;
    peo2->age = tmp;
    SwapStr(peo1->name, peo2->name);
    SwapStr(peo1->sex, peo2->sex);
    SwapStr(peo1->tel, peo2->tel);
    SwapStr(peo1->address, peo2->address);
}

void TelBookSortWithName(TelBook *telbook)              //以升序为例
{
    assert(telbook);
    int i = 0;
    for (i = 0; i < telbook->size - 1; i++)
    {
        int j = 0;
        for (j = 0; j < telbook->size - 1 - i; j++)
        {
            if (strcmp(telbook->peo[j].name, telbook->peo[j + 1].name) > 0)      
            {
                SwapPeo(&telbook->peo[j], &telbook->peo[j + 1]);
            }
        }
    }
}