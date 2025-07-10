#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#include"parse.h"

//loop to solve equation once
void solve_once( int type_code, int argc, char *argv[] )
{
    switch(type_code)
    {
        case 0:
            parse_int(argc, argv);
            break;
        case 1:
            parse_long(argc, argv);
            break;
        case 2:
            parse_float(argc, argv);
            break;
        case 3:
            parse_double(argc, argv);
            break;
        case 4:
            parse_long_double(argc, argv);
            break;
        default:
            printf("solve_once error\n");
            exit(EXIT_FAILURE);
    }
}
//continuous solve
void REPL(int type_code)
{
    if(type_code < 2)
    {
        printf("Example input: 2 - 3 + 7\n");
        printf("Accepted operators: +, -, *, /, %\n");
        printf("Enter any letter to stop.\n\n");
    }
    else
    {
        printf("Example input: 7.25 / .333 + 8\n");
        printf("Accepted operators: +, -, *, /\n");
        printf("Enter any letter to stop.\n\n");
    }
    
    for(;;)
    {
        char string_buffer[MAX];
        char *user_input[MAX];
        char c;
        int i = 0;

        //fill array to make indices align with
        //command line args
        user_input[0] = "useless";
        user_input[1] = "useless";
        
        int total = 2;

        //prompt string
        printf("> ");

        //make array of pointers
        while ((c = getchar()) != '\n')
        {
            if (c == ' ')
            {
                string_buffer[i] = '\0';

                user_input[total] = malloc(strlen(string_buffer) + 1);  

                strcpy(user_input[total++], string_buffer);

                i = 0;
            }
            else
            {
                //allow user exit
                if( isalpha(c) ) 
                {
                    exit(EXIT_SUCCESS);
                }

                string_buffer[i++] = c;
            }
        }
        
        //lat item on list 
        if (i > 0)
        {
            string_buffer[i] = '\0';
            user_input[total] = malloc(strlen(string_buffer) + 1);

            strcpy(user_input[total++], string_buffer);
        }

        switch(type_code)
        {
            case 0:
                parse_int(total, user_input);
                break;
            case 1:
                parse_long(total, user_input);
                break;
            case 2:
                parse_float(total, user_input);
                break;
            case 3:
                parse_double(total, user_input);
                break;
            case 4:
                parse_long_double(total, user_input);
                break;
            default:
                printf("REPL error\n");
                exit(EXIT_FAILURE);
        }
    }
}




int parse_int( int total, char *user_input[] )
{
    //integer mode
    int string_length = total - 1;

    int operands[MAX] = {0};
    char operators[MAX] = {0};

    //for creating the arrays operands and operators
    int conversion_index = 0;

    for (int i = 2; i <= string_length; i++)
    {
        if (i % 2 == 1)
        {
            sscanf( user_input[i], "%c", &operators[conversion_index] );
            operands[conversion_index] = 0; 
        }
        else
        {
            operands[conversion_index] = atoi( user_input[i] );
            operators[conversion_index] = '0'; 
        }

        conversion_index++;
    }

    int answer = operands[0];
    
    
    for(int i = 1; i < conversion_index; i += 2)
    {
        switch( operators[i] )
        {
            case '+':
                answer = answer + operands[i + 1];
                break;
            case '-':
                answer = answer - operands[i + 1];
                break;
            case '*':
                answer = answer * operands[i + 1];
                break;
            case '/':
                answer = answer / operands[i + 1];
                break;
            case '%':
                answer = answer % operands[i + 1];
                break;
            default:
                printf("parse_int error\n");
                exit(EXIT_FAILURE);
        }
    }

    puts("");
    printf("answer = %d\n", answer);
}

