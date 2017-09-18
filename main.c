
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "lcs.h"
#include "BagOfWords.h"
#include <stdlib.h>
#include <ctype.h>
/***
 *
 * @param file text file of type char*
 * @param rtext resultant text of type char*
 *
 */
void filereader(char file[], char rtext[]){

    long lSize;
    char *text;

    strcpy(rtext,"");
    strcpy(text,"");
    FILE *fp = fopen(file,"rb");
    int i,j;
    char buff[255];
    int len1 = 0;

    while((fscanf(fp,"%s",buff))!=EOF)
    {
        i=0,j=0;
        while(buff[i]!='\0')
        {
            j = buff[i];
            if(isalnum(j) || j == 95)
            {
                rtext[len1] = tolower(buff[i]);
                len1++;
            }
            i++;
        }
        rtext[len1]=' ';
        len1++;
    }
    rtext[len1-1]='\0';
    fclose(fp);

}

int main(int argc, char *argv[] )
{
    char files[100][100],tfiles[100][100],f[100];
    char text1[100],text2[100];
    char fname[100] ;
    strcpy(fname,argv[1]);
    int c = 0;
    float per=0.0;
    DIR *d;
    struct dirent *dir;
    d = opendir(fname);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {

            if(subcheck(dir->d_name,".txt")){
                printf("asd");
                if (subcheck(dir->d_name,"outputlog"));
                else{
                    strcat(tfiles[c],dir->d_name);
                    strcat(fname,dir->d_name);
                    strcpy(files[c],fname);
                    strcpy(fname,argv[1]);
                    c++;
                    printf("%s\n",tfiles[c] );
                }
            }
           
        }
        closedir(d);
    }


    FILE *fp = fopen("outputlog.txt","w");
    fprintf(fp,"\t\t");
    for(int i=0;i<c;i++)
        fprintf(fp,"%s\t",tfiles[i]);
    fprintf(fp,"\n");
//Bag of words for given files.
    for(int i=0;i<c;i++){
        fprintf(fp,"%s\t",tfiles[i]);
        filereader(files[i],text1);
        strcpy(text2,"");
        for(int j=0;j<c;j++){

            filereader(files[j],text2);
            if(strlen(text1)&&strlen(text2)){
                per = bow(text1,text2);//calling BagOfWords.h
                fprintf(fp,"%.2f\t\t",per);
            }
            else{
                per = 0.00;
                fprintf(fp, "%.2f\t\t", per);
            }
        }
        fprintf(fp,"\n");
    }

    fprintf(fp,"\n");
//String matching for given files .
    fprintf(fp,"\t\t");
    for(int i=0;i<c;i++)
        fprintf(fp,"%s\t",tfiles[i]);
    fprintf(fp,"\n");
    for(int i=0;i<c;i++){
        fprintf(fp,"%s\t",tfiles[i]);
        filereader(files[i],text1);
        strcpy(text2,"");
        for(int j=0;j<c;j++){
            filereader(files[j],text2);

            if (strlen(text2)&&strlen(text2)){
                per = stringmatch(text1,text2);//Calling StringMatch
                fprintf(fp,"%.2f\t\t",per);
            }
            else
                fprintf(fp,"0.00");
        }
        fprintf(fp,"\n");
    }
/*
   fprintf(fp,"\n");
    fprintf(fp,"\t\t");
    for(int i=0;i<c;i++)
        fprintf(fp,"%s\t",tfiles[i]);
    fprintf(fp,"\n");
    for(int i=0;i<c;i++){
        fprintf(fp,"%s\t",tfiles[i]);
        filereader(files[i],text1);
        strcpy(text2,"");
        for(int j=0;j<c;j++){
            filereader(files[j],text2);
            if(strlen(text1)&&strlen(text2)){
                per = finger(text1,text2);
                fprintf(fp,"%.2f\t\t",per);
            }
            else {
                per = 0.00;
                fprintf(fp, "%.2f\t\t", per);
            }
        }
        fprintf(fp,"\n");
    }*/
    fclose(fp);

    printf("\n");
    return(0);
}
