#include "digui.h"
/*
电话号码对应的字符组合：在电话或者手机上，一个数字如2对应着字母ABC，7对应着PQRS。
那么数字串27所对应的字符的可能组合就有3*4=12种（如AP，BR等）。现在输入一个3到11位长
的电话号码，请打印出这个电话号码所对应的字符的所有可能组合和组合数。
*/

/*
分析、算法：
char conver[][];将数字与字母的对应存起来。行代表需要转换的数字。
phone[];输入的电话号码，将号码存入一个数组。
函数：
int p=0;从号码的第p位开始;phone[p]是此位号码上的数字。
conver数组上第phone[p]行上便是phone[p]对应的字母。
int i=0；conver[phone[p]][i]是此数字对应的第一个字母。
p+1再次调用Conver函数；
...
直至到最后一个数字完毕打印输出。（判断语句）
i++;（此时应用一个for循环）
*/
char phone[11];//电话号码
char combine[11];//字母组合
const char conver[10][4] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
const int sum[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
int count = 0;
void Conver(int p, int len){
	if (p == len){
		combine[len] = '\0';//加上结束字符
		printf("%s\n", combine);
		count++;
	}
	else{
		for (int i = 0; i < sum[phone[p]]; i++){
			combine[p] = conver[phone[p]][i];
			Conver(p + 1, len);
		}
	}
}

void main(){
	printf("请输入一个3-11位的电话号码：");
	scanf("%s", phone);//char型
	int len = strlen(phone);
	//转换类型
	for (int i = 0; i < len; i++){
		phone[i] = phone[i] - '0';
	}
	Conver(0, len);
	printf("组合数：%d\n", count);
	system("pause");
}
