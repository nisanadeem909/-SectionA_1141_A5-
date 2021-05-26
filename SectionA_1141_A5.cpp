// Assignment 5
// Nisa Nadeem 
// 20L-1141


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

static int StringLenght(char* str) // returns length of word
{

	int i = 0, count = 0;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}

	return count;

}

void FillGrid(char**& Grid, int rows, int cols)  // This function fills the grid with random alphabets at the end
{
	char character;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Grid[i][j] == '*')
			{
			     character = (90 - (rand() % 26));
				Grid[i][j] = character;
				
			}
		}
	}


}

char** AllocateGrid(char** WordsArray,int rows,int cols) // This function makes a grid on heap on the basis of the word with maxiumum letters
{
	int c = 0;
	int letters = 0;
	while (WordsArray[0][c] != '\0')
	{
		c++;
		letters++;


	}

	if (letters > rows && letters > cols)
	{

		return 0;
	}


	char** Grid = new char* [rows];

	int count = 0;
	int i = 0;
	while (count <=rows)
	{
		Grid[i] = new char[cols+1];
		i++;
		count++;
	}

	int j = 0;
	int k = 0;
	int count2 = 0;
	while (count2 < rows)
	{
		k = 0;
		while (k < cols)
		{
			Grid[j][k] = '*';
			k++;

		}
		Grid[j][k] = '\0';
		j++;
		count2++;
	}





	return Grid;


}

void FixWordDiagonally(char**& Grid, int& probability, char Words[], int letters, int i, int j, int rows, int cols, int& countLetters)
{

	if (Grid[i][j] == '*') // checks each space to fix the word
	{

		for (int z = i; z < letters; z++)
		{
			int y = j;
			if (Grid[0 + z][0 + y] == '*')
			{
				countLetters++;
				y++;
			}
			else
				if (Grid[0 + z][0 + y] == Words[countLetters]) // checks if overlapping is possible
				{
					countLetters++;
				}
		}

		if (countLetters == letters)
		{
			int b = 0;
			int c = j;
			for (int a = i; a < letters; a++)
			{
				Grid[0 + a][0 + c] = Words[b];
				b++;
				c++;

			}

			return;
		}
		else
			countLetters = 0;

		if (i == (rows - 1) && j == (cols - 1))
		{
			probability++;
		}

	}


}

void FixWordDiagonally_left(char**& Grid, int& probability, char Words[], int letters, int i, int j, int rows, int cols, int& countLetters)
{

	if (Grid[i][j] == '*') // checks each space to fix the word
	{

		int g = i;


		for (int z = j; z < letters + j; z++)
		{
			if (g < 0 || z < 0 || g >= rows || z >= cols)
			{
				break;
			}
			if (Grid[g][z] == '*')
			{
				countLetters++;
				g--;
			}
			else
				if (Grid[g][z] == Words[countLetters]) // checks if overlapping is possible
				{
					countLetters++;
				}
		}

		if (countLetters == letters)
		{
			int e = i;
			int y = 0;
			for (int b = j; b < letters + j; b++)
			{

				Grid[e][b] = Words[y];
				y++;
				e--;

			}
			return;

		}
		else
			countLetters = 0;

		if (i == (rows - 1) && j == (cols - 1))
		{
			probability++;
		}

	}
}

void FixWordToptoBottom(char**& Grid, int& probability, char Words[], int letters, int i, int j, int rows, int cols, int& countLetters)
{

	if (Grid[i][j] == '*')  // checks each space if the word can be placed
	{

		for (int k = i; k > i - letters; k--)
		{
			if (k < 0 || k >= rows)
			{
				break;
			}
			if (Grid[k][j] == '*')
			{
				countLetters++;
			}
			else
				if (Grid[k][j] == Words[countLetters])  // checks if overlapping of word is possible
				{
					countLetters++;
				}

		}

		if (countLetters == letters)
		{
			int y = 0;
			for (int b = i; b > i - letters; b--)
			{
				Grid[b][j] = Words[y];
				y++;

			}
			return;
		}
		else
			countLetters = 0;

		if (i == (rows - 1) && j == (cols - 1))
		{
			probability++;
		}

	}
}

