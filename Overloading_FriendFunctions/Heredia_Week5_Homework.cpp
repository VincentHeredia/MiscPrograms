// File Name: Heredia_Week5_Homework
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: JellyBean class, I/O streams.
// Last Changed: Sep, 23, 2012

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


class JellyBean
{
	friend ostream& operator << (ostream& outputStream, const JellyBean jellyBeanOut);//Overloaded output operator
	friend istream& operator >> (istream& outputStream, JellyBean& jellyBeanIn);//Overloaded input operator
	friend JellyBean operator + (const JellyBean JellyBeanPlus1, const JellyBean JellyBeanPlus2);//Overloaded plus operator
	friend JellyBean operator - (const JellyBean JellyBeanMinus1, const JellyBean JellyBeanMinus2);//Overloaded minus operator
	friend JellyBean operator - (const JellyBean JellyBeanMinus);//Overloaded minus operator with just one parameter
	friend JellyBean operator * (const JellyBean JellyBeanTimes1, const JellyBean JellyBeanTimes2);//Overloaded times operator
	friend JellyBean operator / (const JellyBean JellyBeanDivide1, const JellyBean JellyBeanDivide2);//Overloaded divide operator
	friend bool operator == (const JellyBean& JellyBeanEqual1, const JellyBean& JellyBeanEqual2);//Overloaded equals comparison operator
	friend bool operator < (const JellyBean& JellyBeanLess1, const JellyBean& JellyBeanLess2);//Overloaded less than comparison operator
	friend bool operator > (const JellyBean& JellyBeanGreat1, const JellyBean& JellyBeanGreat2);//Overloaded greater than comparison operator

public:
	JellyBean();//Default constructor
	JellyBean(int);//1 parameter constructor
	JellyBean(string, string, int);//3 parameter constructor

private:
	string flavor;//JellyBean flavor, color, quantity
	string color;
	int quantity;

};//End of JellyBean Class

//------------------------------------------------------------
//Constructors

JellyBean::JellyBean()//Default constructor
{
	flavor = "Null";
	color = "Null";
	quantity = 0;

}//end of default constructor

JellyBean::JellyBean(int newQuantity)//Constructor with just the int parameter
{
	flavor = "Null";
	color = "Null";
	quantity = newQuantity;

}//end of 1 parameter constructor

JellyBean::JellyBean(string nflavor, string ncolor, int nQuantity)//constructor with all the parameters
{
	flavor = nflavor;
	color = ncolor;
	quantity = nQuantity;

}//end if 3 parameter constructor

//End of constructors
//------------------------------------------------------------

//------------------------------------------------------------
//Output/input

//Purpose: Ablitity to output a class with the << operator
//Parameters: JellyBean Class
//Returns: outputStream
ostream& operator << (ostream& outputStream, const JellyBean jellyBeanOut)
{

	outputStream << jellyBeanOut.quantity << " " << jellyBeanOut.flavor << " " << jellyBeanOut.color << endl;

	/*
	cout << "Flavor: " << jellyBeanOut.flavor << endl//Simply outputs the classes parameters
		 << "Color: " << jellyBeanOut.color << endl
		 << "Quantity: " << jellyBeanOut.quantity << endl;
	*/

	return outputStream;
}//End of operator <<

//Purpose: Ablitity to input parameters to a class with the >> operator
//Parameters: JellyBean Class
//Returns: inputStream
istream& operator >> (istream& inputStream, JellyBean& jellyBeanIn)
{

	inputStream >> jellyBeanIn.quantity >> jellyBeanIn.flavor >> jellyBeanIn.color;

	/*
	cout << "Input the flavor: ";
	inputStream >> jellyBeanIn.flavor;//Users input for flavor
	cout << endl
	     << "Input the Color: ";
	inputStream >> jellyBeanIn.color;//Users input for color
	cout << endl
	     << "Input the Quantity: ";
	inputStream >> jellyBeanIn.quantity;//Users input for quantity
	cout << "\n\n"
		 << "Your input was...\n"
		 << "Flavor: " << jellyBeanIn.flavor << " "//Restates the input so the user can see
		 << "Color: " << jellyBeanIn.color << " "
		 << "Quantity: " << jellyBeanIn.quantity << "\n\n";
	*/

	return inputStream;
}//End of operator >>

//End of Output/input
//------------------------------------------------------------

