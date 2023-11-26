#include <stdio.h>
#include <malloc.h>

#define ollist struct list

//The description of the attributes of the one-linked list
ollist {
    int value;
    struct list *next;
};

//The creating of the list
ollist *create(int value) {
    ollist *el = (ollist *) malloc(sizeof(ollist));
    el->value = value;
    el->next = NULL;
    return el;
}

//The function that allows to check if the list is empty
int empty(ollist *l) {
    return !(l->next);
}

//The function that allows to add the element to the end of the list
void push(ollist *l, ollist *el) {
    while (l->next)
        l = l->next;
    ollist *last = l->next;
    el->next = last;
    l->next = el;
}

//The function that allows to pop the first element
int popfirst(ollist *l) {
    if (!empty(l)) {
        ollist *first = l->next;
        l->next = first->next;
        int r = first->value;
        free(first);
        return r;
    }
    return -1;
}

//The function that allows to pop the last element
int popend(ollist *l) {
    if (!empty(l)) {
        ollist *last = l->next;
        while (last->next) {
            l = l->next;
            last = last->next;
        }
        int r = last->value;
        free(last);
        l->next = NULL;
        return r;
    }
    return -1;
}

//The function that allows to find the list length
int listlen(ollist *l) {
    int len = 0;
    while (l->next) {
        l = l->next;
        len++;
    }
    return len;
}

//The function that allows to print the list
void print(ollist *l) {
    ollist *ptr = l->next;
    while (ptr) {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
}

//The function that allows to check the symmetry of parentheses
int parent(char *str, int len) {
    int par = 0;
    for (int i = 0; i < len; i++) {
        if (par < 0)
            return 0;
        else if (str[i] == '(')
            par++;
        else if (str[i] == ')')
            par--;
    }
    if (par)
        return 0;
    return 1;
}

//The function that allows to check if the symbol is arithmetic operation
int isop(char sym) {
    if (sym == '+' || sym == '-' || sym == '*' || sym == '/')
        return 1;
    return 0;
}

//The function that allows to check the example for some input errors
int errors(char *str, int len) {
    if (isop(str[0]) || isop(str[len - 1]))
        return 1;

    for (int i = 0; i < len - 1; i++) {
        if (isop(str[i]) && isop(str[i + 1]))
            return 1;
        else if ((str[i] == '(') && (str[i + 1] == ')'))
            return 1;
        else if ((str[i] == '(') && isop(str[i + 1]))
            return 1;
        else if (isop(str[i]) && (str[i + 1] == ')'))
            return 1;
        else if ('0' <= str[i] && str[i] <= '9' && str[i + 1] == '(')
            return 1;
        else if (str[i] == ')' && '0' <= str[i + 1] && str[i + 1] <= '9')
            return 1;
    }
    return 0;
}

//The function allows to find the non-negative integer degree of the number
int deg(int x, int y) {
    if (y == 0)
        return 1;

    int num = x;
    for (int i = 0; i < y-1; i++)
        num = num * x;
    return num;
}

//The function that allows to convert arithmetic symbols to digit
int convert(char sym) {
    if (sym == '+')
        return -1;
    else if (sym == '-')
        return -2;
    else if (sym == '*')
        return -3;
    else if (sym == '/')
        return -4;
    else if (sym == '(')
        return -5;
    else if (sym == ')')
        return -6;
    else
        return 0;
}

//The function that allows to make postfix notation
void intopost(char *str, int len) {
    ollist *ops = create(0);
    ollist *post = create(0);
    int nlen = 0, num = 0, start;
    for (int i = 0; i < len; i++)
        if ('0' <= str[i] && str[i] <= '9')
            nlen++;
        else {
            if (str[i] != '(') {
                start = i - nlen;
                for (int j = start; j < i; j++)
                    num += (str[j] - '0') * deg(10, start + nlen - j - 1);

                ollist *nums = create(num);
                push(post, nums);
                num = 0;
                nlen = 0;
            }

            int form = convert(str[i]);
            if (form != 0) {
                ollist *op = create(form);
                push(ops, op);
            }
        }
    print(post);
    printf("\n");
    print(ops);

}

int main() {
    int exlen = 0;
    char *example = (char *) malloc(exlen * sizeof(char));
    char sym = getc(stdin);

    while (sym != '\n') {
        if (!('(' <= sym && sym <= '9' && sym != ',' && sym != '.')) {
            puts("syntax error");
            return 0;
        }
        example[exlen] = sym;
        exlen++;
        example = (char *) realloc(example, exlen * sizeof(char));
        sym = getc(stdin);
    }

    if (!parent(example, exlen) || exlen == 0 || errors(example, exlen)) {
        puts("syntax error");
        return 0;
    }

    intopost(example, exlen + 1);

    return 0;
}
