#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//REFERENCES
// https://www3.nd.edu/~busiforc/handouts/cryptography/letterfrequencies.html 
// https://planetcalc.com/1434/


struct PlainText{
	
	char text[30];
	
}object;


int main(int argc, char *argv[]) {
	


	//CRYPTION
	
	FILE *readingPtr,*writingPtr;
	int i,j=0,index,LengthOfString,shift;
	char ExaminationText[30];
	int encodedChar;
	
	char Alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	printf("How many shift will be implemented?\n");
	scanf("%d",&shift);
	
	for(i=0;i<25;i++){
		Alphabet[i]=(((Alphabet[i]+shift)%65)%26)+65;
	}
	
	/*
	for(i=0;i<25;i++){
		printf("%c",Alphabet[i]); ->printing new alphabet
	}
	*/

	if( ((writingPtr=fopen("CipherText.txt","r+"))==NULL) || ((readingPtr=fopen("PlainText.txt","r"))==NULL))
	printf("OPENING FILE ERROR!");
	else
	{
		while(!feof(readingPtr))
		{
			fscanf(readingPtr,"%s ",object.text);
			
			strcpy(ExaminationText,object.text);
			strcpy(ExaminationText,strupr(ExaminationText));// getting Upper String
			LengthOfString=strlen(ExaminationText);
			
			for(i=0;i<LengthOfString;i++,j++){
			
				if(ExaminationText[i]>90 || ExaminationText[i]<65) // controlling non-alphabetic & lowercase characters.
					continue;
				
				encodedChar=(ExaminationText[i]%65);
				fprintf(writingPtr,"%c",Alphabet[encodedChar]);
			}
			
			fprintf(writingPtr,"%c",' '); // adding a space after a word
			
		}
		
	}
	
	//END OF CRYPTION
	
	return 0;
}

