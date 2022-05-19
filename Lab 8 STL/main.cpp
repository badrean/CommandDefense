#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <queue>

bool cmp (std::pair<std::string, int> &a, std::pair<std::string, int> &b){
    if(a.second == b.second) return a.first[0] < b.first[0];
    return a.second > b.second;
}

void sort (std::map<std::string, int> &M){
    std::vector<std::pair<std::string, int> > vector_perechi;

    for(auto &it : M){
        vector_perechi.push_back(it);
    }

    sort(vector_perechi.begin(), vector_perechi.end(), cmp);

    for(auto &it : vector_perechi){
        std::cout << it.first << " => " << it.second << std::endl;
    }
}

int main() {
    // /Users/adrian/CLionProjects/Laborator 8 STL/myfile.txt
    // space, comma, question and exclamation mark, point

    std::fstream file("/Users/adrian/CLionProjects/Laborator 8 STL/myfile.txt");

    std::map<std::string , int> Words;
    //std::priority_queue<int> Sort;
    std::string content;

    while(file >> content){
        char temp;
        temp = content.back();
        if (temp == ',' || temp == '?' || temp == '!' || temp == '.'){
            content.pop_back();
        }

        for (char &it : content){
            it = tolower(it);
        }

        if (Words.find(content) == Words.end()){
            Words[content] = 1;
        }
        else {
            Words[content]++;
        }
    }

    std::map<std::string , int>::iterator it;

    std::cout << std::endl << "Before sort: " << std::endl;

    for (auto it : Words){
        std::cout << it.first << ": " << it.second << std::endl;
    }

    std::cout << std::endl << "After sort: " << std::endl;
    sort(Words);

    return 0;
}
