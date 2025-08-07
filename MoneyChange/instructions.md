A = initial amount
B = rate to convert to USD
C = target currency
D = rate to convert from target currency to USD


If the first argument is an option (-l or -s), we would still like the program to behave the same for the rest of the arguments. Therefore, if we know that the first arguments are those options, we could simply increment an index variable to shift to one.

In fact, bash in linux has a feature like this by default. I wonder if C also has it. If it does, I need to find out how to use it.

the options have to come first, but one does not have to be before the other.

If the first argument begins with an '-', we can assume it begins with an argument. However, we would also like to know if there is another argument after it.

if(first character of first argument == '-') {
    if(first argument == '--long' || '-l') {
        "A becomes B"
    } else if (first argument is -)
}

but we want to check this condition again, so there must be a way to modularize the oode so that we don't have to write the same statement twice since it would do the same thing anyway, we just want to write it once and call it twice.


that's because the option could either be the first, second or third option.

the option --long does not require any arguments.

Can we think of the output as an array?
and then can we create the output in parts?

we know that if the first option is -l, we won't have to worry about anything coming after it, so let's deal with it first

if (argsv[1] == '-l' || argsv[1] == '-long') {
    int size += 1; // to the size of the final array.
}

1. take inline arguments
2. determine which options have been chosen
    if (arguments include)
3. take the amount
4. determine the number of exchanges passed to the program

