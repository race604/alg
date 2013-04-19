/*
 * =====================================================================================
 *
 *       Filename:  cyclicShift.cpp
 *
 *    Description:  循环移位字符串
 *
 *        Version:  1.0
 *        Created:  04/19/13 18:44:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wu Jing (jing), wujing@jike.com
 *        Company:  JIKE
 *
 * =====================================================================================
 */

#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/* 求最大公约数 */
int gcd(int i,int j)
{
	while(i != j )
	{
		if(i > j)
			i = i - j;
		else
			j = j - i;
	}
	return i;
}

/* 
 * 逐个交换
 * tmp <- s[0] <- s[k] <- s[k] ...
 * */
void shift(char* str, int k) {
	int len = strlen(str);
	if (k == 0 || len <= 2) {
		return;
	}

	k %= len;
	if (k == 0) {
		return;
	}

	char tmp;

	int numgcd = gcd(len, k);

	for(int i=0; i<numgcd; ++i) {
		tmp = str[i];
		int m = i;
		int n = (i+k)%len;
		while(n != i) {
			str[m] = str[n];
			m = n;
			n += k;
			if (n >= len) {
				n -= len;
			}
		}
		str[m] = tmp;
	}
}

/* 
 * 字符串求逆
 * 把字符串start到end之间的字符串逆转
 * */
void reverse(char* str, int start, int end) {
	char t;
	while(start < end){
		t = str[start];
		str[start] = str[end];
		str[end] = t;
		start++;
		end--;
	}
}

/* 
 * 使用Doug Macllrory方法，对字符串分别求逆，然后整体求逆
  */
void shift2(char* str, int k) {
	int len = strlen(str);
	k = k % len;

	reverse(str, 0, k-1);
	reverse(str, k, len-1);
	reverse(str, 0, len-1);
}

int main(int argc, char** args) {
	if(argc < 3) {
		return 0;
	}

	char* str = args[1];
	int k = atoi(args[2]);

	//shift(str, k);
	shift2(str, k);

	cout << str << endl;

	return 0;
}

