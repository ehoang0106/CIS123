#include <iostream>
#include <string>

using namespace std;

bool isValidUsername(string username);
bool isValidPassword(string password);





int main()
{
	string username, password;

	while (true)
	{
		cout << "Enter username: ";
		cin >> username;

		if (isValidUsername(username))
		{
			break;
		}

		cout << "Invalid username. Try again!" << endl;
	}


	while (true)
	{
		cout << "Enter password: ";
		cin >> password;

		if (isValidPassword(password))
		{
			break;
		}

		cout << "Invalid password. Try again!" << endl;
	}

	cout << "Congratz. You've entered valid username and password" << endl;

	return 0;
}

bool isValidUsername(string username)
{
	if (username.length() < 4)
	{
		
		return false;

	}

	for (int i = 0; i < username.length(); i++)
	{
		if (!isalnum(username[i]))
		{
			
			return false;
		}
	}

	if (isdigit(username[0]))
	{
		return false;
	}

	return true;
}


bool isValidPassword(string password)
{
	bool hasUpper = false;
	bool hasLower = false;
	bool hasNumber = false;
	bool hasSpecial = false;

	if (password.length() < 7)
	{
		return false;
	}

	//password contain at least one special character

	for (int i = 0; i < password.length(); i++)
	{
		if (!isalnum(password[i]))
		{
			hasSpecial = true;
			break;
		}
	}

	if (!hasSpecial)
	{
		return false;
	}

	//password containt at least one uppercase

	for (int i = 0; i < password.length(); i++)
	{
		if (isupper(password[i]))
		{
			hasUpper = true;
			break;
		}
	}

	if (!hasUpper)
	{
		return false;
	}

	//containt at least one lower

	for (int i = 0; i < password.length(); i++)
	{
		if (islower(password[i]))
		{
			hasLower = true;
			break;
		}
	}

	if (!hasLower)
	{
		return false;
	}

	//containt at least one number

	for (int i = 0; i < password.length(); i++)
	{
		if (isdigit(password[i]))
		{
			hasNumber = true;
			break;
		}
	}

	if (!hasNumber)
	{
		return false;
	}

	return true;
}