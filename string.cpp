#include "String.h"
String::String()
{
	line = nullptr;
	length = 0;
}
String::String(const char* line)
{
	length = strlen(line);
	this->line = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->line[i] = line[i];
	this->line[length] = '\0';

}
String::String(char st, int length)
{
	this->length = length + 1;
	line = new char[length + 1];
	for (int i = 0; i < length; i++)
		line[i] = st;
	line[length] = '\0';

}
String::String(String& a)
{
	length = strlen(a.line);
	line = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->line[i] = a.line[i];
	this->line[length] = '\0';
}
char* String::GetStr()
{
	return line;
}
int String::GetLength()
{
	return length;
}
void String::SetStrLength(const char* ch)
{
	length = strlen(ch);
	line = new char[length + 1];
	for (int i = 0; i < length; i++)
		line[i] = ch[i];
	line[length] = '\0';
}
String String::operator+ (const String& a)
{
	String NewStr;
	int thisLength = strlen(this->line);
	int aLength = strlen(a.line);
	NewStr.length = thisLength + aLength;
	NewStr.line = new char[thisLength + aLength + 1];
	int i = 0;
	for (; i < thisLength; i++)
		NewStr.line[i] = this->line[i];
	for (int j = 0; j < aLength; j++, i++)
		NewStr.line[i] = a.line[j];
	NewStr.line[thisLength + aLength] = '\0';
	return NewStr;
}
String& String::operator= (const String& a)
{
	if (this->line != nullptr)
	{
		delete[] line;
	}
	length = strlen(a.line);
	this->line = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->line[i] = a.line[i];
	this->line[length] = '\0';
	return*this;
}
bool String::operator== (const String& a)
{
	if (this->length != a.length) {
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (this->line[i] != a.line[i])
		{
			return false;
		}
	}
	return true;
}
ostream& operator<< (ostream& os, const String& a)
{
	for (int i = 0; i < a.length; i++)
		os << a.line[i];
	return os;
}
istream& operator>> (istream& is, String& a)
{
	char c[256];
	is.getline(c, 256);
	String tmp(c);
	a = tmp;
	return is;
}
bool String::operator< (const String& a)
{
	return length < a.length;

}
bool String::operator> (const String& a)
{
	return length > a.length;
}
char& String::operator[] (int index)
{
	if (index >= 0 && index < length)
		return this->line[index];
}
String::~String()
{
	delete[] line;
}
char* String::Find(const char* tmp)
{
	char* c = strstr(line, tmp);
	return c;
}
char* String::FirstFind(const char* ch)
{
	char* c = strstr(line, ch);
	return c;
}
String* String::Getline(const char* ch)
{
	String tmp = line;
	int digit = 0;
	char* c = linetok(tmp.line, ch);
	while (c != NULL)
	{
		digit += 1;
		c = linetok(NULL, ch);
	}
	tmp = c;
	String* a = new String[digit];
	digit = 0;
	c = linetok(tmp.line, ch);
	while (c != NULL)
	{
		a[digit] = c;
		digit += 1;
		c = linetok(NULL, c);
	}
	return a;
}