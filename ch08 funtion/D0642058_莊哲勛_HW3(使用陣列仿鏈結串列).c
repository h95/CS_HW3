/*D0642058_莊哲勛_HW3.c(用array仿circularly_linked_list)*/ 
#include <stdio.h>
#define LEN 17 

void power_off(int);						//停電順序函數(傳入的數是間隔數)

int main()
{
	for(int i = 5; i <= 8; i++)
	{
		printf("%d的停電順序為：", i);
		power_off(i);						//印出停電順序 
		printf("\n");
	}

	return 0;
}

void power_off(int num)						//停電順序函數(傳入的數是間隔數) 
{
	int dist[LEN + 1], index = 1, prev, temp;	//分區陣列, 索引值(初始為1), 前一位, 暫存 
	
	for(int i = 1; i <= LEN; i++)			//初始化陣列, 放的值是下一位的索引值 
	{
		if(i != LEN)
			dist[i] = i + 1;				//如果不是最後一位, 下一位是自身 +1 
		else
			dist[i] = 1;					//如果是最後一位, 下一位是第一位
	}
	
	for(int i = 0; i < LEN; i++)			//印出所有區域, 共 LEN 個 
	{
		printf("%3d", index);				//印出當前要停電的區域 
		
		prev = index;
		while(dist[prev] != index)			//找出前一個指向當前區域的區域, 即 while(prev->next != current) prev = prev->next;
			prev = dist[prev];
		dist[prev] = dist[index];			//前一個區域指向當前指向的區域, 即 prev->next = current->next; 
		
		for(int j = 0; j < num; j++)		//當前區域變成下 num 個指向的區域, 即 current = current->next;重複 num 次 
			index = dist[index];
	}
}
