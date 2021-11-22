/*
2. Receive n strings from the input and sort them ascendingly.
Ex:
 _________________________________________
| Input: one two three                    |
| Output: one three two                   |
|_________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int compare_char(char a[], char b[]){
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0')  {  
        if(a[i] > b[i]) return 1; 
        if(a[i] < b[i]) return -1;
        i++;
    }  
}


void Ex2(int n, char *str[]){
    char *temp;
    for (int i = 0; i <= n-1; ++i) {
        for (int j = i + 1; j <= n-1; ++j) {
            if (compare_char(str[i], str[j]) > 0) {
                char *str1 = str[i], *str2 = str[j];
                temp = str1;
                str1 = str2;
                str2 = temp;
                str[i] = str1; str[j] = str2;
            }
        }
    }
    for(int i = 0; i <= n-1; ++i){
		printf("%s ",str[i]);
	}
}


int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	char *testcase[argc];
	int i;
	for(i=0; i<argc; i++){
		testcase[i] = argv[i+1];
	}
	
	Ex2(argc, testcase);
	
	return 0;
}
