#include <stdio.h>

class Money
{
    private:
        int dollars;
        int cents;
public:

/*get*/
    int get_dollars(){return this->dollars;}
    int get_cents(){return this->cents;}

/*secu*/
        bool check_cents_class(void){
            if (get_dollars()<100) return 1;
            else return 0;
            }
        bool check_cents_arg(int c){
            if (c<100) return 1;
            else return 0;
        }

/*constructor*/
        Money(int d, int c)
        {
            dollars = d;
            cents = c;
            if (check_cents_arg(c)!=1){
                throw "error check_cents_arg return 0 in constructor ";
            }
        }
        Money()
        {
            dollars = 0;
            cents = 0;
        }

/*set*/
    void set_dollars(int d)
    {
        this->dollars = d;
    }
    void set_cents(int c)
        { 
            if (check_cents_arg(c)!=1){
                throw "error check_cents_arg return 0 in set_cents ";
            }
            this->cents;
        }
/*add*/
    void add_dollars(int d)
    {
        int tmp = get_dollars();
        set_dollars(tmp+d);
    }
    void add_cents(int c)
    {
        if(check_cents_arg(c+get_cents())!=1){throw "error check_cents_arg return 0 in add_cents";}
    }
    void add_cents_of(int c)
    {
        printf("cents a %d\n",get_dollars());
        int of = 0;
        while (c >= 100){
            c-=100;
            of++;
        }
        add_dollars(of);
        add_cents(c);
        printf("cents b %d\n",get_dollars());
        if (check_cents_class()!=1){throw "error check_cents_class return 0 in add_cents_of";}
    }
/*sub*/
    void sub_dollars(int d){
        if(d<=get_dollars()){set_dollars(get_dollars()-d);}
        else{
            set_cents(100 - get_cents());
            set_dollars(get_dollars()-d-1);
            if (check_cents_class()!=1){throw "error check_cents_class return 0 in sub_dollars";}
        }
    }
    void sub_cents(int c){
    if (c<=get_cents()){set_cents(get_cents()-c);}
    else{
        set_dollars(get_dollars()-1);
        set_cents(get_cents()+100-c);
    }
    if (check_cents_class()!=1){throw "error check_cents_class return 0 in sub_cents";}
}
/*display*/
    void display_all(){
        printf("dollars -> %d\ncents -> %d\n",this->dollars,this->cents);
    }
/*op*/
    Money operator+(Money m)
    {
        Money tmp;
        tmp.dollars=get_dollars()+m.get_dollars();
        tmp.cents=get_cents()+m.get_cents();
        while(tmp.cents>=100){
            tmp.cents -= 100;
            tmp.dollars += 1;
        }
        if (check_cents_arg(tmp.cents)!=1){throw "error check_cents_class return 0 in op+";}
        return tmp;
    }
    Money operator-(Money m)
    {
        Money tmp;
        if (dollars >= m.dollars and cents >= m.cents){tmp.dollars=dollars-m.dollars;tmp.cents=cents-m.cents;}
        else{
            if (dollars > m.dollars and cents<m.cents){tmp.dollars=dollars-m.dollars-1;tmp.cents=cents-m.cents+100;}
            else if (dollars < m.dollars and cents<m.cents){tmp.cents=cents-m.cents;tmp.dollars=dollars-m.dollars;}
            else{tmp.cents=cents-m.cents;tmp.dollars=dollars-m.dollars;}
        }
        if (check_cents_arg(tmp.cents)!=1){throw "error check_cents_class return 0 in op+";}
        return tmp;
    }
    Money operator*(double m)
        {
            Money tmp;
            tmp.dollars = dollars * m;
            tmp.cents = cents * m;
            while (tmp.cents >= 100)
            {
                tmp.cents -= 100;
                tmp.dollars++;
            }
            return tmp;
        }
    Money operator+=(Money m){
        printf("c -> %d mc -> %d\n",cents,m.cents);
        dollars += m.dollars;
        cents += m.cents;
        if (cents >= 100){cents-=100;dollars++;}
        if (cents>=0 and dollars<0){cents-=100;dollars+=1;}
        return *this;
    }
    Money operator-=(Money m)
        {
            dollars -= m.dollars;
            cents -= m.cents;
            while (cents <= -100)
            {
                cents += 100;
                dollars--;
            }
            return *this;
        }
    Money operator*=(Money m)
        {
            dollars *= m.dollars;
            cents *= m.cents;
            while (cents >= 100)
            {
                cents -= 100;
                dollars++;
            }
            return *this;
        }
    Money operator=(Money m){
        dollars = m.dollars;
        cents = m.cents;
        return *this;
    }
/*cmp*/    
    bool operator<(Money m)
    {
        if(dollars>m.dollars){return 0;}
        else if (dollars<m.dollars){return 1;}
        else{
            if (cents >= m.cents){return 0;}
            return 1;
        }
    }
    bool operator<=(Money m)
    {
        if(dollars>m.dollars){return 0;}
        else if (dollars<m.dollars){return 1;}
        else{
            if (cents > m.cents){return 0;}
            return 1;
        }
    }
    bool operator>(Money m)
    {
        if(dollars>m.dollars){return 1;}
        else if (dollars<m.dollars){return 0;}
        else{
            if (cents > m.cents){return 1;}
            return 0;
        }
    }
    bool operator>=(Money m)
    {
        if(dollars>m.dollars){return 1;}
        else if (dollars<m.dollars){return 0;}
        else{
            if (cents >= m.cents){return 1;}
            return 0;
        }
    }
    bool operator==(Money m)
    {
        if(dollars==m.dollars and cents==m.cents){return 1;}
        return 0;
    }
    bool operator!=(Money m)
    {
        if(dollars!=m.dollars or cents!=m.cents){return 1;}
        return 0;
    }    
};

int main(){
    Money t1(-60,-12);
    Money t2(10,14);
    t2.display_all();
    t1=t2;
    t1.display_all();
    return 1;
}