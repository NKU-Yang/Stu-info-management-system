#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//ѧ���Ľṹ��
typedef struct Stu
{
	int		num;
	char	name[20];
	float	chinese;
	float	math;

	struct Stu* pnext;
}STU;

STU		*pStu = NULL; //����ָ�� ͷָ��
FILE	*fp = NULL;   //�ļ�ָ��
char	filename[20] = { 0 }; //�ļ���

/************����������***************/
void CreateList();
/************�������ļ���***************/
void LoadFile();
/************�������桿***************/
void Interface();
/**************��������������***********/
void SearchMain();
/***************��ȫ���鿴��*************/
void PrintAll();
/***************����ѧ�Ų��ҡ�*************/
void SearchNum(STU *ptemp);
/***************�����������ҡ�*************/
void SearchName(STU *ptemp);
/***************���޸���Ϣ��*************/
void Modify(STU *ptemp);
/***************�����浽�ļ���*************/
void SaveData();
/**************�������Ϣ��***********/
void AddData();
/***************��ɾ����Ϣ��*************/
void deletestu();