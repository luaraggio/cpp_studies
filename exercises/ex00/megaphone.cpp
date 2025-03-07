#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    size_t i = 0;
    int j = 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while (argv[j])
    {
        i = 0;
        while (argv[j][i])
        {
            std::cout << (char) std::toupper(argv[j][i]);
            i++;
        }
        j++;
    }
    std::cout << std::endl;
    return (0);
}

