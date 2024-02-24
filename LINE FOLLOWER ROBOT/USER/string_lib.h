/*
	********************************************************************************************
	*@file				string_lib.h																									*
	*@author			Vu Quang Luong																								*
	*@date				28/04/2023																										*
	********************************************************************************************
*/

#ifndef __STRING_LIB__
#define __STRING_LIB__

#ifdef __cplusplus
	extern "C"{
#endif

#include "stdio.h"
#include "stdint.h"

// uint8_t		String_Compare(char *s1, char *s2);
// uint8_t		String_String(char *s1, char *s2);
uint8_t	String_Length(const char *s);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ***********************************************/
/*********************************************************************************************/

