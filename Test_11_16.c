#include "digui.h"
/*
�绰�����Ӧ���ַ���ϣ��ڵ绰�����ֻ��ϣ�һ��������2��Ӧ����ĸABC��7��Ӧ��PQRS��
��ô���ִ�27����Ӧ���ַ��Ŀ�����Ͼ���3*4=12�֣���AP��BR�ȣ�����������һ��3��11λ��
�ĵ绰���룬���ӡ������绰��������Ӧ���ַ������п�����Ϻ��������
*/

/*
�������㷨��
char conver[][];����������ĸ�Ķ�Ӧ���������д�����Ҫת�������֡�
phone[];����ĵ绰���룬���������һ�����顣
������
int p=0;�Ӻ���ĵ�pλ��ʼ;phone[p]�Ǵ�λ�����ϵ����֡�
conver�����ϵ�phone[p]���ϱ���phone[p]��Ӧ����ĸ��
int i=0��conver[phone[p]][i]�Ǵ����ֶ�Ӧ�ĵ�һ����ĸ��
p+1�ٴε���Conver������
...
ֱ�������һ��������ϴ�ӡ��������ж���䣩
i++;����ʱӦ��һ��forѭ����
*/
char phone[11];//�绰����
char combine[11];//��ĸ���
const char conver[10][4] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
const int sum[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
int count = 0;
void Conver(int p, int len){
	if (p == len){
		combine[len] = '\0';//���Ͻ����ַ�
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
	printf("������һ��3-11λ�ĵ绰���룺");
	scanf("%s", phone);//char��
	int len = strlen(phone);
	//ת������
	for (int i = 0; i < len; i++){
		phone[i] = phone[i] - '0';
	}
	Conver(0, len);
	printf("�������%d\n", count);
	system("pause");
}
