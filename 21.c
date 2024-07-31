#include <stdio.h>
#include <stdbool.h>

void askQuestion(const char *question, bool *answer) {
    char response;
    printf("%s (y/n): ", question);
    scanf(" %c", &response);
    *answer = (response == 'y' || response == 'Y');
}

int main() {
    bool answer;
    int questionNumber = 1;

    printf("Welcome to the 21 Questions game!\n");
    printf("Think of something, and I'll try to guess what it is by asking up to 21 yes/no questions.\n");

    while (questionNumber <= 21) {
        switch (questionNumber) {
            case 1:
                askQuestion("Is it something that is alive?", &answer);
                if (answer) {
                    // Follow-up questions if the answer is yes
                    askQuestion("Is it an animal?", &answer);
                    if (answer) {
                        askQuestion("Does it live in the water?", &answer);
                        if (answer) {
                            printf("It sounds like you're thinking of a fish!\n");
                            break;
                        } else {
                            askQuestion("Is it a common pet?", &answer);
                            if (answer) {
                                printf("It sounds like you're thinking of a dog!\n");
                                break;
                            } else {
                                printf("It sounds like you're thinking of a wild animal!\n");
                                break;
                            }
                        }
                    } else {
                        printf("It sounds like you're thinking of a plant or something else living!\n");
                        break;
                    }
                } else {
                    // Follow-up questions if the answer is no
                    askQuestion("Is it something that can be found indoors?", &answer);
                    if (answer) {
                        printf("It sounds like you're thinking of an appliance or piece of furniture!\n");
                        break;
                    } else {
                        printf("It sounds like you're thinking of something found outdoors!\n");
                        break;
                    }
                }
                break;

            // Add more cases for additional questions if needed
            // ...

            default:
                printf("I couldn't guess what you're thinking of. Maybe you can give me more hints next time.\n");
                break;
        }

        questionNumber++;
    }

    if (questionNumber > 21) {
        printf("I reached the maximum number of questions. I couldn't guess what you're thinking of.\n");
    }

    return 0;
}
