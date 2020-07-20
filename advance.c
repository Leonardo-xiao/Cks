#include"main.h"
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
#define PI 3.1415926

/***********************************************************************
void bow(int,int,int,int);
void semicircle_up(int,int,int,int);
void semicircle_down(int,int,int,int);
void fill_bow_right_up(int,int,int,int);
void fill_bow_left_up(int,int,int,int);
void fill_bow_right_down(int,int,int,int);
void fill_bow_left_down(int,int,int,int);
void fill_bow_down(int,int,int,int);
void fill_bow_up(int,int,int,int);
void fill_bow_left(int,int,int,int);
void fill_bow_right(int,int,int,int);
void bar_round(int,int,int,int,int,int,int);
void bow_right_up(int,int,int,int);
void bow_right_down(int,int,int,int);
void bow_left_up(int,int,int,int);
void bow_left_down(int,int,int,int);
void lean_line(int,int,int,int,int);
void theta_bar(int x,int y,int length,int wide,int theta,int color);
void robot_hand_left(int,int,int);
void robot_hand_right(int ,int ,int );
void red_cross(int x,int y);
void green_tick(int x,int y);
void button(int x,int y,int judge);
void triangle1(int x,int y,int height,int color);
void triangle2(int x,int y,int height,int color);
***********************************************************************/

/*只能画竖直方向的实心椭圆
输入：两个圆心坐标及半径，颜色*/
void Fillellipse(int x1,int y1,int x2,int y2,int r,int color)
{
	FillCircle(x1,y1,r,color);
	FillCircle(x2,y2,r,color);
	bar(x1-r,y1,x2+r,y2,color);
}

/*2018/10/1新增
可画出水平方向的实心椭圆
输入：两个圆心坐标及半径，颜色*/
void ever_Fillellipse(int x1,int y1,int x2,int y2,int r,int color)
{
	FillCircle(x1,y1,r,color);
	FillCircle(x2,y2,r,color);
	bar(x1,y1-r,x2,y2+r,color);
}

/*非实心椭圆*/
void ellipse(int x1,int y1,int x2,int y2,int r,int color)
{
	semicircle_up(x2,y2,r,color);
	semicircle_down(x1,y1,r,color);
	linever(x1-r,y1,x1-r,y2,1,color);
	linever(x2+r,y1,x2+r,y2,1,color);
}

/*上半圆（非实心）*/
void semicircle_up(int x0,int y0,int r,int color)
{
	int x, y, d;
	y = r;
	d = 3 - r << 1;

	for (x = 0; x <= y; x++)
	{
		Putpixel64k(x0 + x, y0 + y, color);
		Putpixel64k(x0 - x, y0 + y, color);
		Putpixel64k(x0 + y, y0 + x, color);
		Putpixel64k(x0 - y, y0 + x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}

void semicircle_down(int x0,int y0,int r,int color)
{
	int x, y, d;
	y = r;
	d = 3 - r << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(x0 + x, y0 - y, color);
		Putpixel64k(x0 - x, y0 - y, color);
		Putpixel64k(x0 + y, y0 - x, color);
		Putpixel64k(x0 - y, y0 - x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}



/*四个画四分之一弧函数，非实心，均使用勾股定理计算*/

void bow_right_up(int x,int y,int r,int color)//右上方
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x+d,y-tx,color);
		tx++;
	}
}

void bow_right_down(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x+d,y+tx,color);
		tx++;
	}
}

void bow_left_up(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x-d,y-tx,color);
		tx++;
	}
}

void bow_left_down(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x-d,y+tx,color);
		tx++;
	}
}




/*填充四分之一圆，右上*/
void fill_bow_right_up(int x,int y,int r,int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;
	while( tx < ty)
	{
		// 画水平两点连线(<45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
		}

		if (d < 0)			// 取上面的点
			d += 4 * tx + 6;
		else				// 取下面的点
		{
			// 画水平两点连线(>45度)
			for (i = x; i <= x + tx; i++)
			{
				Putpixel64k(i, y - ty, color);
				
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}
	if (tx == ty)			// 画水平两点连线(=45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
			
		}
}

void fill_bow_left_up(int x,int y,int r,int color)
{
	int tx=0,ty=r,i;
	double sx;
	while(tx<ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x-sx;i<=x;i++)
		{
			Putpixel64k(i,y-tx,color);
		}
		tx++;
	}
}

void fill_bow_right_down(int x,int y,int r,int color)
{
	int tx=0,ty=r,i;
	double sx;
	while(tx<ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x;i<=x+sx;i++)
		{
			Putpixel64k(i,y+tx,color);
		}
		tx++;
	}
}

void fill_bow_left_down(int x,int y,int r,int color)
{
	int tx=0,ty=r,i;
	double sx;
	while(tx<ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x-sx;i<=x;i++)
		{
			Putpixel64k(i,y+tx,color);
		}
		tx++;
	}
}

