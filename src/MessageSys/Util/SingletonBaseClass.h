#pragma once
#ifndef __SINGLETONBASE
#define __SINGLETONBASE
template<class classname>
class Singleton{
    protected:
        Singleton(){}
        ~Singleton(){}
    private:
        Singleton(Singleton const & rhs){}
        Singleton const & operator = (Singleton const & rhs){}
    public:
        static classname& Instance(){
            static classname instance;
            return instance;
        }
};
#endif