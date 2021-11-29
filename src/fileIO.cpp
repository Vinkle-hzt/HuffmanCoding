#include "fileIO.h"
using namespace std;

string readFromFile(const string &filename)
{
    ifstream ifile;
    string s;
    char ch;

    ifile.open(filename);
    while (ifile.read(&ch, 1))
        s.push_back(ch);

    ifile.close();

    return s;
}

map<char, int> getFrequency(string &words)
{
    map<char, int> f;
    for (char c : words)
        f[c]++;
    return f;
}

string encodingString(const string &words, map<char, string> &code)
{
    string binwords;

    for (auto const word : words)
        binwords.append(code[word]);

    return binwords;
}

void writeCode(const string &filename, map<char, string> &code)
{
}

map<string, char> readCode(const string &filename)
{
    return {};
}

string get01Text(const string &sourceText, map<char, string> &code)
{
    string result;
    for (int i = 0; i < sourceText.length(); ++i)
    {
        char ch = sourceText[i];
        result.append(code[ch]);
    }
    return result;
}

void writeToBinary(const string &filename, map<char, string> &code)
{
    string binaryName = filename + ".huf";
    ofstream outFile(binaryName, ios::out | ios::binary);
    int index = 0;
    string codeText = get01Text(readFromFile(filename), code);
    unsigned char remain = codeText.length() % 8;
    outFile.write((char *)(&remain), 1);
    for (int j = 0; j < 8 - remain; j++)
        codeText.push_back('0');
    while (index < codeText.length())
    {
        unsigned char byte = 0;
        for (int i = 0; i < 8; i++)
        {
            byte = codeText[index] - '0' + byte;
            if (i != 7)
                byte *= 2;
            ++index;
        }
        outFile.write((char *)&byte, 1);
    }
    outFile.close();
}

string decodingFile(const string &zipFile, const string &codeFile)
{
    map<string, char> codeMap = readCode(codeFile);
    ifstream inFile(zipFile, ios::in | ios::binary);
    if (!inFile)
        return "";
    char ch, remain;
    string code01;
    inFile.read(&remain, 1);
    while (inFile.read(&ch, 1))
    {
        unsigned char byte = ch;
        for (int i = 0; i < 8; i++)
        {
            code01.push_back((byte & 0x80) / 128 + '0');
            byte = byte << 1;
        }
    }
    int len = code01.length();
    if (remain != 0)
        code01 = code01.substr(0, len - 8 + remain);

    string result; //最终结果为原文本
    string code;   //单个的字符的01串
    map<string, char>::iterator itr;
    for (int i = 0; i < code01.length(); ++i)
    {
        code.push_back(code01[i]);
        itr = codeMap.find(code);
        // 找到code对应的char
        if (itr != codeMap.end())
        {
            result.push_back(itr->second);
            code = "";
        }
    }
    return result;
}

void writeToFile(const string &filename, const string &data)
{
    ofstream ofile;

    ofile.open(filename);
    ofile.write(data.c_str(), data.length());
    ofile.close();
}