#include <iostream>
#include <fstream>
#include <random>

/*
 * Safe getting of integer from keyboard.
 */
int getIntFromKeyboard()
{
    do
    {
        std::string input;
        std::getline(std::cin, input);
        try
        {
            return std::stoi(input);
        }
        catch (std::exception& e)
        {
            std::cerr << "Bad input. Try again.\n";
        }
    } while (true);
}

int main() {
    const std::string OUTPUT_PATH = "..\\pic.txt";
    int width;
    int height;
    srand(time(nullptr));

    std::cout << "Please enter the width: ";
    width = getIntFromKeyboard();
    std::cout << "You've entered: " << width << "\n";
    std::cout << "Please enter the height: ";
    height = getIntFromKeyboard();
    std::cout << "You've entered: " << height << "\n";

    std::ofstream outputStream(OUTPUT_PATH);
    if (outputStream.is_open())
    {
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                int value = rand() % 2;
                outputStream << value;
            }
            outputStream <<'\n';
        }
        outputStream.close();
    }
    else
    {
        std::cerr << "File read error! Check path or rights for file edit.\n";
    }

    return 0;
}
