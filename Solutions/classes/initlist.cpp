
int a;
int &ra = a;

class Complex
{
public:
    Complex(int r, int i);
private:
    int real;
    int imaginary;
};

Complex::Complex(int r, int i):
    real(r),
    imaginary(i)
{
}


int main()
{

}
