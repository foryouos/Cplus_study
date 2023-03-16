#include <json/json.h>
#include <fstream> 
#include <iostream>
using namespace std;
using namespace Json;

//����Json������ԣ��ڲ���˳��������ģ����˳�����������ݵ�˳��
void writeJson()
{
    Value root;
    root.append("luffy");
    root.append(19);
    root.append(170);
    root.append(false);


    Value subArray;
    subArray.append("ace");
    subArray.append("sabo");
    root.append(subArray);

    Value obj;
    obj["sex"] = "man";
    obj["girlfriend"] = "Hancock";

    root.append(obj);
#if 1
    //���������ݸ�ʽ���л�ʹ��toStyledString�����õ�����ʽ���ַ���
    string json = root.toStyledString();
#else
    //�õ�������ʽ���ַ���
    FastWriter w;
    //ͨ��write�����õ��������з����ַ���   
    string json = w.write(root);
#endif
    //д�ļ�
    //write  ->  ostream 
    //read   ->  ifstream   
    ofstream ofs("test.json");
    ofs << json;
    ofs.close();
}

void readJson()
{
    //��
    ifstream ifs("test.json");
    Reader rd;
    Value root;
    rd.parse(ifs, root);
    if (root.isArray())
    {
        for (unsigned i = 0; i < root.size(); ++i)
        {
            Value item = root[i];
            if (item.isInt())
            {
                cout << item.asInt() << " ,";
            }
            else if (item.isString())
            {
                cout << item.asString() << " ,";
            }
            else if (item.isBool())
            {
                cout << item.asBool() << " ,";
            }
            else if (item.isArray())
            {
                for (unsigned j = 0; j < item.size(); ++j)
                {
                    cout << item[j].asString() << ", ";
                }
            }
            else if (item.isObject())
            {
                Value::Members keys = item.getMemberNames();
                for (int k = 0; k < keys.size(); ++k)
                {
                    cout << keys.at(k) << "," << item[keys[k]];
                }
            }
            cout << endl;
        }
    }
}

int main()
{
    writeJson();
    printf("jsonд�����");
    readJson();


    return 0;
}