#include "include/videoDriver.h"
#include "include/types.h"

static dword uintToBase(qword value, char * buffer, dword base);

static char buffer[64] = { '0' };
static byte * const video = (byte*)0xB8000;
static byte * currentVideo = (byte*)0xB8000;
static const dword width = 80;
static const dword height = 25 ;

void printString(const char * string) {
	int i;

	for (i = 0; string[i] != 0; i++)
		printChar(string[i]);
}

void printChar(char character) {
	*currentVideo = character;
	currentVideo += 2;
}

void newline() {
	do {
		printChar(' ');
	} while((qword)(currentVideo - video) % (width * 2) != 0);
}

void printDec(qword value) {
	printBase(value, 10);
}

void printHex(qword value) {
	printBase(value, 16);
}

void printBin(qword value) {
	printBase(value, 2);
}

void printBase(qword value, dword base) {
    uintToBase(value, buffer, base);
    printString(buffer);
}

void clear() {
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

static dword uintToBase(qword value, char * buffer, dword base) {
	char *p = buffer;
	char *p1, *p2;
	dword digits = 0;

	//Calculate characters for each digit
	do	{
		dword remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2) {
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}