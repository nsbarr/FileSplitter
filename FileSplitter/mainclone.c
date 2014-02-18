//
//  main.c
//  FileSplitter
//
//  Created by Nicholas Barr on 2/17/14.
//  Copyright (c) 2014 Nick Barr. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXLINE 50

int main(void)
{
    FILE *originalFile = fopen("foo/everyword.txt", "r");
    FILE *outputFile = fopen("foo/lettersthatfollow_a.txt", "w");
    char line [MAXLINE];
    char currentFirstLetter = 'a';
    char currentSecondLetter = '5';
    
    
    while (fgets(line, MAXLINE, originalFile) != NULL && line[0] != '\n')
        
        if (line[0] == currentFirstLetter) {
            if (line[1] != currentSecondLetter) {
                fputc(line[1], outputFile);
                currentSecondLetter = line[1];
            }
            

        }
        else {
            currentSecondLetter = '5';
            currentFirstLetter = line[0];
            
            char buffer[32];
            snprintf(buffer, sizeof(char) * 32, "foo/lettersthatfollow_%c.txt", currentFirstLetter);
            outputFile = fopen(buffer, "w");
            if (line[1] != currentSecondLetter) {
                fputc(line[1], outputFile);
                currentSecondLetter = line[1];
            }
        }
    return 0;
}