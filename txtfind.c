#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
int getlines(char s[]){
    int i=0;
    while(s[i]!='\n'){
        i++;
    }
    return i;
}
int getword(char w[]){
    int i=0;
    while((w[i]>='a'&&w[i]<='z')||((w[i]>='A'&&w[i]<='Z'))){
       i++; 
    }
    return i;
}
int substring( char * str1, char * str2){
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1<len2) return 0;
    for (size_t i = 0; i < len1-len2+1; i++)
    {
        int j=0;
        while(j<len2){
            if(str1[i+j]!=str2[j]) break;
            j++;
        }
        if(j==len2) return 1;
    }
    return 0;
}
int similar (char *s, char *t, int n){
    int len_s=strlen(s);
    int len_t=strlen(t);
    int i=0;
    int j=0;
    int diff=0;
    while(i<len_s&&j<len_t&&diff<=n){
        if(s[i]!=t[j]){
            diff++;
            i++;
        }else{
            i++;
            j++;
        }
    }
    int delta=n-diff;
    if(diff>n) return 0;
    if(j!=len_t) return 0;
    if(len_s-i>delta) return 0;
    return 1;
}
void print_lines(char * str){
    int b=0;
    char c='\0';
    while(c!=EOF){
        char w[WORD]={0};
        char line[LINE]={0};
        int i=0;
        c='\0';
        while(c!='\n'){
            int n=scanf("%c",&c);
            if(n==EOF){
                b=1;
                line[i++]='\n';
                break;
            }else{ 
            line[i++]=c;
            }
        }
        int j=0;
        while(j<i&&((!(line[j]>='a'&&line[j]<='z'))&&(!(line[j]>='A'&&line[j]<='Z')))){
            j++;
        }
        while(j<i){
            int w_size=getword(line+j);
            size_t k;
            for ( k = 0; k < w_size; k++)
            {
                w[k]=line[k+j];
            }
            w[k]='\0';
            j+=k;
            while(j<i&&((!(line[j]>='a'&&line[j]<='z'))&&(!(line[j]>='A'&&line[j]<='Z'))))
            {
            j++;
            }
            if(substring(w,str)){
                printf("%s",line);
                break;
            }
        }
            if(b==1){
                return;
            } 
    }
}

void print_similar_words(char * str){
    char c='\0';
    int b=0;
    while(c!=EOF){
        char w[WORD]={0};
        char line[LINE]={0};
        int i=0;
        c='\0';
        while(c!='\n'){
            int n=scanf("%c",&c);
            if(n==EOF){
                b=1;
                line[i++]='\n';
                break;
            }else{
            line[i++]=c;
            }
        }
        int j=0;
        while(j<i&&((!(line[j]>='a'&&line[j]<='z'))&&(!(line[j]>='A'&&line[j]<='Z')))){
            j++;
        }
        while(j<i){
            int w_size=getword(line+j);
            size_t k;
            for ( k = 0; k < w_size; k++)
            {
                w[k]=line[k+j];
            }
            j+=k;
            w[w_size]='\0';
            while(j<i&&((!(line[j]>='a'&&line[j]<='z'))&&(!(line[j]>='A'&&line[j]<='Z'))))
            {
            j++;
            }
            if(similar(w,str,1)){
                printf("%s\n",w);
            }
        }
        if(b==1){
            return;
        }
    }
}


int main(){
    char c='\0';
    char line[LINE]={0};
    int i=0;
    while(c!='\n'){
        scanf("%c",&c);
        line[i++]=c;
    }
    int j=0;
        while(j<i&&(line[j]=='\t'||line[j]==' '||line[j]=='\n')){
        j++;
    }
    char w[WORD]={0};
    int w_size=getword((line+j));
    size_t k;
    for(k = 0;  k< w_size; k++)
    {
        w[k]=line[j+k];
    }
    j+=k;
        while(j<i&&(line[j]=='\t'||line[j]==' '||line[j]=='\n')){
        j++;
    }
    c=line[j];
    if(c=='a'){
    print_lines(w);
    }
    else if(c=='b'){
    print_similar_words(w);
    }else
    {
        printf("Error in option, only a or b are possible!\n");
    }
    return 0;
}

