#include <stdio.h>

typedef struct alx {
    int scores;
    int age;
} alxstudent;

int main() {
    alxstudent habie = {185, 21};
    printf("Scores of habie: %d\n", habie.scores);
    printf("Age of habie: %d\n", habie.age);

    return (0);
}