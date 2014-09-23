#include<stdio.h>
#include<string.h>

const int maxint = 999999;


void Dijkstra(int n, int v, int *dist, int *prev, int c[300][300])
{
	int s[10000];
	for (int i = 1; i <= n; ++i)
	{

		dist[i] = c[v][i];
		s[i] = 0;     // S���ϳ�ʼ��
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;//����������ʼ��ĵ�
	}
	dist[v] = 0;//�Լ����Լ�Ϊ0��
	s[v] = 1;//Դ�����S����

	// ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
	//��s����1��0��ʾ�Ƿ���S������
	for (int i = 2; i <= 10000; ++i)
	{
		int tmp = maxint;
		int u = v;
		// �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
		for (int j = 1; j <= n; ++j)
		if ((!s[j]) && dist[j]<tmp)//S��j��Ϊ0��ִ�к�����䣻

		{
			u = j;              // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
			tmp = dist[j];
		}
		s[u] = 1;    // ��ʾu���Ѵ���S������

		// ����dist
		for (int j = 1; j <= n; ++j)
		if ((!s[j]) && c[u][j]<maxint)
		{
			int newdist = dist[u] + c[u][j];
			if (newdist < dist[j])
			{
				dist[j] = newdist;
				prev[j] = u;
			}
		}
	}
}

