#include <stdio.h>

int main() {
  int original_marks[25], revised_marks[25];
  int birth_month[25];
  int i, original_total = 0, revised_total = 0;
  float original_avg, revised_avg, increase;

  printf("Enter original marks and birth month for each student:\n");
  for(i = 0; i < 25; i++) {
    scanf("%d %d", &original_marks[i], &birth_month[i]);
  }

  for(i = 0; i < 25; i++) {
    revised_marks[i] = original_marks[i] + birth_month[i];
    revised_total += revised_marks[i];
    original_total += original_marks[i];
  }

  original_avg = (float)original_total / 25;
  revised_avg = (float)revised_total / 25;

  increase = revised_avg - original_avg;

  if(increase >= 5) {
    printf("Can implement - Significant increase in class average\n");
  } else {
    printf("Need not implement - No significant increase in class average\n");
  }

  return 0;
}