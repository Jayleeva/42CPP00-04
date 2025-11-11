#include "sed.hpp"

int	ft_replace(std::string path, std::string text, std::string s1, std::string s2)
{
	std::ofstream	outfile;
	int				pos;

	outfile.open((path + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << YELLOW << "Error: " << (std::string(path) + ".replace").c_str() << ": could not open file." << DEFAULT << std::endl;
		return (1);
	}
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
	std::cout << "[DEBUG] : REPLACED" << std::endl;
	return (0);
}

int ft_sed(std::string path, std::string s1, std::string s2)
{
	std::string		line;
	std::ifstream	infile;
	std::string		text;

	if (path.empty() || s1.empty() || s2.empty())
	{
		std::cout << YELLOW << "Error: invalid parameters." << DEFAULT << std::endl;
		return (1);
	}
	infile.open(path.c_str());
	if (infile.fail())
	{
		std::cout << YELLOW << "Error: " << path << ": could not open file." << DEFAULT << std::endl;
		return (1);
	}
	while(getline(infile, line))
	{
		text += line;
		if (!infile.eof())
			text += '\n';
	}
	infile.close();
	return (ft_replace(path, text, s1, s2));
}