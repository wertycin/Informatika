class Client 
{
private:
  void A(int a);
  void B(float b);
  void C(double c);
  friend class Attorney;
};

class Attorney {
private:
  static void callA(Client & c, int a) {
    c.A(a);
  } 
  static void callB(Client & c, float b) {
    c.B(b);
  }
  friend class Bar;
};

class Bar {
// Bar now has access to only Client::A and Client::B through the Attorney.
};
