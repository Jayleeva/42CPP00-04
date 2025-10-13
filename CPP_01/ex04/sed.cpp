#include "sed.hpp"

int ft_strlen(string s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

/*string ft_update_name(string path, string extension)
{
    path.resize(ft_strlen(path) + ft_strlen("_replace") + ft_strlen(extension));
    string npath = new string[ft_strlen(path)];
    npath = path + "_replace" + extension;
    return (npath);
}

string  ft_trim_extension(string *path)
{
    int i = 0;
    int end = 0;

    while (path[i])
    {
        if (path[i] == '.')
            end = i;
        i ++;
    }
    if (end > 0)
        path->resize(end);

    int j = 0;
    while (j < end)
    {
        *path ++;
        j ++;
    }
    return (*path);
}

string ft_replace(string text, string s1, string s2)
{
    int i = 0;

    while (text[i])
    {

        i ++;
    }
    return (text);
}*/

int ft_sed(string path, string s1, string s2)
{
    if (path.empty() || s1.empty() || s2.empty())
    {
        cout << "Argument invalid. Format: int sed(string path, string s1, string s2)" << endl;
        return (1);
    }
    filesystem::path filePath = path;
    ifstream file(filePath);
    if (!file.is_open())
    {
        cout << "File could not open. Check path." << endl;
        return (1);
    }
    else
    {
        file.seekg (0, file.end);
        int length = file.tellg();
        file.seekg (0, file.beg);
        string buffer = new string[length];
        file.read (buffer,length);
        if (!file)
            cout << "error: only " << file.gcount() << " could be read";
        file.close();

        //ft_replace(buffer, s1, s2);
        string extension = filePath.extension();
        filesystem::path newFilePath = "hello" + extension;
        //string name = ft_update_name(path, extension);
        ofstream outfile(newFilePath);
        outfile << buffer;
        outfile.close();
        // ...buffer contains the entire file...
        delete[] buffer;
    }
    return (0);
}