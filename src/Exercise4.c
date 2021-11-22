/*
4. Receive a string, remove all blank spaces at begin and
end of the string and leave only one blank space between words.
Ex:
 ________________________________________________
| Input: "  this  is an   unformatted  string "  |
| Output: this is an unformatted string          |
|________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void Ex4(char *str){
	//Your codes here
	int temp = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] != ' '){
            printf("%c", str[i]);
            temp = 0;
        }else{
            if(temp == 0) {
				printf(" ");
			}
            temp++;
        }
    }
}


int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *testcase = argv[1];

	Ex4(testcase);

	return 0;
}