#include <stdio.h>
#include <stdlib.h>
struct BOOK
{
    char Author[64];
    char Title[128];
    char Firm[64];
    int year, page;
};
int main(int argc, char* argv[])
{

    int n;
    BOOK *pBook;
    printf("n="); scanf_s("%d", &n);
    pBook = new BOOK[n];
    for (int i = 0; i<n; i++)
    {
        printf("Book N=%d:\n", i + 1);
        printf("Author: ");
        fflush(stdin); gets_s(pBook[i].Author, 63);
        printf("Title: ");
        fflush(stdin); gets_s(pBook[i].Title, 127);
        printf("Firm: ");
        fflush(stdin); gets_s(pBook[i].Firm, 63);
        printf("year: "); scanf_s("%d", &pBook[i].year);
        printf("page: "); scanf_s("%d", &pBook[i].page);
    }
    FILE *pF;
    fopen_s(&pF, "MyBook.txt", "wb");
    fwrite(&n, sizeof(int), 1, pF);
    fwrite(pBook, sizeof(BOOK), n, pF);
    fclose(pF);
    system("pause");
    return 0;
}