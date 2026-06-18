#define MAX 1000
#define TYPE 1

/*The functions for solving the equations are copied multiple times
 *as macros so that we don't have to have a separate function for each type.
 *Each time, the arrays are set up with separate ones for operators and operands,
 *converted to the corrected numeric type from strings, represented as "std_function",
 *before solving. 
 *
 *The first of these macros solves equations with integer types, the second one does 
 *floating point since the standard library functions have slightly different 
 *argument requirements. Putting line comments inside the function will break it.
 *
 *The basic logic is:
 *-the even slots in the arrays represent operands (the numbers)
 *-odd numbers the operators, the plus signs etc.
 *
 * The two arrays are kept in sync with a filler character, so we get this after the 
 * first loop:
 *Operands: 5 0 1 0 3
 *Operators: 0 + 0 * 0
 *
 * "type answer = operands[0];" just shifts the array back to the first 
 * digit to prepare for finding the answer. The second for loop increments by 2 in order
 * to find the next operator.
 * */
#define SOLVE_INT(type, function_name, std_function, specifier)           \
void function_name(int total, char *user_input[])                         \
{                                                                         \
    int string_length = total - 1;                                        \
    type operands[MAX] = {0};                                             \
    char operators[MAX] = {0};                                            \
    int conversion_index = 0;                                             \
	                                                                      \
    for (int i = 2; i <= string_length; i++)                              \
    {                                                                     \
        if (i % 2 == 1)                                                   \
        {                                                                 \
            sscanf( user_input[i], "%c", &operators[conversion_index] );  \
            operands[conversion_index] = 0;                               \
        }                                                                 \
        else                                                              \
        {                                                                 \
            operands[conversion_index] = std_function( user_input[i] );   \
            operators[conversion_index] = '0';                            \
        }                                                                 \
        conversion_index++;                                               \
    }                                                                     \
	                                                                      \
    type answer = operands[0];                                            \
                                                                          \
    for(int i = 1; i < conversion_index; i += 2)                          \
    {                                                                     \
        switch( operators[i] )                                            \
        {                                                                 \
            case '+':                                                     \
                answer = answer + operands[i + 1];                        \
                break;                                                    \
            case '-':                                                     \
                answer = answer - operands[i + 1];                        \
                break;                                                    \
            case '*':                                                     \
                answer = answer * operands[i + 1];                        \
                break;                                                    \
            case '/':                                                     \
                answer = answer / operands[i + 1];                        \
                break;                                                    \
            case '%':                                                     \
                answer = answer % operands[i + 1];                        \
                break;                                                    \
            default:                                                      \
                printf("Something went wrong:INT_SOLVE failure\n");       \
                exit(EXIT_FAILURE);                                       \
        }                                                                 \
    }                                                                     \
    puts("");                                                             \
    printf("answer = " specifier "\n", answer);                           \
}                                                                         
  
/*"char *end" is used for better error detection in the str functions*/  
#define SOLVE_FLOAT(type, function_name, std_function, specifier)             \
void function_name(int total, char *user_input[])                             \
{                                                                             \
    int string_length = total - 1;                                            \
    type operands[MAX] = {0};                                                 \
    char operators[MAX] = {0};                                                \
    int conversion_index = 0;                                                 \
	char *end;                                                                \
	                                                                          \
    for (int i = 2; i <= string_length; i++)                                  \
    {                                                                         \
        if (i % 2 == 1)                                                       \
        {                                                                     \
            sscanf( user_input[i], "%c", &operators[conversion_index] );      \
            operands[conversion_index] = 0;                                   \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            operands[conversion_index] = std_function(user_input[i], &end);   \
            operators[conversion_index] = '0';                                \
        }                                                                     \
        conversion_index++;                                                   \
    }                                                                         \
	                                                                          \
    type answer = operands[0];                                                \
                                                                              \
    for(int i = 1; i < conversion_index; i += 2)                              \
    {                                                                         \
        switch( operators[i] )                                                \
        {                                                                     \
            case '+':                                                         \
                answer = answer + operands[i + 1];                            \
                break;                                                        \
            case '-':                                                         \
                answer = answer - operands[i + 1];                            \
                break;                                                        \
            case '*':                                                         \
                answer = answer * operands[i + 1];                            \
                break;                                                        \
            case '/':                                                         \
                answer = answer / operands[i + 1];                            \
                break;                                                        \
            case '%':                                                         \
                printf("Logical error:\n");                                   \
                printf("float cannot use \'%%\'");                            \
				exit(EXIT_FAILURE);                                           \
            default:                                                          \
                printf("Something went wrong: FLOAT_SOLVE failure\n");        \
                exit(EXIT_FAILURE);                                           \
        }                                                                     \
    }                                                                         \
    puts("");                                                                 \
    printf("answer = " specifier "\n", answer);                               \
}                                                                         

//so definitions.c has access to them
extern char *options[];
extern int available_options;

//remainder of function prototypes
void solve_once(int type_code, int argc, char *argv[] );
void REPL(int type_code);
void help_msg();
