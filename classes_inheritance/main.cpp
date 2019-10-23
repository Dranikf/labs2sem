// тут разберусь навсегда со спецификаторами наследоания
class Parent{
public:
    int public_int;
    void public_function(){};

protected:
    int protected_int;
    void protected_function(){};

private:
    int private_int;
    void private_function(){};

};

class ancestor1 : public Parent{
    public:
        void test(){
            // внутри не видит только private но оно и понятно
            protected_int  = 200;
            protected_function();
            
            public_int = 200;
            public_function();
        };
};

class ancestor2 : protected Parent{

    public:
        void test(){

            // внутри не видит только private
            protected_int  = 200;
            protected_function();
            
            public_int = 200;
            public_function();

        };

};

int main(){

    // при спецификаторе наследования public
    // вне класса видит только public поля
    ancestor1 a1;
    a1.public_function();
    a1.public_int = 200;

    ancestor2 a2;// вот при спецификаторе protected я все класса уже и public родителя не вижу

}