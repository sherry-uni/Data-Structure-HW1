/*
This code can be compiled and run ok.

This is to sort couple of numbers by using insertion sort and merge sort

usage:
	insmg1 xxx
	where xxx are numbers you've put and want to sort in order by using insertion sort and merge sort
input file:
	none
output files:
	none
compile:
    g++ -o d44051208 d44051208.cpp
pseudocode:
    print ("Please input n:")
    read num
    array_A <- an 2D-array from 1 to num
    array_B <- an 2D-array from 1 to num
    print ("Please input") num (" real numbers:")
    for i(1 to num)
        do read array_A[1][i]
    printout_array(array_A, 1, num)
    duplicate_array(array_A, array_B, 1, num)
    print("By insertion sort:")
    ins_sort(array_A, 1, num)
    printout_array(array_A, 1, num)
    if is_ascending(array_A, num) =true
        then print("Great!! It is in ascending order!!")
    mg_sort(array_B, 1, num)
    printout_array(array_B, 1, num)
    if is_ascending(array_B, num) =true
        then print("Great!! It is in ascending order!!")

    func printout_array(**a,b,c)
        for j(1 to b)
            for i(1 to c)
                do print a[j][i]
    func duplicate_array(**a, **b, c, d)
        for j(1 to c)
            for i(1 to d)
                do b[j][i] = a[j][i]
    func ins_sort(**a, b, c)
        for j(1 to b)
            for i(2 to c)
                do key <- a[j][i]
                    k <- i-1
                    while k>=0 && a[j][k]>key
                        do a[j][k+1]=a[j][k]
                        k <- k-1
                    a[j][k+1] <- key
    func is_ascending(**a, b)
        for i(2 to b)
            if a[1][i-1]<a[1][i]
                then a=0
            else a=-1
            if a=0
                then return true
            else return false
     func mg_sort(**a, b, d)
        if (b < d)
            c <- floor (b + d) / 2
            mg_sort(a, b, c)
            mg_sort(a, c + 1, d)
            merge(a, b, c, d)
     func merge(**a, b, c, d)
     n1 <- c-b+1
     n2 <- d-c
     L <- an array from 1 to n1
     R <- an array from 1 to n2
     for i(1 to n1)
        do L[i]<-a[1][b + i - 1]
     for j(1 to n2)
        do R[i]<-a[1][c+j]
	 L[n1+1]<-huge number
	 R[n2+1]<-huge number
	 a1<-0, a2<-0
	 for k(b to c)
        if L[a1]<=R[a2]
            then a[1][k]<-L[a1]
            a1+1
        else
            a[1][k]<-R[a2]
            a2+1
coded by Chen YU-HSUAN, ID: D44051208, email: yusyuanchen0623@gmail.com
date: 2019/09/27
*/
#include<iostream>
#include<math.h>
using namespace std;

void printout_array(int**, int, int);
void duplicate_array(int**, int**, int, int);
void ins_sort(int**, int, int);
bool is_ascending(int**, int);
void mg_sort(int**, int, int);
void merge(int**, int, int, int);

int main() {
	int num;
	cout << "Please input n:" << endl;
	cin >> num;//determine the array size
	int **array_A = new int*[1];
	for (int i = 0; i < 1; i++) {
		array_A[i] = new int[num];
	}//create a two dimension array A for further use
	int **array_B = new int*[1];
	for (int i = 0; i < 1; i++) {
		array_B[i] = new int[num];
	}//create a two dimension array B for further use
	cout << "Please input"<<num<<" real numbers:" << endl;
	for (int i = 0; i < num; i++) {
		cin >> array_A[0][i];//input numbers
	}
	printout_array(array_A, 1, num);//print out array A
	duplicate_array(array_A, array_B, 1, num);//array B copes array A
	cout << "By insertion sort:" << endl;
	ins_sort(array_A, 1, num);//sort function
	printout_array(array_A, 1, num);//show the sorted outcome
	if (is_ascending(array_A, num) == true) {
		cout << "Great!! It is in ascending order!!"<<endl;
	}//checking the accuracy of outcome
	cout << "By merge sort:" << endl;
	mg_sort(array_B, 1, num);
	printout_array(array_B, 1, num);
	if (is_ascending(array_B, num) == true) {
		cout << "Great!! It is in ascending order!!";
	}
	delete array_A;
	delete array_B;
	return 0;
}

void printout_array(int **array_ptr, int m, int n) {
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n - 1; i++) {
			cout << array_ptr[j][i] << " , ";
		}
		cout << array_ptr[j][n - 1] << endl;
	}

}

void duplicate_array(int **array_ptr_A, int**array_ptr_B, int m, int n) {
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			array_ptr_B[j][i] = array_ptr_A[j][i];
		}
	}
}

void ins_sort(int**array_ptr, int m, int n) {
	int key;//store the temp moving value
	int k;
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			key = array_ptr[j][i];
			k = i - 1;
			while (k >= 0 && array_ptr[j][k] > key)//compare the value one step forward
			{
				array_ptr[j][k + 1] = array_ptr[j][k];
				k = k - 1;//keep comparing the value one step forward
			}
			//jump out off the loop while nothing left to compare
			array_ptr[j][k + 1] = key;
		}
	}
}

bool is_ascending(int**array_ptr, int n) {
	int a;
	for (int i = 1; i < n; i++) {
		if (array_ptr[0][i-1] < array_ptr[0][i]) {
			a = 0;
		}
		else
		{
			a = -1;
		}
	}
	if (a == 0) {
		return true;
	}
	else if (a == -1)
	{
		return false;
	}
}


void mg_sort(int**array_ptr, int p, int r) {
	if (p < r) {
		int q = floor((p + r) / 2);//mid-point
		mg_sort(array_ptr, p, q);//divide-conquer
		mg_sort(array_ptr, q + 1, r);//divide-conquer
		merge(array_ptr, p, q, r);//merge
	}
}

void merge(int**array_ptr, int a, int b, int c) {
	int n1 = b - a + 1;//amount of left
	int n2 = c - b;//amount of right
	int *array_L_ptr = new int[n1];//create an new array to store left part
	int *array_R_ptr = new int[n2];//create an new array to store right part
	for (int i = 0; i < n1; i++) {
		array_L_ptr[i] = array_ptr[0][a + i - 1];
	}//put numbers in left array
	for (int j = 0; j < n2; j++) {
		array_R_ptr[j] = array_ptr[0][b + j];
	}//put numbers in right array
	array_L_ptr[n1] = 2147483647;
	array_R_ptr[n2] = 2147483647;

	int a1 = 0;
	int a2 = 0;
	for (int k = a-1; k < c ; k++) {
		if (array_L_ptr[a1] <= array_R_ptr[a2]) {
			array_ptr[0][k] = array_L_ptr[a1];
			a1++;
		}
		else
		{
			array_ptr[0][k] = array_R_ptr[a2];
			a2++;
		}
	}
}

