#include <iostream>
#include "Data.h"
#include "CSV_Reader.h"
#include "Interface.h"
#include "View.h"
#include "Book.h"
#include "Print_Functions.h"

int main() {

  Data data;
  CSV_Reader reader(&data);
  View view(&data);
  Book book(&data, &view);
  Interface interface(&data, view, book);

  println("Would you like to use the default .csv files?");
  reader.fileSelection();
  interface.printMenu(0);
  interface.mainMenu();
  
}
