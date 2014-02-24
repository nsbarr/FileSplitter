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
    FILE *originalFile = fopen("doubleletter/everyword.txt", "r");
    FILE *outputFile = fopen("doubleletter/lettersthatfollow_a.txt", "w");
    char line [MAXLINE];
    char currentFirstLetter = 'a';
    char currentSecondLetter = 'a';
    
    
    while (fgets(line, MAXLINE, originalFile) != NULL && line[0] != '\n')
        
        if (line[0] == currentFirstLetter) {
            if (line[1] == currentSecondLetter) {
                fputc(line[2], outputFile);
                
            }
            else if (line[1] != currentSecondLetter) {
                currentSecondLetter = line[1];
                char buffer[32];
                snprintf(buffer, sizeof(char) * 32, "doubleletter/lettersthatfollow_%c.txt", currentFirstLetter);
                outputFile = fopen(buffer, "w");
                fputc(line[2], outputFile);

            }
            

        }
        else {
            currentFirstLetter = line[0];
            currentSecondLetter = line[1];
            
            char buffer[32];
            snprintf(buffer, sizeof(char) * 32, "doubleletter/lettersthatfollow_%c.txt", currentFirstLetter);
            outputFile = fopen(buffer, "w");
            fputc(line[2], outputFile);
            
        }
}













