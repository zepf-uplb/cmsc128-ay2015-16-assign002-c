/*
* Name : Franz Joezepf C. Dinglasan
* Section : CMSC128 AB-6L
* Date Finished : March 7, 2016
* Program Description : The file contains a library containing
* simple bioinformatics functions.
*/
#include <stdio.h>
#include <string.h>
#define LEN 20

int getHammingDistance(char str1[LEN], char str2[LEN]);
int countSubstrPattern(char original[LEN], char pattern[LEN]);
int isValidString(char str[LEN], char alphabet[LEN]);
int getSkew(char str[LEN], int n);
int getMaxSkew(char str[LEN], int n);
int getMinSkew(char str[LEN], int n);

/*returns the number of inversions per character
between two strings*/
int getHammingDistance(char str1[LEN], char str2[LEN]){
	int i, hamDist = 0;
	if(strlen(str1) != strlen(str2)){
		printf("Error! Strings are not equal!\n");
		return -1;
	}
	for(i = 0; i < strlen(str1); i++){
		if(str1[i] != str2[i]) hamDist++;
	}
	return hamDist;
}

/*returns the number of times the pattern appeared
in the original*/
int countSubstrPattern(char original[LEN], char pattern[LEN]){
	int i, j, k, count = 0;
	if(strlen(pattern) > strlen(original)) return count;
	for(i = 0; i < strlen(original); i++){
		for(j = 0, k = 0; j < strlen(pattern); j++){
			if( original[i+j] != pattern[j] ) break;
			else k++;
		}
		if( k == strlen(pattern) ) count++;
	}
	return count;
}

/*determines if the given string can be defined by
the given alphabet*/ 
int isValidString(char str[LEN], char alphabet[LEN]){
	int i, j;
	for(i = 0; i < strlen(str); i++){
		for(j = 0; j < strlen(alphabet); j++){
			if(str[i] == alphabet[j]) break;
			if(j == strlen(alphabet)-1) return 0;
		}
	}
	return 1;
}

/*returns the number of Gs minus the number of Cs in 
the first n characters*/
int getSkew(char str[LEN], int n){
	int i, g = 0, c = 0;
	if(n <= 0){
		printf("Invalid Parameter.\n");
		return n;
	}
	for(i = 0; i < n; i++){
		if(str[i] == 'G') g++;
		if(str[i] == 'C') c++;
	}
	return g-c;
}

/*returns the maximum skew among the first n characters*/
int getMaxSkew(char str[LEN], int n){
	int i, max;
	if(n <= 0){
		printf("Invalid Parameter.\n");
		return n;
	}	
	max = getSkew(str, 1);
	for(i = 2; i < n+1; i++){
		if(getSkew(str, i) > max) 
			max = getSkew(str, i);
	}
	return max;

}

/*returns the minimum skew among the first n characters*/
int getMinSkew(char str[LEN], int n){
	int i, min;
	if(n <= 0){
		printf("Invalid Parameter.\n");
		return n;
	}	
	min = getSkew(str, 1);
	for(i = 2; i < n+1; i++){
		if(getSkew(str, i) < min) 
			min = getSkew(str, i);
	}
	return min;	
}