int parse_long( int total, char *user_input[] )
{
    int string_length = total - 1;

    long operands[MAX] = {0};
    char operators[MAX] = {0};

    int conversion_index = 0;

    for (int i = 2; i <= string_length; i++)
    {
        if (i % 2 == 1)
        {
            sscanf( user_input[i], "%c", &operators[conversion_index] );
            operands[conversion_index] = 0; 
        }
        else
        {
            operands[conversion_index] = atol( user_input[i] );
            operators[conversion_index] = '0'; 
        }

        conversion_index++;
    }

    long answer = operands[0];
    
    
    for(int i = 1; i < conversion_index; i += 2)
    {
        switch( operators[i] )
        {
            case '+':
                answer = answer + operands[i + 1];
                break;
            case '-':
                answer = answer - operands[i + 1];
                break;
            case '*':
                answer = answer * operands[i + 1];
                break;
            case '/':
                answer = answer / operands[i + 1];
                break;
            case '%':
                answer = answer % operands[i + 1];
                break;
            default:
                printf("parse_long error\n");
                exit(EXIT_FAILURE);
        }
    }

    puts("");
    printf("answer = %ld\n", answer);
}

int parse_float( int total, char *user_input[] )
{
    int string_length = total - 1;

    float operands[MAX] = {0};
    char operators[MAX] = {0};

    int conversion_index = 0;
    char *end;

    for (int i = 2; i <= string_length; i++)
    {
        if (i % 2 == 1)
        {
            sscanf( user_input[i], "%c", &operators[conversion_index] );
            operands[conversion_index] = 0; 
        }
        else
        {
            
            operands[conversion_index] = strtof( user_input[i], &end );
            operators[conversion_index] = '0'; 
        }

        conversion_index++;
    }

    float answer = operands[0];
    
    
    for(int i = 1; i < conversion_index; i += 2)
    {
        switch( operators[i] )
        {
            case '+':
                answer = answer + operands[i + 1];
                break;
            case '-':
                answer = answer - operands[i + 1];
                break;
            case '*':
                answer = answer * operands[i + 1];
                break;
            case '/':
                answer = answer / operands[i + 1];
                break;
            default:
                printf("parse_float error\n");
                exit(EXIT_FAILURE);
        }
    }

    puts("");
    printf("answer = %g\n", answer);
}

int parse_double( int total, char *user_input[] )
{
    int string_length = total - 1;

    double operands[MAX] = {0};
    char operators[MAX] = {0};

    
    int conversion_index = 0;

    for (int i = 2; i <= string_length; i++)
    {
        if (i % 2 == 1)
        {
            sscanf( user_input[i], "%c", &operators[conversion_index] );
            operands[conversion_index] = 0; 
        }
        else
        {
            
            operands[conversion_index] = atof( user_input[i] );
            operators[conversion_index] = '0'; 
        }

        conversion_index++;
    }

    double answer = operands[0];
    
    
    for(int i = 1; i < conversion_index; i += 2)
    {
        switch( operators[i] )
        {
            case '+':
                answer = answer + operands[i + 1];
                break;
            case '-':
                answer = answer - operands[i + 1];
                break;
            case '*':
                answer = answer * operands[i + 1];
                break;
            case '/':
                answer = answer / operands[i + 1];
                break;
            default:
                printf("parse double error\n");
                exit(EXIT_FAILURE);
        }
    }

    puts("");
    printf("answer = %g\n", answer);
}

int parse_long_double( int total, char *user_input[] )
{
    int string_length = total - 1;

    long double operands[MAX] = {0};
    char operators[MAX] = {0};
    
    int conversion_index = 0;
    char *end;

    for (int i = 2; i <= string_length; i++)
    {
        if (i % 2 == 1)
        {
            sscanf( user_input[i], "%c", &operators[conversion_index] );
            operands[conversion_index] = 0; 
            
        }
        else
        {
            operands[conversion_index] = strtold( user_input[i], &end );
            operators[conversion_index] = '0'; 
        }

        conversion_index++;
    }

    long double answer = operands[0];
    
    for(int i = 1; i < conversion_index; i += 2)
    {
        switch( operators[i] )
        {
            case '+':
                answer = answer + operands[i + 1];
                break;
            case '-':
                answer = answer - operands[i + 1];
                break;
            case '*':
                answer = answer * operands[i + 1];
                break;
            case '/':
                answer = answer / operands[i + 1];
                break;
            default:
                printf("parse_double error\n");
                exit(EXIT_FAILURE);
        }
    }

    puts("");
    printf("answer = %Lg\n", answer);
}