void fill_bow_down(int x,int y,int r,int color)
{
	int tx = 0, ty = r,i;
	float d = r/1.414;
	double sx;
	while(tx<ty)
	{
		if(tx<d)
		{
			for(i=x-tx;i<=x+tx;i++)
		    {
			    Putpixel64k(i,y+tx,color);
				
		    }
		}
        else
		{
			for(i=x-sx;i<=x+sx;i++)
			{
				Putpixel64k(i,y+tx,color);	
			}
		}
		tx++;
		sx = sqrt(r*r-tx*tx);
	}
}

void fill_bow_up(int x,int y,int r,int color)   //上半圆
{
	int tx = 0, ty = r,i;
	float d = r/1.414;
	double sx;
	while(tx<ty)
	{
		if(tx<d)
		{
			for(i=x-tx;i<=x+tx;i++)
		    {
			    Putpixel64k(i,y-tx,color);
				
		    }
		}
        else
		{
			for(i=x-sx;i<=x+sx;i++)
			{
				Putpixel64k(i,y-tx,color);	
			}
		}
		tx++;
		sx = sqrt(r*r-tx*tx);
	}
}

void fill_bow_left(int x,int y,int r,int color)
{
	int ty = 0, tx = r,i;
	float d = r/1.414;
	double sy;
	while(ty<tx)
	{
		if(ty<d)
		{
			for(i=y-ty;i<=y+ty;i++)
		    {
			    Putpixel64k(x-ty,i,color);
				
		    }
		}
        else
		{
			for(i=y-sy;i<=y+sy;i++)
			{
				Putpixel64k(x-ty,i,color);	
			}
		}
		ty++;
		sy = sqrt(r*r-ty*ty);
	}
}

void fill_bow_right(int x,int y,int r,int color)
{
	int ty = 0, tx = r,i;
	float d = r/1.414;
	double sy;
	while(ty<tx)
	{
		if(ty<d)
		{
			for(i=y-ty;i<=y+ty;i++)
		    {
			    Putpixel64k(x+ty,i,color);
				
		    }
		}
        else
		{
			for(i=y-sy;i<=y+sy;i++)
			{
				Putpixel64k(x+ty,i,color);	
			}
		}
		ty++;
		sy = sqrt(r*r-ty*ty);
	}
}

/*圆角矩形*/
void bar_round(int x,int y,int length,int height,int r,int thick,int color) //r是圆角半径，thick是粗细
{
	bar(x-length/2+r,y-height/2,x+length/2-r,y+height/2,color);
	bar(x-length/2,y-height/2+r,x+length/2,y+height/2-r,color);
	fill_bow_left_up(x-length/2+r,y-height/2+r,r,color);
	fill_bow_left_down(x-length/2+r,y+height/2-r,r,color);
	fill_bow_right_up(x+length/2-r,y-height/2+r,r,color);
	fill_bow_right_down(x+length/2-r,y+height/2-r,r,color);
	linelevel(x-length/2+r,y-height/2,x+length/2-r,y-height/2,thick,color);
	linelevel(x-length/2+r,y+height/2,x+length/2-r,y+height/2,thick,color);
	linever(x-length/2,y-height/2+r,x-length/2,y+height/2-r,thick,color);
	linever(x+length/2,y-height/2+r,x+length/2,y+height/2-r,thick,color);
    bow_right_up(x+length/2-r,y-height/2+r,r,color);
	bow_left_up(x-length/2+r,y-height/2+r,r,color);
	bow_left_down(x-length/2+r,y+height/2-r,r,color);
	bow_right_down(x+length/2-r,y+height/2-r,r,color);
}

void bar_round_2(int x0,int y0,int x1,int y1,int r,int thick,int color)
{
	int length, height, x, y;
	length = x1-x0;
	height = y1-y0;
	x = (x1+x0)/2;
	y = (y1+y0)/2;
	bar_round(x,y,length,height,r,thick,color);
}


void bar_round_with_shadow(int x,int y,int length,int height,int r,int thick,int color)
{
	bar(x-length/2+r,y-height/2,x+length/2-r,y+height/2,color);
	bar(x-length/2,y-height/2+r,x+length/2,y+height/2-r,color);
	fill_bow_left_up(x-length/2+r,y-height/2+r,r,color);
	fill_bow_left_down(x-length/2+r,y+height/2-r,r,color);
	fill_bow_right_up(x+length/2-r,y-height/2+r,r,color);
	fill_bow_right_down(x+length/2-r,y+height/2-r,r,color);
	linelevel(x-length/2+r,y-height/2,x+length/2-r,y-height/2,thick,65535);
	linelevel(x-length/2+r,y+height/2,x+length/2-r,y+height/2,thick*3,0);
	linever(x-length/2,y-height/2+r,x-length/2,y+height/2-r,thick,65535);
	linever(x+length/2,y-height/2+r,x+length/2,y+height/2-r,thick*2,0);
    bow_right_up(x+length/2-r,y-height/2+r,r,0);
	bow_left_up(x-length/2+r,y-height/2+r,r,65535);
	bow_left_down(x-length/2+r,y+height/2-r,r,65535);
	bow_right_down(x+length/2-r,y+height/2-r,r,0);
}

