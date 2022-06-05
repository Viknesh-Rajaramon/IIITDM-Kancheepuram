#include<stdio.h>
#include<dir.h>

void main()
{
    FILE *ptr=fopen("C:/Users/admin/Documents/IIITDM KANCHEEPURAM/Studies/Computer Organization and Design Practice/Lab/File IO/12.txt","r");
    FILE *newptr=fopen("C:/Users/admin/Documents/IIITDM KANCHEEPURAM/Studies/Computer Organization and Design Practice/Lab/File IO/15.txt","w");
    char c;
    c=fgetc(ptr);
    while((c!=EOF) && (c!='\n'))
    {
        fputc(c,newptr);
        c=fgetc(ptr);
    }
    fputs("\n2nd Year COE",newptr);
    while(c!=EOF)
    {
        fputc(c,newptr);
        c=fgetc(ptr);
    }
    fclose(ptr);
    fclose(newptr);
}
