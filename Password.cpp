#include "Password.h"
#include <string>
#include <iostream>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase) {
    int repetition = 1;
    int index = 0;
    while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1]) {
        repetition++;
        index++;
    }
    return repetition;
}

#include <cctype>
bool Password::has_mixed_case(string str)
{
    bool has_lower = false;
    bool has_upper = false;
    for (char ch : str)
    {
        if (std::islower(ch))
        {
            has_lower = true;
        }
        else if (std::isupper(ch))
        {
            has_upper = true;
        }
    }
    return has_lower && has_upper;
}

Password::Password() {
    pass_history.push_back("ChicoCA-95929");
}

void Password::set(string pw) {
    int chars = pw.length();
    bool mixed_case = has_mixed_case(pw);
    int leading_chars = count_leading_characters(pw);
    bool previously_used = false;

    for (int i = 0; i < pass_history.size(); i++) {
        if (pass_history[i] == pw) {
            previously_used = true;
            break;
        }
    }

    if (chars <= 20 && chars >= 8) {
        if (mixed_case == true) {
            if (previously_used == false) {
                if (leading_chars <= 3) {
                    pass_history.push_back(pw);
                }
            }
        }
    }
}

bool Password::authenticate(string pw) {
    if (pass_history.back() == pw) {
        return true;
    }
    return false;
}