#include <stdio.h>

int main() {
    int acute = 0, right = 0, obtuse = 0, wrong = 0;
    int i, angle;

    for (i = 1; i <= 4; i++) {
        printf("Enter angle %d: ", i);
        scanf("%d", &angle);

        if (angle <= 0 || angle >= 180) {
            printf("Invalid angle. Please try again.\n");
            wrong++;
            i--;
        }
        else if (angle < 90) {
            acute++;
        }
        else if (angle == 90) {
            right++;
        }
        else {
            obtuse++;
        }
    }

    if (acute + right + obtuse == 3) {
        printf("Enter angle 4: ");
        scanf("%d", &angle);

        if (angle <= 0 || angle >= 180) {
            printf("Invalid angle. Please try again.\n");
            wrong++;
        }
        else if (angle < 90) {
            acute++;
        }
        else if (angle == 90) {
            right++;
        }
        else {
            obtuse++;
        }
    }

    printf("Number of acute angled triangles: %d\n", acute);
    printf("Number of right angled triangles: %d\n", right);
    printf("Number of obtuse angled triangles: %d\n", obtuse);
    printf("Number of wrong entries: %d\n", wrong);

    return 0;
}