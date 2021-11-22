/*
1. Receive a maximum 4-digit integer n. Write a program to read the number n.
 ________________________________________________
| Input: 1234                                    |
| Output: one thousand two hundred thirty four   |
|________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Ex1(char* n){
	//Your codes here
	int len = strlen(n);
    if (len == 0) {
        fprintf(stderr, "empty string\n");
        return;
    }
    if (len > 4) {
        fprintf(stderr,"Length more than 4 is not supported\n");
        return;
    }
    char* single_digits[]= { "zero","one","two","three","four","five", "six", "seven", "eight", "nine"};
    char* two_digits[]= { "","ten","eleven","twelve","thirteen","fourteen", "fifteen", "sixteen","seventeen","eighteen","nineteen" };
    char* tens_multiple[] = { "","","twenty","thirty","forty","fifty","sixty", "seventy", "eighty", "ninety"};
    char* tens_power[] = { "hundred", "thousand" };
    if (len == 1) {
        printf("%s\n", single_digits[*n - '0']);
        return;
    }
    while (*n != '\0') {
        if (len >= 3) {
            if (*n - '0' != 0) {
                printf("%s ", single_digits[*n - '0']);
                printf("%s ",tens_power[len - 3]);
            }
            --len;
        }
        else {
            if (*n == '1') {
                int sum = *n - '0' + *(n+ 1) - '0';
                printf("%s\n", two_digits[sum]);
                return;
            }
            else if (*n == '2' && *(n + 1) == '0') {
                printf("twenty\n");
                return;
            }
            else {
                int i = *n - '0';
                printf("%s ", i ? tens_multiple[i] : "");
                ++n;
                if (*n != '0') printf("%s ",single_digits[*n - '0']);
            }
        }
        ++n;
    }
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *temp = argv[1];
	
	Ex1(temp);
	
	return 0;
}