void way(int *prev, int v, int u)//v�����  u���յ�
{
	int que[10000];
	int num = 1;
	que[num] = u;//que��num������ʾ��  1�����յ� 
	num++;
	int tmp = prev[u];
	while (tmp != v)
	{
		que[num] = tmp;
		num++;
		tmp = prev[tmp];
	}//ѭ��ʹһ�δ����ϸ��㣬���м����tmp����ʾ�ϸ�����
	que[num] = v;
	int i;
	i = num;
	int zp=0; //����վ�ƺ�
	//**********************************************************************************************************************************
	if (((que[i] >= 1 && que[i] <= 15) || (que[i] >= 195 && que[i] <= 202)) && ((que[i - 1] >= 1 && que[i - 1] <= 15) || (que[i - 1] >= 195 && que[i - 1] <= 202)))
	{
		printf("�������1���ߵ�����");
		zp = 1;
	}
	else if (((que[i] >= 16 && que[i] <= 23) || (que[i] >= 203 && que[i] <= 209) || que[i] == 200 || que[i] == 194 || que[i] == 198) && ((que[i - 1] >= 16 && que[i - 1] <= 23) || (que[i - 1] >= 203 && que[i - 1] <= 209) || que[i - 1] == 200 || que[i - 1] == 194 || que[i - 1] == 198))
	{
		printf("(�����2���ߵ���)");
		zp = 2;
	}
	else if (((que[i] >= 24 && que[i] <= 51) || (que[i] >= 210 && que[i] <= 213) || que[i] == 194 || que[i] == 195 || que[i] == 208) && ((que[i - 1] >= 24 && que[i - 1] <= 51) || (que[i - 1] >= 210 && que[i - 1] <= 213) || que[i - 1] == 194 || que[i - 1] == 195 || que[i - 1] == 208))
	{
		printf("(�����4�Ŵ�����)");
		zp = 3;
	}
	else if (((que[i] >= 52 && que[i] <= 67) || (que[i] >= 214 && que[i] <= 217) || que[i] == 206 || que[i] == 203 || que[i] == 199) && ((que[i - 1] >= 52 && que[i - 1] <= 67) || (que[i - 1] >= 214 && que[i - 1] <= 217) || que[i - 1] == 206 || que[i - 1] == 203 || que[i - 1] == 199))
	{
		printf("(�����5����)");
		zp = 4;
	}
	else if (((que[i] >= 68 && que[i] <= 79) || (que[i] >= 218 && que[i] <= 221) || que[i] == 209 || que[i] == 204 || que[i] == 212 || que[i] == 216) && ((que[i - 1] >= 68 && que[i - 1] <= 79) || (que[i - 1] >= 218 && que[i - 1] <= 221) || que[i - 1] == 209 || que[i - 1] == 204 || que[i - 1] == 212 || que[i - 1] == 216))
	{
		printf("(�����6����)");
		zp = 5;
	}
	else if (((que[i] >= 80 && que[i] <= 91) || que[i] == 222 || que[i] == 223 || que[i] == 224 || que[i] == 207 || que[i] == 220) && ((que[i - 1] >= 80 && que[i - 1] <= 91) || que[i - 1] == 222 || que[i - 1] == 223 || que[i - 1] == 224 || que[i - 1] == 207 || que[i - 1] == 220))
	{
		printf("(�����8����)");
		zp = 6;
	}
	else if (((que[i] >= 92 && que[i] <= 98) || que[i] == 211 || que[i] == 219 || que[i] == 197 || que[i] == 225 || que[i] == 226 || que[i] == 227) && ((que[i - 1] >= 92 && que[i - 1] <= 98) || que[i - 1] == 211 || que[i - 1] == 219 || que[i - 1] == 197 || que[i - 1] == 225 || que[i - 1] == 226 || que[i - 1] == 227))
	{
		printf("(�����9����)");
		zp = 7;
	}
	else if (((que[i] >= 99 && que[i] <= 129) || que[i] == 213 || que[i] == 217 || que[i] == 201 || que[i] == 221 || que[i] == 228 || que[i] == 229 || que[i] == 215 || que[i] == 224 || que[i] == 230 || que[i] == 210 || que[i] == 218 || que[i] == 196 || que[i] == 225 || que[i] == 231) && \
		((que[i - 1] >= 99 && que[i - 1] <= 129) || que[i - 1] == 213 || que[i - 1] == 217 || que[i - 1] == 201 || que[i - 1] == 221 || que[i - 1] == 228 || que[i - 1] == 229 || que[i - 1] == 215 || que[i - 1] == 224 || que[i - 1] == 230 || que[i - 1] == 210 || que[i - 1] == 218 || que[i - 1] == 196 || que[i - 1] == 225 || que[i - 1] == 231))
	{
		printf("(�����10����)");
		zp = 8;
	}
	else if (((que[i] >= 130 && que[i] <= 137) || que[i] == 208 || que[i] == 230 || que[i] == 232 || que[i] == 223 || que[i] == 214 || que[i] == 233 || que[i] == 229 || que[i] == 205) && ((que[i - 1] >= 130 && que[i - 1] <= 137) || que[i - 1] == 208 || que[i - 1] == 230 || que[i - 1] == 232 || que[i - 1] == 223 || que[i - 1] == 214 || que[i - 1] == 233 || que[i - 1] == 229 || que[i - 1] == 205))
	{
		printf("(�����13����)");
		zp = 9;

	}

	else if (((que[i] >= 138 && que[i] <= 142) || que[i] == 226 || que[i] == 231) && ((que[i - 1] >= 138 && que[i - 1] <= 142) || que[i - 1] == 226 || que[i - 1] == 231))
	{
		printf("(�����14����)");
		zp = 10;
	}
	else if (((que[i] >= 143 && que[i] <= 153) || que[i] == 233) && ((que[i - 1] >= 143 && que[i - 1] <= 153) || que[i - 1] == 233))
	{
		printf("�������15���ߣ�");
		zp = 11;
	}
	else if (((que[i] >= 154 && que[i] <= 164) || que[i] == 15 || que[i] == 202) && ((que[i - 1] >= 154 && que[i - 1] <= 164) || que[i - 1] == 15 || que[i - 1] == 202))
	{
		printf("(�������ͨ��)");
		zp =12;
	}
	else if (((que[i] >= 165 && que[i] <= 169) || que[i] == 222 || que[i] == 232) && ((que[i - 1] >= 165 && que[i - 1] <= 169) || que[i - 1] == 222 || que[i - 1] == 232))
	{
		printf("(�������ƽ��)");
		zp = 13;
	}
	else if (((que[i] >= 170 && que[i] <= 181) || que[i] == 217) && ((que[i - 1] >= 170 && que[i - 1] <= 181) || que[i - 1] == 217))
	{
		printf("(�������ׯ��)");
		zp = 14;
	}
	else if (((que[i] >= 182 && que[i] <= 191) || que[i] == 227) && ((que[i - 1] >= 182 && que[i - 1] <= 191) || que[i - 1] == 227))
	{
		printf("(�������ɽ��)");
		zp = 15;
	}
	else if ((que[i] == 205 || que[i] == 228 || que[i] == 192 || que[i] == 193) && (que[i - 1] == 205 || que[i - 1] == 228 || que[i - 1] == 192 || que[i - 1] == 193))

	{
		printf("(�����������)");
		zp = 16;
	}




	//*************************************************************************************************************************************
	for (i = num; i >= 1; --i)
	if (i != 1)
	{

		//**********************************************************************************************************************************
		if (((que[i] >= 1 && que[i] <= 15) || (que[i] >= 195 && que[i] <= 202)) && ((que[i - 1] >= 1 && que[i - 1] <= 15) || (que[i - 1] >= 195 && que[i - 1] <= 202)) && zp != 1)
		{
			printf("�������1���ߵ�����");
			zp = 1;
		}
		else if (((que[i] >= 16 && que[i] <= 23) || (que[i] >= 203 && que[i] <= 209) || que[i] == 200 || que[i] == 194 || que[i] == 198) && ((que[i - 1] >= 16 && que[i - 1] <= 23) || (que[i - 1] >= 203 && que[i - 1] <= 209) || que[i - 1] == 200 || que[i - 1] == 194 || que[i - 1] == 198) && zp != 2)
		{
			printf("(�����2���ߵ���)");
			zp = 2;
		}
		else if (((que[i] >= 24 && que[i] <= 51) || (que[i] >= 210 && que[i] <= 213) || que[i] == 194 || que[i] == 195 || que[i] == 208) && ((que[i - 1] >= 24 && que[i - 1] <= 51) || (que[i - 1] >= 210 && que[i - 1] <= 213) || que[i - 1] == 194 || que[i - 1] == 195 || que[i - 1] == 208) && zp != 3)
		{
			printf("(�����4�Ŵ�����)");
			zp = 3;
		}
		else if (((que[i] >= 52 && que[i] <= 67) || (que[i] >= 214 && que[i] <= 217) || que[i] == 206 || que[i] == 203 || que[i] == 199) && ((que[i - 1] >= 52 && que[i - 1] <= 67) || (que[i - 1] >= 214 && que[i - 1] <= 217) || que[i - 1] == 206 || que[i - 1] == 203 || que[i - 1] == 199) && zp != 4)
		{
			printf("(�����5����)");
			zp = 4;
		}
		else if (((que[i] >= 68 && que[i] <= 79) || (que[i] >= 218 && que[i] <= 221) || que[i] == 209 || que[i] == 204 || que[i] == 212 || que[i] == 216) && ((que[i - 1] >= 68 && que[i - 1] <= 79) || (que[i - 1] >= 218 && que[i - 1] <= 221) || que[i - 1] == 209 || que[i - 1] == 204 || que[i - 1] == 212 || que[i - 1] == 216) && zp != 5)
		{
			printf("(�����6����)");
			zp = 5;
		}
		else if (((que[i] >= 80 && que[i] <= 91) || que[i] == 222 || que[i] == 223 || que[i] == 224 || que[i] == 207 || que[i] == 220) && ((que[i - 1] >= 80 && que[i - 1] <= 91) || que[i - 1] == 222 || que[i - 1] == 223 || que[i - 1] == 224 || que[i - 1] == 207 || que[i - 1] == 220) && zp != 6)
		{
			printf("(�����8����)");
			zp = 6;
		}
		else if (((que[i] >= 92 && que[i] <= 98) || que[i] == 211 || que[i] == 219 || que[i] == 197 || que[i] == 225 || que[i] == 226 || que[i] == 227) && ((que[i - 1] >= 92 && que[i - 1] <= 98) || que[i - 1] == 211 || que[i - 1] == 219 || que[i - 1] == 197 || que[i - 1] == 225 || que[i - 1] == 226 || que[i - 1] == 227) && zp != 7)
		{
			printf("(�����9����)");
			zp = 7;
		}
		else if (((que[i] >= 99 && que[i] <= 129) || que[i] == 213 || que[i] == 217 || que[i] == 201 || que[i] == 221 || que[i] == 228 || que[i] == 229 || que[i] == 215 || que[i] == 224 || que[i] == 230 || que[i] == 210 || que[i] == 218 || que[i] == 196 || que[i] == 225 || que[i] == 231) && \
			((que[i - 1] >= 99 && que[i - 1] <= 129) || que[i - 1] == 213 || que[i - 1] == 217 || que[i - 1] == 201 || que[i - 1] == 221 || que[i - 1] == 228 || que[i - 1] == 229 || que[i - 1] == 215 || que[i - 1] == 224 || que[i - 1] == 230 || que[i - 1] == 210 || que[i - 1] == 218 || que[i - 1] == 196 || que[i - 1] == 225 || que[i - 1] == 231) && zp != 8)
		{
			printf("(�����10����)");
			zp = 8;
		}
		else if (((que[i] >= 130 && que[i] <= 137) || que[i] == 208 || que[i] == 230 || que[i] == 232 || que[i] == 223 || que[i] == 214 || que[i] == 233 || que[i] == 229 || que[i] == 205) && ((que[i - 1] >= 130 && que[i - 1] <= 137) || que[i - 1] == 208 || que[i - 1] == 230 || que[i - 1] == 232 || que[i - 1] == 223 || que[i - 1] == 214 || que[i - 1] == 233 || que[i - 1] == 229 || que[i - 1] == 205) && zp != 9)
		{
			printf("(�����13����)");
			zp = 9;

		}

		else if (((que[i] >= 138 && que[i] <= 142) || que[i] == 226 || que[i] == 231) && ((que[i - 1] >= 138 && que[i - 1] <= 142) || que[i - 1] == 226 || que[i - 1] == 231) && zp != 10)
		{
			printf("(�����14����)");
			zp = 10;
		}
		else if (((que[i] >= 143 && que[i] <= 153) || que[i] == 233) && ((que[i - 1] >= 143 && que[i - 1] <= 153) || que[i - 1] == 233) && zp != 11)
		{
			printf("�������15���ߣ�");
			zp = 11;
		}
		else if (((que[i] >= 154 && que[i] <= 164) || que[i] == 15 || que[i] == 202) && ((que[i - 1] >= 154 && que[i - 1] <= 164) || que[i - 1] == 15 || que[i - 1] == 202) && zp != 12)
		{
			printf("(�������ͨ��)");
			zp = 12;
		}
		else if (((que[i] >= 165 && que[i] <= 169) || que[i] == 222 || que[i] == 232) && ((que[i - 1] >= 165 && que[i - 1] <= 169) || que[i - 1] == 222 || que[i - 1] == 232) && zp != 13)
		{
			printf("(�������ƽ��)");
			zp = 13;
		}
		else if (((que[i] >= 170 && que[i] <= 181) || que[i] == 217) && ((que[i - 1] >= 170 && que[i - 1] <= 181) || que[i - 1] == 217) && zp != 14)
		{
			printf("(�������ׯ��)");
			zp = 14;
		}
		else if (((que[i] >= 182 && que[i] <= 191) || que[i] == 227) && ((que[i - 1] >= 182 && que[i - 1] <= 191) || que[i - 1] == 227) && zp != 15)
		{
			printf("(�������ɽ��)");
			zp = 15;
		}
		else if ((que[i] == 205 || que[i] == 228 || que[i] == 192 || que[i] == 193) && (que[i - 1] == 205 || que[i - 1] == 228 || que[i - 1] == 192 || que[i - 1] == 193) && zp != 16)

		{
			printf("(�����������)");
			zp = 16;
		}
		if (que[i] == 1)
			printf("ƻ��԰->");
		if (que[i] == 2)
			printf("�ų�->");
		if (que[i] == 3)
			printf("�˽�����԰->");
		if (que[i] == 4)
			printf("�˱�ɽ->");
		if (que[i] == 5)
			printf("��Ȫ·->");
		if (que[i] == 6)
			printf("�����->");
		if (que[i] == 7)
			printf("����·->");
		if (que[i] == 8)
			printf("ľ��·->");
		if (que[i] == 9)
			printf("������·->");
		if (que[i] == 10)
			printf("�찲����->");
		if (que[i] == 11)
			printf("�찲�Ŷ�->");
		if (que[i] == 12)
			printf("������->");
		if (que[i] == 13)
			printf("������->");
		if (que[i] == 14)
			printf("����·->");
		if (que[i] == 15)
			printf("�Ļ�->");
		if (que[i] == 16)
			printf("ǰ��->");
		if (que[i] == 17)
			printf("����վ->");
		if (que[i] == 18)
			printf("����ʮ��->");
		if (que[i] == 19)
			printf("������->");
		if (que[i] == 20)
			printf("��ˮ̶->");
		if (que[i] == 21)
			printf("������->");
		if (que[i] == 22)
			printf("������->");
		if (que[i] == 23)
			printf("��ƽ��->");
		if (que[i] == 24)
			printf("�����ű�->");
		if (que[i] == 25)
			printf("������->");
		if (que[i] == 26)
			printf("��Է->");
		if (que[i] == 27)
			printf("Բ��԰->");
		if (que[i] == 28)
			printf("������ѧ����->");
		if (que[i] == 29)
			printf("�йش�->");
		if (que[i] == 30)
			printf("�����ѧ->");
		if (que[i] == 31)
			printf("κ����->");
		if (que[i] == 32)
			printf("����԰->");
		if (que[i] == 33)
			printf("�½ֿ�->");
		if (que[i] == 34)
			printf("����->");
		if (que[i] == 35)
			printf("�龳��ͬ->");
		if (que[i] == 36)
			printf("���п�->");
		if (que[i] == 37)
			printf("��Ȼͤ->");
		if (que[i] == 38)
			printf("������վ->");
		if (que[i] == 39)
			printf("���ֱ�->");
		if (que[i] == 40)
			printf("��������->");
		if (que[i] == 41)
			printf("�¹�->");
		if (que[i] == 42)
			printf("������->");
		if (que[i] == 43)
			printf("���׵걱->");
		if (que[i] == 44)
			printf("���׵���->");
		if (que[i] == 45)
			printf("��԰->");
		if (que[i] == 46)
			printf("��Դ·->");
		if (que[i] == 47)
			printf("�ƴ������->");
		if (que[i] == 48)
			printf("�ƴ��վ->");
		if (que[i] == 49)
			printf("���ׯ->");
		if (que[i] == 50)
			printf("����ҽҩ����->");
		if (que[i] == 51)
			printf("�칬Ժ->");
		if (que[i] == 52)
			printf("��ͨԷ��->");
		if (que[i] == 53)
			printf("��ͨԷ->");
		if (que[i] == 54)
			printf("��ͨԷ��->");
		if (que[i] == 55)
			printf("��ˮ����->");
		if (que[i] == 56)
			printf("��Է·��->");
		if (que[i] == 57)
			printf("����·��->");
		if (que[i] == 58)
			printf("���±��ֱ���->");
		if (que[i] == 59)
			printf("��ƽ����->");
		if (que[i] == 62)
			printf("������·->");
		if (que[i] == 63)
			printf("���п�->");
		if (que[i] == 64)
			printf("������->");
		if (que[i] == 65)
			printf("��̳����->");
		if (que[i] == 66)
			printf("�ѻ���->");
		if (que[i] == 67)
			printf("����Ҥ->");
		if (que[i] == 68)
			printf("�������·->");
		if (que[i] == 69)
			printf("��԰��->");
		if (que[i] == 70)
			printf("����ׯ��->");
		if (que[i] == 71)
			printf("������->");
		if (que[i] == 72)
			printf("������->");
		if (que[i] == 73)
			printf("��̨·->");
		if (que[i] == 74)
			printf("ʮ�ﱤ->");
		if (que[i] == 75)
			printf("����·->");
		if (que[i] == 76)
			printf("������->");
		if (que[i] == 77)
			printf("����->");
		if (que[i] == 78)
			printf("��Ӫ->");
		if (que[i] == 79)
			printf("�ݷ�->");
		if (que[i] == 80)
			printf("��֪·->");
		if (que[i] == 81)
			printf("ƽ����->");
		if (que[i] == 82)
			printf("�����۶����->");
		if (que[i] == 83)
			printf("����->");
		if (que[i] == 84)
			printf("��С��->");
		if (que[i] == 85)
			printf("��̩ׯ->");
		if (que[i] == 86)
			printf("�ִ���->");
		if (que[i] == 87)
			printf("ɭ�ֹ�԰����->");
		if (que[i] == 88)
			printf("����ƥ�˹�԰->");
		if (que[i] == 89)
			printf("��������->");
		if (que[i] == 90)
			printf("������->");
		if (que[i] == 91)
			printf("ʲɲ��->");
		if (que[i] == 92)
			printf("�׶���->");
		if (que[i] == 93)
			printf("������վ->");
		if (que[i] == 94)
			printf("�����Ŷ�->");
		if (que[i] == 95)
			printf("��̨�����->");
		if (que[i] == 96)
			printf("��̨��·->");
		if (que[i] == 97)
			printf("����·->");
		if (que[i] == 98)
			printf("��̨�Ƽ�԰->");
		if (que[i] == 99)
			printf("����->");
		if (que[i] == 100)
			printf("��̨վ->");
		if (que[i] == 101)
			printf("�׾�ó->");
		if (que[i] == 102)
			printf("�ͼ���->");
		if (que[i] == 103)
			printf("����->");
		if (que[i] == 104)
			printf("���Ŷ�->");
		if (que[i] == 105)
			printf("�����->");
		if (que[i] == 106)
			printf("ʯ��ׯ->");
		if (que[i] == 107)
			printf("������->");
		if (que[i] == 108)
			printf("������->");
		if (que[i] == 109)
			printf("ʮ���->");
		if (que[i] == 110)
			printf("�˼�԰->");
		if (que[i] == 111)
			printf("����->");
		if (que[i] == 112)
			printf("˫��->");
		if (que[i] == 113)
			printf("��̨Ϧ��->");
		if (que[i] == 114)
			printf("�Ž��->");
		if (que[i] == 115)
			printf("ũҵչ����->");
		if (que[i] == 116)
			printf("������->");
		if (que[i] == 117)
			printf("̫����->");
		if (que[i] == 118)
			printf("������->");
		if (que[i] == 119)
			printf("������->");
		if (que[i] == 120)
			printf("ĵ��԰->");
		if (que[i] == 121)
			printf("������->");
		if (que[i] == 122)
			printf("֪����->");
		if (que[i] == 123)
			printf("���ݽ�->");
		if (que[i] == 124)
			printf("�͹�->");
		if (que[i] == 125)
			printf("����Ӫ->");
		if (que[i] == 126)
			printf("������->");
		if (que[i] == 127)
			printf("������->");
		if (que[i] == 128)
			printf("������̨->");
		if (que[i] == 129)
			printf("������->");
		if (que[i] == 130)
			printf("������->");
		if (que[i] == 131)
			printf("������->");
		if (que[i] == 132)
			printf("�ϵ�->");
		if (que[i] == 133)
			printf("����->");
		if (que[i] == 134)
			printf("������->");
		if (que[i] == 135)
			printf("��Է->");
		if (que[i] == 136)
			printf("������->");
		if (que[i] == 137)
			printf("����->");
		if (que[i] == 138)
			printf("�Ź�ׯ->");
		if (que[i] == 139)
			printf("԰��԰->");
		if (que[i] == 140)
			printf("����Ҥ->");
		if (que[i] == 141)
			printf("��ׯ��->");
		if (que[i] == 142)
			printf("��->");
		if (que[i] == 143)
			printf("ٺ��->");
		if (que[i] == 144)
			printf("˳��->");
		if (que[i] == 145)
			printf("ʯ��->");
		if (que[i] == 146)
			printf("�Ϸ���->");
		if (que[i] == 147)
			printf("��ɳ��->");
		if (que[i] == 148)
			printf("���濲->");
		if (que[i] == 149)
			printf("��չ->");
		if (que[i] == 150)
			printf("���->");
		if (que[i] == 151)
			printf("��ȪӪ->");
		if (que[i] == 152)
			printf("�޸�ׯ->");
		if (que[i] == 153)
			printf("����->");
		if (que[i] == 154)
			printf("�߱���->");
		if (que[i] == 155)
			printf("��ý��ѧ->");
		if (que[i] == 156)
			printf("˫��->");
		if (que[i] == 157)
			printf("��ׯ->");
		if (que[i] == 158)
			printf("������->");
		if (que[i] == 159)
			printf("ͨ�ݱ�Է->");
		if (que[i] == 160)
			printf("��԰->");
		if (que[i] == 161)
			printf("�ſ���->");
		if (que[i] == 162)
			printf("��԰->");
		if (que[i] == 163)
			printf("�ٺ���->");
		if (que[i] == 164)
			printf("����->");
		if (que[i] == 165)
			printf("����->");
		if (que[i] == 166)
			printf("ɳ�Ӹ߽�԰->");
		if (que[i] == 167)
			printf("ɳ��->");
		if (que[i] == 168)
			printf("������->");
		if (que[i] == 169)
			printf("������ѧ԰->");
		if (que[i] == 170)
			printf("Ф��->");
		if (que[i] == 171)
			printf("С����->");
		if (que[i] == 172)
			printf("�ɹ�->");
		if (que[i] == 173)
			printf("��ׯ��->");
		if (que[i] == 174)
			printf("��ׯ�Ļ�԰->");
		if (que[i] == 175)
			printf("��Դ��->");
		if (que[i] == 176)
			printf("�پ�����->");
		if (que[i] == 177)
			printf("�ٲ�����->");
		if (que[i] == 178)
			printf("ͬ����·->");
		if (que[i] == 179)
			printf("����·->");
		if (que[i] == 180)
			printf("������->");
		if (que[i] == 181)
			printf("����->");
		if (que[i] == 182)
			printf("��ׯ->");
		if (que[i] == 183)
			printf("�����Ϲ�->");
		if (que[i] == 184)
			printf("�����ѧ����->");
		if (que[i] == 185)
			printf("�����ѧ��->");
		if (que[i] == 186)
			printf("�����ѧ�Ǳ�->");
		if (que[i] == 187)
			printf("������->");
		if (que[i] == 188)
			printf("��ʷ�->");
		if (que[i] == 189)
			printf("����->");
		if (que[i] == 190)
			printf("����->");
		if (que[i] == 191)
			printf("����̨->");
		if (que[i] == 192)
			printf("T2��վ¥->");
		if (que[i] == 193)
			printf("T3��վ¥->");
		if (que[i] == 194)
			printf("������->");
		if (que[i] == 195)
			printf("����->");
		if (que[i] == 196)
			printf("������->");
		if (que[i] == 197)
			printf("���²����->");
		if (que[i] == 198)
			printf("������->");
		if (que[i] == 199)
			printf("����->");
		if (que[i] == 200)
			printf("������->");
		if (que[i] == 201)
			printf("��ó->");
		if (que[i] == 202)
			printf("�Ļݶ�->");
		if (que[i] == 203)
			printf("������->");
		if (que[i] == 204)
			printf("������->");
		if (que[i] == 205)
			printf("��ֱ��->");
		if (que[i] == 206)
			printf("Ӻ�͹�->");
		if (que[i] == 207)
			printf("��¥���->");
		if (que[i] == 208)
			printf("��ֱ��->");
		if (que[i] == 209)
			printf("����ׯ->");
		if (que[i] == 210)
			printf("�����ׯ->");
		if (que[i] == 211)
			printf("����ͼ���->");
		if (que[i] == 212)
			printf("ƽ����->");
		if (que[i] == 213)
			printf("������->");
		if (que[i] == 214)
			printf("��ˮ��->");
		if (que[i] == 215)
			printf("���������Ͽ�->");
		if (que[i] == 216)
			printf("����->");
		if (que[i] == 217)
			printf("�μ�ׯ->");
		if (que[i] == 218)
			printf("������->");
		if (que[i] == 219)
			printf("��ʯ����->");
		if (que[i] == 220)
			printf("�������->");
		if (que[i] == 221)
			printf("����¥->");
		if (que[i] == 222)
			printf("����ׯ->");
		if (que[i] == 223)
			printf("��Ӫ->");
		if (que[i] == 224)
			printf("������->");
		if (que[i] == 225)
			printf("������->");
		if (que[i] == 226)
			printf("����ׯ->");
		if (que[i] == 227)
			printf("����ׯ->");
		if (que[i] == 228)
			printf("��Ԫ��->");
		if (que[i] == 229)
			printf("��ҩ��->");
		if (que[i] == 230)
			printf("֪��·->");
		if (que[i] == 231)
			printf("����->");
		if (que[i] == 232)
			printf("������->");
		if (que[i] == 233)
			printf("������->");
	


	}


	if (que[1] == 1)
		printf("ƻ��԰");
	if (que[1] == 2)
		printf("�ų�");
	if (que[1] == 3)
		printf("�˽�����԰");
	if (que[1] == 4)
		printf("�˱�ɽ");
	if (que[1] == 5)
		printf("��Ȫ·");
	if (que[1] == 6)
		printf("�����");
	if (que[1] == 7)
		printf("����·");
	if (que[1] == 8)
		printf("ľ��·");
	if (que[1] == 9)
		printf("������·");
	if (que[1] == 10)
		printf("�찲����");
	if (que[1] == 11)
		printf("�찲�Ŷ�");
	if (que[1] == 12)
		printf("������");
	if (que[1] == 13)
		printf("������");
	if (que[1] == 14)
		printf("����·");
	if (que[1] == 15)
		printf("->�Ļ�");
	if (que[1] == 16)
		printf("ǰ��");
	if (que[1] == 17)
		printf("����վ");
	if (que[1] == 18)
		printf("����ʮ��");
	if (que[1] == 19)
		printf("������");
	if (que[1] == 20)
		printf("��ˮ̶");
	if (que[1] == 21)
		printf("������");
	if (que[1] == 22)
		printf("������");
	if (que[1] == 23)
		printf("��ƽ��");
	if (que[1] == 24)
		printf("�����ű�");
	if (que[1] == 25)
		printf("������");
	if (que[1] == 26)
		printf("��Է");
	if (que[1] == 27)
		printf("Բ��԰");
	if (que[1] == 28)
		printf("������ѧ����");
	if (que[1] == 29)
		printf("�йش�");
	if (que[1] == 30)
		printf("�����ѧ");
	if (que[1] == 31)
		printf("κ����");
	if (que[1] == 32)
		printf("����԰");
	if (que[1] == 33)
		printf("�½ֿ�");
	if (que[1] == 34)
		printf("����");
	if (que[1] == 35)
		printf("�龳��ͬ");
	if (que[1] == 36)
		printf("���п�");
	if (que[1] == 37)
		printf("��Ȼͤ");
	if (que[1] == 38)
		printf("������վ");
	if (que[1] == 39)
		printf("���ֱ�");
	if (que[1] == 40)
		printf("��������");
	if (que[1] == 41)
		printf("�¹�");
	if (que[1] == 42)
		printf("������");
	if (que[1] == 43)
		printf("���׵걱");
	if (que[1] == 44)
		printf("���׵���");
	if (que[1] == 45)
		printf("��԰");
	if (que[1] == 46)
		printf("��Դ·");
	if (que[1] == 47)
		printf("�ƴ������");
	if (que[1] == 48)
		printf("�ƴ��վ");
	if (que[1] == 49)
		printf("���ׯ");
	if (que[1] == 50)
		printf("����ҽҩ����");
	if (que[1] == 51)
		printf("�칬Ժ");
	if (que[1] == 52)
		printf("��ͨԷ��");
	if (que[1] == 53)
		printf("��ͨԷ");
	if (que[1] == 54)
		printf("��ͨԷ��");
	if (que[1] == 55)
		printf("��ˮ����");
	if (que[1] == 56)
		printf("��Է·��");
	if (que[1] == 57)
		printf("����·��");
	if (que[1] == 58)
		printf("���±��ֱ���");
	if (que[1] == 59)
		printf("��ƽ����");
	if (que[1] == 62)
		printf("������·");
	if (que[1] == 63)
		printf("���п�");
	if (que[1] == 64)
		printf("������");
	if (que[1] == 65)
		printf("��̳����");
	if (que[1] == 66)
		printf("�ѻ���");
	if (que[1] == 67)
		printf("����Ҥ");
	if (que[1] == 68)
		printf("�������·");
	if (que[1] == 69)
		printf("��԰��");
	if (que[1] == 70)
		printf("����ׯ��");
	if (que[1] == 71)
		printf("������");
	if (que[1] == 72)
		printf("������");
	if (que[1] == 73)
		printf("��̨·");
	if (que[1] == 74)
		printf("ʮ�ﱤ");
	if (que[1] == 75)
		printf("����·");
	if (que[1] == 76)
		printf("������");
	if (que[1] == 77)
		printf("����");
	if (que[1] == 78)
		printf("��Ӫ");
	if (que[1] == 79)
		printf("�ݷ�");
	if (que[1] == 80)
		printf("��֪·");
	if (que[1] == 81)
		printf("ƽ����");
	if (que[1] == 82)
		printf("�����۶����");
	if (que[1] == 83)
		printf("����");
	if (que[1] == 84)
		printf("��С��");
	if (que[1] == 85)
		printf("��̩ׯ");
	if (que[1] == 86)
		printf("�ִ���");
	if (que[1] == 87)
		printf("ɭ�ֹ�԰����");
	if (que[1] == 88)
		printf("����ƥ�˹�԰");
	if (que[1] == 89)
		printf("��������");
	if (que[1] == 90)
		printf("������");
	if (que[1] == 91)
		printf("ʲɲ��");
	if (que[1] == 92)
		printf("�׶���");
	if (que[1] == 93)
		printf("������վ");
	if (que[1] == 94)
		printf("�����Ŷ�");
	if (que[1] == 95)
		printf("��̨�����");
	if (que[1] == 96)
		printf("��̨��·");
	if (que[1] == 97)
		printf("����·");
	if (que[1] == 98)
		printf("��̨�Ƽ�԰");
	if (que[1] == 99)
		printf("����");
	if (que[1] == 100)
		printf("��̨վ");
	if (que[1] == 101)
		printf("�׾�ó");
	if (que[1] == 102)
		printf("�ͼ���");
	if (que[1] == 103)
		printf("����");
	if (que[1] == 104)
		printf("���Ŷ�");
	if (que[1] == 105)
		printf("�����");
	if (que[1] == 106)
		printf("ʯ��ׯ");
	if (que[1] == 107)
		printf("������");
	if (que[1] == 108)
		printf("������");
	if (que[1] == 109)
		printf("ʮ���");
	if (que[1] == 110)
		printf("�˼�԰");
	if (que[1] == 111)
		printf("����");
	if (que[1] == 112)
		printf("˫��");
	if (que[1] == 113)
		printf("��̨Ϧ��");
	if (que[1] == 114)
		printf("�Ž��");
	if (que[1] == 115)
		printf("ũҵչ����");
	if (que[1] == 116)
		printf("������");
	if (que[1] == 117)
		printf("̫����");
	if (que[1] == 118)
		printf("������");
	if (que[1] == 119)
		printf("������");
	if (que[1] == 120)
		printf("ĵ��԰");
	if (que[1] == 121)
		printf("������");
	if (que[1] == 122)
		printf("֪����");
	if (que[1] == 123)
		printf("���ݽ�");
	if (que[1] == 124)
		printf("�͹�");
	if (que[1] == 125)
		printf("����Ӫ");
	if (que[1] == 126)
		printf("������");
	if (que[1] == 127)
		printf("������");
	if (que[1] == 128)
		printf("������̨");
	if (que[1] == 129)
		printf("������");
	if (que[1] == 130)
		printf("������");
	if (que[1] == 131)
		printf("������");
	if (que[1] == 132)
		printf("�ϵ�");
	if (que[1] == 133)
		printf("����");
	if (que[1] == 134)
		printf("������");
	if (que[1] == 135)
		printf("��Է");
	if (que[1] == 136)
		printf("������");
	if (que[1] == 137)
		printf("����");
	if (que[1] == 138)
		printf("�Ź�ׯ");
	if (que[1] == 139)
		printf("԰��԰");
	if (que[1] == 140)
		printf("����Ҥ");
	if (que[1] == 141)
		printf("��ׯ��");
	if (que[1] == 142)
		printf("��");
	if (que[1] == 143)
		printf("ٺ��");
	if (que[1] == 144)
		printf("˳��");
	if (que[1] == 145)
		printf("ʯ��");
	if (que[1] == 146)
		printf("�Ϸ���");
	if (que[1] == 147)
		printf("��ɳ��");
	if (que[1] == 148)
		printf("���濲");
	if (que[1] == 149)
		printf("��չ");
	if (que[1] == 150)
		printf("���");
	if (que[1] == 151)
		printf("��ȪӪ");
	if (que[1] == 152)
		printf("�޸�ׯ");
	if (que[1] == 153)
		printf("����");
	if (que[1] == 154)
		printf("�߱���");
	if (que[1] == 155)
		printf("��ý��ѧ");
	if (que[1] == 156)
		printf("˫��");
	if (que[1] == 157)
		printf("��ׯ");
	if (que[1] == 158)
		printf("������");
	if (que[1] == 159)
		printf("ͨ�ݱ�Է");
	if (que[1] == 160)
		printf("��԰");
	if (que[1] == 161)
		printf("�ſ���");
	if (que[1] == 162)
		printf("��԰");
	if (que[1] == 163)
		printf("�ٺ���");
	if (que[1] == 164)
		printf("����");
	if (que[1] == 165)
		printf("����");
	if (que[1] == 166)
		printf("ɳ�Ӹ߽�԰");
	if (que[1] == 167)
		printf("ɳ��");
	if (que[1] == 168)
		printf("������");
	if (que[1] == 169)
		printf("������ѧ԰");
	if (que[1] == 170)
		printf("Ф��");
	if (que[1] == 171)
		printf("С����");
	if (que[1] == 172)
		printf("�ɹ�");
	if (que[1] == 173)
		printf("��ׯ��");
	if (que[1] == 174)
		printf("��ׯ�Ļ�԰");
	if (que[1] == 175)
		printf("��Դ��");
	if (que[1] == 176)
		printf("�پ�����");
	if (que[1] == 177)
		printf("�ٲ�����");
	if (que[1] == 178)
		printf("ͬ����·");
	if (que[1] == 179)
		printf("����·");
	if (que[1] == 180)
		printf("������");
	if (que[1] == 181)
		printf("����");
	if (que[1] == 182)
		printf("��ׯ");
	if (que[1] == 183)
		printf("�����Ϲ�");
	if (que[1] == 184)
		printf("�����ѧ����");
	if (que[1] == 185)
		printf("�����ѧ��");
	if (que[1] == 186)
		printf("�����ѧ�Ǳ�");
	if (que[1] == 187)
		printf("������");
	if (que[1] == 188)
		printf("��ʷ�");
	if (que[1] == 189)
		printf("����");
	if (que[1] == 190)
		printf("����");
	if (que[1] == 191)
		printf("����̨");
	if (que[1] == 192)
		printf("T2��վ¥");
	if (que[1] == 193)
		printf("T3��վ¥");
	if (que[1] == 194)
		printf("������");
	if (que[1] == 195)
		printf("����");
	if (que[1] == 196)
		printf("������");
	if (que[1] == 197)
		printf("���²����");
	if (que[1] == 198)
		printf("������");
	if (que[1] == 199)
		printf("����");
	if (que[1] == 200)
		printf("������");
	if (que[1] == 201)
		printf("��ó");
	if (que[1] == 202)
		printf("�Ļݶ�");
	if (que[1] == 203)
		printf("������");
	if (que[1] == 204)
		printf("������");
	if (que[1] == 205)
		printf("��ֱ��");
	if (que[1] == 206)
		printf("Ӻ�͹�");
	if (que[1] == 207)
		printf("��¥���");
	if (que[1] == 208)
		printf("��ֱ��");
	if (que[1] == 209)
		printf("����ׯ");
	if (que[1] == 210)
		printf("�����ׯ");
	if (que[1] == 211)
		printf("����ͼ���");
	if (que[1] == 212)
		printf("ƽ����");
	if (que[1] == 213)
		printf("������");
	if (que[1] == 214)
		printf("��ˮ��");
	if (que[1] == 215)
		printf("���������Ͽ�");
	if (que[1] == 216)
		printf("����");
	if (que[1] == 217)
		printf("�μ�ׯ");
	if (que[1] == 218)
		printf("������");
	if (que[1] == 219)
		printf("��ʯ����");
	if (que[1] == 220)
		printf("�������");
	if (que[1] == 221)
		printf("����¥");
	if (que[1] == 222)
		printf("����ׯ");
	if (que[1] == 223)
		printf("��Ӫ");
	if (que[1] == 224)
		printf("������");
	if (que[1] == 225)
		printf("������");
	if (que[1] == 226)
		printf("����ׯ");
	if (que[1] == 227)
		printf("����ׯ");
	if (que[1] == 228)
		printf("��Ԫ��");
	if (que[1] == 229)
		printf("��ҩ��");
	if (que[1] == 230)
		printf("֪��·");
	if (que[1] == 231)
		printf("����");
	if (que[1] == 232)
		printf("������");
	if (que[1] == 233)
		printf("������");
	

	//**************************************************************************************************************************************************
}

