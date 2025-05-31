/*
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/#

KMP Algorithm for Pattern Searching

Given two strings txt and pat, the task is to return all indices of occurrences of pat within txt.

Examples:

Input: txt = “abcab”,  pat = “ab”
Output: [0, 3]
Explanation: The string “ab” occurs twice in txt, first occurrence starts from index 0 and second from index 3.


Input: txt=  “aabaacaadaabaaba”, pat =  “aaba”
Output: [0, 9, 12]
Explanation:


The Knuth-Morris-Pratt (KMP) algorithm is a string-searching algorithm which is used to find a pattern within large texts efficiently.
Unlike naive pattern searching algorithm which starts from the beginning of the pattern after each mismatch,
KMP uses the structure of the pattern to avoid redundant comparisons.
It preprocesses the pattern string and creates an array called the Longest Prefix Suffix (lps)
array which indicates how much of the pattern can be reused after a mismatch.


Кароче суть алгоритма:
2 итератора(i, j) , 1 переменная
составляеш lps array - суть в том что есть итератор i, относительно него (важно относительно него) чекаем префиксы и суфиксы (длиной в 1)
steps:

lps[0] is always 0 since a string of length one has no non-empty proper prefix. We store the value of the previous LPS in a variable len, initialized to 0. As we traverse the pattern, we compare the current character at index i, with the character at index len.


Case 1 – pat[i] = pat[len]: this means that we can simply extend the LPS at the previous index, so increment len by 1 and store its value at lps[i].


Case 2 – pat[i] != pat[len] and len = 0: it means that there were no matching characters earlier and the current characters are also not matching, so lps[i] = 0.


Case 3 – pat[i] != pat[len] and len > 0: j = lps[j-1]

!!!
Ми кажем якщо ми пройшли патерн від 0 до і, та на і отримали незівпадіння, то в тому проміжку від 0 до і є проміжок 0 + к до i ,
в якому ми мали зівпадіння та можем почати з його кінця

ababc

якщо дійшли до abaх іт тут (незівпадіння - х) то ми вже бачили а, можем почати з b . 

якщо дійшли до abab далі ababc іт тут (незівпадіння - х) то ми вже бачили аb, можем почати з a . 

!!!

*/


#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления LPS (Longest Prefix Suffix) массива
vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    
    int len = 0; // Длина предыдущего совпадающего префикса и суффикса
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Сдвигаем len назад
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Функция KMP для поиска подстроки в строке
void KMPSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    
    vector<int> lps = computeLPS(pattern);
    
    int i = 0; // Индекс текста
    int j = 0; // Индекс шаблона

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) { // Нашли полное совпадение
            cout << "Шаблон найден в индексе " << i - j << endl;
            j = lps[j - 1]; // Продолжаем поиск
        } else if (i < n && text[i] != pattern[j]) { // Несовпадение
            if (j != 0) {
                j = lps[j - 1]; // Используем LPS для оптимального сдвига
            } else {
                i++;
            }
        }
    }
}

// Тест
int main() {
    string text = "ABADABAB";
    string pattern = "ABAB";
    
    KMPSearch(text, pattern);
    
    return 0;
}
