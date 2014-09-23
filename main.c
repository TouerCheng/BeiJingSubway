#include "1.c"
#include "2.c"
main()
{
adj ditie;
adj *a=&ditie;
struct cam xianlu;
struct cam *b=&xianlu;
int q;
print0();
print1();
scanf("%d",&q);
if(q==1)
{
readwjbj(a);
xianputbj(b);
}
if(q==2)
{
readwjxa(a);
xianputxa(b);
}
if(q==8)
exit(1);
int w=0;
while(w!=6&&w!=7)
{
print2();
scanf("%d",&w);
if(1==w)
printall(a);
if(2==w)
xianout(a,b);
if(3==w)
printf("您好，所有地铁的运行时间为早八点到晚八点。\n");
if(4==w)
input(a,b);
if(5==w)
   {   int e=5;
       while(e!=4)
      {
       print3();
       scanf("%d",&e);
       if(e==1)
       xiugai1(a);
       if(e==2)
       xiugai2(a);
       if(e==3)
       xiugai3(a);
      }
   }
if(6==w)
putwj(a);
}
}
