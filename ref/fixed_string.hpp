#ifndef _fixed_string_hpp
#define _fixed_string_hpp

class fixed_string
{

public:
    fixed_string(int lenght);
    fixed_string(int lenght, char* buf);
    fixed_string(const fixed_string& s);
    ~fixed_string();

    inline int get_lenght();
    fixed_string* copy();
    fixed_string* copy(int beg, int len);
    void free();
    fixed_string* deep_copy();

    void copy_from(char& buf);
    void copy_from(const char* buf, int beg, int len);
    void copy_from(const char* buf, int src_beg, int dst_beg);
    void copy_from(const char* buf, int src_beg, int dst_end, int len);
    void copy_from(const fixed_string* s);
    void copy_from(const fixed_string* buf, int src_beg, int dst_beg, int len);

    void copy_to(/* out */char* buf);
    void copy_to(/* out */char* buf, int src_beg, int dst_end);
    void copy_to(/* out */char* buf, int src_beg, int dst_beg, int len);
    void copy_to(/* out */fixed_string& s);
    void copy_to(/* out */fixed_string& buf, int src_beg, int src_end);
    void copy_to(/* out */fixed_string& buf, int src_beg, int src_end, int dst_beg, int dst_len);

    bool operator=(const fixed_string& s);
    bool operator<(const fixed_string& s);
    bool operator>(const fixed_string& s);
    bool operator==(const fixed_string& s);

    
    bool operator!=(const fixed_string& s);

private:
    int length;
    char* buffer;   

};

#endif