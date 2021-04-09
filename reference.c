#include<stdio.h>

// parameter passing: value, reference, pointer

// name, age, pay passed by pointers
void load(char *myName, int *myAge, float *pay){
    printf("\nEnter a name: ");
    // this argument in gets() doesn't need the * coz it only allows char* type.
    gets(myName);

    //if i used scanf(), I do need to put the *. But myName cannot have a space.
    //scanf("%s", &*myName);

    printf("\nEnter an age: ");
    scanf("%d", &*myAge);

    printf("\nEnter a pay: ");
    scanf("%f", &*pay);
    getchar();
}

// age and pay passed by reference
void loadRef(char *name, int &age, float &pay){
    printf("\nEnter a name: ");
    gets(name);

    printf("\nEnter an age: ");
    scanf("%d", &age);

    printf("\nEnter a pay: ");
    scanf("%f", &pay);

    fflush(stdin);
    
}

// age and pay passed by value
void print(char *name, int age, float pay){
    printf("\nMY DATA: %s %d %.2f", name, age, pay);
}

float calcSomething(int age, float pay){
    if (age > 20)
        return pay * 10;
    return pay * 2;
}

int main(){
    char name[20];
    int age;
    float pay;
    float something; 

    // all using pointers. name is string, special case.
    load(name, &age, &pay);
    print(name, age, pay);
    something = calcSomething(age, pay);
    printf("\n\nSOMETHING: %.2f", something);

    // name is using pointer. age and pay using reference.
    loadRef(name, age, pay);
    print(name, age, pay);
    something = calcSomething(age, pay);
    printf("\n\nSOMETHING: %.2f", something);

    printf("\nSOMETHING ALTERNATIVE: %.2f", calcSomething(age,pay));

    return 0;
}

// Good Luck in your Programming journey!
