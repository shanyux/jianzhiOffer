#include <iostream>

using namespace std;

class Singleton
{
private:
    Singleton() {};
    static Singleton *m_instance;
public:
    static Singleton *getInstance()
    {
        if(m_instance == NULL)
        {
            m_instance = new Singleton();

        }
        return m_instance;
    }
};
Singleton * Singleton::m_instance = NULL;
int main()
{

    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    if(s1==s2)
        cout <<"s1==s2" <<endl;
    return 0;
}
