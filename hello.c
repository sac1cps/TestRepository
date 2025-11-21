#include <stdio.h>
#include <string.h>

static void trim_newline(char *buffer) {
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

int main(int argc, char *argv[]) {
    char name[100] = {0};
    char input[32];
    int year = 0;
    const char *animals[12] = {
        "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
        "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"
    };
    const char *fortunes[12] = {
        "Lean into curiosity; small risks pay off today.",
        "Patience and persistence will open an unexpected door.",
        "Trust your instincts—the bold move is the right one.",
        "Listen closely to others; collaboration fuels success.",
        "Your ideas carry weight now, so share them confidently.",
        "Quiet focus reveals a solution you have overlooked.",
        "Momentum is on your side—finish what you started.",
        "Generosity attracts allies; offer help freely.",
        "Adapt quickly and you will gain a surprise advantage.",
        "Organization brings clarity; tidy the details.",
        "Stand by your values and people will rally to you.",
        "Celebrate progress, but keep the long view in mind."
    };

    if (argc > 1) {
        strncpy(name, argv[1], sizeof(name) - 1);
    } else {
        printf("Enter your name: ");
        if (fgets(name, sizeof(name), stdin) == NULL) {
            printf("No name provided. Goodbye!\n");
            return 1;
        }
        trim_newline(name);
    }

    while (year == 0) {
        printf("Enter your birth year: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Could not read birth year. Goodbye!\n");
            return 1;
        }
        if (sscanf(input, "%d", &year) != 1 || year <= 0) {
            printf("Please enter a valid positive year.\n");
            year = 0;
        }
    }

    int index = (year - 1900) % 12;
    if (index < 0) {
        index += 12;
    }

    printf("\nHello %s!\n", name[0] ? name : "friend");
    printf("You were born in %d, which makes you a %s in the Chinese zodiac.\n",
           year, animals[index]);
    printf("Today's fortune: %s\n", fortunes[index]);

    return 0;
}
