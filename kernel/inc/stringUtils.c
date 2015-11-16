#include "stringUtils.h"

uint16 strlength(string ch)
{
    uint16 i = 1;
    while(ch[i++]);  
    return --i;
}

uint8 strEql(string ch1,string ch2)                     
{
    uint8 result = 1;
    uint8 size = strlength(ch1);
    if(size != strlength(ch2)) result = 0;
    else 
    {
        uint8 i = 0;
        for(i; i <= size; i++)
        {
            if(ch1[i] != ch2[i]) result = 0;
        }
    }
    return result;
}

uint8 isspace(char ch) {
    if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\f' || ch == '\0')
        return 1; // True
    return 0; // False
}

string strTrim(string str)
{
    uint16 len = 0;
    string frontp = str;
    string endp = 0;

    if(str == 0)
        return 0;
    if(str[0] == '\0')
        return str;

    len = strlength(str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while(isspace(*frontp))
        ++frontp;
    if(endp != frontp)
    {
        while(isspace(*(--endp)) && endp != frontp) {}
    }

    if(str + len - 1 != endp)
        *(endp + 2) = '\0';
    else if(frontp != str && endp == frontp)
        *str = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if(frontp != str)
    {
        while(*frontp)
            *endp++ = *frontp++;
        *endp++ = '\0';
    }

    return str;
}
