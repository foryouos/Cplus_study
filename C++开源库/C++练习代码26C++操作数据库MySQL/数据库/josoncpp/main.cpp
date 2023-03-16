#include <json/json.h>
#include <fstream> 
#include <iostream>
using namespace std;
using namespace Json;

//对于Json数组而言，内部的顺序是有序的，这个顺序就是添加数据的顺序
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
    //对上面数据格式序列化使用toStyledString方法得到带格式的字符串
    string json = root.toStyledString();
#else
    //得到不带格式的字符串
    FastWriter w;
    //通过write方法得到不带换行符的字符串   
    string json = w.write(root);
#endif
    //写文件
    //write  ->  ostream 
    //read   ->  ifstream   
    ofstream ofs("test.json");
    ofs << json;
    ofs.close();
}

void readJson()
{
    //读
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
    printf("json写入完毕");
    readJson();


    return 0;
}