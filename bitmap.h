/*
 * =====================================================================================
 *
 *       Filename:  bitmap.h
 *
 *    Description:  Implement bit map data stracture
 *
 *        Version:  1.0
 *        Created:  04/14/13 16:47:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wu Jing (jing), wujing@jike.com
 *        Company:  JIKE
 *
 * =====================================================================================
 */

class Bitmap {
public:
	Bitmap(long size);
	void setBit(long index);
	void clearBit(long index);
	bool getBit(long index);
	virtual ~Bitmap();

private:
	long size;
	char* map;
};

