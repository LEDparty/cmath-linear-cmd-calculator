#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"solve.h"

//global variables for easy error detection and type matching
char *options[] = {"-short", "-unsigned-short", "-int", "-unsigned-int", "-long", "-unsigned-long", "-long-long", 
				   "-unsigned-long-long","-float", "-double", "-long-double"};

int available_options = sizeof(options) / sizeof(options[0] );

int main(int argc, char *argv[] )
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
