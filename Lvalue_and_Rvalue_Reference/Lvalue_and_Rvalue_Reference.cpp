/*
	understanding rvalue and lvalue

	why do i care?
	1.understand c++ construct, and decypher compiler errors or warnings.
	2.c++ 11 introduced rvalue reference

	simplified definition
	lvalue--an object that occupies some identifiable location in memory
	rvalue--any object that is not a lvalue
*/


#include <iostream>

class Dog
{
	//class body
	
};

int main()
{
	//lvalue example
	int i;  //i is a lvalue
	int* p = &i; //i is address is identifiable
	i = 2; //memory content is modified

	Dog dog1; //lvalue of user defined type(class), most variables in c++ code are lvalues


	/************************************************************************************/
	//rvalue example
	int x = 2; //2 is an rvalue
	int x = i + 2; //(i+2) is an rvalue
	int* p = &(i + 2); //error
	2 = i; //error

	Dog dog2 = dog(); //dog() is rvalue of user defined type(class)

	int sum(int x, int y)
	{
		return x + y;
	}
	int i = sum(3, 4); //sum(3,4) is rvalue

	/***************************************************************************************/
	//rvalue: 2, i+2, dog(), sum(3,4), x+y
	//lvalue: x, i, d1, p

	/***************************************************************************************/
	//reference (or lvalue reference)
	int i;
	int& r = i;

	int& r = 5; //error

	//exception: constant lvalue reference can be assigned a rvalue
	const int& r = 5;

	/*****************************************************************************************/
	int square(int& x) {return x*x}
	squre(i); //ok
	squre(40); //error

	int squre(const int& x) {return x*x}
	squre(i); //ok
	squre(40);//ok

	/****************************************************************************************/
	//lvalue can be used to create an rvalue
	int i = 1;
	int x = i + 2;
	int x = i;

	//rvalue can be used to create an lvalue
	int v[3];
	*(v + 2) = 4;

	/****************************************************************************************/
	//misconception 1: function or operator always yields rvalues.
	int x = i + 3;
	int y = sum(3,4);

	int myglobal;
	int& foo()
	{
		return myglobal;
	}
	foo() = 50;

	//a more common example:
	array[3] = 50; // operator [] almost always genrates lvalue

	/******************************************************************************************/
	//misconception 2: lvalues are modifiable
	//c language: lvalue means "value suitable for left-hand-side of assignment"
	const int c = 1; //c is a lvalue
	c = 2; //error, c is not modifiable

	/*****************************************************************************************/
	//misconception 3: rvalue are not modifiable
	i + 3 = 6; //error
	sum(3, 4) = 7; //error

	//it is not true for user defined type(class)
	Dog dog;
	dog.bark(); //bark() may change the state of the dog object.

	/*****************************************************************************************/
	//Summary:
	//1. every c++ expression yield either an rvalue or a lvalue
	//2. if the expression has an identifiable memory address, it is lvalue; otherwise, rvalue


	return 0;
}