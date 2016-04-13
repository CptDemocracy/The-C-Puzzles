/*
[ref.href] hackerrank.com/challenges/time-conversion
"
  Given a time in AM/PM format, convert it to military (24-hour) time.
"
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int timevals[3];

enum daytime {
    am = 0,
    pm = 1
};

int main() {
    
    const char SEPARATOR = ':';
    
    char* time = (char *)malloc(10240 * sizeof(char));
    if (!time) return 1;
    
    scanf("%s",time);
    
    timevals tvals = { 0 };
    size_t count = sizeof(tvals)/sizeof(tvals[0]);
    
    char* pc = time;
    int val = 0;
    for (size_t i = 0; i < count; ++i) {
        val = 0;
        while (isdigit(*pc)) {
            val = val * 10 + *pc - '0';
            ++pc;
        }
        if (*pc == SEPARATOR) ++pc;
        tvals[i] = val;
    }
    
    enum daytime dtime = am;
    
    if (strcmp(pc, "PM") == 0 || strcmp(pc, "pm") == 0) {
        dtime = pm;    
    }
    
    if (dtime == pm) {
        tvals[0] = tvals[0] < 12 ? (tvals[0] + 12) % 24 : tvals[0];    
    } else tvals[0] = tvals[0] % 12;
    
    char* mtime = (char*)calloc(count * strlen("99") + 2 + 1, sizeof(char));
    if (!mtime) return 1;
    
    sprintf(mtime, "%02d%c%02d%c%02d", 
            tvals[0], 
            SEPARATOR, 
            tvals[1], 
            SEPARATOR, 
            tvals[2]);
    
    puts(mtime);
    
    free(time);
    free(mtime);
    return 0;
}
