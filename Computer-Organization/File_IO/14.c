#include<stdio.h>
#include<dir.h>
#include<sys/stat.h>
#include<sys/types.h>

void main()
{
    mkdir("C:/Users/admin/Documents/IIITDM KANCHEEPURAM/Studies/Computer Organization and Design Practice/Lab/File IO/14");
    FILE *ptr=fopen("C:/Users/admin/Documents/IIITDM KANCHEEPURAM/Studies/Computer Organization and Design Practice/Lab/File_IO/file.txt","w");
    fputs("Viknesh Rajaramon\n",ptr);
    fputs("COE18B060",ptr);
    fclose(ptr);
}
