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
int empty(ollist *list) {
    return !(list->next);
}

//The function that allows to add the element to the end of the list
void push(ollist *list, ollist *el) {
    while (list->next)
        list = list->next;
    ollist *last = list->next;
    el->next = last;
    list->next = el;
}

//The function that allows to pop the first element
int popfirst(ollist *list) {
    ollist *first = list->next;
    list->next = first->next;
    int r = first->value;
    free(first);
    return r;
}

//The function that allows to pop the last element
int popend(ollist *list) {
    ollist *last = list->next;
    while (last->next) {
        list = list->next;
        last = last->next;
    }

    int r = last->value;
    free(last);
    list->next = NULL;
    return r;
}

//The function that allow to get the last element value
int valend(ollist *list) {
    if (!empty(list)) {
        while (list->next)
            list = list->next;
        int r = list->value;
        return r;
    }
    return -1;
}

//The function that allows to print the list
void print(ollist *list) {
    ollist *ptr = list->next;
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
int deg(int base, int n) {
    if (n == 0)
        return 1;

    int num = base;
    for (int i = 0; i < n - 1; i++)
        num = num * base;
    return num;
}

//The function that allows to convert arithmetic symbols to digit
int convert(char sym) {
    if (sym == '+')
        return -11;
    else if (sym == '-')
        return -21;
    else if (sym == '*')
        return -12;
    else if (sym == '/')
        return -22;
    else if (sym == '(')
        return '(';
    else
        return ')';
}

//The function that allows to define priority of operations
int prior(ollist *l, int op) {
    int top = valend(l);
    if (top > 0 || op > 0)
        return 0;
    else if (top % 10 > op % 10)
        return 1;
    else if (top % 10 == op % 10)
        return 2;
    return 3;
}

//The function that allows to make postfix notation
ollist *intopost(char *str, int len) {
    ollist *ops = create(0);
    ollist *post = create(0);
    int nlen = 0, num = 0, start;

    for (int i = 0; i < len; i++)
        if ('0' <= str[i] && str[i] <= '9')
            nlen++;

        else {
            if (str[i] != '(' && str[i - 1] != ')') {
                start = i - nlen;
                for (int j = start; j < i; j++)
                    num += (str[j] - '0') * deg(10, start + nlen - j - 1);

                ollist *nums = create(num);
                push(post, nums);
                num = 0;
                nlen = 0;
            }

            int form = convert(str[i]);
            if (isop(str[i])) {
                while (!empty(ops) && prior(ops,form)>=2 && valend(ops)!='(') {
                    ollist *op = create(popend(ops));
                    push(post, op);
                }
                ollist *op = create(form);
                push(ops, op);
            }

            else if (str[i] == '(') {
                ollist *op = create(form);
                push(ops, op);
            }

            else if (str[i] == ')') {
                while (valend(ops) != '(') {
                    ollist *op = create(popend(ops));
                    push(post, op);
                }
                popend(ops);
            }
        }

    while (!empty(ops)) {
        int a = popend(ops);
        ollist *op = create(a);
        push(post, op);
    }
    print(ops);


    return post;
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

    ollist *post = intopost(example, exlen + 1);
    ollist *res = create(0);
    while (!empty(post)) {
        int el = popfirst(post);
        if (el >= 0) {
            ollist *add = create(el);
            push(res, add);
        }

        else {
            int num1 = popend(res);
            int num2 = popend(res);
            int num;

            if (el == -11)
                num = num1 + num2;

            else if (el == -21)
                num = num2 - num1;

            else if (el == -12)
                num = num1 * num2;

            else {
                if (num1 == 0) {
                    puts("division by zero");
                    return 0;
                }
                num = num2 / num1;
            }
            ollist *add = create(num);
            push(res, add);
        }
    }

    print(res);
    free(example);

    return 0;
}
