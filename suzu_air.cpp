// :::::::::  SUZUMI  AIRLINES  ::::::::: //
// :::::   Created by Ryuu Mitsuki  ::::: //
// :::::::::  ----------------  ::::::::: //
// | *** Project C++ <> [ X TKJ-1 ] *** | //


// -- [+] Import Packages [+] -- //
#include <stdio.h>   // C Language
#include <iostream>  // C++ Language
#include <string>    // String Library
#include <stdlib.h>  // Standard Library
#include <conio>     // Control I/O

// -- Namespace -- //
using namespace std;


// -- MAIN FUNCTION -- //
int main() {
    // Create variables
	int i, price, ticket, total, pay;

	// Create list for flight codes & prices
	string flight_codes[5] = {"BDG-JPG  >  Bandung-Jepang   ",
   							  "ING-SRB  >  Inggris-Surabaya ",
   							  "KMB-LOM  >  Kamboja-Lombok   ",
                             "MLY-BDG  >  Malaysia-Bandung ",
                             "SIN-JKT  >  Singapura-Jakarta"};
   string flight_prices[5] = {"2.850.000",
   							  "2.200.000",
                              "1.750.000",
                              "1.440.000",
                              "1.580.000"};
	// Create price list
   const int prices_list[5] = {
        2850000,
        2200000,
        1750000,
        1440000,
        1580000
   };
    

	
   RESET: /* create label for loop retry */
	
   // Display list flight schedules
   clrscr(); /* clear screen */
   gotoxy(18, 2); // memindahkan kursor ke tempat x, y yg ditentukan
   cout << "-------------------------------" << endl;
   gotoxy(18, 3);
   cout << "|       SUZUMI AIRLINES       |" << endl;
   gotoxy(18, 4);
   cout << "-------------------------------" << endl;

   gotoxy(4, 6);
   cout << "-----------------------------------------------------------" << endl;
   gotoxy(4, 7);
   cout << "|  No.  |         Kode Penerbangan        |     Harga     |" << endl;
   gotoxy(4, 8);
   cout << "-----------------------------------------------------------" << endl;

   i = 0;
   for (int index = 0; index < 5; index++) { // menggunakan looping utk meng-iterate list satu-satu
       gotoxy(4, 9+i);
	   cout << "| *[" << ++i << "]  |  ";
	   cout << flight_codes[index] << "  | " << flight_prices[index] << " IDR |" << endl;
   }
   gotoxy(4, 14);
   cout << "-----------------------------------------------------------" << endl << endl;
	
	
    // Create user input (index ticket)
	char user_choice; // char hanya dapat menyimpan satu karakter saja
	cout << "[*] Selamat datang di Suzumi Airlines" << endl << endl;
	cout << "( Masukan No. Ticket [1 - 5] )~[int]" << endl;
	cout << ">>> ";
	user_choice = getche(); // get char & echo (output)
	cout << endl;
	
	// Check user input
    switch (user_choice) {
        case '1':
            price = prices_list[0];
            break;
        case '2':
            price = prices_list[1];
            break;
        case '3':
            price = prices_list[2];
            break;
        case '4':
            price = prices_list[3];
            break;
        case '5':
            price = prices_list[4];
            break;
        default:
            char askretry;
            cout << "\n[!] System: Invalid input -> " << user_choice << endl;
            cout << "Try again? (Y/n): ";
            askretry = getche(); // input
            if (askretry == 'Y' || askretry == 'y') goto RESET; // menuju awal dan ulangi
            else exit(0);
    }
    cout << "[*] Anda telah memilih nomer " << user_choice << endl << endl;
    
    // Create user input (total ticket)
    cout << "( Masukan Jumlah Tiket )~[int]" << endl;
	cout << ">>> ";
	cin >> ticket;
	
	// Check user input
    if (ticket == 0) goto RESET; // menuju awal
    
    // Calculate total price
    total = price * ticket;
    
    cout << "[*] Jumlah tiket = " << ticket << endl;
    cout << "[*] Total harga  = " << total << " IDR" << endl << endl;
    
    // Create user input (pay)
    cout << "( Silahkan Masukan Pembayaran )~[int]" << endl;
	cout << ">>> ";
	cin >> pay;
	cout << endl;
	
	
	// Check user input
	if (pay < total) {
	    cout << "[!] System: Maaf, uang Anda tidak mencukupi" << endl << endl;
	    cout << "Press any key to exit...";
	    getch(); // get char
	    exit(1);
	}
    
    // Output
    clrscr();
    cout << "\n _____________________________" << endl;
    cout << " Harga Tiket  : " << price << endl;
    cout << " Jumlah Tiket : " << ticket << endl;
    cout << " Total Harga  : " << total << endl; 
    cout << " Bayar        : " << pay << endl;
    cout << " ______________________________" << endl;
    cout << " Kembalian    : " << (pay - total) << " IDR" << endl << endl;
    
    cout << "[*] Terima kasih sudah membeli tiket di Suzumi Airlines" << endl;
    cout << endl << "Press any key to exit...";
    getch();
}

