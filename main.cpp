#include <iostream>
#include <string>
#include <cstring>

std::string trimStr(const std::string &s)
{
	size_t left = s.find_first_not_of(" ");

	return (left == std::string::npos) ? "" :
	       s.substr(left, s.find_last_not_of(" ") - left + 1);
}
inline bool isToken(const char *t, bool exp = false)
{
	return (exp) ?
	       (
	           !strcmp(t, "n") ||
	           !strcmp(t, "sn")
	       ) :
	       (
	           !strcmp(t, "n") ||
	           !strcmp(t, "sn") ||
	           !strcmp(t, "pn") ||
	           !strcmp(t, "np") ||
	           !strcmp(t, "snp") ||
	           !strcmp(t, "spn") ||
	           !strcmp(t, "npn") ||
	           !strcmp(t, "snpn")
	       );
}
bool readStr(const std::string &s, char *token, int size, bool exp = false)
{
	int cnt = 0;
	bool prevNum = false;

	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (cnt == size) // buffer is full
			return false;

		switch (s[i])
		{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if (prevNum) // read number completely
				break;
			prevNum = true;
			token[cnt++] = 'n';
			break;
		case '-':
		case '+':
			prevNum = false;
			token[cnt++] = 's';
			break;
		case '.':
			prevNum = false;
			token[cnt++] = 'p';
			break;
		case 'e':
			if (exp || !isToken(token) || i == s.size() - 1)
				return false;
			memset(token, 0, size + 1); // clear buffer
			return readStr(s.substr(i + 1), token, size, true);
		default:
			return false;
		}
	}
	if (cnt == 0) // empty string
		return false;

	return isToken(token, exp);
}
bool isNumber(const std::string &s)
{
	const int buffSize = 6;
	char token[buffSize] = {};
	return readStr(trimStr(s), token, buffSize - 1);
}