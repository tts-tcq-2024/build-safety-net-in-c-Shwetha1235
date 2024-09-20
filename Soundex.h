#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include "Soundex.h"
#include <ctype.h>
#include <string.h>
 
char getSoundexCode(char c) {
static const char soundexMap[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', 
        '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    return soundexMap[toupper(c) - 'A'];} // Map uppercase letter 'c' to its Soundex code.
 
void processChar(char name, char *soundex,int *index){
     char code = getSoundexCode(name);
     if (code != '0' && code != soundex[*index - 1]) {
         soundex[(*index)++] = code;
     } 
}
 
void handleName(const char *name, int *index, int len, char *soundex) {
    for (int i = 1; i < len && *index < 4; i++) {
        processChar(name[i],soundex,index);
    }    
}
 
void padWithZeros(int sIndex, char *soundex) {
        while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
}
 
 
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    handleName(name,&sIndex,len,soundex);
    padWithZeros(sIndex,soundex);
    soundex[4] = '\0';
}
#endif // SOUNDEX_H
