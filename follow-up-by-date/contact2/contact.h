#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define VERSION 0.1

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_DESCRIPTION 50
#define EPT 3

enum menu
{
    EXIT=48,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};
typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
    char sex[MAX_SEX];
    char description[MAX_DESCRIPTION];
}PeoInfo;
typedef struct contact
{
    PeoInfo *data;
    int count;
    int capacity;
    
}Con;
void initContact(Con* pc);
void loadContact(Con* pc);
void addContact(Con* pc);
void delContact(Con* pc);
void searchContact(Con* pc);
void modContact(Con* pc);
void showContact(Con* pc);
void sortContact(Con* pc);
void saveContact(Con* pc);
void destroy(Con* pc);