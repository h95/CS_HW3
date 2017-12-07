/*D0642058_莊哲勛_HW3.c(用circularly_linked_list)*/ 
#include <stdio.h>
#define LEN 17

typedef struct node
{
	int num;
	struct node *next;
}link, *list;

void power_off(int);							//停電順序函數(傳入的數是間隔數)

int main()
{
	for(int i = 5; i <= 8; i++)
	{
		printf("%d的停電順序為：", i);
		power_off(i);							//印出停電順序 
		printf("\n");
	}
	return 0;
}

void power_off(int num)							//停電順序函數(傳入的數是間隔數) 
{
	link dist[LEN];	int start = 0;
	list current, previous;
	
	for(int i = 0; i < LEN; i++)
	{
		(dist + i)->num = i + 1;
		if(i != LEN - 1)
			(dist + i)->next = (dist + i + 1);	//如果不是最後一位, 下一位是自身 +1   
		else
			(dist + i)->next = dist;			//如果是最後一位, 下一位是第一位
	}

	current = (dist + start);					//當前區域為起始區域 
	
	for(int i = 0; i < LEN; i++)				//印出所有區域, 共 LEN 個  
	{
		printf("%3d", current->num);			//印出當前要停電的區域 
		
		previous = current;
		while(previous->next != current)		//找出前一個指向當前區域的區域
			previous = previous->next;
			
		previous->next = current->next;			//前一個區域指向當前指向的區域
		
		for(int j = 0; j < num; j++)			//當前區域變成下 num 個指向的區域
			current = current->next;
	}
}
