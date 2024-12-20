#include <iostream>

int main(int argc, char **argv)
{
    size_t i = 0;
    int j = 1;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (j < argc)
        {
            std::string str = argv[j];
            i = 0;
            while (i < str.size())
            {
                str[i] = std::toupper(str[i]);
                i++;
            }
            j++;
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}

