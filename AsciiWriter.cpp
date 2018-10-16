#include<iostream>
#include<cstring>

using namespace std;


const int MAXLINES = 6;			// ASCII art stacked horizontal lines per letter
const int INPUTLEN = 10;		// Input Limit
const int ASCIIVALUETOALPHABETINDEX = 97;	/* 
											a - 97  =  0.  
											b - 97  = 1 
											etc...
											*/

		// letter  |    line of letter  | char of line
char alphabet[10]		[MAXLINES]			[9] = {
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
	}



};


bool userWantsToContinue();
void writeAsciiArtWith(char  input[]);
void getInput(char  input[], const char * msg);


int main() {
	do {
		char input[INPUTLEN];
		getInput(input, "Write something for ASCII art writing!");

		writeAsciiArtWith(input);

	} while (userWantsToContinue());

	return 0;
}



void getInput(char  input[], const char * msg)
{
	cout << msg << '\n';
	cin.getline(input, INPUTLEN);
}


// Algorithm to write ascii art with our ascii art letters
void writeAsciiArtWith(char  input[])
{
	for (int line = 0; line < MAXLINES; line++) {
		for (int letter = 0; letter < strlen(input); letter++) {
			cout << alphabet[input[letter] - ASCIIVALUETOALPHABETINDEX][line];
		}
		cout << "\n";
	}
}



bool userWantsToContinue() {
	cout << "\n\nQ = quit \n";
	char ch;
	cin >> ch; cin.ignore();
	ch = toupper(ch);
	if (ch != 'Q') return true;
	return false;
}
