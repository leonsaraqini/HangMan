#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void drawHangMan(int missedCharactersCount){
    printf("\n");
    for(int i = 0; i < 8; i++){
        printf("-");
    }
    printf("\n");
    printf("|");

    if (missedCharactersCount >= 1) printf("      |");

    printf("\n");
    printf("|");

    if (missedCharactersCount >= 2) printf("      0");

    printf("\n");
    printf("|");

    if (missedCharactersCount >= 3) printf("     -");
    if (missedCharactersCount >= 4) printf("|");
    if(missedCharactersCount >= 5)printf("-");

    printf("\n");
    printf("|");

    if (missedCharactersCount >= 6) printf("     /");
    if (missedCharactersCount >= 7) printf(" \\");

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("-");
    }
}

char * getRandomWord(){
    time_t t1;
    srand((unsigned ) time(&t1));
    int i = rand() % 10;

    char *  words[] = {
        "cow", "bird", "Computer", "laptop", "blue", "red", "phone", "leaf", "car", "soup"
    };

    return words[i];
}

void wonMessage(char *word){
    printf("\n-------------------------------------\n");
    printf("   You WON Congratulation!!! :))) \n   The word you guessed was: %s", word);
    printf("\n-------------------------------------\n");
    exit(0);
}

void lostMessage(char *word){
    printf("\n--------------------------------------\n");
    printf("     Unfortunately you lost :/\n The word you didn't guess was: %s", word);
    printf("\n--------------------------------------\n");
    exit(0);
}

void welcomeMessage(){
    char c;

    printf("-------------------------------\n");
    printf("     Welcome to HangMan!!!\n");
    printf("-------------------------------\n\n");
    printf("Are you ready to play? (y/n) :");
    scanf("%c", &c);

    while (1){
        if(c != 'y' && c != 'n'){
            printf("\nPlease entered the one of the options (y/n): ");
            scanf("%c", &c);
        }

        if(c == 'n'){
            printf("\nHave a nice day :)\n");
            exit(0);
        }

        if(c == 'y'){
            break;
        }
    }


}

int setGuessWord(char *word, char *dottedWord, char characterGuessed){

    if(strchr(word, tolower(characterGuessed)) != NULL
    && strchr(dottedWord, tolower(characterGuessed)) == NULL){
        for(int i = 0; i < strlen(dottedWord); i++){
            if(word[i] == tolower(characterGuessed))
                dottedWord[i] = word[i];
        }

        return 0;
    }

    return 1;
}

void mainPartOfGame(){
    char *word = getRandomWord();
    int n = 0;
    char c;

    char dottedWord[10];

    for(int i = 0; i < strlen(word); i++){
        dottedWord[i] = '-';
    }

    dottedWord[strlen(word)] = '\0';


    while(1){

        if(strcmp(word, dottedWord) == 0) wonMessage(word);

        drawHangMan(n);

        if(n == 7) lostMessage(word);

        printf("\nGuess word: %s\n", dottedWord);
        printf("Enter a character: ");

        fflush(stdin);
        scanf("%c", &c);

        n += setGuessWord(word, dottedWord, c);
    }

}

int main() {
    welcomeMessage();
    mainPartOfGame();

    return 0;
}
