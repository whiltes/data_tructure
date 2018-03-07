###解密QQ号（队列）
首先将第 1 个数删除，紧接着将第 2 个数放到这串数的末尾，再将第 3 个数删除并将第 4 个数放到这串数的末尾，再将第 5 个数删除……
直到剩下最后一个数，将最后一个数也删除。
原数列：631759243


####1、暴力求解
此方法为首先想到的，将对头存到新的数组内，比较占空间，

```c语言

#include <stdio.h>

int main()
{
	int qm[100] = {0,6,3,1,7,5,8,9,2,4};
	int q[10] = {0};      //新数组，用于存放正确的QQ号
	int i = 0;	int j = 1;
	int head = 1; int tail = 9;

	for(i=0;i<10;i++)
	{
		tail++;
		qm[tail] = qm[head+1];      //新尾等于新头+1
		q[j] = qm[head];
		qm[head] = qm[head+2];  //新头等于原来的头+2
		head +=2;
		if(j == 9)
		{
			break;
		}
		j++;
	}
	for(j=1;j<=9;j++)
	{
		printf("%d", q[j]);
	}
	putchar('\n');

	return 0;
}
```

####2、用队列
队列是一种特
殊的线性结构，它只允许在队列的首部（ head）进行删除操作，这称为“出队”，而在队列
的尾部（ tail）进行插入操作，这称为“入队”。当队列中没有元素时（即 head==tail），称为
空队列。

```c语言

int main()
{
	int q[101] = {0,6,3,1,7,5,8,9,2,4};
	int head = 1; int tail = 10;

	while(head < tail)  //队列不为空执行循环
	{
		printf("%d", q[head]); //打印并出队
		head++;

		q[tail] = q[head]; //将新的队首添加到队尾
		tail++;

		head++;	//在出队
	}
	putchar('\n');


	return 0;
}

```
####3、方法还是队列，用了结构体（C语言里结构体不能直接在里边赋初值）

```c语言

#include <stdio.h>

struct queue
{
	int data[101];
	int head;
	int tail;
};

int main()
{
	struct queue q;
	int i = 0;

	q.head = 1;
	q.tail = 1;
	for(i=1;i<=9;i++)
	{
		scanf("%d",&q.data[q.tail]);
		q.tail++;
	}
	while(q.head < q.tail)
	{
		printf("%d ", q.data[q.head]);
		q.head++;

		q.data[q.tail] = q.data[q.head];
		q.tail++;
		q.head++;
	}

	return 0;
}

```



