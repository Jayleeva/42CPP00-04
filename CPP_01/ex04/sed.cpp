#include "sed.hpp"

int	ft_replace(char *path, string text, string s1, string s2)
{
	ofstream	outfile;
	int			pos;

	outfile.open((string(path) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for (int i = 0; i < (int)text.size(); i++)
	{
		pos = text.find(s1, i);
		if (pos != -1 && pos == i)
		{
			outfile << s2;
			i += string(s1).size() - 1;
		}
		else
			outfile << text[i];
	}
	outfile.close();
	return (0);
}

int ft_sed(char *path, string s1, string s2)
{
	char			c;
	ifstream	infile;
	string		text;

	infile.open(path);
	if (infile.fail())
	{
		cout << "Error: " << path << ": no such file or directory" << endl;
		return (1);
	}
	while(!infile.eof() && infile >> noskipws >> c)
		text += c;
	infile.close();
	return (ft_replace(path, text, s1, s2));
}