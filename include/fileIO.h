#pragma once

#include "HuffmanTree.h"
#include <fstream>

/**
 * @brief 读取文件信息，返回 string 字符串
 * @author 范竞扬
 * 
 * @param filename 
 * @return string 
 */
string readFromFile(const string &filename);

/**
 * @brief 获取字符串字符的频率序列
 * @author 范竞扬
 * 
 * @param words 字符串
 * @return map<char, int> 频率序列
 */
map<char, int> getFrequency(string& words);

/**
 * @brief 编码文件中的字符串
 * @author 范竞扬
 * 
 * @param words 字符串
 * @param code 编码表
 * @return string 编码后的01串
 */
string encodingString(const string &words, map<char, string> &code);

/**
 * @brief 将编码写入文件中
 * @author 王玉涵
 * 
 * @param filename 文件名
 * @param code 编码表
 */
void writeCode(const string &filename, map<char, string> &code);

/**
 * @brief 读取编码文件
 * @author 王玉涵
 * 
 * @param filename 编码文件名
 * @return map<string, char> 反编码表 key:01串 value:字符
 */
map<string, char> readCode(const string &filename);

/**
 * @brief 根据字典，将txt文本转成01字符串
 * @author 陈超林
 * 
 * @param sourceText 源文件内容
 * @param code 编码表
 * @return string 
 */
string get01Text(const string &sourceText, map<char, string> &code);

/**
 * @brief 将文件压缩后写入二进制文件
 * @author 陈超林
 * 
 * @param filename 文件名
 * @param code 编码表
 */
    void writeToBinary(const string &filename, map<char, string> &code);

/**
 * @brief 解码二进制压缩文件
 * @author 陈超林
 * 
 * @param zipFile 压缩文件
 * @param codeFile 编码文件
 * @return string 解码字符串
 */
string decodingFile(const string &zipFile, const string& codeFile);

/**
 * @brief 将字符串写入文件
 * @author 范竞扬
 * 
 * @param filename 写入文件名
 * @param data 数据
 */
void writeToFile(const string &filename, const string &data);
