#ifndef BEVARAGE_H
#define BEVARAGE_H

#include <string>

class Bevarage
{   
public:
    enum Size {TALL,GRANDE,VENTI};
    virtual ~Bevarage() = default;
    virtual std::string description();
    virtual double cost() = 0;
    void setSize(Size size);
    Size size();
protected:
    std::string _description = "Unknown Beverage";
    Size _size = TALL;

};

#endif // BEVARAGE_H
