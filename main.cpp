#include "student.h"
/***********【主函数】************/
int main()
{
	int choice;
	LoadFile();
	do
	{
		Interface();
		printf("\t\t\t请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			AddData();
			//添加信息
			break;
		case 2:
			//查找信息
			SearchMain();
			break;
		case 3:
			deletestu();
			//删除信息
			break;
		case 4:
			//修改信息
			Modify(pStu);
			break;
		case 5:
			//退出系统
			SaveData();
			//保存
			break;
		default:
			break;
		}
	} while (choice != 5);
	return 0;
}
/************【创建链表】***************/
void CreateList()
{
	pStu = (STU*)malloc(sizeof(STU));
	pStu->pnext = NULL;
}
/************【加载文件】***************/
void LoadFile()
{
	char ch;
	STU* pnew = NULL;
	STU* ptemp = NULL;
	//创建链表
	CreateList();
	ptemp = pStu;
	//打开或者创建新文件
	printf("\n\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃		欢迎使用该系统		┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃使用说明:				┃\n");
	printf("\t\t\t┃					┃\n");
	printf("\t\t\t┃	   打开示例:3年2班.txt		┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	while (1)  //一定要打开一个文件
	{
		printf("\t\t\t请输入文件名：");
		scanf("%s", filename);
		if ((fp = fopen(filename, "r")) == NULL)  //打开失败的原因 用r打开一个不存在的文件
		{
			printf("\t\t\t没有该班级的数据！是否创建？（y/n）:");
			fflush(stdin);   //清除键盘的缓冲区
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				if ((fp = fopen(filename, "a+")) == NULL) //创建失败
				{
					printf("\t\t\t创建失败！");
					exit(0);//直接退出程序
				}
				else
				{
					break;
				}
			}
			else //选择NO 不创建文件
			{
				continue;
			}
		}
		else  //存在  打开成功了
		{
			break;
		}
	}

	//while 结束之后 说明什么？文件打开成功了！！
	//新建的  还是  原来就有呢？ 有没有数据呢？
	//文件的数据 保存到链表当中。
	while (1) //不清楚有多少数据
	{
		pnew = (STU*)malloc(sizeof(STU));  //空间开辟好了！

		if (fscanf(fp, "%d\t%s\t%f\t%f\n", &pnew->num, pnew->name, &pnew->chinese, &pnew->math) == EOF) //没有数据 新建的
		{
			free(pnew); //释放开辟好的空间
			break;
		}
		pnew->pnext = NULL;
		ptemp->pnext = pnew;
		ptemp = ptemp->pnext;
	}

	//数据读完
	fclose(fp);
}
/************【主界面】***************/
void Interface()
{
	system("cls");
	printf("\n\n");
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃		学生成绩管理		┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃		1.添加学员		┃\n");
	printf("\t\t\t┃		2.查找学员		┃\n");
	printf("\t\t\t┃		3.删除学员		┃\n");
	printf("\t\t\t┃		4.修改学员		┃\n");
	printf("\t\t\t┃		5.退出系统		┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
/**************【添加信息】***********/
void AddData()
{
	int count;
	system("cls");
	printf("\n\n");
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃		正在添加学员		 ┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t\t\t请问需要添加几名学生的信息？");
	scanf("%d", &count);
	for (int n = 0; n < count; n++)
	{
		STU*ptemp = pStu;
		while (ptemp->pnext != NULL)
		{
			ptemp = ptemp->pnext;
		}//将ptemp移动到最后一个有数据的节点
		STU*pnew = (STU*)malloc(sizeof(STU));
		ptemp->pnext = pnew;
		pnew->pnext = NULL;
		printf("\t\t\t请输入新添加的学生的信息:\n");
		printf("\t\t\t学号:"); scanf("%d", &pnew->num);
		printf("\t\t\t姓名:"); scanf("%s", pnew->name);
		printf("\t\t\t语文:"); scanf("%f", &pnew->chinese);;
		printf("\t\t\t数学:"); scanf("%f", &pnew->math);
	}
	//作业
}
/**************【查找主函数】***********/
void SearchMain()
{
	int choice;
	do
	{
		system("cls");
		printf("\n\n");
		printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t\t┃		正在查找学员		 ┃\n");
		printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\t\t\t1.按学号查找\n");
		printf("\t\t\t2.按姓名查找\n");
		printf("\t\t\t3.全部查看\n");
		printf("\t\t\t4.返回主界面\n");
		printf("\t\t\t请选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:SearchNum(pStu); break;
		case 2:SearchName(pStu); break;
		case 3:PrintAll(); break;
		case 4:break;
		}
	} while (choice != 4);

}
/***************【全部查看】*************/
void PrintAll()
{
	system("cls");
	printf("\n\n");
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃		正在查看学员		 ┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	STU *ptemp = pStu->pnext;  //指向第一个有数据的结点
	if (ptemp == NULL)
	{
		printf("\t\t\t没有任何数据\n");
		printf("\t\t\t按回车键继续...");
		_getch();
		return;
	}

	printf("\t\t\t学号\t姓名\t语文\t数学\n");
	while (ptemp != NULL)
	{
		printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
		ptemp = ptemp->pnext;
	}
	printf("\t\t\t按回车键继续...");
	_getch();  //等待
}
/***************【按学号查找】*************/
void SearchNum(STU *ptemp)
{
	int num;

	system("cls");
	printf("\n\n");
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃		正在查看学员		 ┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t\t\t请输入学号：");
	scanf("%d", &num);

	ptemp = ptemp->pnext; //指向第一个数据
	while (ptemp != NULL)
	{
		if (ptemp->num == num)
		{
			printf("\t\t\t学号\t姓名\t语文\t数学\n");
			printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
			printf("\t\t\t按回车键继续...");
			_getch();
			return;  //找到  return
		}
		ptemp = ptemp->pnext;
	}
	//没有找到 。。。。
	printf("\t\t\t查无此人！按任意键继续...\n");
	_getch();
}
/***************【按姓名查找】*************/
void SearchName(STU *ptemp)
{
	char name[20];

	system("cls");
	printf("\n\n");
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃		正在查看学员		 ┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t\t\t请输入姓名：");
	scanf("%s", name);

	ptemp = ptemp->pnext; //指向第一个数据

	int n = 0;
	while (ptemp != NULL)
	{
		if (!strcmp(ptemp->name, name))
		{
			if (n == 0)
			{
				printf("\t\t\t学号\t姓名\t语文\t数学\n");
			}
			printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
			n++;
		}
		ptemp = ptemp->pnext;
	}
	//没有找到 。。。。
	if (n == 0)
	{
		printf("\t\t\t查无此人！按任意键继续...\n");
	}
	_getch();
}
/***************【修改信息】*************/
void Modify(STU *ptemp)
{
	//修改成绩
	int		num;
	int		num1;
	char	ch;
	system("cls");
	printf("\n\n");
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃		正在修改信息		 ┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t\t\t请输入学号：");
	scanf("%d", &num);

	ptemp = ptemp->pnext; //指向第一个数据
	while (ptemp != NULL)
	{
		if (ptemp->num == num)
		{
			printf("\t\t\t学号\t姓名\t语文\t数学\n");
			printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
			printf("\t\t\t是否修改（y/n）：");
			fflush(stdin);
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				printf("\t\t\t修改数学请按1\n\t\t\t修改语文请按2：");
				scanf("%d", &num1);
				if (num1 == 1)
				{
					printf("\t\t\t请输入新的数学成绩：");
					scanf("%f", &ptemp->math);
				}
				else if (num1 == 2)
				{
					printf("\t\t\t请输入新的语文成绩：");
					scanf("%f", &ptemp->chinese);
				}

				printf("\t\t\t修改成功! 任意键返回...");
				_getch();
				return;  //找到  return
			}
			else
			{
				return;
			}
		}
		ptemp = ptemp->pnext;
	}
}
/***************【保存到文件】*************/
void SaveData()
{
	STU *ptemp = pStu->pnext;

	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("\t\t\t文件打开失败！！");
	}
	else
	{
		while (ptemp != NULL)
		{
			fprintf(fp, "%d\t%s\t%f\t%f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
			ptemp = ptemp->pnext;
		}
	}

	fclose(fp);
}
/***************【删除信息】*************/
void deletestu()
{
	STU *ptemp = pStu;
	if (pStu->pnext == NULL)
	{
		printf("\t\t\t该系统目前为空！");
		return;
	}
	else
	{
		int num; 
		system("cls");
		printf("\n\n");
		printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t\t┃		正在删除信息		 ┃\n");
		printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\t\t\t请输入需要删除信息的学生的学号:");
		scanf("%d", &num);
		while (ptemp->pnext->num != num&&ptemp != NULL)
		{
			ptemp = ptemp->pnext;
		}
		if (ptemp == NULL)
		{
			printf("没有学号为%d的学生！", num);
			return;
		}
		else if (ptemp == pStu)
		{
			pStu->pnext = ptemp->pnext->pnext;
			return;
		}
		else if (ptemp!=pStu&&ptemp!=NULL)
		{
			ptemp->pnext = ptemp->pnext->pnext;
			return;
		}
	}
	
}

