/**
    Dictionary demo using an array by Michael Gamble
 */

#include <iostream>
#include "DictionaryInterface.h"
#include "ArrayDictionary.hpp"
#include "ArrayDictionary.cpp"
#include "Entry.hpp"
#include "Entry.cpp"
#include <string>
using namespace std;

//Host function called by ArrayDictionary class function
//traverse, used to print the data
template< class T>
void visit(T &item)
{
    cout  <<  item  << endl;//Print the value for now
}

//Main
int main(int argc, const char * argv[])
{
    //Create an array dictionary with 25 items 
    int maxItems = 25;
    ArrayDicitionary<string, string> *arrDict = new ArrayDicitionary<string, string>(maxItems);

    //Add a number of entries to the dictionary
    arrDict -> add("Paul",  "Febuary/04/1982");
    arrDict -> add("Suzy",  "May/12/1980");
    arrDict -> add("Lisa",  "December/01/1980");
    arrDict -> add("Liza",  "December/02/1982");
    arrDict -> add("Fred",  "January/05/1982");
    arrDict -> add("Karen", "March/12/1980");
    arrDict -> add("Derek", "June/03/1983");
    arrDict -> add("Frank", "December/12/1980");
    arrDict -> add("Judy",  "July/12/1980");
    arrDict -> add("Jason", "December/03/1981");
    arrDict -> add("Harry", "June/03/1983");
    arrDict -> add("Jamie", "November/12/1980");
    arrDict -> add("Lenny", "December/04/1983");
    arrDict -> add("Brett", "April/12/1980");
    arrDict -> add("Anna",  "September/10/1980");
    arrDict -> add("John",  "October/10/1980");
    cout  <<  "Added "  <<  arrDict -> getNumberOfItems()
          <<  " entries to the dictionary."  <<  endl  <<  endl;
    
    //Search the dictionary for "Frank" and display his
    //birthday
    cout  <<  "Now searching for Frank to display his information: \n";
    if(arrDict ->contains("Frank"))
    {
        //Display Frank's birthday
        cout  <<  "Frank: ";
        cout  <<  arrDict -> getItem("Frank")  <<  endl;
    }
    cout  <<  endl;
    
    //Remove Frank from the dictionary
    cout  <<  "Now removing Frank from the dictionary...\n";
    arrDict -> remove("Frank");
    //Display total number of entries
    cout  <<  "The dictionary now contains "  <<  arrDict -> getNumberOfItems()
          <<  " entries."  <<  endl  <<  endl;

    //Traverse all
    //Asserts that there are entries birthdays and traverse the array
    cout  <<  "Now displaying information for all of \nthose left in the dictionary: "  <<  endl;
    arrDict -> traverse(visit);
    cout  <<  endl;
    cout  <<  endl;
    
    //Traverse for December birthdays
    //Asserts that there are enteries with December birthdays
    cout  <<  "Now displaying information for those \nborn in December: "  <<  endl;
    arrDict -> traverse("December", visit);
    cout  <<  endl;
    cout  <<  endl;
    
    //Clear the entries
    cout  <<  "Now clearing all entries..."  <<  endl;
    arrDict -> clear();
    
    if(arrDict -> isEmpty())
    {
        cout  <<  "The dictionary contains "  <<  arrDict -> getNumberOfItems()
              <<  " entries."  <<  endl  <<  endl;
    }//end if
    
    return 0;
}//end main 
