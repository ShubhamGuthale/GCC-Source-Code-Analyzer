
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_KEYWORDS 32

const char *keywords[MAX_KEYWORDS] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

int keywordCount = 0;
int specialSymbolCount = 0;

void Key_Symbols(FILE *file)
   {
    int c;
    char word[50] = {0};

    while ((c = fgetc(file)) != EOF)
     {
        if (isalnum(c) || c == '_') 
        {
            strncat(word, (char *)&c, 1);
        }
         else 
        {
            if (strlen(word) > 0)
             {
                // Check if the word is a keyword
                for (int i = 0; i < MAX_KEYWORDS; ++i) 
                {
                    if (strcmp(word, keywords[i]) == 0)
                     {
                        keywordCount++;
                        break;
                     }
                }
                word[0] = '\0';
             }


            // Check if the character is a special symbol or not.
            if (!isalnum(c) && c != '_') 
            {
                specialSymbolCount++;
            }
        }
    }

    // Check the last word in the file
    if (strlen(word) > 0) {
        for (int i = 0; i < MAX_KEYWORDS; ++i) {
            if (strcmp(word, keywords[i]) == 0) {
                keywordCount++;
                break;
            }
        }
    }
}

void createReadme(char *filename, int keywordCount, int specialSymbolCount) {
    FILE *readme = fopen("README.md", "a");
    if (readme == NULL)
     {
        perror("Error opening README.md");
        exit(EXIT_FAILURE);
     }

    fprintf(readme, "## Analysis Results for %s\n", filename);
    fprintf(readme, "- Number of Keywords: %d\n", keywordCount);
    fprintf(readme, "- Number of Special Symbols: %d\n\n", specialSymbolCount);

    fclose(readme);
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: %s <directory1> <directory2> ... <directoryN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *readme = fopen("README.md", "w");
    if (readme == NULL) 
    {
        perror("Error creating README.md");
        return EXIT_FAILURE;
    }

    fclose(readme);

    for (int i = 1; i < argc; i++) 
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) 
        {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        Key_Symbols(file);
        createReadme(argv[i], keywordCount, specialSymbolCount);

        // Reset counts for the next file
        keywordCount = 0;
        specialSymbolCount = 0;

        fclose(file);
    }

    printf("Analysis completed. Results written to README.md.\n");

    return EXIT_SUCCESS;
}
