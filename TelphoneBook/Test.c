#include"TelBook.h"

void Menu()
{
    printf("********************************   Menu   **********************************\n");
    printf("****************************************************************************\n");
    printf("********     1.添加联系人                 2.删除联系人          ************\n");
    printf("********     3.查找指定联系人信息         4.修改指定联系人信息  ************\n");
    printf("********     5.显示所有联系人信息         6.清空所有联系人信息  ************\n");
    printf("********     7.以名字排序所有联系人       0.退出菜单            ************\n");
    printf("****************************************************************************\n");

}

void Test()
{
    TelBook telbook;

    TelBookInit(&telbook);

    int input = 0;
    while (1)
    {
        printf("\n\n");
        Menu();
        printf("请选择：");
        fflush(stdin);
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            TelBookAdd(&telbook);
            break;
        case 2:
            TelBookDel(&telbook);
            break;
        case 3:
            TelBookSearch(&telbook);
            break;
        case 4:
            TelBookModify(&telbook);
            break;
        case 5:
            TelBookDisplay(&telbook);
            break;
        case 6:
            TelBookDestroy(&telbook);
            break;
        case 7:
            TelBookSortWithName(&telbook);
            break;
        case 0:
            return;
        default:
            break;
        }
    }

}
int main()
{
    Test();
    system("pause");
    return 0;
}