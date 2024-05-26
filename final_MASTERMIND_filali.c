#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
/*PROJET realisee par ZAYNEB LAMRAIKI et MALAK BENAICHA*/

//fonction pour affficher le code 
void displayCode(int code[5]) {
    printf("The secret code was: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", code[i]);
    }
    printf("\n");
}

 // fonction pour compter les well and misplaced digits
void placements(int code[5], int guess[5], int *wellPlaced, int *misplaced) { // structure 
    *wellPlaced = 0;
    *misplaced = 0;
    int codeCount[10] = {0};
    int guessCount[10] = {0};

    for (int i = 0; i < 5; ++i) {
        if (code[i] == guess[i]) {  // conteur de comparaison for each digit
            (*wellPlaced)++;
        } else {
            codeCount[code[i]]++;
            guessCount[guess[i]]++;
        }
    }

    for (int i = 0; i < 10; ++i) {
        *misplaced += (codeCount[i] < guessCount[i]) ? codeCount[i] : guessCount[i];
    }
     // Adjust for repeated digits
}

//monsieur FILALI on a essayee d'utuliser la fonction _getch ou bien getchar mais cela n'a pas fonctionne et a ruiné tout le code 
// on va essayee de la mettre dans la mise a jour 
//MERCI de votre comprehension

int main() {
    char name1[50], name2[50], jokerChoice[5]  ;
    int  code[5], guess[5] ;
    int guesses = 0, wellPlaced, misplaced, joker = 1;

   printf("\033[1;34m");
   printf("\n\n\t\t\t\t-_-_-_-_-_-_- WELCOME to the -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ \n ");
   printf("\t\t\t\t-_-_-_-_-_-_-_-_-_-_ -_-_-***MASTER_MIND ***_-_-_-_-_-_-_-_-_-_-_-_ \n ");
   printf("\t\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- GAME_-_-_-_-_-_ -_-_-_-_-_\n\n ");
   printf("\033[0m");

   printf("\033[1;33m");
   printf("\tdescription :__________________________________________________________________________________________________________________________");
   printf("\n\t In this version of MASTERMIND game , the player1 will creat a secret code of 5 digits that you the player 2 must guess it ! ");
   printf("\n\t  the game includs 2 level ,the beginner where the 5 are 'distincts' and the expert where the digits could be 'repeated'! ");
   printf("\n\t                   you have 20 guesses at max if you passed it without figured it out you will lose ! ");
   printf("\n\t              you also have an option if JOKER from the 10th guesse ,that will releave one digit you choose ,");
   printf("\n\t                        but keep in mind if you accept this option you will lose 3 attemps .\n");
   printf("\t_______________________________________________________________________________________________________________________________________");
   printf("\n\t\t\t\t\t ******CAN YOU GUESS THE CODE !!******\n");
   printf("\033[0m");

    printf("Choose the level:\n1- Level 1 (Beginner) \n2- Level 2 (Expert) \nEnter your choice: ");
    int level;
    scanf("%d", &level);

    printf("\n\tPlayer 1, enter your name: ");
    scanf("%s", name1);

// entering the code
    
    if (level == 1) {
        printf("Enter your 5 distinct digit secret code (without spaces): ");
        for (int i = 0; i < 5; ++i) {
            scanf("%1d", &code[i]);
            getch();
            system("cls");
        }
    } else if (level == 2) {
        printf("Enter your 5-digit secret code (digits can be repeated, without spaces): ");
        for (int i = 0; i < 5; ++i) {
            scanf("%1d", &code[i]);
            getch();
            system("cls");
        }
    } else {
        printf("Invalid choice. please choose 1 or 2 .\n");
        return 0;
    }

    srand(time(NULL));

    printf("\n\tPlayer 2 , enter your name: ");
    scanf("%s", &name2);

    printf("\n\n \033[0;37m Dear %s , %s has already picked a code of 5 digits . \n",name2 ,name1);
    printf("\t\t\t\033[0;36m CAN YOU GUESS IT ?\n\n");
     

    while (guesses < 20) {
        printf("\t\033[0;37mTake a guess : ");
        for (int i = 0; i < 5; ++i) {
            scanf("%1d", &guess[i]); // read the five digits
        }

        guesses++; // conteur de tentatives 

        // call the fonction placements
        placements(code, guess, &wellPlaced, &misplaced); // structure 

        if (wellPlaced == 5) {
            printf("\033[0;33m");
            printf("\n\t\t\t_-_-_--_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-\n");
            printf("\t\t\t||'           CONGRATULATIONS %s! YOU WON AFTER %d GUESSES.                    ||'\n", name2, guesses);
            printf("\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-\n");
            printf("\033[0m");
            break;
        }

        printf("\033[0;32m");
        printf("\n\t_-_-_Well placed digits: %d_-_-_\n", wellPlaced);
        printf("\033[0;31m");
        printf("\t_-_-_Misplaced digits: %d_-_-_\n", misplaced);
        printf("\033[0m");

       // boocle pour le joker
        if (guesses >= 10 && joker) {    
            do {
                printf("\033[0;35m");
                printf("\n\t*****************************************************");
                printf("\n\t%s, do you want to use the JOKER? (yes/no): ", name2);
                printf("\n\t*****************************************************");
                printf("\033[0m");
                scanf("%s", jokerChoice);
             
                if (strcmp(jokerChoice, "yes") == 0) {
                    int digit;
                    printf("\tEnter the position (1-5) to reveal: ");
                    scanf("%d", &digit);
                    printf("\tThe digit at position %d is %d\n", digit, code[digit - 1]); // digit - 1 CAUSE WESTAART WITH 0
                    guesses -= 3;
                    joker = 0;
                    break;
                } else if (strcmp(jokerChoice, "no") == 0) {
                    break;
                } else {
                    printf("Invalid choice. Please enter 'yes' or 'no'.\n");
                }
            } while (1);
        }
    }

    if (guesses >= 20) {  
        printf("\n\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"); 
        printf("\n\t\033[1;31m %s, you lose. The code was: ", name2);
        displayCode(code);
        printf("\n\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
    }

    FILE *file = fopen("scores.txt", "a");   //stockage dans un fichier
    if (file != NULL) {
        fprintf(file, "%s - %d guesses\n", name2, guesses);
        fclose(file);
    }
    printf("\n\t\t\t\t\t\t\t\t\t realised by : ");
    printf("\n\t\t\t\t\t\t\t\t\t\t \033[1;35m Zayneb LAMRAIKI ");
    printf("\n\t\t\t\t\t\t\t\t\t\t \033[1;35mMalak BENAICHA  ");
    return 0;
}
