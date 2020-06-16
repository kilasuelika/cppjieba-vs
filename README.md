# cppjieba-vs
 cppjieba for Visual Studio.


Original project: [cppjieba](https://github.com/yanyiwu/cppjieba)

# Requirements
C++20编译器。原Limonp中有一些函数使用了新标准中removed的函数，已被修改。

# Usage
把include文件夹添加到项目的additional include中，把dict放到项目文件夹中即可。

如果主项目的源代码中有中文，要使用UTF8编码，分词结果输出到文件，如果直接输出到控制台会乱码。当然，也可以把需要分词的文本放到文件中再读取，则这个文件使用UTF8编码。

# Example
```
#include <iostream>
#include<fstream>

#include "cppjieba/Jieba.hpp"

using namespace std;


int main()
{
    char ch0[] = { "我喜欢吃苹果" };
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
};
```