#include <stdio.h>
#include <string.h>

//The function that allow to define letters
int isltr(char letter) {
    if ((('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z')))
        return 1;
    return 0;
}

//The function that allow to define digits
int isdgt(char digit) {
    if ('0' <= digit && digit <= '9')
        return 1;
    return 0;
}

//The function that allow to define keywords
int iskw(char *word) {
    char kws[35][9] = {
            "False\n", "None\n", "True\n", "and\n", "as\n",
            "assert\n", "async\n", "await\n","break\n", "class\n",
            "continue\n", "def\n", "del\n", "elif\n", "else\n",
            "except\n","finally\n", "for\n", "from\n", "global\n",
            "if\n", "import\n", "in\n", "is\n", "lambda\n",
            "nonlocal\n", "not\n", "or\n", "pass\n", "raise\n",
            "return\n", "try\n", "while\n", "with\n", "yield\n"};

    for (int i = 0; i < 35; i++)
        if (strcmp(word, kws[i]) == 0)
            return 1;
    return 0;
}

int main() {
    char name[80] = "";
    fgets(name, 80, stdin);
    int len = strlen(name) - 2;
    if ((!(isltr(name[0])) && name[0] != '_') || iskw(name)) {
        puts("It's not a name in Python");
        return 0;
    }
    else {
        for (int i = 0; i <= len; i++)
            if (!(isltr(name[i]) || isdgt(name[i]) || name[i] == '_')) {
                puts("It's not a name in Python");
                return 0;
            }
    }
    puts("It seems as it's a name in Python");
    return 0;
}
