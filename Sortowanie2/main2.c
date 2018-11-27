#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define MAX_ELEMENTS 1000
#define RAND_LOW 1
#define RAND_HIGH 100


int main (int argc, char *argv[])
{
  int *elements;
  char text[108];
  int num_elements;
  int min_val, min_index, buff;

  if (argc!= 1)
  {
    printf ("Program nie przyjmuje argumentow\n");
    return 0;
  }

  printf ("Podaj liczbe elementow:");
  gets(text);
  num_elements = atoi (text);
  printf ("Po zmianie na liczbe: %d\n\n", num_elements);

  elements = malloc (num_elements * sizeof(int));

  srand (time(NULL));

  for (int i=0; i < num_elements; i++)
  {
    elements[i] = (rand() % (RAND_HIGH - RAND_LOW)) + RAND_LOW;
    printf ("Element[%d]: %d\n", i, elements[i]);
  } 
   
  printf ("\nElements[%d]: ", num_elements);
  for (int i=0; i < num_elements; i++)
    printf ("%d ", elements[i]);  
  printf ("\n\n");

  for (int step = 0; step < num_elements - 1; step++)
  {
    min_val = elements[step]; 
    min_index = step;
    for(int pilot = step + 1; pilot < num_elements; pilot++)
    {
      if (elements[pilot] < min_val)
      {
        min_val = elements[pilot];
        min_index = pilot;
      }
    }
    if (min_index > step)
    {
      buff = elements[step];
      elements[step] = elements[min_index];
      elements[min_index] = buff;
    }

  printf ("Step[%02d]: ", step);
  for (int i=0; i < num_elements; i++)
  {
    printf ("%02d", elements[i]);  
    if (i== step) 
      printf ("|");
    printf (" ");
  }

  printf("\n");
  }
  printf ("\nElements[%d]: ", num_elements);
  for (int i=0; i < num_elements; i++)
    printf ("%d ", elements[i]);  

  return 0;
}
