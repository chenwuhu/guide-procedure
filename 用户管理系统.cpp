#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define USER_FILE "users.txt"

// 定义结构体存储用户信息
typedef struct user {
    char name[MAX_NAME_LEN];
    int age;
    char gender;
} User;

// 新增用户信息
void add_user(char* name, int age, char gender) {
    // 打开文件
    FILE* fp = fopen(USER_FILE, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // 写入用户信息
    fprintf(fp, "%s %d %c\n", name, age, gender);

    // 关闭文件
    fclose(fp);
}

// 查找用户信息
void find_user(const char* name) {
    // 打开文件
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // 读取文件中的用户信息
    User user;
    while (fscanf(fp, "%s %d %c", user.name, &user.age, &user.gender) != EOF) {
        if (strcmp(user.name, name) == 0) {
            printf("Name: %s, Age: %d, Gender: %c\n", user.name, user.age, user.gender);
            break;
        }
    }

    // 关闭文件
    fclose(fp);
}

// 修改用户信息
void update_user(const char* name, int age, char gender) {
    // 打开文件
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    // 读取文件中的用户信息
    User users[MAX_NAME_LEN];
    int num_users = 0;
    while (fscanf(fp, "%s %d %c", users[num_users].name, &users[num_users].age, &users[num_users].gender) != EOF) {
        if (strcmp(users[num_users].name, name) == 0) {
            users[num_users].age = age;
            users[num_users].gender = gender;
        }
        num_users++;
    }

    // 关闭文件
    fclose(fp);

    // 打开文件
    fp = fopen(USER_FILE, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // 写入修改后的用户信息
    for (int i = 0; i < num_users; i++) {
        fprintf(fp, "%s %d %c\n", users[i].name, users[i].age, users[i].gender);
    }

    // 关闭文件
    fclose(fp);
}

// 删除用户信息
void delete_user(char* name) {
    // 打开文件
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // 读取文件中的用户信息
    User users[MAX_NAME_LEN];
    int num_users = 0;
    while (fscanf(fp, "%s %d %c", users[num_users].name, &users[num_users].age, &users[num_users].gender) != EOF) {
        if (strcmp(users[num_users].name, name) != 0) {
            num_users++;
        }
    }

    // 关闭文件
    fclose(fp);

    // 打开文件
    fp = fopen(USER_FILE, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // 写入删除用户后的用户信息
    for (int i = 0; i < num_users; i++) {
        fprintf(fp, "%s %d %c\n", users[i].name, users[i].age, users[i].gender);
    }

    // 关闭文件
    fclose(fp);
}


// 显示所有用户信息
void display_users() {
    // 打开文件
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    // 读取文件中的用户信息
    User user;
    while (fscanf(fp, "%s %d %c", user.name, &user.age, &user.gender) != EOF) {
        printf("Name: %s, Age: %d, Gender: %c\n", user.name, user.age, user.gender);
    }

    // 关闭文件
    fclose(fp);
}

//菜单
void menu() {
    system("cls");
    printf("┌────────────────────────────┐\n");
    printf("│  ╭ ═══════════════════════ ╮  │\n");
    printf("│  ││    欢 迎 使 用 用 户 信 息 管 理 系 统     ││  │\n");
    printf("│  ╰ ═══════════════════════ ╯  │\n");
    printf("│                   三峡大学  CTGU                       │\n");
    printf("│                     菜 单 选 择                        │\n");
    printf("│  ***************************************************** │\n");
    printf("│  *  1.新增用户信息         **   2.删除用户信息       * │\n");
    printf("│  ***************************************************** │\n");
    printf("│  *  3.查询用户信息         **   4. 修改用户信息      * │\n");
    printf("│  ***************************************************** │\n");
    printf("│  *  5.显示所有用户信息     **   6.菜单               * │\n");
    printf("│  ***************************************************** │\n");
    printf("│  *  0.退出                 **                        * │\n");
    printf("│  ***************************************************** │\n");
    printf("└────────────────────────────┘\n");

}

void xinzeng()
{
    char name[MAX_NAME_LEN];
    int age;
    char gender;
    scanf("%s %d %c", name, &age, &gender);
    // 新增用户
    add_user(name, age, gender);
    printf("新增用户成功！\n");


}

void shanchu() {
    char name[MAX_NAME_LEN];
    // 删除用户
    printf("Enter the name of the user to delete: ");
    scanf("%s", name);
    delete_user(name);
    printf("删除用户成功！\n");
}

void chazhao() {
    // 查找用户
    printf("请输入需要查找的用户名：");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    find_user(name);

}

void xiugai() {
    // 修改用户
    printf("Enter the name of the user to update: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    printf("Enter the updated age: ");
    int age;
    scanf("%d", &age);
    printf("Enter the updated gender: ");
    char gender;
    scanf(" %c", &gender);
    update_user(name, age, gender);
    printf("修改用户信息成功！\n");
}


int main() {
    menu();
    int yourchoice;
    do
    {

        printf("请输入您的需求（输入6为返回菜单）：");
        scanf("%d", &yourchoice);
        switch (yourchoice)
        {
        case 1:system("cls");
            xinzeng();
            break;
        case 2:system("cls");
            shanchu();
            break;
        case 3:system("cls");
            chazhao();
            break;
        case 4:system("cls");
            xiugai();
            break;
        case 5:system("cls");
            // 显示所有用户
            display_users();
            break;
        case 6:menu();break;
        case 0:system("cls");printf("感谢您的使用,期待着我们下次见面。\n");break;
        default:printf("未找到该功能，请输入有效选项！\n");
        }



    } while (yourchoice);

    return 0;
}