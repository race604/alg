/*
 * =====================================================================================
 *
 *       Filename:  bitmap.cpp
 *
 *    Description:  implement bit map data stracture
 *
 *        Version:  1.0
 *        Created:  04/14/13 16:47:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wu Jing (jing), wujing@jike.com
 *        Company:  JIKE
 *
 * =====================================================================================
 */

#include <memory.h>
#include "bitmap.h"

Bitmap::Bitmap(long size) : size(size){
	if (size > 0) {
		long byte = (size >> 3) + 1; // convert to bytes
		map = new char[byte];
		memset(map, 0, byte);
	} else {
		map == NULL;
	}
}

Bitmap::~Bitmap(){
	if (map) {
		delete[] map;
	}
}

void Bitmap::setBit(long index) {
	if (index < size) {
		long byte = index >> 3;
		unsigned char i = (unsigned char)(index & 0x07);
		map[byte] |= (1 << i);
	}
}

void Bitmap::clearBit(long index) {
	if (index < size) {
		long byte = index >> 3;
		unsigned char i = (unsigned char)(index & 0x07);
		map[byte] &= (~(1 << i));
	}
}

bool Bitmap::getBit(long index) {
	if (index < size) {
		long byte = index >> 3;
		unsigned char i = (unsigned char)(index & 0x07);
		return map[byte] & (1 << i) != 0;
	}
}
