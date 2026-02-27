#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Contact
{
    char name[100];
    char ph_number[15];
};

void addContacts()
{

    struct Contact c;
    getchar(); 
    printf("Enter Name: ");
    fgets(c.name, 100, stdin);
    int length = strlen(c.name);
    if (c.name[length - 1] == '\n')
    {
        c.name[length - 1] = '\0';
    }

    printf("Enter 10 digit Mobile Number: ");
    fgets(c.ph_number, 15, stdin);

    int len = strlen(c.ph_number);
    if (c.ph_number[len - 1] == '\n')
    {
        c.ph_number[len - 1] = '\0';
    }

    FILE *ptr;
    ptr = fopen("Contacts.dat", "ab");

    if (ptr == NULL)
    {
        printf("File error\n");
        return;
    }
    fwrite(&c, sizeof(c), 1, ptr);

    fclose(ptr);
    printf("Contact Add Successfully\n");
}

void viewContacts()
{

    struct Contact c;

    FILE *ptr;
    ptr = fopen("Contacts.dat", "rb");
    if (ptr == NULL)
    {
        printf("No Contacts Found\n");
        return;
    }

    int i = 1, found = 0;
    while (fread(&c, sizeof(c), 1, ptr) == 1)
    {
        printf("%d.Name: %s\n", i, c.name);
        printf("  Ph. Number: %s\n", c.ph_number);
        i++;
        found = 1;
    }

    if (found == 0)
    {
        printf("Contacts Not Found\n");
    }

    fclose(ptr);
}

void searchContacts()
{
    struct Contact c;

    char name[100];
    printf("Enter Name for Search Contacts: ");
    getchar();
    fgets(name, 100, stdin);
    int len = strlen(name);
    if (name[len - 1] == '\n')
    {
        name[len - 1] = '\0';
    }

    FILE *ptr;
    ptr = fopen("Contacts.dat", "rb");

    if (ptr == NULL)
    {
        printf("No Contacts Found\n");
        return;
    }

    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = tolower(name[i]);
    }
    int flag = 0;
    while (fread(&c, sizeof(c), 1, ptr) == 1)
    {
        char tempName[100];
        strcpy(tempName, c.name);
        for (int k = 0; tempName[k] != '\0'; k++)
        {
            tempName[k] = tolower(tempName[k]);
        }

        if (strcmp(name, tempName) == 0)
        {
            flag = 1;
            printf("Name: %s\n", c.name);
            printf("Ph Number: %s\n", c.ph_number);
            break;
        }
    }
    if (flag == 0)
    {
        printf("Contact Not Found\n");
    }
    fclose(ptr);
}

void updateContacts()
{
    struct Contact c;
    FILE *ptr;
    ptr = fopen("Contacts.dat", "rb");
    if (ptr == NULL)
    {
        printf("No Contacts Found!\n");
        return;
    }

    int i = 1, j;
    while (fread(&c, sizeof(c), 1, ptr) == 1)
    {
        printf("%d. %s - %s\n", i, c.name, c.ph_number);
        i++;
    }

    fclose(ptr);

    printf("Select Number for Updation: ");
    scanf("%d", &j);

    char update[15];
    printf("Enter new Mobile No: ");
    getchar();
    fgets(update, 15, stdin);

    int check_len = strlen(update);
    if (update[check_len - 1] == '\n')
    {
        update[check_len - 1] = '\0';
    }

    ptr = fopen("Contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (ptr == NULL || temp == NULL)
    {
        printf("Contacts Not Found\n");
        return;
    }

    int counter = 1;
    int found = 0;
    while (fread(&c, sizeof(c), 1, ptr) == 1)
    {
        if (counter == j)
        {
            strcpy(c.ph_number, update);
            found = 1;
            printf("Contact Update Succesfully\n");
        }
        fwrite(&c, sizeof(c), 1, temp); 
        counter++;
    }

    fclose(ptr);
    fclose(temp);

    if (found == 0)
    {
        printf("Invalid Selection\n");
        remove("temp.dat");
    }
    else
    {
        remove("Contacts.dat");
        rename("temp.dat", "Contacts.dat");
    }
}

void deleteContacts()
{
    struct Contact c;
    FILE *ptr;
    ptr = fopen("Contacts.dat", "rb");

    if (ptr == NULL)
    {
        printf("Contacts Not Found\n");
        return;
    }

    int i = 1;
    while (fread(&c, sizeof(c), 1, ptr) == 1)
    {
        printf("%d.Name: %s Ph. Number: %s\n", i, c.name, c.ph_number);
        i++; 
    }

    fclose(ptr);

    ptr = fopen("Contacts.dat", "rb");
    FILE *temp;
    temp = fopen("temp.dat", "wb");

    if (ptr == NULL || temp == NULL)
    {
        printf("Contacts NOt Found\n");
        return;
    }

    int choose, counter = 1, found = 0;
    printf("Select No. that to be deleted: ");
    scanf("%d", &choose);

    while (fread(&c, sizeof(c), 1, ptr) == 1)
    {
        if (counter == choose)
        {
            found = 1; 
        }

        else
        {
            fwrite(&c, sizeof(c), 1, temp);
        }

        counter++;
    }

    fclose(ptr);
    fclose(temp);

    if (found == 0)
    {
        printf("Invalid Selection\n");
        remove("temp.dat");
    }
    else
    {
        printf("Successfully Deleted\n");
        remove("Contacts.dat");
        rename("temp.dat", "Contacts.dat");
    }
}

int main()
{
    int menu;
    do
    {
        printf("\n");
        printf("1.Add Contacts\n");
        printf("2.View Contacts\n");
        printf("3.Search Contacts\n");
        printf("4.Update Contacts\n");
        printf("5.Delete Contacts\n");
        printf("6.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            addContacts();
            break;

        case 2:
            viewContacts();
            break;

        case 3:
            searchContacts();
            break;

        case 4:
            updateContacts();
            break;

        case 5:
            deleteContacts();
            break;

        case 6:
            printf("Exiting...");
            break;
        }

    } while (menu != 6);

    return 0;
}
