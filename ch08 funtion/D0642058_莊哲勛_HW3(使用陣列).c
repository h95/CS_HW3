/*D0642058_莊哲勛_HW3.c(使用array)*/ 
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
	int dist[LEN + 1] = {0}, index = 1; 
	
	printf("%3d", index);					//印出第一個停電的區 
	dist[index] = 1;						//此區停電過了 
	
	for(int i = 0; i < LEN - 1; i++)		//除了第一停電的區還有 16 區要停 
	{		
		for(int j = 0; j < num; j++)		//每個停電區間隔 num 區 
		{
			index++;
			while(dist[index])				//如果停電過就從下一區開始數 
			{
				index++;
				if(index > LEN)				//如果大於 17 區就從第 1 區開始 
					index %= LEN;
			}
		}
		printf("%3d", index);				//印出停電的區 
		dist[index] = 1;					//標示此區停電過了 
	}
}
