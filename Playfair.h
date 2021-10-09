#pragma once
// June 2021
// Playfair cipher implementation in C++ that asks for keyword from user, generates 5x5 matrix, asks for plaintext from user, and then encrypts it with matrix and decrypts it with reverse process.

#include <string>
#include <array>
#include <vector>

using namespace std;

enum eAlphabet
{
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	IJ,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	NumAlphabet
};

class Playfair
{
public:
	void generateMatrix(string keyword);
	void printMatrix();
	vector<int> getSpacesLocations(string plaintext);
	vector<int> getPeriodsLocations(string plaintext);
	vector<int> getCommasLocations(string plaintext);
	vector<int> getJsLocations(string& plaintext);
	vector<int> updatePaddingAndDoubleLetters(string& plaintext);
	string encrypt(string plaintext);
	string decrypt(string ciphertext);
	string convertAfterDecryption(string plaintext, int plaintextSize, vector<int> spacesLocations, vector<int> periodsLocations, vector<int> commasLocations, vector<int> jsLocations, vector<int> extraCharsLocations);
private:
	bool checkCharInMatrix(char keywordChar);
	void updateAlphabet(char letter);
	void findCharLocation(char character, int& char1DIndex, int& char2DIndex);
	string removeExtraChars(string plaintext, vector<int> extraCharsLocations);
	string replaceIsWithJs(string plaintext, vector<int> jsLocations);
	string addSpecialPunctuations(string plaintext, int plaintextSize, vector<int> spacesLocations, vector<int> periodsLocations, vector<int> commaLocations);
	char matrix[5][5]; // 5x5 encryption/decryption matrix
	bool alphabet[NumAlphabet] = {}; // array to keep track of used letters for 5x5 matrix
	bool isPadded = false; // is changed to true if X or Q is added at end because plaintext is odd length
};
