#include <iostream>
#include <list>

using namespace std;

class HashTable
{
    private:
        static const int size = 10;
        list<int> htable[size];
    public:
        int hash(int key)
        {
            return key % size;
        }

        void insert(int key)
        {
            int index = hash(key);
            htable[index].push_back(key);
        }
        bool search(int key)
        {
            int index = hash(key);

            for(auto it = htable[index].begin();it != htable[index].end();it++)
            {
                if(*it == key)
                {
                    return true;
                }

            }
            return false;
        }

        void display()
        {
            for(int i=0;i<size;i++)
            {
                cout << i << "->";
                for(auto it = htable[i].begin(); it != htable[i].end(); it++)
                {
                    cout << *it << "->";
                }
                cout<<endl;
            }
        }
};

 int main()
 {
    HashTable h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(402);
    h.insert(160);
    h.insert(255);
    h.insert(15);
    h.insert(26);
    h.insert(177);
    h.insert(22);
    h.display();
    return 0;
 }