#include<stdio.h>
#include <stdlib.h>
int main()
{
	mainwork();
	return 0;
}
void mainwork() {
	menu();
	int choice;
	do
	{

		printf("请输入您的需求：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");menu();break;
		case 2:system("cls");allattractions();break;
		case 3:system("cls");specificattractions();break;
		case 4:system("cls");shortestpath();break;
		case 5:system("cls");allpath();break;
		case 6:system("cls");manage_map_information();break;
		case 7:system("cls");manage_user_information();break;
		case 0:system("cls");printf("感谢您的使用,期待着我们下次见面。\n");break;
		default:printf("未找到该功能，请输入有效选项！\n");
		}

	} while (choice);

}
void menu() {
	printf("┌────────────────────────────┐\n");
	printf("│  ╭ ═══════════════════════ ╮  │\n");
	printf("│  ││       欢 迎 使 用 校 园 导 游 系 统        ││  │\n");
	printf("│  ╰ ═══════════════════════ ╯  │\n");
	printf("│                      欢迎来到                          │\n");
	printf("│                   三峡大学  CTGU                       │\n");
	printf("│         ⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕          │\n");
	printf("│                     菜 单 选 择                        │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  1.菜单                 **   2.所有景点信息查询   * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  3.具体景点信息查询     **   4.查询景点间最短路径 * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  5.查询景点间所有路径   **   6.管理地图信息       * │\n");// 
	printf("│  ***************************************************** │\n");
	printf("│  *  7.管理用户信息         **   0.退出               * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *                         **                        * │\n");
	printf("│  ***************************************************** │\n");
	printf("└────────────────────────────┘\n");

}
void allattractions()//所有景点信息查询
{



}
void specificattractions()//具体景点信息查询 
{
	

}
void shortestpath() //查询景点间最短路径
{


}
void allpath()//查询景点间所有路径
{



}
void manage_map_information()//管理地图信息
{
	int outcome=verification();//权限核验结果。  如果返回结果为1，则可登入系统修改；否则返回上一级
	if (outcome == 1)
	{
		printf("密码正确，登入系统成功!\n");
		manage_map();
	}
	else
	{
		printf("密码输入错误！自动返回上一级\n");menu();return ;
	}

}

void manage_user_information()//管理用户信息
{
	int outcome = verification();//权限核验结果。  如果返回结果为1，则可登入系统修改；否则返回上一级
	if (outcome == 1)
	{
		printf("密码正确，登入系统成功!\n");
		manage_user();
	}
	else
	{
		printf("密码输入错误！自动返回上一级\n");menu();return;
	}

}
int verification()//身份确认权限核验函数
{

}
void manage_map()
{
	int choice;
	printf("(1)重新建图     (2)删除景点形象  (3)删除路径信息\n");
	printf("(4)增加结点     (5)增加边    (6)更新信息\n");
	printf("(7)打印邻接矩阵 (8)返回上一级\n");
	do
	{
		printf("请输入您的选择：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:creatgraph();break;
		case 2:delvex();break;
		case 3:delarc();break;
		case 4:envex();break;
		case 5:enarc();break;
		case 6:newgraph();break;
		case 7:printmatrix();break;
		case 8:system("cls");menu();return ;//break;
		default:printf("未找到该功能，请输入有效选项！\n");break;
		}
	} while (choice);
}
//以下是修改图的相关信息。包括建图、更新信息、删除、增加结点和边
int creatgraph()//1
{

}
int newgraph()//2
{

}
int enarc()//3
{

}
int envex()//4
{

}
int delvex()//5
{

}
int delarc()//6
{

}
void printmatrix()//7
{

}
// 以下是用户信息管理
void manage_user()
{

}
