#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class clsString {
private:
    string _Value;

public:
    // Constructeurs
    clsString() {
        _Value = "";
    }

    clsString(string Value) {
        _Value = Value;
    }

    // Accesseurs
    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() const {
        return _Value;
    }

    // Méthode d'instance : compter les mots
    short CountWords() const {
        return CountWords(_Value);
    }

    // Méthode statique : compter les mots dans une chaîne donnée
    static short CountWords(string S1) {
        string delim = " ";
        short Counter = 0;
        size_t pos = 0;
        string sWord;

        while ((pos = S1.find(delim)) != string::npos) {
            sWord = S1.substr(0, pos);
            if (!sWord.empty()) {
                Counter++;
            }
            S1.erase(0, pos + delim.length());
        }

        if (!S1.empty()) {
            Counter++; // compte le dernier mot
        }

        return Counter;
    }

    // 1. Longueur de la chaîne
    static size_t Length(const string& str) {
        return str.length();
    }

    // 2. Chaîne vide ?
    static bool IsEmpty(const string& str) {
        return str.empty();
    }

    // 3. Ajouter une chaîne à une autre
    static string Append(string str1, const string& str2) {
        return str1.append(str2);
    }

    // 4. Insérer une sous-chaîne
    static string Insert(string str, size_t pos, const string& toInsert) {
        return str.insert(pos, toInsert);
    }

    // 5. Supprimer une partie de la chaîne
    static string Erase(string str, size_t pos, size_t len) {
        return str.erase(pos, len);
    }

    // 6. Remplacer une sous-chaîne
    static string Replace(string str, size_t pos, size_t len, const string& newSub) {
        return str.replace(pos, len, newSub);
    }

    // 7. Trouver la première occurrence
    static size_t Find(const string& str, const string& toFind) {
        return str.find(toFind);
    }

    // 8. Trouver la dernière occurrence
    static size_t RFind(const string& str, const string& toFind) {
        return str.rfind(toFind);
    }

    // 9. Extraire une sous-chaîne
    static string SubStr(const string& str, size_t pos, size_t len) {
        return str.substr(pos, len);
    }

    // 10. Comparer deux chaînes
    static int Compare(const string& str1, const string& str2) {
        return str1.compare(str2);
    }

    // 11. Convertir en majuscules
    static string ToUpper(string str) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }

    // 12. Convertir en minuscules
    static string ToLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // 13. Supprimer les espaces autour
    static string Trim(string str) {
        size_t first = str.find_first_not_of(" \t\n\r\f\v");
        if (first == string::npos) return "";
        size_t last = str.find_last_not_of(" \t\n\r\f\v");
        return str.substr(first, (last - first + 1));
    }

    // 14. Commence par ?
    static bool StartsWith(const string& str, const string& prefix) {
        return str.rfind(prefix, 0) == 0;
    }

    // 15. Finit par ?
    static bool EndsWith(const string& str, const string& suffix) {
        if (str.length() >= suffix.length()) {
            return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
        }
        return false;
    }
};
