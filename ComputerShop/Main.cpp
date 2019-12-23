

/*                                                Computer Shop
 *
 *		Description - Computer Shop is a project developed to maintain the records of its consumers, details and pricing 
 *                    of various products such as monitor, CPU, GPU, laptop, keyboard, headphones.
 *      This program also generate bill for the items purchased from the shop by a customer using customerIDS and various
 *      details.
 *	
 *		
 *		Security - This program is password protected and the default passowrd is "ds12345" without double quotes.
 *				   It can be changed and is present in the main() function.
 *
 *
 *		Features to be expected soon -
 *        - GUI support
 *        - support for more products
 *		  - Security updates
 *		  - 
 *
 *
 *		Changelogs-
 *			v0.0.1
 *           - Compiled successfully
*/


#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<process.h>


using namespace std;

char Password[10];
float choice, choice02, cho01, cho02, cho03, cho04, cho05, cho06;
int choice01;

// Names and Details oF Product 

//  ------------------------------------------------------------    //

char LaptopN1[50] = " Razer Blade Pro Gaming Laptop";
char LaptopN2[50] = " MSI Gaming MSI GT83 8RG";
char LaptopN3[50] = " ASUS ROG STRIX GL703VM ";

char MonitorN1[100] = " Samsung 49-Inch Monitor";
char MonitorN2[100] = " BenQ 1ms GTG XL2720Z 34-inch High Performance LED Monitor ";
char MonitorN3[100] = " ASUS ROG Swift PG348Q 34-inch Curved Monitor ";

char CPUn1[50] = " Intel i7 7700-Q";
char CPUn2[50] = " Intel i9 7900-X";
char CPUn3[50] = " AMD Ryzen 5 1600X ";
char CPUn4[50] = " AMD Ryzen 3 1300X ";

char GPUn1[50] = " NVIDIA Geforce GTX 1080 8GB GDDR5X ";
char GPUn2[50] = " NVIDIA Geforce GTX 1060 6GB GDDR5 ";
char GPUn3[50] = " AMD Radeon RX 480 4GB GDDR5 ";
char GPUn4[50] = " Gigabyte AMD RADEON R9 380X ";

char KeyboardN1[50] = " Logitech 967599-0403 Keyboard ";
char KeyboardN2[50] = " Logitech G110 Gaming Keyboard ";
char KeyboardN3[50] = " Microsoft Bluetooth Keyboard 6000 ";

char HeadphonesN1[50] = " Razer Kraken Pro V2 RZ04-02050300-R3M1 (Green)";
char HeadphonesN2[50] = " Logitech Prodigy G231 Headphones with Mic(Black)";
char HeadphonesN3[50] = " Razer Hammerhead V2 Analog in-Ear Headphones";

char LaptopP1[20] = " i7-7820HK ";
char LaptopR1[20] = " 32 GB RAM ";
char LaptopS1[20] = " 1 TB SSD ";
char LaptopG1[40] = " GTX 1080 8GB GDDR5X VRAM ";

char LaptopP2[40] = " 8th Gen Core i7 - 8850H ";
char LaptopR2[20] = " 32 GB RAM ";
char LaptopS2[20] = " 1 TB SSD ";
char LaptopG2[40] = " 8GB Graphics";

char LaptopP3[20] = " Core i7-7700HQ ";
char LaptopR3[40] = " 32GB RAM";
char LaptopS3[20] = " 1 TB SSD ";
char LaptopG3[40] = " GTX 1060 (6GB) ";

//  ------------------------------------------------------------    //

//Price Listing
long int LP1 = 320000, LP2 = 450000, LP3 = 400000, MP1 = 120000, MP2 = 230000, MP3 = 96000, CP1 = 63000, CP2 = 176000, CP3 = 56000;
unsigned long int CP4 = 16000, GP1 = 120000, GP2 = 92000, GP3 = 46000, GP4 = 23000, KP1 = 48000, KP2 = 71000, KP3 = 54000, HP1 = 7000, HP2 = 7000, HP3 = 4000, FinalPrice = 0;

