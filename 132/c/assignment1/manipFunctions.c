/* 
 * manipFunctions.c
 * 
 * This source file defines all the functions used to bit manipulate
 *
 */

#include "manipFunctions.h"

int hasAOne(int num) {
  return ((num & 1) | ( num >> 1 & 1) |( num >> 2 & 1) |( num >> 3 & 1) |( num >> 4 & 1) |( num >> 5 & 1) |( num >> 6 & 1) |( num >> 7 & 1) |( num >> 8 & 1) |( num >> 9 & 1) |( num >> 10 & 1) |( num >> 11 & 1) |( num >> 12 & 1) |( num >> 13 & 1) |( num >> 14 & 1) |( num >> 15 & 1) |( num >> 16 & 1) |( num >> 17 & 1) |( num >> 18 & 1) |( num >> 19 & 1) |( num >> 20 & 1) |( num >> 21 & 1) |( num >> 22 & 1) |( num >> 23 & 1) | ( num >> 24 & 1) |( num >> 25 & 1) |( num >> 26 & 1) |( num >> 27 & 1) |( num >> 28 & 1) |( num >> 29 & 1) |( num >> 30 & 1) |( num >> 31 & 1)) ;
}

int hasAZero(int num) {
  return (~num || 0) ; 
}

int leastSigHasAOne(int num) {
  return((num & 1) | ( num >> 1 & 1) |( num >> 2 & 1) |( num >> 3 & 1) |( num >> 4 & 1) |( num >> 5 & 1) |( num >> 6 & 1) |( num >> 7 & 1)) ;
}

int negate(int num) {
  return ~num + 1 ;
}

int isNegativeInt(int num) {
  return (num >> 31 && 1);
}

int isNegativeLong(long num) {
  return (num >> 63 && 1);
}

int isNegativeChar(char num) {
  return (num >> 7 && 1);
}
