#include <stdio.h>
#include <windows.h>
#include <errno.h>

#pragma warning(disable:4996)

int main()
{

	char str[80];
	float f;
	FILE* fp;

	int c = 0;
	fp = fopen("myfile.txt", "w+");
	fprintf(fp, "%f %s", 3.1415, "PI");
	rewind(fp);			//rewind 将文件指针重新定位到文件开头

	fscanf(fp, "%f", &f);			
	fscanf(fp, "%d", c);
	fclose(fp);

	printf("I have read:%f and %s", f, c);


	/*
	FILE *fp;
	char sentence[256];

	printf("Enter sentence to append:");
	fgets(sentence, 256, stdin);
	fp = fopen("myfile.txt", "a");
	fputs(sentence, fp);
	
	fclose(fp);*/


	//FILE *fp;
	//char mystring[100];

	//fp = fopen("myfile.txt", "r");
	//if (NULL == fp)
	//	perror("Error opening file");
	//else
	//{
	//	if (fgets(mystring, 100, fp) != NULL)
	//		puts(mystring);
	//	fclose(fp);
	//}
		

	//char string[] = "hello world";
	//puts(string);

	//char string[256];
	//printf("adress:");
	//gets(string);
	//printf("your adress: %s\n", string);



	/*FILE *fp;
	char c = 0;
	fp = fopen("myfile.txt", "wb");

	for (c = 'A'; c <= 'Z'; ++c)
		putc(c, fp);

	fclose(fp);*/


	//FILE *fp;
	//int c;
	//int n = 0;

	//fp = fopen("myfile.txt", "r");
	//if (NULL == fp)
	//	perror("fp");
	//else
	//{
	//	do
	//	{
	//		c = getc(fp);
	//		if (c == '$')
	//			n++;
	//	} while (c != EOF);
	//	fclose(fp);
	//	printf("$: %d\n", n);
	//}



	//int c = 0;
	//puts("Enter text. Include a dot('.') in a sentence to exit:");
	//do
	//{
	//	c = getc(stdin);
	//	putc(c, stdout);

	//} while (c != '.');

	//FILE *fp;
	//fp = fopen("myfile.txt", "wt");
	//fprintf(stdout, "fclose example");
	//fclose(fp);

	//FILE *fp;
	//fp = fopen("myfile.txt", "w");
	//if (NULL != fp)
	//{
	//	fputs("fopen example", fp);
	//	fclose(fp);
	//}


	//printf("HelloWorld");

	//FILE *fp;
	//fp = fopen("myfile.txt", "a");
	//if (NULL == fp)
	//{
	//	printf("Error opening file");
	//	exit(EXIT_FAILURE);
	//}
	//else
	//{
	//	;
	//}


	//FILE *pFile;
	//pFile = fopen("unexist.ent", "rb");
	//if (NULL == pFile)
	//	//perror("pFile");
	//	printf(" pFile:%s\n", strerror(errno));
	//else
	//	fclose(pFile);

	system("pause");
	return 0;
}