//------------------------------------------------------------
//+, - , *, / operators

//Purpose: Ability to add two classes together
//Parameters: 2 JellyBean classes
//Returns: The two classes values added together
JellyBean operator + (const JellyBean JellyBeanPlus1, const JellyBean JellyBeanPlus2)
{
		return JellyBean( JellyBeanPlus1.flavor + " " + JellyBeanPlus2.flavor, 
						  JellyBeanPlus1.color + " " + JellyBeanPlus2.color,
						  JellyBeanPlus1.quantity + JellyBeanPlus2.quantity );
}//End of + operator

//Purpose: Ability to subtract two classes
//Parameters: 2 JellyBean classes
//Returns: Two classes subtracted from each other
JellyBean operator - (const JellyBean JellyBeanMinus1, const JellyBean JellyBeanMinus2)
{
	return JellyBean( JellyBeanMinus1.flavor + " minus " + JellyBeanMinus2.flavor, 
					  JellyBeanMinus1.color + " minus " + JellyBeanMinus2.color,
					  JellyBeanMinus1.quantity - JellyBeanMinus2.quantity );
}//end of 2 parameter - operator

//Purpose: Ability to change the sign of a class
//Parameters: JellyBean class
//Returns: All the values of the class with "minus" in front of them
JellyBean operator - (const JellyBean JellyBeanMinus)
{
	return JellyBean( "Minus " + JellyBeanMinus.flavor, 
					  "Minus " + JellyBeanMinus.color,
					  -JellyBeanMinus.quantity );
}//End of 1 parameter - operator

//Purpose: Ability to times two classes together
//Parameters: 2 JellyBean classes
//Returns: The two classes times together
JellyBean operator * (const JellyBean JellyBeanTimes1, const JellyBean JellyBeanTimes2)
{
	return JellyBean( JellyBeanTimes1.flavor + " times " + JellyBeanTimes2.flavor, 
					  JellyBeanTimes1.color + " times " + JellyBeanTimes2.color,
					  JellyBeanTimes1.quantity * JellyBeanTimes2.quantity );
 }//End of * operator

//Purpose: Ability to divide a class by another
//Parameters: 2 JellyBean classes
//Returns: The class divided by the other
JellyBean operator / (const JellyBean JellyBeanDivide1, const JellyBean JellyBeanDivide2)
{
	if(JellyBeanDivide2.quantity == 0) //makes sure quantity isnt being divided by 0
	{
		cout << "Cannot divide by 0\nExiting Program...\n\n";//if being divided by 0 the program is exited
		exit(1);
	}
	else
	{
		return JellyBean( JellyBeanDivide1.flavor + " divided by " + JellyBeanDivide2.flavor, 
						  JellyBeanDivide1.color + " divided by " + JellyBeanDivide2.color,
						  JellyBeanDivide1.quantity / JellyBeanDivide2.quantity );
	}
 }//End of / operator

//End of +, - , *, / operators
//------------------------------------------------------------

//------------------------------------------------------------
// ==, <, > operators

//Purpose: Ability to use the == operator to compair the classes
//Parameters: 2 JellyBean classes
//Returns: True or false as a boolean
bool operator == (const JellyBean& JellyBeanEqual1, const JellyBean& JellyBeanEqual2)
{
	if (JellyBeanEqual1.flavor == JellyBeanEqual2.flavor&& //Test all the values of the JellyBean class to see if they are equal
		JellyBeanEqual1.color == JellyBeanEqual2.color&&
		JellyBeanEqual1.quantity == JellyBeanEqual2.quantity)
	{
		return true;
	}
	else 
	{
		return false;
	}
}//End of == operator

//Purpose: Ability to use the < operator to compair the classes
//Parameters: 2 JellyBean classes
//Returns: True or false as a boolean
bool operator < (const JellyBean& JellyBeanLess1, const JellyBean& JellyBeanLess2)
{
	if (JellyBeanLess1.quantity < JellyBeanLess2.quantity)//Only test the quantity of the JellyBean class
	{
		return true;
	}
	else 
	{
		return false;
	}
}//End of < operator

//Purpose: Ability to use the > operator to compair the classes
//Parameters: 2 JellyBean classes
//Returns: True or false as a boolean
bool operator > (const JellyBean& JellyBeanGreat1, const JellyBean& JellyBeanGreat2)
{
	if (JellyBeanGreat1.quantity > JellyBeanGreat2.quantity)//Only test the quantity of the JellyBean class
	{
		return true;
	}
	else 
	{
		return false;
	}
}//End of > operator

