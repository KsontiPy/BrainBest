#include <stdio.h>

int main(int argc, char *argv[])
{
	
	unsigned char mem [65536];
	
	for (int i = 0; i < sizeof mem; i++) {
		
		mem[i] = 0;
		
	}
	
	unsigned char BUFF;
	int MP = 0;
	bool C = false;
	
	char code [] = "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#}>{---#>{++++#}>{#>{+++#";
	
	for (int IP = 0; IP < sizeof code - 1; IP++) {
		
		char l = code[IP];
		
		switch (l) {
			
			case ' ':
				
				break;
				
			case '<':
				
				MP -= 1;
				
				if (MP < 0) { MP = sizeof mem; }
				
				break;
				
			case '>':
				
				MP += 1;
				
				if (MP >= sizeof mem) { MP = 0; }
				
				break;
				
			case '+':
				
				mem[MP] += 1;
				
				break;
				
			case '-':
				
				mem[MP] -= 1;
				
				break;
				
			case '$':
				
				MP = mem[MP];
				
				break;
				
			case '%':
				
				mem[MP] = 0;
				
				break;
				
			case '#':
				
				printf("%c", mem[MP]);
				
				break;
				
			case '@':
				
				printf("%i", mem[MP]);
				
				break;
				
			case '}':
				
				BUFF = mem[MP];
				
				break;
				
			case '{':
				
				mem[MP] = BUFF;
				
				break;
				
			case '[':
				
				BUFF -= 1;
				
				break;
				
			case ']':
				
				BUFF += 1;
				
				break;
				
			case '^':
				
				if (C) { IP = mem[MP]; }
				
				break;
				
			case '~':
				
				if (C) { return 0; }
				
				break;
				
			case '?':
				
				if (mem[MP] == BUFF) { C = true; }
				else { C = false; }
				
				break;
				
			default:
				
				printf("Incorrect symbol \"%c\" by index %i", code[IP], IP);
				
				return 0;
				
		}
		
	}
	
}

/*
		
		" " == NOPE
		
		Work with MemoryPointer:
		
		">" == MP += 1
		"<" == MP -= 1
		"$" == MP = mem[MP]
		
		Work with memory:
		
		"+" == mem[MP] += 1
		"-" == mem[MP] -= 1
		"%" == mem[MP] = 0
		
		Work with I/O:
		
		"#" == print mem[MP] as char
		"@" == print mem[MP] as number
		
		Work width buffer:
		
		"{" == BUFF = mem[MP]
		"}" == mem[MP] = BUFF
		"[" == BUFF -= 1
		"]" == BUFF += 1
		
		Work with InstructionPointer:
		
		"^" == IP = mem[MP] if C
		
		Breaks:
		
		"~" == BREAK if C
		
*/