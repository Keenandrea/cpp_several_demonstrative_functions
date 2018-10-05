#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
using namespace std;

//size of char array
const int SIZE = 80;

//the prototypes
int revnum(int);
void revstr(char[]);
void queue_a_string(char[]);
void print_sorted(int[], int);
void recursive_sort(int[], int, int);


int main()
{
//PART 1==========================================================//
int num, rev;

//the user is prompted to enter an integer number of nine digits
cout << "Enter a number, integers below 999,999,999 only, please:\n";
//get data
cin >> num;

//function called
rev = revnum(num);

cout << "\nHere is the number you entered, palindromed:\n";
//show data
cout << rev;
//give space
cout << endl;
//END PART 1======================================================//

//PART 2==========================================================//
//hold sentence
char line[SIZE];

cout << "\nEnter a sentence of no more than ";
cout << (SIZE - 1) << " characters:\n";
//skip newline
cin.ignore();
//store to 79 characters
cin.getline(line, SIZE);

cout << "\nHere is the sentence you entered, palindromed:\n";
//function call
revstr(line);
//END PART 2======================================================//

//PART 3==========================================================//
cout << "\n\nHere is the sentence you entered, ";
cout << "queued, then dequeued:\n";
//STL queue function
queue_a_string(line);
//END PART 3======================================================//

//PART 4==========================================================//
srand(time(NULL));
//array of randoms
int arr[20] = {};

int size = sizeof(arr) / sizeof(arr[0]);

cout << "\n\nHere are your 20 random numbers:\n";

//set array with random numbers
for(int i = 0; i < 20; i++)
{
	arr[i] = rand() % 100;
	cout << arr[i] << " ";
}

//arr recursive selection sort
recursive_sort(arr, 0, size);
//print the sorted array
print_sorted(arr, size);
//END PART 4======================================================//

system ("pause");
return 0;
}


//=====================================================//
//recursive function displays integers in reverse order//
//=====================================================//
int revnum(int num)
{
static int temp, sum;
//boundry checking
if(num > 999999999)
{
	cout << "Keep you number below 999,999,999\n";
	return 0;
}
	else if(num > 0)
	{
		temp = num % 10;
		sum = sum * 10 + temp;
		//calling itself
		revnum(num / 10);
	}
		else
		{
			return sum;
		}
}
//=====================================================//
//=====================================================//


//=====================================================//
//STL stack function reverses string order=============//
//=====================================================//
void revstr(char str[])
{
//define STL stack vector implement 
stack< char, vector<char> > cString;

//length of string
int n = strlen(str);

//counter 
int i = 0;

	//until the c-string ends
	for(i = 0; i < n + 1; i++)
	{
		//push char on stack
		cString.push(str[i]);
	}
	//until c-string starts
	for(i = 0; i < n; i++)
	{
		//remove top
		cString.pop();
		//reference top value
		str[i] = cString.top();
		cout << str[i];	
	}
}
//=====================================================//
//=====================================================//


//=====================================================//
//STL queue function holds characters of a string======//
//=====================================================//
void queue_a_string(char str[])
{
//opposite
revstr(str);

//make queue object
queue<char> cQueue;

	//put string characters in STL queue
	for(int i = 0; i < strlen(str); i++)
	{
		cQueue.push(str[i]);
	}
		//give space between
		cout << endl << endl;

		//dequeue characters from STL queue
		for(int i = 0; i < strlen(str); i++)
		{
			cout << cQueue.front();
			cQueue.pop();
		}
}	
//=====================================================//
//=====================================================//


//=====================================================//
//recursive function to perform selection sort=========//
//=====================================================//
void recursive_sort(int arr[], int zero, int size)
{
int min = zero;

//find the min element in the array
for(int i = zero + 1; i < size; i++)
{
	//if arr[i] element is
	//less, then it is the
	//new minimum element
	if(arr[i] < arr[min])
	{
		//update
		min = i;
	}
}

	//swap the minimum element
	//in subarray with arr[i]
	swap(arr[min], arr[zero]);
		
		if(zero + 1 < size)
		{ 
			//recursive function calling pass 
			recursive_sort(arr, zero + 1, size);
		}
}
//=====================================================//
//=====================================================//


//=====================================================//
//function to print elements of sorted array===========//
//=====================================================//
void print_sorted(int arr[], int size)
{
cout << "\n\nHere are your 20 random numbers, sorted:\n";

	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	//give space
	cout << endl;
}
//=====================================================//
//=====================================================//


