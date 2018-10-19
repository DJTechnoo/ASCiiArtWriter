#include<iostream>
#include<cstring>
#include<thread>
#include<chrono>
#include<Windows.h>
#include<fstream>
#include<vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;


////////////////-->    CONSTS  <--////////////////////////
const int MAXLINES = 6;			// ASCII art stacked horizontal lines per letter
const int MAXMESSAGE = 5;		// Number of message lines
const int STRLEN = 100;			// message line length
const int INPUTLEN = 200;		// Input Limit
const int ASCIIVALUETOALPHABETINDEX = 97;	/*	Make this happen: foo['a'-97] == foo[0]
											a - 97  =  0.  
											b - 97  = 1 
											etc...
											*/


////////////////-->    STRUCTS  <--////////////////////////
struct Messages{
	char messages[MAXMESSAGE][STRLEN] = {
		{"hey wassup"},
		{"this"},
		{"is"},
		{"a"},
		{"test"}
	};
};


struct Input {
	char in[INPUTLEN];
};



		// letter  |    line of letter  | char of line
char alphabet[26]		[MAXLINES]			[9] = {
	{	// A
		{ "    a   " },
		{ "   a a  " },
		{ "  a   a " },
		{ "  aaaaa " },
		{ "  a   a " },
		{ "  a   a " }

	},
	{	// B
		{ " bbbbb  " },
		{ " bb   b " },
		{ " bbbbb  " },
		{ " bbbbb  " },
		{ " bb   b " },
		{ " bbbbbb " }
	},
	{	// C
		{ " cccccc " },
		{ " cc     " },
		{ " cc     " },
		{ " cc     " },
		{ " cc     " },
		{ " cccccc " }
	},
	{	// D
		{ " ddddd  " },
		{ " dd   d " },
		{ " dd    d" },
		{ " dd    d" },
		{ " dd    d" },
		{ " ddddddd" }
	},
	{	// E
		{ " eeeeee " },
		{ " eee    " },
		{ " eee    " },
		{ " eeeeee " },
		{ " eee    " },
		{ " eeeeee " }
	},
	{	// F
		{ " ffffff " },
		{ " fff    "},
		{ " ffffff " },
		{ " fff    " },
		{ " fff    " },
		{ " fff    " }
	},
	{	// G
		{ " ggggggg" },
		{ " gg     " },
		{ " gg     " },
		{ " gg   gg" },
		{ " gg   gg" },
		{ " ggggggg" }
	},
	{	// H
		{ "hh    hh" },
		{ "hh    hh" },
		{ "hhhhhhhh" },
		{ "hhhhhhhh" },
		{ "hh    hh" },
		{ "hh    hh" }
	},
	{	// I
		{ "  iiii  " },
		{ "  iiii  " },
		{ "  iiii  " },
		{ "  iiii  " },
		{ "  iiii  " },
		{ "  iiii  " }
	},
	{	// J
		{ "    jjj " },
		{ "    jjj " },
		{ "    jjj " },
		{ "    jjj " },
		{ "jj  jjj " },
		{ "jjjjjjj " }
	} ,
	{	// K
		{ " kk   kk" },
		{ " kk  kk " },
		{ " kkkk   " },
		{ " kkkk   " },
		{ " kk  kk " },
		{ " kk   kk" }
	},
	{	// L
		{ " lll    " },
		{ " lll    " },
		{ " lll    " },
		{ " lll    " },
		{ " llllll " },
		{ " llllll " }
	},
	{	// M
		{ "m      m" },
		{ "mm    mm" },
		{ "m mmmm m" },
		{ "m  mm  m" },
		{ "m      m" },
		{ "m      m" }
	} ,
	{	// N
		{ "nn    nn" },
		{ "nnn   nn" },
		{ "nnnn  nn" },
		{ "nn nn nn" },
		{ "nn  nnnn" },
		{ "nn   nnn" }
	},
	{	// O
		{ "oooooooo" },
		{ "oooooooo" },
		{ "oo    oo" },
		{ "oo    oo" },
		{ "oooooooo" },
		{ "oooooooo" }
	}, 
	{	// P
		{ "pppppppp" },
		{ "pppppppp" },
		{ "pppppppp" },
		{ "ppp     " },
		{ "ppp     " },
		{ "ppp     " }
	},

	{	// Q
		{ "qqqqqqqq" },
		{ "q      q" },
		{ "q      q" },
		{ "q   qq q" },
		{ "q    qqq" },
		{ "qqqqqqqq" }
	},
	{	// R
		{ "rrrrrrrr" },
		{ "rrrrrrrr" },
		{ "rrrrrr  " },
		{ "rr  rr  " },
		{ "rr  rrr " },
		{ "rr   rrr" }
	},
	{	// S
		{ "ssssssss" },
		{ "ssssssss" },
		{ "sss     " },
		{ "  sss   " },
		{ "ss  sss " },
		{ "ssssssss" }
	},
	{	// T
		{ "ttttttt " },
		{ "ttttttt " },
		{ "  ttt   " },
		{ "  ttt   " },
		{ "  ttt   " },
		{ "  ttt   " }
	},
	{	// U
		{ "uu    uu" },
		{ "uu    uu" },
		{ "uu    uu" },
		{ "uu    uu" },
		{ "uuuuuuuu" },
		{ "uuuuuuuu" }
	},
	{	// V
		{ "v     v " },
		{ "v     v " },
		{ "v     v " },
		{ " v   v  " },
		{ "  v v   " },
		{ "   v    " }
	},
	{	// W
		{ "w  ww  w" },
		{ "w  ww  w" },
		{ "w  ww  w" },
		{ "w wwww w" },
		{ "ww ww ww" },
		{ "w  ww  w" }
	},
	 {	// X
		{ "x      x" },
		{ " x    x " },
		{ "  x  x  " },
		{ "   x    " },
		{ "  x x   " },
		{ " x   x  " }
	}, 
	{	// Y
		{ " yy   yy" },
		{ "  yy yy " },
		{ "   yy   " },
		{ "   yy   " },
		{ "   yy   " },
		{ "   yy   " }
	}, 
	{	// Z
		{ "zzzzzzzz" },
		{ "zzzzzzzz" },
		{ "   zzz  " },
		{ "zzz     " },
		{ "zzzzzzzz" },
		{ "zzzzzzzz" }
	}
};


