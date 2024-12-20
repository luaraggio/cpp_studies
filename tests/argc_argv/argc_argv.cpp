#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 1;
    if (argc == 1)
    {
        std::cout << "Digite alguma coisa!" << std::endl;
        return (1);
    }
    while (argv[j])
    {
        i = 0;
        while (argv[j][i])
        {
            argv[j][i] = toupper(argv[j][i]);
            std::cout << argv[j][i];
            i++;
        }
        std::cout << std::endl;
        j++;
    }
    return (0);
}
