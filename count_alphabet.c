
/*********************************************************
Version 2
*********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define DEBUG 1
#ifdef DEBUG
#define DBG_PRINT(x) printf x
#else
#define DBG_PRINT(x) do {} while(0)
#endif

/*
 * Counter for each alphabet
 * Store ther numbers of each alphabet,
 * which will be the answers.
 */
unsigned long long count_alph[26]; 

/*
 * Counting alphabet numbers of n,
 * where n is between 0 and 19.
 * Return Value:
 * 1: success
 * 0: fail
 */
int count_0_19(int n)
{
    int i, size, idx_alph;
    char str_n[10];

    if (n < 0 || n > 19)
        return 0;
    
    size = 0;
    
    switch(n) {
    case 1:
        size = strlen("one");
        strcpy(str_n, "one");
        break;
    
    case 2:
        size = strlen("two");
        strcpy(str_n, "two");
        break;
    
    case 3:
        size = strlen("three");
        strcpy(str_n, "three");
        break;
    
    case 4:
        size = strlen("four");
        strcpy(str_n, "four");
        break;
    
    case 5:
        size = strlen("five");
        strcpy(str_n, "five");
        break;
    
    case 6:
        size = strlen("six");
        strcpy(str_n, "six");
        break;
    
    case 7:
        size = strlen("seven");
        strcpy(str_n, "seven");
        break;
    
    case 8:
        size = strlen("eight");
        strcpy(str_n, "eight");
        break;
    
    case 9:
        size = strlen("nine");
        strcpy(str_n, "nine");
        break;
    
    case 10:
        size = strlen("ten");
        strcpy(str_n, "ten");
        break;
    
    case 11:
        size = strlen("eleven");
        strcpy(str_n, "eleven");
        break;
    
    case 12:
        size = strlen("twelve");
        strcpy(str_n, "twelve");
        break;
    
    case 13:
        size = strlen("thirteen");
        strcpy(str_n, "thirteen");
        break;
    
    case 14:
        size = strlen("fourteen");
        strcpy(str_n, "fourteen");
        break;
    
    case 15:
        size = strlen("fifteen");
        strcpy(str_n, "fifteen");
        break;
    
    case 16:
        size = strlen("sixteen");
        strcpy(str_n, "sixteen");
        break;
        
    case 17:
        size = strlen("seventeen");
        strcpy(str_n, "seventeen");
        break;
        
    case 18:
        size = strlen("eighteen");
        strcpy(str_n, "eighteen");
        break;
        
    case 19:
        size = strlen("nineteen");
        strcpy(str_n, "nineteen");
        break;
    default:
        break;
    }

    if (size) {
        DBG_PRINT(("%d: [%s] (%d)\n", n, str_n, size));
        
        for (i = 0 ; i < size ; i++) { // count alphabet number of string number
            if (str_n[i] >= 'a' && str_n[i] <= 'z' ) { // check if is alphabet
                idx_alph = str_n[i]-'a';
                count_alph[idx_alph]++;
            }
        }
    }
    
    return 1;
} /* count_0_19 */

/*
 * Counting alphabet numbers of n,
 * where n is between 20 and 99.
 * Return Value:
 * 1: success
 * 0: fail
 */
int count_20_99(int n) 
{
    int i, size, idx_alph, res;
    char str_n[10];
    int ten, single=1;
    
    if ( n < 20 || n > 99)
        return 0;
    
    ten = n / 10;
    size = 0;
    
    switch(ten) {
    case 2: // n= 20-29
        size = strlen("twenty");
        strcpy(str_n, "twenty");
        break;
    
    case 3:
        size = strlen("thirty");
        strcpy(str_n, "thirty");
        break;
    
    case 4:
        size = strlen("fourty");
        strcpy(str_n, "fourty");
        break;
    
    case 5:
        size = strlen("fifty");
        strcpy(str_n, "fifty");
        break;
    
    case 6:
        size = strlen("sixty");
        strcpy(str_n, "sixty");
        break;
    
    case 7:
        size = strlen("seventy");
        strcpy(str_n, "seventy");
        break;
    
    case 8:
        size = strlen("eighty");
        strcpy(str_n, "eighty");
        break;
    
    case 9:
        size = strlen("ninety");
        strcpy(str_n, "ninety");
        break;
    
    default:
        break;
    }
    
    if (size) {   
        DBG_PRINT(("%d: [%s] (%d)\n", n, str_n, size));
        
        for (i = 0 ; i < size ; i++) { // count alphabet number of string number
            if (str_n[i] >= 'a' && str_n[i] <= 'z' ) { // check if is alphabet
                idx_alph = str_n[i]-'a';
                count_alph[idx_alph]++;
            }
        }
    }
    
    single = n % 10;// count for 0-9
    res = count_0_19(single);
    return res;
} /* count_20_99 */

