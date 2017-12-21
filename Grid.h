#pragma once
#include <cstring>
using uint = size_t;

template <typename T>
class Grid
{
  public:
    Grid()
        : m_cols(20), m_rows(40), m_size(m_cols * m_rows)
    {
        Init();
    }

    Grid(uint cols, uint rows)
        : m_cols(cols), m_rows(rows), m_size(m_cols * m_rows)
    {
        Init();
    }

    Grid(const Grid &other)
        : m_cols(other.m_cols), m_rows(other.m_rows), m_size(other.m_size)
    {
        m_content = new T[m_size];
        std::memcpy(m_content, other.m_content, other.m_size);
    }

    T &operator[](uint index)
    {
        if (index > m_size || index < 0)
        {
            throw "Out of bounds index";
        }
        return m_content[index];
    }

    T &Get(uint col, uint row)
    {
        uint index = row * m_cols + col;
        if (index > m_size || index < 0)
        {
            throw "Out of bounds index";
        }
        return m_content[index];
    }

  private:
    uint m_cols;
    uint m_rows;
    uint m_size;
    T *m_content;

    inline void Init()
    {
        m_content = static_cast<T *>(calloc(m_size, sizeof(T)));
    }
};