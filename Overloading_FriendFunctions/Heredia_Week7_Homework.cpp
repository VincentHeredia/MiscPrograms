// File Name: Heredia_Week7_Homework
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Quiz class with functions to run a quiz.
// Last Changed: Oct, 7, 2012

#include <iostream>//General output
#include <string> //Output strings
#include <fstream>//Write to a file
#include <algorithm>//For converting a string to lower case
using namespace std;

class Quiz
{
	friend istream& operator >> (istream& outputStream, Quiz& quizIn);
	friend ostream& operator << (ostream& outputStream, const Quiz quizOut);//For outputting just the values

public:
	Quiz();//Default constructor
	Quiz(string Ques, string answ, int wor);//3 parameter Constructor
	string getQuestion();//gives back the question
	string getAnswer();//gives back the answer
	int getWorth();//gives back the worth of the question
	void setQuestion(string newQuestion);//sets the question
	void setAnswer(string newAnswer);//sets the answer
	void setWorth(int newWorth);//Sets how much the question is worth

private:
	string question;//The question
	string answer;//The answer to the question
	int worth;//How much the question is worth

};

Quiz::Quiz()//Default constructor
{
	question = "Null";//Values all set to Null
	answer = "Null";
	worth = 0;

}
Quiz::Quiz(string ques, string answ, int wor)//3 parameter constuctor
{
	question = ques;
	answer = answ;
	worth = wor;

}

//Purpose: Basic get function for the question
//Parameters: null
//Returns: string
string Quiz::getQuestion()
{
	return question;
}
//Purpose: Basic get function for the answer
//Parameters: null
//Returns: string
string Quiz::getAnswer()
{
	return answer;
}
//Purpose: Basic get function for the worth of the question
//Parameters: null
//Returns: int
int Quiz::getWorth()
{
	return worth;
}

//Purpose: Basic set function for the question
//Parameters: string of the new question
//Returns: null
void Quiz::setQuestion(string newQuestion)
{
	question = newQuestion;
	return;
}
//Purpose: Basic set function for the answer
//Parameters: string of the new answer
//Returns: null
void Quiz::setAnswer(string newAnswer)
{
	answer = newAnswer;
	return;
}
//Purpose: Basic set function for the worth
//Parameters: int of the new worth
//Returns: null
void Quiz::setWorth(int newWorth)
{
	worth = newWorth;
	return;
}

//Purpose: output << operator overload for the class
//Parameters: the quiz class that is going to be outputted
//Returns: outputStream
ostream& operator << (ostream& outputStream, const Quiz quizOut)
{
	outputStream << quizOut.question << " " << quizOut.answer << " " << quizOut.worth << endl;
	return outputStream;
}//End of operator <<

//Purpose: input >> operator overload for the class
//Parameters: the quiz class that is going to be outputted
//Returns: inputStream
istream& operator >> (istream& inputStream, Quiz& quizIn)
{
	inputStream >> quizIn.question >> quizIn.answer >> quizIn.worth;
	return inputStream;
}//End of operator >>

//Purpose: used to turn a string to all lowercase
//Parameters: int of the character
//Returns: lowercase of the character
int lower_case ( int c )//Needed to connvert strings to lowercase
{
  return tolower ( c );
}


//-------------------------------------------------------------------------------------------
//Quiz Functions

