#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 1. Получение расширения файла
// Вход: ссылка на строку `file_path_full`, входные данные не меняются
// Выход: строка, содержащая расширение файла, если его нет, то пустая строка
string file_format(const string &file_path_full) {
    size_t pos = file_path_full.find_last_of(".");
    if (pos == string::npos) return ""; // Если расширения нет, вернуть пустую строку
    return file_path_full.substr(pos + 1);
}

// 2. Получение имени файла без расширения
// Вход: ссылка на строку `file_path_full`, входные данные не меняются
// Выход: строка с именем файла без расширения.
string file_name(const string &file_path_full) {
    size_t pos1 = file_path_full.find_last_of("/\\"); //обратный слэш экранируется именно "\\"
    size_t pos2 = file_path_full.find_last_of(".");
    if (pos1 == string::npos) {
        pos1 = 0;
     } else pos1++;
    if (pos2 == string::npos || pos2 < pos1) {
        pos2 = file_path_full.size();
    }
    return file_path_full.substr(pos1, pos2 - pos1); //первое - начало извлечения, второе - длина
}

// 3. Получение пути к файлу
// Вход: ссылка на строку `file_path_full`, входные данные не меняются
// Выход: строка, содержащая путь к файлу без имени файла, пустая строка, если нет пути.
string f_path(const string &file_path_full) {
    size_t pos = file_path_full.find_last_of("/\\");
    if (pos == string::npos) return ""; // Если нет пути, вернуть пустую строку
    return file_path_full.substr(0, pos);
}

// 4. Получение имени диска
// Вход: ссылка на строку `file_path_full`, входные данные не меняются
// Выход: символ, представляющий имя диска, если оно существует, пустой символ, если диск не найден.
char file_disk(const string &file_path_full) {
    if (file_path_full.size() > 1 && file_path_full[1] == ':') {
        return file_path_full[0];
    }
    return '\0'; // Возвращаем пустой символ, если диск не найден
}

// 5. Переименование файла
// Вход: указатель на строку `file_path_full`, ссылка на строку new_name с именем нового файла.
// `file_path_full` указывает после исполнения на новое полное расположение файла
// Выход: `true`, если переименование успешно, `false` - в случае неудачи.
bool file_rename(string *file_path_full, const string &new_name) {
    string path = f_path(*file_path_full);
    string new_file_path = path + "/" + new_name;
    if (rename(file_path_full->c_str(), new_file_path.c_str()) == 0) { // стандартная функция C, которая переименовывает файл, в случае успеха возвр. 0
        *file_path_full = new_file_path; // Обновляем исходное расположение
        return true;
    }
    return false;
}

// 6. Копирование файла
// Вход: ссылка на строку `file_path_full`, входные данные не меняются
// Выход: `true`, если копирование прошло успешно, иначе `false`.
bool file_copy(const string &file_path_full) {
    if (f_path(file_path_full) == ""){
        return false;
    } else {
        fstream old_file;
        old_file.open(file_path_full, std::fstream::in);
        string new_file_path = file_path_full.substr(0, file_path_full.find_last_of(".")) + "_copy" + file_format(file_path_full);
        // Берём подстроку от начала строки file_path_full до точки, добавляем _copy, дальше добавляем расширение файла
        fstream new_file;
        new_file.open(new_file_path, std::fstream::out);
        string line;
        while (getline(old_file, line)) {
            new_file << line << '\n'; // Записываем строку в новый файл и добавляем символ новой строки
    }
    old_file.close();
    new_file.close();
    }
}

// Пример работы меню, которое позволяет вызывать функции
int main() {
    int choice;
    string file_path;
    cout << "Enter the full file path: ";
    cin >> file_path;

    do {
        cout << "Menu:\n";
        cout << "1. Get file extension\n";
        cout << "2. Get file name\n";
        cout << "3. Get file path\n";
        cout << "4. Get disk name\n";
        cout << "5. Rename file\n";
        cout << "6. Copy file\n";
        cout << "0. Exit\n";
        cout << "Enter the number of the operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "File extension: " << file_format(file_path) << endl;
                break;
            case 2:
                cout << "File name: " << file_name(file_path) << endl;
                break;
            case 3:
                cout << "File path: " << f_path(file_path) << endl;
                break;
            case 4:
                cout << "Disk name: " << file_disk(file_path) << endl;
                break;
            case 5: {
                string new_name;
                cout << "Enter the new file name: ";
                cin >> new_name;
                if (file_rename(&file_path, new_name)) {
                    cout << "File successfully renamed to: " << file_path << endl;
                } else {
                    cout << "Error renaming the file" << endl;
                }
                break;
            }
            case 6:
                if (file_copy(file_path)) {
                    cout << "File successfully copied." << endl;
                } else {
                    cout << "Error copying the file." << endl;
                }
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
return 0;
}