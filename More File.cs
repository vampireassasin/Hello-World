#include "pch.h"
#include <iostream>

void Readfriend() {
FILE*f = fopen("friends.txt", "rb");
while (1) 
{
int len;
char name[256];
int age;

if (fread(&len, sizeof(len), 1,  f) != 1 || fread(name, len, 1, f) !=1 || fread(&age,  sizeof(age), 1, f) !=1)
{
break;
}
name[len] = '\0';
printf("%s, ", name);
printf("%d \n", age);
}
fclose(f);
}

void Addfriend() {
char name[256];
int age;
printf("What is the name of the friend you would like to add?");
scanf("%s",name);
printf("What is the age of the friend you would like to add?");
scanf("%d", &age);
int len = strlen(name);

FILE*f = fopen("friends.txt", "ab");
fwrite(&len, 1, sizeof(len), f);
fwrite(name, 1, len, f);
fwrite(&age, 1, sizeof(age), f);
fclose(f);
}

int main()
{


int num = 0;
printf("1. Show Friends \n 2. Add Friend \n 3. exit \n \n Enter:");
scanf("%d", &num);

if (num == 1) {
Readfriend();
}
if (num == 2) {
Addfriend();
}
}

/*const char*strs = "Amy";
FILE*f = fopen("myfile.txt", "wb");
fwrite(strs, 1, strlen(strs), f);
fclose(f);*/

