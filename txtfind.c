
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "txtHeader.h"
#define lineLength 60
#define textLen 64000


int print_words(char *line, FILE *myFile, char *wordToFind){
    
    while(fgets(line, lineLength, stdin)) //there is another line in the file
    { 
        char *nextWord = strtok(line, " \n\t");
      
        while(nextWord != NULL) //there is another word in the line
        { 
            if(similar(nextWord, wordToFind, 1))
            {
                puts(nextWord);
               
            }
            nextWord = strtok(NULL, " \n\t");
        } 
    }
   
    return 0;
}

int print_lines(char *line, char *wordToFind){

    int indexLine=0;
    int indexWord =0;
    int lettersCounter = 0;
    
 
    while(*(line+indexLine) != '\0' && *(wordToFind+indexWord) != '\0')
    {
        if(*(line+indexLine) == *(wordToFind+indexWord))
        {
            lettersCounter++;
            indexWord++;
        }
        else
        {
            lettersCounter =0;
            indexWord=0;

        }
        indexLine++;
        
     }
    if(lettersCounter == strlen(wordToFind))
    {
        return 1;
    }

    return 0;
}



int similar(char *tempWord, char *theWord, int n)
{
    
    int lenTemp = strlen(tempWord);
    int lenPerm = strlen(theWord);
    
    if(*(tempWord + lenTemp-1) == '\r'){
    	lenTemp--;
    }
    
    int diffInLen = lenPerm - lenTemp;
    if(abs(diffInLen) > n)
    {
        return 0; //the words isnt similar because one has more then n different letters 
    }

    int countDiff = 0;
    int indexTemp =0;
    int indexPerm =0;
    for (int i = 0; i < lenTemp; i++)
    {

        if(*(tempWord+indexTemp) == *(theWord+indexPerm))
        {
            indexPerm++;
            indexTemp++;
        }
        else
        {
            countDiff++;
            indexTemp++;
        }
           
    }
    if(countDiff > n)
    {
        return 0;
    }

    return 1;
    
}


int main(int argc, char const *argv[])  
{


    char line[lineLength];
   
    fgets(line, lineLength, stdin); //gets the next (in this case first) line (line array == the first 							line)

    char * lineOne; 
    lineOne = strtok(line," \n\t"); //lineOne now points to the first letter in the first line that line array holds("c")
    int i=0;

    char word[50];
    char *wordToFind = lineOne; //char *wordToFind = lineOne; //wordToFind now points to the first letter in the first line that line array holds("c")

    while(*(wordToFind+i))
    {
        *(word+i) = *(lineOne+i);
        i++;
    }

    lineOne = strtok (NULL, " \n\t"); //takes the next word in the same line, lineOne points to it
    char *option = lineOne; //option now points where lineOne points = the second word in the line


    fgets(line, lineLength, stdin); //skipping over the empty second line in the text
    if(*option == 'a')
    {
       
        while(fgets(line, lineLength, stdin)){ //option a - printing lines
            if(print_lines(line, word)){
                printf("%s", line);
            }
        }
        
    }
    if(*option == 'b')
    {
        
        print_words(line, stdin, word); //option b - printing words
    }
    

    return 0;
}