class Customer {
	int cID;
	char cName[20];
	char cAddress[100];
	char cPhoneNumber[15];
	char cEmailID[30];
public:

	// Input customer details
	void getinfo() {
		cout << endl << endl << endl;
		cout << "\t\t  Enter Customer ID  :  ";
		cin >> cID;        cout << endl;
		getchar();
		Sleep(200);
		cout << "\t\t  Enter Customer's Name  :  ";
		fgets(cName,sizeof(cName),stdin);
		Sleep(200);
		cout << "\t\t  Enter Address  :  ";
		fgets(cAddress, sizeof(cAddress), stdin);
		Sleep(200);
		cout << "\t\t  Enter Phone Number  :  ";
		fgets(cPhoneNumber, sizeof(cPhoneNumber), stdin);
		Sleep(200);
		cout << "\t\t  Enter Customer's Email ID  :  ";
		fgets(cEmailID, sizeof(cEmailID), stdin);
		Sleep(200);
	}

	// Display Customer Information
	void displayinfo() {
		cout << "\t\t  Customer ID  :  ";
		cout << cID;        cout << endl;
		cout << "\t\t  Customer's Name  :  ";
		puts(cName);
		cout << "\t\t  Address  :  ";
		puts(cAddress);    cout << endl;
		cout << "\t\t  Phone Number  :  ";
		puts(cPhoneNumber);
		cout << "\t\t  Customer's Email ID  :  ";
		puts(cEmailID);    cout << endl;

	}

	// fucntion to get customer ID
	int getCID() {
		return cID;
	}
	
	// Fucntion to print Bill MEMO
	void BillIFNO() {
		system("cls");
		// Basically All Customer Details
		ifstream f("Customer.dat", ios::binary);
		int no;
		cout << "\n Enter Customer ID Number ";
		cin >> no;
		if (!f) {
			cout << " File Does not exist ";
			exit(0);
		}
		system("cls");
		cout << "\n\n\t\t ______________________________________________________________________________ ";
		cout << "\n\n\t\t                              Bill Memo                                         ";
		cout << " \n\n\t\t          ************************************************************       " << endl;
		int f1 = 0;
		Customer C;
		while (!f.eof()) {
			f.read((char*)& C, sizeof(C));
			if (C.getCID() == no) {
				C.displayinfo();
				f1 = 1;
				break;
			}
		}
		if (f1 == 0) {
			cout << endl << " Customer ID Number Does not exist " << endl;
			return ;
		}
			f.close();
		cout << "\t\t  Final Price : " << FinalPrice << endl << endl;

		cout << " \n\n\t\t          ************************************************************     " << endl;


		cout << "\t\t  Seller Name and contact info -                                               " << endl;
		cout << "\t\t  D.S.Hardware and tech solutions, New Delhi - 110094                          " << endl;
		cout << "\t\t  Contact No. 011 - 2298721-23                                                 " << endl;
		cout << "\t\t  Rating - 4.7                                                                 " << endl;

		cout << " \n\n\t\t          ************************************************************    ";
		cout << " \n\t\t                                                                            " << endl;
		cout << "\n\n\t\t ______________________________________________________________________________ "<<endl;
		getchar();
		getchar();
	}
};

