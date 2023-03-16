#include <json/json.h>
#include <fstream> 
#include <iostream>
using namespace std;
using namespace Json;

//对于Json数组而言，内部的顺序是有序的，这个顺序就是添加数据的顺序
void writeJson()
{
    //定义Value对象
    Value root;
    //使用append方法向Value包装器li填充数据
    root.append("luffy");
    root.append(19);
    root.append(170);
    root.append(false);

    //又定义一个subArray的Value对象
    Value subArray;
    subArray.append("ace");
    subArray.append("sabo");
    //将subArray对象增加到root里面
    root.append(subArray);

    Value obj;
    //定义键值对
    obj["sex"] = "man";
    obj["girlfriend"] = "Hancock";
    //将obj对象的键值对增加到root里面
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
    //将json数据写入test.json
    ofstream ofs("test.json");
    //写入格式化后带格式的字符串
    ofs << json;
    //关闭文件
    ofs.close();
}
/*保存到的json数据
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
    //读，打开test.json
    ifstream ifs("test.json");
    Reader rd;
    Value root;
    //将json数据解析到root里面
    rd.parse(ifs, root);
    //判断解析的root value类是否是Array
    if (root.isArray())
    {
        //size方法判断
        for (unsigned i = 0; i < root.size(); ++i)
        {
            Value item = root[i];
            //对类型进行判断，并对对应的类型进行输出
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
    printf("json写入完毕");
    readJson();
   

    return 0;
}