/******************函数清单***************************
1.  void show_order(int *qhwh,int *y);
2.	void get_str(int *qhwh, char *incode);
3.	void reply_match(char * str,char *order,char *reply);
4.	void show_reply(char *incode, int * y);
5.	void show_main(int *qhwh);
*****************************************************/
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



/**************

	打印命令

**************/
void show_order(int *qhwh,int *y)
{
	int num_qhwh;	//字符数
	int num_line;	//需打印的行数
	int box_top;	//输入框上沿

	Area order_box;
	Coordinate order_begin;

	/***************
	检查有几个字并画对话框底
	***************/
	num_qhwh = CheckQhwhNum(qhwh);	//得到字符数
	num_line = num_qhwh/10+1;		//确认打印行数
	box_top = 345-20*num_line;		//确认对话框上沿

	if(num_qhwh<=10){
		bar_round_2(ORIGINX+239-num_qhwh*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);   //打印对话框
	}
	else{
		bar_round_2(ORIGINX+239-10*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);
	}

	/***************
	打印汉字并打印用户姓名
	***************/
	if(num_qhwh<=10)
	{
		order_box.lt.x = ORIGINX+239-num_qhwh*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-num_qhwh*16;
		order_begin.y = ORIGINY+box_top+2;

		ShowTxt(qhwh, order_box, &order_begin,16);
	}
	else{
		order_box.lt.x = ORIGINX+239-10*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-10*16;
		order_begin.y = ORIGINY+box_top+2;

		ShowTxt(qhwh, order_box, &order_begin,16);
	}

	fdhz(ORIGINX+243-16*2,ORIGINY+box_top-20,1,1,"智",65535);
	fdhz(ORIGINX+243-16*1,ORIGINY+box_top-20,1,1,"敏",65535);

	/*************
	改变回复区域的占位记录值
	*************/
	//*y = ORIGINY+box_top-25;
	*y = ORIGINY+50+20*num_line+25;
}

/**************

	真正得到用户输入的字符串

**************/
void get_str(int *qhwh, char *incode)
{
	char *p=incode;	//incode的位置指针
	int num_qhwh = CheckQhwhNum(qhwh);
	int i;

	for(i=0;i<num_qhwh;i++)
	{
		qhwh2incode(*qhwh,p);
		p+=2;
		qhwh++;
	}
	*p = 0;
	*(p+1)=0;

}



/**************

	前往文件中寻找匹配回复

**************/
void reply_match(char * str,char *order,char **reply,unsigned int *box_save, int *begin_y)
{
	int i=0,k,p;
	CH * ch=NULL;//定义汉字符号结构体
	FILE *hanzi;            //定义汉字符号文件指针
	char t_incode[2];
	char *t_str=str;
	char *t;
	//struct incode_stru *t_incode;
	//int *t_qhwh;
	srand((unsigned int)time(0));
	/*
	if( ( t_qhwh=(int *)malloc(sizeof(int)*20) )==NULL )//如果动态分配内存失败，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to malloc");
        return(1);
    }

	if( ( t_incode=(struct incode_stru *)malloc(sizeof(struct incode_stru)*20) )==NULL )//如果动态分配内存失败，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to malloc");
        return(1);
    }

	if( ( ch=(CH *)malloc(sizeof(CH)*463) )==NULL )//如果动态分配内存失败，则直接返回
    {
		overflow_box(500,500);
		getch();
        perror("fail to malloc");
        return(1);
    }
	if((hanzi = fopen("txt\\hanzi.txt","r")) == NULL)//hanzi和fuhao是文件句柄
    {
		null_box(500,500);
		getch();
        perror("fail to open");
        return (1) ;
    }
	SaveChQhwh(hanzi,ch);	//	初始化汉字输入库，将hanzi.txt里的汉字信息全部一个个转移到ch这个结构体中去

	qhwh2incode(FindChQhwh(ch,"chi",6,0),t_incode[0].a);
	qhwh2incode(FindChQhwh(ch,"chi",6,0),t_incode[1].a);
	qhwh2incode(FindChQhwh(ch,"chi",6,0),t_incode[2].a);
	qhwh2incode(FindChQhwh(ch,"chi",6,0),t_incode[3].a);
	qhwh2incode(FindChQhwh(ch,"chi",6,0),t_incode[4].a);
	*/
	/*
	while (str[i]!=0)
	{
		if (str[i]==t_incode[0].a[0])
		{
			strcpy(*reply,"火锅");
		}
		i+=2;
	}
	*/


	srand((unsigned int)time(0));
	while (*t_str!=0)                                             //ch库不够大
	{
		if (!strncmp(t_str,"吃",2))
		{
			k=rand()%4;
			if (k==0)
				*reply="火锅怎么样";
			else if (k==1)
				*reply="我觉得还是牛排最好吃";
			else if (k==2)
				*reply="还是推荐蔬菜沙拉";
			else if (k==3)
				*reply="你都这么胖了还想吃";
		}
		else if (!strncmp(t_str,"气",2))
		{
			k=rand()%4;
			if (k==0)
				*reply="阳光明媚，适合泡妹";
			else if (k==1)
				*reply="外面下着小雨，建议出门带伞";
			else if (k==2)
				*reply="大暴雨，还是开车吧";
			else if (k==3)
				*reply="阴天，凉爽舒适，是个户外运动的好日子";
		}
		else if (!strncmp(t_str,"啊",2))
		{
			k=rand()%3;
			if (k==0)
				*reply="我是靠谱的智能机器人，让我来协助你生活是个明智的选择";
			else if (k==1)
				*reply="我是智能机器人，请放心地将你的生活交给我";
			else if (k==2)
				*reply="我是一个体贴的机器人，您觉得我说的是对呢，还是非常对呢？";
		}
		else if (!strncmp(t_str,"游",2))
		{
			k=rand()%3;
			if (k==0)
				*reply="我不具有游戏功能，去蒸汽游戏平台吧，上面可有六万多个游戏";
			else if (k==1)
				*reply="你玩游戏玩得太多啦，今天还是歇歇吧";
			else if (k==2)
				*reply="听说最近他们都在玩吃鸡呢，你要去试试吗？";
		}
		else if (!strncmp(t_str,"人",2))
		{
			k=rand()%1;
			if (k==0)
				*reply="除了你我只认识肖力文和袁立凡他们是所有人里最帅的";
		}
		else
			*reply=NULL;
		t_str+=2;
		if (*reply!=NULL)
		{
			save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);
			//delay(2000);
			bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//清空要显示回复消息的区域
			show_reply(*reply,begin_y);	//开始显示回复消息
			///////////////////////put_image_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+345, window_save, begin_y);
			printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,*begin_y);
		}
		*reply=NULL;
	}
	if (no_keyword(str))
	{
		*reply="嗯嗯";
		save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);
			//delay(2000);
			bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//清空要显示回复消息的区域
			show_reply(*reply,begin_y);	//开始显示回复消息
			///////////////////////put_image_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+345, window_save, begin_y);
			printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,*begin_y);
	}
	/*
	free(t_qhwh);
	free(t_incode);
	t_incode=NULL;
	t_qhwh=NULL;
	free(ch);
	ch=NULL;
	*/
}


