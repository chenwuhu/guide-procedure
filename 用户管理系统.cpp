#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define USER_FILE "users.txt"

// ����ṹ��洢�û���Ϣ
typedef struct user {
    char name[MAX_NAME_LEN];
    int age;
    char gender;
} User;

// �����û���Ϣ
void add_user(char* name, int age, char gender) {
    // ���ļ�
    FILE* fp = fopen(USER_FILE, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // д���û���Ϣ
    fprintf(fp, "%s %d %c\n", name, age, gender);

    // �ر��ļ�
    fclose(fp);
}

// �����û���Ϣ
void find_user(const char* name) {
    // ���ļ�
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // ��ȡ�ļ��е��û���Ϣ
    User user;
    while (fscanf(fp, "%s %d %c", user.name, &user.age, &user.gender) != EOF) {
        if (strcmp(user.name, name) == 0) {
            printf("Name: %s, Age: %d, Gender: %c\n", user.name, user.age, user.gender);
            break;
        }
    }

    // �ر��ļ�
    fclose(fp);
}

// �޸��û���Ϣ
void update_user(const char* name, int age, char gender) {
    // ���ļ�
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    // ��ȡ�ļ��е��û���Ϣ
    User users[MAX_NAME_LEN];
    int num_users = 0;
    while (fscanf(fp, "%s %d %c", users[num_users].name, &users[num_users].age, &users[num_users].gender) != EOF) {
        if (strcmp(users[num_users].name, name) == 0) {
            users[num_users].age = age;
            users[num_users].gender = gender;
        }
        num_users++;
    }

    // �ر��ļ�
    fclose(fp);

    // ���ļ�
    fp = fopen(USER_FILE, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // д���޸ĺ���û���Ϣ
    for (int i = 0; i < num_users; i++) {
        fprintf(fp, "%s %d %c\n", users[i].name, users[i].age, users[i].gender);
    }

    // �ر��ļ�
    fclose(fp);
}

// ɾ���û���Ϣ
void delete_user(char* name) {
    // ���ļ�
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // ��ȡ�ļ��е��û���Ϣ
    User users[MAX_NAME_LEN];
    int num_users = 0;
    while (fscanf(fp, "%s %d %c", users[num_users].name, &users[num_users].age, &users[num_users].gender) != EOF) {
        if (strcmp(users[num_users].name, name) != 0) {
            num_users++;
        }
    }

    // �ر��ļ�
    fclose(fp);

    // ���ļ�
    fp = fopen(USER_FILE, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // д��ɾ���û�����û���Ϣ
    for (int i = 0; i < num_users; i++) {
        fprintf(fp, "%s %d %c\n", users[i].name, users[i].age, users[i].gender);
    }

    // �ر��ļ�
    fclose(fp);
}


// ��ʾ�����û���Ϣ
void display_users() {
    // ���ļ�
    FILE* fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    // ��ȡ�ļ��е��û���Ϣ
    User user;
    while (fscanf(fp, "%s %d %c", user.name, &user.age, &user.gender) != EOF) {
        printf("Name: %s, Age: %d, Gender: %c\n", user.name, user.age, user.gender);
    }

    // �ر��ļ�
    fclose(fp);
}

//�˵�
void menu() {
    system("cls");
    printf("������������������������������������������������������������\n");
    printf("��  �q �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �r  ��\n");
    printf("��  ����    �� ӭ ʹ �� �� �� �� Ϣ �� �� ϵ ͳ     ����  ��\n");
    printf("��  �t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �s  ��\n");
    printf("��                   ��Ͽ��ѧ  CTGU                       ��\n");
    printf("��                     �� �� ѡ ��                        ��\n");
    printf("��  ***************************************************** ��\n");
    printf("��  *  1.�����û���Ϣ         **   2.ɾ���û���Ϣ       * ��\n");
    printf("��  ***************************************************** ��\n");
    printf("��  *  3.��ѯ�û���Ϣ         **   4. �޸��û���Ϣ      * ��\n");
    printf("��  ***************************************************** ��\n");
    printf("��  *  5.��ʾ�����û���Ϣ     **   6.�˵�               * ��\n");
    printf("��  ***************************************************** ��\n");
    printf("��  *  0.�˳�                 **                        * ��\n");
    printf("��  ***************************************************** ��\n");
    printf("������������������������������������������������������������\n");

}

void xinzeng()
{
    char name[MAX_NAME_LEN];
    int age;
    char gender;
    scanf("%s %d %c", name, &age, &gender);
    // �����û�
    add_user(name, age, gender);
    printf("�����û��ɹ���\n");


}

void shanchu() {
    char name[MAX_NAME_LEN];
    // ɾ���û�
    printf("Enter the name of the user to delete: ");
    scanf("%s", name);
    delete_user(name);
    printf("ɾ���û��ɹ���\n");
}

void chazhao() {
    // �����û�
    printf("��������Ҫ���ҵ��û�����");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    find_user(name);

}

void xiugai() {
    // �޸��û�
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
    printf("�޸��û���Ϣ�ɹ���\n");
}


int main() {
    menu();
    int yourchoice;
    do
    {

        printf("������������������6Ϊ���ز˵�����");
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
            // ��ʾ�����û�
            display_users();
            break;
        case 6:menu();break;
        case 0:system("cls");printf("��л����ʹ��,�ڴ��������´μ��档\n");break;
        default:printf("δ�ҵ��ù��ܣ���������Чѡ�\n");
        }



    } while (yourchoice);

    return 0;
}