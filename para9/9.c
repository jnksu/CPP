 /*以不同的进制输出整数*/
 #include <stdio.h>
 void to_base_n(unsigned int para,unsigned short int para1);
 int main(void)
 {
	 to_base_n(65535,2);
	 return 0;
 }
 void to_base_n(unsigned int para,unsigned short int para1)
 {
	 if(para < para1){
		 printf("%u",para);
		 return;
	 }
	 to_base_n((para / (unsigned int)para1),para1);
	 printf("%u",(unsigned int)para % para1);
 }