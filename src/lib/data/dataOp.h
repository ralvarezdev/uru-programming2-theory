#include <string>
#include <typeinfo>

#include "../namespaces.h"

using namespace std;
using namespace clients;
using namespace movies;

// --- Extern Variables Declaration
extern bool movieValidFieldsToFilter[], clientValidFieldsToFilter[];
extern char *movieFieldCmdsStr[], *clientFieldCmdsStr[], *genreStr[];
extern int cmdsChar[], subCmdsChar[], movieFieldCmdsChar[], clientFieldCmdsChar[];

#ifndef DATA_H
#define DATA_H

// --- Functions
int isCharOnArray(int character, int array[], int n);
void addMovie(Movies *movies);
void rentMovie(Movies *movies, Clients *clients);
void getMovieStatus(Movies *movies);
void viewMovies(Movies *movies, bool fields[], int sortBy[]);
void filterMovies(Movies *movies, string **params, int sortBy[]);
void viewClients(Clients *clients, bool fields[], int sortBy[]);
void searchClient(Clients *clients, string **params, int sortBy[]);
void movieFields(); // As a Parameter or as a Subcommand
void sortByParameters();
void clientParameters();
void validGenres();
void howToUseViewMovies();
void howToUseFilterMovies();
void howToUseSearchClient();
void addClient(Clients *clients);

// --- Templates

// Template to Return a String that's Surrounded by Brackets
template <typename T>
string addBrackets(T message)
{
  string addedBrackets;

  if (typeid(T) == typeid(const int)) // Checks if it's a Char
    addedBrackets += message;         // Works fine it Message is a Char
  else
    addedBrackets = message; // Message is of type String´

  assert(addedBrackets.length() > 0); // Check if the Character Could be Appended to the String
  addedBrackets.insert(0, 1, '[');

  return addedBrackets.insert(addedBrackets.length(), 1, ']');
}

#endif