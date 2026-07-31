#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int count = 0;

bool stringmatching(char *text, char *pattern, int n, int m)
{
    count = 0;
    for (int i = 0; i <= (n - m); i++)
    {
        int j = 0;
        while (j < m)
        {
            count++;
            if (pattern[j] != text[i + j])
                break;
            j++;
        }
        if (j == m)
            return true;
    }
    return false;
}

void tester()
{
    char text[1000], pattern[1000];

    printf("\n--- BRUTE FORCE STRING MATCHING TESTER ---\n");
    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n)
    {
        printf("Pattern length cannot be greater than text length!\n");
        return;
    }

    bool found = stringmatching(text, pattern, n, m);

    if (found)
    {
        printf("\nPattern found in the text!\n");
    }
    else
    {
        printf("\nPattern not found in the text!\n");
    }

    printf("Number of character comparisons = %d\n", count);
}

void plotter()
{
    FILE *f1 = fopen("strbest.txt", "w");
    FILE *f2 = fopen("strworst.txt", "w");
    FILE *f3 = fopen("stravg.txt", "w");

    char *text = (char *)malloc(1000 * sizeof(char));
    char *pattern;

    for (int i = 0; i < 1000; i++)
        *(text + i) = 'a';

    int m, n;
    n = 1000;
    m = 10;
    
    while (m <= 1000)
    {
        pattern = (char *)malloc(m * sizeof(char));
        
        count = 0;
        for (int i = 0; i < m; i++)
            pattern[i] = 'a';
        stringmatching(text, pattern, n, m);
        fprintf(f1, "%d\t%d\n", m, count);

        count = 0;
        pattern[m - 1] = 'b'; 
        stringmatching(text, pattern, n, m);
        fprintf(f2, "%d\t%d\n", m, count);

        count = 0;
        for (int i = 0; i < m; i++) 
            pattern[i] = 97 + rand() % 3;
        stringmatching(text, pattern, n, m);
        fprintf(f3, "%d\t%d\n", m, count);
        free(pattern);
        if (m < 100)
            m = m + 10;
        else
            m = m + 100;
    }
    free(text);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("Data files generated successfully!\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Tester\n2. Plotter\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        if (choice == 1)
            tester();
        else if (choice == 2)
            plotter();
        else
            printf("Invalid choice!\n");
    }
    return 0;
}