void FixWordBottomtoTop(char**& Grid, int& probability, char Words[], int letters, int i, int j, int rows, int cols, int& countLetters)
{
	if (Grid[i][j] == '*') // checks each space to find space for the whole word
	{
		int countLetters = 0;
		for (int k = i; k < letters + i; k++)
		{
			if (k < 0 || k >= rows)
			{
				break;
			}
			if (Grid[k][j] == '*')
			{
				countLetters++;
			}
			else
				if (Grid[k][j] == Words[countLetters])  // checks if overlapping is possible
				{
					countLetters++;
				}

		}

		if (countLetters == letters)
		{
			int y = 0;
			for (int b = i; b < letters + i; b++)
			{
				Grid[b][j] = Words[y];
				y++;

			}
			return;
		}
		else
			countLetters = 0;

		if (i == (rows - 1) && j == (cols - 1))
		{
			probability++;
		}

	}

}

void FixWordLeftoRight(char**& Grid, int& probability, char Words[], int letters, int i, int j, int rows, int cols, int& countLetters)
{

	if (Grid[i][j] == '*') // checks each space to find the space along to fix word
	{

		for (int k = j; k < letters + j; k++)
		{
			if (k < 0 || k >= cols)
			{
				break;
			}
			if (Grid[i][k] == '*')
			{
				countLetters++;
			}
			else
				if (Grid[k][j] == Words[countLetters]) // checks if overlapping is possible
				{
					countLetters++;
				}

		}

		if (countLetters == letters)
		{
			int y = 0;
			for (int b = j; b < letters + j; b++)
			{
				Grid[i][b] = Words[y];
				y++;

			}
			return;
		}
		else
			countLetters = 0;

		if (i == (rows - 1) && j == (cols - 1))
		{
			probability++;
		}

	}

}

void FixWordRighttoLeft(char**& Grid, int& probability, char Words[], int letters, int i, int j, int rows, int cols, int& countLetters)
{


	if (Grid[i][j] == '*')    // checks space by space for the word to place
	{
		if (j > letters)
		{
			for (int k = j; k > j - letters; k--)
			{
				if (k < 0 || k >= cols)
				{
					break;
				}
				if (Grid[i][k] == '*')
				{
					countLetters++;
				}
				else
					if (Grid[i][k] == Words[countLetters]) // checks if overlapping is possible with other words
					{
						countLetters++;
					}

			}

			if (countLetters == letters)
			{
				int y = 0;
				for (int b = j; b > j - letters; b--)
				{
					Grid[i][b] = Words[y];
					y++;

				}
				return;
			}
			else
				countLetters = 0;

			if (i == (rows - 1) && j == (cols - 1))  // probability is handled randomly
			{
				probability++;
			}
		}

	}

}

void MakeGrid(char**& Grid,char Words[], int words, int rows,int cols, int &probability) // This function will fix the words in the grid and generate a puzzle
{
	
	
	int a = 0;
	int letters = 0;
	
	while (Words[a] != '\0')
	{
		letters++;
		a++;
	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (probability == 0 || probability == 7 || probability == 8)
			{
				int countLetters = 0;
				FixWordDiagonally(Grid, probability, Words, letters, i, j, rows, cols, countLetters); // Finds if the word can be placed diagonally right according to probability number
				if (countLetters != 0)
					return;
			}

			if (probability == 1 || probability==7 || probability == 8)
			{
				int countLetters = 0;
				FixWordDiagonally_left(Grid, probability, Words, letters, i, j, rows, cols, countLetters); // Finds if the word can be placed diagonally left according to probability number
				if (countLetters != 0)
					return;
			}

			if (probability == 2)
			{
				int countLetters = 0;
				FixWordToptoBottom(Grid, probability, Words, letters, i, j, rows, cols, countLetters); // Finds if the word can be placed Top to Bottom according to probability number
				if (countLetters != 0)
					return;
			}


			if (probability == 3 || probability == 4 || probability == 5 || probability == 6 || probability == 7 || probability == 8 || probability == 9)
			{
				int countLetters = 0;
				FixWordBottomtoTop(Grid, probability, Words, letters, i, j, rows, cols, countLetters);  // Finds if the word can be placed Bottom to top according to probability number
				if (countLetters != 0)
					return;
			}


			if (probability == 4 || probability== 5 || probability == 6 || probability == 7 || probability == 8 || probability == 9)
			{
				int countLetters = 0;
				FixWordLeftoRight(Grid, probability, Words, letters, i, j, rows, cols, countLetters); // Finds if the word can be placed left to right according to probability number
				if (countLetters != 0)
					return;

			}


			if (probability == 4 || probability == 5 || probability == 6 || probability == 7)
			{
				int countLetters = 0;
				FixWordRighttoLeft(Grid, probability, Words, letters, i, j, rows, cols, countLetters);  // // Finds if the word can be placed right to left according to probability number
				if (countLetters != 0)
					return;

			} 



		}
	}


}

