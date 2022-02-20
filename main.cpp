#include <iostream>
#include "Book.h"
#include "Store.h"
#include <string>

using namespace std;

int main()
{
    //***creating the library
    Book bk101 ("Gambardella, Matthew" ,"XML Developer's Guide" , "Akashic Books" , 44.95 , "long" );
    Book bk102 ("Ralls, Kim" , "Midnight Rain" , "Dzanc Books" , 5.95 ,"short");
    Book bk103 ("Corets, Eva","Maeve Ascendant","Graywolf Press",5.95,"short");
    Book bk104 ("Corets, Eva","Oberon's Legacy","Graywolf Press",5.95,"short");
    Book bk105 ("Corets, Eva","The Sundered Grail","Graywolf Press",5.95,"short");
    Book bk106 ("Randall, Cynthia","Lover Birds","Dzanc Books",4.95,"long");
    Book bk107 ("Thurman, Paula","Splish Splash","Akashic Books",4.95,"short");
    Book bk108 ("Knorr, Stefan","Creepy Crawlies","Graywolf Press",4.95,"short");
    Book bk109 ("Kress, Peter","Paradox Lost","McSweeney's",6.95,"short");
    Book bk110 ("O'Brien, Tim","Microsoft .NET: The Programming Bible","McSweeney's",36.95,"long");
    Book bk111 ("O'Brien, Tim","MSXML3: A Comprehensive Guide","McSweeney's",36.95,"long");
    Book bk112 ("Galos, Mike","Visual Studio 7: A Comprehensive Guide","McSweeney's",49.95,"short");
    Book bk113 ("Corets, Eva","The Sundered Grail","Graywolf Press",5.95,"short");
    Book bk114 ("Corets, Eva","The Sundered Grail","Graywolf Press",5.95,"short");
    Book bk115 ("Corets, Eva","The Sundered Grail","Graywolf Press",5.95,"short");
    Book bk116 ("Ralls, Kim" , "Midnight Rain" , "Dzanc Books" , 5.95 ,"short");
    Book bk117 ("Ralls, Kim" , "Midnight Rain" , "Dzanc Books" , 5.95 ,"short");
    Book bk118 ("Gambardella, Matthew" ,"XML Developer's Guide" , "Akashic Books" , 44.95 , "long" );
    Book bk119 ("Gambardella, Matthew" ,"XML Developer's Guide" , "Akashic Books" , 44.95 , "long" );
    Book bk120 ("Gambardella, Matthew" ,"XML Developer's Guide" , "Akashic Books" , 44.95 , "long" );
    Book bk121 ("Corets, Eva","Maeve Ascendant","Graywolf Press",5.95,"short");
    Book bk122 ("Randall, Cynthia","Lover Birds","Dzanc Books",4.95,"long");
    Book bk123 ("Randall, Cynthia","Lover Birds","Dzanc Books",4.95,"long");
    Book bk124 ("Kress, Peter","Paradox Lost","McSweeney's",6.95,"short");
    Book bk125 ("Galos, Mike","Visual Studio 7: A Comprehensive Guide","McSweeney's",49.95,"short");
    Book bk126 ("Galos, Mike","Visual Studio 7: A Comprehensive Guide","McSweeney's",49.95,"short");
    Book bk127 ("Galos, Mike","Visual Studio 7: A Comprehensive Guide","McSweeney's",49.95,"short");
    Book bk128 ("Galos, Mike","Visual Studio 7: A Comprehensive Guide","McSweeney's",49.95,"short");
    Book bk129 ("Galos, Mike","Visual Studio 7: A Comprehensive Guide","McSweeney's",49.95,"short");

    Book books [50]= {bk101,bk102,bk103,bk104,bk105,bk106,bk107,bk108,bk109,bk110,bk111,bk112,bk113,bk114,bk115,bk116,bk117,bk118,bk119,bk120,bk121,bk122,bk123,bk124,bk125,bk126,bk127,bk128,bk129};;


    //*****input******

 while (1){
    cout << "Please enter the title of the book and the author name or \"-1\" to exit the program." << endl;

    string tempAuthor,tempTitle;
    string ans;
    float clientRate;
    bool found=false , correctIO=false;

    cout << "The book title: " ;
    getline(cin>>ws,tempTitle);
    if (tempTitle == "-1") return 0;
   // cin.ignore();
    cout << "The book's author: ";
    getline(cin>>std::ws,tempAuthor);
   // cin.ignore();
    if (tempAuthor == "-1") return 0;

    //***search***
    int bookPos,copiesWanted,copiesFound=1;

    for (int i=0; i<50 ; i++){
        if (books[i].getTitle()==tempTitle && books[i].getAuthor()==tempAuthor){
            bookPos=i;
            cout <<"Found"<< endl;
            found=true;
            break;
        }
    }
    if (found){
    cout << "The book details:- "<<endl ;
    cout << "Author: " << books[bookPos].getAuthor() << endl;
    cout << "Title: " << books[bookPos].getTitle() << endl;
    cout << "Publisher: " << books[bookPos].getPublisher() << endl;
    cout << "Price: " << books[bookPos].getPrice() << endl;
    cout << "Stock Position: " << books[bookPos].getStockPos() << endl;
    cout << "Rate: " ;
    if (books[bookPos].getRate()==0) cout << "Not rated yet." << endl;
        else
    cout << books[bookPos].getRate() << endl;

    //*****take the rate
    cout << "Have you read this book before?" << endl << "1)Yes \t 2)No" << endl;
    cout << "Type 1 or 2" << endl;

    while(!correctIO) {

    cin>> ans;

        if (ans=="1"){
            correctIO=true;
            cout << "Please give this book a rate out of 5" << endl;
            do {
            cout << "You must enter a rate less than or equal 5." << endl;
            cin >> clientRate;
            } while (clientRate>5);
            books[bookPos].setRateCounter(books[bookPos].getRateCounter()+1); //rateCounter++
            books[bookPos].setRate((clientRate+books[bookPos].getRate())/books[bookPos].getRateCounter()); //clientRate+ old rate / n


        }
        else if(ans=="2"){
            correctIO=true;
            cout << "We hope you like the book." << endl;
        }
        else {
             cout << "Please choose 1 or 2" << endl;
        }
        }

    //***Purchasing

    cout << "How many copies are you want?" << endl;
    cin >> copiesWanted ;

    //***determine the number of copies of the books
    int i=bookPos+1;
    while(i<50){
        if (books[bookPos].getTitle()==books[i].getTitle() && books[bookPos].getAuthor()==books[i].getAuthor()){
        copiesFound++;
        }
        i++;
    }
    //**check the copies
    if (copiesFound>=copiesWanted){
        cout << "The total cost is " << copiesWanted*books[bookPos].getPrice() << endl;
    }
    else {
        cout <<"The requested copies aren't in stock, there is only " << copiesFound << " book/s."<< endl;
    }
    }
    else {
       cout <<"The book isn't found! "<< endl << endl << "******************************" << endl<< endl;
    }
}
       return 0;
}
