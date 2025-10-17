#include "sed.hpp"

int	ft_replace(char *path, std::string text, std::string s1, std::string s2)
{
	std::ofstream	outfile;
	int			pos;

	outfile.open((std::string(path) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for (int i = 0; i < (int)text.size(); i++)
	{
		pos = text.find(s1, i);
		if (pos != -1 && pos == i)
		{
			outfile << s2;
			i += std::string(s1).size() - 1;
		}
		else
			outfile << text[i];
	}
	outfile.close();
	return (0);
}

int ft_sed(char *path, std::string s1, std::string s2)
{
	char			c;
	std::ifstream	infile;
	std::string		text;

	infile.open(path);
	if (infile.fail())
	{
		std::cout << "Error: " << path << ": no such file or directory" << std::endl;
		return (1);
	}
	while(!infile.eof() && infile >> std::noskipws >> c)
		text += c;
	infile.close();
	return (ft_replace(path, text, s1, s2));
}