void PrintGrid(char**& Grid, int rows, int cols)  // Prints the Grid 
{
	for (int i = 0; i <rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << Grid[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void SortArray_of_Words(char** &tempArray,int words)
{
	for (int q = 0; q < words; q++)    //Sorting of words from words with largest length to words with smallest length so it becomes easy to allocate words in grid
	{
		for (int p = q + 1; p < words; p++) // Bigger words allocated first so that there space is reserved and smaller ones are placed later
		{

			int b3 = 0;
			while (tempArray[p][b3] != '\0')
			{

				b3++;
			}

			int b4 = 0;
			while (tempArray[q][b4] != '\0')
			{

				b4++;
			}
			if (b3 > b4)
			{
				char temp[30];
				int a = 0;
				int b = 0;
				while (tempArray[q][b] != '\0')
				{
					temp[a] = tempArray[q][b];
					a++;
					b++;
				}


				temp[a] = '\0';


				int b1 = 0;
				while (tempArray[p][b1] != '\0')
				{
					tempArray[q][b1] = tempArray[p][b1];

					b1++;
				}

				tempArray[q][b1] = '\0';


				int a2 = 0;
				int b2 = 0;
				while (temp[a2] != '\0')
				{
					tempArray[p][b2] = temp[a2];
					a2++;
					b2++;
				}

				tempArray[p][b2] = '\0';

			}
		}
	}

}

bool CheckRows(char** Grid, char Words[], int& r1, int& c1, int& r2, int& c2, int rows, int cols, int words)  // IT CHECKS RIGHT TO LEFT AND LEFT TO WRITE
{

	int a = 0;
	int letters = 0;
	letters = StringLenght(Words);

	int FALSE = 0;


	int number = 0;
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < rows; i++) // Checks each space for the first letter of the word
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;

			if (Grid[i][j] == Words[number]) // if letter found then traverse from right to left
			{
				for (k = j; k < letters + j; k++)
				{
					if (number == letters)
						break;
					if (Grid[i][k] == Words[number]) 
					{
						count++;
					}
					else
					{
						number = 0;
						count = 0;
						break;
					}
					number++;
				}

			}



			if (count == letters) // if word found then saves indexes passed by reference 
			{
				r2 = i;
				c2 = k - 1;
				r1 = i;
				c1 = j;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count2++;
	}

	int number2 = 0;
	int count3 = 0;
	int count4 = 0;
	for (int i = 0; i < rows; i++)  // Now finds word from left to right if not found before
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;
			if (number2 < letters)
			{
				if (Grid[i][j] == Words[number2])
				{
					if (j >= letters - 1)
					{
						for (k = j; k >= ((j + 1) - letters); k--)
						{
							if (number == letters)
								break;

							if (Grid[i][k] == Words[number2])
							{
								count3++;
							}
							else
							{
								number2 = 0;
								count3 = 0;
								break;
							}
							number2++;
						}
					}
				}

			}

			if (count3 == letters)
			{
				r2 = i;
				c2 = k + 1;
				r1 = i;
				c1 = j;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count4++;
	}
	if (FALSE == 1)
	{
		return false;
	}


}

bool CheckColumns(char** Grid, char Words[], int& r1, int& c1, int& r2, int& c2, int rows, int cols, int words)  // IT CHECKS TOP TO BOTTOM AND BOTTOM TO TOP
{



	int a = 0;
	int letters = 0;
	letters = StringLenght(Words);


	int FALSE = 0;


	int number = 0;
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < rows; i++) // checks each space for the first letter of the word
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;

			if (Grid[i][j] == Words[number])  // if letter found traverse from top to bottom
			{


				for (k = i; k < letters + i; k++)
				{
					if (letters + i > rows)
						break;
					if (number == letters)
						break;
					if (Grid[k][j] == Words[number])
					{
						count++;
					}
					else
					{
						number = 0;
						count = 0;
						break;
					}
					number++;
				}


			}



			if (count == letters) // if word found then saves indexes
			{
				r2 = k - 1;
				c2 = j;
				r1 = i;
				c1 = j;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count2++;
	}



	int number2 = 0;
	int count3 = 0;
	int count4 = 0;
	for (int i = 0; i < rows; i++)  // Now finds the word by bottom to top if not found before
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;

			if (Grid[i][j] == Words[number2])
			{

				for (k = i; k > i - letters; k--)
				{
					if (k < 0)
						break;
					if (number2 == letters)
						break;
					if (Grid[k][j] == Words[number2])
					{
						count3++;
					}
					else
					{
						number2 = 0;
						count3 = 0;
						break;
					}
					number2++;
				}


			}



			if (count3 == letters)
			{
				r2 = k + 1;
				c2 = j;
				r1 = i;
				c1 = j;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count4++;
	}
}

bool CheckDiagonally(char** Grid, char Words[], int& r1, int& c1, int& r2, int& c2, int rows, int cols, int words) // WILL CHECK DIAGONALS
{

	int a = 0;
	int letters = 0;
	letters = StringLenght(Words);  // word length 

	int FALSE = 0;


	int number = 0;
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < rows; i++)  // checks each space for the first letter of word
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;

			if (Grid[i][j] == Words[number])  // if letter found traverse in the diagonal direction
			{
				int u = i;
				for (k = j; k < letters + j; k++)
				{
					if ((letters + j) > cols)
						break;
					if (number == letters)
						break;
					if (Grid[u][k] == Words[number])
					{
						count++;
					}
					else
					{
						number = 0;
						count = 0;
						u = 0;
						break;
					}
					number++;
					u++;
				}

			}



			if (count == letters) // if word found saves indexes passed by refernce
			{
				r2 = i;
				c2 = k - 1;
				r1 = i;
				c1 = j;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count2++;
	}


	int number2 = 0;
	int count3 = 0;
	int count4 = 0;
	for (int i = 0; i < rows; i++)  // Now checks for the word in the opposite direction if not found before
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;
			if (number2 < letters)
			{
				if (Grid[i][j] == Words[number2])
				{

					int u1 = i;
					for (k = j; k > j - letters; k--)
					{
						if (k < 0)
							break;

						if (number2 == letters)
							break;
						if (Grid[u1][k] == Words[number2])
						{
							count3++;
						}
						else
						{
							number2 = 0;
							count3 = 0;
							u1 = 0;
							break;
						}
						number2++;
						u1++;
					}


				}

			}

			if (count3 == letters)
			{
				r2 = i;
				c2 = k - 1;
				r1 = i;
				c1 = j;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count4++;
	}



}

