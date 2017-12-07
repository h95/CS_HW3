/*D0642058_������_HW3.c(��circularly_linked_list)*/ 
#include <stdio.h>
#define LEN 17

typedef struct node
{
	int num;
	struct node *next;
}link, *list;

void power_off(int);							//���q���Ǩ��(�ǤJ���ƬO���j��)

int main()
{
	for(int i = 5; i <= 8; i++)
	{
		printf("%d�����q���Ǭ��G", i);
		power_off(i);							//�L�X���q���� 
		printf("\n");
	}
	return 0;
}

void power_off(int num)							//���q���Ǩ��(�ǤJ���ƬO���j��) 
{
	link dist[LEN];	int start = 0;
	list current, previous;
	
	for(int i = 0; i < LEN; i++)
	{
		(dist + i)->num = i + 1;
		if(i != LEN - 1)
			(dist + i)->next = (dist + i + 1);	//�p�G���O�̫�@��, �U�@��O�ۨ� +1   
		else
			(dist + i)->next = dist;			//�p�G�O�̫�@��, �U�@��O�Ĥ@��
	}

	current = (dist + start);					//��e�ϰ쬰�_�l�ϰ� 
	
	for(int i = 0; i < LEN; i++)				//�L�X�Ҧ��ϰ�, �@ LEN ��  
	{
		printf("%3d", current->num);			//�L�X��e�n���q���ϰ� 
		
		previous = current;
		while(previous->next != current)		//��X�e�@�ӫ��V��e�ϰ쪺�ϰ�
			previous = previous->next;
			
		previous->next = current->next;			//�e�@�Ӱϰ���V��e���V���ϰ�
		
		for(int j = 0; j < num; j++)			//��e�ϰ��ܦ��U num �ӫ��V���ϰ�
			current = current->next;
	}
}
