/*lesser.c--找出两个整数中的较小者*/
 #include <stdio.h>
 
 int imin(int para,int para1);
 
 int main(void)
 {
	 int evil,evil1;
	 
	 printf("Enter a pair of integer(q to quit):\n");
	 
	 while(scanf("%d %d",&evil,&evil1) == 2)
	 {
		 printf("The lesser of %d and %d is %d\n",evil,evil1,imin(evil,evil1));
		 printf("Enter a pair of integers(q to quit):\n");
	 }
	 printf("Bye.\n");
	 
	 return 0;
 }
 
 int imin(int para,int para1)
 {
	 int min;
	 
	 min = para < para1 ? para : para1;
	 
	 return min;
 }