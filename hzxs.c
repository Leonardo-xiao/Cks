#include<fcntl.h>
#include<io.h>
#include<stdio.h>
#include "nmouse.h"
#include "move.h"
#include"svgahead.h"
#include"basicgf.h"
#include"compo.h"
#include<conio.h>
#include"advance.h"
#include"frame.h"
#include"hzxs.h"
#include"module_b.h"
#include<string.h>
#include<bios.h>
#include"input.h"
#include"color1.h"
#include"roomgf.h"
#include"sign.h"
#include"filefun.h"
#include"room.h"
#include"ground.h"
#include"brick.h"
#include"wall.h"
#include"outside.h"
#include"iphone.h"
#include"iphCheck.h"
#include"idCheck.h"
#include"select.h"
#include"service.h"
#include"manage.h"
#include"time.h"
#include"control.h"
#include"chat.h"
#include"chatHanz.h"
#include"chatInpu.h"
#include"chatQhwh.h"
#include"chatShow.h"
#include"gkmove.h"
#include"myhouse.h"
#include"chatGame.h"
#include"iphCmfrt.h"
#include"mysystem.h"


void gethz(char incode[],char  *bytes)
{
	unsigned char qh, wh;
	unsigned long offset;
 FILE * fhzk_p;                                                      /*�����ļ�ָ��*/
 fhzk_p = fopen("HZK\\hzk16", "rb");
 
 if (fhzk_p == NULL)
 {
	 printf("the hzk can't open\n");

	 delay(1000);
	 exit(1);
 }


 qh=incode[0]-0xa0;
 wh=incode[1]-0xa0;
 offset=(94*(qh-1)+(wh-1))*32L;
 fseek(fhzk_p,offset,SEEK_SET);
 fread(bytes,1,32,fhzk_p);
 fclose(fhzk_p);
 }
 


void dishz(int x0,int y0,int mx,int my,char *code,int color)//��ʾ�ַ�
{
	int x, y, i, j, k, xt, yt, bit;
	int count = 0;
 unsigned char mask=0x80;
 char *mat=(char *)malloc(32*sizeof(char));
 if (mat == NULL)
 {
	 overflow_box(500,500);
	 getch();
	 printf("there is no place\n");
	 exit(1);

 }



 gethz(code,mat);
 y=y0;
 x=x0;
 i=0;
 while(i<32)
 {
  for(yt=0;yt<my;yt++)
  {
   for(k=0;k<2;k++,count++)
   {
	for(j=0;j<8;j++)
	{
	 bit=mat[count]&mask;
	 for(xt=0;xt<mx;xt++)
	 {
	  if(bit)
	  {
		  Putpixel64k(x,y,color);
	  }
	 x++;
	 }
	 mask=mask>>1;
	}
	mask=0x80;
   }
   x=x0;
   count=count-2;
   y++;
  }
  i+=2;
  count+=2;
 }
 free(mat);
}



void fdhz(int x,int y,int mx,int my,char *s,int color)
{
  while(*s!=NULL)
  {
   while( ( (x+20*mx) <1024)&&(*s!=NULL) )
   {
   dishz(x,y,mx,my,s,color);
   x+=20*mx;
   s+=2;
   }
   x=20;
   y+=20*my;
  }

}

