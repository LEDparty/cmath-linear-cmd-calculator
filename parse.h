//make functions available across files
#define MAX 51
void solve_once( int type_code, int argc, char *argv[] );
void REPL(int type);

int parse_int( int total, char *user_input[] );
int parse_long( int total, char *user_input[] );
int parse_float( int total, char *user_input[] );
int parse_double( int total, char *user_input[] );
int parse_long_double( int total, char *user_input[] );
