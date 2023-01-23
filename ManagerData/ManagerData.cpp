#include <iostream>
#include <map>

using namespace std;

template<typename T>
class dataManager
{
private:
    map<int, T> data;
    map<T, int> popular_key;

public:



    void insert(int id, T val)
    {
        auto it = data.find(id);

        if (it == data.end())
        {
            data.insert({ id, val });
            cout << "component  insert" << endl << endl;
        }
        else
        {
            cout << "error: the key already exists" << endl;
        }
    }
    void modify(int key, T new_val)
    {

        auto it = data.find(key);

        if (it != data.end())
        {
            data.at(key) = new_val;
            cout << "modification completed successfully" << endl << endl;
        }
        else
        {
            cout << " element with this value does not exist" << endl << endl;
        }
    }
    void del(int key)
    {
        auto it = data.find(key);

        if (it == data.end())
        {
            cout << " element with this value does not exist" << endl << endl;
        }
        else
        {
            data.erase(key);
        }
    }

    T find(int key)
    {
        auto it = data.find(key);

        popular_key[key]++;

        if (it == data.end())
        {
            cout << " element with this value does not exist" << endl << endl;
            return 0;
        }
        else
        {
            return (*it).second;
        }
    }

    T mostPopularKeyToFind()
    {

        auto it_pop = popular_key.begin();

        for (auto it = popular_key.begin(); it != popular_key.end(); it++)
        {
            if (it->second > it_pop->second) it_pop = it;
        }

        return it_pop->first;
    }
};


int main()
{
    dataManager<int> obj;

    obj.insert(0, 11);
    obj.insert(1, 22);
    obj.insert(2, 33);

    cout << obj.find(0) << endl;
    cout << obj.find(1) << endl;
    cout << obj.find(2) << endl;

    cout << obj.find(1) << endl;
    cout << obj.find(1) << endl;

    obj.modify(1, 12);

    cout << endl;

    cout << obj.find(1) << endl;
    cout << obj.find(2) << endl;
    cout << obj.find(3) << endl;


    cout << obj.mostPopularKeyToFind() << endl;



}

