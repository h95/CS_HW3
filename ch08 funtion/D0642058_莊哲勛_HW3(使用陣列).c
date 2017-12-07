/*D0642058_������_HW3.c(�ϥ�array)*/ 
#include <stdio.h>
#define LEN 17 

void power_off(int);						//���q���Ǩ��(�ǤJ���ƬO���j��) 

int main()
{
	for(int i = 5; i <= 8; i++)
	{
		printf("%d�����q���Ǭ��G", i);
		power_off(i);						//�L�X���q���� 
		printf("\n");
	}
	return 0;
}

void power_off(int num)						//���q���Ǩ��(�ǤJ���ƬO���j��) 
{
	int dist[LEN + 1] = {0}, index = 1; 
	
	printf("%3d", index);					//�L�X�Ĥ@�Ӱ��q���� 
	dist[index] = 1;						//���ϰ��q�L�F 
	
	for(int i = 0; i < LEN - 1; i++)		//���F�Ĥ@���q�����٦� 16 �ϭn�� 
	{		
		for(int j = 0; j < num; j++)		//�C�Ӱ��q�϶��j num �� 
		{
			index++;
			while(dist[index])				//�p�G���q�L�N�q�U�@�϶}�l�� 
			{
				index++;
				if(index > LEN)				//�p�G�j�� 17 �ϴN�q�� 1 �϶}�l 
					index %= LEN;
			}
		}
		printf("%3d", index);				//�L�X���q���� 
		dist[index] = 1;					//�Хܦ��ϰ��q�L�F 
	}
}