bool CheckDiagonallyOppo(char** Grid, char Words[], int& r1, int& c1, int& r2, int& c2, int rows, int cols, int words) // IT WILL CHECK DIAGONALS AT OPPOSITE OF PREVIOUS FUNCTION
{

	
	int letters = 0;
	letters = StringLenght(Words);  // Function returns length of the word

	int FALSE = 0;

	int R2 = 0;
	int number = 0;
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < rows; i++)   // Checks each letter index by index
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;
			if (number < letters)
			{
				if (j > letters)
				{
					if (Grid[i][j] == Words[number]) // if letter found than traverse diagonally 
					{

						int u = i;


						for (k = j; k > j - letters; k--)
						{
							if (u < 0 || k < 0)
								break;
							if (number == letters)
								break;
							if (Grid[u][k] == Words[number])
							{
								count++;
							}
							else
							{
								number = 0;
								count = 0;
								u = 0;
								break;
							}
							number++;
							u--;
						}
						R2 = u;

					}
				}
			}

			if (count == letters) // stores the indexes if word found // indexes passed by reference
			{
				r2 = R2 + 1;
				c2 = k + 1;
				r1 = i;
				c1 = j;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count2++;
	}

	int r3 = 0;      
	int number2 = 0;
	int count3 = 0;
	int count4 = 0;
	for (int i = 0; i < rows; i++) // again checks index by index in opposite direction
	{
		for (int j = 0; j < cols; j++)
		{
			int k = 0;
			if (number2 < letters)
			{
				if (Grid[i][j] == Words[number2])
				{

					int u1 = i;
					for (k = j; k < letters + j; k++)
					{
						if ((letters + j) > cols || u1 < 0)
							break;

						if (number2 == letters)
							break;
						if (Grid[u1][k] == Words[number2])
						{
							count3++;
						}
						else
						{
							number2 = 0;
							count3 = 0;
							u1 = 0;
							break;
						}
						number2++;
						u1--;
						r3 = u1;

					}


				}

			}

			if (count3 == letters)
			{
				r2 = r3 + 1;
				c2 = k - 1;
				r1 = i + 2;
				c1 = j - 2;
				return true;
			}
			else
			{
				FALSE = 1;
			}

		}
		count4++;
	}



}





