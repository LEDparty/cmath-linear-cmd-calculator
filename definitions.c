#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"solve.h"

void help_msg()
{
    printf("Usage: cmath [-short|-ushort|-int|etc.] <operands/operators>\n");
    printf("--or--\n\n");
    printf("Usage: cmath [-short|-ushort|-int|etc.]\n");
    puts("");
    printf("Accepted operators for integers: +, -, *, /, %\n");
    printf("Accepted operators for float types: +, -, *, /\n");
    printf("If running running once, use quotes for multiplication\n");
    printf("operator ('*') to keep shell expansion from occurring.\n");
    puts("");
    printf("Examples: cmath -int 4 / 2 '*' 5, cmath -long-double");
    puts("");
    puts("");
    printf("Types allowed: ");
    puts("");
    puts("");

    for(int i = 0; i < available_options; i++)
    {
		printf("%s\n", options[i]);
    }
}

//functions with different type requirements
SOLVE_INT(short, solve_short, atoi, "%hd");
SOLVE_INT(unsigned short, solve_ushort, atoi, "%hu");
SOLVE_INT(int, solve_int, atoi, "%d");
SOLVE_INT(unsigned int, solve_uint, atol, "%u");
SOLVE_INT(long, solve_long, atol, "%ld");
SOLVE_INT(unsigned long, solve_ulong, atol, "%lu");
SOLVE_INT(long long, solve_llong, atol, "%lld");
SOLVE_INT(unsigned long long, solve_ullong, atol, "%ld");
SOLVE_FLOAT(float, solve_float, strtof, "%f");
SOLVE_FLOAT(double, solve_double, strtod, "%lf");
SOLVE_FLOAT(long double, solve_long_double, strtold, "%Lf");

//used for direct solving from the command line
void solve_once(int type_code, int argc, char *argv[] )
{
    switch(type_code)
    {
        case 0:
            solve_short(argc, argv);
            break;
        case 1:
            solve_ushort(argc, argv);
            break;
        case 2:
            solve_int(argc, argv);
            break;
        case 3:
            solve_uint(argc, argv);
            break;
        case 4:
            solve_long(argc, argv);
            break;
        case 5:
            solve_ulong(argc, argv);
            break;
        case 6:
            solve_llong(argc, argv);
            break;
        case 7:
            solve_ullong(argc, argv);
            break;
        case 8:
            solve_float(argc, argv);
            break;
        case 9:
            solve_double(argc, argv);
            break;
        case 10:
            solve_long_double(argc, argv);
            break;
        default:
            printf("Something went wrong here: solve_once error\n");
            exit(EXIT_FAILURE);
    }
}

//indefinite execution of program
void REPL(int type_code)
{
    if(type_code < 7)
    {
        printf("Example input: 2 - 3 + 7\n");
        printf("Accepted operators: +, -, *, /, %\n");
        printf("Always put spaces between numbers and math operators.\n");
        printf("Enter any letter to stop.\n\n");
    }
    else
    {
        printf("Example input: 7.25 / .333 + 8\n");
        printf("Accepted operators: +, -, *, /\n");
        printf("Always put spaces between numbers and math operators.\n");
        printf("Enter any letter to stop.\n\n");
    }
    
    for(;;)
    {
        char string_buffer[MAX];
        char *user_input[MAX];
        char c;
        int i = 0;

        //dummy input marking where to start calculating,
		//two values needed to start equation on an even number
        user_input[0] = "useless";
        user_input[1] = "useless";

        //start at 2 for math input, the real string total
		//is essentially the string length minus 2
        int total = 2;

        printf("> ");
		
        while ( (c = getchar() ) != '\n')
        {
			//prevents spaces from being written to the buffer
            if (c == ' ')
            {
                string_buffer[i] = '\0';
				//increase size of user_input dynamically using malloc
				//since user_input is an array of pointers
                user_input[total] = malloc(strlen(string_buffer) + 1);
				//string_buffer is just the holding area, it writes to user_input
				//after a space is entered
                strcpy(user_input[total++], string_buffer);
				//reset i for string_buffer to keep re-writing
                i = 0;
            }
            else
            {
				//allow user to enter letters to exit
                if(isalpha(c) ) 
                {
                    exit(EXIT_SUCCESS);
                }

                string_buffer[i++] = c;
            }
        }

        //records string after pressing enter, needed 
		//to complete above while-loop operation successfully if
		//user doesn't exit since pressing enter above abruptley enters
		//the loop. " > 0" Is the flow control condition so that the REPL 
		//starts over when user presses enter with nothing.
        if (i > 0)
        {
			//complete string buffer
            string_buffer[i] = '\0';
			//final dynamic increase
            user_input[total] = malloc(strlen(string_buffer) + 1);
			//final write
            strcpy(user_input[total++], string_buffer);
        }
       
        switch(type_code)
        {
			case 0:
				solve_short(total, user_input);
				break;
			case 1:
				solve_ushort(total, user_input);
				break;
			case 2:
				solve_int(total, user_input);
				break;
			case 3:
				solve_uint(total, user_input);
				break;
			case 4:
				solve_long(total, user_input);
				break;
			case 5:
				solve_ulong(total, user_input);
				break;
			case 6:
				solve_llong(total, user_input);
				break;
			case 7:
				solve_ullong(total, user_input);
				break;
			case 8:
				solve_float(total, user_input);
				break;
			case 9:
				solve_double(total, user_input);
				break;
			case 10:
				solve_long_double(total, user_input);
				break;
            default:
                printf("Something went wrong here: REPL error\n");
                exit(EXIT_FAILURE);
        }

		for(int j = 2; j < total; j++)
		{
			//free only the dynamically allocated space,
			//you can't free the whole array because there's
			//a lot of static space including the strings containing 
			//"useless" values
			free(user_input[j]);
		}
    }
}

