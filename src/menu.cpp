#include "menu.h"

using namespace std;

/**
 * @brief չʾѡ��˵�
 * @author ����
 * 
 */
static void showMenu()
{
    cout << "**************************************************************" << endl;
    cout << "��������˵����" << endl;
    cout << "ͳ�������ļ��ַ�Ƶ�Ȳ����ַ������벢������ļ�������Ҫ�󣩣� 1" << endl;
    cout << "  �������ļ����벢�����������һ���������ļ����м�Ҫ�󣩣� 2" << endl;
    cout << "          �ļ����벢������������Ϊһ�ı��ļ����߼�Ҫ�󣩣� 3" << endl;
    cout << "                                                     �˳� �� 4" << endl;
    cout << "**************************************************************" << endl;
}

void startMenu()
{
    cout << "**************************************************************" << endl;
    cout << "                     ��ӭʹ��huffman������                    " << endl;
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
                cout << "�������ļ�����";
                cin >> filename;
                words = readFromFile(filename);
                freq = getFrequency(words);
                cout << filename << "�ļ��ַ���Ƶ�ȣ�" << endl;
                for (auto i : freq)
                    cout << i.first << " " << i.second << endl;
                ht = new HuffmanTree(freq);
                coding = ht->getCoding();
                cout << '\n'
                     << filename << "�ļ��ַ������룺" << endl;
                for (auto i : coding)
                    cout << i.first << " " << i.second << endl;
                writeCode(filename + ".code", coding);
                cout << filename << "�ַ���������д��" << filename << ".code��" << endl;
                break;
            case '2':
                if (!ht)
                {
                    cout << "���Ƚ����ַ������������" << endl;
                    break;
                }
                zip = writeToBinary(filename, coding);
                cout << filename << "�����Ʊ���: \n"
                     << get01Text(words, coding) << endl;
                cout << "\nѹ����Ϊ" << zip * 100 << "%\n";
                cout << '\n'
                     << "�����Ʊ������ѱ��浽" << filename << ".huf��" << endl;
                break;
            case '3':
                cout << "��������Ҫ�����.huf�ļ���";
                cin >> huf_file;
                if (huf_file.substr(huf_file.size() - 4, 4) != ".huf")
                {
                    cout << "�ļ�����.huf�ļ�" << endl;
                    continue;
                }
                decode_result = decodingFile(huf_file, huf_file.substr(0, huf_file.size() - 4) + ".code");
                writeToFile(filename + ".result", decode_result);
                cout << "������:\n"
                     << decode_result << endl;
                cout << '\n'
                     << "�������ѱ��浽" << filename << ".result" << endl;
                break;
            case '4':
                cout << "�ټ� :)" << endl;
                break;
            default:
                cout << "�Ƿ�����" << endl;
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