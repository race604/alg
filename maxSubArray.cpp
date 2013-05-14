/*
 * =====================================================================================
 *
 *       Filename:  maxSubArray.cpp
 *
 *    Description:  求最大的子串
 *
 *        Version:  1.0
 *        Created:  05/14/2013 10:34:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wu Jing (jing), race604@gmail.com
 *        Company:  bupt
 *
 * =====================================================================================
 */
#include <stdio.h>

typedef struct _maxsub{
	int start;
	int end;
	int sum;

	_maxsub() {
		start = 0;
		end = 0;
		sum = 0;
	}
} MaxSub;

MaxSub findMaxSubArray(int arr[], int len) {
	MaxSub maxSub;
	if (len <=0) {
		return maxSub;
	}

	int* subs = new int[len*2];

	subs[0] = 0;
	subs[1] = arr[0];

	int max = subs[1];
	int index = 0;

	for(int i=1; i<len; ++i) {
		int sum = subs[2*(i-1) + 1] + arr[i];
		if (sum > arr[i]) {
			subs[2*i] = subs[2*(i-1)];
			subs[2*i + 1] = sum;
		} else {
			subs[2*i] = i;
			subs[2*i + 1] = arr[i];
		}

		if(subs[2*i + 1] > max) {
			index = i;
		}
	}

	maxSub.start = subs[2*index];
	maxSub.end = index;
	maxSub.sum = subs[2*index+1];

	return maxSub;
}

int main(void) {
	int arr[] = {-3, 1, 2 ,3, -5, 4, -1, 3};
	MaxSub max = findMaxSubArray(arr, 8);

	printf("start=%d, end=%d, sum=%d\n", max.start, max.end, max.sum);
}
