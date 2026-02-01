#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAX 10

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
    return s->top == MAX -1;
}

int pop(struct stack *s){
    if(isEmpty(s)) return -1;
    
    return s->arr[s->top--];
}

void push(struct stack *s , int val){
    if(isFull(s)) return;
    s->arr[++s->top] = val;
}

int peek(struct stack *s){
     if(isEmpty(s)) return -1;
     
     return s->arr[s->top];
}

int prec(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '/':
        case '*':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int applyop(char ch , int a , int b){
    switch(ch){
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '*': return a * b;
        case '%': return a % b ;
        case '^': return pow(a,b);
        default: return 0;
    }
}

void infixtopostfix(char infix[MAX] , char postfix[MAX] ){
    
    struct stack s;
    init(&s);
    char ch;
    int i =0 , k =0;
    
    while((ch = infix[i++]) != '\0'){
        if(isalnum(ch)){
            postfix[k++] = ch;
        }else if(ch == '('){
            push(&s ,ch);
        }else if(ch == ')'){
            while(peek(&s) != '('){
                postfix[k++] = pop(&s);
            }
            pop(&s);
        }else{
            while(!isEmpty(&s) && (prec(peek(&s)) >= prec(ch))){
                postfix[k++] = pop(&s);
            }
            push(&s , ch);
        }
        
    }
    while(!isEmpty(&s)){
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int evaluate(char postfix[MAX]){
    struct stack s;
    init(&s);
    
    int i =0;
    char ch;
    
    while((ch = postfix[i++]) != '\0'){
        if(isdigit(ch)){
            push(&s, ch-'0');
        }else{
            int b = pop(&s);
            int a = pop(&s);
            push(&s ,applyop(ch , a , b));
        }        
    }
    return pop(&s);
}

int main(){
    char infix[MAX], postfix[MAX];
    int ch , result;
    
    while(1){
        printf("\n1.Infix to Postfix");
        printf("\n2.Evaluate Postfix");
        printf("\n3.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                    printf("\nEnter infix expression: ");
                    scanf("%s", infix);
                    infixtopostfix(infix , postfix);
                    printf("\nPostfix Expression is: %s ",postfix);
                    break;
            case 2:
                    result = evaluate(postfix);
                    printf("\n%d", result);
                    break;
            case 3: exit(0);
            default: return 0;
        }
    }
}


