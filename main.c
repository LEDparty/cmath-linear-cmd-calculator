#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"solve.h"

#define TYPE 1

//global variables for easy error detection and type matching
char *options[] = {"-short", "-unsigned-short", "-int", "-unsigned-int", "-long", "-unsigned-long", "-long-long", \
				   "-unsigned-long-long","-float", "-double", "-long-double"};

int available_options = sizeof(options) / sizeof(options[0] );

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

int main( int argc, char *argv[] )
{
    if(!argv[TYPE])
    {
        help_msg();

        return 1;
    }

    char *type = argv[TYPE];

    for(int type_code = 0; type_code < available_options; type_code++)
    {
        //type codes correspond with global array "options"
        if(strcmp(type, options[type_code] ) == 0) 
        {
            if(argc > 2)
            {
                solve_once(type_code, argc, argv);
            }
            else if(argc == 2)
            {
                REPL(type_code);
            }

            return 0;
        }
    }

	help_msg();

	return 1;
}
