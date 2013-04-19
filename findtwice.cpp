/*
 * =====================================================================================
 *
 *       Filename:  findtwice.cpp
 *
 *    Description:  在一个包含至少4300000000个32位整数的文件中，查找至少出现一次的整数
 *
 *        Version:  1.0
 *        Created:  04/19/13 11:14:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wu Jing (jing), wujing@jike.com
 *        Company:  JIKE
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int findtwice(int* arr, int len) {
	int l = 0;
	int h = len - 1;
	int m;
	
	int size;
	int cnt;

	while (h > l) {
		m = (l+h)/2;
		size = m - l + 1;
		cnt = arr[m] - arr[l] + 1;
		if (cnt == 1) {
			return arr[m];
		} else {
			if (size > cnt) {
				h = m;
			} else {
				l = m;
			}
		}
	}
	
	return arr[h];
}

int main(int argc, char** args) {
	int len = argc - 1;

	if (len > 0) {

		int* arr = new int[len];

		for(int i=0; i<len; ++i) {
			arr[i] = atoi(args[i+1]);
			cout << arr[i] << " ";
		}
		
		cout << endl;

		cout << "result:" << findtwice(arr, len) << endl;

		delete[] arr;
	}

	return 0;
}
