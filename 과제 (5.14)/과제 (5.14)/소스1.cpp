#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int value[100];
int global_count =0;

int checkvalue(int value);
void Get_max();
void Get_min();
void Get_avr();
void Get_middle();
int main()
{
	for (int i = 0; i < 100; i++) //100번 반복에 필요한  for문
	{
		int tmp;
		printf("값을 입력하시오 :");
		scanf("%d", &tmp);
		if (tmp == -1) // -1이 나오면 멈춤
		{
			break;
		}
		int ret = checkvalue(tmp);
		if (ret ==1 ) // 값이 1일때만 value 값에 저장한다. 
		{
			value[global_count++] = tmp;
			printf("global_count :%d\n", global_count); //카운트가 잘 되는지 확인하기 위한 printf(답과는 상관 없다).
		}
	}
	Get_max();
	Get_min();
	Get_avr();
	Get_middle();

}
int checkvalue(int value)
{
	if (value < 1 || value >100) // 범위 설정.
	{
		return 0;
	}
	else return 1;
}

void Get_max()
{
	int max = value[0];
	for (int i = 1; i < global_count; i++)//최댓값을 구하기 위한 for문
	{
		if (value[i] > max)
		{
			max = value[i];
		}
	}
	printf("최댓값은 %d 입니다\n", max);
}
void Get_min()
{
	int min = value[0];
	for (int k = 1; k < global_count; k++)//최솟값을 구하기 위한 for문
	{
		if (value[k] < min)
		{
			min = value[k];
		}
	}
	printf("최솟값은 %d 입니다.\n", min);
}
void Get_avr()
{
	int avr;
	int sum = 0;
	for (int j = 0; j < global_count; j++)//평균을 구하기 위한 for문
	{
		sum += value[j];
	}
	avr = sum / global_count;
	printf("평균은 %d 입니다.\n ", avr);
}
void Get_middle()
{
	int m=0;
	for (int l = 0; l < global_count; l++)//중간값을 구하기 위한 for문 정렬이 필요하다.
	{

		for (m = 0; m < global_count - 1; m++)
		{
			if (value[m] > value[m + 1])
			{
				int chg = value[m];
				value[m] = value[m + 1];
				value[m + 1] = chg;
			}
		}
	}		
	printf("중간값은 %d 입니다.\n", value[m / 2]); //어차피 나누면 정수형으로 받으므로 나머지는 버려지게 되므로 갯수가 짝수이거나 홀수이거나 상관 없다.
}