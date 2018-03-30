#include <iostream>
#include <string>
#include <cstring>

std::string trimStr(const std::string &s)
{
	size_t left = s.find_first_not_of(" ");

	return (left == std::string::npos) ? "" :
	       s.substr(left, s.find_last_not_of(" ") - left + 1);
}
inline bool isNormNum(const char *num)
{
	return (
	           !strcmp(num, "n") ||
	           !strcmp(num, "sn") ||
	           !strcmp(num, "pn") ||
	           !strcmp(num, "np") ||
	           !strcmp(num, "snp") ||
	           !strcmp(num, "spn") ||
	           !strcmp(num, "npn") ||
	           !strcmp(num, "snpn")
	       );
}
inline bool isNormExp(const char *exp)
{
	return (
	           !strcmp(exp, "n") ||
	           !strcmp(exp, "sn")
	       );
}
bool readStr(const std::string &s, char *tokens, int size, bool exp = false)
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
			tokens[cnt++] = 'n';
			break;
		case '-':
		case '+':
			prevNum = false;
			tokens[cnt++] = 's';
			break;
		case '.':
			prevNum = false;
			tokens[cnt++] = 'p';
			break;
		case 'e':
			if (exp || !isNormNum(tokens) || i == s.size() - 1)
				return false;
			memset(tokens, 0, size + 1); // clear buffer
			return readStr(s.substr(i + 1), tokens, size, true);
		default:
			return false;
		}
	}
	if (cnt == 0)
		return false;

	if (exp)
		return isNormExp(tokens);

	return isNormNum(tokens);
}
bool isNumber(const std::string &s)
{
	const int buffSize = 6;
	char tokens[buffSize] = {};
	return readStr(trimStr(s), tokens, buffSize - 1);
}