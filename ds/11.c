#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MAX 30

struct cstack{
    char st[MAX];
    int top;
};

struct istack{
    int st[MAX];
    int top;
};

void initcstack(struct cstack* s){
    s->top = -1;
}

int isEmptyC(struct cstack* s){
    return s->top == -1;
}

void pushC(struct cstack* s, char val){
    s->st[++s->top] = val;
}

char popC(struct cstack* s){
    return s->st[s->top--];
}

char peekC(struct cstack* s){
    return s->st[s->top];
}

void initIstack(struct istack* s){
    s->top = -1;
}

void pushI(struct istack* s, int val){
    s->st[++s->top] = val;
}

int popI(struct istack* s){
    return s->st[s->top--];
}

int precedence(char op){
    switch(op){
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
    }
    return 0;
}

void reverse(char str[]){
    int i = 0, j = strlen(str) - 1;
    while(i < j){
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
}

void swapbrackets(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
}

void infixtoprefix(char infix[], char prefix[]){
    char temp[MAX], postfix[MAX];
    struct cstack s;
    initcstack(&s);

    strcpy(temp, infix);
    reverse(temp);
    swapbrackets(temp);

    int i = 0, k = 0;
    char ch;

    while((ch = temp[i++]) != '\0'){
        if(isalnum(ch)){
            postfix[k++] = ch;
        }
        else if(ch == '('){
            pushC(&s, ch);
        }
        else if(ch == ')'){
            while(peekC(&s) != '(')
                postfix[k++] = popC(&s);
            popC(&s);
        }
        else{
            while(!isEmptyC(&s) && precedence(peekC(&s)) > precedence(ch))
                postfix[k++] = popC(&s);
            pushC(&s, ch);
        }
    }

    while(!isEmptyC(&s))
        postfix[k++] = popC(&s);

    postfix[k] = '\0';
    reverse(postfix);
    strcpy(prefix, postfix);
}

int applyOperator(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

int evaluatePrefix(char prefix[]){
    struct istack s;
    initIstack(&s);

    for(int i = strlen(prefix) - 1; i >= 0; i--){
        char ch = prefix[i];

        if(isdigit(ch)){
            pushI(&s, ch - '0');
        }
        else{
            int a = popI(&s);
            int b = popI(&s);
            pushI(&s, applyOperator(a, b, ch));
        }
    }
    return popI(&s);
}

int main(){
    char infix[MAX], prefix[MAX];
    int choice;

    while(1){
        printf("\n1.Infix to Prefix");
        printf("\n2.Evaluate Prefix");
        printf("\n3.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", infix);
                infixtoprefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;

            case 2:
                printf("Evaluation Result: %d\n", evaluatePrefix(prefix));
                break;

            case 3:
                exit(0);
        }
    }
}
