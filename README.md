# Hash code generator

[1 excercise - Hash generator](https://github.com/Arijus1979/BGT-Hash-code-generator/files/9659589/1.uzduotis.-.Hash.generatoriaus.kurimas.2022-09-22.pdf)

### The application generates a 256-bit hash code for any data input.

## Pseudo-code
```
Function HexToBin
{
    Every Hex digit is converted into a Binary form
}

Function Hashing
{
    Hash variable determines the starting value of the Hash number
    Multiply variable determines the multiplier that the Hash value will be multiplied by
    For each i, Hash + ASCII value of a char * multiplier
}

Function decToHexa
{
    Changes the decimal numbers to Hexadecimal
}

Function to256bit
{
    For each i a Hexadecimal number is added into the string
    Only the first 64 symbols are returned
}

Function hashas
{
    Joins the Hashing and to256bit functions
}

Function fromFile
{
    Reads data from a file.
    User inputs the file name.
}

Function random_string
{
    Generates a user-specified length random string.
}

Function generateFiles
{
    Generates the files needed for testing
}

Function testing1
{
    Testing for similarities between different data samples
}

Function efec
{
    Testing the effectiveness of the Hashing function
}

Function collision
{
    Testing if the collisions occur
}

Function howSimilar
{
    Calculates the percentage of how similar are the two hash codes by HEX values
}

Function howSimilar1
{
    Calculates the percentage of how similar are the two hash codes by BIT values
}

Function similarity
{
    Calculates the minimum, maximum and average values of the similarity between hashes in HEX and BIT values.
}

Function initiate
{
    The function meant for user interface.
}

Function main
{
    Main function
}

```

# Testing results
































