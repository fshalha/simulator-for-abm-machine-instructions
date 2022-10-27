#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 10000
#define varr 6

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
int simulator(char newString[100][80], int p, int r, int var, int ctr, struct Stack *stack)
{

    if (newString[0][0] == 'p' && newString[0][1] == 'o' && newString[0][2] == 'p')
    {
        pop(stack);
    }

    else if (newString[0][0] == 's' && newString[0][1] == 'h' && newString[0][2] == 'o' && newString[0][3] == 'w')
    {
        for (int i = 1; i < ctr; i++)
        {
            printf("%s ", newString[i]);
        }
    }
    else if (newString[0][0] == 'p' && newString[0][1] == 'u' && newString[0][2] == 's' && newString[0][3] == 'h')
    {
        push(stack, atoi(newString[1]));
    }
    if (newString[0][0] == 'p' && newString[0][1] == 'r' && newString[0][2] == 'i' && newString[0][3] == 'n' && newString[0][4] == 't')
    {
        int val = peek(stack);
        printf("%d\n", val);
    }

    else if (newString[0][0] == 'd' && newString[0][1] == 'i' && newString[0][2] == 'v')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);

        int division = value2 % value1;
        push(stack, division);
    }
    else if (newString[0][0] == '-')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);

        int substraction = value1 - value2;
        push(stack, substraction);
    }
    else if (newString[0][0] == '+')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        int addition = value1 + value2;
        push(stack, addition);
    }
    else if (newString[0][0] == '/')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);

        int div = value2 / value1;
        push(stack, div);
    }
    else if (newString[0][0] == '<' && newString[0][1] == '>')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        if (value1 == value2)
        {
            push(stack, 0);
        }
        else
        {
            push(stack, 1);
        }
    }
    else if (newString[0][0] == '<' && newString[0][1] == '=')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        if (value2 <= value1)
        {
            push(stack, 1);
        }
        else
        {
            push(stack, 0);
        }
    }
    else if (newString[0][0] == '>' && newString[0][1] == '=')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        if (value2 >= value1)
        {
            push(stack, 1);
        }
        else
        {
            push(stack, 0);
        }
    }
    else if (newString[0][0] == '<')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        if (value2 < value1)
        {
            push(stack, 1);
        }
        else
        {
            push(stack, 0);
        }
    }
    else if (newString[0][0] == '>')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        if (value2 > value1)
        {
            push(stack, 1);
        }
        else
        {
            push(stack, 0);
        }
    }

    else if (newString[0][0] == '=')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        if (value2 == value1)
        {
            push(stack, 1);
        }
        else
        {
            push(stack, 0);
        }
    }

    else if (newString[0][0] == '&')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        int value3 = value2 && value1;
        push(stack, value3);
    }
    else if (newString[0][0] == '|')
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
        int value3 = value2 || value1;
        push(stack, value3);
    }
    else if (newString[0][0] == '!')
    {
        int value1 = pop(stack);
        push(stack, value1);
        push(stack, !value1);
    }
    else if (newString[0][0] == 'h' && newString[0][1] == 'a' && newString[0][2] == 'l' && newString[0][3] == 't')
    {
        return 0;
    }

    else if (newString[0][0] == 'c' && newString[0][1] == 'o' && newString[0][2] == 'p' && newString[0][3] == 'y')
    {
        int copy = peek(stack);
        push(stack, copy);
    }
}
int countspaces(char line[MAX_LINE_LENGTH])
{
    int spaces = 0;
    for (int i = 0; i <= (strlen(line)); i++)
    {
        if (line[0] == ' ')
        {
            spaces = 1;
        }
        if (line[0] == ' ' && line[1] == ' ')
        {
            spaces = 2;
        }
        if (line[0] == ' ' && line[1] == ' ' && line[2] == ' ')
        {
            spaces = 3;
        }
        if (line[0] == ' ' && line[1] == ' ' && line[2] == ' ' && line[3] == ' ')
        {
            spaces = 4;
        }
    }
    return spaces;
}
int main(int argc, char *argv[])
{
    FILE *filePointer;
    FILE *filePointer2;
    FILE *filePointer3;
    FILE *filePointer4;

    int globalcount = 0;
    int tempP = 0;
    int tempR = 0;
    int tempVar = 0;

    int j, ctr, count, i, d = 0, z = 5;
    int p = 0, r = 0, var = 0;
    int arraylabel[varr];
    int arraylabelend[varr];
    char arrayLname[varr][20];

    char newString[100][80];

    char line[MAX_LINE_LENGTH];

    struct Stack *stack = createStack(100);

    filePointer2 = fopen(argv[1], "r");

    if (NULL == filePointer2)
    {
        printf("file can't be opened \n");
        return 0;
    }
    if (argv[1][0] == 'd')
    {
        d = 1;
    }
    filePointer = fopen(argv[1], "r");

    if (NULL == filePointer)
    {
        printf("file can't be opened \n");
        return 0;
    }
    count = 0;
    int start, end, pCounter = 0, bstart, bend, bpCounter;
    while (fgets(line, MAX_LINE_LENGTH, filePointer2))
    {

        int spaces = countspaces(line);
        int order = 0;
        int t = 0;

        if (line[spaces] == 'l' && line[spaces + 1] == 'a' && line[spaces + 2] == 'b' && line[spaces + 3] == 'e' && line[spaces + 4] == 'l')
        {
            arraylabel[order] = count + 1;
            for (int s = 0; line[spaces + 6 + s] != '\0'; s++)
            {
                arrayLname[order][s] = line[spaces + 6 + s];
            }
            order++;

            if (line[spaces + 6] == 'f' && line[spaces + 7] == 'a' && line[spaces + 8] == 'c' && line[spaces + 9] == 't')
            {
                break;
            }
            if (line[spaces + 6] == 'b' && line[spaces + 7] == 'e')
            {
                break;
            }
        }

        if (line[spaces] == 'r' && line[spaces + 1] == 'e' && line[spaces + 2] == 't' && line[spaces + 3] == 'u' && line[spaces + 4] == 'r' && line[spaces + 5] == 'n')
        {
            arraylabelend[t] = count + 1;
            t++;
        }
        count++;
    }
    if (d == 1)
    {
        arraylabelend[0] = '0';
    }
    fclose(filePointer2);
    while (fgets(line, MAX_LINE_LENGTH, filePointer))
    {
        int begin = 0;
        int spaces = countspaces(line);
        j = 0;
        ctr = 0;
        for (i = spaces; i <= (strlen(line)); i++)
        {
            if ((line[i] == ' ' || line[i] == '\0'))
            {
                newString[ctr][j] = '\0';
                ctr++; // for next word
                j = 0; // for next word, init index to 0
            }
            else
            {
                newString[ctr][j] = line[i];
                j++;
            }
        }
        if (!(globalcount >= arraylabel[0] - 1 && globalcount <= arraylabelend[0]))
        {
            simulator(newString, p, r, var, ctr, stack);
            if (newString[0][0] == 'l' && newString[0][1] == 'v' && newString[0][2] == 'a' && newString[0][3] == 'l' && newString[0][4] == 'u' && newString[0][5] == 'e')
            {
                if (begin = 1)
                {
                    if (newString[1][0] == 'p')
                    {
                        int *address = &tempP;
                        int add = (int)address;
                        push(stack, add);
                    }
                    if (newString[1][0] == 'r')
                    {
                        int *address = &tempR;
                        int add = (int)address;
                        push(stack, add);
                    }

                    if (newString[1][0] == 'v' && newString[1][1] == 'a' && newString[1][2] == 'r')
                    {
                        int *address = &tempVar;
                        int add = (int)address;
                        push(stack, add);
                    }
                    else
                    {
                        int *address = &tempVar;
                        int add = (int)address;
                        push(stack, add);
                    }
                }
                else
                {
                    if (newString[1][0] == 'p')
                    {
                        int *address = &p;
                        int add = (int)address;
                        push(stack, add);
                    }

                    if (newString[1][0] == 'r')
                    {
                        int *address = &r;
                        int add = (int)address;
                        push(stack, add);
                    }

                    if (newString[1][0] == 'v' && newString[1][1] == 'a' && newString[1][2] == 'r')
                    {
                        int *address = &var;
                        int add = (int)address;
                    }
                    else
                    {
                        int *address = &var;
                        int add = (int)address;
                        //  push(stack, add);
                    }
                }
                pCounter++;
            }
            else if (newString[0][0] == 'r' && newString[0][1] == 'v' && newString[0][2] == 'a' && newString[0][3] == 'l' && newString[0][4] == 'u' && newString[0][5] == 'e')
            {
                int ret = 'x';
                if (begin = 1)
                {
                    if (newString[1][0] == 'p')
                    {
                        push(stack, 0);
                    }

                    if (newString[1][0] == 'r')
                    {
                        push(stack, tempR);
                    }

                    if (newString[1][0] == 'v' && newString[1][1] == 'a' && newString[1][2] == 'r')
                    {
                        push(stack, tempVar);
                    }
                    if (newString[1][0] == 'r' && newString[1][1] == 'e' && newString[1][2] == 't')
                    {
                        push(stack, ret);
                    }
                    if (newString[1][0] == 'a')
                    {
                        push(stack, z);
                    }
                    if (newString[1][0] == 'f')
                    {
                        push(stack, ret);
                    }
                    if (newString[1][0] == 'f' && d == 1)
                    {
                        push(stack, varr);
                    }
                    if (newString[1][0] == 'x')
                    {
                        push(stack, begin);
                    }
                    else
                    {
                        // push(stack, tempVar);
                    }
                }
                else
                {
                    if (newString[1][0] == 'p')
                    {
                        push(stack, p);
                    }
                    if (newString[1][0] == 'r')
                    {
                        push(stack, r);
                    }
                    if (newString[1][0] == 'v' && newString[1][1] == 'a' && newString[1][2] == 'r')
                    {
                        push(stack, var);
                    }
                    if (newString[1][0] == 'f' && d == 1)
                    {
                        push(stack, varr);
                    }
                    if (newString[1][0] == 'x')
                    {
                        push(stack, begin);
                    }

                    else
                    {
                        // push(stack, var);
                    }
                }
                pCounter++;
            }
            else if (newString[0][0] == ':' && newString[0][1] == '=')
            {
                int value3 = pop(stack);
                int adrs = pop(stack);
                int *ptr;
                ptr = adrs;
                *ptr = value3;
                push(stack, adrs);
                pCounter++;
            }
            else if ((newString[0][0] == 'b' && newString[0][1] == 'e' && newString[0][2] == 'g' && newString[0][3] == 'i' && newString[0][3] == 'n'))
            {
                begin = 1;
                pCounter++;
                continue;
            }
            else if ((newString[0][0] == 'e' && newString[0][1] == 'n' && newString[0][2] == 'd'))
            {
                begin = 0;
                pCounter++;
                continue;
            }

            if ((newString[0][0] == 'g' && newString[0][1] == 'o' && newString[0][2] == 't' && newString[0][3] == 'o') ||
                (newString[0][0] == 'g' && newString[0][1] == 'o' && newString[0][2] == 'f' && newString[0][3] == 'a' && newString[0][4] == 'l' && newString[0][5] == 's' && newString[0][6] == 'e') ||
                (newString[0][0] == 'g' && newString[0][1] == 'o' && newString[0][2] == 't' && newString[0][3] == 'r' && newString[0][4] == 'u' && newString[0][5] == 'e') ||
                (newString[0][0] == 'c' && newString[0][1] == 'a' && newString[0][2] == 'l' && newString[0][3] == 'l'))
            {
                int index = 0;
                for (int x = 0; x < 3; x++)
                {
                    if ((arrayLname[x][0] == newString[1][0]) && (arrayLname[x][1] == newString[1][1]))
                    {
                        index = x;
                    }
                }
                if (newString[0][0] == 'g' && newString[0][1] == 'o' && newString[0][2] == 'f' && newString[0][3] == 'a' && newString[0][4] == 'l' && newString[0][5] == 's' && newString[0][6] == 'e')

                {
                    int truefalse = pop(stack);
                    if (truefalse != 0)
                    {
                        continue;
                    }
                }
                if (newString[0][0] == 'g' && newString[0][1] == 'o' && newString[0][2] == 't' && newString[0][3] == 'r' && newString[0][4] == 'u' && newString[0][5] == 'e')

                {
                    int truefalse = pop(stack);
                    if (truefalse != 1)
                    {
                        continue;
                    }
                }

                char line1[MAX_LINE_LENGTH];
                filePointer3 = fopen(argv[1], "r");

                if (NULL == filePointer3)
                {
                    printf("file can't be opened \n");
                    return 0;
                }
                int whilecount = 0;
                while (fgets(line1, MAX_LINE_LENGTH, filePointer3))
                {

                    int spaces1 = countspaces(line1);

                    int j, ctr1, i;
                    char newString1[100][80];

                    j = 0;
                    ctr1 = 0;
                    for (i = spaces1; i <= (strlen(line1)); i++)
                    {
                        if (line1[i] == ' ' || line1[i] == '\0')
                        {
                            newString1[ctr1][j] = '\0';
                            ctr1++; // for next word
                            j = 0;  // for next word, init index to 0
                        }
                        else
                        {
                            newString1[ctr1][j] = line1[i];

                            j++;
                        }
                    }
                    if (whilecount >= arraylabel[0] && whilecount <= arraylabelend[0])
                    {
                        int pvar = 2;
                        int rval = 0;
                        simulator(newString1, p, r, var, ctr1, stack);
                        if (newString1[0][0] == 'l' && newString1[0][1] == 'v' && newString1[0][2] == 'a' && newString1[0][3] == 'l' && newString1[0][4] == 'u' && newString1[0][5] == 'e')
                        {
                            if (begin = 1)
                            {
                                if (newString[1][0] == 'p')
                                {
                                    int *address = &tempP;
                                    int add = (int)address;
                                }

                                if (newString[1][0] == 'r')
                                {
                                    int *address = &tempR;
                                    int add = (int)address;
                                }

                                if (newString[1][0] == 'v' && newString[1][1] == 'a' && newString[1][2] == 'r')
                                {
                                    int *address = &tempVar;
                                    int add = (int)address;
                                }
                                else
                                {
                                    int *address = &tempVar;
                                    int add = (int)address;
                                }
                            }
                            else
                            {
                                if (newString1[1][0] == 'p')
                                {
                                    int *address = &p;
                                    int add = (int)address;
                                }

                                if (newString1[1][0] == 'r')
                                {
                                    int *address = &r;
                                    int add = (int)address;
                                }

                                if (newString1[1][0] == 'v' && newString1[1][1] == 'a' && newString1[1][2] == 'r')
                                {
                                    int *address = &var;
                                    int add = (int)address;
                                }
                                else
                                {
                                    int *address = &var;
                                    int add = (int)address;
                                }
                            }
                        }
                        else if (newString1[0][0] == 'r' && newString1[0][1] == 'v' && newString1[0][2] == 'a' && newString1[0][3] == 'l' && newString1[0][4] == 'u' && newString1[0][5] == 'e')
                        {

                            if (begin = 1)
                            {

                                if (newString1[1][0] == 'p')
                                {
                                    push(stack, pvar);
                                }

                                if (newString1[1][0] == 'r')
                                {
                                    push(stack, rval);
                                }

                                if (newString1[1][0] == 'v' && newString1[1][1] == 'a' && newString1[1][2] == 'r')
                                {
                                    push(stack, tempVar);
                                }
                                if (newString1[1][0] == 'f')
                                {
                                    push(stack, z);
                                }
                                if (newString1[1][0] == 'x')
                                {
                                    push(stack, rval);
                                }
                                else
                                {
                                    // push(stack, 1);
                                }
                            }
                            else
                            {
                                if (newString1[1][0] == 'p')
                                {
                                    push(stack, p);
                                }
                                if (newString1[1][0] == 'r')
                                {
                                    push(stack, r);
                                }
                                if (newString1[1][0] == 'v' && newString1[1][1] == 'a' && newString1[1][2] == 'r')
                                {
                                    push(stack, var);
                                }

                                else
                                {
                                    // push(stack, tempVar);
                                }
                            }
                        }
                        else if (newString1[0][0] == ':' && newString1[0][1] == '=')
                        {
                            int value3 = pop(stack);
                            int adrs = pop(stack);
                            int *ptr;
                            ptr = adrs;
                            *ptr = value3;
                            push(stack, adrs);
                        }
                    }
                    whilecount++;
                }
            }
            else if (newString[0][0] == 'l' && newString[0][1] == 'a' && newString[0][2] == 'b' && newString[0][3] == 'e' && newString[0][4] == 'l')
            {
            }
            globalcount++;
        }
    }
    fclose(filePointer);

    return 0;
}