int main()
{
	printf("��ӭʹ�ñ�������վ\n����Ϊ���ṩ���·����ѯ\n����ʱ��   6/16/2014 (by cheng)\n");
	int dist[10000];     // ��ʾ��ǰ�㵽Դ������·������
	int prev[10000];     // ��¼��ǰ���ǰһ�����
	int c[300][300];   // ��¼ͼ�������·������
	int n;             // ͼ�Ľ������·����

	// ��������
	n = 233;

	int p, q;          // ����p, q���㼰��·������

	// ��ʼ��c[][]Ϊmaxint
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
		c[i][j] = maxint;


	//*************************************************************************************************************************************************

	//·�������룡������

	//һ����


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 1, q = 2;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 2, q = 3;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 3, q = 4;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 4, q = 5;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 5, q = 6;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 6, q = 7;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 7, q = 196;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 196, q = 197;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 197, q = 8;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 8, q = 9;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 9, q = 198;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 198, q = 195;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 195, q = 10;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 10, q = 11;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 11, q = 12;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 12, q = 199;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 199, q = 200;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 200, q = 13;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 13, q = 201;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 201, q = 14;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 14, q = 15;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 15, q = 202;
		c[p][q] = 1;
		c[q][p] = 1;
	}



	//2����



	//��ʾѹ��ɽ��ķָ���   
	{
		p = 16, q = 203;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 203, q = 17;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 17, q = 200;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 200, q = 204;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 204, q = 18;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 18, q = 205;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 205, q = 206;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 206, q = 19;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 19, q = 207;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 207, q = 20;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 20, q = 208;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 208, q = 209;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 209, q = 21;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 21, q = 198;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 198, q = 22;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 22, q = 194;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 194, q = 23;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 23, q = 16;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//4�Ŵ�����


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 24, q = 25;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 25, q = 26;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 26, q = 27;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 27, q = 28;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 28, q = 29;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 29, q = 210;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 210, q = 30;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 30, q = 31;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 31, q = 211;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 211, q = 32;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 32, q = 208;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 208, q = 33;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 33, q = 212;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 212, q = 34;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 34, q = 35;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 35, q = 195;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 195, q = 194;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 194, q = 36;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 36, q = 37;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 37, q = 38;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 38, q = 39;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 39, q = 213;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 213, q = 40;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 40, q = 41;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 41, q = 42;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 42, q = 43;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 43, q = 44;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 44, q = 45;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 45, q = 46;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 46, q = 47;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 47, q = 48;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 48, q = 49;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 49, q = 50;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 50, q = 51;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//5����


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 52, q = 53;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 53, q = 54;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 54, q = 214;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 214, q = 55;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 55, q = 56;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 56, q = 57;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 57, q = 58;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 58, q = 215;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 215, q = 59;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 59, q = 60;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 60, q = 206;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 206, q = 61;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 61, q = 62;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 62, q = 216;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 216, q = 63;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 63, q = 199;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 199, q = 203;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 203, q = 64;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 64, q = 65;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 65, q = 66;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 66, q = 67;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 67, q = 217;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//6����



	//��ʾѹ��ɽ��ķָ���   
	{
		p = 68, q = 218;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 218, q = 69;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 69, q = 219;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 219, q = 70;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 70, q = 209;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 209, q = 212;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 212, q = 71;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 71, q = 220;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 220, q = 216;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 216, q = 204;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 204, q = 72;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 72, q = 221;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 221, q = 73;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 73, q = 74;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 74, q = 75;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 75, q = 76;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 76, q = 77;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 77, q = 78;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 78, q = 79;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//8����

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 222, q = 80;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 80, q = 81;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 81, q = 82;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 82, q = 223;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 223, q = 83;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 83, q = 84;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 84, q = 85;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 85, q = 86;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 86, q = 87;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 87, q = 88;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 88, q = 89;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 89, q = 224;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 224, q = 90;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 90, q = 207;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 207, q = 91;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 91, q = 220;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//9����



	//��ʾѹ��ɽ��ķָ���   
	{
		p = 211, q = 219;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 219, q = 92;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 92, q = 197;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 197, q = 93;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 93, q = 94;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 94, q = 225;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 225, q = 226;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 226, q = 95;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 95, q = 96;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 96, q = 97;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 97, q = 98;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 98, q = 227;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//����ɽ���10���� ����������������


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 99, q = 100;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 100, q = 101;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 101, q = 102;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 102, q = 103;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 103, q = 213;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 213, q = 104;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 104, q = 105;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 105, q = 106;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 106, q = 217;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 217, q = 107;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 107, q = 108;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 108, q = 109;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 109, q = 110;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 110, q = 111;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 111, q = 112;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 112, q = 201;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 201, q = 113;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 113, q = 221;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 221, q = 114;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 114, q = 115;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 115, q = 116;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 116, q = 228;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 228, q = 117;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 117, q = 229;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 229, q = 215;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 215, q = 118;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 118, q = 224;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 224, q = 119;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 119, q = 120;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 120, q = 121;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 121, q = 230;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 230, q = 122;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 122, q = 210;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 210, q = 123;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 123, q = 124;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 124, q = 125;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 125, q = 126;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 126, q = 127;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 127, q = 218;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 218, q = 128;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 128, q = 196;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 196, q = 129;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 129, q = 225;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 225, q = 231;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 231, q = 99;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//13����



	//��ʾѹ��ɽ��ķָ���   
	{
		p = 208, q = 130;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 130, q = 230;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 230, q = 131;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 131, q = 132;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 132, q = 232;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 232, q = 133;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 133, q = 134;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 134, q = 223;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 223, q = 214;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 214, q = 135;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 135, q = 233;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 233, q = 229;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 229, q = 136;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 136, q = 137;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 137, q = 205;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//14����

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 138, q = 139;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 139, q = 140;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 140, q = 141;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 141, q = 142;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 142, q = 226;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 226, q = 231;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//15����


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 143, q = 144;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 144, q = 145;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 145, q = 146;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 146, q = 147;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 147, q = 148;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 148, q = 149;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 149, q = 150;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 150, q = 151;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 151, q = 152;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 152, q = 153;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 153, q = 233;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ͨ��



	//��ʾѹ��ɽ��ķָ���   
	{
		p = 202, q = 154;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 154, q = 155;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 155, q = 156;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 156, q = 157;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 157, q = 158;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 158, q = 159;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 159, q = 160;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 160, q = 161;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 161, q = 162;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 162, q = 163;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 163, q = 164;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ƽ��


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 165, q = 166;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 166, q = 167;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 167, q = 168;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 168, q = 222;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 222, q = 169;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 169, q = 232;
		c[p][q] = 1;
		c[q][p] = 1;
	}



	//��ׯ��



	//��ʾѹ��ɽ��ķָ���   
	{
		p = 217, q = 170;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 170, q = 171;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 171, q = 172;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 172, q = 173;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 173, q = 174;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 174, q = 175;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 175, q = 176;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 176, q = 177;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 177, q = 178;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 178, q = 179;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 179, q = 180;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 180, q = 181;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ɽ��


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 182, q = 183;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 183, q = 184;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 184, q = 185;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 185, q = 186;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 186, q = 187;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 187, q = 188;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 188, q = 189;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 189, q = 190;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 190, q = 191;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 191, q = 227;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//������


	//��ʾѹ��ɽ��ķָ���   
	{
		p = 205, q = 228;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 228, q = 192;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//��ʾѹ��ɽ��ķָ���   
	{
		p = 228, q = 193;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//��ʾѹ��ɽ��ķָ���   
	{
		p = 192, q = 193;
		c[p][q] = 1;
		c[q][p] = 1;
	}



	//************************************************************************************************************************************************************************************


	//��ʼ��ַ���յ������
	int a1, a2;
	char z[20], x[20];

	int asd = 1;

	while (asd)
	{

		printf("���������\n");
		gets_s(z, 20);



		//******************************************************************************************************************************************************************************************


		//���
		while (1)
		{

			//1���ߵ����룡��������������
			if (0 == (strcmp(z, "ƻ��԰")))
			{
				a1 = 1;
				break;
			}

			if (0 == (strcmp(z, "�ų�")))
			{
				a1 = 2;
				break;
			}

			if (0 == (strcmp(z, "�˽�����԰")))
			{
				a1 = 3;
				break;
			}


			if (0 == (strcmp(z, "�˱�ɽ")))
			{
				a1 = 4;
				break;
			}
			if (0 == (strcmp(z, "��Ȫ·")))
			{
				a1 = 5;
				break;
			}

			if (0 == (strcmp(z, "�����")))
			{
				a1 = 6;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a1 = 7;
				break;
			}


			if (0 == (strcmp(z, "ľ�ص�")))
			{
				a1 = 8;
				break;
			}

			if (0 == (strcmp(z, "����ʿ·")))
			{
				a1 = 9;
				break;
			}

			if (0 == (strcmp(z, "�찲����")))
			{
				a1 = 10;
				break;
			}

			if (0 == (strcmp(z, "�찲�Ŷ�")))
			{
				a1 = 11;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 12;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 13;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a1 = 14;
				break;
			}

			if (0 == (strcmp(z, "�Ļ�")))
			{
				a1 = 15;
				break;
			}


			//2����


			if (0 == (strcmp(z, "ǰ��")))
			{
				a1 = 16;
				break;
			}

			if (0 == (strcmp(z, "����վ")))
			{
				a1 = 17;
				break;
			}
			if (0 == (strcmp(z, "����ʮ��")))
			{
				a1 = 18;
				break;
			}


			if (0 == (strcmp(z, "������")))
			{
				a1 = 19;
				break;
			}

			if (0 == (strcmp(z, "��ˮ̶")))
			{
				a1 = 20;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 21;
				break;
			}


			if (0 == (strcmp(z, "������")))
			{
				a1 = 22;
				break;
			}

			if (0 == (strcmp(z, "��ƽ��")))
			{
				a1 = 23;
				break;
			}



			//4�Ŵ�����





			if (0 == (strcmp(z, "�����ű�")))
			{
				a1 = 24;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 25;
				break;
			}
			if (0 == (strcmp(z, "��Է")))
			{
				a1 = 26;
				break;
			}

			if (0 == (strcmp(z, "Բ��԰")))
			{
				a1 = 27;
				break;
			}
			if (0 == (strcmp(z, "������ѧ����")))
			{
				a1 = 28;
				break;
			}

			if (0 == (strcmp(z, "�йش�")))
			{
				a1 = 29;
				break;
			}

			if (0 == (strcmp(z, "�����ѧ")))
			{
				a1 = 30;
				break;
			}

			if (0 == (strcmp(z, "κ����")))
			{
				a1 = 31;
				break;
			}

			if (0 == (strcmp(z, "����԰")))
			{
				a1 = 32;
				break;
			}

			if (0 == (strcmp(z, "�½ֿ�")))
			{
				a1 = 33;
				break;
			}


			if (0 == (strcmp(z, "����")))
			{
				a1 = 34;
				break;
			}

			if (0 == (strcmp(z, "�龳��ͬ")))
			{
				a1 = 35;
				break;
			}

			if (0 == (strcmp(z, "���п�")))
			{
				a1 = 36;
				break;
			}

			if (0 == (strcmp(z, "��Ȼͤ")))
			{
				a1 = 37;
				break;
			}


			if (0 == (strcmp(z, "������վ")))
			{
				a1 = 38;
				break;
			}

			if (0 == (strcmp(z, "���ֱ�")))
			{
				a1 = 39;
				break;
			}

			if (0 == (strcmp(z, "��������")))
			{
				a1 = 40;
				break;
			}

			if (0 == (strcmp(z, "�¹�")))
			{
				a1 = 41;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 42;
				break;
			}

			if (0 == (strcmp(z, "���׵걱")))
			{
				a1 = 43;
				break;
			}

			if (0 == (strcmp(z, "���׵���")))
			{
				a1 = 44;
				break;
			}
			if (0 == (strcmp(z, "��԰")))
			{
				a1 = 45;
				break;
			}

			if (0 == (strcmp(z, "��Դ·")))
			{
				a1 = 46;
				break;
			}

			if (0 == (strcmp(z, "�ƴ������")))
			{
				a1 = 47;
				break;
			}

			if (0 == (strcmp(z, "�ƴ��վ")))
			{
				a1 = 48;
				break;
			}

			if (0 == (strcmp(z, "���ׯ")))
			{
				a1 = 49;
				break;
			}

			if (0 == (strcmp(z, "����ҽҩ����")))
			{
				a1 = 50;
				break;
			}

			if (0 == (strcmp(z, "�칬Ժ")))
			{
				a1 = 51;
				break;
			}




			//5����



			if (0 == (strcmp(z, "��ͨԷ��")))
			{
				a1 = 52;
				break;
			}


			if (0 == (strcmp(z, "��ͨԷ")))
			{
				a1 = 53;
				break;
			}
			if (0 == (strcmp(z, "��ͨԷ��")))
			{
				a1 = 54;
				break;
			}

			if (0 == (strcmp(z, "��ˮ����")))
			{
				a1 = 55;
				break;
			}

			if (0 == (strcmp(z, "��Է·��")))
			{
				a1 = 56;
				break;
			}

			if (0 == (strcmp(z, "����·��")))
			{
				a1 = 57;
				break;
			}

			if (0 == (strcmp(z, "�������ֱ���")))
			{
				a1 = 58;
				break;
			}

			if (0 == (strcmp(z, "��ƽ����")))
			{
				a1 = 59;
				break;
			}

			if (0 == (strcmp(z, "��ƽ�ﱱ��")))
			{
				a1 = 60;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 61;
				break;
			}


			if (0 == (strcmp(z, "������·")))
			{
				a1 = 62;
				break;
			}

			if (0 == (strcmp(z, "���п�")))
			{
				a1 = 63;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 64;
				break;
			}

			if (0 == (strcmp(z, "��̳����")))
			{
				a1 = 65;
				break;
			}

			if (0 == (strcmp(z, "�ѻ���")))
			{
				a1 = 66;
				break;
			}
			if (0 == (strcmp(z, "����Ҥ")))
			{
				a1 = 67;
				break;
			}



			//6����




			if (0 == (strcmp(z, "������·��")))
			{
				a1 = 68;
				break;
			}


			if (0 == (strcmp(z, "��԰��")))
			{
				a1 = 69;
				break;
			}

			if (0 == (strcmp(z, "����ׯ��")))
			{
				a1 = 70;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 71;
				break;
			}


			if (0 == (strcmp(z, "������")))
			{
				a1 = 72;
				break;
			}

			if (0 == (strcmp(z, "��̨·")))
			{
				a1 = 73;
				break;
			}


			if (0 == (strcmp(z, "ʮ�ﱤ")))
			{
				a1 = 74;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a1 = 75;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 76;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 77;
				break;
			}

			if (0 == (strcmp(z, "��Ӫ")))
			{
				a1 = 78;
				break;
			}

			if (0 == (strcmp(z, "�ݷ�")))
			{
				a1 = 79;
				break;
			}


			//8����


			if (0 == (strcmp(z, "��֪·")))
			{
				a1 = 80;
				break;
			}

			if (0 == (strcmp(z, "ƽ����")))
			{
				a1 = 81;
				break;
			}

			if (0 == (strcmp(z, "�����۶����")))
			{
				a1 = 82;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 83;
				break;
			}
			if (0 == (strcmp(z, "��С��")))
			{
				a1 = 84;
				break;
			}

			if (0 == (strcmp(z, "��̩ׯ")))
			{
				a1 = 85;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 86;
				break;
			}

			if (0 == (strcmp(z, "ɭ�ֹ�԰����")))
			{
				a1 = 87;
				break;
			}
			if (0 == (strcmp(z, "����ƥ�˹�԰")))
			{
				a1 = 88;
				break;
			}

			if (0 == (strcmp(z, "��������")))
			{
				a1 = 89;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 90;
				break;
			}

			if (0 == (strcmp(z, "ʲɲ��")))
			{
				a1 = 91;
				break;
			}

			//9����


			if (0 == (strcmp(z, "�׶���")))
			{
				a1 = 92;
				break;
			}

			if (0 == (strcmp(z, "������վ")))
			{
				a1 = 93;
				break;
			}

			if (0 == (strcmp(z, "�����Ŷ�")))
			{
				a1 = 94;
				break;
			}
			if (0 == (strcmp(z, "��̨�����")))
			{
				a1 = 95;
				break;
			}

			if (0 == (strcmp(z, "��̨��·")))
			{
				a1 = 96;
				break;
			}
			if (0 == (strcmp(z, "����·")))
			{
				a1 = 97;
				break;
			}
			if (0 == (strcmp(z, "��̨�Ƽ�԰")))
			{
				a1 = 98;
				break;
			}



			//���ߵ�ʮ����


			if (0 == (strcmp(z, "����")))
			{
				a1 = 99;
				break;
			}
			if (0 == (strcmp(z, "��̨վ")))
			{
				a1 = 100;
				break;
			}
			if (0 == (strcmp(z, "�׾�ó")))
			{
				a1 = 101;
				break;
			}
			if (0 == (strcmp(z, "�ͼ���")))
			{
				a1 = 102;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a1 = 103;
				break;
			}
			if (0 == (strcmp(z, "���Ŷ�")))
			{
				a1 = 104;
				break;
			}

			if (0 == (strcmp(z, "�����")))
			{
				a1 = 105;
				break;
			}
			if (0 == (strcmp(z, "ʯ��ׯ")))
			{
				a1 = 106;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 107;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 108;
				break;
			}
			if (0 == (strcmp(z, "ʮ���")))
			{
				a1 = 109;
				break;
			}
			if (0 == (strcmp(z, "�˼�԰")))
			{
				a1 = 110;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a1 = 111;
				break;
			}
			if (0 == (strcmp(z, "˫��")))
			{
				a1 = 112;
				break;
			}
			if (0 == (strcmp(z, "��̨Ϧ��")))
			{
				a1 = 113;
				break;
			}
			if (0 == (strcmp(z, "�Ž��")))
			{
				a1 = 114;
				break;
			}
			if (0 == (strcmp(z, "ũҵչ����")))
			{
				a1 = 115;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 116;
				break;
			}
			if (0 == (strcmp(z, "̫����")))
			{
				a1 = 117;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 118;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 119;
				break;
			}
			if (0 == (strcmp(z, "ĵ��԰")))
			{
				a1 = 120;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 121;
				break;
			}
			if (0 == (strcmp(z, "֪����")))
			{
				a1 = 122;
				break;
			}

			if (0 == (strcmp(z, "���ݽ�")))
			{
				a1 = 123;
				break;
			}

			if (0 == (strcmp(z, "�͹�")))
			{
				a1 = 124;
				break;
			}

			if (0 == (strcmp(z, "����Ӫ")))
			{
				a1 = 125;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 126;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 127;
				break;
			}

			if (0 == (strcmp(z, "��������")))
			{
				a1 = 128;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 129;
				break;
			}


			//13����


			if (0 == (strcmp(z, "������")))
			{
				a1 = 130;
				break;
			}

			if (0 == (strcmp(z, "�����")))
			{
				a1 = 131;
				break;
			}
			if (0 == (strcmp(z, "�ϵ�")))
			{
				a1 = 132;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a1 = 133;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 134;
				break;
			}

			if (0 == (strcmp(z, "��Է")))
			{
				a1 = 135;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 136;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 137;
				break;
			}

			//14����


			if (0 == (strcmp(z, "�Ź�ׯ")))
			{
				a1 = 138;
				break;
			}

			if (0 == (strcmp(z, "԰��԰")))
			{
				a1 = 139;
				break;
			}

			if (0 == (strcmp(z, "����Ҥ")))
			{
				a1 = 140;
				break;
			}

			if (0 == (strcmp(z, "��ׯ��")))
			{
				a1 = 141;
				break;
			}

			if (0 == (strcmp(z, "��")))
			{
				a1 = 142;
				break;
			}


			//15����


			if (0 == (strcmp(z, "ٺ��")))
			{
				a1 = 143;
				break;
			}

			if (0 == (strcmp(z, "˳��")))
			{
				a1 = 144;
				break;
			}

			if (0 == (strcmp(z, "ʯ��")))
			{
				a1 = 145;
				break;
			}

			if (0 == (strcmp(z, "�Ϸ���")))
			{
				a1 = 146;
				break;
			}

			if (0 == (strcmp(z, "��ɳ��")))
			{
				a1 = 147;
				break;
			}
			if (0 == (strcmp(z, "���濲")))
			{
				a1 = 148;
				break;
			}
			if (0 == (strcmp(z, "��չ")))
			{
				a1 = 149;
				break;
			}
			if (0 == (strcmp(z, "���")))
			{
				a1 = 150;
				break;
			}

			if (0 == (strcmp(z, "��ȪӪ")))
			{
				a1 = 151;
				break;
			}

			if (0 == (strcmp(z, "�޸�ׯ")))
			{
				a1 = 152;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 153;
				break;
			}


			//��ͨ��


			if (0 == (strcmp(z, "�߱���")))
			{
				a1 = 154;
				break;
			}

			if (0 == (strcmp(z, "��ý��ѧ")))
			{
				a1 = 155;
				break;
			}

			if (0 == (strcmp(z, "˫��")))
			{
				a1 = 156;
				break;
			}

			if (0 == (strcmp(z, "��ׯ")))
			{
				a1 = 157;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 158;
				break;
			}

			if (0 == (strcmp(z, "ͨ�ݱ�Է")))
			{
				a1 = 159;
				break;
			}

			if (0 == (strcmp(z, "��԰")))
			{
				a1 = 160;
				break;
			}

			if (0 == (strcmp(z, "�ſ���")))
			{
				a1 = 161;
				break;
			}

			if (0 == (strcmp(z, "��԰")))
			{
				a1 = 162;
				break;
			}

			if (0 == (strcmp(z, "�ٺ���")))
			{
				a1 = 163;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 164;
				break;
			}

			//��ƽ��

			if (0 == (strcmp(z, "����")))
			{
				a1 = 165;
				break;
			}

			if (0 == (strcmp(z, "ɳ�Ӹ߽�԰")))
			{
				a1 = 166;
				break;
			}

			if (0 == (strcmp(z, "ɳ��")))
			{
				a1 = 167;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 168;
				break;
			}

			if (0 == (strcmp(z, "������ѧ԰")))
			{
				a1 = 169;
				break;
			}


			//��ׯ��


			if (0 == (strcmp(z, "Ф��")))
			{
				a1 = 170;
				break;
			}
			if (0 == (strcmp(z, "С����")))
			{
				a1 = 171;
				break;
			}
			if (0 == (strcmp(z, "�ɹ�")))
			{
				a1 = 172;
				break;
			}
			if (0 == (strcmp(z, "��ׯ��")))
			{
				a1 = 173;
				break;
			}

			if (0 == (strcmp(z, "��ׯ�Ļ�԰")))
			{
				a1 = 174;
				break;
			}

			if (0 == (strcmp(z, "��Դ��")))
			{
				a1 = 175;
				break;
			}

			if (0 == (strcmp(z, "�پ�����")))
			{
				a1 = 176;
				break;
			}

			if (0 == (strcmp(z, "�ٲ�����")))
			{
				a1 = 177;
				break;
			}

			if (0 == (strcmp(z, "ͬ����·")))
			{
				a1 = 178;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a1 = 179;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 180;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 181;
				break;
			}


			//��ɽ��


			if (0 == (strcmp(z, "��ׯ")))
			{
				a1 = 182;
				break;
			}

			if (0 == (strcmp(z, "�����Ϲ�")))
			{
				a1 = 183;
				break;
			}

			if (0 == (strcmp(z, "�����ѧ����")))
			{
				a1 = 184;
				break;
			}
			if (0 == (strcmp(z, "�����ѧ��")))
			{
				a1 = 185;
				break;
			}
			if (0 == (strcmp(z, "�����ѧ�Ǳ�")))
			{
				a1 = 186;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 187;
				break;
			}

			if (0 == (strcmp(z, "��ʷ�")))
			{
				a1 = 188;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a1 = 189;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 190;
				break;
			}

			if (0 == (strcmp(z, "����̨")))
			{
				a1 = 191;
				break;
			}

			//������


			if (0 == (strcmp(z, "T2��վ¥")))
			{
				a1 = 192;
				break;
			}

			if (0 == (strcmp(z, "T3��վ¥")))
			{
				a1 = 193;
				break;
			}


			//����Ĳ���

			if (0 == (strcmp(z, "������")))
			{
				a1 = 194;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 195;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 196;
				break;
			}
			if (0 == (strcmp(z, "���²����")))
			{
				a1 = 197;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 198;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a1 = 199;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 200;
				break;
			}
			if (0 == (strcmp(z, "��ó")))
			{
				a1 = 201;
				break;
			}
			if (0 == (strcmp(z, "�Ļݶ�")))
			{
				a1 = 202;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 203;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 204;
				break;
			}

			if (0 == (strcmp(z, "��ֱ��")))
			{
				a1 = 205;
				break;
			}

			if (0 == (strcmp(z, "Ӻ�͹�")))
			{
				a1 = 206;
				break;
			}

			if (0 == (strcmp(z, "��¥���")))
			{
				a1 = 207;
				break;
			}

			if (0 == (strcmp(z, "��ֱ��")))
			{
				a1 = 208;
				break;
			}

			if (0 == (strcmp(z, "����ׯ")))
			{
				a1 = 209;
				break;
			}
			if (0 == (strcmp(z, "�����ׯ")))
			{
				a1 = 210;
				break;
			}
			if (0 == (strcmp(z, "����ͼ���")))
			{
				a1 = 211;
				break;
			}
			if (0 == (strcmp(z, "ƽ����")))
			{
				a1 = 212;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 213;
				break;
			}

			if (0 == (strcmp(z, "��ˮ��")))
			{
				a1 = 214;
				break;
			}

			if (0 == (strcmp(z, "���������Ͽ�")))
			{
				a1 = 215;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a1 = 216;
				break;
			}

			if (0 == (strcmp(z, "�μ�ׯ")))
			{
				a1 = 217;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 218;
				break;
			}
			if (0 == (strcmp(z, "��ʯ����")))
			{
				a1 = 219;
				break;
			}
			if (0 == (strcmp(z, "�������")))
			{
				a1 = 220;
				break;
			}
			if (0 == (strcmp(z, "����¥")))
			{
				a1 = 221;
				break;
			}
			if (0 == (strcmp(z, "����ׯ")))
			{
				a1 = 222;
				break;
			}
			if (0 == (strcmp(z, "��Ӫ")))
			{
				a1 = 223;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 224;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 225;
				break;
			}
			if (0 == (strcmp(z, "����ׯ")))
			{
				a1 = 226;
				break;
			}
			if (0 == (strcmp(z, "����ׯ")))
			{
				a1 = 227;
				break;
			}
			if (0 == (strcmp(z, "��Ԫ��")))
			{
				a1 = 228;
				break;
			}
			if (0 == (strcmp(z, "��ҩ��")))
			{
				a1 = 229;
				break;
			}
			if (0 == (strcmp(z, "֪��·")))
			{
				a1 = 230;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a1 = 231;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a1 = 232;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a1 = 233;
				break;
			}





			//�������ѭ����������
			printf("\n���������������������\n");
			gets_s(z, 20);

		}



		//*************************************************************************************************************************************

		printf("�������յ�\n");
		gets_s(z, 20);


		//  �յ�����룡����������
		while (1)
		{

			//1���ߵ����룡��������������
			if (0 == (strcmp(z, "ƻ��԰")))
			{
				a2 = 1;
				break;
			}

			if (0 == (strcmp(z, "�ų�")))
			{
				a2 = 2;
				break;
			}

			if (0 == (strcmp(z, "�˽�����԰")))
			{
				a2 = 3;
				break;
			}


			if (0 == (strcmp(z, "�˱�ɽ")))
			{
				a2 = 4;
				break;
			}
			if (0 == (strcmp(z, "��Ȫ·")))
			{
				a2 = 5;
				break;
			}

			if (0 == (strcmp(z, "�����")))
			{
				a2 = 6;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a2 = 7;
				break;
			}


			if (0 == (strcmp(z, "ľ�ص�")))
			{
				a2 = 8;
				break;
			}

			if (0 == (strcmp(z, "����ʿ·")))
			{
				a2 = 9;
				break;
			}

			if (0 == (strcmp(z, "�찲����")))
			{
				a2 = 10;
				break;
			}

			if (0 == (strcmp(z, "�찲�Ŷ�")))
			{
				a2 = 11;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 12;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 13;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a2 = 14;
				break;
			}

			if (0 == (strcmp(z, "�Ļ�")))
			{
				a2 = 15;
				break;
			}


			//2����


			if (0 == (strcmp(z, "ǰ��")))
			{
				a2 = 16;
				break;
			}

			if (0 == (strcmp(z, "����վ")))
			{
				a2 = 17;
				break;
			}
			if (0 == (strcmp(z, "����ʮ��")))
			{
				a2 = 18;
				break;
			}


			if (0 == (strcmp(z, "������")))
			{
				a2 = 19;
				break;
			}

			if (0 == (strcmp(z, "��ˮ̶")))
			{
				a2 = 20;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 21;
				break;
			}


			if (0 == (strcmp(z, "������")))
			{
				a2 = 22;
				break;
			}

			if (0 == (strcmp(z, "��ƽ��")))
			{
				a2 = 23;
				break;
			}



			//4�Ŵ�����





			if (0 == (strcmp(z, "�����ű�")))
			{
				a2 = 24;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 25;
				break;
			}
			if (0 == (strcmp(z, "��Է")))
			{
				a2 = 26;
				break;
			}

			if (0 == (strcmp(z, "Բ��԰")))
			{
				a2 = 27;
				break;
			}
			if (0 == (strcmp(z, "������ѧ����")))
			{
				a2 = 28;
				break;
			}

			if (0 == (strcmp(z, "�йش�")))
			{
				a2 = 29;
				break;
			}

			if (0 == (strcmp(z, "�����ѧ")))
			{
				a2 = 30;
				break;
			}

			if (0 == (strcmp(z, "κ����")))
			{
				a2 = 31;
				break;
			}

			if (0 == (strcmp(z, "����԰")))
			{
				a2 = 32;
				break;
			}

			if (0 == (strcmp(z, "�½ֿ�")))
			{
				a2 = 33;
				break;
			}


			if (0 == (strcmp(z, "����")))
			{
				a2 = 34;
				break;
			}

			if (0 == (strcmp(z, "�龳��ͬ")))
			{
				a2 = 35;
				break;
			}

			if (0 == (strcmp(z, "���п�")))
			{
				a2 = 36;
				break;
			}

			if (0 == (strcmp(z, "��Ȼͤ")))
			{
				a2 = 37;
				break;
			}


			if (0 == (strcmp(z, "������վ")))
			{
				a2 = 38;
				break;
			}

			if (0 == (strcmp(z, "���ֱ�")))
			{
				a2 = 39;
				break;
			}

			if (0 == (strcmp(z, "��������")))
			{
				a2 = 40;
				break;
			}

			if (0 == (strcmp(z, "�¹�")))
			{
				a2 = 41;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 42;
				break;
			}

			if (0 == (strcmp(z, "���׵걱")))
			{
				a2 = 43;
				break;
			}

			if (0 == (strcmp(z, "���׵���")))
			{
				a2 = 44;
				break;
			}
			if (0 == (strcmp(z, "��԰")))
			{
				a2 = 45;
				break;
			}

			if (0 == (strcmp(z, "��Դ·")))
			{
				a2 = 46;
				break;
			}

			if (0 == (strcmp(z, "�ƴ������")))
			{
				a2 = 47;
				break;
			}

			if (0 == (strcmp(z, "�ƴ��վ")))
			{
				a2 = 48;
				break;
			}

			if (0 == (strcmp(z, "���ׯ")))
			{
				a2 = 49;
				break;
			}

			if (0 == (strcmp(z, "����ҽҩ����")))
			{
				a2 = 50;
				break;
			}

			if (0 == (strcmp(z, "�칬Ժ")))
			{
				a2 = 51;
				break;
			}




			//5����



			if (0 == (strcmp(z, "��ͨԷ��")))
			{
				a2 = 52;
				break;
			}


			if (0 == (strcmp(z, "��ͨԷ")))
			{
				a2 = 53;
				break;
			}
			if (0 == (strcmp(z, "��ͨԷ��")))
			{
				a2 = 54;
				break;
			}

			if (0 == (strcmp(z, "��ˮ����")))
			{
				a2 = 55;
				break;
			}

			if (0 == (strcmp(z, "��Է·��")))
			{
				a2 = 56;
				break;
			}

			if (0 == (strcmp(z, "����·��")))
			{
				a2 = 57;
				break;
			}

			if (0 == (strcmp(z, "�������ֱ���")))
			{
				a2 = 58;
				break;
			}

			if (0 == (strcmp(z, "��ƽ����")))
			{
				a2 = 59;
				break;
			}

			if (0 == (strcmp(z, "��ƽ�ﱱ��")))
			{
				a2 = 60;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 61;
				break;
			}


			if (0 == (strcmp(z, "������·")))
			{
				a2 = 62;
				break;
			}

			if (0 == (strcmp(z, "���п�")))
			{
				a2 = 63;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 64;
				break;
			}

			if (0 == (strcmp(z, "��̳����")))
			{
				a2 = 65;
				break;
			}

			if (0 == (strcmp(z, "�ѻ���")))
			{
				a2 = 66;
				break;
			}
			if (0 == (strcmp(z, "����Ҥ")))
			{
				a2 = 67;
				break;
			}



			//6����




			if (0 == (strcmp(z, "������·��")))
			{
				a2 = 68;
				break;
			}


			if (0 == (strcmp(z, "��԰��")))
			{
				a2 = 69;
				break;
			}

			if (0 == (strcmp(z, "����ׯ��")))
			{
				a2 = 70;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 71;
				break;
			}


			if (0 == (strcmp(z, "������")))
			{
				a2 = 72;
				break;
			}

			if (0 == (strcmp(z, "��̨·")))
			{
				a2 = 73;
				break;
			}


			if (0 == (strcmp(z, "ʮ�ﱤ")))
			{
				a2 = 74;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a2 = 75;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 76;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 77;
				break;
			}

			if (0 == (strcmp(z, "��Ӫ")))
			{
				a2 = 78;
				break;
			}

			if (0 == (strcmp(z, "�ݷ�")))
			{
				a2 = 79;
				break;
			}


			//8����


			if (0 == (strcmp(z, "��֪·")))
			{
				a2 = 80;
				break;
			}

			if (0 == (strcmp(z, "ƽ����")))
			{
				a2 = 81;
				break;
			}

			if (0 == (strcmp(z, "�����۶����")))
			{
				a2 = 82;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 83;
				break;
			}
			if (0 == (strcmp(z, "��С��")))
			{
				a1 = 84;
				break;
			}

			if (0 == (strcmp(z, "��̩ׯ")))
			{
				a2 = 85;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 86;
				break;
			}

			if (0 == (strcmp(z, "ɭ�ֹ�԰����")))
			{
				a2 = 87;
				break;
			}
			if (0 == (strcmp(z, "����ƥ�˹�԰")))
			{
				a2 = 88;
				break;
			}

			if (0 == (strcmp(z, "��������")))
			{
				a2 = 89;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 90;
				break;
			}

			if (0 == (strcmp(z, "ʲɲ��")))
			{
				a2 = 91;
				break;
			}

			//9����


			if (0 == (strcmp(z, "�׶���")))
			{
				a2 = 92;
				break;
			}

			if (0 == (strcmp(z, "������վ")))
			{
				a2 = 93;
				break;
			}

			if (0 == (strcmp(z, "�����Ŷ�")))
			{
				a2 = 94;
				break;
			}
			if (0 == (strcmp(z, "��̨�����")))
			{
				a2 = 95;
				break;
			}

			if (0 == (strcmp(z, "��̨��·")))
			{
				a2 = 96;
				break;
			}
			if (0 == (strcmp(z, "����·")))
			{
				a2 = 97;
				break;
			}
			if (0 == (strcmp(z, "��̨�Ƽ�԰")))
			{
				a2 = 98;
				break;
			}



			//���ߵ�ʮ����


			if (0 == (strcmp(z, "����")))
			{
				a2 = 99;
				break;
			}
			if (0 == (strcmp(z, "��̨վ")))
			{
				a2 = 100;
				break;
			}
			if (0 == (strcmp(z, "�׾�ó")))
			{
				a2 = 101;
				break;
			}
			if (0 == (strcmp(z, "�ͼ���")))
			{
				a2 = 102;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a2 = 103;
				break;
			}
			if (0 == (strcmp(z, "���Ŷ�")))
			{
				a2 = 104;
				break;
			}

			if (0 == (strcmp(z, "�����")))
			{
				a2 = 105;
				break;
			}
			if (0 == (strcmp(z, "ʯ��ׯ")))
			{
				a2 = 106;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 107;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 108;
				break;
			}
			if (0 == (strcmp(z, "ʮ���")))
			{
				a2 = 109;
				break;
			}
			if (0 == (strcmp(z, "�˼�԰")))
			{
				a2 = 110;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a2 = 111;
				break;
			}
			if (0 == (strcmp(z, "˫��")))
			{
				a2 = 112;
				break;
			}
			if (0 == (strcmp(z, "��̨Ϧ��")))
			{
				a2 = 113;
				break;
			}
			if (0 == (strcmp(z, "�Ž��")))
			{
				a2 = 114;
				break;
			}
			if (0 == (strcmp(z, "ũҵչ����")))
			{
				a2 = 115;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 116;
				break;
			}
			if (0 == (strcmp(z, "̫����")))
			{
				a2 = 117;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 118;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 119;
				break;
			}
			if (0 == (strcmp(z, "ĵ��԰")))
			{
				a2 = 120;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 121;
				break;
			}
			if (0 == (strcmp(z, "֪����")))
			{
				a2 = 122;
				break;
			}

			if (0 == (strcmp(z, "���ݽ�")))
			{
				a2 = 123;
				break;
			}

			if (0 == (strcmp(z, "�͹�")))
			{
				a2 = 124;
				break;
			}

			if (0 == (strcmp(z, "����Ӫ")))
			{
				a2 = 125;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 126;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 127;
				break;
			}

			if (0 == (strcmp(z, "��������")))
			{
				a2 = 128;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 129;
				break;
			}


			//13����


			if (0 == (strcmp(z, "������")))
			{
				a2 = 130;
				break;
			}

			if (0 == (strcmp(z, "�����")))
			{
				a2 = 131;
				break;
			}
			if (0 == (strcmp(z, "�ϵ�")))
			{
				a2 = 132;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a2 = 133;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 134;
				break;
			}

			if (0 == (strcmp(z, "��Է")))
			{
				a2 = 135;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 136;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 137;
				break;
			}

			//14����


			if (0 == (strcmp(z, "�Ź�ׯ")))
			{
				a2 = 138;
				break;
			}

			if (0 == (strcmp(z, "԰��԰")))
			{
				a2 = 139;
				break;
			}

			if (0 == (strcmp(z, "����Ҥ")))
			{
				a2 = 140;
				break;
			}

			if (0 == (strcmp(z, "��ׯ��")))
			{
				a2 = 141;
				break;
			}

			if (0 == (strcmp(z, "��")))
			{
				a2 = 142;
				break;
			}


			//15����


			if (0 == (strcmp(z, "ٺ��")))
			{
				a2 = 143;
				break;
			}

			if (0 == (strcmp(z, "˳��")))
			{
				a2 = 144;
				break;
			}

			if (0 == (strcmp(z, "ʯ��")))
			{
				a2 = 145;
				break;
			}

			if (0 == (strcmp(z, "�Ϸ���")))
			{
				a2 = 146;
				break;
			}

			if (0 == (strcmp(z, "��ɳ��")))
			{
				a2 = 147;
				break;
			}
			if (0 == (strcmp(z, "���濲")))
			{
				a2 = 148;
				break;
			}
			if (0 == (strcmp(z, "��չ")))
			{
				a2 = 149;
				break;
			}
			if (0 == (strcmp(z, "���")))
			{
				a2 = 150;
				break;
			}

			if (0 == (strcmp(z, "��ȪӪ")))
			{
				a2 = 151;
				break;
			}

			if (0 == (strcmp(z, "�޸�ׯ")))
			{
				a2 = 152;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 153;
				break;
			}


			//��ͨ��


			if (0 == (strcmp(z, "�߱���")))
			{
				a2 = 154;
				break;
			}

			if (0 == (strcmp(z, "��ý��ѧ")))
			{
				a2 = 155;
				break;
			}

			if (0 == (strcmp(z, "˫��")))
			{
				a2 = 156;
				break;
			}

			if (0 == (strcmp(z, "��ׯ")))
			{
				a2 = 157;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 158;
				break;
			}

			if (0 == (strcmp(z, "ͨ�ݱ�Է")))
			{
				a2 = 159;
				break;
			}

			if (0 == (strcmp(z, "��԰")))
			{
				a2 = 160;
				break;
			}

			if (0 == (strcmp(z, "�ſ���")))
			{
				a2 = 161;
				break;
			}

			if (0 == (strcmp(z, "��԰")))
			{
				a2 = 162;
				break;
			}

			if (0 == (strcmp(z, "�ٺ���")))
			{
				a2 = 163;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 164;
				break;
			}

			//��ƽ��

			if (0 == (strcmp(z, "����")))
			{
				a2 = 165;
				break;
			}

			if (0 == (strcmp(z, "ɳ�Ӹ߽�԰")))
			{
				a2 = 166;
				break;
			}

			if (0 == (strcmp(z, "ɳ��")))
			{
				a2 = 167;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 168;
				break;
			}

			if (0 == (strcmp(z, "������ѧ԰")))
			{
				a2 = 169;
				break;
			}


			//��ׯ��


			if (0 == (strcmp(z, "Ф��")))
			{
				a2 = 170;
				break;
			}
			if (0 == (strcmp(z, "С����")))
			{
				a2 = 171;
				break;
			}
			if (0 == (strcmp(z, "�ɹ�")))
			{
				a2 = 172;
				break;
			}
			if (0 == (strcmp(z, "��ׯ��")))
			{
				a2 = 173;
				break;
			}

			if (0 == (strcmp(z, "��ׯ�Ļ�԰")))
			{
				a2 = 174;
				break;
			}

			if (0 == (strcmp(z, "��Դ��")))
			{
				a2 = 175;
				break;
			}

			if (0 == (strcmp(z, "�پ�����")))
			{
				a2 = 176;
				break;
			}

			if (0 == (strcmp(z, "�ٲ�����")))
			{
				a2 = 177;
				break;
			}

			if (0 == (strcmp(z, "ͬ����·")))
			{
				a2 = 178;
				break;
			}

			if (0 == (strcmp(z, "����·")))
			{
				a2 = 179;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 180;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 181;
				break;
			}


			//��ɽ��


			if (0 == (strcmp(z, "��ׯ")))
			{
				a2 = 182;
				break;
			}

			if (0 == (strcmp(z, "�����Ϲ�")))
			{
				a2 = 183;
				break;
			}

			if (0 == (strcmp(z, "�����ѧ����")))
			{
				a2 = 184;
				break;
			}
			if (0 == (strcmp(z, "�����ѧ��")))
			{
				a2 = 185;
				break;
			}
			if (0 == (strcmp(z, "�����ѧ�Ǳ�")))
			{
				a2 = 186;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 187;
				break;
			}

			if (0 == (strcmp(z, "��ʷ�")))
			{
				a2 = 188;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a2 = 189;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 190;
				break;
			}

			if (0 == (strcmp(z, "����̨")))
			{
				a2 = 191;
				break;
			}

			//������


			if (0 == (strcmp(z, "T2��վ¥")))
			{
				a2 = 192;
				break;
			}

			if (0 == (strcmp(z, "T3��վ¥")))
			{
				a2 = 193;
				break;
			}


			//����Ĳ���

			if (0 == (strcmp(z, "������")))
			{
				a2 = 194;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 195;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 196;
				break;
			}
			if (0 == (strcmp(z, "���²����")))
			{
				a2 = 197;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 198;
				break;
			}

			if (0 == (strcmp(z, "����")))
			{
				a2 = 199;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 200;
				break;
			}
			if (0 == (strcmp(z, "��ó")))
			{
				a2 = 201;
				break;
			}
			if (0 == (strcmp(z, "�Ļݶ�")))
			{
				a2 = 202;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 203;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 204;
				break;
			}

			if (0 == (strcmp(z, "��ֱ��")))
			{
				a2 = 205;
				break;
			}

			if (0 == (strcmp(z, "Ӻ�͹�")))
			{
				a2 = 206;
				break;
			}

			if (0 == (strcmp(z, "��¥���")))
			{
				a2 = 207;
				break;
			}

			if (0 == (strcmp(z, "��ֱ��")))
			{
				a2 = 208;
				break;
			}

			if (0 == (strcmp(z, "����ׯ")))
			{
				a2 = 209;
				break;
			}
			if (0 == (strcmp(z, "�����ׯ")))
			{
				a2 = 210;
				break;
			}
			if (0 == (strcmp(z, "����ͼ���")))
			{
				a2 = 211;
				break;
			}
			if (0 == (strcmp(z, "ƽ����")))
			{
				a2 = 212;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 213;
				break;
			}

			if (0 == (strcmp(z, "��ˮ��")))
			{
				a2 = 214;
				break;
			}

			if (0 == (strcmp(z, "���������Ͽ�")))
			{
				a2 = 215;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a2 = 216;
				break;
			}

			if (0 == (strcmp(z, "�μ�ׯ")))
			{
				a2 = 217;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 218;
				break;
			}
			if (0 == (strcmp(z, "��ʯ����")))
			{
				a2 = 219;
				break;
			}
			if (0 == (strcmp(z, "�������")))
			{
				a2 = 220;
				break;
			}
			if (0 == (strcmp(z, "����¥")))
			{
				a2 = 221;
				break;
			}
			if (0 == (strcmp(z, "����ׯ")))
			{
				a2 = 222;
				break;
			}
			if (0 == (strcmp(z, "��Ӫ")))
			{
				a2 = 223;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 224;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 225;
				break;
			}
			if (0 == (strcmp(z, "����ׯ")))
			{
				a2 = 226;
				break;
			}
			if (0 == (strcmp(z, "����ׯ")))
			{
				a2 = 227;
				break;
			}
			if (0 == (strcmp(z, "��Ԫ��")))
			{
				a2 = 228;
				break;
			}
			if (0 == (strcmp(z, "��ҩ��")))
			{
				a2 = 229;
				break;
			}
			if (0 == (strcmp(z, "֪��·")))
			{
				a2 = 230;
				break;
			}
			if (0 == (strcmp(z, "����")))
			{
				a2 = 231;
				break;
			}

			if (0 == (strcmp(z, "������")))
			{
				a2 = 232;
				break;
			}
			if (0 == (strcmp(z, "������")))
			{
				a2 = 233;
				break;
			}





			//�������ѭ����������
			printf("\n�յ�������������������\n");
			gets_s(z, 20);

		}


		if (a1 == a2)
		{
			printf("��������\n");
			system("pause");
			return;
		}

		//**********************************************************************************************************************************************************
		for (int i = 1; i <= n; ++i)
			dist[i] = maxint;

		Dijkstra(n, a1, dist, prev, c);

		// ���·������
		printf("����Ҫ��������%dվ\n", dist[a2]);

		// ·��
		printf("���·��Ϊ��");
		way(prev, a1, a2);
		printf("\n���������밴1  ���������밴0     ");
		scanf_s("%d", &asd);
		getchar();
	}
	system("pause");
}