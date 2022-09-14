#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//REFERENCES

//https://bilgisayarkavramlari.com/2008/02/21/dogrusal-sifreleme-affine-cipher/


struct PlainText{
	
	char text[30];
	
}object;

char Affine(int,int,int,char[]);

int main(int argc, char *argv[]) {
	
	//INDEXING STARTS -> 0
	
	//DO NOT FORGOT TO CREATE CipherText & PlainText FILES  

	
	// CRYPTION PART 
	
	FILE *readingPtr,*writingPtr;
	int i,j=0,index,A,B,LengthOfString;
	char MainText[30];
	int encodedChar;
	
	char Alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	printf("PLEASE ENTER A and B for AFFINE CIPHER?\n");
	printf("A->\n");
	scanf("%d",&A);
	printf("B->\n");
	scanf("%d",&B);
	


	if( ((writingPtr=fopen("CipherText.txt","r+"))==NULL) || ((readingPtr=fopen("PlainText.txt","r"))==NULL))
	printf("OPENING FILE ERROR!");
	else
	{
		while(!feof(readingPtr))
		{
			fscanf(readingPtr,"%s ",object.text);
			
			strcpy(MainText,object.text);
			
			strcpy(MainText,strupr(MainText));// getting Upper String for STANDARDIZATION
			
			LengthOfString=strlen(MainText);
			
			for(i=0;i<LengthOfString;i++,j++){
			
				if(MainText[i]>90 || MainText[i]<65) // controlling non-alphabetic & lowercase characters in the text and we ignored them.
					continue;
				
				encodedChar=(MainText[i]%65);
				fprintf(writingPtr,"%c",Affine(A,B,encodedChar,Alphabet));
			}
			
			fprintf(writingPtr,"%c",' ');// adding a space after a word 
			
			
		}
		
	}
	
	//END OF CRYPTION
	
	return 0;
}


char Affine(int A,int B,int Encoded,char Alphabet[]){
	
	
	return Alphabet[((A*Encoded)+B)%26];
	
}

