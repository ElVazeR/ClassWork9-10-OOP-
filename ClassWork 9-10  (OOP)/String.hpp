#pragma once
class String {
private:
	char* data;
	size_t size;

public:
	String();
	String(const char* str);
	String(size_t repeats, char sym);
	String(const String& other); // lvalue-reference
	String(String&& other) noexcept; // rvalue-reference, move-конструктор ( конструктор пермещения ).
	~String();

	void print() const;

	String& operator=(const char* str);
	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;
	String operator+(const char* other) const;
	String operator+(const String& other) const;
};

