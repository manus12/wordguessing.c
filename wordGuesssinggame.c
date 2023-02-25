#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

char guess[10];
int chances;

// FUNCTION
void update_dashes(char guess[], int index, char dashes[], char secret_word[]);
char get_guess(char secret_word[])
{
	// guesses left
	if (strlen(secret_word) > 6)
	{
		chances = 5;
	}
	else
	{
		chances = strlen(secret_word) - 1;
	}
	// DASHES
	char dashes[strlen(secret_word)];
	// this array is to store entered guesses to stop when user enters again same value
	char guesses[strlen(secret_word)];
	for (int i = 0; i < strlen(secret_word); i++)
	{
		// initializing all values to null to remove garbage
		guesses[i] = '\0';
	}
	// printing dashes
	for (int i = 0; i < strlen(secret_word); i++)
	{
		dashes[i] = '_';
		printf(" %c", dashes[i]);
	}
	int k = 0, j = 0;
	// guess checking here
	while (chances > 0)
	{
		printf("\n%d guesses left", chances);
		printf("\nEnter the letter\n");
		int i, count = 0, l, count1 = 0;
		gets(guess);
		if (strlen(guess) != 1)
		{
			// if guess is of more than one word the program again prompts
			printf("Your guess must be of one character.");
			continue;
		}
		if (isdigit(guess[0]) || isupper(guess[0]) || isblank(guess[0]))
		{
			// if guess is a upper case or any digit so the program again prompts
			printf("Your guess must be a lowercase alphabet.");
			continue;
		}
		if (isalpha(guess[0]))
		{
			// storing guess into guesses
			guesses[j] = guess[0];
			j++;
			for (int a = 0; a < strlen(guesses); a++)
			{
				if (guesses[a] == guess[0])
				{
					count1++;
				}
			}
			// if guess is previously entered show message and again prompt
			if (count1 > 1)
			{
				printf("You have entered this previously.");
				count1 = 0;
				continue;
			}
			// if guess in the word.
			for (i = 0; i < strlen(secret_word); i++)
			{
				if (guess[0] == secret_word[i] && count != 1)
				{
					printf("Your guess is in the word!\n");
					int index = i;
					update_dashes(guess, index, dashes, secret_word);
					count++;
				}
			}
			// if guess not in word
			if (count == 0)
			{
				printf("Incorrect guess.\n");
				chances--;
				if (chances == 0)
				{
					// terminating program if chances finished
					printf("You lose, the word was ");
					for (i = 0; i < strlen(secret_word); i++)
					{
						printf("%c", secret_word[i]);
					}
					exit(0);
				}
				// printing dashes again
				for (i = 0; i < strlen(secret_word); i++)
				{
					printf(" %c", dashes[i]);
				}
				continue;
			}
		}
		else
		{
			printf("Please enter a lowercase alphabet\n");
			continue;
		}
	}
}
void update_dashes(char guess[], int index, char dashes[], char secret_word[])
{
	int i, l = 0, count;
	// replacing
	for (i = 0; i < strlen(secret_word); i++)
	{
		if (guess[0] == secret_word[i])
		{
			dashes[i] = guess[0];
		}
	}
	// replacing preview
	for (i = 0; i < strlen(secret_word); i++)
	{
		printf(" %c", dashes[i]);
	}
	//  To stop, if word is completed correctly (even if "chances" are left)
	for (count = 0; count < strlen(secret_word); count++)
	{
		if (dashes[count] == secret_word[count])
		{
			l++;
		}
	}
	if (l == strlen(secret_word))
	{
		printf("\nYou won Congrats.\n");
		exit(0);
	}
	count = 0;
	l = 0;
}

int random(int n) // Function to generate random number
{
	srand(time(NULL));
	int num = rand() % n;
	return num;
}

