
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "txtHeader.h"
#define lineLength 256
#define textLen 260


int print_words(char *line, FILE *myFile, char *wordToFind){
    
    while(fgets(line, lineLength, myFile)) //there is another line in the file
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

int print_lines(char *line, FILE *myFile, char *wordToFind){

    int indexLine=0;
    int indexWord =0;
    int lettersCounter = 0;
    
    // while(fgets(line, lineLength, myFile)) //there is another line in the file
    // { 
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

    char text[textLen];
    scanf("%s", text);

    FILE *myFile;
    char line[lineLength];

    myFile = fopen(text, "r"); //open the file to read
    fgets(line, lineLength, myFile); //gets the next (in this case first) line (line array == the first line)
    
    
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


    fgets(line, lineLength, myFile); //skipping over the empty second line in the text
    if(*option == 'a')
    {
        //call func1 - print_lines
        while(fgets(line, lineLength, myFile)){
            if(print_lines(line, myFile, word)){
                printf("%s", line);
            }
        }
        
    }
    if(*option == 'b')
    {
        //call func2 - print_similar_words
        print_words(line, myFile, word);
    }
    
    fclose(myFile);

    return 0;
}
