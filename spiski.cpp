// Console_Menu_Alpha.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
class Filework{
public:Filework() {};
	   void MainMenu();
	   void FunctionCall();
	   void FileworkMenu();
	   void EditMenu();
	   void DelMenu();
	   void AddMenu();
};
void Filework::FunctionCall(){
	system("cls");
	cout << "Âûçîâ ôóíêöèè";
	getch();
}
void GTXY(short x, short y){
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {0,x};
	SetConsoleCursorPosition(StdOut,coord);
	cout << " ";
	coord.Y = y;
	SetConsoleCursorPosition(StdOut,coord);
	cout << "*";
}
void Filework::FileworkMenu(){
	char c(0);
	int point(0);
	system("cls");
	cout << "*\t1 - Ôàéë 1\n\t2 - Ôàéë 2\n\t3 - Ôàéë 3\n\t4 - Ôàéë 4\n\t5 - Ôàéë 5\n\t0 - Íàçàä";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,5);
			point = 5;
		}
		else if( c == 49 ) {
			GTXY(point,0);
			point = 0;
		}
		else if( c == 50 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 51 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 52 ) {
			GTXY(point,3);
			point = 3;
		}
		else if( c == 53 ) {
			GTXY(point,4);
			point = 4;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 0 ) point = 5;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 5 ) point = 0;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 5 ) break;
			else FunctionCall();
			system("cls");
	        cout << "*\t1 - Ôàéë 1\n\t2 - Ôàéë 2\n\t3 - Ôàéë 3\n\t4 - Ôàéë 4\n\t5 - Ôàéë 5\n\t0 - Íàçàä";
			point = 0;
		}
		else if( c == 27 ) break;
	}
}
void Filework::EditMenu(){
	char c(0);
	int point(0);
	system("cls");
	cout << "*\t1 - qqq\n\t2 - www\n\t3 - eee\n\t4 - rrr\n\t0 - Íàçàä";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,4);
			point = 4;
		}
		else if( c == 49 ) {
			GTXY(point,0);
			point = 0;
		}
		else if( c == 50 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 51 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 52 ) {
			GTXY(point,3);
			point = 3;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 0 ) point = 4;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 4 ) point = 0;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 4 ) break;
			else FunctionCall();
			system("cls");
	        cout << "*\t1 - qqq\n\t2 - www\n\t3 - eee\n\t4 - rrr\n\t0 - Íàçàä";
			point = 0;
		}
		else if( c == 27 ) break;
	}
}
void Filework::AddMenu(){
	char c(0);
	int point(0);
	system("cls");
	cout << "*\t1 - 111\n\t2 - 222\n\t3 - 333\n\t0 - Íàçàä";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,3);
			point = 3;
		}
		else if( c == 49 ) {
			GTXY(point,0);
			point = 0;
		}
		else if( c == 50 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 51 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 0 ) point = 3;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 3 ) point = 0;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 3 ) break;
			else FunctionCall();
			system("cls");
	        cout << "*\t1 - 111\n\t2 - 222\n\t3 - 333\n\t0 - Íàçàä";
			point = 0;
		}
		else if( c == 27 ) break;
	}
}
void Filework::DelMenu(){
	char c(0);
	int point(0);
	system("cls");
	cout << "*\t1 - 123\n\t2 - 213\n\t3 - 321\n\t0 - Íàçàä";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,3);
			point = 3;
		}
		else if( c == 49 ) {
			GTXY(point,0);
			point = 0;
		}
		else if( c == 50 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 51 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 0 ) point = 3;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 3 ) point = 0;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 3 ) break;
			else FunctionCall();
			system("cls");
	        cout << "*\t1 - 123\n\t2 - 213\n\t3 - 321\n\t0 - Íàçàä";
			point = 0;
		}
		else if( c == 27 ) break;
	}
}
void ExitMenu(){
	char c(0);
	int point(0);
	system("cls");
	cout << "Âû äåéñòâèòåëüíî õîòèòå âûéòè?\n\t1 - Äà\n\t2 - Íåò";
	GTXY(point + 1,point + 1);
	while(1){
	c = getch();
	if( c == 49 ){ 
		GTXY(point + 1,1);
		point = 0;
	}
	else if( c == 50 ){ 
		GTXY(point + 1,2);
		point = 1;
	}
	else if( c == 13 ) {
		if( point == 0 ) exit(0);
		else break;
	}
	else if( c == 72 || c == 80 ) {
		point ^= 1;
		GTXY((point ^ 1) + 1,point + 1);
	}
	else if( c == 27 ) break;
	}
}
void Filework::MainMenu(){
	char c(0);
	int point(0);
	system("cls");
	cout << "*\t1 - Ðàáîòà ñ ôàéëàìè\n\t2 - Ïðîñìîòð\n\t3 - Äîáàâëåíèå\n\t4 - Óäàëåíèå\n\t5 - Ðåäàêòèðîâàíèå\n\t0 - Âûõîä";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,5);
			point = 5;
		}
		else if( c == 49 ) {
			GTXY(point,0);
			point = 0;
		}
		else if( c == 50 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 51 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 52 ) {
			GTXY(point,3);
			point = 3;
		}
		else if( c == 53 ) {
			GTXY(point,4);
			point = 4;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 0 ) point = 5;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 5 ) point = 0;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 5 ) ExitMenu();
			else if( point == 0 ) FileworkMenu();
			else if( point == 1 ) FunctionCall();
			else if( point == 2 ) AddMenu();
			else if( point == 3 ) DelMenu();
			else if( point == 4 ) EditMenu();
			system("cls");
			cout << "*\t1 - Ðàáîòà ñ ôàéëàìè\n\t2 - Ïðîñìîòð\n\t3 - Äîáàâëåíèå\n\t4 - Óäàëåíèå\n\t5 - Ðåäàêòèðîâàíèå\n\t0 - Âûõîä";
			point = 0;
		}
		else if( c == 27 ){ 
			ExitMenu();
			system("cls");
			cout << "*\t1 - Ðàáîòà ñ ôàéëàìè\n\t2 - Ïðîñìîòð\n\t3 - Äîáàâëåíèå\n\t4 - Óäàëåíèå\n\t5 - Ðåäàêòèðîâàíèå\n\t0 - Âûõîä";
			point = 0;
		}
	}
}

void _tmain()
{
	setlocale(NULL,"Russian");
	Filework some;
	some.MainMenu();
}

