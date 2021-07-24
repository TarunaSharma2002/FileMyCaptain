#include<stdio.h>
#include<stdlib.h>

int fcpy(FILE * fp, FILE * fp2);

int main()
{
    FILE *fp, *fp2;
    int count;
 	char ch;
    int i,pos;
    fp=fopen("MyCapFile.txt","r");
    if(fp==NULL)
    {
    	printf("File does not exist..");
    }
    fseek(fp,0,SEEK_END);
    pos=ftell(fp);
    i=0;
    while(i<pos)
    {
        i++;
        fseek(fp,-i,SEEK_END);
        printf("%c",fgetc(fp));
        ch=fgetc(fp);
    }
      
      
    
    fp2=fopen("MyCapAnotherFile.txt","w");

   
    if (fp == NULL || fp2 == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read/write privilege.\n");

        exit(EXIT_FAILURE);
    }


    count = fcpy(fp, fp2);
    printf("\nFiles copied successfully.\n");



    /* Finally close files to release resources */
    fclose(fp);
    fclose(fp2);
    return 0;
}

int fcpy(FILE * fp, FILE * fp2)
{
    int  count = 0;
    char ch;

    /* Copy file contents character by character. */
    while ((ch = fgetc(fp)) != EOF)
    {
        fputc(ch, fp2);

        /* Increment character copied count */
        count++;
    }

    return count;
}

