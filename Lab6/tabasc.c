#include <iostream>
#include <string>

template<typename TYPE>
class Stack
{
    int Size;
    int MaxSize;
    TYPE *Tab;
public:
    Stack()
        : Size(0), MaxSize(4)
    {
        Tab = new TYPE[MaxSize];
    }
    ~Stack()
    {
        delete[] Tab;
    }
    void Push(TYPE Obj)
    {
        if(Size>=MaxSize)
        {
            TYPE *NewTab = new TYPE[MaxSize*2];
            for(int i=0; i<Size; ++i) NewTab[i]=Tab[i];
            delete[] Tab;
            Tab = NewTab;
            MaxSize*=2;
        }
        Tab[Size] = Obj;
        ++Size;
    }
    int GetSize(){return Size;}
    TYPE& operator[](int Index)
    {
        return Tab[Index];
    }
    const TYPE& operator[](int Index) const
    {
        return Tab[Index];
    }

    TYPE& GetLast(){return Tab[Size-1];}
    const TYPE& GetLast() const {return Tab[Size-1];}

    TYPE& GetFirst(){return Tab[0];}
    const TYPE& GetFirst() const {return Tab[0];}
};

template<typename TYPE>
class AssoArray
{
    struct Element
    {
        std::string Id;
        TYPE Data;
        Element() : Id("") {;}
        Element(const std::string &_Id) : Id(_Id){;}
    };

    Stack<Element> Tab;
public:
    TYPE& operator[](const std::string &Text)
    {
        for(int i=0; i<Tab.GetSize(); ++i)
        {
            if(Tab[i].Id==Text) return Tab[i].Data;
        }
        Tab.Push(Element(Text));
        return Tab.GetLast().Data;
    }
    const TYPE& operator[](const std::string &Text) const
    {
        for(int i=0; i<Tab.GetSize(); ++i)
        {
            if(Tab[i].Id==Text) return Tab[i].Data;
        }
        Tab.Push(Element(Text));
        return Tab.GetLast().Data;
    }
    int GetSize(){return Tab.GetSize();}
    const std::string &GetId(int Index) const {return Tab[Index].Id;}
};


template<typename TYPE>
class AssoArrayLink
{
    struct Element
    {
        std::string Id;
        TYPE Data;
        Element() : Id("") {;}
        Element(const std::string &_Id) : Id(_Id){;}
    };

    Stack<Element> **Tab;
    int MaxSize;
public:
    AssoArrayLink()
    {
        MaxSize = 1500;
        Tab = new Stack<Element>*[MaxSize]{};
    }
    ~AssoArrayLink()
    {
        for(int i=0; i<MaxSize; ++i) if(Tab[i]) delete Tab[i];
        delete[] Tab;
    }
    int TextToId(const std::string &Text)
    {
        int Sum = 0;
        for(int i=0; i<Text.size(); ++i) Sum+=Text[i];
        return Sum;
    }
    TYPE& operator[](const std::string &Text)
    {
        int Index = TextToId(Text);

        if(Tab[Index])
        for(int i=0; i<Tab[Index]->GetSize(); ++i)
            if((*Tab[Index])[i].Id==Text) return (*Tab[Index])[i].Data;

        Tab[Index] = new Stack<Element>;
        Tab[Index]->Push(Text);
        return Tab[Index]->GetLast().Data;
    }
    const TYPE& operator[](const std::string &Text) const
    {
        int Index = TextToId(Text);

        if(Tab[Index])
        for(int i=0; i<Tab[Index]->GetSize(); ++i)
            if(Tab[Index][i].Id==Text) return Tab[Index][i].Data;

        Tab[Index] = new Stack<Element>;
        Tab[Index]->Push(Text);
        return Tab[Index]->GetLast().Data;
    }
    int GetSize(){return MaxSize;}
    //const std::string &GetId(int Index) const {return Tab[Index].Id;}
};

class HashTab
{
    struct Element
    {
        int Data;
        bool Empty;
        Element():Empty(true),Data(0){;}
    };
    int MaxSize;
    Element *Tab;
public:
    HashTab(int _MaxSize)
        : MaxSize(_MaxSize)
    {
        Tab = new Element[MaxSize];
    }
    ~HashTab()
    {
        delete[] Tab;
    }
    void Add(int Value)
    {
        int Index = Value % MaxSize;
        for(int i=0; i<MaxSize; ++i)
        {
            int Temp = (Index+i)%MaxSize;
            if(Tab[Temp].Empty)
            {
                Tab[Temp].Data = Value;
                Tab[Temp].Empty = false;
                return;
            }
        }
    }
    int Get(int Value)
    {
        int Index = Value % MaxSize;
        for(int i=0; i<MaxSize; ++i)
        {
            int Temp = (Index+i)%MaxSize;
            if(!Tab[Temp].Empty && Tab[Temp].Data==Value)
            {
                return Temp;
            }
        }
        return -1;
    }
    int& operator[](int Index)
    {
        return Tab[Index].Data;
    }
    int operator[](int Index) const
    {
        return Tab[Index].Data;
    }
    void Display()
    {
        for(int i=0; i<MaxSize; ++i)
        {
            if(!Tab[i].Empty) std::cout<<i<<": "<<Tab[i].Data<<'\n';
            else std::cout<<i<<": ---\n";
        }
    }
};

int main()
{
    /*
    AssoArray<int> Tab;
    Tab["Adam Adamowicz"] = 1;
    Tab["Marcin Kos"] = 100;
    Tab["Krzysztof Nowak"] = 4;

    std::cout<<"Tab:\n";
    for(int i=0; i<Tab.GetSize(); ++i)
        std::cout<<Tab.GetId(i)<<": "<<Tab[Tab.GetId(i)]<<'\n';

    Tab["Marcin Kos"] = 30;
    Tab["Maciek z klanu"] = 99;

    std::cout<<"\nTab:\n";
    for(int i=0; i<Tab.GetSize(); ++i)
        std::cout<<Tab.GetId(i)<<": "<<Tab[Tab.GetId(i)]<<'\n';

    std::cout<<'\n'<<Tab["Adam Adamowicz"]<<'\n';
    */

    /*
    AssoArrayLink<int> Tab;
    Tab["AAA"] = 0;
    Tab["BBB"] = 2;
    Tab["CCC"] = 4;
    Tab["DDD"] = 6;
    Tab["EEE"] = 8;
    std::cout<<Tab["EEE"]<<'\n';
    std::cout<<Tab["DDD"]<<'\n';
    std::cout<<Tab["CCC"]<<'\n';
    std::cout<<Tab["BBB"]<<'\n';
    std::cout<<Tab["AAA"]<<'\n';
    */

    HashTab Tab(6);
    Tab.Add(11);
    Tab.Add(12);
    Tab.Add(4);
    Tab.Add(18);
    Tab.Display();
}
