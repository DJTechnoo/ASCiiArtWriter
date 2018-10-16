#include<iostream>
#include<cstring>
#include <thread>
#include <chrono>


using namespace std;


const int MAXLINES = 6;			// ASCII art stacked horizontal lines per letter
const int INPUTLEN = 20;		// Input Limit
const int ASCIIVALUETOALPHABETINDEX = 97;	/* 
											a - 97  =  0.  
											b - 97  = 1 
											etc...
											*/

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
		{ "ppp" },
		{ "ppp" },
		{ "ppp" }
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


// Algorithm to write ascii art with our ascii art letters
void writeAsciiArtWith(char  input[])
{
	char ch;
	for (int line = 0; line < MAXLINES; line++) {
		for (int letter = 0; letter < strlen(input); letter++) {
			if (input[letter] - ASCIIVALUETOALPHABETINDEX < 0) cout << "\t";
			else {
				cout << alphabet[input[letter] - ASCIIVALUETOALPHABETINDEX][line];
			}
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "\n";
	}
}



bool userWantsToContinue() {
	cout << "\n\nQ = quit \n";
	char ch;
	cin >> ch; cin.ignore();
	cout << "\n\nindex = " << ch - 97 << '\n';
	ch = toupper(ch);
	if (ch != 'Q') return true;
	return false;
}
