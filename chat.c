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

#include"iphCmfrt.h"
#include"mysystem.h"

#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764
#define MAXTXT 1000


//	界面框架
void chat_interface(unsigned int *box_save)
{
	/********
	界面背景
	********/
	FillCircle(ORIGINX+200,ORIGINY+157,40,36410);	//138 198 210
	fill_bow_right_up(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	fill_bow_right_down(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	
	/********
	底部导航栏
	********/
	bar_round_2(ORIGINX+3,ORIGINY+473,ORIGINX+252,ORIGINY+542,30,1,36410);	//138 198 210
	
	//熊爪图标
	FillCircle(ORIGINX+24, ORIGINY+503, 5, 65535);
	FillCircle(ORIGINX+37, ORIGINY+491, 5, 65535);
	FillCircle(ORIGINX+55, ORIGINY+491, 5, 65535);
	FillCircle(ORIGINX+69, ORIGINY+503, 5, 65535);
	bar_round_2(ORIGINX+31,ORIGINY+502,ORIGINX+64,ORIGINY+529,10,1,65535);
	//主页图标（双圆环
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
	//聊天气泡
	FillCircle(ORIGINX+178, ORIGINY+529, 4, 65535);
	FillCircle(ORIGINX+183, ORIGINY+514, 7, 65535);
	bar_round_2(ORIGINX+190,ORIGINY+486,ORIGINX+238,ORIGINY+516,10,1,65535);
	bar(ORIGINX+195,ORIGINY+496,ORIGINX+225,ORIGINY+497,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+502,ORIGINX+225,ORIGINY+503,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+508,ORIGINX+225,ORIGINY+509,36410);	//138 198 210
	
	
	/***************
	输入框
	**************/
	bar_round_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+468,5,1,36410);
	bar_round_2(ORIGINX+13,ORIGINY+363,ORIGINX+243,ORIGINY+468,5,1,65535);
	bar(ORIGINX+13,ORIGINY+384,ORIGINX+243,ORIGINY+403,48631);		//191 191 191

	get_image(ORIGINX+25,ORIGINY+365/*365*/,ORIGINX+225,ORIGINY+400/*400*/, box_save);
}	

void ClearKey(void)//2
{
	union REGS key;

	key.h.ah = 0x0c;
	key.h.al = 0x00;
	int86(0x21, &key, &key);
}


/**************
区号位号归零操作
每次调用输入法都要使用
**************/
int QhwhToZero(int *qhwh)//6
{
    int i;
    for(i=0;i<MAXTXT;i++)
        qhwh[i]=0;
    return 0;
}

void chat_main(void)
 {	
	 Area box_area = { {ORIGINX+15+2,ORIGINY+415} , {ORIGINX+240,ORIGINY+460} };		//输入框左上角坐标
	 Coordinate current_show_position = {ORIGINX+17,ORIGINY+407};		//现在正在码的字的左上角坐标
	
	int i;
	int flag;
	int *qhwh=(int *)malloc(sizeof(int)*MAXTXT);		//区号位号
	
	unsigned int *box_save=(unsigned int *)malloc(200*35*sizeof(unsigned int));
	 
	if(qhwh==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(box_save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	//界面 
	iph_frame(28153);
	chat_interface(box_save);
	
	while(1)
	{
		//初始化区位号
		QhwhToZero(qhwh);
		//开始输入法 
		flag = ShowChTab(box_area,current_show_position/*现在正在码的字的左上角坐标*/, 16,qhwh, box_save) ;
		//回车键之后刷新聊天窗口
		bar(ORIGINX+15, ORIGINY+405, ORIGINX+240, ORIGINY+460,65535);
		if(flag == 3){
			show_main(qhwh,box_save);
		}
		else{
			break;
		}
		getch();
	}
		//ShowTxt(qhwh, cc,&cd,16);
		//num_qhwh=CheckQhwhNum(qhwh);	//看有几个字

	free(box_save);
	free(qhwh);
	qhwh = NULL;
	box_save = NULL;
	ph_main();
 }
