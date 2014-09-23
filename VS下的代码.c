#include<stdio.h>
#include<string.h>

const int maxint = 999999;


void Dijkstra(int n, int v, int *dist, int *prev, int c[300][300])
{
	int s[10000];
	for (int i = 1; i <= n; ++i)
	{

		dist[i] = c[v][i];
		s[i] = 0;     // S集合初始化
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;//设置连接起始点的点
	}
	dist[v] = 0;//自己到自己为0；
	s[v] = 1;//源点加入S集合

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	//用s集合1和0表示是否在S集合内
	for (int i = 2; i <= 10000; ++i)
	{
		int tmp = maxint;
		int u = v;
		// 找出当前未使用的点j的dist[j]最小值
		for (int j = 1; j <= n; ++j)
		if ((!s[j]) && dist[j]<tmp)//S【j】为0则执行后面语句；

		{
			u = j;              // u保存当前邻接点中距离最小的点的号码
			tmp = dist[j];
		}
		s[u] = 1;    // 表示u点已存入S集合中

		// 更新dist
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

void way(int *prev, int v, int u)//v是起点  u是终点
{
	int que[10000];
	int num = 1;
	que[num] = u;//que【num】来表示点  1代表终点 
	num++;
	int tmp = prev[u];
	while (tmp != v)
	{
		que[num] = tmp;
		num++;
		tmp = prev[tmp];
	}//循环使一次代表上个点，用中间变量tmp来表示上个点编号
	que[num] = v;
	int i;
	i = num;
	int zp=0; //定义站牌号
	//**********************************************************************************************************************************
	if (((que[i] >= 1 && que[i] <= 15) || (que[i] >= 195 && que[i] <= 202)) && ((que[i - 1] >= 1 && que[i - 1] <= 15) || (que[i - 1] >= 195 && que[i - 1] <= 202)))
	{
		printf("（请乘坐1号线地铁）");
		zp = 1;
	}
	else if (((que[i] >= 16 && que[i] <= 23) || (que[i] >= 203 && que[i] <= 209) || que[i] == 200 || que[i] == 194 || que[i] == 198) && ((que[i - 1] >= 16 && que[i - 1] <= 23) || (que[i - 1] >= 203 && que[i - 1] <= 209) || que[i - 1] == 200 || que[i - 1] == 194 || que[i - 1] == 198))
	{
		printf("(请乘坐2号线地铁)");
		zp = 2;
	}
	else if (((que[i] >= 24 && que[i] <= 51) || (que[i] >= 210 && que[i] <= 213) || que[i] == 194 || que[i] == 195 || que[i] == 208) && ((que[i - 1] >= 24 && que[i - 1] <= 51) || (que[i - 1] >= 210 && que[i - 1] <= 213) || que[i - 1] == 194 || que[i - 1] == 195 || que[i - 1] == 208))
	{
		printf("(请乘坐4号大兴线)");
		zp = 3;
	}
	else if (((que[i] >= 52 && que[i] <= 67) || (que[i] >= 214 && que[i] <= 217) || que[i] == 206 || que[i] == 203 || que[i] == 199) && ((que[i - 1] >= 52 && que[i - 1] <= 67) || (que[i - 1] >= 214 && que[i - 1] <= 217) || que[i - 1] == 206 || que[i - 1] == 203 || que[i - 1] == 199))
	{
		printf("(请乘坐5号线)");
		zp = 4;
	}
	else if (((que[i] >= 68 && que[i] <= 79) || (que[i] >= 218 && que[i] <= 221) || que[i] == 209 || que[i] == 204 || que[i] == 212 || que[i] == 216) && ((que[i - 1] >= 68 && que[i - 1] <= 79) || (que[i - 1] >= 218 && que[i - 1] <= 221) || que[i - 1] == 209 || que[i - 1] == 204 || que[i - 1] == 212 || que[i - 1] == 216))
	{
		printf("(请乘坐6号线)");
		zp = 5;
	}
	else if (((que[i] >= 80 && que[i] <= 91) || que[i] == 222 || que[i] == 223 || que[i] == 224 || que[i] == 207 || que[i] == 220) && ((que[i - 1] >= 80 && que[i - 1] <= 91) || que[i - 1] == 222 || que[i - 1] == 223 || que[i - 1] == 224 || que[i - 1] == 207 || que[i - 1] == 220))
	{
		printf("(请乘坐8号线)");
		zp = 6;
	}
	else if (((que[i] >= 92 && que[i] <= 98) || que[i] == 211 || que[i] == 219 || que[i] == 197 || que[i] == 225 || que[i] == 226 || que[i] == 227) && ((que[i - 1] >= 92 && que[i - 1] <= 98) || que[i - 1] == 211 || que[i - 1] == 219 || que[i - 1] == 197 || que[i - 1] == 225 || que[i - 1] == 226 || que[i - 1] == 227))
	{
		printf("(请乘坐9号线)");
		zp = 7;
	}
	else if (((que[i] >= 99 && que[i] <= 129) || que[i] == 213 || que[i] == 217 || que[i] == 201 || que[i] == 221 || que[i] == 228 || que[i] == 229 || que[i] == 215 || que[i] == 224 || que[i] == 230 || que[i] == 210 || que[i] == 218 || que[i] == 196 || que[i] == 225 || que[i] == 231) && \
		((que[i - 1] >= 99 && que[i - 1] <= 129) || que[i - 1] == 213 || que[i - 1] == 217 || que[i - 1] == 201 || que[i - 1] == 221 || que[i - 1] == 228 || que[i - 1] == 229 || que[i - 1] == 215 || que[i - 1] == 224 || que[i - 1] == 230 || que[i - 1] == 210 || que[i - 1] == 218 || que[i - 1] == 196 || que[i - 1] == 225 || que[i - 1] == 231))
	{
		printf("(请乘坐10号线)");
		zp = 8;
	}
	else if (((que[i] >= 130 && que[i] <= 137) || que[i] == 208 || que[i] == 230 || que[i] == 232 || que[i] == 223 || que[i] == 214 || que[i] == 233 || que[i] == 229 || que[i] == 205) && ((que[i - 1] >= 130 && que[i - 1] <= 137) || que[i - 1] == 208 || que[i - 1] == 230 || que[i - 1] == 232 || que[i - 1] == 223 || que[i - 1] == 214 || que[i - 1] == 233 || que[i - 1] == 229 || que[i - 1] == 205))
	{
		printf("(请乘坐13号线)");
		zp = 9;

	}

	else if (((que[i] >= 138 && que[i] <= 142) || que[i] == 226 || que[i] == 231) && ((que[i - 1] >= 138 && que[i - 1] <= 142) || que[i - 1] == 226 || que[i - 1] == 231))
	{
		printf("(请乘坐14号线)");
		zp = 10;
	}
	else if (((que[i] >= 143 && que[i] <= 153) || que[i] == 233) && ((que[i - 1] >= 143 && que[i - 1] <= 153) || que[i - 1] == 233))
	{
		printf("（请乘坐15号线）");
		zp = 11;
	}
	else if (((que[i] >= 154 && que[i] <= 164) || que[i] == 15 || que[i] == 202) && ((que[i - 1] >= 154 && que[i - 1] <= 164) || que[i - 1] == 15 || que[i - 1] == 202))
	{
		printf("(请乘坐八通线)");
		zp =12;
	}
	else if (((que[i] >= 165 && que[i] <= 169) || que[i] == 222 || que[i] == 232) && ((que[i - 1] >= 165 && que[i - 1] <= 169) || que[i - 1] == 222 || que[i - 1] == 232))
	{
		printf("(请乘坐昌平线)");
		zp = 13;
	}
	else if (((que[i] >= 170 && que[i] <= 181) || que[i] == 217) && ((que[i - 1] >= 170 && que[i - 1] <= 181) || que[i - 1] == 217))
	{
		printf("(请乘坐亦庄线)");
		zp = 14;
	}
	else if (((que[i] >= 182 && que[i] <= 191) || que[i] == 227) && ((que[i - 1] >= 182 && que[i - 1] <= 191) || que[i - 1] == 227))
	{
		printf("(请乘坐房山线)");
		zp = 15;
	}
	else if ((que[i] == 205 || que[i] == 228 || que[i] == 192 || que[i] == 193) && (que[i - 1] == 205 || que[i - 1] == 228 || que[i - 1] == 192 || que[i - 1] == 193))

	{
		printf("(请乘坐机场线)");
		zp = 16;
	}




	//*************************************************************************************************************************************
	for (i = num; i >= 1; --i)
	if (i != 1)
	{

		//**********************************************************************************************************************************
		if (((que[i] >= 1 && que[i] <= 15) || (que[i] >= 195 && que[i] <= 202)) && ((que[i - 1] >= 1 && que[i - 1] <= 15) || (que[i - 1] >= 195 && que[i - 1] <= 202)) && zp != 1)
		{
			printf("（请乘坐1号线地铁）");
			zp = 1;
		}
		else if (((que[i] >= 16 && que[i] <= 23) || (que[i] >= 203 && que[i] <= 209) || que[i] == 200 || que[i] == 194 || que[i] == 198) && ((que[i - 1] >= 16 && que[i - 1] <= 23) || (que[i - 1] >= 203 && que[i - 1] <= 209) || que[i - 1] == 200 || que[i - 1] == 194 || que[i - 1] == 198) && zp != 2)
		{
			printf("(请乘坐2号线地铁)");
			zp = 2;
		}
		else if (((que[i] >= 24 && que[i] <= 51) || (que[i] >= 210 && que[i] <= 213) || que[i] == 194 || que[i] == 195 || que[i] == 208) && ((que[i - 1] >= 24 && que[i - 1] <= 51) || (que[i - 1] >= 210 && que[i - 1] <= 213) || que[i - 1] == 194 || que[i - 1] == 195 || que[i - 1] == 208) && zp != 3)
		{
			printf("(请乘坐4号大兴线)");
			zp = 3;
		}
		else if (((que[i] >= 52 && que[i] <= 67) || (que[i] >= 214 && que[i] <= 217) || que[i] == 206 || que[i] == 203 || que[i] == 199) && ((que[i - 1] >= 52 && que[i - 1] <= 67) || (que[i - 1] >= 214 && que[i - 1] <= 217) || que[i - 1] == 206 || que[i - 1] == 203 || que[i - 1] == 199) && zp != 4)
		{
			printf("(请乘坐5号线)");
			zp = 4;
		}
		else if (((que[i] >= 68 && que[i] <= 79) || (que[i] >= 218 && que[i] <= 221) || que[i] == 209 || que[i] == 204 || que[i] == 212 || que[i] == 216) && ((que[i - 1] >= 68 && que[i - 1] <= 79) || (que[i - 1] >= 218 && que[i - 1] <= 221) || que[i - 1] == 209 || que[i - 1] == 204 || que[i - 1] == 212 || que[i - 1] == 216) && zp != 5)
		{
			printf("(请乘坐6号线)");
			zp = 5;
		}
		else if (((que[i] >= 80 && que[i] <= 91) || que[i] == 222 || que[i] == 223 || que[i] == 224 || que[i] == 207 || que[i] == 220) && ((que[i - 1] >= 80 && que[i - 1] <= 91) || que[i - 1] == 222 || que[i - 1] == 223 || que[i - 1] == 224 || que[i - 1] == 207 || que[i - 1] == 220) && zp != 6)
		{
			printf("(请乘坐8号线)");
			zp = 6;
		}
		else if (((que[i] >= 92 && que[i] <= 98) || que[i] == 211 || que[i] == 219 || que[i] == 197 || que[i] == 225 || que[i] == 226 || que[i] == 227) && ((que[i - 1] >= 92 && que[i - 1] <= 98) || que[i - 1] == 211 || que[i - 1] == 219 || que[i - 1] == 197 || que[i - 1] == 225 || que[i - 1] == 226 || que[i - 1] == 227) && zp != 7)
		{
			printf("(请乘坐9号线)");
			zp = 7;
		}
		else if (((que[i] >= 99 && que[i] <= 129) || que[i] == 213 || que[i] == 217 || que[i] == 201 || que[i] == 221 || que[i] == 228 || que[i] == 229 || que[i] == 215 || que[i] == 224 || que[i] == 230 || que[i] == 210 || que[i] == 218 || que[i] == 196 || que[i] == 225 || que[i] == 231) && \
			((que[i - 1] >= 99 && que[i - 1] <= 129) || que[i - 1] == 213 || que[i - 1] == 217 || que[i - 1] == 201 || que[i - 1] == 221 || que[i - 1] == 228 || que[i - 1] == 229 || que[i - 1] == 215 || que[i - 1] == 224 || que[i - 1] == 230 || que[i - 1] == 210 || que[i - 1] == 218 || que[i - 1] == 196 || que[i - 1] == 225 || que[i - 1] == 231) && zp != 8)
		{
			printf("(请乘坐10号线)");
			zp = 8;
		}
		else if (((que[i] >= 130 && que[i] <= 137) || que[i] == 208 || que[i] == 230 || que[i] == 232 || que[i] == 223 || que[i] == 214 || que[i] == 233 || que[i] == 229 || que[i] == 205) && ((que[i - 1] >= 130 && que[i - 1] <= 137) || que[i - 1] == 208 || que[i - 1] == 230 || que[i - 1] == 232 || que[i - 1] == 223 || que[i - 1] == 214 || que[i - 1] == 233 || que[i - 1] == 229 || que[i - 1] == 205) && zp != 9)
		{
			printf("(请乘坐13号线)");
			zp = 9;

		}

		else if (((que[i] >= 138 && que[i] <= 142) || que[i] == 226 || que[i] == 231) && ((que[i - 1] >= 138 && que[i - 1] <= 142) || que[i - 1] == 226 || que[i - 1] == 231) && zp != 10)
		{
			printf("(请乘坐14号线)");
			zp = 10;
		}
		else if (((que[i] >= 143 && que[i] <= 153) || que[i] == 233) && ((que[i - 1] >= 143 && que[i - 1] <= 153) || que[i - 1] == 233) && zp != 11)
		{
			printf("（请乘坐15号线）");
			zp = 11;
		}
		else if (((que[i] >= 154 && que[i] <= 164) || que[i] == 15 || que[i] == 202) && ((que[i - 1] >= 154 && que[i - 1] <= 164) || que[i - 1] == 15 || que[i - 1] == 202) && zp != 12)
		{
			printf("(请乘坐八通线)");
			zp = 12;
		}
		else if (((que[i] >= 165 && que[i] <= 169) || que[i] == 222 || que[i] == 232) && ((que[i - 1] >= 165 && que[i - 1] <= 169) || que[i - 1] == 222 || que[i - 1] == 232) && zp != 13)
		{
			printf("(请乘坐昌平线)");
			zp = 13;
		}
		else if (((que[i] >= 170 && que[i] <= 181) || que[i] == 217) && ((que[i - 1] >= 170 && que[i - 1] <= 181) || que[i - 1] == 217) && zp != 14)
		{
			printf("(请乘坐亦庄线)");
			zp = 14;
		}
		else if (((que[i] >= 182 && que[i] <= 191) || que[i] == 227) && ((que[i - 1] >= 182 && que[i - 1] <= 191) || que[i - 1] == 227) && zp != 15)
		{
			printf("(请乘坐房山线)");
			zp = 15;
		}
		else if ((que[i] == 205 || que[i] == 228 || que[i] == 192 || que[i] == 193) && (que[i - 1] == 205 || que[i - 1] == 228 || que[i - 1] == 192 || que[i - 1] == 193) && zp != 16)

		{
			printf("(请乘坐机场线)");
			zp = 16;
		}
		if (que[i] == 1)
			printf("苹果园->");
		if (que[i] == 2)
			printf("古城->");
		if (que[i] == 3)
			printf("八角游乐园->");
		if (que[i] == 4)
			printf("八宝山->");
		if (que[i] == 5)
			printf("玉泉路->");
		if (que[i] == 6)
			printf("五棵松->");
		if (que[i] == 7)
			printf("万寿路->");
		if (que[i] == 8)
			printf("木樨路->");
		if (que[i] == 9)
			printf("南礼土路->");
		if (que[i] == 10)
			printf("天安门西->");
		if (que[i] == 11)
			printf("天安门东->");
		if (que[i] == 12)
			printf("王府井->");
		if (que[i] == 13)
			printf("永安里->");
		if (que[i] == 14)
			printf("大望路->");
		if (que[i] == 15)
			printf("四惠->");
		if (que[i] == 16)
			printf("前门->");
		if (que[i] == 17)
			printf("北京站->");
		if (que[i] == 18)
			printf("东四十条->");
		if (que[i] == 19)
			printf("安定门->");
		if (que[i] == 20)
			printf("积水潭->");
		if (que[i] == 21)
			printf("阜成门->");
		if (que[i] == 22)
			printf("长椿街->");
		if (que[i] == 23)
			printf("和平门->");
		if (que[i] == 24)
			printf("安河桥北->");
		if (que[i] == 25)
			printf("北宫门->");
		if (que[i] == 26)
			printf("西苑->");
		if (que[i] == 27)
			printf("圆明园->");
		if (que[i] == 28)
			printf("北京大学东门->");
		if (que[i] == 29)
			printf("中关村->");
		if (que[i] == 30)
			printf("人民大学->");
		if (que[i] == 31)
			printf("魏公村->");
		if (que[i] == 32)
			printf("动物园->");
		if (que[i] == 33)
			printf("新街口->");
		if (que[i] == 34)
			printf("西四->");
		if (que[i] == 35)
			printf("灵境胡同->");
		if (que[i] == 36)
			printf("菜市口->");
		if (que[i] == 37)
			printf("陶然亭->");
		if (que[i] == 38)
			printf("北京南站->");
		if (que[i] == 39)
			printf("马字堡->");
		if (que[i] == 40)
			printf("公益西桥->");
		if (que[i] == 41)
			printf("新宫->");
		if (que[i] == 42)
			printf("西红门->");
		if (que[i] == 43)
			printf("高米店北->");
		if (que[i] == 44)
			printf("高米店南->");
		if (que[i] == 45)
			printf("枣园->");
		if (que[i] == 46)
			printf("清源路->");
		if (que[i] == 47)
			printf("黄村西大街->");
		if (que[i] == 48)
			printf("黄村火车站->");
		if (que[i] == 49)
			printf("义和庄->");
		if (que[i] == 50)
			printf("生物医药基地->");
		if (que[i] == 51)
			printf("天宫院->");
		if (que[i] == 52)
			printf("天通苑北->");
		if (que[i] == 53)
			printf("天通苑->");
		if (que[i] == 54)
			printf("天通苑南->");
		if (que[i] == 55)
			printf("立水桥南->");
		if (que[i] == 56)
			printf("北苑路北->");
		if (que[i] == 57)
			printf("大屯路东->");
		if (que[i] == 58)
			printf("惠新北街北口->");
		if (que[i] == 59)
			printf("和平西桥->");
		if (que[i] == 62)
			printf("张自忠路->");
		if (que[i] == 63)
			printf("灯市口->");
		if (que[i] == 64)
			printf("磁器口->");
		if (que[i] == 65)
			printf("天坛东门->");
		if (que[i] == 66)
			printf("蒲黄榆->");
		if (que[i] == 67)
			printf("刘家窑->");
		if (que[i] == 68)
			printf("海淀五居路->");
		if (que[i] == 69)
			printf("花园桥->");
		if (que[i] == 70)
			printf("车公庄西->");
		if (que[i] == 71)
			printf("北海北->");
		if (que[i] == 72)
			printf("东大桥->");
		if (que[i] == 73)
			printf("金台路->");
		if (que[i] == 74)
			printf("十里堡->");
		if (que[i] == 75)
			printf("青年路->");
		if (que[i] == 76)
			printf("褡裢坡->");
		if (que[i] == 77)
			printf("黄渠->");
		if (que[i] == 78)
			printf("常营->");
		if (que[i] == 79)
			printf("草房->");
		if (que[i] == 80)
			printf("育知路->");
		if (que[i] == 81)
			printf("平西府->");
		if (que[i] == 82)
			printf("回龙观东大街->");
		if (que[i] == 83)
			printf("育新->");
		if (que[i] == 84)
			printf("西小口->");
		if (que[i] == 85)
			printf("永泰庄->");
		if (que[i] == 86)
			printf("林翠桥->");
		if (que[i] == 87)
			printf("森林公园南门->");
		if (que[i] == 88)
			printf("奥林匹克公园->");
		if (que[i] == 89)
			printf("奥体中心->");
		if (que[i] == 90)
			printf("安华桥->");
		if (que[i] == 91)
			printf("什刹海->");
		if (que[i] == 92)
			printf("白堆子->");
		if (que[i] == 93)
			printf("北京西站->");
		if (que[i] == 94)
			printf("六里桥东->");
		if (que[i] == 95)
			printf("丰台东大街->");
		if (que[i] == 96)
			printf("丰台南路->");
		if (que[i] == 97)
			printf("科怡路->");
		if (que[i] == 98)
			printf("丰台科技园->");
		if (que[i] == 99)
			printf("泥洼->");
		if (que[i] == 100)
			printf("丰台站->");
		if (que[i] == 101)
			printf("首经贸->");
		if (que[i] == 102)
			printf("纪家庙->");
		if (que[i] == 103)
			printf("草桥->");
		if (que[i] == 104)
			printf("角门东->");
		if (que[i] == 105)
			printf("大红门->");
		if (que[i] == 106)
			printf("石榴庄->");
		if (que[i] == 107)
			printf("成寿寺->");
		if (que[i] == 108)
			printf("分钟寺->");
		if (que[i] == 109)
			printf("十里河->");
		if (que[i] == 110)
			printf("潘家园->");
		if (que[i] == 111)
			printf("劲松->");
		if (que[i] == 112)
			printf("双井->");
		if (que[i] == 113)
			printf("金台夕照->");
		if (que[i] == 114)
			printf("团结湖->");
		if (que[i] == 115)
			printf("农业展览馆->");
		if (que[i] == 116)
			printf("亮马桥->");
		if (que[i] == 117)
			printf("太阳宫->");
		if (que[i] == 118)
			printf("安贞门->");
		if (que[i] == 119)
			printf("建德门->");
		if (que[i] == 120)
			printf("牡丹园->");
		if (que[i] == 121)
			printf("西土城->");
		if (que[i] == 122)
			printf("知春里->");
		if (que[i] == 123)
			printf("苏州街->");
		if (que[i] == 124)
			printf("巴沟->");
		if (que[i] == 125)
			printf("火器营->");
		if (que[i] == 126)
			printf("长春桥->");
		if (que[i] == 127)
			printf("车道沟->");
		if (que[i] == 128)
			printf("西钓鱼台->");
		if (que[i] == 129)
			printf("莲花桥->");
		if (que[i] == 130)
			printf("大钟寺->");
		if (que[i] == 131)
			printf("西道口->");
		if (que[i] == 132)
			printf("上地->");
		if (que[i] == 133)
			printf("龙泽->");
		if (que[i] == 134)
			printf("回龙观->");
		if (que[i] == 135)
			printf("北苑->");
		if (que[i] == 136)
			printf("光熙门->");
		if (que[i] == 137)
			printf("柳芳->");
		if (que[i] == 138)
			printf("张郭庄->");
		if (que[i] == 139)
			printf("园博园->");
		if (que[i] == 140)
			printf("大瓦窑->");
		if (que[i] == 141)
			printf("郭庄子->");
		if (que[i] == 142)
			printf("大井->");
		if (que[i] == 143)
			printf("俸伯->");
		if (que[i] == 144)
			printf("顺义->");
		if (que[i] == 145)
			printf("石门->");
		if (que[i] == 146)
			printf("南法信->");
		if (que[i] == 147)
			printf("后沙峪->");
		if (que[i] == 148)
			printf("花梨坎->");
		if (que[i] == 149)
			printf("国展->");
		if (que[i] == 150)
			printf("孙河->");
		if (que[i] == 151)
			printf("马泉营->");
		if (que[i] == 152)
			printf("崔各庄->");
		if (que[i] == 153)
			printf("望京->");
		if (que[i] == 154)
			printf("高碑店->");
		if (que[i] == 155)
			printf("传媒大学->");
		if (que[i] == 156)
			printf("双桥->");
		if (que[i] == 157)
			printf("管庄->");
		if (que[i] == 158)
			printf("八里桥->");
		if (que[i] == 159)
			printf("通州北苑->");
		if (que[i] == 160)
			printf("果园->");
		if (que[i] == 161)
			printf("九棵树->");
		if (que[i] == 162)
			printf("梨园->");
		if (que[i] == 163)
			printf("临河里->");
		if (que[i] == 164)
			printf("土桥->");
		if (que[i] == 165)
			printf("南邵->");
		if (que[i] == 166)
			printf("沙河高教园->");
		if (que[i] == 167)
			printf("沙河->");
		if (que[i] == 168)
			printf("巩华城->");
		if (que[i] == 169)
			printf("生命科学园->");
		if (que[i] == 170)
			printf("肖村->");
		if (que[i] == 171)
			printf("小红门->");
		if (que[i] == 172)
			printf("旧宫->");
		if (que[i] == 173)
			printf("亦庄桥->");
		if (que[i] == 174)
			printf("亦庄文化园->");
		if (que[i] == 175)
			printf("万源街->");
		if (que[i] == 176)
			printf("荣京东街->");
		if (que[i] == 177)
			printf("荣昌东街->");
		if (que[i] == 178)
			printf("同济南路->");
		if (que[i] == 179)
			printf("经海路->");
		if (que[i] == 180)
			printf("次渠南->");
		if (que[i] == 181)
			printf("次渠->");
		if (que[i] == 182)
			printf("苏庄->");
		if (que[i] == 183)
			printf("良乡南关->");
		if (que[i] == 184)
			printf("良乡大学城西->");
		if (que[i] == 185)
			printf("良乡大学城->");
		if (que[i] == 186)
			printf("良乡大学城北->");
		if (que[i] == 187)
			printf("广阳城->");
		if (que[i] == 188)
			printf("篱笆房->");
		if (que[i] == 189)
			printf("长阳->");
		if (que[i] == 190)
			printf("稻田->");
		if (que[i] == 191)
			printf("大葆台->");
		if (que[i] == 192)
			printf("T2航站楼->");
		if (que[i] == 193)
			printf("T3航站楼->");
		if (que[i] == 194)
			printf("宣武门->");
		if (que[i] == 195)
			printf("西单->");
		if (que[i] == 196)
			printf("公主坟->");
		if (que[i] == 197)
			printf("军事博物馆->");
		if (que[i] == 198)
			printf("复兴门->");
		if (que[i] == 199)
			printf("东单->");
		if (que[i] == 200)
			printf("建国门->");
		if (que[i] == 201)
			printf("国贸->");
		if (que[i] == 202)
			printf("四惠东->");
		if (que[i] == 203)
			printf("崇文门->");
		if (que[i] == 204)
			printf("朝阳门->");
		if (que[i] == 205)
			printf("东直门->");
		if (que[i] == 206)
			printf("雍和宫->");
		if (que[i] == 207)
			printf("鼓楼大街->");
		if (que[i] == 208)
			printf("西直门->");
		if (que[i] == 209)
			printf("车公庄->");
		if (que[i] == 210)
			printf("海淀黄庄->");
		if (que[i] == 211)
			printf("国家图书馆->");
		if (que[i] == 212)
			printf("平安里->");
		if (que[i] == 213)
			printf("角门西->");
		if (que[i] == 214)
			printf("立水桥->");
		if (que[i] == 215)
			printf("惠新西街南口->");
		if (que[i] == 216)
			printf("东四->");
		if (que[i] == 217)
			printf("宋家庄->");
		if (que[i] == 218)
			printf("慈寿寺->");
		if (que[i] == 219)
			printf("白石桥南->");
		if (que[i] == 220)
			printf("南锣巷鼓->");
		if (que[i] == 221)
			printf("呼家楼->");
		if (que[i] == 222)
			printf("朱辛庄->");
		if (que[i] == 223)
			printf("霍营->");
		if (que[i] == 224)
			printf("北土城->");
		if (que[i] == 225)
			printf("六里桥->");
		if (que[i] == 226)
			printf("七里庄->");
		if (que[i] == 227)
			printf("郭公庄->");
		if (que[i] == 228)
			printf("三元桥->");
		if (que[i] == 229)
			printf("芍药居->");
		if (que[i] == 230)
			printf("知春路->");
		if (que[i] == 231)
			printf("西局->");
		if (que[i] == 232)
			printf("西二旗->");
		if (que[i] == 233)
			printf("望西京->");
	


	}


	if (que[1] == 1)
		printf("苹果园");
	if (que[1] == 2)
		printf("古城");
	if (que[1] == 3)
		printf("八角游乐园");
	if (que[1] == 4)
		printf("八宝山");
	if (que[1] == 5)
		printf("玉泉路");
	if (que[1] == 6)
		printf("五棵松");
	if (que[1] == 7)
		printf("万寿路");
	if (que[1] == 8)
		printf("木樨路");
	if (que[1] == 9)
		printf("南礼土路");
	if (que[1] == 10)
		printf("天安门西");
	if (que[1] == 11)
		printf("天安门东");
	if (que[1] == 12)
		printf("王府井");
	if (que[1] == 13)
		printf("永安里");
	if (que[1] == 14)
		printf("大望路");
	if (que[1] == 15)
		printf("->四惠");
	if (que[1] == 16)
		printf("前门");
	if (que[1] == 17)
		printf("北京站");
	if (que[1] == 18)
		printf("东四十条");
	if (que[1] == 19)
		printf("安定门");
	if (que[1] == 20)
		printf("积水潭");
	if (que[1] == 21)
		printf("阜成门");
	if (que[1] == 22)
		printf("长椿街");
	if (que[1] == 23)
		printf("和平门");
	if (que[1] == 24)
		printf("安河桥北");
	if (que[1] == 25)
		printf("北宫门");
	if (que[1] == 26)
		printf("西苑");
	if (que[1] == 27)
		printf("圆明园");
	if (que[1] == 28)
		printf("北京大学东门");
	if (que[1] == 29)
		printf("中关村");
	if (que[1] == 30)
		printf("人民大学");
	if (que[1] == 31)
		printf("魏公村");
	if (que[1] == 32)
		printf("动物园");
	if (que[1] == 33)
		printf("新街口");
	if (que[1] == 34)
		printf("西四");
	if (que[1] == 35)
		printf("灵境胡同");
	if (que[1] == 36)
		printf("菜市口");
	if (que[1] == 37)
		printf("陶然亭");
	if (que[1] == 38)
		printf("北京南站");
	if (que[1] == 39)
		printf("马字堡");
	if (que[1] == 40)
		printf("公益西桥");
	if (que[1] == 41)
		printf("新宫");
	if (que[1] == 42)
		printf("西红门");
	if (que[1] == 43)
		printf("高米店北");
	if (que[1] == 44)
		printf("高米店南");
	if (que[1] == 45)
		printf("枣园");
	if (que[1] == 46)
		printf("清源路");
	if (que[1] == 47)
		printf("黄村西大街");
	if (que[1] == 48)
		printf("黄村火车站");
	if (que[1] == 49)
		printf("义和庄");
	if (que[1] == 50)
		printf("生物医药基地");
	if (que[1] == 51)
		printf("天宫院");
	if (que[1] == 52)
		printf("天通苑北");
	if (que[1] == 53)
		printf("天通苑");
	if (que[1] == 54)
		printf("天通苑南");
	if (que[1] == 55)
		printf("立水桥南");
	if (que[1] == 56)
		printf("北苑路北");
	if (que[1] == 57)
		printf("大屯路东");
	if (que[1] == 58)
		printf("惠新北街北口");
	if (que[1] == 59)
		printf("和平西桥");
	if (que[1] == 62)
		printf("张自忠路");
	if (que[1] == 63)
		printf("灯市口");
	if (que[1] == 64)
		printf("磁器口");
	if (que[1] == 65)
		printf("天坛东门");
	if (que[1] == 66)
		printf("蒲黄榆");
	if (que[1] == 67)
		printf("刘家窑");
	if (que[1] == 68)
		printf("海淀五居路");
	if (que[1] == 69)
		printf("花园桥");
	if (que[1] == 70)
		printf("车公庄西");
	if (que[1] == 71)
		printf("北海北");
	if (que[1] == 72)
		printf("东大桥");
	if (que[1] == 73)
		printf("金台路");
	if (que[1] == 74)
		printf("十里堡");
	if (que[1] == 75)
		printf("青年路");
	if (que[1] == 76)
		printf("褡裢坡");
	if (que[1] == 77)
		printf("黄渠");
	if (que[1] == 78)
		printf("常营");
	if (que[1] == 79)
		printf("草房");
	if (que[1] == 80)
		printf("育知路");
	if (que[1] == 81)
		printf("平西府");
	if (que[1] == 82)
		printf("回龙观东大街");
	if (que[1] == 83)
		printf("育新");
	if (que[1] == 84)
		printf("西小口");
	if (que[1] == 85)
		printf("永泰庄");
	if (que[1] == 86)
		printf("林翠桥");
	if (que[1] == 87)
		printf("森林公园南门");
	if (que[1] == 88)
		printf("奥林匹克公园");
	if (que[1] == 89)
		printf("奥体中心");
	if (que[1] == 90)
		printf("安华桥");
	if (que[1] == 91)
		printf("什刹海");
	if (que[1] == 92)
		printf("白堆子");
	if (que[1] == 93)
		printf("北京西站");
	if (que[1] == 94)
		printf("六里桥东");
	if (que[1] == 95)
		printf("丰台东大街");
	if (que[1] == 96)
		printf("丰台南路");
	if (que[1] == 97)
		printf("科怡路");
	if (que[1] == 98)
		printf("丰台科技园");
	if (que[1] == 99)
		printf("泥洼");
	if (que[1] == 100)
		printf("丰台站");
	if (que[1] == 101)
		printf("首经贸");
	if (que[1] == 102)
		printf("纪家庙");
	if (que[1] == 103)
		printf("草桥");
	if (que[1] == 104)
		printf("角门东");
	if (que[1] == 105)
		printf("大红门");
	if (que[1] == 106)
		printf("石榴庄");
	if (que[1] == 107)
		printf("成寿寺");
	if (que[1] == 108)
		printf("分钟寺");
	if (que[1] == 109)
		printf("十里河");
	if (que[1] == 110)
		printf("潘家园");
	if (que[1] == 111)
		printf("劲松");
	if (que[1] == 112)
		printf("双井");
	if (que[1] == 113)
		printf("金台夕照");
	if (que[1] == 114)
		printf("团结湖");
	if (que[1] == 115)
		printf("农业展览馆");
	if (que[1] == 116)
		printf("亮马桥");
	if (que[1] == 117)
		printf("太阳宫");
	if (que[1] == 118)
		printf("安贞门");
	if (que[1] == 119)
		printf("建德门");
	if (que[1] == 120)
		printf("牡丹园");
	if (que[1] == 121)
		printf("西土城");
	if (que[1] == 122)
		printf("知春里");
	if (que[1] == 123)
		printf("苏州街");
	if (que[1] == 124)
		printf("巴沟");
	if (que[1] == 125)
		printf("火器营");
	if (que[1] == 126)
		printf("长春桥");
	if (que[1] == 127)
		printf("车道沟");
	if (que[1] == 128)
		printf("西钓鱼台");
	if (que[1] == 129)
		printf("莲花桥");
	if (que[1] == 130)
		printf("大钟寺");
	if (que[1] == 131)
		printf("西道口");
	if (que[1] == 132)
		printf("上地");
	if (que[1] == 133)
		printf("龙泽");
	if (que[1] == 134)
		printf("回龙观");
	if (que[1] == 135)
		printf("北苑");
	if (que[1] == 136)
		printf("光熙门");
	if (que[1] == 137)
		printf("柳芳");
	if (que[1] == 138)
		printf("张郭庄");
	if (que[1] == 139)
		printf("园博园");
	if (que[1] == 140)
		printf("大瓦窑");
	if (que[1] == 141)
		printf("郭庄子");
	if (que[1] == 142)
		printf("大井");
	if (que[1] == 143)
		printf("俸伯");
	if (que[1] == 144)
		printf("顺义");
	if (que[1] == 145)
		printf("石门");
	if (que[1] == 146)
		printf("南法信");
	if (que[1] == 147)
		printf("后沙峪");
	if (que[1] == 148)
		printf("花梨坎");
	if (que[1] == 149)
		printf("国展");
	if (que[1] == 150)
		printf("孙河");
	if (que[1] == 151)
		printf("马泉营");
	if (que[1] == 152)
		printf("崔各庄");
	if (que[1] == 153)
		printf("望京");
	if (que[1] == 154)
		printf("高碑店");
	if (que[1] == 155)
		printf("传媒大学");
	if (que[1] == 156)
		printf("双桥");
	if (que[1] == 157)
		printf("管庄");
	if (que[1] == 158)
		printf("八里桥");
	if (que[1] == 159)
		printf("通州北苑");
	if (que[1] == 160)
		printf("果园");
	if (que[1] == 161)
		printf("九棵树");
	if (que[1] == 162)
		printf("梨园");
	if (que[1] == 163)
		printf("临河里");
	if (que[1] == 164)
		printf("土桥");
	if (que[1] == 165)
		printf("南邵");
	if (que[1] == 166)
		printf("沙河高教园");
	if (que[1] == 167)
		printf("沙河");
	if (que[1] == 168)
		printf("巩华城");
	if (que[1] == 169)
		printf("生命科学园");
	if (que[1] == 170)
		printf("肖村");
	if (que[1] == 171)
		printf("小红门");
	if (que[1] == 172)
		printf("旧宫");
	if (que[1] == 173)
		printf("亦庄桥");
	if (que[1] == 174)
		printf("亦庄文化园");
	if (que[1] == 175)
		printf("万源街");
	if (que[1] == 176)
		printf("荣京东街");
	if (que[1] == 177)
		printf("荣昌东街");
	if (que[1] == 178)
		printf("同济南路");
	if (que[1] == 179)
		printf("经海路");
	if (que[1] == 180)
		printf("次渠南");
	if (que[1] == 181)
		printf("次渠");
	if (que[1] == 182)
		printf("苏庄");
	if (que[1] == 183)
		printf("良乡南关");
	if (que[1] == 184)
		printf("良乡大学城西");
	if (que[1] == 185)
		printf("良乡大学城");
	if (que[1] == 186)
		printf("良乡大学城北");
	if (que[1] == 187)
		printf("广阳城");
	if (que[1] == 188)
		printf("篱笆房");
	if (que[1] == 189)
		printf("长阳");
	if (que[1] == 190)
		printf("稻田");
	if (que[1] == 191)
		printf("大葆台");
	if (que[1] == 192)
		printf("T2航站楼");
	if (que[1] == 193)
		printf("T3航站楼");
	if (que[1] == 194)
		printf("宣武门");
	if (que[1] == 195)
		printf("西单");
	if (que[1] == 196)
		printf("公主坟");
	if (que[1] == 197)
		printf("军事博物馆");
	if (que[1] == 198)
		printf("复兴门");
	if (que[1] == 199)
		printf("东单");
	if (que[1] == 200)
		printf("建国门");
	if (que[1] == 201)
		printf("国贸");
	if (que[1] == 202)
		printf("四惠东");
	if (que[1] == 203)
		printf("崇文门");
	if (que[1] == 204)
		printf("朝阳门");
	if (que[1] == 205)
		printf("东直门");
	if (que[1] == 206)
		printf("雍和宫");
	if (que[1] == 207)
		printf("鼓楼大街");
	if (que[1] == 208)
		printf("西直门");
	if (que[1] == 209)
		printf("车公庄");
	if (que[1] == 210)
		printf("海淀黄庄");
	if (que[1] == 211)
		printf("国家图书馆");
	if (que[1] == 212)
		printf("平安里");
	if (que[1] == 213)
		printf("角门西");
	if (que[1] == 214)
		printf("立水桥");
	if (que[1] == 215)
		printf("惠新西街南口");
	if (que[1] == 216)
		printf("东四");
	if (que[1] == 217)
		printf("宋家庄");
	if (que[1] == 218)
		printf("慈寿寺");
	if (que[1] == 219)
		printf("白石桥南");
	if (que[1] == 220)
		printf("南锣巷鼓");
	if (que[1] == 221)
		printf("呼家楼");
	if (que[1] == 222)
		printf("朱辛庄");
	if (que[1] == 223)
		printf("霍营");
	if (que[1] == 224)
		printf("北土城");
	if (que[1] == 225)
		printf("六里桥");
	if (que[1] == 226)
		printf("七里庄");
	if (que[1] == 227)
		printf("郭公庄");
	if (que[1] == 228)
		printf("三元桥");
	if (que[1] == 229)
		printf("芍药居");
	if (que[1] == 230)
		printf("知春路");
	if (que[1] == 231)
		printf("西局");
	if (que[1] == 232)
		printf("西二旗");
	if (que[1] == 233)
		printf("望西京");
	

	//**************************************************************************************************************************************************
}

int main()
{
	printf("欢迎使用北京地铁站\n这里为你提供最短路径查询\n更新时间   6/16/2014 (by cheng)\n");
	int dist[10000];     // 表示当前点到源点的最短路径长度
	int prev[10000];     // 记录当前点的前一个结点
	int c[300][300];   // 记录图的两点间路径长度
	int n;             // 图的结点数和路径数

	// 输入结点数
	n = 233;

	int p, q;          // 输入p, q两点及其路径长度

	// 初始化c[][]为maxint
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
		c[i][j] = maxint;


	//*************************************************************************************************************************************************

	//路径的输入！！！！

	//一号线


	//表示压力山大的分隔符   
	{
		p = 1, q = 2;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 2, q = 3;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 3, q = 4;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 4, q = 5;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 5, q = 6;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 6, q = 7;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 7, q = 196;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 196, q = 197;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 197, q = 8;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 8, q = 9;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 9, q = 198;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 198, q = 195;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 195, q = 10;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 10, q = 11;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 11, q = 12;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 12, q = 199;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 199, q = 200;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 200, q = 13;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 13, q = 201;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 201, q = 14;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 14, q = 15;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 15, q = 202;
		c[p][q] = 1;
		c[q][p] = 1;
	}



	//2号线



	//表示压力山大的分隔符   
	{
		p = 16, q = 203;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 203, q = 17;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 17, q = 200;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 200, q = 204;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 204, q = 18;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 18, q = 205;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 205, q = 206;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 206, q = 19;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 19, q = 207;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 207, q = 20;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 20, q = 208;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 208, q = 209;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 209, q = 21;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 21, q = 198;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 198, q = 22;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 22, q = 194;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 194, q = 23;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 23, q = 16;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//4号大兴线


	//表示压力山大的分隔符   
	{
		p = 24, q = 25;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 25, q = 26;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 26, q = 27;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 27, q = 28;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 28, q = 29;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 29, q = 210;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 210, q = 30;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 30, q = 31;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 31, q = 211;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 211, q = 32;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 32, q = 208;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 208, q = 33;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 33, q = 212;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 212, q = 34;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 34, q = 35;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 35, q = 195;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 195, q = 194;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 194, q = 36;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 36, q = 37;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 37, q = 38;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 38, q = 39;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 39, q = 213;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 213, q = 40;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 40, q = 41;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 41, q = 42;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 42, q = 43;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 43, q = 44;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 44, q = 45;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 45, q = 46;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 46, q = 47;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 47, q = 48;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 48, q = 49;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 49, q = 50;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 50, q = 51;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//5号线


	//表示压力山大的分隔符   
	{
		p = 52, q = 53;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 53, q = 54;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 54, q = 214;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 214, q = 55;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 55, q = 56;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 56, q = 57;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 57, q = 58;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 58, q = 215;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 215, q = 59;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 59, q = 60;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 60, q = 206;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 206, q = 61;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 61, q = 62;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 62, q = 216;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 216, q = 63;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 63, q = 199;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 199, q = 203;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 203, q = 64;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 64, q = 65;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 65, q = 66;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 66, q = 67;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 67, q = 217;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//6号线



	//表示压力山大的分隔符   
	{
		p = 68, q = 218;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 218, q = 69;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 69, q = 219;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 219, q = 70;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 70, q = 209;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 209, q = 212;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 212, q = 71;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 71, q = 220;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 220, q = 216;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 216, q = 204;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 204, q = 72;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 72, q = 221;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 221, q = 73;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 73, q = 74;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 74, q = 75;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 75, q = 76;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 76, q = 77;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 77, q = 78;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 78, q = 79;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//8号线

	//表示压力山大的分隔符   
	{
		p = 222, q = 80;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 80, q = 81;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 81, q = 82;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 82, q = 223;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 223, q = 83;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 83, q = 84;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 84, q = 85;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 85, q = 86;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 86, q = 87;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 87, q = 88;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 88, q = 89;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 89, q = 224;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 224, q = 90;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 90, q = 207;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 207, q = 91;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 91, q = 220;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//9号线



	//表示压力山大的分隔符   
	{
		p = 211, q = 219;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 219, q = 92;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 92, q = 197;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 197, q = 93;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 93, q = 94;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 94, q = 225;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 225, q = 226;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 226, q = 95;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 95, q = 96;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 96, q = 97;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 97, q = 98;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 98, q = 227;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//亚历山大的10号线 啊啊啊啊啊啊啊啊


	//表示压力山大的分隔符   
	{
		p = 99, q = 100;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 100, q = 101;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 101, q = 102;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 102, q = 103;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 103, q = 213;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 213, q = 104;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 104, q = 105;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 105, q = 106;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 106, q = 217;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 217, q = 107;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 107, q = 108;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 108, q = 109;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 109, q = 110;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 110, q = 111;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 111, q = 112;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 112, q = 201;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 201, q = 113;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 113, q = 221;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 221, q = 114;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 114, q = 115;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 115, q = 116;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 116, q = 228;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 228, q = 117;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 117, q = 229;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 229, q = 215;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 215, q = 118;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 118, q = 224;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 224, q = 119;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 119, q = 120;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 120, q = 121;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 121, q = 230;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 230, q = 122;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 122, q = 210;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 210, q = 123;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 123, q = 124;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 124, q = 125;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 125, q = 126;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 126, q = 127;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 127, q = 218;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 218, q = 128;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 128, q = 196;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 196, q = 129;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 129, q = 225;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 225, q = 231;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 231, q = 99;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//13号线



	//表示压力山大的分隔符   
	{
		p = 208, q = 130;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 130, q = 230;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 230, q = 131;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 131, q = 132;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 132, q = 232;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 232, q = 133;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 133, q = 134;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 134, q = 223;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 223, q = 214;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 214, q = 135;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 135, q = 233;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 233, q = 229;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 229, q = 136;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 136, q = 137;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 137, q = 205;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//14号线

	//表示压力山大的分隔符   
	{
		p = 138, q = 139;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 139, q = 140;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 140, q = 141;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 141, q = 142;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 142, q = 226;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 226, q = 231;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//15号线


	//表示压力山大的分隔符   
	{
		p = 143, q = 144;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 144, q = 145;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 145, q = 146;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 146, q = 147;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 147, q = 148;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 148, q = 149;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 149, q = 150;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 150, q = 151;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 151, q = 152;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 152, q = 153;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 153, q = 233;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//八通线



	//表示压力山大的分隔符   
	{
		p = 202, q = 154;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 154, q = 155;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 155, q = 156;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 156, q = 157;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 157, q = 158;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 158, q = 159;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 159, q = 160;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 160, q = 161;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 161, q = 162;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 162, q = 163;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 163, q = 164;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//昌平线


	//表示压力山大的分隔符   
	{
		p = 165, q = 166;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 166, q = 167;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 167, q = 168;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 168, q = 222;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 222, q = 169;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 169, q = 232;
		c[p][q] = 1;
		c[q][p] = 1;
	}



	//亦庄线



	//表示压力山大的分隔符   
	{
		p = 217, q = 170;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 170, q = 171;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 171, q = 172;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 172, q = 173;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 173, q = 174;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 174, q = 175;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 175, q = 176;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 176, q = 177;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 177, q = 178;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 178, q = 179;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 179, q = 180;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 180, q = 181;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//房山线


	//表示压力山大的分隔符   
	{
		p = 182, q = 183;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 183, q = 184;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 184, q = 185;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 185, q = 186;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 186, q = 187;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//表示压力山大的分隔符   
	{
		p = 187, q = 188;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 188, q = 189;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 189, q = 190;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 190, q = 191;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 191, q = 227;
		c[p][q] = 1;
		c[q][p] = 1;
	}


	//机场线


	//表示压力山大的分隔符   
	{
		p = 205, q = 228;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 228, q = 192;
		c[p][q] = 1;
		c[q][p] = 1;
	}

	//表示压力山大的分隔符   
	{
		p = 228, q = 193;
		c[p][q] = 1;
		c[q][p] = 1;
	}
	//表示压力山大的分隔符   
	{
		p = 192, q = 193;
		c[p][q] = 1;
		c[q][p] = 1;
	}



	//************************************************************************************************************************************************************************************


	//起始地址和终点的输入
	int a1, a2;
	char z[20], x[20];

	int asd = 1;

	while (asd)
	{

		printf("请输入起点\n");
		gets_s(z, 20);



		//******************************************************************************************************************************************************************************************


		//起点
		while (1)
		{

			//1号线的输入！！！！！！！！
			if (0 == (strcmp(z, "苹果园")))
			{
				a1 = 1;
				break;
			}

			if (0 == (strcmp(z, "古城")))
			{
				a1 = 2;
				break;
			}

			if (0 == (strcmp(z, "八角游乐园")))
			{
				a1 = 3;
				break;
			}


			if (0 == (strcmp(z, "八宝山")))
			{
				a1 = 4;
				break;
			}
			if (0 == (strcmp(z, "玉泉路")))
			{
				a1 = 5;
				break;
			}

			if (0 == (strcmp(z, "五棵松")))
			{
				a1 = 6;
				break;
			}

			if (0 == (strcmp(z, "万寿路")))
			{
				a1 = 7;
				break;
			}


			if (0 == (strcmp(z, "木樨地")))
			{
				a1 = 8;
				break;
			}

			if (0 == (strcmp(z, "南礼士路")))
			{
				a1 = 9;
				break;
			}

			if (0 == (strcmp(z, "天安门西")))
			{
				a1 = 10;
				break;
			}

			if (0 == (strcmp(z, "天安门东")))
			{
				a1 = 11;
				break;
			}

			if (0 == (strcmp(z, "王府井")))
			{
				a1 = 12;
				break;
			}

			if (0 == (strcmp(z, "永安里")))
			{
				a1 = 13;
				break;
			}

			if (0 == (strcmp(z, "大望路")))
			{
				a1 = 14;
				break;
			}

			if (0 == (strcmp(z, "四惠")))
			{
				a1 = 15;
				break;
			}


			//2号线


			if (0 == (strcmp(z, "前门")))
			{
				a1 = 16;
				break;
			}

			if (0 == (strcmp(z, "北京站")))
			{
				a1 = 17;
				break;
			}
			if (0 == (strcmp(z, "东四十条")))
			{
				a1 = 18;
				break;
			}


			if (0 == (strcmp(z, "安定门")))
			{
				a1 = 19;
				break;
			}

			if (0 == (strcmp(z, "积水潭")))
			{
				a1 = 20;
				break;
			}

			if (0 == (strcmp(z, "阜成门")))
			{
				a1 = 21;
				break;
			}


			if (0 == (strcmp(z, "长椿街")))
			{
				a1 = 22;
				break;
			}

			if (0 == (strcmp(z, "和平门")))
			{
				a1 = 23;
				break;
			}



			//4号大兴线





			if (0 == (strcmp(z, "安河桥北")))
			{
				a1 = 24;
				break;
			}

			if (0 == (strcmp(z, "北宫门")))
			{
				a1 = 25;
				break;
			}
			if (0 == (strcmp(z, "西苑")))
			{
				a1 = 26;
				break;
			}

			if (0 == (strcmp(z, "圆明园")))
			{
				a1 = 27;
				break;
			}
			if (0 == (strcmp(z, "北京大学东门")))
			{
				a1 = 28;
				break;
			}

			if (0 == (strcmp(z, "中关村")))
			{
				a1 = 29;
				break;
			}

			if (0 == (strcmp(z, "人民大学")))
			{
				a1 = 30;
				break;
			}

			if (0 == (strcmp(z, "魏公村")))
			{
				a1 = 31;
				break;
			}

			if (0 == (strcmp(z, "动物园")))
			{
				a1 = 32;
				break;
			}

			if (0 == (strcmp(z, "新街口")))
			{
				a1 = 33;
				break;
			}


			if (0 == (strcmp(z, "西四")))
			{
				a1 = 34;
				break;
			}

			if (0 == (strcmp(z, "灵境胡同")))
			{
				a1 = 35;
				break;
			}

			if (0 == (strcmp(z, "菜市口")))
			{
				a1 = 36;
				break;
			}

			if (0 == (strcmp(z, "陶然亭")))
			{
				a1 = 37;
				break;
			}


			if (0 == (strcmp(z, "北京南站")))
			{
				a1 = 38;
				break;
			}

			if (0 == (strcmp(z, "马字堡")))
			{
				a1 = 39;
				break;
			}

			if (0 == (strcmp(z, "公益西桥")))
			{
				a1 = 40;
				break;
			}

			if (0 == (strcmp(z, "新宫")))
			{
				a1 = 41;
				break;
			}

			if (0 == (strcmp(z, "西红门")))
			{
				a1 = 42;
				break;
			}

			if (0 == (strcmp(z, "高米店北")))
			{
				a1 = 43;
				break;
			}

			if (0 == (strcmp(z, "高米店南")))
			{
				a1 = 44;
				break;
			}
			if (0 == (strcmp(z, "枣园")))
			{
				a1 = 45;
				break;
			}

			if (0 == (strcmp(z, "清源路")))
			{
				a1 = 46;
				break;
			}

			if (0 == (strcmp(z, "黄村西大街")))
			{
				a1 = 47;
				break;
			}

			if (0 == (strcmp(z, "黄村火车站")))
			{
				a1 = 48;
				break;
			}

			if (0 == (strcmp(z, "义和庄")))
			{
				a1 = 49;
				break;
			}

			if (0 == (strcmp(z, "生物医药基地")))
			{
				a1 = 50;
				break;
			}

			if (0 == (strcmp(z, "天宫院")))
			{
				a1 = 51;
				break;
			}




			//5号线



			if (0 == (strcmp(z, "天通苑北")))
			{
				a1 = 52;
				break;
			}


			if (0 == (strcmp(z, "天通苑")))
			{
				a1 = 53;
				break;
			}
			if (0 == (strcmp(z, "天通苑南")))
			{
				a1 = 54;
				break;
			}

			if (0 == (strcmp(z, "立水桥南")))
			{
				a1 = 55;
				break;
			}

			if (0 == (strcmp(z, "北苑路北")))
			{
				a1 = 56;
				break;
			}

			if (0 == (strcmp(z, "大屯路东")))
			{
				a1 = 57;
				break;
			}

			if (0 == (strcmp(z, "惠新西街北口")))
			{
				a1 = 58;
				break;
			}

			if (0 == (strcmp(z, "和平西桥")))
			{
				a1 = 59;
				break;
			}

			if (0 == (strcmp(z, "和平里北街")))
			{
				a1 = 60;
				break;
			}

			if (0 == (strcmp(z, "北新桥")))
			{
				a1 = 61;
				break;
			}


			if (0 == (strcmp(z, "张自忠路")))
			{
				a1 = 62;
				break;
			}

			if (0 == (strcmp(z, "灯市口")))
			{
				a1 = 63;
				break;
			}

			if (0 == (strcmp(z, "磁器口")))
			{
				a1 = 64;
				break;
			}

			if (0 == (strcmp(z, "天坛东门")))
			{
				a1 = 65;
				break;
			}

			if (0 == (strcmp(z, "蒲黄榆")))
			{
				a1 = 66;
				break;
			}
			if (0 == (strcmp(z, "刘家窑")))
			{
				a1 = 67;
				break;
			}



			//6号线




			if (0 == (strcmp(z, "海淀五路居")))
			{
				a1 = 68;
				break;
			}


			if (0 == (strcmp(z, "花园桥")))
			{
				a1 = 69;
				break;
			}

			if (0 == (strcmp(z, "车公庄西")))
			{
				a1 = 70;
				break;
			}

			if (0 == (strcmp(z, "北海北")))
			{
				a1 = 71;
				break;
			}


			if (0 == (strcmp(z, "东大桥")))
			{
				a1 = 72;
				break;
			}

			if (0 == (strcmp(z, "金台路")))
			{
				a1 = 73;
				break;
			}


			if (0 == (strcmp(z, "十里堡")))
			{
				a1 = 74;
				break;
			}

			if (0 == (strcmp(z, "青年路")))
			{
				a1 = 75;
				break;
			}

			if (0 == (strcmp(z, "褡裢坡")))
			{
				a1 = 76;
				break;
			}

			if (0 == (strcmp(z, "黄渠")))
			{
				a1 = 77;
				break;
			}

			if (0 == (strcmp(z, "常营")))
			{
				a1 = 78;
				break;
			}

			if (0 == (strcmp(z, "草房")))
			{
				a1 = 79;
				break;
			}


			//8号线


			if (0 == (strcmp(z, "育知路")))
			{
				a1 = 80;
				break;
			}

			if (0 == (strcmp(z, "平西府")))
			{
				a1 = 81;
				break;
			}

			if (0 == (strcmp(z, "回龙观东大街")))
			{
				a1 = 82;
				break;
			}

			if (0 == (strcmp(z, "育新")))
			{
				a1 = 83;
				break;
			}
			if (0 == (strcmp(z, "西小口")))
			{
				a1 = 84;
				break;
			}

			if (0 == (strcmp(z, "永泰庄")))
			{
				a1 = 85;
				break;
			}

			if (0 == (strcmp(z, "林萃桥")))
			{
				a1 = 86;
				break;
			}

			if (0 == (strcmp(z, "森林公园南门")))
			{
				a1 = 87;
				break;
			}
			if (0 == (strcmp(z, "奥林匹克公园")))
			{
				a1 = 88;
				break;
			}

			if (0 == (strcmp(z, "奥体中心")))
			{
				a1 = 89;
				break;
			}

			if (0 == (strcmp(z, "安华桥")))
			{
				a1 = 90;
				break;
			}

			if (0 == (strcmp(z, "什刹海")))
			{
				a1 = 91;
				break;
			}

			//9号线


			if (0 == (strcmp(z, "白堆子")))
			{
				a1 = 92;
				break;
			}

			if (0 == (strcmp(z, "北京西站")))
			{
				a1 = 93;
				break;
			}

			if (0 == (strcmp(z, "六里桥东")))
			{
				a1 = 94;
				break;
			}
			if (0 == (strcmp(z, "丰台东大街")))
			{
				a1 = 95;
				break;
			}

			if (0 == (strcmp(z, "丰台南路")))
			{
				a1 = 96;
				break;
			}
			if (0 == (strcmp(z, "科怡路")))
			{
				a1 = 97;
				break;
			}
			if (0 == (strcmp(z, "丰台科技园")))
			{
				a1 = 98;
				break;
			}



			//悲催的十号线


			if (0 == (strcmp(z, "泥洼")))
			{
				a1 = 99;
				break;
			}
			if (0 == (strcmp(z, "丰台站")))
			{
				a1 = 100;
				break;
			}
			if (0 == (strcmp(z, "首经贸")))
			{
				a1 = 101;
				break;
			}
			if (0 == (strcmp(z, "纪家庙")))
			{
				a1 = 102;
				break;
			}
			if (0 == (strcmp(z, "草桥")))
			{
				a1 = 103;
				break;
			}
			if (0 == (strcmp(z, "角门东")))
			{
				a1 = 104;
				break;
			}

			if (0 == (strcmp(z, "大红门")))
			{
				a1 = 105;
				break;
			}
			if (0 == (strcmp(z, "石榴庄")))
			{
				a1 = 106;
				break;
			}
			if (0 == (strcmp(z, "成寿寺")))
			{
				a1 = 107;
				break;
			}

			if (0 == (strcmp(z, "分钟寺")))
			{
				a1 = 108;
				break;
			}
			if (0 == (strcmp(z, "十里河")))
			{
				a1 = 109;
				break;
			}
			if (0 == (strcmp(z, "潘家园")))
			{
				a1 = 110;
				break;
			}
			if (0 == (strcmp(z, "劲松")))
			{
				a1 = 111;
				break;
			}
			if (0 == (strcmp(z, "双井")))
			{
				a1 = 112;
				break;
			}
			if (0 == (strcmp(z, "金台夕照")))
			{
				a1 = 113;
				break;
			}
			if (0 == (strcmp(z, "团结湖")))
			{
				a1 = 114;
				break;
			}
			if (0 == (strcmp(z, "农业展览馆")))
			{
				a1 = 115;
				break;
			}
			if (0 == (strcmp(z, "亮马桥")))
			{
				a1 = 116;
				break;
			}
			if (0 == (strcmp(z, "太阳宫")))
			{
				a1 = 117;
				break;
			}

			if (0 == (strcmp(z, "安贞门")))
			{
				a1 = 118;
				break;
			}

			if (0 == (strcmp(z, "建德门")))
			{
				a1 = 119;
				break;
			}
			if (0 == (strcmp(z, "牡丹园")))
			{
				a1 = 120;
				break;
			}
			if (0 == (strcmp(z, "西土城")))
			{
				a1 = 121;
				break;
			}
			if (0 == (strcmp(z, "知春里")))
			{
				a1 = 122;
				break;
			}

			if (0 == (strcmp(z, "苏州街")))
			{
				a1 = 123;
				break;
			}

			if (0 == (strcmp(z, "巴沟")))
			{
				a1 = 124;
				break;
			}

			if (0 == (strcmp(z, "火器营")))
			{
				a1 = 125;
				break;
			}

			if (0 == (strcmp(z, "长春桥")))
			{
				a1 = 126;
				break;
			}

			if (0 == (strcmp(z, "车道沟")))
			{
				a1 = 127;
				break;
			}

			if (0 == (strcmp(z, "西钓鱼桥")))
			{
				a1 = 128;
				break;
			}
			if (0 == (strcmp(z, "莲花桥")))
			{
				a1 = 129;
				break;
			}


			//13号线


			if (0 == (strcmp(z, "大钟寺")))
			{
				a1 = 130;
				break;
			}

			if (0 == (strcmp(z, "五道口")))
			{
				a1 = 131;
				break;
			}
			if (0 == (strcmp(z, "上地")))
			{
				a1 = 132;
				break;
			}
			if (0 == (strcmp(z, "龙泽")))
			{
				a1 = 133;
				break;
			}
			if (0 == (strcmp(z, "回龙观")))
			{
				a1 = 134;
				break;
			}

			if (0 == (strcmp(z, "北苑")))
			{
				a1 = 135;
				break;
			}
			if (0 == (strcmp(z, "光熙门")))
			{
				a1 = 136;
				break;
			}

			if (0 == (strcmp(z, "柳芳")))
			{
				a1 = 137;
				break;
			}

			//14号线


			if (0 == (strcmp(z, "张郭庄")))
			{
				a1 = 138;
				break;
			}

			if (0 == (strcmp(z, "园博园")))
			{
				a1 = 139;
				break;
			}

			if (0 == (strcmp(z, "大瓦窑")))
			{
				a1 = 140;
				break;
			}

			if (0 == (strcmp(z, "郭庄子")))
			{
				a1 = 141;
				break;
			}

			if (0 == (strcmp(z, "大井")))
			{
				a1 = 142;
				break;
			}


			//15号线


			if (0 == (strcmp(z, "俸伯")))
			{
				a1 = 143;
				break;
			}

			if (0 == (strcmp(z, "顺义")))
			{
				a1 = 144;
				break;
			}

			if (0 == (strcmp(z, "石门")))
			{
				a1 = 145;
				break;
			}

			if (0 == (strcmp(z, "南法信")))
			{
				a1 = 146;
				break;
			}

			if (0 == (strcmp(z, "后沙峪")))
			{
				a1 = 147;
				break;
			}
			if (0 == (strcmp(z, "花梨坎")))
			{
				a1 = 148;
				break;
			}
			if (0 == (strcmp(z, "国展")))
			{
				a1 = 149;
				break;
			}
			if (0 == (strcmp(z, "孙河")))
			{
				a1 = 150;
				break;
			}

			if (0 == (strcmp(z, "马泉营")))
			{
				a1 = 151;
				break;
			}

			if (0 == (strcmp(z, "崔各庄")))
			{
				a1 = 152;
				break;
			}

			if (0 == (strcmp(z, "望京")))
			{
				a1 = 153;
				break;
			}


			//八通线


			if (0 == (strcmp(z, "高碑店")))
			{
				a1 = 154;
				break;
			}

			if (0 == (strcmp(z, "传媒大学")))
			{
				a1 = 155;
				break;
			}

			if (0 == (strcmp(z, "双桥")))
			{
				a1 = 156;
				break;
			}

			if (0 == (strcmp(z, "管庄")))
			{
				a1 = 157;
				break;
			}
			if (0 == (strcmp(z, "八里桥")))
			{
				a1 = 158;
				break;
			}

			if (0 == (strcmp(z, "通州北苑")))
			{
				a1 = 159;
				break;
			}

			if (0 == (strcmp(z, "果园")))
			{
				a1 = 160;
				break;
			}

			if (0 == (strcmp(z, "九棵树")))
			{
				a1 = 161;
				break;
			}

			if (0 == (strcmp(z, "梨园")))
			{
				a1 = 162;
				break;
			}

			if (0 == (strcmp(z, "临河里")))
			{
				a1 = 163;
				break;
			}

			if (0 == (strcmp(z, "土桥")))
			{
				a1 = 164;
				break;
			}

			//昌平线

			if (0 == (strcmp(z, "南邵")))
			{
				a1 = 165;
				break;
			}

			if (0 == (strcmp(z, "沙河高教园")))
			{
				a1 = 166;
				break;
			}

			if (0 == (strcmp(z, "沙河")))
			{
				a1 = 167;
				break;
			}
			if (0 == (strcmp(z, "巩华城")))
			{
				a1 = 168;
				break;
			}

			if (0 == (strcmp(z, "生命科学园")))
			{
				a1 = 169;
				break;
			}


			//亦庄线


			if (0 == (strcmp(z, "肖村")))
			{
				a1 = 170;
				break;
			}
			if (0 == (strcmp(z, "小红门")))
			{
				a1 = 171;
				break;
			}
			if (0 == (strcmp(z, "旧宫")))
			{
				a1 = 172;
				break;
			}
			if (0 == (strcmp(z, "亦庄桥")))
			{
				a1 = 173;
				break;
			}

			if (0 == (strcmp(z, "亦庄文化园")))
			{
				a1 = 174;
				break;
			}

			if (0 == (strcmp(z, "万源街")))
			{
				a1 = 175;
				break;
			}

			if (0 == (strcmp(z, "荣京东街")))
			{
				a1 = 176;
				break;
			}

			if (0 == (strcmp(z, "荣昌东街")))
			{
				a1 = 177;
				break;
			}

			if (0 == (strcmp(z, "同济南路")))
			{
				a1 = 178;
				break;
			}

			if (0 == (strcmp(z, "经海路")))
			{
				a1 = 179;
				break;
			}

			if (0 == (strcmp(z, "次渠南")))
			{
				a1 = 180;
				break;
			}

			if (0 == (strcmp(z, "次渠")))
			{
				a1 = 181;
				break;
			}


			//房山线


			if (0 == (strcmp(z, "苏庄")))
			{
				a1 = 182;
				break;
			}

			if (0 == (strcmp(z, "良乡南关")))
			{
				a1 = 183;
				break;
			}

			if (0 == (strcmp(z, "良乡大学城西")))
			{
				a1 = 184;
				break;
			}
			if (0 == (strcmp(z, "良乡大学城")))
			{
				a1 = 185;
				break;
			}
			if (0 == (strcmp(z, "良乡大学城北")))
			{
				a1 = 186;
				break;
			}
			if (0 == (strcmp(z, "广阳城")))
			{
				a1 = 187;
				break;
			}

			if (0 == (strcmp(z, "篱笆房")))
			{
				a1 = 188;
				break;
			}
			if (0 == (strcmp(z, "长阳")))
			{
				a1 = 189;
				break;
			}

			if (0 == (strcmp(z, "稻田")))
			{
				a1 = 190;
				break;
			}

			if (0 == (strcmp(z, "大葆台")))
			{
				a1 = 191;
				break;
			}

			//机场线


			if (0 == (strcmp(z, "T2航站楼")))
			{
				a1 = 192;
				break;
			}

			if (0 == (strcmp(z, "T3航站楼")))
			{
				a1 = 193;
				break;
			}


			//交点的插入

			if (0 == (strcmp(z, "宣武门")))
			{
				a1 = 194;
				break;
			}

			if (0 == (strcmp(z, "西单")))
			{
				a1 = 195;
				break;
			}

			if (0 == (strcmp(z, "公主坟")))
			{
				a1 = 196;
				break;
			}
			if (0 == (strcmp(z, "军事博物馆")))
			{
				a1 = 197;
				break;
			}

			if (0 == (strcmp(z, "复兴门")))
			{
				a1 = 198;
				break;
			}

			if (0 == (strcmp(z, "东单")))
			{
				a1 = 199;
				break;
			}

			if (0 == (strcmp(z, "建国门")))
			{
				a1 = 200;
				break;
			}
			if (0 == (strcmp(z, "国贸")))
			{
				a1 = 201;
				break;
			}
			if (0 == (strcmp(z, "四惠东")))
			{
				a1 = 202;
				break;
			}
			if (0 == (strcmp(z, "崇文门")))
			{
				a1 = 203;
				break;
			}
			if (0 == (strcmp(z, "朝阳门")))
			{
				a1 = 204;
				break;
			}

			if (0 == (strcmp(z, "东直门")))
			{
				a1 = 205;
				break;
			}

			if (0 == (strcmp(z, "雍和宫")))
			{
				a1 = 206;
				break;
			}

			if (0 == (strcmp(z, "鼓楼大街")))
			{
				a1 = 207;
				break;
			}

			if (0 == (strcmp(z, "西直门")))
			{
				a1 = 208;
				break;
			}

			if (0 == (strcmp(z, "车公庄")))
			{
				a1 = 209;
				break;
			}
			if (0 == (strcmp(z, "海淀黄庄")))
			{
				a1 = 210;
				break;
			}
			if (0 == (strcmp(z, "国家图书馆")))
			{
				a1 = 211;
				break;
			}
			if (0 == (strcmp(z, "平安里")))
			{
				a1 = 212;
				break;
			}
			if (0 == (strcmp(z, "角门西")))
			{
				a1 = 213;
				break;
			}

			if (0 == (strcmp(z, "立水桥")))
			{
				a1 = 214;
				break;
			}

			if (0 == (strcmp(z, "惠新西街南口")))
			{
				a1 = 215;
				break;
			}
			if (0 == (strcmp(z, "东四")))
			{
				a1 = 216;
				break;
			}

			if (0 == (strcmp(z, "宋家庄")))
			{
				a1 = 217;
				break;
			}

			if (0 == (strcmp(z, "慈寿寺")))
			{
				a1 = 218;
				break;
			}
			if (0 == (strcmp(z, "白石桥南")))
			{
				a1 = 219;
				break;
			}
			if (0 == (strcmp(z, "南锣巷鼓")))
			{
				a1 = 220;
				break;
			}
			if (0 == (strcmp(z, "呼家楼")))
			{
				a1 = 221;
				break;
			}
			if (0 == (strcmp(z, "朱辛庄")))
			{
				a1 = 222;
				break;
			}
			if (0 == (strcmp(z, "霍营")))
			{
				a1 = 223;
				break;
			}
			if (0 == (strcmp(z, "北土城")))
			{
				a1 = 224;
				break;
			}

			if (0 == (strcmp(z, "六里桥")))
			{
				a1 = 225;
				break;
			}
			if (0 == (strcmp(z, "七里庄")))
			{
				a1 = 226;
				break;
			}
			if (0 == (strcmp(z, "郭公庄")))
			{
				a1 = 227;
				break;
			}
			if (0 == (strcmp(z, "三元桥")))
			{
				a1 = 228;
				break;
			}
			if (0 == (strcmp(z, "芍药居")))
			{
				a1 = 229;
				break;
			}
			if (0 == (strcmp(z, "知春路")))
			{
				a1 = 230;
				break;
			}
			if (0 == (strcmp(z, "西局")))
			{
				a1 = 231;
				break;
			}

			if (0 == (strcmp(z, "西二旗")))
			{
				a1 = 232;
				break;
			}
			if (0 == (strcmp(z, "望京西")))
			{
				a1 = 233;
				break;
			}





			//输入错误循环！！！！
			printf("\n起点输入有误请重新输入\n");
			gets_s(z, 20);

		}



		//*************************************************************************************************************************************

		printf("请输入终点\n");
		gets_s(z, 20);


		//  终点的输入！！！！！！
		while (1)
		{

			//1号线的输入！！！！！！！！
			if (0 == (strcmp(z, "苹果园")))
			{
				a2 = 1;
				break;
			}

			if (0 == (strcmp(z, "古城")))
			{
				a2 = 2;
				break;
			}

			if (0 == (strcmp(z, "八角游乐园")))
			{
				a2 = 3;
				break;
			}


			if (0 == (strcmp(z, "八宝山")))
			{
				a2 = 4;
				break;
			}
			if (0 == (strcmp(z, "玉泉路")))
			{
				a2 = 5;
				break;
			}

			if (0 == (strcmp(z, "五棵松")))
			{
				a2 = 6;
				break;
			}

			if (0 == (strcmp(z, "万寿路")))
			{
				a2 = 7;
				break;
			}


			if (0 == (strcmp(z, "木樨地")))
			{
				a2 = 8;
				break;
			}

			if (0 == (strcmp(z, "南礼士路")))
			{
				a2 = 9;
				break;
			}

			if (0 == (strcmp(z, "天安门西")))
			{
				a2 = 10;
				break;
			}

			if (0 == (strcmp(z, "天安门东")))
			{
				a2 = 11;
				break;
			}

			if (0 == (strcmp(z, "王府井")))
			{
				a2 = 12;
				break;
			}

			if (0 == (strcmp(z, "永安里")))
			{
				a2 = 13;
				break;
			}

			if (0 == (strcmp(z, "大望路")))
			{
				a2 = 14;
				break;
			}

			if (0 == (strcmp(z, "四惠")))
			{
				a2 = 15;
				break;
			}


			//2号线


			if (0 == (strcmp(z, "前门")))
			{
				a2 = 16;
				break;
			}

			if (0 == (strcmp(z, "北京站")))
			{
				a2 = 17;
				break;
			}
			if (0 == (strcmp(z, "东四十条")))
			{
				a2 = 18;
				break;
			}


			if (0 == (strcmp(z, "安定门")))
			{
				a2 = 19;
				break;
			}

			if (0 == (strcmp(z, "积水潭")))
			{
				a2 = 20;
				break;
			}

			if (0 == (strcmp(z, "阜成门")))
			{
				a2 = 21;
				break;
			}


			if (0 == (strcmp(z, "长椿街")))
			{
				a2 = 22;
				break;
			}

			if (0 == (strcmp(z, "和平门")))
			{
				a2 = 23;
				break;
			}



			//4号大兴线





			if (0 == (strcmp(z, "安河桥北")))
			{
				a2 = 24;
				break;
			}

			if (0 == (strcmp(z, "北宫门")))
			{
				a2 = 25;
				break;
			}
			if (0 == (strcmp(z, "西苑")))
			{
				a2 = 26;
				break;
			}

			if (0 == (strcmp(z, "圆明园")))
			{
				a2 = 27;
				break;
			}
			if (0 == (strcmp(z, "北京大学东门")))
			{
				a2 = 28;
				break;
			}

			if (0 == (strcmp(z, "中关村")))
			{
				a2 = 29;
				break;
			}

			if (0 == (strcmp(z, "人民大学")))
			{
				a2 = 30;
				break;
			}

			if (0 == (strcmp(z, "魏公村")))
			{
				a2 = 31;
				break;
			}

			if (0 == (strcmp(z, "动物园")))
			{
				a2 = 32;
				break;
			}

			if (0 == (strcmp(z, "新街口")))
			{
				a2 = 33;
				break;
			}


			if (0 == (strcmp(z, "西四")))
			{
				a2 = 34;
				break;
			}

			if (0 == (strcmp(z, "灵境胡同")))
			{
				a2 = 35;
				break;
			}

			if (0 == (strcmp(z, "菜市口")))
			{
				a2 = 36;
				break;
			}

			if (0 == (strcmp(z, "陶然亭")))
			{
				a2 = 37;
				break;
			}


			if (0 == (strcmp(z, "北京南站")))
			{
				a2 = 38;
				break;
			}

			if (0 == (strcmp(z, "马字堡")))
			{
				a2 = 39;
				break;
			}

			if (0 == (strcmp(z, "公益西桥")))
			{
				a2 = 40;
				break;
			}

			if (0 == (strcmp(z, "新宫")))
			{
				a2 = 41;
				break;
			}

			if (0 == (strcmp(z, "西红门")))
			{
				a2 = 42;
				break;
			}

			if (0 == (strcmp(z, "高米店北")))
			{
				a2 = 43;
				break;
			}

			if (0 == (strcmp(z, "高米店南")))
			{
				a2 = 44;
				break;
			}
			if (0 == (strcmp(z, "枣园")))
			{
				a2 = 45;
				break;
			}

			if (0 == (strcmp(z, "清源路")))
			{
				a2 = 46;
				break;
			}

			if (0 == (strcmp(z, "黄村西大街")))
			{
				a2 = 47;
				break;
			}

			if (0 == (strcmp(z, "黄村火车站")))
			{
				a2 = 48;
				break;
			}

			if (0 == (strcmp(z, "义和庄")))
			{
				a2 = 49;
				break;
			}

			if (0 == (strcmp(z, "生物医药基地")))
			{
				a2 = 50;
				break;
			}

			if (0 == (strcmp(z, "天宫院")))
			{
				a2 = 51;
				break;
			}




			//5号线



			if (0 == (strcmp(z, "天通苑北")))
			{
				a2 = 52;
				break;
			}


			if (0 == (strcmp(z, "天通苑")))
			{
				a2 = 53;
				break;
			}
			if (0 == (strcmp(z, "天通苑南")))
			{
				a2 = 54;
				break;
			}

			if (0 == (strcmp(z, "立水桥南")))
			{
				a2 = 55;
				break;
			}

			if (0 == (strcmp(z, "北苑路北")))
			{
				a2 = 56;
				break;
			}

			if (0 == (strcmp(z, "大屯路东")))
			{
				a2 = 57;
				break;
			}

			if (0 == (strcmp(z, "惠新西街北口")))
			{
				a2 = 58;
				break;
			}

			if (0 == (strcmp(z, "和平西桥")))
			{
				a2 = 59;
				break;
			}

			if (0 == (strcmp(z, "和平里北街")))
			{
				a2 = 60;
				break;
			}

			if (0 == (strcmp(z, "北新桥")))
			{
				a2 = 61;
				break;
			}


			if (0 == (strcmp(z, "张自忠路")))
			{
				a2 = 62;
				break;
			}

			if (0 == (strcmp(z, "灯市口")))
			{
				a2 = 63;
				break;
			}

			if (0 == (strcmp(z, "磁器口")))
			{
				a2 = 64;
				break;
			}

			if (0 == (strcmp(z, "天坛东门")))
			{
				a2 = 65;
				break;
			}

			if (0 == (strcmp(z, "蒲黄榆")))
			{
				a2 = 66;
				break;
			}
			if (0 == (strcmp(z, "刘家窑")))
			{
				a2 = 67;
				break;
			}



			//6号线




			if (0 == (strcmp(z, "海淀五路居")))
			{
				a2 = 68;
				break;
			}


			if (0 == (strcmp(z, "花园桥")))
			{
				a2 = 69;
				break;
			}

			if (0 == (strcmp(z, "车公庄西")))
			{
				a2 = 70;
				break;
			}

			if (0 == (strcmp(z, "北海北")))
			{
				a2 = 71;
				break;
			}


			if (0 == (strcmp(z, "东大桥")))
			{
				a2 = 72;
				break;
			}

			if (0 == (strcmp(z, "金台路")))
			{
				a2 = 73;
				break;
			}


			if (0 == (strcmp(z, "十里堡")))
			{
				a2 = 74;
				break;
			}

			if (0 == (strcmp(z, "青年路")))
			{
				a2 = 75;
				break;
			}

			if (0 == (strcmp(z, "褡裢坡")))
			{
				a2 = 76;
				break;
			}

			if (0 == (strcmp(z, "黄渠")))
			{
				a2 = 77;
				break;
			}

			if (0 == (strcmp(z, "常营")))
			{
				a2 = 78;
				break;
			}

			if (0 == (strcmp(z, "草房")))
			{
				a2 = 79;
				break;
			}


			//8号线


			if (0 == (strcmp(z, "育知路")))
			{
				a2 = 80;
				break;
			}

			if (0 == (strcmp(z, "平西府")))
			{
				a2 = 81;
				break;
			}

			if (0 == (strcmp(z, "回龙观东大街")))
			{
				a2 = 82;
				break;
			}

			if (0 == (strcmp(z, "育新")))
			{
				a2 = 83;
				break;
			}
			if (0 == (strcmp(z, "西小口")))
			{
				a1 = 84;
				break;
			}

			if (0 == (strcmp(z, "永泰庄")))
			{
				a2 = 85;
				break;
			}

			if (0 == (strcmp(z, "林萃桥")))
			{
				a2 = 86;
				break;
			}

			if (0 == (strcmp(z, "森林公园南门")))
			{
				a2 = 87;
				break;
			}
			if (0 == (strcmp(z, "奥林匹克公园")))
			{
				a2 = 88;
				break;
			}

			if (0 == (strcmp(z, "奥体中心")))
			{
				a2 = 89;
				break;
			}

			if (0 == (strcmp(z, "安华桥")))
			{
				a2 = 90;
				break;
			}

			if (0 == (strcmp(z, "什刹海")))
			{
				a2 = 91;
				break;
			}

			//9号线


			if (0 == (strcmp(z, "白堆子")))
			{
				a2 = 92;
				break;
			}

			if (0 == (strcmp(z, "北京西站")))
			{
				a2 = 93;
				break;
			}

			if (0 == (strcmp(z, "六里桥东")))
			{
				a2 = 94;
				break;
			}
			if (0 == (strcmp(z, "丰台东大街")))
			{
				a2 = 95;
				break;
			}

			if (0 == (strcmp(z, "丰台南路")))
			{
				a2 = 96;
				break;
			}
			if (0 == (strcmp(z, "科怡路")))
			{
				a2 = 97;
				break;
			}
			if (0 == (strcmp(z, "丰台科技园")))
			{
				a2 = 98;
				break;
			}



			//悲催的十号线


			if (0 == (strcmp(z, "泥洼")))
			{
				a2 = 99;
				break;
			}
			if (0 == (strcmp(z, "丰台站")))
			{
				a2 = 100;
				break;
			}
			if (0 == (strcmp(z, "首经贸")))
			{
				a2 = 101;
				break;
			}
			if (0 == (strcmp(z, "纪家庙")))
			{
				a2 = 102;
				break;
			}
			if (0 == (strcmp(z, "草桥")))
			{
				a2 = 103;
				break;
			}
			if (0 == (strcmp(z, "角门东")))
			{
				a2 = 104;
				break;
			}

			if (0 == (strcmp(z, "大红门")))
			{
				a2 = 105;
				break;
			}
			if (0 == (strcmp(z, "石榴庄")))
			{
				a2 = 106;
				break;
			}
			if (0 == (strcmp(z, "成寿寺")))
			{
				a2 = 107;
				break;
			}

			if (0 == (strcmp(z, "分钟寺")))
			{
				a2 = 108;
				break;
			}
			if (0 == (strcmp(z, "十里河")))
			{
				a2 = 109;
				break;
			}
			if (0 == (strcmp(z, "潘家园")))
			{
				a2 = 110;
				break;
			}
			if (0 == (strcmp(z, "劲松")))
			{
				a2 = 111;
				break;
			}
			if (0 == (strcmp(z, "双井")))
			{
				a2 = 112;
				break;
			}
			if (0 == (strcmp(z, "金台夕照")))
			{
				a2 = 113;
				break;
			}
			if (0 == (strcmp(z, "团结湖")))
			{
				a2 = 114;
				break;
			}
			if (0 == (strcmp(z, "农业展览馆")))
			{
				a2 = 115;
				break;
			}
			if (0 == (strcmp(z, "亮马桥")))
			{
				a2 = 116;
				break;
			}
			if (0 == (strcmp(z, "太阳宫")))
			{
				a2 = 117;
				break;
			}

			if (0 == (strcmp(z, "安贞门")))
			{
				a2 = 118;
				break;
			}

			if (0 == (strcmp(z, "建德门")))
			{
				a2 = 119;
				break;
			}
			if (0 == (strcmp(z, "牡丹园")))
			{
				a2 = 120;
				break;
			}
			if (0 == (strcmp(z, "西土城")))
			{
				a2 = 121;
				break;
			}
			if (0 == (strcmp(z, "知春里")))
			{
				a2 = 122;
				break;
			}

			if (0 == (strcmp(z, "苏州街")))
			{
				a2 = 123;
				break;
			}

			if (0 == (strcmp(z, "巴沟")))
			{
				a2 = 124;
				break;
			}

			if (0 == (strcmp(z, "火器营")))
			{
				a2 = 125;
				break;
			}

			if (0 == (strcmp(z, "长春桥")))
			{
				a2 = 126;
				break;
			}

			if (0 == (strcmp(z, "车道沟")))
			{
				a2 = 127;
				break;
			}

			if (0 == (strcmp(z, "西钓鱼桥")))
			{
				a2 = 128;
				break;
			}
			if (0 == (strcmp(z, "莲花桥")))
			{
				a2 = 129;
				break;
			}


			//13号线


			if (0 == (strcmp(z, "大钟寺")))
			{
				a2 = 130;
				break;
			}

			if (0 == (strcmp(z, "五道口")))
			{
				a2 = 131;
				break;
			}
			if (0 == (strcmp(z, "上地")))
			{
				a2 = 132;
				break;
			}
			if (0 == (strcmp(z, "龙泽")))
			{
				a2 = 133;
				break;
			}
			if (0 == (strcmp(z, "回龙观")))
			{
				a2 = 134;
				break;
			}

			if (0 == (strcmp(z, "北苑")))
			{
				a2 = 135;
				break;
			}
			if (0 == (strcmp(z, "光熙门")))
			{
				a2 = 136;
				break;
			}

			if (0 == (strcmp(z, "柳芳")))
			{
				a2 = 137;
				break;
			}

			//14号线


			if (0 == (strcmp(z, "张郭庄")))
			{
				a2 = 138;
				break;
			}

			if (0 == (strcmp(z, "园博园")))
			{
				a2 = 139;
				break;
			}

			if (0 == (strcmp(z, "大瓦窑")))
			{
				a2 = 140;
				break;
			}

			if (0 == (strcmp(z, "郭庄子")))
			{
				a2 = 141;
				break;
			}

			if (0 == (strcmp(z, "大井")))
			{
				a2 = 142;
				break;
			}


			//15号线


			if (0 == (strcmp(z, "俸伯")))
			{
				a2 = 143;
				break;
			}

			if (0 == (strcmp(z, "顺义")))
			{
				a2 = 144;
				break;
			}

			if (0 == (strcmp(z, "石门")))
			{
				a2 = 145;
				break;
			}

			if (0 == (strcmp(z, "南法信")))
			{
				a2 = 146;
				break;
			}

			if (0 == (strcmp(z, "后沙峪")))
			{
				a2 = 147;
				break;
			}
			if (0 == (strcmp(z, "花梨坎")))
			{
				a2 = 148;
				break;
			}
			if (0 == (strcmp(z, "国展")))
			{
				a2 = 149;
				break;
			}
			if (0 == (strcmp(z, "孙河")))
			{
				a2 = 150;
				break;
			}

			if (0 == (strcmp(z, "马泉营")))
			{
				a2 = 151;
				break;
			}

			if (0 == (strcmp(z, "崔各庄")))
			{
				a2 = 152;
				break;
			}

			if (0 == (strcmp(z, "望京")))
			{
				a2 = 153;
				break;
			}


			//八通线


			if (0 == (strcmp(z, "高碑店")))
			{
				a2 = 154;
				break;
			}

			if (0 == (strcmp(z, "传媒大学")))
			{
				a2 = 155;
				break;
			}

			if (0 == (strcmp(z, "双桥")))
			{
				a2 = 156;
				break;
			}

			if (0 == (strcmp(z, "管庄")))
			{
				a2 = 157;
				break;
			}
			if (0 == (strcmp(z, "八里桥")))
			{
				a2 = 158;
				break;
			}

			if (0 == (strcmp(z, "通州北苑")))
			{
				a2 = 159;
				break;
			}

			if (0 == (strcmp(z, "果园")))
			{
				a2 = 160;
				break;
			}

			if (0 == (strcmp(z, "九棵树")))
			{
				a2 = 161;
				break;
			}

			if (0 == (strcmp(z, "梨园")))
			{
				a2 = 162;
				break;
			}

			if (0 == (strcmp(z, "临河里")))
			{
				a2 = 163;
				break;
			}

			if (0 == (strcmp(z, "土桥")))
			{
				a2 = 164;
				break;
			}

			//昌平线

			if (0 == (strcmp(z, "南邵")))
			{
				a2 = 165;
				break;
			}

			if (0 == (strcmp(z, "沙河高教园")))
			{
				a2 = 166;
				break;
			}

			if (0 == (strcmp(z, "沙河")))
			{
				a2 = 167;
				break;
			}
			if (0 == (strcmp(z, "巩华城")))
			{
				a2 = 168;
				break;
			}

			if (0 == (strcmp(z, "生命科学园")))
			{
				a2 = 169;
				break;
			}


			//亦庄线


			if (0 == (strcmp(z, "肖村")))
			{
				a2 = 170;
				break;
			}
			if (0 == (strcmp(z, "小红门")))
			{
				a2 = 171;
				break;
			}
			if (0 == (strcmp(z, "旧宫")))
			{
				a2 = 172;
				break;
			}
			if (0 == (strcmp(z, "亦庄桥")))
			{
				a2 = 173;
				break;
			}

			if (0 == (strcmp(z, "亦庄文化园")))
			{
				a2 = 174;
				break;
			}

			if (0 == (strcmp(z, "万源街")))
			{
				a2 = 175;
				break;
			}

			if (0 == (strcmp(z, "荣京东街")))
			{
				a2 = 176;
				break;
			}

			if (0 == (strcmp(z, "荣昌东街")))
			{
				a2 = 177;
				break;
			}

			if (0 == (strcmp(z, "同济南路")))
			{
				a2 = 178;
				break;
			}

			if (0 == (strcmp(z, "经海路")))
			{
				a2 = 179;
				break;
			}

			if (0 == (strcmp(z, "次渠南")))
			{
				a2 = 180;
				break;
			}

			if (0 == (strcmp(z, "次渠")))
			{
				a2 = 181;
				break;
			}


			//房山线


			if (0 == (strcmp(z, "苏庄")))
			{
				a2 = 182;
				break;
			}

			if (0 == (strcmp(z, "良乡南关")))
			{
				a2 = 183;
				break;
			}

			if (0 == (strcmp(z, "良乡大学城西")))
			{
				a2 = 184;
				break;
			}
			if (0 == (strcmp(z, "良乡大学城")))
			{
				a2 = 185;
				break;
			}
			if (0 == (strcmp(z, "良乡大学城北")))
			{
				a2 = 186;
				break;
			}
			if (0 == (strcmp(z, "广阳城")))
			{
				a2 = 187;
				break;
			}

			if (0 == (strcmp(z, "篱笆房")))
			{
				a2 = 188;
				break;
			}
			if (0 == (strcmp(z, "长阳")))
			{
				a2 = 189;
				break;
			}

			if (0 == (strcmp(z, "稻田")))
			{
				a2 = 190;
				break;
			}

			if (0 == (strcmp(z, "大葆台")))
			{
				a2 = 191;
				break;
			}

			//机场线


			if (0 == (strcmp(z, "T2航站楼")))
			{
				a2 = 192;
				break;
			}

			if (0 == (strcmp(z, "T3航站楼")))
			{
				a2 = 193;
				break;
			}


			//交点的插入

			if (0 == (strcmp(z, "宣武门")))
			{
				a2 = 194;
				break;
			}

			if (0 == (strcmp(z, "西单")))
			{
				a2 = 195;
				break;
			}

			if (0 == (strcmp(z, "公主坟")))
			{
				a2 = 196;
				break;
			}
			if (0 == (strcmp(z, "军事博物馆")))
			{
				a2 = 197;
				break;
			}

			if (0 == (strcmp(z, "复兴门")))
			{
				a2 = 198;
				break;
			}

			if (0 == (strcmp(z, "东单")))
			{
				a2 = 199;
				break;
			}

			if (0 == (strcmp(z, "建国门")))
			{
				a2 = 200;
				break;
			}
			if (0 == (strcmp(z, "国贸")))
			{
				a2 = 201;
				break;
			}
			if (0 == (strcmp(z, "四惠东")))
			{
				a2 = 202;
				break;
			}
			if (0 == (strcmp(z, "崇文门")))
			{
				a2 = 203;
				break;
			}
			if (0 == (strcmp(z, "朝阳门")))
			{
				a2 = 204;
				break;
			}

			if (0 == (strcmp(z, "东直门")))
			{
				a2 = 205;
				break;
			}

			if (0 == (strcmp(z, "雍和宫")))
			{
				a2 = 206;
				break;
			}

			if (0 == (strcmp(z, "鼓楼大街")))
			{
				a2 = 207;
				break;
			}

			if (0 == (strcmp(z, "西直门")))
			{
				a2 = 208;
				break;
			}

			if (0 == (strcmp(z, "车公庄")))
			{
				a2 = 209;
				break;
			}
			if (0 == (strcmp(z, "海淀黄庄")))
			{
				a2 = 210;
				break;
			}
			if (0 == (strcmp(z, "国家图书馆")))
			{
				a2 = 211;
				break;
			}
			if (0 == (strcmp(z, "平安里")))
			{
				a2 = 212;
				break;
			}
			if (0 == (strcmp(z, "角门西")))
			{
				a2 = 213;
				break;
			}

			if (0 == (strcmp(z, "立水桥")))
			{
				a2 = 214;
				break;
			}

			if (0 == (strcmp(z, "惠新西街南口")))
			{
				a2 = 215;
				break;
			}
			if (0 == (strcmp(z, "东四")))
			{
				a2 = 216;
				break;
			}

			if (0 == (strcmp(z, "宋家庄")))
			{
				a2 = 217;
				break;
			}

			if (0 == (strcmp(z, "慈寿寺")))
			{
				a2 = 218;
				break;
			}
			if (0 == (strcmp(z, "白石桥南")))
			{
				a2 = 219;
				break;
			}
			if (0 == (strcmp(z, "南锣巷鼓")))
			{
				a2 = 220;
				break;
			}
			if (0 == (strcmp(z, "呼家楼")))
			{
				a2 = 221;
				break;
			}
			if (0 == (strcmp(z, "朱辛庄")))
			{
				a2 = 222;
				break;
			}
			if (0 == (strcmp(z, "霍营")))
			{
				a2 = 223;
				break;
			}
			if (0 == (strcmp(z, "北土城")))
			{
				a2 = 224;
				break;
			}

			if (0 == (strcmp(z, "六里桥")))
			{
				a2 = 225;
				break;
			}
			if (0 == (strcmp(z, "七里庄")))
			{
				a2 = 226;
				break;
			}
			if (0 == (strcmp(z, "郭公庄")))
			{
				a2 = 227;
				break;
			}
			if (0 == (strcmp(z, "三元桥")))
			{
				a2 = 228;
				break;
			}
			if (0 == (strcmp(z, "芍药居")))
			{
				a2 = 229;
				break;
			}
			if (0 == (strcmp(z, "知春路")))
			{
				a2 = 230;
				break;
			}
			if (0 == (strcmp(z, "西局")))
			{
				a2 = 231;
				break;
			}

			if (0 == (strcmp(z, "西二旗")))
			{
				a2 = 232;
				break;
			}
			if (0 == (strcmp(z, "望京西")))
			{
				a2 = 233;
				break;
			}





			//输入错误循环！！！！
			printf("\n终点输入有误请重新输入\n");
			gets_s(z, 20);

		}


		if (a1 == a2)
		{
			printf("您别逗我玩\n");
			system("pause");
			return;
		}

		//**********************************************************************************************************************************************************
		for (int i = 1; i <= n; ++i)
			dist[i] = maxint;

		Dijkstra(n, a1, dist, prev, c);

		// 最短路径长度
		printf("您需要乘坐至少%d站\n", dist[a2]);

		// 路径
		printf("最短路径为：");
		way(prev, a1, a2);
		printf("\n继续查找请按1  放弃查找请按0     ");
		scanf_s("%d", &asd);
		getchar();
	}
	system("pause");
}