/**************

	给出回复

**************/
void show_reply(char *incode, int * begin_y)
{
	int x=ORIGINX+17,y;	//打印回复汉字的位置
	int box_top;	//对话框底顶部的纵坐标
	int i;			//temp
	int num_word=0;	//需要回复的字数
	int num_line;	//回复几行
	char *p_incode=incode;	//incode的位置指针

	/*************
	检查有几个字
	*************/
	while(*p_incode!=NULL)
	{
		p_incode+=2;
		num_word++;
	}

	/*************
	画对话框底
	*************/
	num_line = num_word/10+1;
	box_top = 345-20*num_line;
	if(num_word<=10){	//假如不到一行，则打印相应数量的框（宽度可调）
		bar_round_2(ORIGINX+13,ORIGINY+box_top,ORIGINX+17+num_word*16+4,ORIGINY+345,5,1,65535);
	}
	else{		//假如超过一行，则框的宽度定死，为最大宽度
		bar_round_2(ORIGINX+13,ORIGINY+box_top,ORIGINX+17+10*16+4,ORIGINY+345,5,1,65535);
	}

	/*************
	打印回复的汉字
	*************/
	i = 0;	//作字数标记
	y = ORIGINY+box_top+2;
	while(*incode!=NULL)
	{
		while( (i<10)&&(*incode!=NULL) )
		{
			dishz(x,y,1,1,incode,36410);
			i++;
			x+=16*1;
			incode+=2;
		}
		i=0;
		x=ORIGINX+17;
		y+=20*1;
	}

	/*************
	打印机器猫姓名
	*************/
	fdhz(ORIGINX+13+16*0,ORIGINY+box_top-20,1,1,"多",65535);
	fdhz(ORIGINX+13+16*1,ORIGINY+box_top-20,1,1,"啦",65535);
	fdhz(ORIGINX+13+16*2,ORIGINY+box_top-20,1,1,"啊",65535);
	fdhz(ORIGINX+13+16*3,ORIGINY+box_top-20,1,1,"梦",65535);

	/*************
	改变回复区域的占位记录值
	*************/
	//*y = ORIGINY+box_top-25;
	*begin_y = ORIGINY+50+20*num_line+25;

}




void show_main(int *qhwh,unsigned int *box_save)
{
	int num_qhwh;	//统计输入的字符数量
	int begin_y;	//标记每次对话框输出时的顶端y坐标以确定putimage的范围
	char *order = (char *)malloc(30*sizeof(char));	//之后标记到文件中的问句部分
	char *reply = (char *)malloc(30*sizeof(char));	//之后标记到文件中的答句部分
	char incode[30] ={0};

	/*when_press_ENTER
	save_image
	checkQhwhNum
	Check_QhwhNum>10_
	put_image
	draw_box
	delay
	put_image_moveup
	draw_box_moveup_standard_height
	draw_another_box*/

	if(order==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(reply==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(incode==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}

	/***************
	显示用户输入部分
	***************/
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);	//清空要显示用户输入消息的区域
	show_order(qhwh,&begin_y);	//开始显示用户输入消息
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);

	delay(500);	//等待机器人回复

	/***************
	显示机器人回复部分
	***************/

	//寻找匹配句
	//delay(2000);
	get_str( qhwh, incode);
	reply_match( incode, order, &reply,box_save,&begin_y);


	//释放空间
	free(order);
	order = NULL;
	free(reply);
	reply = NULL;


}

int no_keyword(char *str)
{
	int p=1;
	char *t_str=str;
	while (*t_str!=0)
	{
		if (!strncmp(t_str,"吃",2)  ||  !strncmp(t_str,"气",2)  ||  !strncmp(t_str,"你",2)  ||  !strncmp(t_str,"游",2)  ||  !strncmp(t_str,"人",2)  )
			p=0;
		t_str+=2;
	}
	return  p;
}

