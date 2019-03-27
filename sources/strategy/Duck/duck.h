#ifndef DUCK_H
#define DUCK_H

class IFly {
public:
    virtual void fly() = 0;
    virtual ~IFly() = default;
};

class FlyWithWings: public IFly {
    virtual void fly() override;
};

class FlyNoWay: public IFly{
    virtual void fly() override;
};

class IQuack {
public:
    virtual void quack() = 0;
    virtual ~IQuack() = default;
};

class Quack: public IQuack{
    virtual void quack() override;
};

class MuteQuack: public IQuack{
    virtual void quack() override;
};

class Squeak: public IQuack{
    virtual void quack() override;
};

class Duck {
public:
    explicit Duck() = default;
    virtual ~Duck();
    virtual void display() = 0;
    void fly();
    void quack();
    void swim();

protected:
    IFly *iFly = nullptr;
    IQuack *iQuack = nullptr;
};

class MallardDuck: public Duck {
public:
    explicit MallardDuck();
    virtual void display() override;
};

class TransformDuck: public Duck {
public:
    explicit TransformDuck();
    virtual void display() override;
    void setFlyInterface(IFly *iFly);
    void setQuackInterface(IQuack *iQuack);
};

#endif // DUCK_H
