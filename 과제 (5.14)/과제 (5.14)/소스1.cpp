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
	for (int i = 0; i < 100; i++) //100�� �ݺ��� �ʿ���  for��
	{
		int tmp;
		printf("���� �Է��Ͻÿ� :");
		scanf("%d", &tmp);
		if (tmp == -1) // -1�� ������ ����
		{
			break;
		}
		int ret = checkvalue(tmp);
		if (ret ==1 ) // ���� 1�϶��� value ���� �����Ѵ�. 
		{
			value[global_count++] = tmp;
			printf("global_count :%d\n", global_count); //ī��Ʈ�� �� �Ǵ��� Ȯ���ϱ� ���� printf(����� ��� ����).
		}
	}
	Get_max();
	Get_min();
	Get_avr();
	Get_middle();

}
int checkvalue(int value)
{
	if (value < 1 || value >100) // ���� ����.
	{
		return 0;
	}
	else return 1;
}

void Get_max()
{
	int max = value[0];
	for (int i = 1; i < global_count; i++)//�ִ��� ���ϱ� ���� for��
	{
		if (value[i] > max)
		{
			max = value[i];
		}
	}
	printf("�ִ��� %d �Դϴ�\n", max);
}
void Get_min()
{
	int min = value[0];
	for (int k = 1; k < global_count; k++)//�ּڰ��� ���ϱ� ���� for��
	{
		if (value[k] < min)
		{
			min = value[k];
		}
	}
	printf("�ּڰ��� %d �Դϴ�.\n", min);
}
void Get_avr()
{
	int avr;
	int sum = 0;
	for (int j = 0; j < global_count; j++)//����� ���ϱ� ���� for��
	{
		sum += value[j];
	}
	avr = sum / global_count;
	printf("����� %d �Դϴ�.\n ", avr);
}
void Get_middle()
{
	int m=0;
	for (int l = 0; l < global_count; l++)//�߰����� ���ϱ� ���� for�� ������ �ʿ��ϴ�.
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
	printf("�߰����� %d �Դϴ�.\n", value[m / 2]); //������ ������ ���������� �����Ƿ� �������� �������� �ǹǷ� ������ ¦���̰ų� Ȧ���̰ų� ��� ����.
}