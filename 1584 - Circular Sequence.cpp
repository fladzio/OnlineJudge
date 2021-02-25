#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int T;
    std::cin >> T;

    while(T--)
    {
        char smallest;
        std::string dna;
        std::vector<std::string> words;

        std::cin >> dna;

        if(dna.find("A") != std::string::npos) smallest = 'A';
        else if(dna.find("C") != std::string::npos) smallest= 'C';
        else if(dna.find("G") != std::string::npos) smallest = 'G';
        else smallest = 'T';

        for(int i = 0; i < dna.length(); ++i)
        {
            if(dna[i] == smallest)
            {
                std::string word = "";
                for(int j = i; j < dna.length(); ++j)
                    word += dna[j];
                for(int j = 0; j < i; ++j)
                    word += dna[j];
                words.push_back(word);
            }
        }

        std::sort(words.begin(), words.end());

        std::cout << words[0] << std::endl;
    }
    return 0;
}