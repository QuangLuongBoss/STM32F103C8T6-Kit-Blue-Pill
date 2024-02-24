#include "string_lib.h"

uint8_t String_Length(const char *s){
	uint8_t len=0;
	while(*s != 0){
		len++;
		s++;
	}
	return len;
}

// uint8_t String_String(char *s1, char *s2){
// 	uint8_t flag=0,i=0, i1, i2;
// 	if(String_Length(s2) > String_Length(s1))	return 0;
// 	while(s1[i] != NULL){
// 		i1 = i;
// 		i2 = 0;
// 		while(s1[i1] != NULL && s2[i2] != NULL){
// 			if(s2[i2++] != s1[i1++]){
// 				flag=0;
// 				break;
// 			}
// 			else	flag = 1;
// 		}
// 		i++;
// 		if(flag)	return flag;
// 	}
// 	return flag;
// }
 uint8_t	String_Compare(char *s1, char *s2){
 	if(String_Length(s1) != String_Length(s2)) return 0;
 	else{
 		uint16_t i;
 		uint16_t len = String_Length(s1);
 		for(i=0 ; i<len ; i++){
 			if(s1[i] != s2[i])	return 0;
 		}
 		return 1;
 	}
 }

