#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <cmath> 
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    string id;
    string name;
    string dob;
    float gpa;
    string className;

    Student(string i, string n, string d, float g, string c) 
        : id(i), name(n), dob(d), gpa(round(g * 100.0)/ 100.0), className(c) {
        cout << "Constructor called for student: " << name << endl;
    }

    ~Student() {
        cout << "Destructor called for student: " << name << endl;
    }

    string concatInfo() {
        stringstream ss;
        ss << id << " " << name << " " << dob << " " 
           << fixed << setprecision(2) << gpa << " " << className;
        return ss.str();
    }
};

bool isValidId(const string& id, const vector<string>& infoList) {
    if (id.length() != 8) return false;
    
    for (const auto& info : infoList) {
        if (info.substr(0, 8) == id) return false;
    }
    return true;
}

bool isValidDate(const string& dob) {
    if (dob.length() != 10 || dob[2] != '/' || dob[5] != '/') return false;
    string day = dob.substr(0, 2), month = dob.substr(3, 2), year = dob.substr(6, 4);
    int d = stoi(day), m = stoi(month), y = stoi(year);
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900 || y > 2025) return false;
    return true;
}

void copyDataFromFile(fstream &file, vector<string> &infoList) {
    file.clear();
    file.seekg(0, ios::beg);
    string line;
    while (getline(file, line)) {
        infoList.push_back(line);
    }
    sort(infoList.begin(), infoList.end());
}

void addStudent(vector<Student> &list, vector<string> &infoList, fstream &file) {
    string id, name, dob, className;
    float gpa;

    do {
        cout << "Nhap ma sinh vien (8 ky tu, khong trung): ";
        cin >> id;
        if (!isValidId(id, infoList)) {
            cout << "Ma sinh vien khong hop le hoac da ton tai! Vui long nhap lai.\n";
        }
    } while (!isValidId(id, infoList));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ten: ";
    getline(cin, name);

    cout << "Nhap ngay thang nam sinh: ";
    getline(cin, dob);

    while (!isValidDate(dob)) {
        cout << "Ngay sinh khong hop le! Nhap lai (DD/MM/YYYY): ";
        getline(cin, dob);
    }

    cout << "Nhap diem gpa: ";
    while (!(cin >> gpa) || gpa < 0 || gpa > 4) {
        cout << "GPA khong hop le (0-4). Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap ten lop: ";
    getline(cin, className);

    list.emplace_back(id, name, dob, gpa, className);
    infoList.push_back(list.back().concatInfo());
    
    sort(infoList.begin(), infoList.end());
    
    file.close();
    file.open("quanLySV.txt", ios::out | ios::trunc);
    for (const auto& line : infoList) {
        file << line << endl;
    }
    file.close();
    file.open("quanLySV.txt", ios::in | ios::out | ios::app);
}

void displayStudents(fstream &file) {
    file.clear();
    file.seekg(0, ios::beg);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

void searchStudent(const vector<string> &infoList) {
    int choice;
    cout << "Tim kiem theo:\n1. Ma sinh vien\n2. Ten sinh vien\nChon: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string searchTerm;
    if (choice == 1) {
        cout << "Nhap ma sinh vien can tim: ";
        cin >> searchTerm;
        for (const auto &info : infoList) {
            if (info.find(searchTerm) == 0) {
                cout << info << endl;
            }
        }
    } else if (choice == 2) {
        cout << "Nhap ten sinh vien can tim: ";
        getline(cin, searchTerm);
        string lowerSearch = searchTerm;
        transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);
        for (const auto &info : infoList) {
            string lowerInfo = info;
            transform(lowerInfo.begin(), lowerInfo.end(), lowerInfo.begin(), ::tolower);
            if (lowerInfo.find(lowerSearch) != string::npos) {
                cout << info << endl;
            }
        }
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }
}

void updateStudentInfo(vector<string> &infoList, fstream &file) {
    string id;
    cout << "Nhap ma sinh vien can sua: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto &info : infoList) {
        if (info.find(id) == 0) {
            cout << "Da tim thay: " << info << endl;

            string name, dob, className;
            float gpa;

            cout << "Nhap ten moi: ";
            getline(cin, name);
            cout << "Nhap ngay thang nam sinh moi: ";
            getline(cin, dob);
            cout << "Nhap diem gpa moi: ";
            while (!(cin >> gpa) || gpa < 0 || gpa > 4) {
                cout << "GPA khong hop le (0-4). Nhap lai: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap ten lop moi: ";
            getline(cin, className);

            info = Student(id, name, dob, gpa, className).concatInfo();

            sort(infoList.begin(), infoList.end());
            
            file.close();
            file.open("quanLySV.txt", ios::out | ios::trunc);
            for (const auto &line : infoList) {
                file << line << endl;
            }

            file.close();
            file.open("quanLySV.txt", ios::in | ios::out | ios::app);
            cout << "Thong tin da duoc cap nhat!" << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi ma " << id << endl;
}

void deleteStudent(vector<string> &infoList, fstream &file) {
    string id;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> id;

    if (id.length() != 8){
        cout << "Ma sinh vien khong dung dinh dang!" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto it = infoList.begin();
    bool found = false;
    for (; it != infoList.end(); ++it) {
        if (it->find(id) == 0) { 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Khong tim thay sinh vien voi ma " << id << endl;
        return; 
    }

    cout << "Da tim thay: " << *it << endl;

    char confirm;
    do {
        cout << "Xac nhan xoa? (Y/N): ";
        cin >> confirm;
        confirm = toupper(confirm); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirm == 'Y') {
            infoList.erase(it);
            file.close();
            file.open("quanLySV.txt", ios::out | ios::trunc); 
            for (const auto &line : infoList) {
                file << line << endl;
            }
            file.close();
            file.open("quanLySV.txt", ios::in | ios::out);
            cout << "Da xoa sinh vien!" << endl;
            return;
        } else if (confirm == 'N') {
            cout << "Huy thao tac xoa." << endl;
            return;
        } else {
            cout << "Lua chon khong hop le! Vui long nhap Y hoac N.\n";
        }
    } while (true); 
}

int main() {
    vector<Student> studentsList;
    vector<string> studentsInfoList;
    fstream file("quanLySV.txt", ios::in | ios::out | ios::app);

    if (!file.is_open()) {
        cout << "Khong the mo file!" << endl;
        return 1;
    }

    copyDataFromFile(file, studentsInfoList);

    int choice;
    while (true) {
        cout << "===== QUAN LY SINH VIEN =====\n";
        cout << "1. Them sinh vien\n2. Hien thi danh sach\n3. Tim kiem sinh vien\n";
        cout << "4. Sua thong tin sinh vien\n5. Xoa sinh vien\n6. Thoat\nChon: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lua chon khong hop le! Vui long nhap tu 1 den 6.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: addStudent(studentsList, studentsInfoList, file); break;
            case 2: displayStudents(file); break;
            case 3: searchStudent(studentsInfoList); break;
            case 4: updateStudentInfo(studentsInfoList, file); break;
            case 5: deleteStudent(studentsInfoList, file); break;
            case 6: cout << "Thoat chuong trinh.\n"; file.close(); return 0;
        }
    }
    return 0;
}