//End of ==, <, > operators
//------------------------------------------------------------

//------------------------------------------------------------
// I/O stream functions

//Purpose: Makes a output file called "output.txt" that holds JellyBean classes
//Parameters: JellyBean class
//Returns: null
void makeFile(JellyBean JellyFileOut)
{

	ofstream fout;
	fout.open("output.txt", ios::app);//creates the file if it doesnt exsist

	if(fout.fail())
	{
		//Checks if file opens, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}

	fout << JellyFileOut;//Writes the class into the file using the << overload

	fout.close();

	cout << JellyFileOut;//shows the class on the screen
}

//Purpose: Writes a JellyBean class into a file called "jellyBeans.txt" (used by the function writeJellyBeans)
//Parameters: JellyBean class
//Returns: null
void writeToFile(JellyBean JellyFileOut)
{
	ofstream JellyOut;
	JellyOut.open("jellyBeans.txt", ios::app);//Opens a new text file

	if(JellyOut.fail())
	{
		//the file did not open, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}

	JellyOut << fixed << setw(15) << setprecision(2) << JellyFileOut;//Formats the output

	JellyOut.close();

}

//Purpose: Opens output.txt and uses the writeToFile function to rewrite the values in a cleaner format
//Parameters: null
//Returns: null
void writeJellyBeans()
{
	ifstream fin;
	fin.open("output.txt");

	if (fin.fail())//the file did not open, exits program if the file doesnt open
	{	
		cout << "File open failed.\n";	exit(1);
	}

	JellyBean InputJelly;//Temp class to hold the values

	while(fin >> InputJelly)//checks to see if there is a another line to the file
	{
		cout << fixed << setw(8) << setprecision(2) << InputJelly; //Fixes the output to line up on the decimals
		writeToFile(InputJelly);//Uses the writeToFile to output a the class to the file jellyBeans.txt
	}

	fin.close();
}

//Purpose: Opens up output.txt and only writes it to the screen
//Parameters: null
//Returns: null
void writeJellyBeansToScreen()
{
	ifstream fin;
	fin.open("output.txt");

	if (fin.fail())//the file did not open, exits program if the file doesnt open
	{	
		cout << "File open failed.\n";	exit(1);
	}

	JellyBean InputJelly;//Temp class to hold the values

	while(fin >> InputJelly)//checks to see if there is a another line to the file
	{
		cout << fixed << setw(8) << setprecision(2) << InputJelly; //Fixes the output to line up on the decimals
	}

	fin.close();
}
// End of I/O stream functions
//------------------------------------------------------------

int main()//Runs the program
{
	//------------------------------------------------------------
	// Write to a file and read from a file test (New Program for week 5)

	/*
	JellyBean JBCherry("Cherry", "Purple", 2030);
	JellyBean JBApple("Apple", "Green", 1);
	JellyBean JBFudge("Fudge", "Blue", 50);
	JellyBean JBPeach("Peach", "Red", 100);

	makeFile(JBCherry);
	makeFile(JBApple);
	makeFile(JBFudge);
	makeFile(JBPeach);
	cout << "\nI expect to see the screen output in output.txt\n";
	*/

	/*
	writeJellyBeans();
	cout << "\nI expect the values shown on the screen to be in the file jellyBeans.txt\n";
	*/

	//
	//------------------------------------------------------------

	//------------------------------------------------------------
	//cout Test
	/* //Testing code is commented out so that the output isnt overwhelming

	JellyBean JBBanana;//Default constructor
	JellyBean JBPineapple(10);//1 parameter constructor
	JellyBean JBCherry("Cherry", "Purple", 20);//3 parameter constructor

	cout << "Making JellyBeans...\n\n"
		 << "Expected output [ Flavor: Null, Color: Null, Quantity: 0 ]\n\n"
		 << JBBanana << endl
		 << "Expected output [ Flavor: Null, Color: Null, Quantity: 10 ]\n\n"
		 << JBPineapple << endl
		 << "Expected output [ Flavor: Cherry, Color: Purple, Quantity: 20 ]\n\n"
		 << JBCherry << endl;

	*/
	//End of cout Test
	//------------------------------------------------------------

	//------------------------------------------------------------
	//cin Test
	/*

	JellyBean JBBanana;
	cin >> JBBanana;
	cout << "Expected output [ Flavor: <Input>, Color: <Input>, Quantity: <Input> ]\n\n"
		 << JBBanana;

	*/
	//End of cin Test
	//------------------------------------------------------------

	//------------------------------------------------------------
	// + operator test
	/*

	JellyBean JBPlusTest1("Cherry", "Purple", 20);
	JellyBean JBPlusTest2("Apple", "Green", 10);
	JellyBean JBPlusTest3("Dirt", "Brown", 5);

	cout << "\nOutputing Cherry and Apple JellyBean\n\n"
		 << JBPlusTest1 << endl
		 << JBPlusTest2 << endl
		 << "Ajusting Values...\n\n" 
		 << "Expected output [ Flavor: Cherry Apple, Color: Purple Green, Quantity: 30 ] \n\n";

	JBPlusTest1 = JBPlusTest1 + JBPlusTest2;

	cout << JBPlusTest1 << endl;

	cout << "Outputting Dirt JellyBean...\n\n"
		 << JBPlusTest3 << endl
		 << "Ajusting Values...\n\n" 
		 << "Expected output [ Flavor: Dirt null, Color: Brown null, Quantity: 30 ] \n\n";
	JBPlusTest3 = JBPlusTest3 + 25;

	cout << JBPlusTest3;

	*/
	//end of + operator test
	//------------------------------------------------------------

	//------------------------------------------------------------
	// - operator test
	/*

	JellyBean JBMinusTest1("Coconut", "Blue", 5);
	JellyBean JBMinusTest2("Bluebarry", "Pink", 10);
	JellyBean JBMinusTest3("Rock", "White", 1);

	cout << "Outputting Coconut and Bluebarry JellyBeans...\n\n"
		 << JBMinusTest1 << endl
		 << JBMinusTest2 << endl
		 << "Ajusting Values...\n\n" 
		 << "Expected output...\n"
		 << "[ Flavor: Coconut minus Bluebarry, Color: Blye Pink, Quantity: -5 ] \n\n";

	JBMinusTest1 = JBMinusTest1 - JBMinusTest2;

	cout << JBMinusTest1 << endl;

	cout << "Outputting Rock JellyBean\n\n"
		 << JBMinusTest3 << endl
		 << "Flipping Signs...\n\n"
		 << "Expected output...\n"
		 << "[ Flavor: Minus Rock, Color: Minus White, Quantity: -1] \n\n";

	JBMinusTest3 = -JBMinusTest3;

	cout << JBMinusTest3 << endl;

	*/
	//end of - operator test
	//------------------------------------------------------------

	//------------------------------------------------------------
	// * operator test
	/*

	JellyBean JBTimesTest1("Fudge", "Blue", 20);
	JellyBean JBTimesTest2("Peach", "Red", 10);
	JellyBean JBTimesTest3("Grape", "Brown", 5);

	cout << "\nOutputing Fudge and Peach JellyBean\n\n"
		 << JBTimesTest1 << endl
		 << JBTimesTest2 << endl
		 << "Ajusting Values...\n\n" 
		 << "Expected output...\n[ Flavor: Fudge times Peach, Color: Blue times Red, Quantity: 200 ] \n\n";

	JBTimesTest1 = JBTimesTest1 * JBTimesTest2;

	cout << JBTimesTest1 << endl;

	cout << "Outputting Grape JellyBean...\n\n"
		 << JBTimesTest3 << endl
		 << "Ajusting Values...\n\n" 
		 << "Expected output...\n[ Flavor: Grape times null, Color: Brown times null, Quantity: 125 ] \n\n";
	JBTimesTest3 = JBTimesTest3 * 25;
	
	cout << JBTimesTest3;

	*/
	//End of * operator test
	//------------------------------------------------------------

	//------------------------------------------------------------
	// / operator test
	/*

	JellyBean JBDivideTest1("Lime", "Yellow", 20);
	JellyBean JBDivideTest2("Lemon", "Green", 10);
	JellyBean JBDivideTest3("Charcoal", "Black", 5);

	cout << "\nOutputing Lime and Lemon JellyBean\n\n"
		 << JBDivideTest1 << endl
		 << JBDivideTest2 << endl
		 << "Ajusting Values...\n\n" 
		 << "Expected output...\n[ Flavor: Lime divided by Lemon, Color: Yellow divided by Green, Quantity: 2 ] \n\n";

	JBDivideTest1 = JBDivideTest1 / JBDivideTest2;

	cout << JBDivideTest1 << endl;

	cout << "Outputting Charcoal JellyBean...\n\n"
		 << JBDivideTest3 << endl
		 << "Ajusting Values...\n\n" 
		 << "Expected output...\n[ Flavor: null divided by Charcoal, Color: null divided by Black, Quantity: 6 ] \n\n";
	JBDivideTest3 = 30 / JBDivideTest3;

	cout << JBDivideTest3 << "\n"
		 << "Dividing by 0...\n\n";
		 JBDivideTest3 = JBDivideTest3 / 0;

	*/
	//End of  / operator test
	//------------------------------------------------------------

	//------------------------------------------------------------
	// == operator test
	/*

	bool testEqual = false;
	JellyBean JBEqualTest1("Banana", "Yellow", 20);
	JellyBean JBEqualTest2("Banana", "Yellow", 20);
	JellyBean JBEqualTest3("Pie", "Blue", 10);
	
	cout << "Outputting the Two Banana JellyBeans...\n\n"
		 << JBEqualTest1 << endl
		 << JBEqualTest2 << endl
		 << "Testing if they are the same...\n\n";
	if (JBEqualTest1 == JBEqualTest2)
	{
		testEqual = true;
	}
	else
	{
		testEqual = false;
	}

	cout << "(1 if they are the same 0 if they are not, output should be 1): " << testEqual << "\n\n";

	cout << "Outputting Pie JellyBean...\n\n"
		 << JBEqualTest3 << endl
		 << "Testing they are not the same as Banana JellyBean...\n\n";

	if (JBEqualTest1 == JBEqualTest3)
	{
		testEqual = true;
	}
	else
	{
		testEqual = false;
	}

	cout << "(1 if they are the same 0 if they are not, output should be 0): " << testEqual << "\n\n";

	*/
	//End of  == operator test
	//------------------------------------------------------------

	//------------------------------------------------------------
	// < operator test
	/*

	bool testEqual = false;
	JellyBean JBLessTest1("Icecream", "Blue", 10);
	JellyBean JBLessTest2("Peanut", "Yellow", 20);

	cout << "Outputting Icecream and Peanut JellyBeans...\n\n"
		 << JBLessTest1 << endl
		 << JBLessTest2 << endl
		 << "Testing if Icecream is < than Peanut\n\n";

	if (JBLessTest1 < JBLessTest2)
	{
		testEqual = true;
	}
	else
	{
		testEqual = false;
	}

	cout << "(1 if Icecream is lesser, 0 is not lesser, output should be 1): " << testEqual << "\n\n"
		 << "Testing opposite\n\n";

	if (JBLessTest2 < JBLessTest1)
	{
		testEqual = true;
	}
	else
	{
		testEqual = false;
	}
	
	cout << "(1 if Peanut is lesser, 0 is not lesser, output should be 0): " << testEqual << "\n\n";

	*/
	//End of  < operator test
	//------------------------------------------------------------

	//------------------------------------------------------------
	// > operator test
	/*

	bool testEqual = false;
	JellyBean JBGreatTest1("Icecream", "Blue", 20);
	JellyBean JBGreatTest2("Peanut", "Yellow", 10);

	cout << "Outputting Icecream and Peanut JellyBeans...\n\n"
		 << JBGreatTest1 << endl
		 << JBGreatTest2 << endl
		 << "Testing if Icecream is > than Peanut\n\n";

	if (JBGreatTest1 > JBGreatTest2)
	{
		testEqual = true;
	}
	else
	{
		testEqual = false;
	}

	cout << "(1 if Icecream is Greater, 0 is not Greater, output should be 1): " << testEqual << "\n\n"
		 << "Testing opposite\n\n";

	if (JBGreatTest2 > JBGreatTest1)
	{
		testEqual = true;
	}
	else
	{
		testEqual = false;
	}
	
	cout << "(1 if Peanut is Greater, 0 is not Greater, output should be 0): " << testEqual << "\n\n";

	*/
	//End of > operator test
	//------------------------------------------------------------

	return 1;
}//End of int main