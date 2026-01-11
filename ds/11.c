#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX 30

struct stack{
    char st[MAX];
    int top;
};

void initstack(struct stack* s){
    s->top = -1;
}

int isEmpty(struct stack* s){
    return (s->top == -1);
}

int isFull(struct stack* s){
    return (s->top == MAX-1);
}

void push(struct stack* s, char val){
    if(isFull(s)) return;
    else{
        s->st[++s->top] = val;
    }
}

char pop(struct stack* s){
    if(isEmpty(s)) return;
    char top = s->st[s->top];
    s->top--;
    return top;
}

char peek(struct stack* s){
    if(isEmpty(s)) return;
    char top = s->st[s->top];
    return top;
}

int precedence(char op){
    switch(op){
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;      
        case '^': return 3;
        default: return 0;        
    }
}

void reverse(char infix[]){
    for(int i = 0; i < strlen(infix) -1 ;i++){
        char temp = infix[i];
        infix[i] =  infix[strlen(infix) - i];
        infix[strlen(infix) - i] = temp;
    }
}

void swapbrackets(char infix[]){
    for(int i = 0; i < strlen(infix) -1 ;i++){
        if(infix[i] == '(') infix[i] = ')';
        if(infix[i] == ')') infix[i] = '(';
    }
}
void infixtoprefix(char infix[] , char prefix[]){
    char temp[MAX] , postfix[MAX];
    struct stack s;
    initstack(&s);

    strcpy(temp, infix);
    reverse(temp);
    swapbrackets(temp);

    int i =0, k=0;
    char ch;
    while((ch = temp[i++])!='\0' ){
        if(isalnum(ch)){
            postfix[k++] = ch;
        }else if(ch =='('){
           push(&s,ch);
        }else if(ch== ')'){
            pop(&s);
            while(peek(&s) != '( ' && !isEmpty(&s)){
                postfix[k++] = pop(&s);
            }
            pop(&s);
        }else{
            while(!isEmpty(&s) && precedence(peek(&s) > precedence(ch)) ){
                postfix[k++] = pop(&s);
            }
            push(&s , ch);
        }
    }

    while(!isEmpty(&s)){
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';

    reverse(postfix);
    strcpy(prefix ,postfix);
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

int evaluate(int prefix[]){
    struct stack s;
    initstack(&s);

    int i = strlen(prefix) -1;
    char ch;

    while(i >=0){
        ch = prefix[i--];

        if(isdigit(ch)){
            push(&s ,ch-'0');
        }
        else{
            int a = pop(&s);
            int b = pop(&s);
            int res = applyOperator(a,b,ch);

            push(&s, res);
        }
    }
    return pop(&s);
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
                infixToPrefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;

            case 2:
                result = evaluatePrefix(prefix);
                printf("Evaluation Result: %d\n", result);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
