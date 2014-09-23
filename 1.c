
//地铁线路图
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 300
#define maxnum 500
struct com //定义站点信息
{
int num;
char name[20];
};
struct cam //定义线路信息
{
int cama;
int camb[max];
int camc[max][max];
};
typedef struct//定义邻接矩阵
{
int diannum;
int xiannum;
int c[max][max];
struct com dian[max];
}adj;

//函数区域

//****************************************************************

//文件输入线路信息
xianputbj(struct cam *q)
{
int i,j;
FILE *fp;
fp=fopen("filebj1.txt","rt");
fscanf(fp,"%d",&q->cama);
for(i=1;i<=q->cama;i++)
fscanf(fp,"%d",&q->camb[i]);
for(i=1;i<=q->cama;i++)
for(j=1;j<=q->camb[i];j++)
fscanf(fp,"%d",&q->camc[i][j]);
fclose(fp);
}

xianputxa(struct cam *q)
{
int i,j;
FILE *fp;
fp=fopen("filexa1.txt","rt");
fscanf(fp,"%d",&q->cama);
for(i=1;i<=q->cama;i++)
fscanf(fp,"%d",&q->camb[i]);
for(i=1;i<=q->cama;i++)
for(j=1;j<=q->camb[i];j++)
fscanf(fp,"%d",&q->camc[i][j]);
fclose(fp);
}


//*********************************************************

//输出线路信息
xianout(adj *a,struct cam *p)
{
char name[20];
int i,j;
printf("共有%d条地铁线路\n",p->cama);
for(i=1;i<=p->cama;i++)
 {
 printf("%d线路的站点：",i);
      for(j=1;j<=p->camb[i];j++)
      {
       numname(a,p->camc[i][j],name);
       printf("%s ",name);
      }
 printf("\n");
 }

}
//*********************************************************

int namenum(adj *a,char aaname[] )//给名称，返回编号
{
int i,j;
for(i=1;i<=a->diannum;i++)
if(strcmp(aaname,a->dian[i].name) == 0)
return i;
return -13;
}

//***************************************************************
numname(adj *a,int b,char *s )//给编号，返回名称
{
int i,j;
for(i=1;i<=a->diannum;i++)
if(a->dian[i].num==b)
strcpy(s,a->dian[i].name);
}
//*******************************************************************


readwjbj(adj *b)  //创建结构体初始化并且从文件 （file.txt）中提取信息至邻接矩阵
{
int i,j;
int m,n;
FILE *fp;
//距离初始化
for(i=1;i<=max;i++)
for(j=1;j<=max;j++)
b->c[i][j]=maxnum;
fp=fopen("filebj.txt","rt");
fscanf(fp,"%d%d",&b->diannum,&b->xiannum);//首先读取站点和连线个数
for(i=1;i<=b->diannum;i++)
fscanf(fp,"%d%s",&b->dian[i].num,b->dian[i].name);//读取 编号 站名
for(i=1;i<=((b->xiannum)*2);i++)
{
fscanf(fp,"%d%d",&m,&n);//读取 相邻站点 编号
b->c[m][n]=1;
}
fclose(fp);
}
readwjxa(adj *b)  //创建结构体初始化并且从文件 （file.txt）中提取信息至邻接矩阵
{
int i,j;
int m,n;
FILE *fp;
//距离初始化
for(i=1;i<=max;i++)
for(j=1;j<=max;j++)
b->c[i][j]=maxnum;
fp=fopen("filexa.txt","rt");
fscanf(fp,"%d%d",&b->diannum,&b->xiannum);//首先读取站点和连线个数
for(i=1;i<=b->diannum;i++)
fscanf(fp,"%d%s",&b->dian[i].num,b->dian[i].name);//读取 编号 站名
for(i=1;i<=((b->xiannum)*2);i++)
{
fscanf(fp,"%d%d",&m,&n);//读取 相邻站点 编号
b->c[m][n]=1;
}
fclose(fp);
}
//********************************************************************

