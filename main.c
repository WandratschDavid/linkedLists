//***********************************************************************
//
//                  H T L - W E L S   /   Klasse 3BHIT
//
//-----------------------------------------------------------------------
// Programm         : Liste
//
// Ersteller        : David Wandratsch
//
// Erstelldatum     : 2021-05-06
//
// Abgabedatum      : 2021-05-18
//
// Kurzbeschreibung : Arbeiten mit einfach - verketteten Listen
//
// GitHub Repository: https://github.com/WandratschDavid/linkedLists
//***********************************************************************

// Including libraries
#include <stdio.h>
#include <stdbool.h>
#include <mm_malloc.h>

// creating the data struct
struct data{
    int value;
    struct data *next;
};

// declaration of global variables
struct data *head;
struct data *tail;
struct data *cursor;
bool isInit = false;

// predefining functions
void init();
int first();
int last();
int next();
void insert(int value);
void delete();
void find(int value);
void print();

// main program
int main()
{
    printf("\nFirst: %d\n", first());
    print();

    printf("\nNext: %d\n", next());
    print();

    printf("\nInsert: 12\n");
    insert(12);
    print();

    printf("\nInsert: 13\n");
    insert(13);
    print();

    printf("\nInit\n");
    init();
    print();

    printf("\nInsert: 1\n");
    insert(1);
    print();

    printf("\nInsert: 3\n");
    insert(3);
    print();

    printf("\nFirst: %d\n", first());
    print();

    printf("\nInsert: 3\n");
    insert(3);
    print();

    printf("\nNext: %d\n", next());
    print();

    printf("\nNext: %d\n", next());
    print();

    printf("\nInsert: 4\n");
    insert(4);
    print();

    printf("\nNext: %d\n", next());
    print();

    printf("\nInit\n");
    init();
    print();

    printf("\nFind: 12\n");
    find(12);
    print();

    printf("\nFind: 2\n");
    find(2);
    print();

    printf("\nDelete\n");
    delete();
    print();

    printf("\nFirst: %d\n", first());
    print();

    printf("\nDelete\n");
    delete();
    print();

    printf("\nLast: %d\n", last());
    print();
}


//********************************************************************
// Funktion        : init
//
// Kurzbeschreibung: initializes the list
//********************************************************************
void init()
{
    if(head != NULL)
    {
        printf("The list is already initialized!\n");
    }
    else
    {
        head = NULL;

        if (head != NULL)
        {
            head->next = NULL;
        }

        tail = NULL;
        cursor = head;
    }

    isInit = true;
}


//************************************************************************
// Funktion        : first
//
// Kurzbeschreibung: changes the pointer to the first element of the list
//
// Parameter       :
//    R   cursor->value  int  value of the first element in the list
//************************************************************************
int first()
{
    cursor = head;

    if(head == NULL)
    {
        return -1;
    }

    return cursor->value;
}


//***********************************************************************
// Funktion        : last
//
// Kurzbeschreibung: changes the pointer to the last element of the list
//
// Parameter       :
//    R   cursor->value  int  value of the last element in the list
//***********************************************************************
int last()
{
    cursor = tail;

    if(head == NULL)
    {
        return -1;
    }

    return cursor->value;
}


//***********************************************************************
// Funktion        : next
//
// Kurzbeschreibung: changes the pointer to the next element of the list
//
// Parameter       :
//    R   cursor->value  int  value of the next element in the list
//***********************************************************************
int next()
{
    if(head == NULL)
    {
        return -1;
    }

    if(cursor->next != NULL)
    {
        cursor = cursor->next;
    }
    else
        {
            printf("\nThere is no next element in the list -> the cursor stays at last position!\n");
        }

    return cursor->value;
}


//*******************************************************************************************************
// Funktion        : insert
//
// Kurzbeschreibung: inserts a new element with the specified value to the list
//
// Parameter       :
//    1   value        int         hands over the value the function is supposed to insert into the list
//*******************************************************************************************************
void insert(int value)
{
    bool isTail = false;

    if(isInit)
    {
        struct data *new = NULL;
        new = malloc(sizeof(struct data));

        if (tail == cursor)
        {
            isTail = true;
        }

        if (new != NULL)
        {
            if (head == NULL)
            {
                new->next = NULL;
                new->value = value;
                cursor = new;
                head = cursor;
            }
            else if (head->next == NULL && head != NULL)
            {
                new->next = NULL;
                new->value = value;
                cursor = new;
                head->next = cursor;
            }
            else
            {
                new->next = cursor->next;
                new->value = value;
                cursor->next = new;
                cursor = new;
            }

            if(isTail)
            {
                tail = new;
            }
        }
    }
}


//********************************************************************
// Funktion        : delete
//
// Kurzbeschreibung: deletes an element from the list
//********************************************************************
void delete()
{
    struct data *search;
    struct data *cache;
    bool isHead = false;
    bool isTail = false;

    if(isInit)
    {
        search = head;
        do
        {
            if (search->next == cursor)
            {
                if(cursor == tail)
                {
                    tail = search;
                    isTail = true;
                }

                search->next = cursor->next;
                break;
            }
            else if(cursor == head)
            {
                isHead = true;
                break;
            }
            else
            {
                search = search->next;
            }
        }
        while (search->next != cursor->next);

        cache = cursor;

        if(isHead)
        {
            cursor = cursor->next;
            head = cursor;
        }
        else if(isTail)
        {
            printf("\nThe deleted item was last item in the list -> cursor moved to the beginning of the list!\n");
            cursor = head;
        }
        else
            {
                cursor = cursor->next;
            }

        free(cache);
    }
}


//*********************************************************************************************
// Funktion        : find
//
// Kurzbeschreibung: searches for the provided value in the list
//
// Parameter       :
//    1   value      int     hands over the value the function is supposed to find in the list
//*********************************************************************************************
void find(int value)
{
    struct data *search;

    search = head;

    if(head != NULL)
    {
        do
        {
            if (search->value == value)
            {
                cursor = search;
                break;
            }
            search = search->next;
        }
        while (search->next != NULL);

        if (search->value != value)
        {
            printf("Value not found -> cursor remains at the position!\n");
        }
    }
}


//********************************************************
// Funktion        : print
//
// Kurzbeschreibung: prints all elements of the list
//********************************************************
void print()
{
    struct data *iterator;
    int count;

    count = 0;
    iterator = head;

    if(head != NULL)
    {
        do
        {
            printf("%d : %d\n", count, iterator->value);
            count++;
            iterator = iterator->next;
        }
        while(iterator != NULL);
    }
    else
        {
            printf("List empty or not initialized!\n");
        }
}