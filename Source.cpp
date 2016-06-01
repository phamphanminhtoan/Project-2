#include <iostream>
#include <string.h>
#include <direct.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
using namespace std;
#pragma warning(disable:4996)

void EditFile(char Link1[])
{
	for (int i = 0;; i++)
	{
		printf("1: REPLACE\n");
		printf("2: INSERT\n");
		printf("3: THOAT\n");
		int chon;
		printf("Chon cong viec: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
		{
				  char reStr[100];
				  gets(reStr);
				  int ln = strlen(reStr);
				  FILE *f = fopen(Link1, "rt");
				  if (f != NULL)
				  {
					  while (!feof(f))
					  {
						  if (fgetc(f) == reStr[0])
						  {
							  int flag;
							  int count = 1;
							  for (int i = 1; i < ln; i++)
							  {
								  if (fgetc(f) == reStr[i])
								  {
									  count++;
								  }
								  else
								  {
									  flag = i;
									  break;
								  }
							  }
							  if (count == ln)
							  {
								  fseek(f, -ln, SEEK_CUR);
								  for (int j = 0; j < ln; j++)
								  {

								  }
							  }
						  }
					  }
				  }
		}
			break;
		case 2:
		{

		}
			break;
		default:
			return;
		}
		system("cls");
	}
}
void ImplementedCommands(char temp[], char commands[], int i, char deDir[])
{
	char Link1[100];
	int j = 0;
	while (commands[i] != ' ' && commands[i] != NULL)
	{
		Link1[j] = commands[i];
		j++;
		i++;
	}
	Link1[j] = NULL;
	if (stricmp(temp, "cd") == 0)
	{
		int h = 0;
		while (Link1[h] != NULL)
		{
			deDir[h] = Link1[h];
			h++;
		}
		deDir[h] = NULL;
		return;
	}
	if (stricmp(temp, "copy") == 0)
	{
		char fileName[100];
		int n = 0;
		j--;
		while (Link1[j] != '\\')
		{
			fileName[n] = Link1[j];
			n++;
			j--;
		}
		fileName[n] = NULL;
		strrev(fileName);
		i++;
		char Link2[100];
		int k = 0;
		while (commands[i] != ' ' && commands[i] != NULL)
		{
			Link2[k] = commands[i];
			k++;
			i++;
		}
		Link2[k] = '\\';
		k++;
		Link2[k] = NULL;
		strcat(Link2, fileName);
		FILE *fSrc = fopen(Link1, "rb");
		FILE *fDes = fopen(Link2, "wb");
		while (!feof(fSrc))
		{
			char c = fgetc(fSrc);
			fprintf(fDes, "%c", c);
		}
		fcloseall();
		return;
	}
	if (stricmp(temp, "move") == 0)
	{
		char fileName[100];
		int n = 0;
		j--;
		while (Link1[j] != '\\')
		{
			fileName[n] = Link1[j];
			n++;
			j--;
		}
		fileName[n] = NULL;
		strrev(fileName);
		i++;
		char Link2[100];
		int k = 0;
		while (commands[i] != ' ' && commands[i] != NULL)
		{
			Link2[k] = commands[i];
			k++;
			i++;
		}
		Link2[k] = '\\';
		k++;
		Link2[k] = NULL;
		strcat(Link2, fileName);
		FILE *fSrc = fopen(Link1, "rb");
		FILE *fDes = fopen(Link2, "wb");
		while (!feof(fSrc))
		{
			char c = fgetc(fSrc);
			fprintf(fDes, "%c", c);
		}
		fcloseall();
		DeleteFile(Link1);
		return;
	}
	if (stricmp(temp, "del") == 0)
	{
		int check;
		printf("Do you want to delete this file?\n");
		printf("1: yes\n");
		printf("0: no\n");
		scanf("%d", &check);
		if (check == 1)
		{
			DeleteFile(Link1);
			printf("Delete successfully!\n");
			return;
		}
		return;
	}
	if (stricmp(temp, "mkdir") == 0)
	{
		mkdir(Link1);
		return;
	}
	if (stricmp(temp, "rd") == 0)
	{
		int check;
		printf("Do you want to delete this folder?\n");
		printf("1: yes\n");
		printf("0: no\n");
		scanf("%d", &check);
		if (check == 1)
		{
			rmdir(Link1);
			printf("Delete successfully!\n");
			return;
		}
		return;
	}
	if (stricmp(temp, "createfile") == 0)
	{
		FILE *fSrc = fopen(Link1, "a");
		system(Link1);
		fclose(fSrc);
		return;
	}
	if (stricmp(temp, "viewfile") == 0)
	{
		FILE *fView = fopen(Link1, "rb");
		setmode(fileno(fView), _O_U16TEXT);
		fgetwc(fView);
		wchar_t c[100];
		while (!feof(fView))
		{
			fgetws(c, 100, fView);
			wcout << c;
		}
		fclose(fView);
		return;
	}
	if (stricmp(temp, "editfile") == 0)
	{
		EditFile(Link1);
	}
}
void main()
{
	char deDir[] = "C:\\";
	for (int j = 0;; j++)
	{
		char commands[100];
		gets(commands);
		if (stricmp(commands, "pwd") == 0)
		{
			printf("%s\n", deDir);
			continue;
		}
		if (stricmp(commands, "exit") == 0)
		{
			return;
		}
		else
		{
			char temp[20];
			int i = 0;
			while (commands[i] != ' ')
			{
				temp[i] = commands[i];
				i++;
			}
			temp[i] = NULL;
			ImplementedCommands(temp, commands, i + 1, deDir);
		}
	}
	system("pause");
}
