#include <stdio.h>
#include <math.h>

int main() {
    int floors, aps, num, entrance, floor;
    scanf("%d %d %d", &floors, &aps, &num);
    entrance = (num / (floors * aps)) + (1 <= (num % (floors * aps)));
    floor = ((num % (floors * aps)) / aps) + (1 <= (num % aps)) + ((num % (floors * aps)) == 0) * 5;
    printf("%d %d", entrance, floor);

    return 0;
}
