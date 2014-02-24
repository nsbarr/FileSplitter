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
    FILE *originalFile = fopen("a/everyword.txt", "r");
    FILE *outputFile = fopen("a/lettersthatfollow_aa.txt", "w");
    char line [MAXLINE];
    char currentFirstLetter = 'a';
    char currentSecondLetter = 'a';
    char currentThirdLetter = '5';
    
    
    while (fgets(line, MAXLINE, originalFile) != NULL && line[0] != '\n')
        
        if (line[0] == currentFirstLetter && line[1] == currentSecondLetter) {
            if (line[2] != currentThirdLetter) {
                fputc(line[1], outputFile);
                currentThirdLetter = line[2];
            }
            
            
        }
        else {
            currentThirdLetter = '5';
            currentFirstLetter = line[0];
            currentSecondLetter = line[1];
            
            char buffer[32];
            snprintf(buffer, sizeof(char) * 32, "a/lettersthatfollow_%c%c.txt", currentFirstLetter, currentSecondLetter);
            outputFile = fopen(buffer, "w");
            if (line[2] != currentThirdLetter) {
                fputc(line[2], outputFile);
                currentThirdLetter = line[2];
            }
        }
    return 0;
}













