#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"parse.h"

//global variables for easy error and type matching
char *options[] = {"-int", "-long", "-float", "-double", "-ld"};
int available_options = sizeof(options) / sizeof( options[0] );

void help_msg()
{
    printf("Usage: cmath <type> <operands/operators>\n");
    printf("Or, run with type alone to keep solving indefinetly.\n");
    puts("");
    printf("Accepted operators for integers: +, -, *, /, %\n");
    printf("Accepted operators for float types: +, -, *, /\n");
    printf("If running running once, use quotes for multiplication\n");
    printf("operator ('*') to keep shell expansion from occurring.\n");
    puts("");
    printf("Example: cmath -int 4 / 2 '*' 5");
    puts("");
    printf("Types allowed: ");

    int last_item = available_options - 1;

    for(int i = 0; i < available_options; i++)
    {
        //print last item on list differently
        if(i != last_item)
        {
            printf("%s, ", options[i]);
        }
        else
        {
            printf("%s.\n", options[i]);
        }
    }
}

int main( int argc, char *argv[] )
{
    if(!argv[1])
    {
        help_msg();

        return 1;
    }

    char *type = argv[1];

    for(int type_code = 0; type_code < available_options; type_code++)
    {
        //type codes correspond with global array "options":
        //0 for short, 1 for integer, 2 for long, 3 for float,
        //4 for double, 5 for long double
        if( strcmp( type, options[type_code] ) == 0 ) 
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
}
