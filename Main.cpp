#include <iostream>
#include<fstream>

#include "cppjieba/Jieba.hpp"

using namespace std;


int main()
{
    char ch0[] = {"我喜欢吃苹果" };
    const char* const DICT_PATH = "dict/jieba.dict.utf8";
    const char* const HMM_PATH = "dict/hmm_model.utf8";
    const char* const USER_DICT_PATH = "dict/user.dict.utf8";
    const char* const IDF_PATH = "dict/idf.utf8";
    const char* const STOP_WORD_PATH = "dict/stop_words.utf8";

    cppjieba::Jieba jieba(DICT_PATH,
        HMM_PATH,
        USER_DICT_PATH,
        IDF_PATH,
        STOP_WORD_PATH);
    vector<string> words;
    vector<cppjieba::Word> jiebawords;
    string s = ch0;
    string result;

    jieba.Cut(s, words, true);

    ofstream file("result.txt");
    file << limonp::Join(words.begin(), words.end(), "/") << endl;
    file.close();

    return 0;
}