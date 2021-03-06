// sorting problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <string>
#include <omp.h>


using namespace std;

string test[10];
string array10k[10000];
string array50k[50000];
string array100k[100000];
string array150k[150000];
string array200k[200000];
string array250k[250000];
string array300k[300000];
string array350k[350000];
string array400k[400000];
string array450k[450000];
string array500k[500000];
string array550k[550000];
string array600k[600000];


void swap(string *a, string *b) {
	string temp;
	temp =*a;
	*a = *b;
	*b = temp;	
}
void selection(string *input, int round) {
	#pragma omp parallel for
	for (int i = 0; i < round-1; i++) {
		int small = i;
		#pragma omp parallel for
		for (int j = i+1; j < round; j++) {
			if (input[small] >= input[j]) {
				small = j;
			}
		}
		if (small != i) {
			string temp;
			swap(input[small], input[i]);
		}
			

	}
}
void clear(string *array, int size) {
	for (int i = 0; i <= size; i++) {
		array[i] = "";
	}
}
void refresh() {
	clear(test, 10);
	clear(array10k,10000);
	clear(array50k,50000);
	clear(array100k, 100000);
	clear(array150k, 150000);
	clear(array200k, 200000);
	clear(array250k, 250000);
	clear(array300k, 300000);
	clear(array350k, 350000);
	clear(array400k, 400000);
	clear(array450k, 450000);
	clear(array500k, 500000);
	clear(array550k, 550000);
	clear(array600k, 600000);

	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 6; j++) {
			test[i] += alphabet[rand() % 26];
		}
	}
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < 6; j++) {
			array10k[i] += alphabet[rand() % 26];
		}
		//cout << array10k[i] << "\t";
	}

	for (int i = 0; i < 50000; i++) {
		for (int j = 0; j < 6; j++) {
			array50k[i] += alphabet[rand() % 26];
		}
		//cout << array50k[i] << "\t";
	}
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 6; j++) {
			array100k[i] += alphabet[rand() % 26];
		}
		//cout << array100k[i] << "\t";
	}
	for (int i = 0; i < 150000; i++) {
		for (int j = 0; j < 6; j++) {
			array150k[i] += alphabet[rand() % 26];
		}
		//cout << array150k[i] << "\t";
	}
	for (int i = 0; i < 200000; i++) {
		for (int j = 0; j < 6; j++) {
			array200k[i] += alphabet[rand() % 26];
		}
		//cout << array200k[i] << "\t";
	}
	for (int i = 0; i < 250000; i++) {
		for (int j = 0; j < 6; j++) {
			array250k[i] += alphabet[rand() % 26];
		}
		//cout << array250k[i] << "\t";
	}
	for (int i = 0; i < 300000; i++) {
		for (int j = 0; j < 6; j++) {
			array300k[i] += alphabet[rand() % 26];
		}
		//cout << array300k[i] << "\t";
	}

	for (int i = 0; i < 350000; i++) {
		for (int j = 0; j < 6; j++) {
			array350k[i] += alphabet[rand() % 26];
		}
		//cout << array350k[i] << "\t";
	}

	for (int i = 0; i < 400000; i++) {
		for (int j = 0; j < 6; j++) {
			array400k[i] += alphabet[rand() % 26];
		}
		//cout << array400k[i] << "\t";
	}

	for (int i = 0; i < 450000; i++) {
		for (int j = 0; j < 6; j++) {
			array450k[i] += alphabet[rand() % 26];
		}
		//cout << array450k[i] << "\t";
	}
	for (int i = 0; i < 500000; i++) {
		for (int j = 0; j < 6; j++) {
			array500k[i] += alphabet[rand() % 26];
		}
		//cout << array500k[i] << "\t";
	}

	for (int i = 0; i < 550000; i++) {
		for (int j = 0; j < 6; j++) {
			array550k[i] += alphabet[rand() % 26];
		}
		//cout << array550k[i] << "\t";
	}
	for (int i = 0; i < 600000; i++) {
		for (int j = 0; j < 6; j++) {
			array600k[i] += alphabet[rand() % 26];
		}
		//cout << array600k[i] << "\t";
	}
}
void selectoutput(string *array,int size) {
	double long timer = clock();
	selection(array, size);
	timer = clock() - timer;
	cout << size <<"\t"<< (timer / CLOCKS_PER_SEC)*1000 << "ms" << endl;
}
void maxheap(string *array,int size,int index) {
	int big = index;
	int left = index * 2+1;
	int right = index * 2 + 2;
	if (left <size && array[left]>array[big]) {
		big = left;
	}
	if (right<size && array[right]>array[big]) {
		big = right;
	}
	if (big != index) {
		swap(array[big], array[index]);
		maxheap(array, size, big); //recursive call for sub tree
	}
}
void heapsort(string *array, int turns) {
	#pragma omp parallel for
	for (int i = turns / 2 - 1; i >= 0; i--) {
		maxheap(array, turns, i);
	}
	#pragma omp parallel for
	for (int i = turns - 1; i >= 0; i--) {
		maxheap(array, i, 0);
		swap(array[i], array[0]);
	
		
	}
}
void heapsorttest(string *array, int turns) {
	//for rearrangement
	for (int i = turns / 2 - 1; i >= 0; i--) {
		maxheap(array, turns, i);
	}
	for (int i = turns - 1; i >= 0; i--) {
		maxheap(array, i, 0);
		cout << "\n here is heapsort" << endl;
		for (int i = 0; i <= 10; i++) {
			
			cout << array[i] << "\t";
		}
		swap(array[i], array[0]);
		


	}
}
void heapoutput(string *array, int size) {
	double timer = clock();
	heapsort(array, size);
	timer = clock() - timer;
	cout << size << "\t" << (timer / CLOCKS_PER_SEC) * 1000 << "ms" << endl;
}
void merge(string *array, int left, int mid, int right) {
	int lcounter = mid - left + 1;
	int rcounter = right - mid;
	string *ltemp = new string[lcounter];
	string *rtemp = new string[rcounter];
	//copy array to temp
	#pragma omp parallel for
	for (int i = 0; i < lcounter; i++) {
		ltemp[i] = array[left + i];
	}
	#pragma omp parallel for
	for (int j = 0; j < rcounter; j++) {
		rtemp[j] = array[mid + 1 + j];
	}
	int lpoint = 0;
	int rpoint = 0;
	int index =left;
	//rewrite it to array
	while (lpoint < lcounter && rpoint < rcounter) {
		if (ltemp[lpoint] <= rtemp[rpoint]) {
			array[index] = ltemp[lpoint];
			lpoint++;
		}
		else {
			array[index] = rtemp[rpoint];
			rpoint++;
		}
		index++;
	}
	while (lpoint < lcounter) {
		array[index] = ltemp[lpoint];
		lpoint++;
		index++;
	}
	while (rpoint < rcounter) {
		array[index] = rtemp[rpoint];
		rpoint++;
		index++;
	}
	delete [] ltemp;
	delete []rtemp;
}
void recursive(string *array, int left,  int right) {
	if (left < right) {
		int mid = left + (right - left) / 2; // == (left+right)/2 and avoid overflow
		recursive(array, left, mid);
		recursive(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}
void recursiveoutput(string *array, int size) {
	double timer = clock();
	recursive(array,0, size-1);
	timer = clock() - timer;
	cout << size << "\t" << (timer / CLOCKS_PER_SEC) * 1000 << "ms" << endl;
}
void iterative(string *array,int turns) {
	string *answer = new string[turns];
	for (int i = 1; i < turns; i*=2) {	//this is outer shell
		for (int left = 0; left + i < turns; left+=i*2) {	//this is the divide system
			int right = left + i;
			int rend = right + i;
			if (rend > turns) {
				rend = turns;
			}
			int lside = left;
			int rside = right;
			int index = left;
			while(lside <right && rside<rend){
				if (array[lside] <= array[rside]) {
					answer[index] = array[lside];
					lside++;
			}
				else {
					answer[index] = array[rside];
					rside++;
				}
				index++;
			}
			while (lside < right) {
				answer[index] = array[lside];
				lside++;
				index++;
			}
			while (rside < rend) {
				answer[index] = array[rside];
				rside++;
				index++;
			}
			for (int i = left; i < rend; i++) {
				array[i] = answer[i];
		}	
	}
	
	}
	delete [] answer;
}
void iterativeoutput(string *array, int size) {
	double timer = clock();
	iterative(array, size);
	timer = clock() - timer;
	cout << size << "\t" << (timer / CLOCKS_PER_SEC) * 1000 << "ms" << endl;
}


int main()
{
	cout << "heap" << "\t time" << endl;
	//this is test for heap
/*	for (int i = 0; i < 10; i++) {
		cout << test[i] << "\t";
	}
	double timer = clock();
	heapsort(test, 10);
	timer = clock() - timer;
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		cout << test[i] << "\t";
	}
	cout << "\n" << "time:" << timer  << "ticks" << endl;
	*/
	heapoutput(array10k, 10000);
	heapoutput(array50k, 50000);
	heapoutput(array100k, 100000);
	heapoutput(array150k, 15000);
	heapoutput(array200k, 200000);
	heapoutput(array250k, 250000);
	heapoutput(array300k, 300000);
	heapoutput(array350k, 350000);
	heapoutput(array400k, 400000);
	heapoutput(array450k, 450000);
	heapoutput(array500k, 500000);
	heapoutput(array550k, 550000);
	heapoutput(array600k, 600000);

	refresh();
	cout << "recursive mergesort" << "\t time" << endl;
	//here is testing for recursive
/*	for (int i = 0; i < 10; i++) {
		cout << test[i] << "\t";
	}
	timer = clock();
	recursive(test,0, 9);
	timer = clock() - timer;
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		cout << test[i] << "\t";
	}
	cout << "\n" << "time:" << timer << "ticks" << endl;
*/	
	recursiveoutput(array10k, 10000);
	recursiveoutput(array50k, 50000);
	recursiveoutput(array100k, 100000);
	recursiveoutput(array150k, 150000);
	recursiveoutput(array200k, 200000);
	recursiveoutput(array250k, 250000);
	recursiveoutput(array300k, 300000);
	recursiveoutput(array350k, 350000);
	recursiveoutput(array400k, 400000);
	recursiveoutput(array450k, 450000);
	recursiveoutput(array500k, 500000);
	recursiveoutput(array550k, 550000);
	recursiveoutput(array600k, 600000);

	cout << "itertative mergesort" << "\t time" << endl;
	//here is test for iterative
/*	for (int i = 0; i < 10; i++) {
		cout << test[i] << "\t";
	}
	double timer = clock();
	iterative(test, 10);
	timer = clock() - timer;
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		cout << test[i] << "\t";
	}
	cout << "\n" << "time:" << timer << "ticks" << endl;
*/
	iterativeoutput(array10k, 10000);
	iterativeoutput(array50k, 50000);
	iterativeoutput(array100k, 100000);
	iterativeoutput(array150k, 150000);
	iterativeoutput(array200k, 200000);
	iterativeoutput(array250k, 250000);
	iterativeoutput(array300k, 300000);
	iterativeoutput(array350k, 350000);
	iterativeoutput(array400k, 400000);
	iterativeoutput(array450k, 450000);
	iterativeoutput(array500k, 500000);
	iterativeoutput(array550k, 550000);
	iterativeoutput(array600k, 600000);
	
		
	refresh();
	cout << "selection" << "\t time" << endl;
	//this is test for selection
	/*	for (int i = 0; i < 10; i++) {
	cout << test[i] << "\t";
	}
	double timer = clock();
	selection(test, 10);
	timer = clock() - timer;
	cout << "\n";
	for (int i = 0; i < 10; i++) {
	cout << test[i] << "\t";
	}
	cout << "\n" << "time:" << timer  << "ticks" << endl;

	*/
/*	selectoutput(array10k,10000);
	selectoutput(array50k,50000);
	selectoutput(array100k, 100000);
	selectoutput(array150k, 150000);
	selectoutput(array200k, 200000);
	selectoutput(array250k, 250000);
	selectoutput(array300k, 300000);
	selectoutput(array350k, 350000);
	selectoutput(array400k, 400000);
	selectoutput(array450k, 450000);
	selectoutput(array500k, 500000);
	selectoutput(array550k, 550000);
	selectoutput(array600k, 600000);
*/	
	system("pause");
    return 0;
}


