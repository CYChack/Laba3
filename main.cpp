#include "String.h"
int main() {
	String line;
	String line2("Hello");
	String line3(line2);
	cout << line2.GetStr() << endl;
	cout << line3.GetStr() << endl;
	line3.SetStrLength("World");
	cout << line3 << endl;

	String result;
	result = line2 + line3;
	bool equal = line2 == line3;
	cout << "+ : " << result << endl;
	cout << "== : " << equal << endl;
	cout << line2.GetLength() << endl;
	cout << line3.GetLength() << endl;
	cout << result.GetLength() << endl;

	String line4("Summer holiday");
	String line5("Summer holiday");
	bool equal2 = line4 == line5;
	cout << "== : " << equal2 << endl;

	line5.SetStrLength("holiday");
	bool res = line4 < line5;
	cout << "< : " << res << endl;

	bool res2 = line4 > line5;
	cout << "> : " << res2 << endl;
	cout << "[] : " << line4[0] << endl;
	cout << line4.Find("S") << endl;
	cout << line4.FirstFind("m") << endl;

	line4.Getline(" "); 

	int i, j, k;
	String* linedop;
	cin << j;
	for (i = 0; i < j + 1; i++)
	{
		cin << linedop[i];
	}
	for (i = 0; i < j; i++)
	{
		if (linedop[i] == linedop[i + 1])
			delete linedop[i + 1];
		else
			for (k = i; k < j; k++)
			{
				if (linedop[i] == linedop[k + 1])
					delete linedop[k + 1];
				else 
					continue
			}
	}
	cout << linedop[i];


	return 0;
}