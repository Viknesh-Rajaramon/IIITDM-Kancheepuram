#include<stdio.h>
#include<dir.h>

void main()
{
    FILE *ptr=fopen("C:/Users/admin/Documents/IIITDM KANCHEEPURAM/Studies/Computer Organization and Design Practice/Lab/File IO/12.txt","r");
    FILE *newptr=fopen("C:/Users/admin/Documents/IIITDM KANCHEEPURAM/Studies/Computer Organization and Design Practice/Lab/File IO/16.txt","w");
    char c;
    char s[100];
    printf("\nEnter the string to be inserted in the file : ");
    gets(s);
    c=fgetc(ptr);
    while((c!=EOF) && (c!='\n'))
    {
        fputc(c,newptr);
        c=fgetc(ptr);
    }
    c='\n';
    fputc(c,newptr);
    fputs(s,newptr);
    while(c!=EOF)
    {
        fputc(c,newptr);
        c=fgetc(ptr);
    }
    fclose(ptr);
    fclose(newptr);
}
