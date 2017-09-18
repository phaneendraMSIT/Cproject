#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct dictionary
{ char words[100];
    int values;
}dictionary1[100],dictionary2[100];

float BoW(char a[500][100],char b[500][100],int c,int d)
{
     //cuA=count of words in a
     //cuB=count of words in b
    int i,j,k,co,cuA=0,cuB=0;
    // dictionarytionary for a

    for (i=0;i<c;i++)
    {
        co =0;
        int flag=0;
        for(j = 0 ; j < c ; j++)
        {
            if(strcmp(a[i],a[j]) == 0)
            {
                co =co+1;
            }
        }
        for (k=0;k<i;k++) {
            if (strcmp(a[i],dictionary1[k].words) == 0)
            {
                flag=1;
                break;
            }}
        if(flag==0)
        {
            strcpy(dictionary1[cuA].words, a[i]);
            dictionary1[cuA].values = co;
            cuA++;}
    }
    for (i=0;i<cuA;i++)
    {
        printf("%s : %d\n",dictionary1[i].words,dictionary1[i].values);
    }
    //dictionarytionary for b
    for (i=0;i<d;i++)
    {
        co =0;
        int flag=0;
        for(j = 0 ; j < d ; j++)
        {
            if(strcmp(b[i],b[j]) == 0)
            {
                co =co+1;
            }
        }
        for (k=0;k<i;k++) {
            if (strcmp(b[i],dictionary2[k].words) == 0)
            {
                flag=1;
                break;
            }}
        if(flag==0)
        {
            strcpy(dictionary2[cuB].words, b[i]);
            dictionary2[cuB].values = co;
            cuB++;}
    }
    for (i=0;i<cuB;i++)
    {
        printf("%s : %d\n",dictionary2[i].words,dictionary2[i].values);
    }
    int dotsum=0,Norm=0,Norm1=0;
    float Result;
    // common words from a and b
    for(i=0;i<cuA;i++)
    {
        for(j=0;j<cuB;j++)
        {
            if(strcmp(dictionary1[i].words,dictionary2[j].words)==0)
            {
                printf("\n%d %d",dictionary1[i].values,dictionary2[i].values);
                dotsum += dictionary1[i].values*dictionary2[j].values;
            }
        }
    }
    printf("\n%d",dotsum);

    // sum of squres of a and b

    for(i=0;i<cuA;i++)
    {
        Norm += dictionary1[i].values*dictionary1[i].values;
    }
    float res1= sqrt(Norm);
    for(i=0;i<cuB;i++)
    {
        Norm1 += dictionary2[i].values*dictionary2[i].values;
    }
    float res2=sqrt(Norm1);
    Result = ((dotsum*100.0)/(res1*res2));
    printf("plag : %.2f",Result);
    return Result;

}

double bow(char text1[],char text2[])
{

    char ch;
    char ch1;
    int n,i,j;
    char s[50];
    char m[50];    
    i=0;
    while(text1[i] != EOF)
    {
        if((text1[i] >= 'a' && text1[i] <= 'z') || (text1[i]>= 'A' && text1[i] <= 'Z') || (text1[i]>= '0' && text1[i] <= '9') || text1[i] == '_')
        {
            if(text1[i] >= 'A' && text1[i] <= 'Z')
                text1[i] = text1[i] + 32;
            s[i]=text1[i];
        }
        else
        {
            s[i] = ' ';
        }
        i=i+1;
    }
    s[i]= '\0';
     printf("%s", s);
    i=0;
    while(text2[i] != EOF)
    {
        if((text2[i] >= 'a' && text2[i] <= 'z') || (text2[i]>= 'A' && text2[i] <= 'Z') || (text2[i]>= '0' && text2[i] <= '9') || text2[i] == '_')
        {
            if(text2[i] >= 'A' && text2[i] <= 'Z')
                text2[i] = text2[i] + 32;
            m[i]=text2[i];
        }
        else
        {
            m[i] = ' ';
        }
        i=i+1;
    }
    m[i]= '\0';
    char str[100], *z = str, *t = NULL;
    char c[500][100];
     n=0;
    int count=0;
    strcpy(str,s);
    while ((t = strtok(z, " ")) != NULL) {
        z = NULL;
    //  printf("%s \n", t);
        strcpy(c[n++],t);
        count += 1;
    }
//   for (i=0;i<count;i++) {
//       printf("%d : %s \n ", i, c[i]);
//   }
    char d[500][100];
    n=0;
     char *t1 = NULL,str1[100],*z1=str1;
    int count1=0;
    strcpy(str1,m);
    while ((t1 = strtok(z1, " ")) != NULL) {
        z1 = NULL;
     //  printf("%s \n", t1);
        strcpy(d[n++],t1);
        count1 += 1;
    }
    /*for (i=0;i<count1;i++) {
        printf("%d : %s \n ", i, d[i]);
    }*/
 float p;
    p = BoW(c,d,count,count1);
    printf("\n BOW percent : %.2f",p);
}