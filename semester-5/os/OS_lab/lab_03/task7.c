// i have taken  a lot of help from AI in this couldnot figure out how to do it
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define FILE_NAME "task8.txt"

char  id[MAX_BOOKS][20];
char  title[MAX_BOOKS][50];
char  author[MAX_BOOKS][50];
char  category[MAX_BOOKS][30];
int   edition[MAX_BOOKS];
float price[MAX_BOOKS];
int   count = 0;

void clearBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void loadBooks(void) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        perror("Warning: could not open " FILE_NAME);
        return;
    }
    while (count < MAX_BOOKS &&
           fscanf(fp, "%19s %49s %49s %29s %d %f",
                  id[count], title[count], author[count],
                  category[count], &edition[count], &price[count]) == 6) {
        count++;
    }
    fclose(fp);
}

void printHeader(void) {
    printf("%-10s %-20s %-15s %-12s %-8s %s\n",
           "ID", "Title", "Author", "Category", "Edition", "Price");
}

void printBook(int i) {
    printf("%-10s %-20s %-15s %-12s %-8d %.2f\n",
           id[i], title[i], author[i], category[i], edition[i], price[i]);
}

int findById(const char *key) {
    for (int i = 0; i < count; i++) {
        if (strcmp(id[i], key) == 0) return i;
    }
    return -1;
}

void addRecord(void) {
    if (count >= MAX_BOOKS) {
        fprintf(stderr, "Error: library is full (max %d books)\n", MAX_BOOKS);
        return;
    }

    char newId[20];
    printf("Enter ID (e.g. Book11): ");
    if (scanf("%19s", newId) != 1) { clearBuffer(); return; }
    if (findById(newId) != -1) {
        fprintf(stderr, "Error: a book with ID %s already exists\n", newId);
        return;
    }

    int ed;
    float pr;
    char t[50], a[50], c[30];

    printf("Enter Title (no spaces): ");
    scanf("%49s", t);
    printf("Enter Author (no spaces): ");
    scanf("%49s", a);
    printf("Enter Category (no spaces): ");
    scanf("%29s", c);

    printf("Enter Edition: ");
    if (scanf("%d", &ed) != 1 || ed < 1) {
        fprintf(stderr, "Error: invalid edition\n");
        clearBuffer();
        return;
    }
    printf("Enter Price: ");
    if (scanf("%f", &pr) != 1 || pr < 0) {
        fprintf(stderr, "Error: invalid price\n");
        clearBuffer();
        return;
    }

    strcpy(id[count], newId);
    strcpy(title[count], t);
    strcpy(author[count], a);
    strcpy(category[count], c);
    edition[count] = ed;
    price[count] = pr;
    count++;

    printf("Record added.\n");
}

void searchRecord(void) {
    char key[20];
    printf("Enter ID to search: ");
    if (scanf("%19s", key) != 1) { clearBuffer(); return; }

    int idx = findById(key);
    if (idx == -1) {
        printf("No book found with ID %s.\n", key);
    } else {
        printHeader();
        printBook(idx);
    }
}

void showAll(void) {
    if (count == 0) {
        printf("No records.\n");
        return;
    }
    printHeader();
    for (int i = 0; i < count; i++) printBook(i);
}

void showAbovePrice(void) {
    float limit;
    printf("Enter price limit (e.g. 1000): ");
    if (scanf("%f", &limit) != 1) {
        fprintf(stderr, "Error: invalid price\n");
        clearBuffer();
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (price[i] > limit) {
            if (!found) printHeader();
            printBook(i);
            found = 1;
        }
    }
    if (!found) printf("No books with price greater than %.2f.\n", limit);
}

int saveBooks(void) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        perror("Error saving file");
        return 0;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s %s %s %d %.2f\n",
                id[i], title[i], author[i], category[i], edition[i], price[i]);
    }
    fclose(fp);
    return 1;
}

int main(void) {
    int choice;
    loadBooks();

    do {
        printf("\n==================== MENU ====================\n");
        printf("1. Add a record\n");
        printf("2. Search a record by ID\n");
        printf("3. Show all records\n");
        printf("4. Show books with price greater than a given limit (1000)\n");
        printf("5. Save and exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            choice = 0;
        }

        switch (choice) {
            case 1: addRecord();      break;
            case 2: searchRecord();   break;
            case 3: showAll();        break;
            case 4: showAbovePrice(); break;
            case 5:
                if (saveBooks()) printf("Saved. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, enter 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}
