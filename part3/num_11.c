#include <stdio.h>
#include <string.h>
#include <malloc.h>

//The function that allow to count chars in string
int cntr(char *str, char chr) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == chr)
            cnt++;
    return cnt;
}

//The function that change uppercase letters to lowercase letters
char *uptolow(char *str, int len) {
    for (int i = 0; i < len; i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
    return str;
}

int main() {
    char players[2][6] = {
            "Petya", "Vasya"};
    
    char seps[] = " \n";
    char seq[80] = "";
    fgets(seq, 80, stdin);
    char *token, **tokens;
    int i = 0, j, len, num, id;
    num = cntr(seq, ' ');
    tokens = (char **) malloc(num * sizeof(char *));
    
    token = strtok(seq, seps);
    while (token != NULL) {
        tokens[i] = uptolow(token, strlen(token));
        token = strtok(NULL, seps);
        i++;
    }

    for (j = 0; j < i - 1; j++) {
        len = strlen(tokens[j]);
        id = j % 2;
        if (tokens[j][len - 1] != tokens[j + 1][0]) {
            printf("Winner: %s", players[id]);
            free(tokens);
            return 0;
        }
    }

    id = j % 2;
    printf("Winner: %s", players[id]);
    free(tokens);
    return 0;
}
