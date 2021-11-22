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

void Ex1(char* num){
	//Your codes here
	int len = strlen(num);
 
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
        printf("%s\n", single_digits[*num - '0']);
        return;
    }

    while (*num != '\0') {
        if (len >= 3) {
            if (*num - '0' != 0) {
                printf("%s ", single_digits[*num - '0']);
                printf("%s ",tens_power[len - 3]);
            }
            --len;
        }
        else {
            if (*num == '1') {
                int sum = *num - '0' + *(num + 1) - '0';
                printf("%s\n", two_digits[sum]);
                return;
            }
            else if (*num == '2' && *(num + 1) == '0') {
                printf("twenty\n");
                return;
            }
            else {
                int i = *num - '0';
                printf("%s ", i ? tens_multiple[i] : "");
                ++num;
                if (*num != '0') printf("%s ",single_digits[*num - '0']);
            }
        }
        ++num;
    }
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *t = argv[1];
	
	Ex1(t);
	
	return 0;
}
