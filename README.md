This was both a mental experiment and has practical uses
for people learning C to see how a C math equation should
turn out. Limitations:

-doesn't do an exact float calculation, as you have to
ensure the compiler does float by putting "f" next to the
numbers.

-it's linear, so you can't do real order of operations or
use parenthesis in equations. Problems will be solved from left
to right despite the operators.

# Install

<pre><code>
git clone https://github.com/LEDparty/cmath-with-arrays
cd cmath-with-arrays
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
