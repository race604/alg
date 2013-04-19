/*
 * =====================================================================================
 *
 *       Filename:  util.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/14/13 18:31:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wu Jing (jing), wujing@jike.com
 *        Company:  JIKE
 *
 * =====================================================================================
 */


#include <cstdlib>

long lrand()
{
	if (sizeof(int) < sizeof(long))
		return static_cast<long>(static_cast<long>(rand()) << (sizeof(int) * 8)) | rand();

	return rand();
}
