#include "Playfair.h"
#include <iostream>
#include <string>
#include <array>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

#pragma region PRIVATE METHODS
bool Playfair::checkCharInMatrix(char keywordChar)
{
	bool contains = true;

	if (keywordChar == 'A')
		alphabet[A] ? contains = true : contains = false;
	else if (keywordChar == 'B')
		alphabet[B] ? contains = true : contains = false;
	else if (keywordChar == 'C')
		alphabet[C] ? contains = true : contains = false;
	else if (keywordChar == 'D')
		alphabet[D] ? contains = true : contains = false;
	else if (keywordChar == 'E')
		alphabet[E] ? contains = true : contains = false;
	else if (keywordChar == 'F')
		alphabet[F] ? contains = true : contains = false;
	else if (keywordChar == 'G')
		alphabet[G] ? contains = true : contains = false;
	else if (keywordChar == 'H')
		alphabet[H] ? contains = true : contains = false;
	else if (keywordChar == 'I' || keywordChar == 'J')
		alphabet[IJ] ? contains = true : contains = false;
	else if (keywordChar == 'K')
		alphabet[K] ? contains = true : contains = false;
	else if (keywordChar == 'L')
		alphabet[L] ? contains = true : contains = false;
	else if (keywordChar == 'M')
		alphabet[M] ? contains = true : contains = false;
	else if (keywordChar == 'N')
		alphabet[N] ? contains = true : contains = false;
	else if (keywordChar == 'O')
		alphabet[O] ? contains = true : contains = false;
	else if (keywordChar == 'P')
		alphabet[P] ? contains = true : contains = false;
	else if (keywordChar == 'Q')
		alphabet[Q] ? contains = true : contains = false;
	else if (keywordChar == 'R')
		alphabet[R] ? contains = true : contains = false;
	else if (keywordChar == 'S')
		alphabet[S] ? contains = true : contains = false;
	else if (keywordChar == 'T')
		alphabet[T] ? contains = true : contains = false;
	else if (keywordChar == 'U')
		alphabet[U] ? contains = true : contains = false;
	else if (keywordChar == 'V')
		alphabet[V] ? contains = true : contains = false;
	else if (keywordChar == 'W')
		alphabet[W] ? contains = true : contains = false;
	else if (keywordChar == 'X')
		alphabet[X] ? contains = true : contains = false;
	else if (keywordChar == 'Y')
		alphabet[Y] ? contains = true : contains = false;
	else if (keywordChar == 'Z')
		alphabet[Z] ? contains = true : contains = false;

	return contains;
}
void Playfair::updateAlphabet(char letter)
{
	if (letter == 'A')
		alphabet[A] = true;
	else if (letter == 'B')
		alphabet[B] = true;
	else if (letter == 'C')
		alphabet[C] = true;
	else if (letter == 'D')
		alphabet[D] = true;
	else if (letter == 'E')
		alphabet[E] = true;
	else if (letter == 'F')
		alphabet[F] = true;
	else if (letter == 'G')
		alphabet[G] = true;
	else if (letter == 'H')
		alphabet[H] = true;
	else if (letter == 'I' || letter == 'J')
		alphabet[IJ] = true;
	else if (letter == 'K')
		alphabet[K] = true;
	else if (letter == 'L')
		alphabet[L] = true;
	else if (letter == 'M')
		alphabet[M] = true;
	else if (letter == 'N')
		alphabet[N] = true;
	else if (letter == 'O')
		alphabet[O] = true;
	else if (letter == 'P')
		alphabet[P] = true;
	else if (letter == 'Q')
		alphabet[Q] = true;
	else if (letter == 'R')
		alphabet[R] = true;
	else if (letter == 'S')
		alphabet[S] = true;
	else if (letter == 'T')
		alphabet[T] = true;
	else if (letter == 'U')
		alphabet[U] = true;
	else if (letter == 'V')
		alphabet[V] = true;
	else if (letter == 'W')
		alphabet[W] = true;
	else if (letter == 'X')
		alphabet[X] = true;
	else if (letter == 'Y')
		alphabet[Y] = true;
	else if (letter == 'Z')
		alphabet[Z] = true;
}
void Playfair::findCharLocation(char character, int& char1DIndex, int& char2DIndex)
{
	if (toupper(character) == 'J')
		character = 'I';

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (matrix[i][j] == toupper(character))
			{
				char1DIndex = i;
				char2DIndex = j;
			}
		}
	}
}
string Playfair::removeExtraChars(string plaintext, vector<int> extraCharsLocations)
{
	for (int i = extraCharsLocations.size() - 1; i >= 0; i--)
		plaintext.erase(extraCharsLocations.at(i), 1); // remove all Xs between double letters

	if (isPadded)
		plaintext.erase(plaintext.size() - 1, 1); // remove X or Q padding at the end of string

	return plaintext;
}
string Playfair::replaceIsWithJs(string plaintext, vector<int> jsLocations)
{
	if (!jsLocations.empty())
	{
		for (int i = 0; i < jsLocations.size(); i++)
			plaintext.at(jsLocations.at(i)) = 'J'; 
	}

	return plaintext;
}
string Playfair::addSpecialPunctuations(string plaintext, int plaintextSize, vector<int> spacesLocations, vector<int> periodsLocations, vector<int> commasLocations)
{
	int spacesIndex = 0;
	int periodsIndex = 0;
	int commasIndex = 0;

	for (int i = 0; i < plaintextSize; i++)
	{
		if (spacesIndex != spacesLocations.size())
		{
			if (spacesLocations.at(spacesIndex) == i)
			{
				plaintext.insert(i, " "); // Add back all spaces to decrypted text
				spacesIndex++;
			}
		}
		if (periodsIndex != periodsLocations.size())
		{
			if (periodsLocations.at(periodsIndex) == i)
			{
				plaintext.insert(i, "."); // Add back all periods to decrypted text
				periodsIndex++;
			}
		}
		if (commasIndex != commasLocations.size())
		{
			if (commasLocations.at(commasIndex) == i)
			{
				plaintext.insert(i, ","); // Add back all commas to decrypted text
				commasIndex++;
			}
		}
	}

	return plaintext;
}
#pragma endregion PRIVATE METHODS

