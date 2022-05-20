#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int value[100];
int global_count;

int Get_Max();
int Get_Min();
int checkvalue(int value);


int ret;

int main()
{
	int i;	
	for (i = 0; i < 100; i++)
	{			

		printf("값을 입력하시오 :");
		scanf("%d", &value[i]);
		if (i == -1)
		{
			break;
		}
	}
}

int Get_Max()
{
	if (ret == 1)
	{
		
	}
}

int Get_min()
{

}

int checkvalue(int value)
{

	if (value < 1 && value>99)
	{
		ret = 1;
	}
	else ret =0;

}




