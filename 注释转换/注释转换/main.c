
#include <stdio.h>
#include <string.h>
#include <assert.h>

#pragma warning(disable:4996)

typedef enum State
{
	NORMAL,			//不是注释
	Find_Slash,		//有可能进入注释
	CPP_Comment,		//C++注释
	C_Comment,		//C注释
	Find_Star		//有可能出C注释
}State;

int main()
{
	FILE* pIn = fopen("input.c", "r");
	assert(pIn);
	FILE* pOut = fopen("output.c", "w");
	assert(pOut);

	State state = NORMAL;
	char ch, Nextch;

	while (1)
	{
		ch = fgetc(pIn);
		if (ch == EOF)
			break;

		switch (state)
		{
		case NORMAL:
			if (ch == '/')
				state = Find_Slash;
			else
				state = NORMAL;
			fputc(ch, pOut);
			break;

		case Find_Slash:
			if (ch == '*')
			{
				state = C_Comment;
				fputc('/',pOut);
			}
			else if (ch == '/')
			{
				state = CPP_Comment;
				fputc('/', pOut);
			}
			else
			{
				state = NORMAL;
				fputc(ch, pOut);
			}
			break;

		case C_Comment:
			if (ch == '*')
			{
				Nextch = fgetc(pIn);
				state = Find_Star;
				//如果下一个字符是‘/’说明要出注释，不打印
				//否则，打印
				if (Nextch != '/')
					fputc(ch, pOut);
				ungetc(Nextch, pIn);
			}
			else
			{
				state = C_Comment;
				if (ch == '\n')
				{
					fputc(ch, pOut);
					fputc('/', pOut);
					fputc('/', pOut);
				}
				else
				{
					fputc(ch, pOut);
				}
			}
			break;

		case CPP_Comment:
			if (ch == '\n')
				state = NORMAL;
			else
				state = CPP_Comment;
			fputc(ch, pOut);
			break;

		case Find_Star:
			if (ch == '/')
			{
				state = NORMAL;
				Nextch = fgetc(pIn);
				if (Nextch != '\n')
				{
					fputc('\n', pOut);
				}
				ungetc(Nextch, pIn);
			}
			else if (ch == '*')
			{
				fputc(ch, pOut);
				state = Find_Star;
			}
			else
			{
				state = C_Comment;
				fputc(ch, pOut);
			}
			break;

		default:
			break;
		}
	}

	fclose(pIn);
	fclose(pOut);
	
	return 0;
}