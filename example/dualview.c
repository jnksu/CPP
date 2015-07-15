/*
 * dualview.c
 *
 *  Created on: 2014年3月8日
 *      Author: Mr_Li
 */

#include <stdio.h>
#include <stdlib.h>
/* 字节的位数 */
#define BYTES 8
/* 位字段常量				 */
/* 是否透明和是否可见           */
#define YES 1
#define NO 1
/* 边线框的样式                 */
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/* 三原色                       */
#define BLUE 4
#define GREEN 2
#define RED 1
/* 混合颜色                     */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

/* 位运算中使用的常量 */
#define FILL_BLUE  0x8
#define FILL_GREEN 0x4
#define FILL_RED   0x2
#define OPAQUE     0x1
#define FILL_MASK  0xE
#define BORDER        0x100
#define BORDER_BLUE   0x800
#define BORDER_GREEN  0x400
#define BORDER_RED    0x200
#define BORDER_MASK   0xE00
#define B_SOLID       0x0000
#define B_DOTTED      0x1000
#define B_DASHED      0x2000
#define STYLE_MASK    0x3000

const char * colors[8] = { "black", "red", "green",
 "blue", "magenta", "cyan", "white"};

typedef struct {
	unsigned int opaque       : 1;
	unsigned int fill_color   : 3;
	unsigned int 			  : 4;
	unsigned int show_border  : 1;
	unsigned int border_color : 3;
	unsigned int border_style : 2;
	unsigned int 			  : 2;
} BOX_PROPS;

typedef union{		/* 把数据看作结构或unsigned short 变量 */
	BOX_PROPS st_view;
	unsigned int ui_view;
}  VIEWS;

void show_settings(BOX_PROPS *);
void show_settings1(unsigned short);
char * itobs(int, char *);

int main(int argc, char ** argv)
{
	/* 创建Views对象, 初始化结构box view */
	VIEWS box = {{YES, YELLOW, YES, GREEN, DASHED}};
	char bin_str[8 * sizeof(unsigned int) + 1];

	printf("Original box settings:\n");
	show_settings(&box.st_view);
	printf("\n Box settings using unsigned int view:\n");
	show_settings1(box.ui_view);

	printf("bits are %s\n",
				itobs(box.ui_view, bin_str));
	box.ui_view &= ~FILL_MASK;	/* 把代充颜色的位清0 */
	box.ui_view |= (FILL_BLUE | FILL_GREEN); /* 重置填充色 */
	box.ui_view ^= OPAQUE;	/* 转置是否透明的位 */
	box.ui_view |= BORDER_RED; /* 错误的方法 */
	box.ui_view &= ~STYLE_MASK; /* 清除样式位 */
	box.ui_view |= B_DOTTED; /* 把样式设置为点 */

	printf("\nModifield box settings:\n");
	show_settings(&box.st_view);
	printf("\nBox settings using unsigned int view:\n");
	show_settings1(box.ui_view);
	printf("bits are %s\n",
			itobs(box.ui_view, bin_str));

	exit(EXIT_SUCCESS);
}

void show_settings(BOX_PROPS * pb)
{
	printf("Box is %s.\n",
		pb->opaque == YES ? "opaque" : "transparent");
	printf("The fill color is %s.\n", colors[pb->fill_color]);
	printf("Border %s.\n",
			pb->show_border == YES ? "shown" : "not shown");
	printf("The border color is %s.\n", colors[pb->border_color]);
	printf("The border style is ");
	switch(pb->border_style){
		case SOLID  : printf("solid.\n");
					 break;
		case DOTTED : printf("dotted.\n");
					 break;
		case DASHED : printf("dashed.\n");
					 break;
		default     : printf("unknown type.\n");
	}
}

void show_settings1(unsigned short us)
{
	printf("Box is %s.\n",
				us & OPAQUE == OPAQUE ? "opaque" : "transparent");
	printf("The fill color is %s.\n",
			colors[(us >> 1) & 07]);
	printf("Border %s.\n",
			us & BORDER == BORDER ? "show" : "not shown");
	printf("The border style is ");
	switch(us & STYLE_MASK){
	 case B_SOLID  : printf("solid.\n");  break;
	 case B_DOTTED : printf("dotted.\n"); break;
	 case B_DASHED : printf("dashed.\n"); break;
     default       : printf("unknown type.\n");
	}
	printf("The border color is %s.\n",
			colors[(us >> 9) & 07]);
}

/* 把int转换为二进制字符串 */
char * itobs(int n, char * ps)
{
	int index;
	static int size = BYTES * sizeof(unsigned int);

	for(index = size - 1; index >= 0; index--, n >>= 1)
		ps[index] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}
