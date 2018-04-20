#include <iostream>
#include <map>
#include<string>
using namespace std;

int main()
{
    char *buf[1024];
    map<string, string> strmap;
    int num = 0;
    while(1)
    {
        num = net_read(fd,buf,1024);
        if(num ==0)
            break;
        const char * split = "\r\n";
        string s;
        s = strtok (buf,split);
        while(s!=NULL)
        {
            if(s == "http")
                continue;
            string strtmp[] = s.split(":");
            if(sizeof(strtmp)==2)
            {
                map[strtmp[0]] = strtmp[1];
            }
            else
                s = strtok(NULL,split);
        }
    }
    cout << "{" << endl;
    for(auto it = strmap.begin(); it != strmap.end(); it++)
    {
        cout << "{" << it->first << "\",\"" << it->second << "\"}" << endl;
    }
    cout << "}" << endl;

    return 0;
}