int main()
{
	char fruit[][20] = {"apple", "watermelon", "orange", "pear", "cherry",
						"stawberry", "grape", "mango", "pomegranate", "plum",
						"apricot", "grapefruit", "melon", "banana", "coconut", "peach",
						"avocado", "custardapple", "guava", "pumpkin", "lychee", "sapodilla",
						"dates", "fig", "cranberry", "honepoot", "jackfruit", "dragonfruit",
						"kiwi", "olive", "sugarcane"};

	char country[][20] = {"indonesia", "china", "america", "india",
						  "dubai", "turkey", "afghanistan", "australia", "bangladesh", "austria", "maldives", "singapore",
						  "malaysia", "germany", "france", "norway", "kuwait", "brazil", "qatar", "russia",
						  "zinbabwe", "portugal"};
	char food[][20] = {"rice", "milk", "chocolate", "pasta", "lasagne", "chowmein", "burger", "broast", "roll", "sandwich", "steak", "kebab", "spaghetti", "salad", "seafood", "bacon", "nuggets", "mushroom", "mandi", "hotdogs", "sausage"};
	char Animal[][20] = {"chicken", "duck", "deer", "cow", "buffalow", "horse",
						 "elephant", "goat", "lion", "zebra", "cat", "dog", "fish", "camel",
						 "donkey", "parrot", "butterfly", "eagle"};
	char things[][20] = {"pillow", "fork", "book", "boat", "table", "panaflex", "banner", "camera", "bolt", "bucket", "bulb", "almirah", "album", "cloth", "desk", "container", "stove", "heater", "cutlery"};
	char movie[][20] = {"jumanji", "braveheart", "ironman", "maverick", "avatar", "martian", "interstellar", "zootopia", "virus", "titanic", "extraction", "gravity", "inception", "matrix", "alien", "morbius", "dune", "tenet", "sherdil", "malik"};

	system("cls"); // clearing screen before game
	srand(time(NULL)); // to flush memory so the system generate a new number
	char chr[5], chr1[5];
	char secret_word[20];
	int num, a = 20;
	printf("\t***** Welcome to word guessing game! ***** \n");
	printf("There are two modes Easy and Hard.\nIn easy mode you have to select the category from which you want the secret word to be chosen and in hard mode the secret word will be selected from any random category.\n");
	while (1)
	// loop using to validate user for incorrect inputs
	{
		printf("Enter mode (Press E for Easy) or (Press H for Hard): ");
		gets(chr1);
		fflush(stdin);
		if (strlen(chr1) == 1 && isalpha(chr1[0]))
		{
			if (chr1[0] == 'e' || chr1[0] == 'E')
			// EASY Mode
			{
				printf("Choose the category\n");
				while (1)
				// loop using to validate user for incorrect inputs
				{
					printf("Press a for Animal\n");
					printf("Press f for Fruits\n");
					printf("Press c for country\n");
					printf("Press t for Thing\n");
					printf("Press d for Food\n");
					printf("Press m for Movies\n");
					printf("Enter the option: ");
					scanf("%s", &chr);
					fflush(stdin);
					if (strlen(chr) == 1 && isalpha(chr[0]))
					{
						// generating word of user's desired category
						switch (chr[0])
						{
						case 'd':
						case 'D':
							num = random(a);
							strcpy(secret_word, food[num]); // used this function instead of using for loop because the program looks lengthy
							break;
						case 'a':
						case 'A':
							num = random(a);
							strcpy(secret_word, Animal[num]);
							break;
						case 'F':
						case 'f':
							num = random(a);
							strcpy(secret_word, fruit[num]);
							break;
						case 'c':
						case 'C':
							num = random(a);
							strcpy(secret_word, country[num]);
							break;
						case 't':
						case 'T':
							num = random(a);
							strcpy(secret_word, things[num]);
							break;
						case 'm':
						case 'M':
							num = random(a);
							strcpy(secret_word, movie[num]);
							break;
						default:
							printf("Invalid option\n\n");
							continue;
							// break;
						}
						break;
					}
					else
					{
						printf("Invalid input\n\n");
						continue;
					}
				}
			}
			else if (chr1[0] == 'h' || chr1[0] == 'H')
			{
				// HARD MODE
				int num1 = 6;
				// generating a number to generate a random category
				num = random(num1); 
				// selecting categories randomnly
				if (num == 0)
				{
					num1 = random(a);
					strcpy(secret_word, food[num1]); // used this function instead of using for loop because the program looks lengthy
				}
				else if (num == 1)
				{
					num1 = random(a);
					strcpy(secret_word, Animal[num1]); 
				}
				else if (num == 2)
				{
					num1 = random(a);
					strcpy(secret_word, fruit[num1]);
				}
				else if (num == 3)
				{
					num1 = random(a);
					strcpy(secret_word, country[num1]);
				}
				else if (num == 4)
				{
					num1 = random(a);
					strcpy(secret_word, things[num1]);
				}
				else if (num == 5)
				{
					num1 = random(a);
					strcpy(secret_word, movie[num1]);
				}
			}
			else
			{
				printf("Invalid choice\n");
				continue;
			}
			break;
		}
		else
		{
			printf("Invalid input\n");
			continue;
		}
	}
	// Now word generated
	// calling function for further game steps
	get_guess(secret_word);
	return 0;
}