class Complex{
  private:
    double a, b, r, angle;

  public:
    Complex();
    Complex(double, double);
    Complex(double, double, bool);
    
    void setA(double);
    void setB(double);
    void setAngle(double);
    void setR(double);

    double getA();
    double getB();
    double getAngle();
    double getR();

    void calculateR();
    void calculateAngle();

    void display();

    void operator+ (Complex lhs);
    void operator- (Complex lhs);
    void operator* (double);
    void operator/ (double);
    bool operator== (Complex lhs);
};