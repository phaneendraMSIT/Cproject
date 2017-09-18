#include<string.h>
#define MAX 100000
void append(char* a, char c)
{
    int len = strlen(a);
    a[len] = c;
    a[len+1] = '\0';
}

void linewc(char text[]){
    char word[MAX][100];
    int k,p;

    int len = 0;
    int i = 0,j = 0,c = 0,flag;

    p = strlen(text);

    for(k=0;k<p;k++){
        if(text[k]!=' '){

            if(text[k]>=65 && text[k]<=90){
                text[k] = text[k]+32;
            }

            word[i][j]=text[k];
            j++;

        }
        else{
            word[i][j]='\0';
            i++;
            j=0;

            c += 1;
        }
    }
    word[i][j]='\0';
    c+=1;
    strcpy(text,"");
    for(k=0;k<c;k++){
        flag = 1;
        for (i = 0; i<strlen(word[k]);i++){

            if(word[k][i]>122 || word[k][i]<97){

                flag = 0;
                break;
            }
        }
        if(flag){
            strcat(text,word[k]);
            strcat(text," ");
        }
    }
}

int subcheck(char str[MAX],char substr[MAX]){
    int len1 = 0, len2 = 0, i, j, flag;


    len1 = strlen(str);
    len2 = strlen(substr);
    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = i; j < i + len2; j++)
        {
            flag = 1;
            if (str[j] != substr[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        return 1;
    return 0;
}

float stringmatch(char tex[],char tex1 []){

    char maxss[100]="";
    int i=0,j=0;
    char substr[100];
    int len = strlen(tex);
    int len1 = strlen(tex1);
    strcpy(substr,"");
    append(substr,tex[0]);
    while(i<len && j<len1){
        if (subcheck(tex1,substr)){
            j++;
            if(strlen(maxss)<strlen(substr))
                strcpy(maxss,substr);
            append(substr,tex[i+j]);
        }
        else{
            i += 1;
            j = 0;
            strcpy(substr,"");
            append(substr,tex[i]);
        }
    }
    float per;
    per = strlen(maxss)*200/(len+len1);
    return per;
}

