#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int calcular(char* expr) {
    int resulto = 0;
    int num = 0;
    char op = '+';
    while (*expr) {
        if (isdigit(*expr)) {
            num = num * 10 + (*expr - '0');
        } else if (isOperator(*expr)) {
            switch (op) {
                case '+': resulto += num; break;
                case '-': resulto -= num; break;
                case '*': resulto *= num; break;
                case '/': resulto /= num; break;
            }
            num = 0;
            op = *expr;
        }
        expr++;
    }
    switch (op) {
        case '+': resulto += num; break;
        case '-': resulto -= num; break;
        case '*': resulto *= num; break;
        case '/': resulto /= num; break;
    }
    return resulto;
}

int main() {
    char* operacao;
    int op, resultado;
    while(1){
        printf("==================CALCULADORA==================\n");
        printf("1 - Calculadora\n");
        printf("0 - Sair\n");
        scanf("%i", &op);
        fflush(stdin);
        switch(op){
            case 1:
                printf("Digite uma operacao ex. 1+1: \n");
                scanf("%s", operacao);
                resultado = calcular(operacao);
                printf("Resultado: %d\n", resultado);
                break;
            case 0:
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}
