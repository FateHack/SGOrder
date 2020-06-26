#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Primer.h"

using namespace std;

void split(const string &s, vector<string> &tokens, const string &delimiters = " ") {
    string::size_type lastPos = s.find_first_not_of(delimiters, 0); //从索引为0开始查找非delimiters的字符索引
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos -
                                           lastPos));//use emplace_back after C++11
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

int main(int argv, char *args[]) {
    string inPath;
    cout << "请将要处理的引物信息文件拖到此处(按回车键确认)" << endl;
    cin >> inPath;
    string hex = "GAAGGTCGGAGTCAACGGATT";
    string fam = "GAAGGTGACCAAGTTCATGCT";
    cout << "请选择引物类别" << endl;
    cout << "1.KASP" << "    2.SSR(普通引物)" << endl;
    int mode = 0;
    cin >> mode;
    while (mode != 1 && mode != 2) {
        cout << "输入有误，请重新输入" << endl;
        cout << "1.KASP" << "    2.SSR(普通引物)" << endl;
        cin >> mode;
    }
    ifstream in(inPath);
    inPath.replace(inPath.find("."), 1, "_mod."); //保存路径
    ofstream of(inPath);
    string line;
    vector<Primer> primers;
    string content;
    string delimiters;
    int index = 1;
    switch (mode) {
        case 1: { //KASP
            if (in) {
                while (getline(in, line, '\n')) {
                    vector<string> splits;
                    if (strstr(line.c_str(), ",")) {
                        delimiters = ",";
                    } else if (strstr(line.c_str(), "\t")) {
                        delimiters = "\t";
                    } else {
                        cout << "不是有效格式的文件" << endl;
                        exit(0);
                    }
                    split(line, splits, delimiters);
                    Primer primer(splits[0], splits[1], splits[2], splits[3]);
                    primers.push_back(primer);
                }
            } else {
                cout << "文件不存在" << endl;
            }
            for (const auto &primer:primers) {
                content.append(primer.getId()).append("-").append(to_string(index)).append("A").append(delimiters).append(
                        hex).append(
                        primer.getA()).append("\n"); //第一行
                content.append(primer.getId()).append("-").append(to_string(index)).append("B").append(delimiters).append(
                        fam).append(
                        primer.getB()).append("\n"); //第二行
                content.append(primer.getId()).append("-").append(to_string(index)).append("C").append(delimiters).append(
                        primer.getCommon()).append("\n"); //第三行
                index++;
            }
        }
            break;
        case 2: { //SSR
            if (in) {
                while (getline(in, line, '\n')) {
                    vector<string> splits;
                    if (strstr(line.c_str(), ",")) {
                        delimiters = ",";
                    } else if (strstr(line.c_str(), "\t")) {
                        delimiters = "\t";
                    } else {
                        cout << "不是有效格式的文件" << endl;
                        exit(0);
                    }
                    split(line, splits, delimiters);
                    Primer primer(splits[0], splits[1], splits[2]);
                    primers.push_back(primer);
                }
            } else {
                cout << "文件不存在" << endl;
            }
            for (const auto &primer:primers) {
                content.append(primer.getId()).append("-").append(to_string(index)).append("F").append(delimiters).append(
                        primer.getA()).append("\n"); //第一行
                content.append(primer.getId()).append("-").append(to_string(index)).append("R").append(delimiters).append(
                        primer.getB()).append("\n"); //第二行
                index++;
            }
        }
            break;
    }
    of.write(content.c_str(), content.size());
    of.close();
    in.close();
    cout << "处理完成，文件保存在：" << inPath << endl;
    return 0;
}