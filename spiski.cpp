

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
struct List{
	int id;
	char * text; //тексовая строка
	List *next; //указатель на след.элемент
};
class Filework{
public:Filework(): head(NULL), current(NULL) {};
	   void MainMenu();
	   void FunctionCall();
	   void FileworkMenu();
	   void EditMenu();
	   void DelMenu();
	   void AddMenu();
	   void ShowList();
	   void AddElem();
	   void EditMiddle();
	   void Sort();
	   void FileRead();
	   void DeleteAll();
	   void FileSave();
private: List *head; //головной
		 List *current; //текущий эл-т списка
};
void Filework::FileSave(){ //ф-ция записи саписка в файл
	FILE * f = fopen("data.dat","wb"); //wb-чтение,бинарный
	current = head;
	while(current){
		fwrite(&current -> id,sizeof(int),1,f); //ключ.4 аргумента.f-куда записываем элемент . записывает ключ в файл
		fwrite(current -> text,sizeof(current -> text),1,f); //записывает элемент списка
		current = current -> next;
	}
	fclose(f);//закрываем файл
}
void Filework::DeleteAll(){
	current = head;
	while(current){
		head = current;
		current = current -> next;
		delete head;
	}
	head = NULL;
}
void Filework::FileRead(){//чтение файла
	FILE *f = fopen("data.dat","rb+"); //ф-ия открывает файл для чтения
	DeleteAll();//должны удалить сначала загружаемый файл
	int id;
	//head = NULL;
	if(fread(&id,sizeof(int),1,f)){//если в списке 1 эл-т или 0 эл-т,подстраховка. если в файле есть данные, то записываем их.
		List * temp = new List;//тем типа записи лист
		temp -> next = NULL;//текущий последний эл-т
		temp -> id = id;
		char * text = new char;
		id = ftell(f);//ftel-ф-ия, которая показывает, на каком эл-те файла мы находимся
		fread(text, sizeof(text),1,f);//считавание текстовой строки
		id = ftell(f) - id;//чтобы знать, сколько строка имеет символов.когда считываем с бинарного файла, нужно добавлять 0 символ
		text[id] = NULL;//см.выше
		temp -> text = text;
		text = NULL;
		delete[] text;//временная строка,удаляем.
		head = temp;//темп-запись, которую считали.
		temp = NULL;//чтоб хед не удалилось
		delete temp;
		current = head;
	}
	while(fread(&id,sizeof(int),1,f)){//считывает информацию с файла(ключ). если конец файла,то заканчиваем.
		List * temp = new List;
		temp -> next = NULL;
		temp -> id = id;
		char * text = new char;
		id = ftell(f);
		fread(text, sizeof(text),1,f);
		id = ftell(f) - id;
		text[id] = NULL;
		temp -> text = text;
		text = NULL;
		delete[] text;
		current -> next = temp;
		current = current -> next;
		temp = NULL;//накопление списка
		delete temp;
	}
	fclose(f);//закрытие файла
}
void Filework::Sort(){
  for(List *cur = this->head; cur!=NULL; cur = cur->next){//cur-указатель на главный элемент
    List *max = NULL;//запись с макс.ключом
    int maxId = cur -> id; //храним макс ключ, с которым сравниваем.
    for(List *pos = cur -> next; pos != NULL; pos = pos -> next)//pos-временная переменная,следующая после текущего эл-та
      if(pos -> id > maxId){//<-делает обратное действие
        max = pos;
        maxId = pos -> id;
      }
    if(max != NULL){//запись с макс.ключом
		int id = cur -> id;//переменная для обмена
        cur -> id = max -> id;
        max -> id = id;
        char * tmp = cur -> text;//строковая переменная.
        cur -> text = max -> text;
        max -> text = tmp;
	}//головной-1 эл-т списка
  }
}
void Filework::EditMiddle(){
	int id;
	system("cls");
	cout << "Введите ключ: ";
	cin >> id;
	current = head;
	while(current && current -> id != id) current = current -> next;
	if(current){//если каррент-не налл,
			cout << "\nВведите текст: ";
	        cin >> current -> text;
	}
	else{
		cout << "\nТакого элемента не существует.";
		getch();//считывает клавишу с клавиатуры
	}
}
void Filework::AddElem(){	
	int id;
	char * text = new char;
	char * t = new char;
	while(1){
		system("cls");
	    cout << "Введите ключ: ";
	    cin >> t;
		if( !(id = atoi(t)) ){//ф-ия, которая переводит строку в число
		    cout << "\nВведен неверный формат ключа";
			getch();
			break;
		}
		current = head;//чтобы пройти с начала списка до конца
		while(current && current -> id != id) current = current -> next;//идем по списку, пока он не кончится или айди не совпадут.
		if(!current || !head){//если ключ уникальный
			cout << "\nВведите текст: ";
	        cin >> text;
			List * temp = new List;//вводим текст,создавая темповую переменную
			temp -> next = head;
			temp -> id = id;
			temp -> text = text;
			text = NULL;
			delete text;
			head = temp;
			temp = NULL;
			delete temp;
			break;
		}
		else{
			cout << "\nКлюч уже существует. Введите новый, либо введите какой-нибудь символ для выхода.";
			getch();
		}
	}
}
void Filework::ShowList(){
	system("cls");
	if(!head) cout << "Список пуст.";
	else{
		current = head;
		cout << "Список: \n\t";
		while(current){
			cout << current -> id << " " << current -> text << "\n\t";
			current = current -> next;
	    }
	}
	getch();
}
void Filework::FunctionCall(){
	system("cls");
	cout << "Вызов функции";
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
	int point(1);
	system("cls");
	cout << "Работа с файлами:\n*\t1 - Сохранить список в файл\n\t2 - Загрузить список из файла\n\t0 - Назад";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,3);
			point = 3;
		}
		else if( c == 49 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 50 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 1 ) point = 3;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 3 ) point = 1;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 3 ) break;
			else if( point == 1 ) FileSave();
			else if( point == 2 ) FileRead();
			system("cls");
	        cout << "Работа с файлами:\n*\t1 - Сохранить список в файл\n\t2 - Загрузить список из файла\n\t0 - Назад";
			point = 1;
		}
		else if( c == 27 ) break;
	}
}
void Filework::EditMenu(){
	char c(0);
	int point(1);
	system("cls");
	cout << "Редактирование:\n*\t1 - Элемента списка по ключу\n\t2 - Сортировка Я-А по ключу\n\t0 - Назад";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,3);
			point = 3;
		}
		else if( c == 49 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 50 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 1 ) point = 3;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 3 ) point = 1;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 3 ) break;
			else if( point == 1 ) EditMiddle();
			else if( point == 2 ) Sort();
			else FunctionCall();
			system("cls");
	        cout << "Редактирование:\n*\t1 - Элемента списка по ключу\n\t2 - Сортировка Я-А по ключу\n\t0 - Назад";
			point = 1;
		}
		else if( c == 27 ) break;
	}
}
void Filework::AddMenu(){
	char c(0);
	int point(1);
	system("cls");
	cout << "Добавление:\n*\t1 - Добавить элемент в список\n\t0 - Назад";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 49 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 1 ) point = 2;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 2 ) point = 1;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 2 ) break;
			else if( point == 1 ) AddElem();
			else FunctionCall();
			system("cls");
	        cout << "Добавление:\n*\t1 - Добавить элемент в список\n\t0 - Назад";
			point = 1;
		}
		else if( c == 27 ) break;
	}
}
void Filework::DelMenu(){
	char c(0);
	int point(1);
	system("cls");
	cout << "Удаление:\n*\t1 - Удалить весь список\n\t0 - Назад";
	while(1){
		c = getch();
		if( c  == 48 ) {
			GTXY(point,2);
			point = 2;
		}
		else if( c == 49 ) {
			GTXY(point,1);
			point = 1;
		}
		else if( c == 72 ){
			int i(point);
			point = point - 1;
			if( point < 1 ) point = 2;
			GTXY(i,point);
		}
		else if( c == 80 ){
			int i(point);
			point = point + 1;
			if( point > 2 ) point = 1;
			GTXY(i,point);
		}
		else if( c == 13 ){
			if( point == 2 ) break;
			else if( point == 1 ) DeleteAll();
			else FunctionCall();
			system("cls");
	        cout << "Удаление:\n*\t1 - Удалить весь список\n\t0 - Назад";
			point = 1;
		}
		else if( c == 27 ) break;
	}
}
void ExitMenu(){
	char c(0);
	int point(0);
	system("cls");
	cout << "Вы действительно хотите выйти?\n\t1 - Да\n\t2 - Нет";
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
	cout << "*\t1 - Работа с файлами\n\t2 - Просмотр\n\t3 - Добавление\n\t4 - Удаление\n\t5 - Редактирование\n\t0 - Выход";
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
			else if( point == 1 ) ShowList();
			else if( point == 2 ) AddMenu();
			else if( point == 3 ) DelMenu();
			else if( point == 4 ) EditMenu();
			system("cls");
			cout << "\t1 - Работа с файлами\n\t2 - Просмотр\n\t3 - Добавление\n\t4 - Удаление\n\t5 - Редактирование\n\t0 - Выход";
			GTXY(point,point);
		}
		else if( c == 27 ){ 
			ExitMenu();
			system("cls");
			cout << "\t1 - Работа с файлами\n\t2 - Просмотр\n\t3 - Добавление\n\t4 - Удаление\n\t5 - Редактирование\n\t0 - Выход";
			GTXY(point,point);
		}
	}
}

void _tmain()
{
	setlocale(NULL,"Russian");
	Filework some;
	some.MainMenu();
}