//Purpose: Runs the quiz
//Parameters: the quiz array (must be a pointer), int size (size of the array/quiz)
//Returns: null
void runQuiz(Quiz quizToRun[], int size)
{
	int userScore = 0;//How much the user has won
	bool begin = true;//Used to give the beginning message of the quiz

	for(int i = 0; i < size; i++)
	{
		if (begin == true)//Gives the beginning message
		{
		cout << "The quiz has started!\n"
			 << "(Answers will only be one word or number)\n\n"
		     << "First Question..\n\n";
		begin = false;
		}
		else//Gives the next question message
		{
		cout << "Next Question..\n\n";
		}

		string userAnswer = "Null";
		cout << quizToRun[i].getQuestion() << "?" << endl << "Your Answer: ";//gives the question
		cin >> userAnswer;//The users answer can be all upper or lower case
		cout << endl;

		string test1 = userAnswer;//Loads the values into temp strings to compair them
		string test2 = quizToRun[i].getAnswer();
		transform( test1.begin(), test1.end(), test1.begin(), lower_case );//Converts userAnswer to lowercase
		transform( test2.begin(), test2.end(), test2.begin(), lower_case );//Converts the answer to lowercase

		//Compairs the answer and the users answer
		if (test1 == test2)//if the user gets it right
		{
			userScore = userScore + quizToRun[i].getWorth();//Adds to the users score
			cout << "Correct! You have won: $" << userScore << " So far!" << endl << endl;//Shows the users score
		}
		else//if the user gets it wrong
		{
			cout << "Wrong! The correct answer was: " << quizToRun[i].getAnswer() << endl//Shows the user the right answer
				 << "You have won: $" << userScore << " So far!" << endl << endl;//Shows the users score
		}
		
	}

	cout << "Congratulations! You have Won: $" << userScore << "!" << endl << endl//End of the quiz message
		 << "Thank you for playing...\n\n";

	return;
}

//Purpose: Gives the size of the quiz by inspecting the "quizworth.txt" file
//Parameters: null
//Returns: int size (the size of the quiz)
int getSize()
{
	ifstream fin;
	fin.open("quizworth.txt");
	if (fin.fail())//the file did not open, exits program if the file doesnt open
	{	
		cout << "File open failed.\n";	exit(1);
	}

	int inputWorth;
	int size = 0;//Number represents the file size
	while(fin >> inputWorth)//checks to see how big the file is
	{
		size++;
	}
	fin.close();//Closes it so the pointer can be reset

	return size;//returns the size of the file
}

