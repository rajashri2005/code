#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 50

char stack[max];
int top=-1;

void push(char c)
{
if(top==max-1)
{
    printf("stack overflow\n");
} 
else{
    stack[++top]=c;
}
}

char pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return -1;
    }
    else{
       return stack[top--];
    }
}
char peek()
{
    return stack[top];
}

int precedence(char c)
{
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;        
    
}
  
  int isOperator(char c)
  {
    return(c== '+'|| c== '-'|| c== '*'|| c== '/'|| c== '^');
  }

 void infixTOPostfix(char *infix)
 {
    char postfix[max];
     int i=0,k=0;
     char c;

     while(infix[i] != '\0')// nullity
     {
        c= infix[i];
        if(isalnum(c)){
        postfix[k++]=c;
        }
        else if(c=='(')
        {
            push(c);
        }
        else if(c==')')
        {
           while(top !=-1 && peek() !='(')
           {
            postfix[k++] = pop();

           }  
           if(top !=-1 && peek()=='(')
           {
             pop();
           }
        }
        //if the character is operator
        else if(isOperator(c))
        {
            while(top!=-1 && precedence(peek())>= precedence(c))
            {
                postfix[k++]=pop();
            }
            push(c);

        }
        i++;
     }
     while(top !=-1)
     {
        postfix[k++]=pop();
        

     }
    postfix[k]= '\0'; //null -terminate the postfix expression

    printf("prefix expression : %s\n", postfix);
    

 } 

 int main()
 {
    char infix[max];
    printf("enter the expression");
    scanf("%s", infix);

    infixTOPostfix(infix); 

    return 0;
 }

 