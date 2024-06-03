class SortRule
{
public:
    virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 > num2)
            return true;
        else
            return false;
    }
};

class DescendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 < num2)
            return true;
        else
            return false;
    }
};

class DataStotage 
{
private:
    int* m_arr;
    int m_capacity;
    int m_size;
public:
    DataStotage(int cap) : m_capacity(cap), m_size(0) {
        m_arr = new int[m_capacity];
    }
    ~DataStotage() 
    {
        delete[] m_arr;
    }
    void addnum(int arr) {
        m_arr[m_size] = arr;
        m_size++;
    }
    void ShowData()
    {
        for (int i = 0; i < m_size; i++)
        {
            std::cout << m_arr[i] << std::endl;
        }
    }
    void SortData(const SortRule& functor)
    {
        for (int i = 0; i < (m_size-1); i++)
        {
            for(int j = 0; j < (m_size-1); j++)
            {
                if (functor(m_arr[j], m_arr[j + 1]))
                {
                    int temp = m_arr[j];
                    m_arr[j] = m_arr[j + 1];
                    m_arr[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    DataStotage* str = new DataStotage(10);
    str->addnum(10);
    str->addnum(15);
    str->addnum(20);
    str->addnum(25);

    AscendingSort upsort;
    DescendingSort downsort;
    str->SortData(downsort);
    str->ShowData();
    delete str;
    return 0;
}