/* Contains functions for calc.c program */

#include <stdio.h>

  struct student 
  {
    int score[50];
    char name[256];
    int percent;
    char grade;
  } student[256];

void calc (struct student *, int);
int grades (int);
void print (struct student *, int, int, int, int, int, char, int);


void calc(struct student *student, int q)
{
  float total = 0;
  float assign, quiz, exam, final;
  char letter;
  int i;
  float x;

  for (i = 0; i < 6; i++)
    total = total + student[q].score[i];
  assign = ((total/700)*100);

  total = 0;

  for (i = 6; i < 9; i++)
    total = total + student[q].score[i];
  quiz = ((total/75) * 100);

  total = 0;
  
  for (i = 9; i < 11; i++)
    total = total + student[q].score[i];
  exam = ((total/200) * 100);
  
  total = 0;

  total = total + student[q].score[11];
  final = ((total/200)*100);

  x = ((assign*.4) + (quiz*.1) + (exam*.25) + (final*.25));

  letter = grades(x);

  print(student, assign, quiz, exam, final, x, letter, q);

}

int grades(int x)
{
  if (x >= 90)
    return 'A';
  else if (x >= 80)
    return 'B';
  else if (x >= 70)
    return 'C';
  else if (x >= 60)
    return 'D';
  else
    return 'F';
}

void print (struct student *student, int assign, int quiz, int exam, int final, int x, char letter, int q)
{
  int i;
  int y = 1;
  printf("\nName: %s", student[q].name);
  for (i = 0; i <= 6; i++)
    {
      printf("\nScore for Assignment %d: %d", y, student[q].score[i]);
      y++;
    }
  y = 1;
      for (i = 6; i < 9; i++)
    {
      printf("\nScore for Quiz %d: %d", y, student[q].score[i]);
      y++;
    }
  y = 1;
  for (i = 9; i < 11; i++)
    {
      printf("\nScore for Exam %d: %d", y, student[q].score[i]);
      y++;
    }
  printf("\nScore for Final Exam: %d", student[q].score[11]);
  printf("\n_____________________________________________________");
  printf("\nPercentage per category:");
  printf("\nAssignments: %d", assign);
  printf("\nQuizzes: %d", quiz);
  printf("\nExams: %d", exam);
  printf("\nFinal Exam: %d", final);
  printf("\nYour weighted percentage is: %d%", x);
  printf("\nYour Grade Point is: %c\n", letter);
}
