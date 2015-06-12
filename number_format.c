#include<stdio.h>
#include<math.h> 

double str_to_double(char*);
int valid(char*);
double integer(char*);
double floating(char*);

int main(){
    char ch[100];
    while (scanf("%s",ch)!=EOF) { 
        double d = str_to_double(ch);
        if (d==d) { 
            printf("%f\n",d);
        } else { 
            printf("Invalid Number\n");
        }
    }
    return 0;
}

int valid(char* ch) {
    int count=0;
    if((ch[0]<'0' || ch[0]>'9') && ch[0]!='+'  && ch[0]!='-' && ch[0]!='.')  {
        return 0;
    }
    if(ch[0]=='.'){
        count++;
    }

    for(int i=1;ch[i]!='\0';i++) {
        if((ch[i]<'0' || ch[i]>'9') && ch[i]!='.' )  {
            return 0;
        } 
        if(ch[i]=='.'){
            count++;
        }
    }
    if(count>1) {
    return 0;
    }
    return 1;
}

double str_to_double(char* ch) {
    double d;
    if(valid(ch)) {
        d=integer(ch);
        return ch[0]=='-'?-d:d;
    } else {
        return NAN;
    }
}

double integer(char* ch) {
    char c;
    double d;
    double fd;
    for(int i=0;ch[i]!='\0';i++) {
        if(ch[i]>='0'&&ch[i]<='9') {
            c=ch[i];
            d=(d*10)+(c-'0');
        }
        else if(ch[i]=='.') {
            fd=floating(ch+(i+1));
            break;
        }
    }
    return d+fd ;
}

double floating(char* ch) {
    char c;
    double fd=0;
    double div=1.0;
    for(int i=0;ch[i]!='\0';i++) {
        if(ch[i]>='0'&&ch[i]<='9') {
            c=ch[i];
            div=div*10;
            fd=fd+ ((c-'0')/div);
        }
    }
    return fd; 
}
