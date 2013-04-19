/*
 * =====================================================================================
 *
 *       Filename:  BitmapTest.cpp
 *
 *    Description:  test Bitmap class
 *
 *        Version:  1.0
 *        Created:  04/14/13 17:35:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wu Jing (jing), wujing@jike.com
 *        Company:  JIKE
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include "bitmap.h"
#include "util.h"

using namespace std;

int main(int argc, char** args) {
	const long MAX = 100;
	const long NUM = 50;


	srand((unsigned)time(NULL));

	Bitmap* bmp = new Bitmap(MAX);

	cout << "============ Random data ============" << endl;

	for (long i=0; i<NUM; ++i) {
		long v = lrand() % MAX;
		cout << v << endl;
		bmp->setBit(v);
	}
	
	cout << "============ Sorted data ============" << endl;
	for (long i=0; i<MAX; ++i) {
		if (bmp->getBit(i))
			cout << i << endl;
	}
	
}
