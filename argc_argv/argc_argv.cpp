#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 1;
    if (argc == 1)
    {
        std::cout << "Digite alguma coisa!" << endl;
        return (1);
    }
    while (argv[j])
    {
        i = 0;
        while (argv[j][i])
        {
            std::cout << argv[j][i];
            i++;
        }
        std::cout << endl;
        std::cout << " " << j << endl;
        j++;
    }
    return (0);
}
