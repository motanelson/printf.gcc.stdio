#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdarg.h>
void cputc(char c){
    putc(c,stdout);


}
void cputs(char* s){
    int counter=0;
    while(1){
        if(s[counter]==0)break;
        cputc(s[counter]);
        counter++;
    }

}
void cputinteger(int i){
     char ccc[4096]="";
     sprintf(ccc,"%d",i);
     cputs(ccc);
     
}
void cputlong(long i){
     char ccc[4096]="";
     sprintf(ccc,"%ld",i);
     cputs(ccc);
     
}
void cputfloat(float i){
     char ccc[4096]="";
     sprintf(ccc,"%f",i);
     cputs(ccc);
     
}
void cputdouble(double i){
     char ccc[4096]="";
     sprintf(ccc,"%lf",i);
     cputs(ccc);
     
}
void cputhex(int i){
     char ccc[4096]="";
     sprintf(ccc,"%X",i);
     cputs(ccc);
     
}
void cputprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;  // avança para o especificador
            switch (*fmt) {
                case 'd': // inteiro
                    cputinteger(va_arg(args, int));
                    break;
                case 'l': // long
                    cputlong(va_arg(args, long));
                    break;
                case 'f': // double (float é promovido)
                    cputdouble(va_arg(args, double));
                    break;
                case 'x': // hexadecimal
                case 'X':
                    cputhex(va_arg(args, int));
                    break;
                case 's': // string
                    cputs(va_arg(args, char *));
                    break;
                case '%': // imprime o próprio %
                    cputc('%');
                    break;
                default:
                    cputc('%'); // se não reconhece, imprime bruto
                    cputc(*fmt);
                    break;
            }
        } else {
            cputc(*fmt);  // imprime caracteres normais
        }
        fmt++;
    }

    va_end(args);
}
int main(){
    char *ccc="hello world.....\n";
    printf("\033c\033[43;30m\nprintf exemple;\n");
    cputprintf("String: %s\n", "#####");
    cputprintf("Int: %d, Hex: %X, Float: %f\n", 42, 42, 3.14);
    cputprintf("Long: %ld, Percent: %%\n", 123456789L);

    return 0;
}