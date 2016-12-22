#include <stdio.h>
#include <stdlib.h>

struct BOOK
{
    char Author[64];
    char Title[128];
    char Firm[64];
    int year, page;
};

int main(int argc, char* argv[]) {
    int n;
    BOOK *pBook;
    FILE *pF;
    fopen_s(&pF, "MyBook.txt", "r");
    if (pF == 0)
    {
        printf("Error, file not found");
        return 1;
    }
    fread(&n, sizeof(int), 1, pF);
    pBook = new BOOK[n];
    fread(pBook, sizeof(BOOK), n, pF);
    fclose(pF);
    for (int i = 0; i < n; i++)
        printf("%s. %s. %s, %d. - %d.\n", pBook[i].Author, pBook[i].Title, pBook[i].Firm, pBook[i].year, pBook[i].page);
    system("pause");
    return 0;
}
