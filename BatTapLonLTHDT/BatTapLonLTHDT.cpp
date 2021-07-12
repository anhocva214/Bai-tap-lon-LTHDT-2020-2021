#include <iostream>
#include <string>
#include <vector>
#include "Stack.h"


using namespace std;


void ScanInput(string x, vector<string>& M)
{
	cout << "  >>> ";
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] >= '0' && x[i] <= '9')
		{
			if (i < x.length() - 1)
			{
				for (int j = i + 1; j < x.length(); j++)
				{
					if (
						x[j] == ')' || x[j] == '*' || x[j] == '/' || x[j] == '+' || x[j] <= '-' || x[j] == '%' || x[j] == '^')
					{
						M.push_back(x.substr(i, j - i));
						i = j - 1;
						break;
					}
				}
			}
			else
			{
				M.push_back(x.substr(i, x.length() - 1));
				break;
			}
		}
		else if (
			x[i] == '(' || x[i] == ')' || x[i] == '*' || x[i] == '/' || x[i] == '+' || x[i] == '-' || x[i] == '%' || x[i] == '^')
		{
			string a(1, x[i]);
			M.push_back(a);
		}
		else if (x[i] == 's' && x[i + 1] == 'q' && x[i + 2] == 'r' && x[i + 3] == 't')
		{
			M.push_back(x.substr(i, 4));
		}
		else if (x[i] == 'c' && x[i + 1] == 'o' && x[i + 2] == 's')
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'c' && x[i + 1] == 'o' && x[i + 2] == 's' && x[i + 3] == 'i' && x[i + 4] == 's')
		{
			M.push_back(x.substr(i, 5));
		}
		else if (x[i] == 's' && x[i + 1] == 'i' && x[i + 2] == 'n')
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'e' && x[i + 1] == 'x' && x[i + 2] == 'p')
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'e' && x[i + 1] == '^')
		{
			M.push_back(x.substr(i, 2));
		}
		else if (x[i] == 'l' && x[i + 1] == 'o' && x[i + 2] == 'g')
		{
			M.push_back(x.substr(i, 3));
		}
	}
	for (int i = 0; i < M.size(); i++)
	{
		cout << M[i];
	}
}

int Prioritize(string x)
{
	if (x == "sqrt" || x == "sin" || x == "cos")
		return 3;
	if (x == "*" || x == "/" || x == "%" || x == "^")
		return 2;
	else if (x == "+" || x == "-")
		return 1;
	else if (x == "(")
		return 0;

	return -1;
}

int Classify(string x)
{
	if (x == "sqrt" || x == "exp" || x == "sin" || x == "cos" || x == "cosin" || x == "log")
		return 3;
	if (x == "*" || x == "/" || x == "%" || x == "+" || x == "-" || x == "^")
		return 2;
	else
		return 1;
}

string CalValue(string b, string x, string a)
{
	float fResult = 0;

	if (x == "sqrt")
		fResult = double(sqrt(atof(a.c_str())));
	if (x == "cos" || x == "cosin")
		fResult = double(cos(atof(a.c_str())));
	if (x == "sin")
		fResult = double(sin(atof(a.c_str())));
	if (x == "log")
		fResult = double(log(atof(a.c_str())));
	if (x == "exp" || x == "e^")
		fResult = double(exp(atof(a.c_str())));
	if (x == "^")
	{
		fResult = 1;

		for (int i = 1; i <= int(atof(a.c_str())); i++)
			fResult = fResult * atof(b.c_str());
	}

	if (x == "%")
		fResult = int(atof(b.c_str())) % int(atof(a.c_str()));

	if (x == "*")
		fResult = atof(b.c_str()) * atof(a.c_str());
	else if (x == "/")
		fResult = atof(b.c_str()) / atof(a.c_str());
	else if (x == "+")
		fResult = atof(b.c_str()) + atof(a.c_str());
	else if (x == "-")
		fResult = atof(b.c_str()) - atof(a.c_str());

	string strResult = to_string(fResult);
	return strResult;
}

float Calculator(vector<string> M)
{
	float fResult = 0;

	Stack* Sh = new Stack();
	Stack* St = new Stack();

	int iLength = M.size();

	for (int i = 0; i < iLength; i++)
	{
		if (Classify(M[i]) == 1 && M[i] != "(" && M[i] != ")")
			Sh->Push(M[i]);
		if (Classify(M[i]) == 2)
		{
			while (!St->IsEmpty() &&
				(Prioritize(M[i]) <= Prioritize(St->GetTop()->Info)))
			{
				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Pop(b);
				Sh->Push(CalValue(b, x, a));
			}
			St->Push(M[i]);
		}
		if (Classify(M[i]) == 3)
		{
			while (!St->IsEmpty() &&
				(Prioritize(M[i]) < Prioritize(St->GetTop()->Info)))
			{
				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Push(CalValue(b, x, a));
			}
			St->Push(M[i]);
		}
		if (M[i] == "(")
			St->Push(M[i]);
		if (M[i] == ")")
		{
			while (St->GetTop()->Info != "(")
			{

				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Pop(b);
				Sh->Push(CalValue(b, x, a));
			}
			string c = "";
			St->Pop(c);
			while (!St->IsEmpty() &&
				(St->GetTop()->Info == "sqrt" ||
					St->GetTop()->Info == "sin" ||
					St->GetTop()->Info == "cos"))
			{
				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Push(CalValue(b, x, a));
			}
		}
	}

	while (!St->IsEmpty())
	{
		string a = "";
		Sh->Pop(a);
		string x = "";
		St->Pop(x);
		string b = "";
		Sh->Pop(b);
		Sh->Push(CalValue(b, x, a));
	}


	string strResult = "";
	Sh->Pop(strResult);
	fResult = atof(strResult.c_str());
	return fResult;
}

void main()
{

	while (1 == 1) {

		string Input;
		cout << "\nNhap bieu thuc trung to:  ";
		getline(cin, Input);

		system("cls");
		cout << "\n";

		vector<string> M;
		ScanInput(Input, M);
		cout << " = " << Calculator(M) << endl;
		cout << endl;

		system("pause");
		system("cls");
		
	}


}