#pragma region PUBLIC METHODS
void Playfair::generateMatrix(string keyword)
{
	keyword.erase(remove_if(keyword.begin(), keyword.end(), isspace), keyword.end()); // Delete all spaces from keyword and update size
	keyword.erase(remove_if(keyword.begin(), keyword.end(), ispunct), keyword.end()); // Delete all punctuation from keyword and update size
	int keywordPlace = -1;
	char letter = 'A';

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			keywordPlace++;
			if (keywordPlace < keyword.size()) // Executes until cycled through keyword
			{
				if (!checkCharInMatrix(keyword.at(keywordPlace))) // Check to make sure char from keyword is not already in matrix
				{
					matrix[i][j] = keyword.at(keywordPlace) == 'J' ? 'I' : keyword.at(keywordPlace);
					updateAlphabet(keyword.at(keywordPlace));
				}
				else // Continue loop at same place in matrix
				{
					j--;
				}
			}
			else // Executes starting at letter 'a' until matrix is filled
			{
				if (!checkCharInMatrix(letter)) // Check to make sure char from alphabet is not already in matrix
				{
					matrix[i][j] = (letter == 'J') ? 'I' : letter;
					updateAlphabet(letter);
					letter++;
				}
				else // Continue loop at same place in matrix and next alphabet letter
				{
					j--;
					letter++;
				}
			}
		}
	}
}
void Playfair::printMatrix()
{
	cout << "\n5x5 Matrix:";
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;
}
vector<int> Playfair::getSpacesLocations(string plaintext)
{
	vector<int> spacesLocations;

	for (int i = 0; i < plaintext.size(); i++)
	{
		if (isspace(plaintext.at(i)))
			spacesLocations.push_back(i);
	}

	return spacesLocations;
}
vector<int> Playfair::getPeriodsLocations(string plaintext)
{
	vector<int> periodsLocations;
	
	for (int i = 0; i < plaintext.size(); i++)
	{
		if (plaintext.at(i) == '.')
			periodsLocations.push_back(i);
	}

	return periodsLocations;
}
vector<int> Playfair::getCommasLocations(string plaintext)
{
	vector<int> commasLocations;
	
	for (int i = 0; i < plaintext.size(); i++)
	{
		if (plaintext.at(i) == ',')
			commasLocations.push_back(i);
	}

	return commasLocations;
}
vector<int> Playfair::getJsLocations(string& plaintext)
{
	plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), isspace), plaintext.end()); // Delete all spaces from plaintext and update size
	plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), ispunct), plaintext.end()); // Delete all punctuation from plaintext and update size
	vector<int> jsLocations;

	for (int i = 0; i < plaintext.size(); i++)
	{
		if (plaintext.at(i) == 'J')
			jsLocations.push_back(i);
	}

	return jsLocations;
}
vector<int> Playfair::updatePaddingAndDoubleLetters(string& plaintext)
{
	vector<int> extraCharsLocations;

	for (int i = 0; i < plaintext.size() - 1; i = i + 2)
	{
		// if letters are the same, add X between them
		if (plaintext.at(i) == plaintext.at(i + 1))
		{
			extraCharsLocations.push_back(i + 1);
			plaintext.insert(i + 1, "X");
		}
	}

	// if length is odd, add an X or a Q if it ends with X already
	if (plaintext.size() % 2 == 1)
	{
		if (plaintext.at(plaintext.size() - 1) == 'X')
			plaintext.push_back('Q');
		else
			plaintext.push_back('X');

		isPadded = true;
	}

	return extraCharsLocations;
}
string Playfair::encrypt(string plaintext)
{
	string ciphertext;
	int firstChar1DIndex;
	int firstChar2DIndex;
	int secondChar1DIndex;
	int secondChar2DIndex;

	for (int i = 0; i < plaintext.size() - 1; i = i + 2)
	{
		findCharLocation(plaintext.at(i), firstChar1DIndex, firstChar2DIndex);
		findCharLocation(plaintext.at(i + 1), secondChar1DIndex, secondChar2DIndex);
		if (firstChar1DIndex == secondChar1DIndex) // If both chars are in the same column
		{
			plaintext.at(i) = matrix[firstChar1DIndex][(firstChar2DIndex + 1) % 5];
			plaintext.at(i + 1) = matrix[secondChar1DIndex][(secondChar2DIndex + 1) % 5];
		}
		else if (firstChar2DIndex == secondChar2DIndex) // If both chars are in the same column
		{
			plaintext.at(i) = matrix[(firstChar1DIndex + 1) % 5][firstChar2DIndex];
			plaintext.at(i + 1) = matrix[(secondChar1DIndex + 1) % 5][secondChar2DIndex];
		}
		else // If both chars are in different rows and columns, make rectangle to find encryption chars
		{
			plaintext.at(i) = matrix[firstChar1DIndex][secondChar2DIndex];
			plaintext.at(i + 1) = matrix[secondChar1DIndex][firstChar2DIndex];
		}
	}
	ciphertext = plaintext;

	return ciphertext;
}
string Playfair::decrypt(string ciphertext)
{
	string plaintext;
	int firstChar1DIndex;
	int firstChar2DIndex;
	int secondChar1DIndex;
	int secondChar2DIndex;

	for (int i = 0; i < ciphertext.size(); i = i + 2)
	{
		findCharLocation(ciphertext.at(i), firstChar1DIndex, firstChar2DIndex);
		findCharLocation(ciphertext.at(i + 1), secondChar1DIndex, secondChar2DIndex);
		if (firstChar1DIndex == secondChar1DIndex) // If both chars are in the same column
		{
			ciphertext.at(i) = (firstChar2DIndex != 0) ? matrix[firstChar1DIndex][firstChar2DIndex - 1] : matrix[firstChar1DIndex][4];
			ciphertext.at(i + 1) = (secondChar2DIndex != 0) ? matrix[secondChar1DIndex][secondChar2DIndex - 1] : matrix[secondChar1DIndex][4];
		}
		else if (firstChar2DIndex == secondChar2DIndex) // If both chars are in the same rows
		{
			ciphertext.at(i) = (firstChar1DIndex != 0) ? matrix[firstChar1DIndex - 1][firstChar2DIndex] : matrix[4][firstChar2DIndex];
			ciphertext.at(i + 1) = (secondChar1DIndex != 0) ? matrix[secondChar1DIndex - 1][secondChar2DIndex] : matrix[4][secondChar2DIndex];
		}
		else // If both chars are in different rows and columns, make rectangle to find decryption chars
		{
			ciphertext.at(i) = matrix[firstChar1DIndex][secondChar2DIndex];
			ciphertext.at(i + 1) = matrix[secondChar1DIndex][firstChar2DIndex];
		}
	}
	plaintext = ciphertext;

	return plaintext;
}
string Playfair::convertAfterDecryption(string plaintext, int plaintextSize, vector<int> spacesLocations, vector<int> periodsLocations, vector<int> commasLocations, vector<int> jsLocations, vector<int> extraCharsLocations)
{
	plaintext = replaceIsWithJs(plaintext, jsLocations); // Replace Is with original Js
	plaintext = removeExtraChars(plaintext, extraCharsLocations); // Remove extra Xs and Qs
	plaintext = addSpecialPunctuations(plaintext, plaintextSize, spacesLocations, periodsLocations, commasLocations); // Add spaces and periods back in from original plaintext

	return plaintext;
}
#pragma endregion PUBLIC METHODS

