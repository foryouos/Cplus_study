#include <json/json.h>
#include <fstream> 
#include <iostream>
using namespace std;
using namespace Json;

//����Json������ԣ��ڲ���˳��������ģ����˳�����������ݵ�˳��
void writeJson()
{
    //����Value����
    Value root;
    //ʹ��append������Value��װ��li�������
    root.append("luffy");
    root.append(19);
    root.append(170);
    root.append(false);

    //�ֶ���һ��subArray��Value����
    Value subArray;
    subArray.append("ace");
    subArray.append("sabo");
    //��subArray�������ӵ�root����
    root.append(subArray);

    Value obj;
    //�����ֵ��
    obj["sex"] = "man";
    obj["girlfriend"] = "Hancock";
    //��obj����ļ�ֵ�����ӵ�root����
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
    //��json����д��test.json
    ofstream ofs("test.json");
    //д���ʽ�������ʽ���ַ���
    ofs << json;
    //�ر��ļ�
    ofs.close();
}
/*���浽��json����
[
    "luffy",
    19,
    170,
    false,
    [
        "ace",
        "sabo"
    ],
    {
        "girlfriend" : "Hancock",
        "sex" : "man"
    }
]
*/

void readJson()
{
    //������test.json
    ifstream ifs("test.json");
    Reader rd;
    Value root;
    //��json���ݽ�����root����
    rd.parse(ifs, root);
    //�жϽ�����root value���Ƿ���Array
    if (root.isArray())
    {
        //size�����ж�
        for (unsigned i = 0; i < root.size(); ++i)
        {
            Value item = root[i];
            //�����ͽ����жϣ����Զ�Ӧ�����ͽ������
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
                //Return a list of the member names.
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