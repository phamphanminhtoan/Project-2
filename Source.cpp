#include <iostream>
#include <string.h>
#include <direct.h>
#include <Windows.h>
using namespace std;

//- Hiển thị nội dung tập tin – TYPE : đọc nội dung tập tin và xuất ra màn hình

void ImplementedCommands(char temp[], char commands[], int i)
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
	}
	if (stricmp(temp, "del") == 0)
	{
		DeleteFile(Link1);
	}
	if (stricmp(temp, "mkdir") == 0)
	{
		mkdir(Link1);
	}
	if (stricmp(temp, "rd") == 0)
	{
		rmdir(Link1);
	}
	if (stricmp(temp, "createfile") == 0)
	{
		FILE *fSrc = fopen(Link1, "w");
		fclose(fSrc);
	}
	if (stricmp(temp, "viewfile") == 0)
	{

	}
	if (stricmp(temp, "editfile") == 0)
	{

	}
}
void main()
{
	for (int i = 0;; i++)
	{
		char commands[100];
		gets(commands);
		if (stricmp(commands, "pwd") == 0)
		{
			printf("C:\\");
		}
		if (stricmp(commands, "exit") == 0)
		{
			return;
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
			ImplementedCommands(temp, commands, i + 1);
		}
	}
	system("pause");
}