putwj(adj *a)  //把邻接矩阵输入至文件 file.txt
{
int i,j;
int m,n;
FILE *fp;
fp=fopen("file.txt","wt");
fprintf(fp,"%d %d\n",a->diannum,a->xiannum);
for(i=1;i<=a->diannum;i++)
fprintf(fp,"%d %s\n",a->dian[i].num,a->dian[i].name);
for(m=1;m<=a->diannum;m++)
for(n=1;n<=a->diannum;n++)
if (a->c[m][n]==1)
fprintf(fp,"%d %d\n",m,n);
fclose(fp);
}
//***************************************************************

//用dijkstra算法计算最短距离
 void Dijkstra(adj *a, int v, int *dist, int *prev)
 {   int i,j;
     int s[max];    // 判断是否已存入该点到S集合中
     for(i=1; i<=a->diannum; i++)
     {
         dist[i] = a->c[v][i];
         s[i] = 0;     // 初始都未用过该点
         if(dist[i] == maxnum)
             prev[i] = 0;
         else
             prev[i] = v;
     }
     dist[v] = 0;
     s[v] = 1;
  
     // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
     // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
     for(i=2; i<=a->diannum; ++i)
     {
         int tmp = maxnum;
         int u = v;
         // 找出当前未使用的点j的dist[j]最小值
         for( j=1; j<=a->diannum; ++j)
             if((!s[j]) && dist[j]<tmp)
             {
                 u = j;              // u保存当前邻接点中距离最小的点的号码
                 tmp = dist[j];
             }
         s[u] = 1;    // 表示u点已存入S集合中
  
         // 更新dist
         for( j=1; j<=a->diannum; ++j)
             if((!s[j]) && a->c[u][j]<maxnum)
             {
                 int newdist = dist[u] + a->c[u][j];
                 if(newdist < dist[j])
                 {
                     dist[j] = newdist;
                     prev[j] = u;
                 }
             }
     }
 }

//*********************************************************************
                                                                                      
//***************************************
//地址的输入的和最佳路径的输出
input(adj *a,struct cam *p)
{
int i,j;
int m,n,l,bj;
char qiname[20],zhongname[20],nowname[20];
int qinum,zhongnum,nownum;
printf("请输入起点：");
scanf("%s",qiname);
qinum=namenum(a,qiname);
printf("\n请输入终点：");
scanf("%s",zhongname);
zhongnum=namenum(a,zhongname);
printf("\n途中经历的路径为：");
int prev[max];
int dist[maxnum];
Dijkstra(a,qinum,dist,prev);
if(dist[zhongnum]>400)
printf("无法到达！\n");
else
{
printf("需要经过%d站\n",dist[zhongnum]);

     int que[maxnum];
     int tot = 1;
     que[tot] = zhongnum;
     tot++;
     int tmp = prev[zhongnum];
     while(tmp != qinum)
     {
         que[tot] = tmp;
         tot++;
         tmp = prev[tmp];
     }
     que[tot] = qinum;
     //线路的输出
     for(m=1;m<=p->cama;m++)
     for(n=1;n<=p->camb[m];n++)
     if(que[tot]==p->camc[m][n])
     { for(l=1;l<=p->camb[m];l++)
      if(que[tot-1]==p->camc[m][l])
      {printf("(乘坐%d号线)",m);
      bj=m;
      }
     }
     for( i=tot; i>1; i--)
         if(i != 1)
          {
            for(m=1;m<=p->cama;m++)
            for(n=1;n<=p->camb[m];n++)
            if(que[i]==p->camc[m][n]&&bj!=m)
               { for(l=1;l<=p->camb[m];l++)
                 if(que[i-1]==p->camc[m][l])
                 {
                  printf("(换乘%d号线)",m);
                  bj=m;
                 }
               }

            nownum=que[i];
            numname(a,nownum,nowname);
            printf("%s->",nowname); 
          }   
             printf("%s\n",zhongname);
}
}

//*************************************************************************************

//显示所有站点
void printall(adj *a)
{
int i=1;
printf("共有%d个站点\n",a->diannum);
printf("站点分别是：");
for(i=1;i<=a->diannum;i++)
printf("%s  ",a->dian[i].name);
printf("\n");
}
























                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