/*
 * Counting alphabet numbers of n,
 * where n is between 0 and 999.
 * Return Value:
 * 1: success
 * 0: fail
 */
int count_0_999(int n)
{
    int i, size, idx_alph, res=1;
    char str_n[10];
    int ten, hundred, rest;
    
    if ( n < 0 || n > 999)
        return 0;
    
    hundred = n / 100;
    if ( hundred ) {
        size = strlen("hundred");
        strcpy(str_n, "hundred");
        
        DBG_PRINT(("%d: [%s] (%d)\n", n, str_n, size));
        for (i = 0 ; i < size ; i++) { // count alphabet number of string number
            if (str_n[i] >= 'a' && str_n[i] <= 'z' ) { // check if is alphabet
                idx_alph = str_n[i]-'a';
                count_alph[idx_alph]++;
            }
        }
    }
    res &= count_0_19(hundred);
    
    rest = n % 100;
    ten = rest / 10 ;
    if ( ten > 1 ) // 20~99
        res &= count_20_99(rest);
    else // 0~19
        res &= count_0_19(rest);
    
    return res;
} /* count_0_999 */

/*
 * Counting alphabet numbers of n,
 * where n is between 1,000 and 9,999.
 * Return Value:
 * 1: success
 * 0: fail
 */
int count_thousand(int n)
{
    int i, size, idx_alph, res=1;
    char str_n[10];
    int thousand;
    
    if ( n > 999999 ) //999,999
        return 0;
    
    thousand = n / 1000; //1,000
    if (thousand) {
        size = strlen("thousand");
        strcpy(str_n, "thousand");
        
        DBG_PRINT(("%d: [%s] (%d)\n", n, str_n, size));
        for (i = 0 ; i < size ; i++) { // count alphabet number of string number
            if (str_n[i] >= 'a' && str_n[i] <= 'z' ) { // check if is alphabet
                idx_alph = str_n[i]-'a';
                count_alph[idx_alph]++;
            }
        }
    }
    
    return count_0_999(thousand);
} /* count_thousand */

/*
 * Counting alphabet numbers of n,
 * where n is between 1,000,000 and 9,999,999.
 * Return Value:
 * 1: success
 * 0: fail
 */
int count_million(int n)
{
    int i, size, idx_alph, res=1;
    char str_n[10];
    int million;
    
    if ( n > 999999999 ) // 999,999,999
        return 0;
    
    million = n / 1000000; // 1,000,000
    if (million) {
        size = strlen("million");
        strcpy(str_n, "million");
        
        DBG_PRINT(("%d: [%s] (%d)\n", n, str_n, size));
        for (i = 0 ; i < size ; i++) { // count alphabet number of string number
            if (str_n[i] >= 'a' && str_n[i] <= 'z' ) { // check if is alphabet
                idx_alph = str_n[i]-'a';
                count_alph[idx_alph]++;
            }
        }
    }
    
    return count_0_999(million);
} /* count_million */


int main(int argc, char* argv[])
{

    int n_max, nth, i, n, idx_alph, alpha, found;
    unsigned long long sum;

    if (argc != 3) {
        printf("Please input two numbers: 1. how many numbers, 2. n-th letter to find\n");
        printf("e.g. ./a.out 1234567 888888\n");
        printf("By default using: 100000000 and 500000\n\n");
        n_max = 100000000;
        nth = 500000;
    } else {
        n_max = atoi(argv[1]); // Count from 1 to n_max
        nth = atoi(argv[2]);   // show nth alphabet
    }

    printf("n_max = %d, nth = %d\n\n", n_max, nth); // print input parameter
    
    for (i = 0 ; i < 26 ; i++) // initialize counter to zero
        count_alph[i] = 0;

    for (n = 1 ; n <= n_max ; n++) { // traverse 1 to n_max to count alphabet
         if ( !count_million(n) )
            printf("ERROR million!\n");

        if ( !count_thousand( n % 1000000 ) ) //1,000,000
            printf("ERROR thousand!\n");
        
        if ( !count_0_999( n % 1000 ) )
            printf("ERROR hundred!\n");
       
    }
    
    for (i = 0 ; i < 26 ; i++) {// print alphabet counter
        DBG_PRINT(("%c: %d\n", 'a'+i, count_alph[i]));
    }
    
    sum = 0;
    found = 0;
    alpha = -1;
    printf("Alphabet  Counted Numbers  Cumulated Numbers\n");
    for (i = 0 ; i < 26 ; i++) {// print alphabet counter
        sum += count_alph[i];
        printf("   %c:   %11llu,   %12llu\n", 'a'+i, count_alph[i], sum);
        if (!found && sum >= nth) {
            found = 1;
            alpha = i;
        }
    }
    
    if (found) {
        printf("\n%d-th alphabet is %c\n\n", nth, 'a'+alpha);
    } else {
        printf("\n%d-th alphabet not exists\n\n", nth);
    }
    return 0;
}
