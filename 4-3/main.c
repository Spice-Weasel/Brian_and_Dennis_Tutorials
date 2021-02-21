// Reverse Polish Notation Calculator

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

#define MAXOP 20
#define NUMBER '0'
#define TOOBIG '9'

int main(void)
{
  // Variable declaration
  int type;
  char s[MAXOP];
  double op2;

  //Function declaration
  //double atof();
  //double pop();
  //double push();
  //void clear();

  int getop(char* s, int lim);

  while((type = getop(s, MAXOP)) != EOF)
  {
    switch(type)
    {
      case NUMBER:
        puts("NUMBER");
        push(atof(s));
        break;
      case '+':
        puts("PLUS");
        push(pop() + pop());
        break;
      case '*':
        puts("TIMES");
        push(pop() * pop());
        break;
      case '-':
        puts("SUBTRACT");
        op2 = pop();
        push(pop() - op2);
        break;
      case '~':
        push(-1*pop());
        break;
      case '/':
        puts("DIVIDE");
        op2 = pop();
        if(op2 != 0.0)
        {
          push(pop() / op2);
        } else {
          printf("zero divisor popped\n");
        }
        break;
      case '%':
        puts("MODULO");
        op2 = pop();
        if(op2 != 0.0)
        {
          double result;
          result = (double)((int)pop() % (int)op2);
          push(result);
        } else {
          printf("zero divisor popped\n");
        }
        break;
      case '&':
        puts("ERASE TOP STACK ENTRY");
        pop();
        break;
      case '=':
        puts("EQUALS");
        printf("\t%f\n", push(pop()));
        break;
      case 'c':
        puts("CLEAR");
        clear();
        break;
      case TOOBIG:
        puts("TOO BIG");
        printf("%.20s ... is too long\n", s);
        break;
      default:
        printf("unknown command %c\n", type);
        break;
    }
  }

  puts("SUCCESSFUL!");

  return EXIT_SUCCESS;
}



int getop(char* s, int lim)
{
  int i, c;

  while((c = getchar())==' ' || c == '\t' || c == '\n')
  {
    ;
  }
  if(c != '.' && (c < '0' || c > '9'))
  {
    return c;
  }
  s[0] = c;
  for(i = 1; (c = getchar()) >= '0' && c <= '9'; i++)
  {
    if(i < lim)
    {
      s[i] = c;
    }
  }
  if(c == '.')
  {
    if(i < lim)
    {
      s[i] = c;
    }
    for(i++; (c=getchar()) >= '0' && c <= '9'; i++)
    {
      if(i < lim)
      {
        s[i] = c;
      }
    }
  }
  if(i < lim)
  {
    ungetc(c, stdin);
    s[i] = '\0';

    return(NUMBER);
  } else {
    while(c != '\n' && c != EOF)
    {
      c = getchar();
    }
    s[lim - 1] = '\0';

    return TOOBIG;
  }
}
