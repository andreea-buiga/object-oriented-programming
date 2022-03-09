/*
           .•° ✿ °•.

     created on 22-feb-2021

        @author: andreea

           °•. ✿ .•°
*/

/*
 1. a. Generate all the prime numbers smaller than a given natural number n.
    b. Given a vector of numbers, find the longest increasing contiguous subsequence,
    such the sum of that any 2 consecutive elements is a prime number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_menu() {
    printf("\n___________________________________________\n");
    printf("|                 m e n u                 |\n");
    printf("-------------------------------------------\n");
    printf("| 1 | generate all prime numbers smaller  |\n"
           "|     than a given natural number n.      |\n");
    printf("-------------------------------------------\n");
    printf("| 2 | read a vector.                      |\n");
    printf("-------------------------------------------\n");
    printf("| 3 | given a vector of numbers, find the |\n"
           "|     longest increasing contiguous       |\n"
           "|     subsequence, such the sum of that   |\n"
           "|     any 2 consecutive elements is a     |\n"
           "|     prime number.                       |\n");
    printf("-------------------------------------------\n");
    printf("| 4 | exit the app.                       |\n");
    printf("-------------------------------------------\n");
    printf("| 5 | 13 b.                               |\n");
    printf("-------------------------------------------\n");
}

int is_prime(int x) {
    /*
     * • verifies if a number is prime or not
     * • int x - the number we test
     * • returns 1 if it is prime, 0 otherwise
     *
     * • in order to see if it prime or not, we try to see if we find
     * divisor between 2 and x/2
     * • if we do not find any and x >= 2, then thw number would be prime
     */
    int div;
    bool prime = true;
    for(div = 2; div <= x/2; div++)
        if(x % div == 0)
            prime = false;
    if(x >= 2 && prime == true)
        return 1;
    else
        return 0;
}

void print_all_prime_numbers_smaller_than_n(int n) {
    /*
     * • displaying all prime numbers smaller than n
     * • int n - our upper limit
     *
     * • calling the is_prime function, we test every number from 2 to n
     */
    if(n <= 2)
        printf("there are no prime numbers smaller than n!");
    else {
        int i;
        printf("\nthe prime numbers smaller than %d are: \n", n);
        for(i = 2; i < n; i++)
            if(is_prime(i))
                printf("%d ", i);
    }

}

/*
 * b. Given a vector of numbers, find the longest contiguous subsequence such
 * that any consecutive elements contain the same digits.
 */

int longest_sequence_digits_left(const int *pointer, int length) {
    /*
     * • int *pointer - pointer pointing to the given vector
     * • int length - the length of the vector
     *
     * • test if two consecutive numbers have same frequency sum -> increase the current length sequence
     * • if we find two numbers that do not obey this property, we compare to maximum and set the
     * left and right bounds
     * • we have an if outside of the for loop in case the whole list would have the given property
     * or the subsequence is at the end of the vector
     */
    int i, length_max = -1, length_current = 1, left = 0, right = 0, freq1[10], freq2[10], j;
    int nr1, nr2;
    for(i = 1; i < length; i++){
        for(j = 0; j < 10; j++) {
            freq1[j] = 0;
            freq2[j] = 0;
        }

        nr1 = *(pointer + i);
        nr2 = *(pointer + i - 1);

        while(nr1 != 0) {
            freq1[nr1 % 10] = 1;
            nr1 = nr1 / 10;
        }

        while(nr2 != 0) {
            freq2[nr2 % 10] = 1;
            nr2 = nr2 / 10;
        }

        int ok = 1;

        for(j = 0; j < 10; j++)
            if(freq1[j] != freq2[j])
                ok = 0;

        if(ok == 1)
            length_current++;
        else {
            if(length_current > length_max) {
                length_max = length_current;
                left = i - length_current;
                right = i - 1;
            }
            length_current = 1;
        }
    }


    if(length_current > length_max) {
        length_max = length_current;
        left = length - length_current;
        right = length - 1;
    }

    if(length_max >= 2)
        return left;
    else
        return -1;
}

int longest_sequence_digits_right(const int *pointer, int length) {
    /*
     * • int *pointer - pointer pointing to the given vector
     * • int length - the length of the vector
     *
     * • test if two consecutive numbers have same frequency sum -> increase the current length sequence
     * • if we find two numbers that do not obey this property, we compare to maximum and set the
     * left and right bounds
     * • we have an if outside of the for loop in case the whole list would have the given property
     * or the subsequence is at the end of the vector
     */
    int i, length_max = -1, length_current = 1, left = 0, right = 0, freq1[10], freq2[10], j;
    int nr1, nr2;
    for(i = 1; i < length; i++){
        for(j = 0; j < 10; j++) {
            freq1[j] = 0;
            freq2[j] = 0;
        }

        nr1 = *(pointer + i);
        nr2 = *(pointer + i - 1);

        while(nr1 != 0) {
            freq1[nr1 % 10] = 1;
            nr1 = nr1 / 10;
        }

        while(nr2 != 0) {
            freq2[nr2 % 10] = 1;
            nr2 = nr2 / 10;
        }

        int ok = 1;

        for(j = 0; j < 10; j++)
            if(freq1[j] != freq2[j])
                ok = 0;

        if(ok == 1)
            length_current++;
        else {
            if(length_current > length_max) {
                length_max = length_current;
                left = i - length_current;
                right = i - 1;
            }
            length_current = 1;
        }
    }


    if(length_current > length_max) {
        length_max = length_current;
        left = length - length_current;
        right = length - 1;
    }

    if(length_max >= 2)
        return right;
    else
        return -1;
}

