#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate(char* s[], int N)
{
    // Step 1: Handle * and /
    int values[N]; // store the intermediate results
    char ops[N];   // store the operators
    int valIndex = 0, opIndex = 0;
    
    // Initialize with the first number
    values[valIndex++] = atoi(s[0]);

    for (int i = 1; i < N; i += 2) // process operators and numbers
    {
        char op = s[i][0];   // current operator
        int num = atoi(s[i + 1]); // next number
        
        if (op == '*' || op == '/') 
        {
            if (op == '*')
            {
                values[valIndex - 1] *= num; // multiply with the last value
            }
            else
            {
                values[valIndex - 1] /= num; // divide and take the floor
            }
        }
        else // for + and - operators
        {
            ops[opIndex++] = op;  // store the operator
            values[valIndex++] = num; // store the number
        }
    }

    // Step 2: Handle + and -
    int result = values[0];
    for (int i = 0; i < opIndex; i++) 
    {
        if (ops[i] == '+')
        {
            result += values[i + 1];
        }
        else if (ops[i] == '-')
        {
            result -= values[i + 1];
        }
    }

    return result;
}

int main()
{
    // Example expression: 25 + 3 / 10 + 12 * 3
    char* s[9] = { "25", "+", "3", "/", "10", "+", "12", "*", "3" };
    int ans = calculate(s, 9);
    printf("Result: %d\n", ans); // Should print the correct result
    return 0;
}
