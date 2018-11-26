// Pliki naglówkowe
#include <stdlib.h> // standard
#include <math.h>   // math
#include <stdio.h>  // input output
#include <time.h>   // time

// Definicje preprocesora - stałe do obliczeń
#define MAX_ELEMENTS 1000
#define RAND_LOW 1
#define RAND_HIGH 100


int main (int argc, char *argv[])
{
  //
  // deklaracje zmiennych
  //
  // TODO: dorobic zarzadzanie pamiecia zeby zniesc ograniczenie
  int  static_elements[MAX_ELEMENTS];
  int *dynamic_elements;
  int *elements;
  char text[108];
  int  num_elements;
  int  min_val, min_index, buff;

  // Sprawdzenie czy użytkownik podal argumenty w konsoli
  if (argc != 1)
  {
	// Jeśli oprócz nazwy programu będzie podany argument to nara..
    printf("Program nie przyjmuje argumentow\n");
    return 0;
  }

  // Odczytaj liczbe elementow do posortowania
  printf("Podaj liczbe elementow do posortowania: ");
  gets(text); // Get String - tu czytamy ciąg znaków podany przez użytkownika

  printf("Uzytkownik podal: %s\n", text);

  // Zamiana string ASCII to Int (American Standard Code for Information Interchange)
  num_elements = atoi(text);
  printf("Po zamianie na liczbe: %d\n\n", num_elements);

  // Alokacja pamieci na tablice o zmiennym rozmiarze
  dynamic_elements = malloc(num_elements * sizeof(int));
  elements = static_elements;
  elements = dynamic_elements;

  // Zaplodnic generator liczb pseudolosowych czasem
  srand(time(0)); // set seed

  // Wygenerowac podana liczbe liczb losowych
  for (int i=0; i < num_elements; i++)
  {
    elements[i] = (rand() % (RAND_HIGH - RAND_LOW)) + RAND_LOW;
    printf("Element[%d]: %d\n", i, elements[i]);
  }
  // Wypisujemy wszystkie elementy
  printf("\nElements[%d]: ", num_elements); for (int i=0; i < num_elements; i++) { printf("%d ", elements[i]); } printf("\n\n");

  // Sortowanie
  for (int krok = 0; krok < num_elements - 1; krok++)
  {
    min_val = elements[krok];
    min_index = krok;
    for(int pilot = krok + 1; pilot < num_elements; pilot++)
    {
      if(elements[pilot] < min_val)
      {
        min_val = elements[pilot];
	    min_index = pilot;
      }
    }
    if (min_index > krok)
    {
      buff = elements[krok];
      elements[krok] = elements[min_index];
      elements[min_index] = buff;
    }
  //printf("Krok[%02d]: ", krok); for (int i=0; i < num_elements; i++) { printf("%02d ", elements[i]); } printf("\n");
  //for (int i=0; i < 3*krok+11; i++) printf(" ");printf("^\n");
  }

  printf("\nElements[%d]: ", num_elements); for (int i=0; i < num_elements; i++) { printf("%d ", elements[i]); } printf("\n\n");
  free(dynamic_elements);
  return (0);
}
