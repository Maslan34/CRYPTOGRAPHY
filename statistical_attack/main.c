#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	REFERENCES:
	
	https://www3.nd.edu/~busiforc/handouts/cryptography/letterfrequencies.html 
	https://planetcalc.com/1434/

*/
struct PlainText{
	
	char text[30];
	
}object;

int indexFinder(int,float[]);

int main(int argc, char *argv[]) {
	
	FILE *readingPtr,*writingPtr;
	int i,j=0,index,totalLetter=0,LengthOfString,index_find,index_encoded;
	char ExaminationText[30];
	char ExaminationChar;
	float temp=0.0f;

	
	char Letter_Probability[26]={'E','T','A','I','N','O','S','H','R','D','L','U','C','M','F','W','Y','G','P','B','V','K','Q','J','X','Z'};
	
	
	float Occurrencies_Letters[26]={0}; // A to Z
	float Sorted_Occurrencies_Letters[26];
	
	
	if( (readingPtr=fopen("CipherText.txt","r"))==NULL)
		printf("OPENING FILE ERROR!");
	else
	{
		while(!feof(readingPtr))
		{
			fscanf(readingPtr,"%s ",object.text);
			
		
			//printf("%c",object.text[3]);
			
			strcpy(ExaminationText,object.text);
			strcpy(ExaminationText,strupr(ExaminationText)); // getting Upper Str
			//printf("%s ",ExaminationText);
			LengthOfString=strlen(ExaminationText);
			
			
			for(i=0;i<LengthOfString;i++,j++){
				
				printf("%c",ExaminationText[i]);
				
				if(ExaminationText[i]>90 || ExaminationText[i]<65) 	// controlling nonalphabetic & lowercase characters.
					continue;
		
		
				index=(ExaminationText[i]%65);
				
				Occurrencies_Letters[index]+=1;
				totalLetter+=1;
			}
			
		}

	}
	//printf("\ntotal:%d\n",totalLetter); //->controlling
	
	fclose(readingPtr);
	
	for(i=0;i<26;i++){
		Occurrencies_Letters[i]=(Occurrencies_Letters[i]/totalLetter)*1000; //rating
	}
	
	for(i=0;i<26;i++){
		printf("\nThe rating of %c: %f\n",i+65,Occurrencies_Letters[i]);
	}
	
	
	
	//Copying Array Elements
	for(i=0;i<26;i++){
		Sorted_Occurrencies_Letters[i]=Occurrencies_Letters[i];
	}
	//Copying Array Elements
	
	
	
	//Sorting Array after getting rates
	for(i=0;i<26;i++)
		{
		    for(j=0;j<26-i-1;j++)
		    {
		        if(Sorted_Occurrencies_Letters[j]<Sorted_Occurrencies_Letters[j+1])
		        {
		            temp=Sorted_Occurrencies_Letters[j+1];//swaping element 
		            Sorted_Occurrencies_Letters[j+1]=Sorted_Occurrencies_Letters[j];
		            Sorted_Occurrencies_Letters[j]=temp;
		        }
		    }
		}
		/*
		printf("\n\nElement After Sorting \n\n");
		for(i= 0; i< 26; i++) 
		{
		    printf("%.2f  ", Sorted_Occurrencies_Letters[i]);
		
				printf("\n\n");
	}
*/

	//DECRYPTION
	if( ((writingPtr=fopen("ResultText.txt","w"))==NULL) || ((readingPtr=fopen("CipherText.txt","r"))==NULL))
		printf("OPENING FILE ERROR!");
	else
	{
		while(!feof(readingPtr))
		{
			fscanf(readingPtr,"%s ",object.text);
			//ExaminationText[]=object.text;
			
			//printf("%s->text\n",object.text); ->cant assignt it this way
			//printf("%c",object.text[3]);
			
			strcpy(ExaminationText,object.text);
			strcpy(ExaminationText,strupr(ExaminationText));// getting Upper Str
			//printf("ExaminationText->%s ",ExaminationText);
			LengthOfString=strlen(ExaminationText);
			
			
			for(i=0;i<LengthOfString;i++,j++){
				
				if(ExaminationText[i]>90 || ExaminationText[i]<65) 	// controlling nonalphabetic & lowercase characters.
					continue;
					
				index_find=(ExaminationText[i]%65);
				//printf("\nindexFind->%c\n",index_find+65);
				
				
				index_encoded=indexFinder(Occurrencies_Letters[index_find],Sorted_Occurrencies_Letters);
				
				fprintf(writingPtr,"%c",Letter_Probability[index_encoded]);
			}
			fprintf(writingPtr,"%c",' ');
			
		}
		
	}
	//END OF DECRYPTION
	
	
	//CRYPTION
	/*
	FILE *readingPtr,*writingPtr;
	int i,j=0,index,LengthOfString,shift;
	char ExaminationText[30];
	int encodedChar;
	
	char Alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	printf("How many shift will be executed?\n");
	scanf("%d",&shift);
	
	for(i=0;i<25;i++){
		Alphabet[i]=(((Alphabet[i]+shift)%65)%26)+65;
	}
	
	for(i=0;i<25;i++){
		printf("%c",Alphabet[i]);
	}
	

	if( ((writingPtr=fopen("CipherText.txt","r+"))==NULL) || ((readingPtr=fopen("PlainText.txt","r"))==NULL))
	printf("OPENING FILE ERROR!");
	else
	{
		while(!feof(readingPtr))
		{
			fscanf(readingPtr,"%s ",object.text);
			
			strcpy(ExaminationText,object.text);
			strcpy(ExaminationText,strupr(ExaminationText));// getting Upper Str
			LengthOfString=strlen(ExaminationText);
			
			printf("\n%s\n",ExaminationText);
			for(i=0;i<LengthOfString;i++,j++){
			
				if(ExaminationText[i]>90 || ExaminationText[i]<65) // controlling nonalphabetic & lowercase characters.
					continue;
				
				encodedChar=(ExaminationText[i]%65);
				printf("\n*%c*\n",Alphabet[encodedChar]);
				fprintf(writingPtr,"%c",Alphabet[encodedChar]);
			}
			
			fprintf(writingPtr,"%c",' ');
			
		}
		
	}
	
	//END OF CRYPTION
	*/
	return 0;
}

	int indexFinder(int indexValue, float sorted_arr[]){
		
		int rvalue=0;
		
		while (indexValue<sorted_arr[rvalue]){
			rvalue++;
		}
		
		//printf("\nrvalue->%d\n",rvalue-1);
		return rvalue-1;
	}
