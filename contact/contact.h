#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 20
#define MAX_AGE 3
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define MAX_DATA 100


typedef struct PeoInfo
{
    char name[MAX_NAME];
    char age[MAX_AGE];
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];

}PeoInfo;

typedef struct Contact
{
    PeoInfo data[MAX_DATA];
    int count;
}Contact;

void InitContact(Contact* pc);

void addContact(Contact* pc);

void showOne(Contact* pc,int i);

int findWay();

int find(Contact* pcon,char input[MAX_NAME],int way);

void delete(Contact* pc);

void search(Contact* pc);

void modify(Contact* pc);

void showAll(Contact* pc);

void sort(Contact* pc);