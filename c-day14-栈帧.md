#### 习题1：
实现一个函数，可以左旋字符串中的k个字符。
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB 

代码如下:
```
#include <stdio.h>
#include <assert.h>

void zuoxuan(char *str, int num)
{
	char tmp;
	char *dst = str;

	assert(str); 
	while(num)
	{
		str = dst;
		tmp = *str;
		while(*(str+1))
		{
			*str =  *(str+1);
			str++;
		}
		*str = tmp;
		num--;
	}
}

int main()
{
	char ch[15] = " ";
	int num = 0;

	scanf("%d", &num);    //获取左旋的个数
	scanf("%s", ch);	  //获取字符串
	zuoxuan(ch, num);
	printf("%s\n", ch);

	return 0;
}
```
*在写程序中遇到的问题：
把指针没有解引用，一直对指针做运算，程序没有输出结果，发现是没有解引用。*

#### 习题2:

2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0.

AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC 

**理解：这个题目和第一个题目类似，上边的字符串右旋一个字符就相当于左旋两个字符。**
```
#include <stdio.h>
#include <assert.h>
#include <string.h>


int judge(char *str1, char *str2, int size)  //代码的缺点是在翻转时改变了原来的字符串
{
	char tmp;
	char *dst = str1;

	assert(str1);
	assert(str2);
	while(size)
	{
		str1 = dst;

		if(strcmp(str1,str2) == 0)
			return 1;

		tmp = *str1;
		while(*(str1+1))
		{
			*str1 = *(str1+1);
			str1++;
		}
		*str1 = tmp;
		size--;
	}

	return 0;
}

int main()
{
	char s1[] = "ABCDEF";   //源字符串
	char s2[] = "DEFABC";   //要判断的字符串
	int ret = 0;
	int size = strlen(s1);

	ret = judge(s1, s2, size);
	if(ret == 0)
	{
		printf("No.\n");
	}
	else
	{
		printf("Yes.\n");
	}
	
	return 0;
}
```



















