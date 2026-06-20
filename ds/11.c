#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MAX 50

struct stack{
    int top;
    int arr[MAX];
};

void init(struct stack *s){
    s->top = -1;
}

int isEmpty(struct stack *s){
    return s->top == -1;
}

int isFull(struct stack *s){
    return s->top == MAX - 1;
}

void push(struct stack *s , int val){
    if(isFull(s)) return;
    s->arr[++s->top] = val;
}

int pop(struct stack *s){
    if(isEmpty(s)) return -1;
    return s->arr[s->top--];
}

int peek(struct stack *s){
    if(isEmpty(s)) return -1;
    return s->arr[s->top];
}

int prec(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int applyop(char ch , int a , int b){
    switch(ch){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return pow(a,b);
    }
    return 0;
}

void reverse(char str[]){
    int n = strlen(str);
    for(int i = 0; i < n/2; i++){
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

void swapbrackets(char str[]){
    for(int i = 0; str[i]; i++){
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
}

void infixtoprefix(char infix[], char prefix[]){
    struct stack s;
    init(&s);

    char temp[MAX];
    strcpy(temp, infix);

    reverse(temp);
    swapbrackets(temp);

    int i = 0, k = 0;
    char ch;

    while((ch = temp[i++]) != '\0'){
        if(isalnum(ch)){
            prefix[k++] = ch;
        }
        else if(ch == '('){
            push(&s, ch);
        }
        else if(ch == ')'){
            while(peek(&s) != '(')
                prefix[k++] = pop(&s);
            pop(&s);
        }
        else{
            while(!isEmpty(&s) && prec(peek(&s)) > prec(ch))
                prefix[k++] = pop(&s);
            push(&s, ch);
        }
    }

    while(!isEmpty(&s))
        prefix[k++] = pop(&s);

    prefix[k] = '\0';
    reverse(prefix);
}

int evaluate(char prefix[]){
    struct stack s;
    init(&s);

    for(int i = strlen(prefix) - 1; i >= 0; i--){
        char ch = prefix[i];

        if(isdigit(ch)){
            push(&s, ch - '0');
        }else{
            int a = pop(&s);
            int b = pop(&s);
            push(&s, applyop(ch, a, b));
        }
    }
    return pop(&s);
}

int main(){
    char infix[MAX], prefix[MAX];
    int ch;

    while(1){
        printf("\n1.Infix to Prefix\n2.Evaluate Prefix\n3.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%s", infix);
                infixtoprefix(infix, prefix);
                printf("Prefix: %s\n", prefix);
                break;
            case 2:
                printf("Result = %d\n", evaluate(prefix));
                break;
            case 3:
                exit(0);
        }
    }
}
