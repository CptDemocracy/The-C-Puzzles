/*
[ref.href] leetcode.com/problems/valid-number
"
  Validate if a given string is numeric.
  
  Some examples:
  "0" => true
  " 0.1 " => true
  "abc" => false
  "1 a" => false
  "2e10" => true
"
*/

int isNumber(char* s) {
    while (isspace(*s)) ++s;
    
    char c = '\0';
    if ((c = *s) == '+' || c == '-') ++s;
    
    c = *s;
    if (isdigit(c)) {
        while (isdigit(*s)) ++s;
        if (*s == '.') {
            ++s;
            if (isdigit(*s)) {
                while (isdigit(*s)) ++s;
            }
            else if (isspace(*s)) {
                while (isspace(*s)) ++s;
                if (*s) return 0;
            }
        }
    }
    else if (c == '.') { 
        ++s;
        c = *s;
        if (!c || isspace(c) || c == 'E' || c == 'e') {
            return 0;
        }
        while (isdigit(*s)) ++s;
    }
    else {
        return 0;
    }
    
    c = *s;
    if (c == 'E' || c == 'e') {
        ++s;
        c = *s;
        if (c == '+' || c == '-') ++s;
        if (!isdigit(*s)) {
            return 0;
        }
    }
    
    while (isdigit(*s)) ++s;
    while (isspace(*s)) ++s;
    
    if (*s) {
        return 0;
    }
    return 1;
}