int read_vector(int **vector) {
    /*
     * • passing pointer to pointer to vector and return length of vector
     */
    int i, length;
    printf("\ngive the length of the vector\nlength = ");
    scanf("%d", &length);
    *vector = (int *)malloc(length * sizeof(int));
    for(i = 0; i < length; i++)
        scanf("%d", &(*vector)[i]);
    return length;
}

void print_vector(const int *pointer, int length) {
    /*
     * • printing the dynamically allocated vector
     */
    int i;
    for(i = 0; i < length; i++)
        printf("%d  ", *(pointer + i));
}

int longest_sequence_left(const int *pointer, int length) {
    /*
     * • determining the longest increasing contiguous subsequence
     * such the sum of that any 2 consecutive elements is a prime number
     * • int *pointer - pointer pointing to the given vector
     * • int length - the length of the vector
     *
     * • test if two consecutive numbers have a prime sum -> increase the current length sequence
     * • if we find two numbers that do not obey this property, we compare to maximum and set the
     * left and right bounds
     * • we have an if outside of the for loop in case the whole list would have the given property
     * or the subsequence is at the end of the vector
     */
    int i, length_max = -1, length_current = 1, left = 0, right = 0;
    for(i = 1; i < length; i++)
        if(is_prime(*(pointer + i) + *(pointer + i - 1)) && *(pointer + i) >= *(pointer + i - 1))
            length_current++;
        else {
            if(length_current > length_max) {
                length_max = length_current;
                left = i - length_current;
                right = i - 1;
            }
            length_current = 1;
        }

    if(length_current > length_max) {
        length_max = length_current;
        left = length - length_current;
        right = length - 1;
    }

    if(length_max >= 2)
        return left;
    else
        return -1;
}

int longest_sequence_right(const int *pointer, int length) {
    /*
     * • determining the longest increasing contiguous subsequence
     * such the sum of that any 2 consecutive elements is a prime number
     * • int *pointer - pointer pointing to the given vector
     * • int length - the length of the vector
     *
     * • test if two consecutive numbers have a prime sum -> increase the current length sequence
     * • if we find two numbers that do not obey this property, we compare to maximum and set the
     * left and right bounds
     * • we have an if outside of the for loop in case the whole list would have the given property
     * or the subsequence is at the end of the vector
     */
    int i, length_max = -1, length_current = 1, left = 0, right = 0;
    for(i = 1; i < length; i++)
        if(is_prime(*(pointer + i) + *(pointer + i - 1)) && *(pointer + i) >= *(pointer + i - 1))
            length_current++;
        else {
            if(length_current > length_max) {
                length_max = length_current;
                left = i - length_current;
                right = i - 1;
            }
            length_current = 1;
        }

    if(length_current > length_max) {
        length_max = length_current;
        left = length - length_current;
        right = length - 1;
    }

    if(length_max >= 2)
        return right;
    else
        return -1;
}

void ui() {
    /*
     * • ui functions that takes care of the menu app appearance
     */
    int *vector, length;
    bool are_we_done_yet = false;
    int left, right, j;

    while(are_we_done_yet == false) {
        int command = 0;
        printf("\nyour wish is my command: ");
        scanf("%d", &command);
        printf("\n");

        if(command == 1) {
            int n;
            printf("\ngive an n\nn = ");
            scanf("%d", &n);
            print_all_prime_numbers_smaller_than_n(n);
            printf("\n");
        }
        else
            if(command == 2) {
                length = read_vector(&vector);
                printf("the read vector is:\n");
                print_vector(vector, length);
            }
            else
                if(command == 3) {
                    left = longest_sequence_left(vector, length);
                    right = longest_sequence_right(vector, length);
                    if(right == -1 || left == -1)
                        printf("• there is no such subsequence.\n");
                    else {
                        printf("the longest sequence with the given property is:\n");
                        for (j = left; j <= right; j++)
                            printf("%d ", *(vector + j));
                    }
                }
                else
                    if(command == 4)
                        are_we_done_yet = true;
                    else
                        if(command == 5) {
                            left = longest_sequence_digits_left(vector, length);
                            right = longest_sequence_digits_right(vector, length);
                            if(right == -1 || left == -1)
                                printf("• there is no such subsequence.\n");
                            else {
                                printf("the longest sequence with the given property is:\n");
                                for (j = left; j <= right; j++)
                                    printf("%d ", *(vector + j));
                            }
                        }
                        else
                            printf("bad command!\n");
    }
}

int main() {
    print_menu();
    ui();

    return 0;
}