// PasswordToLogin
void GetPASSWORD() {

	// Default - ds12345

	Password[0] = _getch();;
	cout << "*";
	Password[1] = _getch();;
	cout << "*";
	Password[2] = _getch();;
	cout << "*";
	Password[3] = _getch();;
	cout << "*";
	Password[4] = _getch();;
	cout << "*";
	Password[5] = _getch();;
	cout << "*";
	Password[6] = _getch();;
	cout << "*";
	Password[7] = '\0';
	_getch();


	//getchar();                 // Readkey() - Enter
}
// CreateFileToSaveRecord 
void WriteALL() {
	ofstream f("Customer.dat");
	f.close();
}
//DisplayRecord
void Display() {
	Customer c;
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");

	ifstream f("Customer.dat", ios::binary | ios::in);
	if (!f) {
		cout << " File Does not exist ";
		exit(0);
	}

	while (f.read((char*)& c, sizeof(c))) {
		c.displayinfo();
	}
	getchar();
	getchar();
	f.close();
	//return;
}
//Append
void Append() {
	
	WriteALL();
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");

	fstream f("Customer.dat", ios::app | ios::binary);
	Customer C;
	C.getinfo();
	f.write((char*)& C, sizeof(C));
	f.close();
	cout << " Saving Data ";
	Sleep(200);
	cout << " .";
	Sleep(200);
	cout << " .";
	Sleep(200);
	cout << " .";

}
//Search
void Search() {
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");

	ifstream f("Customer.dat", ios::binary);
	int no;
	cout << "\n Enter Customer ID Number to Search ";
	cin >> no;
	if (!f) {
		cout << " File Does not exist ";
		exit(0);
	}
	int f1 = 0;
	Customer C;
	while (!f.eof()) {
		f.read((char*)& C, sizeof(C));
		if (C.getCID() == no) {
			C.displayinfo();
			f1 = 1;
			break;
		}
	}
	if (f1 == 0)
		cout << endl << " Customer ID Number Does not exist " << endl;
	f.close();
	getchar();
	getchar();

}
//Modify
void Modify() {
	system("cls");
	Customer C1;
	fstream f("Customer.dat", ios::in | ios::out | ios::binary);
	if (!f) {
		cout << " File Not Found ";
		exit(0);
	}
	int no;
	cout << " Enter Customer ID Number you want to search ";
	cin >> no;
	while (!f.eof()) {
		f.read((char*)& C1, sizeof(C1));
		if (C1.getCID() == no) {
			C1.getinfo();
			//f.seekg(-1 * sizeof(C1), ios::cur);
			f.seekp(f.tellg());
			f.write((char*)& C1, sizeof(C1));
		}
	}
	f.close();
	getchar();
}
//Disp Info
void LaptopINFO() {
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
LI:
	cout << "\t\t   ------- Laptops --------          " << endl << endl << endl;

	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\t 1. " << endl;
	cout << "\t\t    " << LaptopN1 << endl;
	cout << "\t\t    Processor -> " << LaptopP1 << "   RAM       -> " << LaptopR1 << endl;
	cout << "\t\t    GPU       -> " << LaptopG1 << "   Storage   -> " << LaptopS1 << endl;
	cout << "\t\t            Price -> " << LP1 << endl << endl;

	cout << "\t\t 2. " << endl;
	cout << "\t\t    " << LaptopN2 << endl;
	cout << "\t\t    Processor -> " << LaptopP2 << "    RAM       -> " << LaptopR2 << endl;
	cout << "\t\t    GPU       -> " << LaptopG2 << "    Storage   -> " << LaptopS2 << endl;
	cout << "\t\t            Price -> " << LP2 << endl << endl;

	cout << "\t\t 3. " << endl;
	cout << "\t\t    " << LaptopN3 << endl;
	cout << "\t\t    Processor -> " << LaptopP3 << "    RAM       -> " << LaptopR3 << endl;
	cout << "\t\t    GPU       -> " << LaptopG3 << "    Storage   -> " << LaptopS3 << endl;
	cout << "\t\t            Price -> " << LP3 << endl << endl;
	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\tBack - 0 " << endl;

	cout << endl << "\t\t     Enter Your Choice ";
	cin >> cho01;
	if (cho01 == 1)
		FinalPrice = FinalPrice + LP1;
	else if (cho01 == 2)
		FinalPrice = FinalPrice + LP2;
	else if (cho01 == 3)
		FinalPrice = FinalPrice + LP3;
	else if (cho01 == 0)
		return;

	else {
		system("cls");
		cout << " Wrong Command ";
		getchar();
		goto LI;
	}
	Sleep(1000);
	cout << " Confirming Your Order Please Wait ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	cout << "  Order Confirmed ";
	Sleep(500);
	cout << " \n\n\n Thanks For shoppping with us ...";
	cout << " \n Press Any Key To Continue ";
	getchar();

}
void MonitorINFO() {
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
MI:
	cout << "\t\t             ------- Monitors --------          " << endl << endl << endl;

	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\t     1. " << endl;
	cout << "\t\t     -->   " << MonitorN1 << endl;
	cout << "\t\t     Price -->   " << MP1 << endl << endl;
	cout << "\t\t     2. " << endl;
	cout << "\t\t     -->   " << MonitorN2 << endl;
	cout << "\t\t     Price -->   " << MP2 << endl << endl;
	cout << "\t\t     3. " << endl;
	cout << "\t\t     -->   " << MonitorN3 << endl;
	cout << "\t\t     Price -->   " << MP3 << endl << endl;
	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\tBack - 0 " << endl;

	cout << endl << "\t\t     Enter Your Choice ";
	cin >> cho02;
	if (cho02 == 1)
		FinalPrice = FinalPrice + MP1;
	else if (cho02 == 2)
		FinalPrice = FinalPrice + MP2;
	else if (cho02 == 3)
		FinalPrice = FinalPrice + MP3;
	else if (cho02 == 0)
		return;
	else {
		system("cls");
		cout << " Wrong Command ";
		getchar();
		goto MI;
	}
	Sleep(1000);
	cout << " Confirming Your Order Please Wait ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	cout << "  Order Confirmed ";
	Sleep(500);
	cout << " \n\n\n Thanks For shoppping with us ...";
	cout << " \n Press Any Key To Continue ";
	getchar();


}
void CPUINFO() {
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
CPUI:
	cout << "\t\t               ------- CPUs --------          " << endl << endl << endl;

	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\t     1. " << endl;
	cout << "\t\t     -->   " << CPUn1 << endl;
	cout << "\t\t     Price -->   " << CP1 << endl << endl;
	cout << "\t\t     2. " << endl;
	cout << "\t\t     -->   " << CPUn2 << endl;
	cout << "\t\t     Price -->   " << CP2 << endl << endl;
	cout << "\t\t     3. " << endl;
	cout << "\t\t     -->   " << CPUn3 << endl;
	cout << "\t\t     Price -->   " << CP3 << endl << endl;
	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\tBack - 0 " << endl;


	cout << endl << "\t\t     Enter Your Choice ";
	cin >> cho03;

	if (cho03 == 1)
		FinalPrice = FinalPrice + CP1;
	else if (cho03 == 2)
		FinalPrice = FinalPrice + CP2;
	else if (cho03 == 3)
		FinalPrice = FinalPrice + CP3;
	else if (cho03 == 0)
		return;
	else {
		system("cls");
		cout << " Wrong Command ";
		getchar();
		goto CPUI;
	}

	Sleep(1000);
	cout << " Confirming Your Order Please Wait ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	cout << "  Order Confirmed ";
	Sleep(500);
	cout << " \n\n\n Thanks For shoppping with us ...";
	cout << " \n Press Any Key To Continue ";
	getchar();



}
void GPUINFO() {
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
GPUI:
	cout << "\t\t               ------- GPUs --------          " << endl << endl << endl;

	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\t     1. " << endl;
	cout << "\t\t     -->   " << GPUn1 << endl;
	cout << "\t\t     Price -->   " << GP1 << endl << endl;
	cout << "\t\t     2. " << endl;
	cout << "\t\t     -->   " << GPUn2 << endl;
	cout << "\t\t    Price -->   " << GP2 << endl << endl;
	cout << "\t\t     3. " << endl;
	cout << "\t\t     -->   " << GPUn3 << endl;
	cout << "\t\t     Price -->   " << GP3 << endl << endl;
	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\tBack - 0 " << endl;


	cout << endl << "\t\t     Enter Your Choice ";
	cin >> cho04;

	if (cho04 == 1)
		FinalPrice = FinalPrice + GP1;
	else if (cho04 == 2)
		FinalPrice = FinalPrice + GP2;
	else if (cho04 == 3)
		FinalPrice = FinalPrice + GP3;
	else if (cho04 == 0)
		return;
	else {
		system("cls");
		cout << " Wrong Command ";
		getchar();
		goto GPUI;
	}

	Sleep(1000);
	cout << " Confirming Your Order Please Wait ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	cout << "  Order Confirmed ";
	Sleep(500);
	cout << " \n\n\n Thanks For shoppping with us ...";
	cout << " \n Press Any Key To Continue ";
	getchar();


}
void KeyboardINFO() {
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
KI:
	cout << "\t\t             ------- Keyboards --------          " << endl << endl << endl;

	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\t     1. " << endl;
	cout << "\t\t     -->   " << KeyboardN1 << endl;
	cout << "\t\t     Price -->   " << KP1 << endl << endl;
	cout << "\t\t     2. " << endl;
	cout << "\t\t     -->   " << KeyboardN2 << endl;
	cout << "\t\t     Price -->   " << KP2 << endl << endl;
	cout << "\t\t     3. " << endl;
	cout << "\t\t     -->   " << KeyboardN3 << endl;
	cout << "\t\t     Price -->   " << KP3 << endl << endl;
	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\tBack - 0 " << endl;

	cout << endl << "\t\t     Enter Your Choice ";
	cin >> cho05;

	if (cho05 == 1)
		FinalPrice = FinalPrice + KP1;
	else if (cho05 == 2)
		FinalPrice = FinalPrice + KP2;
	else if (cho05 == 3)
		FinalPrice = FinalPrice + KP3;
	else if (cho05 == 0)
		return;
	else {
		system("cls");
		cout << " Wrong Command ";
		getchar();
		goto KI;
	}

	Sleep(1000);
	cout << " Confirming Your Order Please Wait ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	cout << "  Order Confirmed ";
	Sleep(500);
	cout << " \n\n\n Thanks For shoppping with us ...";
	cout << " \n Press Any Key To Continue ";
	getchar();

}
void HeadphoneINFO() {
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
HI:
	cout << "\t\t   ------- Headphones --------          " << endl << endl << endl;

	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\t     1. " << endl;
	cout << "\t\t     -->   " << HeadphonesN1 << endl;
	cout << "\t\t     Price -->   " << HP1 << endl << endl;
	cout << "\t\t     2. " << endl;
	cout << "\t\t     -->   " << HeadphonesN2 << endl;
	cout << "\t\t     Price -->   " << HP2 << endl << endl;
	cout << "\t\t     3. " << endl;
	cout << "\t\t     -->   " << HeadphonesN3 << endl;
	cout << "\t\t     Price -->   " << HP3 << endl << endl;
	cout << "\t\t-----     -------------------------------   ----- " << endl;
	cout << "\t\tBack - 0 " << endl;

	cout << endl << "\t\t     Enter Your Choice ";
	cin >> cho06;

	if (cho06 == 1)
		FinalPrice = FinalPrice + HP1;
	else if (cho06 == 2)
		FinalPrice = FinalPrice + HP2;
	else if (cho06 == 3)
		FinalPrice = FinalPrice + HP3;
	else if (cho06 == 0)
		return;
	else {
		system("cls");
		cout << " Wrong Command ";
		getchar();
		goto HI;
	}

	Sleep(1000);
	cout << " Confirming Your Order Please Wait ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	cout << "  Order Confirmed ";
	Sleep(500);
	cout << " \n\n\n Thanks For shoppping with us ...";
	cout << " \n Press Any Key To Continue ";
	getchar();


}
// DisplayProductINFO
void ProductList() {

	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	char DoWl;
	do {
		cout << "\n\n";
		cout << "\n\n\t\t ______________________________________________________________________________     ";
		cout << "\n\n\t\t                              Products Available                                    ";
		cout << "\n\n\t\t          ************************************************************             " << endl;
		cout << "\t\t                  1. Laptop(s)                                             " << endl;
		cout << "\t\t                  2. Monitor" << endl;
		cout << "\t\t                  3. CPU" << endl;
		cout << "\t\t                     [Currently Availble]" << endl;
		cout << "\t\t                       3.1 AMD" << endl;
		cout << "\t\t                       3.2 Nvidia" << endl;
		cout << "\t\t                  4. Graphic Card(s)" << endl;
		cout << "\t\t                     [Currently Availble]" << endl;
		cout << "\t\t                       4.1  AMD" << endl;
		cout << "\t\t                       4.2  Nvidia" << endl;
		cout << "\t\t                  5. Keyboard" << endl;
		cout << "\t\t                  6. Headphones" << endl;
		cout << "\n\n\t\t          ************************************************************     ";
		cout << "\n\t\t   Exit - 0" << endl;
		cout << "\n\n\t\t ______________________________________________________________________________ ";
		cout << endl << "\t\t Enter Your choice ";
		cin >> choice02;
		if (choice02 == 1)
			LaptopINFO();
		else if (choice02 == 2)
			MonitorINFO();
		else if (choice02 == 3)
			CPUINFO();
		else if (choice02 == 4)
			GPUINFO();
		else if (choice02 == 5)
			KeyboardINFO();
		else if (choice02 == 6)
			HeadphoneINFO();
		else if (choice02 == 0) {
			exit(0);
		}
		else {
			cout << "\n\n\t\t INVALID INPUT ";
			getchar();
			getchar();
		}

		system("cls");
		Sleep(1000);
		cout << endl << " Do You Want To Continue to Product List ";
		cout << endl << " Press Y for Yes and N for No ";
		cin >> DoWl;
		system("cls");
	} while (DoWl == 'y' || DoWl == 'Y');

}
// Menu02
void CustomerMenu() {
	char DoWl02;
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	do {
		system("cls");
		cout << "\n\n\n";
		cout << "\n\n\t\t   ______________________________________________________________________________    ";
		cout << "\n\n\t\t                               Customer Details                                      ";
		cout << " \n\n\t\t          ************************************************************              " << endl;
		cout << "\n\t\t                  1.1 Display                                                          " << endl;
		cout << " \t\t                  1.2 Append                                                            " << endl;
		cout << " \t\t                  1.3 Search Record                                                     " << endl;
		cout << " \t\t                  1.4 Modify                                                            " << endl;
		cout << " \n\n\t\t          ************************************************************              ";
		cout << " \n\t\t	Exit - 0                                                                          ";
		cout << "\n\n\t\t ______________________________________________________________________________      ";
		cout << endl << "\t\t Enter Your choice ";
		cin >> choice01;

		if (choice01 == 1 || choice01 == 1.1) {
			Display();
		}
		else if (choice01 == 2 || choice01 == 1.2) {
			Append();
		}
		else if (choice01 == 3 || choice01 == 1.3) {
			Search();
		}
		else if (choice01 == 4 || choice01 == 1.4) {
			Modify();
		}
		else if (choice01 == 1 || choice01 == 1.1) {
			Display();
		}
		else if (choice01 == 0) {
			exit(0);
		}
		else {
			cout << "\n\n\t\t INVALID INPUT ";
			getchar();
			getchar();
		}
		system("cls");
		Sleep(400);
		cout << " Do Your Want To Continue To Customer Menu " << endl;
		Sleep(200);
		cout << " Press Y to Continue And N to Continue " << endl;
		cin >> DoWl02;
	} while (DoWl02 == 'y' || DoWl02 == 'Y');

}
// Delete all Record Function
void delF() {

	cout << " Deleting Records ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	ifstream f("Customer.dat");
	ofstream f1("temp.dat");
	remove("Customer.dat");
	rename("temp.dat ", "Customer.dat");
	f.close();
	f1.close();

}
// About
void About() {
	system("cls");
	cout << " Loading ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	system("cls");
	cout << "\n\n";
	cout << " \n\n\n\t\t                     ****** About US ******                                " << endl << endl;
	cout << "\t\t Hey! We are D.S. TechSolutions, Established in 1999                              " << endl;
	cout << "\t\t This Computer Shop offers a wide range of PC products including Laptops, Monitor " << endl;
	cout << "\t\t , CPU, GPU and accessories. Whether it's basic home computer, Business system or " << endl;
	cout << "\t\t Gaming machine we can build it.                                                  " << endl << endl;
	cout << "\t\t We here work for you and get you best deals available on best computer hardware. " << endl;
	cout << "\t\t We hope You will like our service                                                " << endl;
	cout << "\t\t Thanks For Visiting us                                                           " << endl << endl << endl << endl;
	cout << "\t\t                                                           - Team D.S.            "<<endl; // Not Data Structure
	getchar();
	getchar();
}
// Main Function
int main() {
	system("cls");
	Customer c1;
	int z = 0;   char DoWl01;
	Sleep(500);
	cout << " Welcome to DS TechSolutions " << endl << endl << endl;
	Sleep(1500);
	cout << " Please Wait while System is Loading ";
	Sleep(1000);
	cout << ". ";
	Sleep(1000);
	cout << ". ";
	Sleep(1000);
	cout << ". " << endl;
start:
	system("cls");
	cout << " \n\n\n\t\t\t  			    Computer Shop Project                           " << endl << endl << endl;

	cout << "\t\t\t ________________________________________________________________________" << endl << endl << endl;
	cout << "\t\t\t                            Admin Panel                                  " << endl << endl << endl;
	cout << "\t\t\t Enter Login Details                                                     " << endl << endl;
	cout << "\t\t\t       Username - ADMIN                                                  " << endl;
	cout << "\t\t\t       Password - ";
	GetPASSWORD();
	Sleep(1000);
	if (strcmp(Password, "ds12345") == 0)
	{
		cout << endl << " Welcome SIR ," << endl;
		Sleep(300);
		system("cls");
		Sleep(500);
	}
	else
	{

		z++;
		cout << endl;
		if (z == 3) {
			cout << " System was unable to recognise you . Exiting Program " << endl;
			exit(0);
		}
		Sleep(200);
		cout << " Wrong Password ";
		Sleep(200);
		goto start;
	}
	do {
		//	MainMenu:
		cout << "\n \t\t                                Welcome                                               ";
		cout << "\n\n\t\t   ______________________________________________________________________________    ";
		cout << "\n\n\t\t                                 Menu                                                ";
		cout << " \n\n\t\t            ************************************************************            " << endl;
		cout << "\t\t      1. [ NEW ] Customer Details                                                        " << endl;
		cout << "\t\t            1.1 Display                                                                   " << endl;
		cout << "\t\t            1.2 Append                                                                   " << endl;
		cout << "\t\t            1.3 Search Record                                                            " << endl;
		cout << "\t\t            1.4 Modify                                                                   " << endl;
		cout << "\t\t       2. Product List                                                                   " << endl;
		cout << "\t\t       3. Delete All Customer Data                                                       " << endl;
		cout << "\t\t       4. Billing Information(MEMO)                                                      " << endl;
		cout << "\t\t       5. About                                                                          " << endl;
		cout << " \n\n\t\t             ************************************************************           ";
		cout << " \n\t\t   	Exit - 0                                                                          ";
		cout << "\n\n\t\t    ______________________________________________________________________________   ";
		cout << endl << endl << "\t\t    Enter Your choice - ";
		cin >> choice;
		if (choice == 1)
			CustomerMenu();
		else if (choice == 2)
			ProductList();
		else if (choice == 3)
			delF();
		else if (choice == 4)
			c1.BillIFNO();
		else if (choice == 5)
			About();
		else if (choice == 0)
			exit(0);
		else {
			cout << "\n\n\t\t INVALID INPUT ";
			getchar();
			getchar();
		}
		system("cls");
		Sleep(500);
		cout << endl << " Do You Want To Continue to Main Menu";
		cout << endl << " Press Y for Yes and N for No ";
		cin >> DoWl01;
		system("cls");
	} while (DoWl01 == 'y' || DoWl01 == 'Y');

	return 0;
}

/////////////////////////////
//////  End Of Project  /////
/////////////////////////////