//Purpose: Makes files that are used to store the questions, answers, and worth (3 in total)
//Parameters: Quiz class that the user wishes to store
//Returns: null
void makeQuizFile(Quiz QuizFileOut)
{
	ofstream foutQ;
	ofstream foutA;
	ofstream foutW;
	foutQ.open("quizquestions.txt", ios::app);
	foutA.open("quizanswers.txt", ios::app);
	foutW.open("quizworth.txt", ios::app);

	if(foutQ.fail())
	{
		//Checks if file opens, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}
	if(foutA.fail())
	{
		//Checks if file opens, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}
	if(foutW.fail())
	{
		//Checks if file opens, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}

	foutQ << QuizFileOut.getQuestion() << endl;//Writes the parameters into a file using the << overload
	foutA << QuizFileOut.getAnswer() << endl;//there are 3 files for each of the values
	foutW << QuizFileOut.getWorth() << endl;

	foutQ.close();
	foutA.close();
	foutW.close();
	return;
}

//Purpose: Lets the user input questions into the quiz, the questions are stored in files
//Parameters: null
//Returns: null
void userInputQuestions()
{
	bool done = false;//Used to break the while loop

	while (done == false)
	{
		string choice = "Null";
		cout << "Would you like to add questions to the quiz?\n";//Displays options
		cout << "(1 for yes, 0 for no)\n" << "Input: ";
		cin >> choice;//Users choice
		cin.ignore(1000, '\n');//Used to stop cin from messing with getline
		cout << endl;

		if (choice == "1")
		{
			string userQuestion = "";
			//Lets the user input a question
			cout << "Input a question\n(Do not input punctuation, tell the user if they need to input a number)\n" << "Input: ";
			getline(cin, userQuestion);
			cout << "\nYour question is: " << userQuestion << endl << endl;

			string userAnswer = "";
			//Lets the user input an answer
			cout << "Input a answer (Do not input punctuation)\n" << "Input: ";
			getline(cin, userAnswer);
			cout << "\nYour answer is: " << userAnswer << endl << endl;

			int userWorth = 0;
			//Lets the user input how much the question is worth
			cout << "Input how much the question is worth\n(Do not input decimals, Should be worth no more than 1000)\n" << "Input: ";;
			cin >> userWorth;
			cout << "\nThis question is worth: " << userWorth << endl << endl;
			//Loads the users values into a class
			Quiz userQuiz(userQuestion, userAnswer, userWorth);
			makeQuizFile(userQuiz);//Loads the users question into a file
		}
		else if (choice == "0")
		{
			done = true;//Breaks the while loop
		}
		else 
		{
			cout << "Invalid input...\n";// if the user inputs something besides 1 or 0
		}
	}

	return;
}

//Purpose: creates the array quiz by reading in the questions, answers, and worth
//Parameters: The quiz array (must be a pointer), int size (size of the array/quiz)
//Returns: null
void createArray(Quiz arrayToMake[], int size)
{
	cout << "Amount of Questions: " <<  size << "\n";//for checking size of the file

	ifstream finQ;
	ifstream finA;
	ifstream finW;
	finQ.open("quizquestions.txt");
	finA.open("quizanswers.txt");
	finW.open("quizworth.txt");

	if(finQ.fail())
	{
		//Checks if file opens, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}
	if(finA.fail())
	{
		//Checks if file opens, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}
	if(finW.fail())
	{
		//Checks if file opens, exits program if the file doesnt open
		cout << "the file did not open" << endl;
		exit(1);
	}

	string tempQuestions = "";
	string tempAnswers = "";//Temp parameters to hold the files values
	int tempWorth = 0;

	for(int i = 0; i < size; i++)//Loads the jelly beans into an array
	{
		getline(finQ, tempQuestions);//uses getline to read in the files question
		getline(finA, tempAnswers);//uses getline for the answers
		finW >> tempWorth;//reads in the worth value
		arrayToMake[i].setQuestion(tempQuestions);//Loads the file input into the array
		arrayToMake[i].setAnswer(tempAnswers);	  //using the get functions
		arrayToMake[i].setWorth(tempWorth);
	}
	finQ.close();
	finA.close();
	finW.close();
	
	return;
}//end of createArray

//Purpose: Clears the files that are used to store the questions, answers, and worth so that
//		   the program reuse the files next time the program is run
//Parameters: null
//Returns: null
void clearFile()
{
	ofstream foutQ;
	ofstream foutA;
	ofstream foutW;

	foutQ.open("quizquestions.txt", ios::trunc);
	foutA.open("quizanswers.txt", ios::trunc);//ios::trunc clears the files
	foutW.open("quizworth.txt", ios::trunc);

	foutQ.close();
	foutA.close();
	foutW.close();
}

//Quiz Functions
//-------------------------------------------------------------------------------------------

//Purpose: Runs the program... First it creates 5 questions, inputs the 5 questions into files, lets the user
//		   input their own questions, gets the size of the quiz, creates the array for the quiz, 
//		   runs the quiz, finally clears the external files so that they can be used next time the program is run.
//Parameters: null
//Returns: int 0
int main()
{
	clearFile();//clears the quiz files to make sure nothing is in them
	Quiz questionOne("What color is a Banana", "Yellow", 1); // 5 questions that are hard coded into the program
	Quiz questionTwo("What is the 5th root of 130,691,232 (Hint: Answer to everything, input a number)", "42", 42);
	Quiz questionThree("Was the last question Hard", "Depends", 100);
	Quiz questionFour("Is Hippopotomonstrosesquipedaliophobia the fear of long words", "Yes", 100);
	Quiz questionFive("Does this question count as a question", "Yes", 100);

	makeQuizFile(questionOne);//makeQuizFile stores the questions, answers, and worth into 3 files
	makeQuizFile(questionTwo);//so that they can be used to create the array later
	makeQuizFile(questionThree);
	makeQuizFile(questionFour);
	makeQuizFile(questionFive);
	userInputQuestions();//lets the user input their own questions into the quiz

	int size = getSize();//gets the size of the quiz

	typedef Quiz* QuizPtr;
	QuizPtr QuizArrayPtr;//makes a class array pointer
	QuizArrayPtr = new Quiz[size];//uses the size of the quiz to create the array

	createArray(QuizArrayPtr, size);//loads the array values with the quiz questions

	runQuiz(QuizArrayPtr, size);//runs the quiz

	return 0;
}