/*斜线*/
void lean_line(int x,int y,int length,int theta,int color)//x,y为线段的起点
{
	double right_x;
	double i,y0;
	double theta0 = ((double)(theta))/180*PI;
	right_x= x+cos(theta0)*(length);
    y0 = y;
	if((int)(theta)<=90)
	{
		for(i=x;i<=right_x;i++)
	    {
		    Putpixel64k(i,y0,color);
		    y0 += tan(theta0);
	    }
	}
	else
	{
		for(i=x;i>=right_x;i--)
	    {
		    Putpixel64k(i,y0,color);
		    y0 = y0+tan(theta0);
	    }
	}

}

/*通过加粗斜线画出平行四边形*/
void lean_line_thick(int x,int y,int length,int theta,int thick,int color)//x,y 为矩形的左边左上角坐标
{
	int i;
	for(i=0;i<thick;i++)
	{
		lean_line(x+i,y,length,theta,color);
	}
}

/*斜矩形*/
void theta_bar(int x,int y,int length,int height,int theta,int color)//x,y为矩形左上角,height为线长,θ为跟x正方向夹角
{
	lean_line_thick(x,y,height,theta,length,color);
}


/*机器人的右手*/
void robot_hand_right(int x,int y,int theta)
{
    theta_bar(x,y-30,(int)(12/sin((double)(theta)/180*PI)),(int)(12/sin((double)(theta)/180*PI)),theta,0);
	theta_bar(x,y-30,(int)(10/sin((double)(theta)/180*PI)),(int)(10/sin((double)(theta)/180*PI)),theta,255);
	FillCircle(x+(int)(16/tan((double)(theta)/180*PI))+2,y-(int)(24*sin((double)(theta)/180*PI))-5,7,0);
    FillCircle(x+(int)(16/tan((double)(theta)/180*PI))+2,y-(int)(24*sin((double)(theta)/180*PI))-5,6,65535);
}

/*机器人的左手*/
void robot_hand_left(int x,int y,int theta)
{
    theta_bar(x,y-30,(int)(12/sin((double)(-1*theta)/180*PI)),(int)(12/sin((double)(-1*theta)/180*PI)),theta,0);
	theta_bar(x,y-30,(int)(10/sin((double)(-1*theta)/180*PI)),(int)(10/sin((double)(-1*theta)/180*PI)),theta,255);
	FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-10,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,7,0);
    FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-10,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,6,65535);
}

/*提示错误的红色叉*/
void red_cross(int x,int y)
{
	lean_line_thick(x,y,30,45,3,63488);
	lean_line_thick(x,y+20,30,-45,3,63488);
}

/*提示正确的绿色勾*/
void green_tick(int x,int y)
{
	lean_line_thick(x,y,15,45,3,2047);
	lean_line_thick(x+13,y+5,40,-45,3,2047);
}


/*树上方的三角形*/
void triangle1(int x,int y,int height,int color)//x,y为三角形底边中点
{
	int i,j=0;
	for(i=0;i<height;i++)
	{
		for(j=0;j<=i;j++)
		{
			Putpixel64k(x-j/2,y+i,color);
		    Putpixel64k(x+j/2,y+i,color);
		}
		
	}
}

/*较扁的三角形*/
void triangle2(int x,int y,int height,int color)//x,y为三角形底边中点
{
	int i,j=0;
	for(i=0;i<height*2;i++)
	{
		for(j=0;j<=i;j++)
		{
			Putpixel64k(x-j,y+i/2,color);
		    Putpixel64k(x+j,y+i/2,color);
		}
		
	}
}


void triangleleft(int x,int y,int height,int color)//x,y为三角形底边中点，左半三角
{
	int i,j=0;
	for(i=0;i<height*2;i++)
	{
		for(j=0;j<=i;j++)
		{
			Putpixel64k(x-i/2,y-j,color);
		    Putpixel64k(x-i/2,y+j,color);
		}
		
	}
}

void triangleright(int x,int y,int height,int color)//x,y为三角形底边中点
{
	int i,j=0;
	for(i=0;i<height*2;i++)
	{
		for(j=0;j<=i;j++)
		{
			Putpixel64k(x+i/2,y-j,color);
		    Putpixel64k(x+i/2,y+j,color);
		}
		
	}
}

void triangledown(int x,int y,int height,int color)//x,y为三角形底边中点
{
	int i,j=0;
	for(i=0;i<height*2;i++)
	{
		for(j=0;j<=i;j++)
		{
			Putpixel64k(x-j,y-i/2,color);
		    Putpixel64k(x+j,y-i/2,color);
		}
		
	}
}
void button(int x,int y,int judge)//judge:0:关，1开,x,y为中心点，机器人按钮啥的
{
	if(judge)
	{
		ever_Fillellipse(x-30,y,x+30,y,20,50712);
		ever_Fillellipse(x-30,y,x+30,y,19,2016);
		FillCircle(x+30,y,19,65535);
	}
	else
	{
		ever_Fillellipse(x-30,y,x+30,y,20,50712);
		//fillellipse(x-15,y,x+15,y,2,2016);
		FillCircle(x-30,y,19,65535);
	}
}


