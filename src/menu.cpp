#include "menu.h"

using namespace std;

/**
 * @brief 展示选择菜单
 * @author 王玉涵
 * 
 */
static void showMenu()
{
    cout << "**************************************************************" << endl;
    cout << "操作命令说明：" << endl;
    cout << "统计输入文件字符频度并对字符集编码并输出至文件（基本要求）： 1" << endl;
    cout << "  对整个文件编码并保存编码结果到一个二进制文件（中级要求）： 2" << endl;
    cout << "          文件解码并将解码结果保存为一文本文件（高级要求）： 3" << endl;
    cout << "                                                     退出 ： 4" << endl;
    cout << "**************************************************************" << endl;
}

void startMenu()
{
    cout << "**************************************************************" << endl;
    cout << "                     欢迎使用huffman编码器                    " << endl;
    cout << "**************************************************************" << endl;

    char option;
    string filename;
    string words;
    map<char, int> freq;
    map<char, string> coding;
    string decode_result;
    HuffmanTree *ht = nullptr;
    string huf_file;
    double zip;
    do
    {
        cout << endl;
        showMenu();
        cout << endl
             << "$$ ";
        cin >> option;
        try
        {
            switch (option)
            {
            case '1':
                cout << "请输入文件名：";
                cin >> filename;
                words = readFromFile(filename);
                freq = getFrequency(words);
                cout << filename << "文件字符集频度：" << endl;
                for (auto i : freq)
                    cout << i.first << " " << i.second << endl;
                ht = new HuffmanTree(freq);
                coding = ht->getCoding();
                cout << '\n'
                     << filename << "文件字符集编码：" << endl;
                for (auto i : coding)
                    cout << i.first << " " << i.second << endl;
                writeCode(filename + ".code", coding);
                cout << filename << "字符集编码已写入" << filename << ".code中" << endl;
                break;
            case '2':
                if (!ht)
                {
                    cout << "请先进行字符集编码操作！" << endl;
                    break;
                }
                zip = writeToBinary(filename, coding);
                cout << filename << "二进制编码: \n"
                     << get01Text(words, coding) << endl;
                cout << "\n压缩率为" << zip * 100 << "%\n";
                cout << '\n'
                     << "二进制编码结果已保存到" << filename << ".huf中" << endl;
                break;
            case '3':
                cout << "请输入需要解码的.huf文件：";
                cin >> huf_file;
                if (huf_file.substr(huf_file.size() - 4, 4) != ".huf")
                {
                    cout << "文件不是.huf文件" << endl;
                    continue;
                }
                decode_result = decodingFile(huf_file, huf_file.substr(0, huf_file.size() - 4) + ".code");
                writeToFile(filename + ".result", decode_result);
                cout << "解码结果:\n"
                     << decode_result << endl;
                cout << '\n'
                     << "解码结果已保存到" << filename << ".result" << endl;
                break;
            case '4':
                cout << "再见 :)" << endl;
                break;
            default:
                cout << "非法输入" << endl;
                break;
            }
        }
        catch (const char *err)
        {
            cerr << err << endl;
        }
        cin.clear();
        cin.sync();
        system("pause");
    } while (option != '4');
}