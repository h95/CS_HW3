/*D0642058_������_HW3.c(��array��circularly_linked_list)*/ 
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
	int dist[LEN + 1], index = 1, prev, temp;	//���ϰ}�C, ���ޭ�(��l��0), �e�@��, �Ȧs 
	
	for(int i = 1; i <= LEN; i++)			//��l�ư}�C, �񪺭ȬO�U�@�쪺���ޭ� 
	{
		if(i != LEN)
			dist[i] = i + 1;				//�p�G���O�̫�@��, �U�@��O�ۨ� +1 
		else
			dist[i] = 1;					//�p�G�O�̫�@��, �U�@��O�Ĥ@��(0)
	}
	
	for(int i = 0; i < LEN; i++)			//�L�X�Ҧ��ϰ�, �@ LEN �� 
	{
		printf("%3d", index);				//�L�X��e�n���q���ϰ� 
		
		prev = index;
		while(dist[prev] != index)			//��X�e�@�ӫ��V��e�ϰ쪺�ϰ�, �Y while(prev->next != current) prev = prev->next;
			prev = dist[prev];
		dist[prev] = dist[index];			//�e�@�Ӱϰ���V��e���V���ϰ�, �Y prev->next = current->next; 
		
		for(int j = 0; j < num; j++)		//��e�ϰ��ܦ��U num �ӫ��V���ϰ�, �Y current = current->next;���� num �� 
			index = dist[index];
	}
}
