#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define MAX 50

struct cstack{
    char st[MAX];
    int top;
};

struct istack{
    int st[MAX];
    int top;
};

void initcstack(struct cstack* S){
    S->top = -1;
}

void pushc(struct cstack* S ,char val){
    if(S->top < MAX-1)
        S->st[++S->top] = val;
}

char popc(struct cstack* S){
    if(S->top == -1)
        return '\0';
    return S->st[S->top--];
}

char peekc(struct cstack* S){
    if(S->top == -1)
        return '\0';
    return S->st[S->top];
}

void initistack(struct istack* S){
    S->top = -1;
}

void pushi(struct istack* S ,int val){
    if(S->top < MAX-1)
        S->st[++S->top] = val;
}

int popi(struct istack* S){
    if(S->top == -1)
        return 0;
    return S->st[S->top--];
}

void reverse(char str[]){
    int i, j;
    char temp;
    for(i = 0, j = strlen(str)-1; i < j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void swapBrackets(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
}

int precedence(char op){
    switch(op){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

void infixtoprefix(char infix[], char prefix[]){
    char temp[MAX], postfix[MAX];
    struct cstack s;
    initcstack(&s);

    strcpy(temp, infix);
    reverse(temp);
    swapBrackets(temp);

    int i = 0, k = 0;
    char ch;

    while((ch = temp[i++]) != '\0'){
        if(isalnum(ch)){
            postfix[k++] = ch;
        }
        else if(ch == '('){
            pushc(&s, ch);
        }
        else if(ch == ')'){
            while(peekc(&s) != '(')
                postfix[k++] = popc(&s);
            popc(&s);
        }
        else{
            while(precedence(peekc(&s)) > precedence(ch))
                postfix[k++] = popc(&s);
            pushc(&s, ch);
        }
    }

    while(s.top != -1)
        postfix[k++] = popc(&s);

    postfix[k] = '\0';
    reverse(postfix);
    strcpy(prefix, postfix);
}

int applyoperator(int a, int b, char op){
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
    initistack(&s);

    for(int i = strlen(prefix)-1; i >= 0; i--){
        char ch = prefix[i];

        if(isdigit(ch)){
            pushi(&s, ch - '0');
        }
        else{
            int a = popi(&s);
            int b = popi(&s);
            int result = applyoperator(a, b, ch);
            pushi(&s, result);
        }
    }
    return popi(&s);
}

int main(){
    char infix[MAX], prefix[MAX];
    int choice, result;

    while(1){
        printf("\n1.Infix to Prefix");
        printf("\n2.Evaluate Prefix");
        printf("\n3.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", infix);
                infixtoprefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;

            case 2:
                result = evaluatePrefix(prefix);
                printf("Evaluation Result: %d\n", result);
                break;

            case 3:
                exit(0);
        }
    }
}
