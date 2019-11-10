#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**3.2.
Write a function to extract, from a source string,
a substring identified by the position in the source string
and by the length expressed as a number of characters.*/

char *extractString (char *string, int initialPosition, int length)
{
    char *substring = (char*)malloc(sizeof(char)*length);
    int i,j=initialPosition;

    for(i=0 ; i<length; i++)
    {
        substring[i]=string[j+i];
    }
    substring[i]='\0';

    return substring;
}


/**3.3.
Write  a  function  to  insert  a  source  character  string  in
a  destination character string, at a  given position.*/

char *insertString (char *destination, char *source, int position)
{
    int lengthDestination, lengthSource,i;
    lengthDestination = strlen(destination);
    lengthSource = strlen(source);

    char *finalString = (char*)malloc(sizeof(char)*(lengthDestination+lengthSource));

    for(i=0; i<position; i++)
    {
        finalString[i]=destination[i];
    }

    for(i=position; i<position+lengthSource; i++)
    {
        finalString[i]=source[i-position];
    }

    for(i=position+lengthSource; i<lengthDestination+lengthSource; i++)
    {
        finalString[i]=destination[i-position-1];
    }

    finalString[i]='\0';

    return finalString;
}

/**3.4.  Write  a  function  to  delete  a  substring  from  a  given  character  string,
specifying  the  beginning position and the length of the substring*/

char *deleteSubstring (char *string, int position, int substringLength)
{
    int stringLength = strlen(string);
    char *newString = (char*)malloc(sizeof(char)*(stringLength-substringLength+1));

    int i,j;
    for(i=0; i<position; i++)
    {
        newString[i]=string[i];
    }

    for(j=position+substringLength; j<stringLength; j++)
    {
        newString[i++]=string[j];
    }
    newString[i]='\0';

    return newString;
}

/**3.5. Write a function to verify if a given string is asubstring of another character string.
If it is, specify the beginning position of the substring.**/

int verifySubstring(char *string, char *substring, int stringLength, int substringLength)
{
    int ok=0,position=-1;
    int i,j;

    for(i=0 ; i<stringLength-substringLength && ok==0 ; i++)
    {
        if(string[i]==substring[0])
        {
            ok=1;
            int ii=i;
            for(j=0; j<substringLength; j++)
            {
                if(string[ii++]!=substring[j])
                {
                    ok = 0;
                }
            }

            if(ok==1 && position==-1)
            {
                position = i;
            }
        }
    }

    return position;
}

/**3.6. Write two functions, the first to convert an integer or
real number into a string of characters,
and the second to perform the inverse operation.*/

char intToChar (double number)
{
    char string[1001]; ///nu pot declara cu pointer pentru ca nu am de unde sa stiu lungimea sirului
    int copy = number, i,nrDigits=0;

    do
    {
        nrDigits++;
        copy=copy/10;
    }
    while(copy);

    copy = number;

    ///punem in string cifrele dinainte de virgula
    for(i=nrDigits-1; i>=0; i--)
    {

        int lastDigit=copy%10;
        string[i]=(char)(lastDigit+'0');
        copy=copy/10;
    }

    ///punem in string ce este dupa virgula daca exista
    if(number-(int)number!=0)
    {
        string[nrDigits]='.';

        double decimalNumber = number-(int)number;
        printf("%f\n", decimalNumber);

        int i;

        /** asa setez eu precizia la 5 zecimale pt ca pe StackOverflow gasesc setarea preciziei in C
            doar pentru afisare si in CodeBlocks imi apar numere random la unele lucruri
            (de ex ( 208.987 - (int)208.987 ) ar trebui sa fie 0.987 dar in CodeBlocks imi da 0.9870050 si imi
            strica tot algoritmul asadar aleg eu sa verific doar primele 5 zecimale) */

        for(i=1; i<=5; i++)
        {
            decimalNumber = decimalNumber*10;
        }

        int intDecimalNumber = (int)decimalNumber;

        for(i=nrDigits+5; i>=nrDigits+1; i--)
        {
            int lastDecimalDigit = intDecimalNumber%10;
            string[i] = (char)(lastDecimalDigit+'0');
            intDecimalNumber = intDecimalNumber/10;
        }

        string[nrDigits+6] = '\0';

        /** in final, in loc sa afiseze 208.987 de exemplu imi afiseaza 208.98699
            dar m-am saturat */

    }
    else
    {
        string[nrDigits] = '\0';
    }

    return string;

}

///3.6 VARIANTA 2 DE LA CHAR LA INT

double charToInt (char *string)
{
    int i,length = strlen(string);
    double number = 0;
    for(i=0; i<length; i++)
    {
        if(string[i]=='.')
        {
            break;
        }

        number = number*10 + (int)(string[i] - '0');
    }

    int nrOfDecimals = length - i - 1;

    ///aici ne ocupam de zecimale

    int pow = 10,j;
    i++;

    ///urmatorul for adauga zecimalele

    for(j=1; j<=nrOfDecimals; j++)
    {
        int moreDecimals = (int)(string[i++] - '0');
        double something = moreDecimals/(double)pow;
        printf("%f\n",something);
        number = number + something;
        ///nu mai am nume de variabile
        pow = pow*10;
    }

    printf("%f",number);
    return number;
}


int main()
{
    float number;
    ///scanf("%f",&number);

    char *string = (char*)malloc(sizeof(char)*12);

    scanf("%s",string);

    charToInt(string);

    return 0;
}
