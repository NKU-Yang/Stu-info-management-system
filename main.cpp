#include "student.h"
/***********����������************/
int main()
{
	int choice;
	LoadFile();
	do
	{
		Interface();
		printf("\t\t\t��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			AddData();
			//�����Ϣ
			break;
		case 2:
			//������Ϣ
			SearchMain();
			break;
		case 3:
			deletestu();
			//ɾ����Ϣ
			break;
		case 4:
			//�޸���Ϣ
			Modify(pStu);
			break;
		case 5:
			//�˳�ϵͳ
			SaveData();
			//����
			break;
		default:
			break;
		}
	} while (choice != 5);
	return 0;
}
/************����������***************/
void CreateList()
{
	pStu = (STU*)malloc(sizeof(STU));
	pStu->pnext = NULL;
}
/************�������ļ���***************/
void LoadFile()
{
	char ch;
	STU* pnew = NULL;
	STU* ptemp = NULL;
	//��������
	CreateList();
	ptemp = pStu;
	//�򿪻��ߴ������ļ�
	printf("\n\n\t\t\t����������������������������������������������������������������������������������\n");
	printf("\t\t\t��		��ӭʹ�ø�ϵͳ		��\n");
	printf("\t\t\t�ǩ�������������������������������������������������������������������������������\n");
	printf("\t\t\t��ʹ��˵��:				��\n");
	printf("\t\t\t��					��\n");
	printf("\t\t\t��	   ��ʾ��:3��2��.txt		��\n");
	printf("\t\t\t����������������������������������������������������������������������������������\n");

	while (1)  //һ��Ҫ��һ���ļ�
	{
		printf("\t\t\t�������ļ�����");
		scanf("%s", filename);
		if ((fp = fopen(filename, "r")) == NULL)  //��ʧ�ܵ�ԭ�� ��r��һ�������ڵ��ļ�
		{
			printf("\t\t\tû�иð༶�����ݣ��Ƿ񴴽�����y/n��:");
			fflush(stdin);   //������̵Ļ�����
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				if ((fp = fopen(filename, "a+")) == NULL) //����ʧ��
				{
					printf("\t\t\t����ʧ�ܣ�");
					exit(0);//ֱ���˳�����
				}
				else
				{
					break;
				}
			}
			else //ѡ��NO �������ļ�
			{
				continue;
			}
		}
		else  //����  �򿪳ɹ���
		{
			break;
		}
	}

	//while ����֮�� ˵��ʲô���ļ��򿪳ɹ��ˣ���
	//�½���  ����  ԭ�������أ� ��û�������أ�
	//�ļ������� ���浽�����С�
	while (1) //������ж�������
	{
		pnew = (STU*)malloc(sizeof(STU));  //�ռ俪�ٺ��ˣ�

		if (fscanf(fp, "%d\t%s\t%f\t%f\n", &pnew->num, pnew->name, &pnew->chinese, &pnew->math) == EOF) //û������ �½���
		{
			free(pnew); //�ͷſ��ٺõĿռ�
			break;
		}
		pnew->pnext = NULL;
		ptemp->pnext = pnew;
		ptemp = ptemp->pnext;
	}

	//���ݶ���
	fclose(fp);
}
/************�������桿***************/
void Interface()
{
	system("cls");
	printf("\n\n");
	printf("\t\t\t����������������������������������������������������������������������������������\n");
	printf("\t\t\t��		ѧ���ɼ�����		��\n");
	printf("\t\t\t�ǩ�������������������������������������������������������������������������������\n");
	printf("\t\t\t��		1.���ѧԱ		��\n");
	printf("\t\t\t��		2.����ѧԱ		��\n");
	printf("\t\t\t��		3.ɾ��ѧԱ		��\n");
	printf("\t\t\t��		4.�޸�ѧԱ		��\n");
	printf("\t\t\t��		5.�˳�ϵͳ		��\n");
	printf("\t\t\t����������������������������������������������������������������������������������\n");
}
/**************�������Ϣ��***********/
void AddData()
{
	int count;
	system("cls");
	printf("\n\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t��		�������ѧԱ		 ��\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t������Ҫ��Ӽ���ѧ������Ϣ��");
	scanf("%d", &count);
	for (int n = 0; n < count; n++)
	{
		STU*ptemp = pStu;
		while (ptemp->pnext != NULL)
		{
			ptemp = ptemp->pnext;
		}//��ptemp�ƶ������һ�������ݵĽڵ�
		STU*pnew = (STU*)malloc(sizeof(STU));
		ptemp->pnext = pnew;
		pnew->pnext = NULL;
		printf("\t\t\t����������ӵ�ѧ������Ϣ:\n");
		printf("\t\t\tѧ��:"); scanf("%d", &pnew->num);
		printf("\t\t\t����:"); scanf("%s", pnew->name);
		printf("\t\t\t����:"); scanf("%f", &pnew->chinese);;
		printf("\t\t\t��ѧ:"); scanf("%f", &pnew->math);
	}
	//��ҵ
}
/**************��������������***********/
void SearchMain()
{
	int choice;
	do
	{
		system("cls");
		printf("\n\n");
		printf("\t\t\t������������������������������������������������������������������������������������\n");
		printf("\t\t\t��		���ڲ���ѧԱ		 ��\n");
		printf("\t\t\t������������������������������������������������������������������������������������\n");
		printf("\t\t\t1.��ѧ�Ų���\n");
		printf("\t\t\t2.����������\n");
		printf("\t\t\t3.ȫ���鿴\n");
		printf("\t\t\t4.����������\n");
		printf("\t\t\t��ѡ��:");
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
/***************��ȫ���鿴��*************/
void PrintAll()
{
	system("cls");
	printf("\n\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t��		���ڲ鿴ѧԱ		 ��\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");

	STU *ptemp = pStu->pnext;  //ָ���һ�������ݵĽ��
	if (ptemp == NULL)
	{
		printf("\t\t\tû���κ�����\n");
		printf("\t\t\t���س�������...");
		_getch();
		return;
	}

	printf("\t\t\tѧ��\t����\t����\t��ѧ\n");
	while (ptemp != NULL)
	{
		printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
		ptemp = ptemp->pnext;
	}
	printf("\t\t\t���س�������...");
	_getch();  //�ȴ�
}
/***************����ѧ�Ų��ҡ�*************/
void SearchNum(STU *ptemp)
{
	int num;

	system("cls");
	printf("\n\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t��		���ڲ鿴ѧԱ		 ��\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t������ѧ�ţ�");
	scanf("%d", &num);

	ptemp = ptemp->pnext; //ָ���һ������
	while (ptemp != NULL)
	{
		if (ptemp->num == num)
		{
			printf("\t\t\tѧ��\t����\t����\t��ѧ\n");
			printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
			printf("\t\t\t���س�������...");
			_getch();
			return;  //�ҵ�  return
		}
		ptemp = ptemp->pnext;
	}
	//û���ҵ� ��������
	printf("\t\t\t���޴��ˣ������������...\n");
	_getch();
}
/***************�����������ҡ�*************/
void SearchName(STU *ptemp)
{
	char name[20];

	system("cls");
	printf("\n\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t��		���ڲ鿴ѧԱ		 ��\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t������������");
	scanf("%s", name);

	ptemp = ptemp->pnext; //ָ���һ������

	int n = 0;
	while (ptemp != NULL)
	{
		if (!strcmp(ptemp->name, name))
		{
			if (n == 0)
			{
				printf("\t\t\tѧ��\t����\t����\t��ѧ\n");
			}
			printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
			n++;
		}
		ptemp = ptemp->pnext;
	}
	//û���ҵ� ��������
	if (n == 0)
	{
		printf("\t\t\t���޴��ˣ������������...\n");
	}
	_getch();
}
/***************���޸���Ϣ��*************/
void Modify(STU *ptemp)
{
	//�޸ĳɼ�
	int		num;
	int		num1;
	char	ch;
	system("cls");
	printf("\n\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t��		�����޸���Ϣ		 ��\n");
	printf("\t\t\t������������������������������������������������������������������������������������\n");
	printf("\t\t\t������ѧ�ţ�");
	scanf("%d", &num);

	ptemp = ptemp->pnext; //ָ���һ������
	while (ptemp != NULL)
	{
		if (ptemp->num == num)
		{
			printf("\t\t\tѧ��\t����\t����\t��ѧ\n");
			printf("\t\t\t%d\t%s\t%.2f\t%.2f\n", ptemp->num, ptemp->name, ptemp->chinese, ptemp->math);
			printf("\t\t\t�Ƿ��޸ģ�y/n����");
			fflush(stdin);
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				printf("\t\t\t�޸���ѧ�밴1\n\t\t\t�޸������밴2��");
				scanf("%d", &num1);
				if (num1 == 1)
				{
					printf("\t\t\t�������µ���ѧ�ɼ���");
					scanf("%f", &ptemp->math);
				}
				else if (num1 == 2)
				{
					printf("\t\t\t�������µ����ĳɼ���");
					scanf("%f", &ptemp->chinese);
				}

				printf("\t\t\t�޸ĳɹ�! ���������...");
				_getch();
				return;  //�ҵ�  return
			}
			else
			{
				return;
			}
		}
		ptemp = ptemp->pnext;
	}
}
/***************�����浽�ļ���*************/
void SaveData()
{
	STU *ptemp = pStu->pnext;

	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("\t\t\t�ļ���ʧ�ܣ���");
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
/***************��ɾ����Ϣ��*************/
void deletestu()
{
	STU *ptemp = pStu;
	if (pStu->pnext == NULL)
	{
		printf("\t\t\t��ϵͳĿǰΪ�գ�");
		return;
	}
	else
	{
		int num; 
		system("cls");
		printf("\n\n");
		printf("\t\t\t������������������������������������������������������������������������������������\n");
		printf("\t\t\t��		����ɾ����Ϣ		 ��\n");
		printf("\t\t\t������������������������������������������������������������������������������������\n");
		printf("\t\t\t��������Ҫɾ����Ϣ��ѧ����ѧ��:");
		scanf("%d", &num);
		while (ptemp->pnext->num != num&&ptemp != NULL)
		{
			ptemp = ptemp->pnext;
		}
		if (ptemp == NULL)
		{
			printf("û��ѧ��Ϊ%d��ѧ����", num);
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

