This was both a mental experiment and has practical uses
for people learning C to see how a C math equation should
turn out. The problem with it is that it uses arrays, so
it's not capable of parenthesis and order of operations.

Since it works, it's considered a completed project, and
no more data types will be added since it currently has all
data types that are native to the C language, without the
kinds that are available with pre-defined macros.

# Install

<pre><code>
git clone https://github.com/LEDparty/cmath-linear-cmd-calculator
cd cmath-linear-cmd-calculator
make
</pre></code>

Run program like this:

<pre><code>
./cmath
</pre></code>

if you think it's useful, install system wide like this:

<pre><code>
sudo install cmath /usr/local/bin
</pre></code>

# How to use

Running the program with the wrong number of arguments, or wrong
argument types, will output the help message in most cases. You can
run it as a continous command line prompt or just solve one equation
(the latter being my favorite).

You must use a data types as the second argument. Example of how to
keep solving for -int:

<pre><code>
./cmath -int
</pre></code>

You can also do the equation directly on the command line for one
answer and an exit:

<pre><code>
./cmath -int 2 + 6
</pre></code>

This will produce an answer as ```answer = 8``` as the output.

If you want to multiply, you have to put the asterisks in quotes or
else bash will expand the answer as a wild card (giving you a wildly
wrong answer). Example:

<pre><code>
./cmath -int 2 "*" 6
</pre></code>