int main()
{
	Playfair playfair;
	vector<int> spacesLocations; // Locations of all spaces in original plaintext
	vector<int> periodsLocations; // Locations of all periods in original plaintext
	vector<int> commasLocations; // Locations of all commas in original plaintext
	vector<int> jsLocations; // Locations of all js in original plaintext
	vector<int> extraCharsLocations; // Locations of padding and Xs inserted between double letters
	string keyword;
	string plaintext;
	string ciphertext;
	int plaintextSize;

	// Get keyword from user
	cout << "Enter keyword: ";
	getline(cin, keyword);
	transform(keyword.begin(), keyword.end(), keyword.begin(), toupper); // Transform keyword to all uppercase

	// Generate and print matrix from keyword
	playfair.generateMatrix(keyword);
	playfair.printMatrix();

	// Get plaintext from user and print out with padding and X for double letters
	cout << "\nEnter plaintext: ";
	getline(cin, plaintext);
	plaintextSize = plaintext.size();
	transform(plaintext.begin(), plaintext.end(), plaintext.begin(), toupper); // Transform plaintext to all uppercase
	spacesLocations = playfair.getSpacesLocations(plaintext);
	periodsLocations = playfair.getPeriodsLocations(plaintext);
	commasLocations = playfair.getCommasLocations(plaintext);
	jsLocations = playfair.getJsLocations(plaintext);
	extraCharsLocations = playfair.updatePaddingAndDoubleLetters(plaintext);
	cout << "\nBefore Encryption" << endl;
	cout << "----------------------------" << endl;
	cout << "Plaintext: " << plaintext << endl;

	// Encrypt plaintext and print it out
	ciphertext = playfair.encrypt(plaintext);
	cout << "\nAfter Encryption" << endl;
	cout << "----------------------------" << endl;
	cout << "Ciphertext: " << ciphertext << endl;

	// Decrypt ciphertext and print it out
	plaintext = playfair.convertAfterDecryption(playfair.decrypt(ciphertext), plaintextSize, spacesLocations, periodsLocations, commasLocations, jsLocations, extraCharsLocations);
	cout << "\nAfter Decryption" << endl;
	cout << "----------------------------" << endl;
	cout << "Plaintext: " << plaintext << endl;

	return 0;
}

