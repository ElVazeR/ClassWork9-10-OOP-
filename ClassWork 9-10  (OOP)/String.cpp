#include "String.hpp"
#include <iostream>
String::String() : size(0) {
	data = new char[1] { '\0' };
}

String::String(const char* str) {
	size_t counter{}; // счётчик количества элементов, 
	//	расположенных в памяти по переданному местоположению строки.
	while (*(str + counter++) != '\0');
	data = new char[counter];
	for (size_t i{}; i < counter; ++i)
		data[i] = str[i];
	size = counter - 1;
}

String::String(size_t repeats, char sym) : size(repeats) {
	data = new char[repeats + 1];
	for (size_t i = 0; i < repeats; ++i)
		data[i] = sym;
	data[repeats] = '\0';
	
}

String::String(const String& other) : size(other.size) {
	data = new char[size + 1];
	for (size_t i{}; i < size + 1; ++i)
		data[i] = other.data[i];
}

String::String(String&& other) noexcept : String() {
	// std::cout << "Move-constructor\n";
	std::swap(data, other.data);
	std::swap(size, other.size);
}

String::~String() {
	delete[] data;
}

void  String::print() const {
	std::cout << data << std::endl;
}

String& String::operator=(const char* str) {
	delete[] data;
	
	size_t counter{}; // счётчик количества элементов, 
	//	расположенных в памяти по переданному местоположению строки.
	while (*(str + counter++) != '\0');
	data = new char[counter];
	for (size_t i{}; i < counter; ++i)
		data[i] = str[i];
	size = counter - 1;
	
	return *this;
}

String& String::operator=(const String& other) {
	delete[] data;
	
	size = other.size;
	data = new char[size + 1];
	for (size_t i{}; i < size + 1; ++i)
		data[i] = other.data[i];

	return *this;
}
String& String::operator=(String&& other) noexcept {
	std::swap(data, other.data);
	std::swap(size, other.size);
	return *this;
}
String String::operator+(const char* other) const {
	return String();
}
String String::operator+(const String& other) const {
	return String();
}
