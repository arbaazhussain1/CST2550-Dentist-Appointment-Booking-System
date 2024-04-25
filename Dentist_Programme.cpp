#include <iostream>
#include "Data.h"
#include "CSV_Reader.h"
#include "Interface.h"
#include "View.h"
#include "Book.h"
#include "Print_Functions.h"

int main() {
  // Create instances of necessary classes
  Data data;
  CSV_Reader reader(&data);
  View view(&data);
  Book book(&data, &view);
  Interface interface(&data, view, book);

  // Prompt the user to use default .csv files
  println("Would you like to use the default .csv files?");
  reader.fileSelection();
  // Print the main menu and start the interface
  interface.printMenu(0);
  interface.mainMenu();
  
}