bool ProcessMenu()
{
	cout << "Please Choose any one option:\n\n" << "1) Enter 'C' to Create Grid\n" << "2) Enter 'S' to Search Words from Grid\n";
	cout << "3) Enter 'Q' to Quit the Game\n\n" << "Enter your option:\t";

	char option;    // stores a character 

	cin >> option;

	if (option == 'C')
	{
		char fileName[20];
		int noOfWords;
		cout << "\nYou have chosen option 'C'! LETS CREATE A GRID\n" << "Please Enter the name of the file of words list:\t";
		cin >> fileName;
		cout << "\nPlease Enter the number of words in the file:\t";
		cin >> noOfWords;

		ifstream Myfile;
		Myfile.open(fileName);

		if (!Myfile)
		{
			cout << "\nFile could not open"; // file could not open return to home screen
			return false;
		}

		char** WordsArray = new char* [noOfWords];
		int j = 0;


		for (int k = 0; k < noOfWords; k++)    //Stores each word in a array and stores in a 2d array
		{
			char tempArray2[80];
			Myfile.getline(tempArray2, 80);


			int countLetters = 0;
			int a = 0;
			while (tempArray2[a] != '\0')
			{
				a++;
				countLetters++;

			}

			WordsArray[k] = new char[countLetters + 1];
			int i = 0;
			int l = 0;
			while (tempArray2[i] != '\0')
			{
				if (tempArray2[i] == 32)
				{

					i++;
					WordsArray[j][l] = tempArray2[i];
					i++;
					l++;

				}
				else
				{
					WordsArray[j][l] = tempArray2[i];
					i++;
					l++;
				}


			}

			WordsArray[j][l] = '\0';
			j++;

		}

		Myfile.close();

		
		int noOfRows = 0, noOfCols = 0;
		char outputFile[30];

		cout << "\nPlease Enter the number of rows in the Grid:\t";
		cin >> noOfRows;
		cout << "\nPlease Enter the number of cols in the Grid:\t";
		cin >> noOfCols;
		cout << "\nPlease Enter the name of the output file to place Grid:\t";
		cin >> outputFile;

		SortArray_of_Words(WordsArray, noOfWords);
		char** Grid = 0;
		Grid = AllocateGrid(WordsArray, noOfRows, noOfCols); // Grid filled with * in default
		if (Grid == 0)
		{
			cout << "\nGrid cannot be formed!\n"; // if max wordlength is not able to fit in desired grid
			return false;                                                                    // return to home screen
		}


		int prob = 0;  // it is an iteger which decides the probability of words to be placed in through which function
		int count1 = 0;
		int t = 0;
		while (count1 < noOfWords)   // loop which sends word by word and locates in them in grid
		{
			char temp[30];
			int h = 0;
			while (WordsArray[t][h] != '\0')
			{
				temp[h] = WordsArray[t][h];
				h++;
			}
			temp[h] = '\0';

			MakeGrid(Grid,temp,noOfWords,noOfRows,noOfCols,prob);
			t++;
			count1++;

			prob++;
		}

		FillGrid(Grid, noOfRows,noOfCols);
		cout << "\n\nPresenting you the Grid made:\n\n";
		PrintGrid(Grid, noOfRows, noOfCols);
		ofstream Newfile(outputFile);

		for (int c = 0; c < noOfRows; c++) // Stores grid in the new file
		{
			for (int d = 0; d < noOfCols; d++)
			{
				Newfile << Grid[c][d];
			}
			Newfile << endl;
		}

		 for (int i = 0; i < noOfRows; i++)  //deletes the the dynamic array
			{
				delete[] Grid[i];
			}
			Grid = 0;

			return false;
	}
	else
		if (option == 'S')
		{
			char InputFile[30];
			char WordsFile[30];
			char OutputFile[30];
			cout << "\nYou have chosen option 'S'!  Lets Search Words from the Grid\n";   // Inputs from user
			cout << "\nPlease enter the name of the Input file which has a Grid in it:\t";
			cin >> InputFile;
			cout << "\nPlease enter the name of file with inputs of words to be searched:\t ";
			cin >> WordsFile;
			cout << "\nPlease enter the name of the output file to place the result:\t";
			cin >> OutputFile;

			ifstream MyWords;
			MyWords.open(WordsFile);  // Takes words in a 2d static array

			if (!MyWords)
			{
				cout << "Unable to open file";
				return false;
			}

			int rows, cols;
			int words;

			MyWords >> rows;
			MyWords >> cols;
			MyWords >> words;

			char WordArray[30][30];

			for (int i = 0; i < words; i++)
			{
				MyWords >> WordArray[i];
			}
			MyWords.close();


			ifstream MyGrid;
			MyGrid.open(InputFile); // Stores the grid in 2d dynamic array

			if (!MyGrid)
			{
				cout << "Unable to open file";
				return false;
			}

			char** Grid = new char* [rows];   // DYNAMIC ARRAY 

			for (int i = 0; i < rows; i++)
			{
				Grid[i] = new char[cols + 1];
			}

			int k = 0;
			for (int i = 0; i < rows; i++)
			{
				for (k = 0; k < cols; k++)
				{
					MyGrid >> Grid[i][k];
				}
				Grid[i][k] = '\0';
			}
             MyGrid.close();


			ofstream Newfile(OutputFile);
			int R1, R2, C1, C2;
			cout << "\n\n The output of the searched words are:\n\n";
			for (int i = 0; i < words; i++)          //LOOP TO CONFIGURE THE LOCATION WORD BY WORD
			{
				if (CheckRows(Grid, WordArray[i], R1, C1, R2, C2, rows, cols, words) == true)
				{
					Newfile << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}" << endl;
					cout << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}\n" << endl;
				}
				else
					if (CheckColumns(Grid, WordArray[i], R1, C1, R2, C2, rows, cols, words) == true)
					{
						Newfile << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}" << endl;
						cout << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}\n" << endl;
					}
					else
						if (CheckDiagonally(Grid, WordArray[i], R1, C1, R2, C2, rows, cols, words) == true)
						{
							Newfile << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}" << endl;
							cout << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}\n" << endl;
						}
						else
							if (CheckDiagonallyOppo(Grid, WordArray[i], R1, C1, R2, C2, rows, cols, words) == true)
							{
								Newfile << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}" << endl;
								cout << "{" << R1 << "," << C1 << "}" << " {" << R2 << "," << C2 << "}\n" << endl;
							}
							else
							{
								Newfile << "not found" << endl; // if not found then prints this message
								cout << "not found\n" << endl;
							}
			}

			Newfile.close();

			for (int i = 0; i < rows; i++)   // Delete the dynamic Array
			{
				delete[] Grid[i];
			}
			delete[] Grid;

			return false;

		}
		else
		if (option == 'Q')
		{
			return true;
		}
		else
		{
			cout << "\nWrong option chosen!\n";
			return false;
		}

}



int main()
{

	cout << "---------------WELCOME TO WORD SEARCH GAME-------------\n\n";
	
	char flag;
	while (!ProcessMenu())
	{
		cout << "Press any key to return to home page\n";   // calls the process menu function again until it is in true state
		cin >> flag;
		cout << "\nReturning to the home page.....\n\n\n";
	}

	cout << "\nThank you for playing the game! BYE \n";


}