////////////////-->    GLOBAL FUNCTIONS  <--////////////////////////
bool userWantsToContinue();
void writeAsciiArtWith(char  input[]);
void writeAsciiArtWithHappyBirthdayMessage(Messages & m);
void getInput(char  input[], const char * msg);
void writeAsciiWith(ofstream &outFile);
void changeColor();
void writtenInputToArt(Input &input);
void init();
void writeToFile();


////////////////-->    GLOBAL VARIABLES  <--////////////////////////
vector <Input> inputLines;
HANDLE console;


////////////////-->    MAIN   <--////////////////////////
int main() {

	Messages bday;
	Input input;

	init();

	do {
		//writeAsciiArtWithHappyBirthdayMessage(bday);	// Use this one for predefined with "Message"	 
		writtenInputToArt(input);
		 
	} while (userWantsToContinue());

	writeToFile();
	CloseHandle(console);
	return 0;
}



void writeToFile()
{
	ofstream outFile("happybirthday.txt");
	writeAsciiWith(outFile);
}



void init()
{
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	changeColor();
}



void writtenInputToArt(Input &input)
{
	getInput(input.in, "Write something for ASCII art writing!");
	writeAsciiArtWith(input.in);					// Use this one to type each line in console
	inputLines.push_back(input);		// save the current line
}



void getInput(char  input[], const char * msg)
{
	cout << msg << '\n';
	cin.getline(input, INPUTLEN);
	char c; int i = 0;
	while (i < 8)
	{
		c = input[i];
		input[i] = tolower(c);
		i++;
	}
	cout << input;
	cout << "\n\n";
}



void writeAsciiWith(ofstream & outFile)
{
	for (int i = 0; i < inputLines.size(); i++) {
		for (int line = 0; line < MAXLINES; line++) {
			for (int letter = 0; letter < strlen(inputLines[i].in); letter++) {
				if (inputLines[i].in[letter] - ASCIIVALUETOALPHABETINDEX < 0) outFile << "    ";
				else {
					outFile << alphabet[inputLines[i].in[letter] - ASCIIVALUETOALPHABETINDEX][line];
				}
				outFile << " ";
			}
			outFile << "\n";
		}
		outFile << "\n\n";
	}
}


// Algorithm to write ascii art with our ascii art letters
void writeAsciiArtWith(char  input[])
{

	for (int line = 0; line < MAXLINES; line++) {
		for (int letter = 0; letter < strlen(input); letter++) {
			if (input[letter] - ASCIIVALUETOALPHABETINDEX < 0) cout << "    ";
			else {
				cout << alphabet[input[letter] - ASCIIVALUETOALPHABETINDEX][line];
			}
			cout << " ";
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "\n";
		//SetConsoleTextAttribute(console, line * 2);

	}
}



void writeAsciiArtWithHappyBirthdayMessage(Messages & m)
{
	for (int i = 0; i < MAXMESSAGE; i++) {
		for (int line = 0; line < MAXLINES; line++) {
			for (int letter = 0; letter < strlen(m.messages[i]); letter++) {
				if (m.messages[i][letter] - ASCIIVALUETOALPHABETINDEX < 0) cout << "    ";
				else {
					cout << alphabet[m.messages[i][letter] - ASCIIVALUETOALPHABETINDEX][line];
				}
				cout << " ";
				this_thread::sleep_for(chrono::milliseconds(10));
			}
			this_thread::sleep_for(chrono::milliseconds(200));
			cout << "\n";
		}
		cout << "\n\n";
		changeColor();
	}
}



bool userWantsToContinue() {
	cout << "\n\n\tWRITE ANOTHER LINE? \n\t1=YES 0=DONE";
	char ch;
	cin >> ch; cin.ignore();
	if (ch != '0') {
		changeColor();
		return true;
	}
	return false;
}



void changeColor() {
	srand(time(NULL));
	int randomColor = rand() % 7 + 9;
	while(randomColor == 12) randomColor = rand() % 7 + 9;
	cout << "\n\tcolor = " << randomColor << '\n';
	SetConsoleTextAttribute(console, randomColor);
}
