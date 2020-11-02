#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//学生的结构体
typedef struct Stu
{
	int		num;
	char	name[20];
	float	chinese;
	float	math;

	struct Stu* pnext;
}STU;

STU		*pStu = NULL; //定义指针 头指针
FILE	*fp = NULL;   //文件指针
char	filename[20] = { 0 }; //文件名

/************【创建链表】***************/
void CreateList();
/************【加载文件】***************/
void LoadFile();
/************【主界面】***************/
void Interface();
/**************【查找主函数】***********/
void SearchMain();
/***************【全部查看】*************/
void PrintAll();
/***************【按学号查找】*************/
void SearchNum(STU *ptemp);
/***************【按姓名查找】*************/
void SearchName(STU *ptemp);
/***************【修改信息】*************/
void Modify(STU *ptemp);
/***************【保存到文件】*************/
void SaveData();
/**************【添加信息】***********/
void AddData();
/***************【删除信息】*************/
void deletestu();